#include "TCanvas.h"
#include "TTree.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>


void division_forfakes_mu_v2()
{
  TFile* file_Data= new TFile("outputsFR_round2/Data_mu.root");
  TFile* file_DY= new TFile("outputsFR_round2/DY_mu.root");
  TFile* file_WJets= new TFile("outputsFR_round2/WJets_mu.root");

  TH1F* h_DATA = (TH1F*)file_Data->Get("afterjetcut/h_pt1_tight_jet");
  TH1F* h_DY = (TH1F*)file_DY->Get("afterjetcut/h_pt1_tight_jet");
  TH1F* h_WJets = (TH1F*)file_WJets->Get("afterjetcut/h_pt1_tight_jet");
  TH1F* h_denominator_DATA = (TH1F*)file_Data->Get("afterjetcut/h_pt1_loose_jet");
  TH1F* h_denominator_DY = (TH1F*)file_DY->Get("afterjetcut/h_pt1_loose_jet");
  TH1F* h_denominator_WJets = (TH1F*)file_WJets->Get("afterjetcut/h_pt1_loose_jet");
  TH1F* h_DATA_eta = (TH1F*)file_Data->Get("afterjetcut/h_eta1_tight_jet");
  TH1F* h_DY_eta = (TH1F*)file_DY->Get("afterjetcut/h_eta1_tight_jet");
  TH1F* h_WJets_eta = (TH1F*)file_WJets->Get("afterjetcut/h_eta1_tight_jet");
  TH1F* h_denominator_DATA_eta = (TH1F*)file_Data->Get("afterjetcut/h_eta1_loose_jet");
  TH1F* h_denominator_DY_eta = (TH1F*)file_DY->Get("afterjetcut/h_eta1_loose_jet");
  TH1F* h_denominator_WJets_eta = (TH1F*)file_WJets->Get("afterjetcut/h_eta1_loose_jet");

  gStyle->SetOptStat(0);
  TH1F* h_num = (TH1F*)h_DATA->Clone("h_num");
  h_num->Add(h_DY,-1);
  h_num->Add(h_WJets,-1);
  TH1F* h_den = (TH1F*)h_denominator_DATA->Clone("h_den");
  h_den->Add(h_denominator_DY,-1);
  h_den->Add(h_denominator_WJets,-1);
  TH1F* h_div = (TH1F*)h_num->Clone("h_div");
  h_div->Divide(h_den);
  
  TH1F* h_div_noEWKcorr = (TH1F*)h_DATA->Clone("h_div_noEWKcorr");
  h_div_noEWKcorr->Divide(h_denominator_DATA);
 
  TH1F* h_relEWKcont = (TH1F*)h_DY->Clone("h_relEWKcont");
  h_relEWKcont->Add(h_WJets,1);
  TH1F* h_relEWKcont_numerator = (TH1F*)h_relEWKcont->Clone("h_relEWKcont_numerator");
  h_relEWKcont_numerator->Divide(h_DATA);
  TH1F* h_relEWKcont2 = (TH1F*)h_denominator_DY->Clone("h_relEWKcont2");
  h_relEWKcont2->Add(h_denominator_WJets,1);
  TH1F* h_relEWKcont_denominator = (TH1F*)h_relEWKcont2->Clone("h_relEWKcont_denominator");
  h_relEWKcont_denominator->Divide(h_denominator_DATA);

  TH1F* h_num_eta = (TH1F*)h_DATA_eta->Clone("h_num_eta");
  h_num_eta->Add(h_DY_eta,-1);
  h_num_eta->Add(h_WJets_eta,-1);
  TH1F* h_den_eta = (TH1F*)h_denominator_DATA_eta->Clone("h_den_eta");
  h_den_eta->Add(h_denominator_DY_eta,-1);
  h_den_eta->Add(h_denominator_WJets_eta,-1);
  TH1F* h_div_eta = (TH1F*)h_num_eta->Clone("h_div_eta");
  h_div_eta->Divide(h_den_eta);
  TH1F* h_div_noEWKcorr_eta = (TH1F*)h_DATA_eta->Clone("h_div_noEWKcorr_eta");
  h_div_noEWKcorr_eta->Divide(h_denominator_DATA_eta);

  TLegend *leg= new TLegend(0.1,0.7,0.48,0.9);
  leg->AddEntry(h_div_noEWKcorr,"Without EWK correction");
  leg->AddEntry(h_div,"With EWK correction");

  /////////////Efficiency errors //////////////////                                                                                                                                                                  
  float binvalue ;
  float totaln ;
  float newerror ;

  for (int i=1; i<= 8; i++) {
    binvalue = h_div->GetBinContent(i);
    totaln = h_den->GetBinContent(i);
    newerror = sqrt((binvalue*(1-binvalue))/totaln);
    h_div->SetBinError(i,newerror);
  }
  for (int i=1; i<= 8; i++) {
    binvalue = h_div_noEWKcorr->GetBinContent(i);
    totaln = h_denominator_DATA->GetBinContent(i);
    newerror = sqrt((binvalue*(1-binvalue))/totaln);
    h_div_noEWKcorr->SetBinError(i,newerror);
  }
  for (int i=1; i<= 5; i++) {
    binvalue = h_div_eta->GetBinContent(i);
    totaln = h_den_eta->GetBinContent(i);
    newerror = sqrt((binvalue*(1-binvalue))/totaln);
    h_div_eta->SetBinError(i,newerror);
  }
  for (int i=1; i<= 5; i++) {
    binvalue = h_div_noEWKcorr_eta->GetBinContent(i);
    totaln = h_denominator_DATA_eta->GetBinContent(i);
    newerror = sqrt((binvalue*(1-binvalue))/totaln);
    h_div_noEWKcorr_eta->SetBinError(i,newerror);
  }
  /////////////////////////////////////////////                                                                                                                                                                   
  
  TCanvas *c1= new TCanvas();
  h_div->Draw("E"); h_div->GetYaxis()->SetRangeUser(0,1); h_div->SetTitle("TightMuon_cut_Tight80x_HWWW"); h_div->GetYaxis()->SetTitle("Muon fake rate"); h_div->SetLineColor(2); h_div->GetXaxis()->SetTitle("p_{T} [GeV]");c1->SetGridx(1);c1->SetGridy(1); h_div->SetLineWidth(2); h_div->SetMarkerColor(2);  h_div->SetMarkerStyle(kFullCircle);
  h_div_noEWKcorr->Draw("sameE"); h_div_noEWKcorr->SetLineColor(1);h_div_noEWKcorr->SetLineWidth(2); h_div_noEWKcorr->SetMarkerColor(1);  h_div_noEWKcorr->SetMarkerStyle(kFullCircle);
  leg->Draw();c1->SaveAs("division_TightMuon_pt.gif");
  h_relEWKcont_numerator->Draw();h_relEWKcont_numerator->GetYaxis()->SetRangeUser(0,1);h_relEWKcont_numerator->SetTitle("Muon EWK contamination"); h_relEWKcont_numerator->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_numerator->GetXaxis()->SetTitle("Pt1 [GeV]");c1->SaveAs("EWK_contamination_muonTightWP_numerator.gif");
  h_relEWKcont_denominator->Draw();h_relEWKcont_denominator->GetYaxis()->SetRangeUser(0,1);h_relEWKcont_denominator->SetTitle("Muon EWK contamination"); h_relEWKcont_denominator->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_denominator->GetXaxis()->SetTitle("Pt1 [GeV]");c1->SaveAs("EWK_contamination_muonTightWP_denominator.gif");

  TCanvas *c2= new TCanvas();
  h_div_eta->Draw("E"); h_div_eta->GetYaxis()->SetRangeUser(0,1); h_div_eta->SetTitle("TightMuon_cut_Tight80x_HWWW"); h_div_eta->GetYaxis()->SetTitle("Muon fake rate"); h_div_eta->SetLineColor(2); h_div_eta->GetXaxis()->SetTitle("|#eta|");c2->SetGridx(1);c2->SetGridy(1); h_div_eta->SetLineWidth(2); h_div_eta->SetMarkerColor(2);  h_div_eta->SetMarkerStyle(kFullCircle);
  h_div_noEWKcorr_eta->Draw("sameE"); h_div_noEWKcorr_eta->SetLineColor(1);h_div_noEWKcorr_eta->SetLineWidth(2); h_div_noEWKcorr_eta->SetMarkerColor(1); h_div_noEWKcorr_eta->SetMarkerStyle(kFullCircle);
  leg->Draw();c2->SaveAs("division_TightMuon_eta.gif");
 
  cout<<"THE END"<<endl;
 
}



 
