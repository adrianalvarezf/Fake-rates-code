
#include "TCanvas.h"
#include "TTree.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>


void division_forfakes_mu()
{
 
  TFile* file_hadd= new TFile("code_muon_fakes/rootFile_24September_Fake_muons_noMCtrigger/plots__24September_Fake_muons_noMCtrigger.root");
  //TFile* file_hadd= new TFile("rootFile_17September_Fake_muons__TrkIsoVVL/plots__17September_Fake_muons__TrkIsoVVL.root");
  
  TH1F* h_DATA = (TH1F*)file_hadd->Get("numerator/mu_pt1/histo_DATA"); 
  TH1F* h_DY = (TH1F*)file_hadd->Get("numerator/mu_pt1/histo_DY"); 
  TH1F* h_WJets = (TH1F*)file_hadd->Get("numerator/mu_pt1/histo_WJets"); 
  TH1F* h_denominator_DATA = (TH1F*)file_hadd->Get("denominator/mu_pt1/histo_DATA"); 
  TH1F* h_denominator_DY = (TH1F*)file_hadd->Get("denominator/mu_pt1/histo_DY"); 
  TH1F* h_denominator_WJets = (TH1F*)file_hadd->Get("denominator/mu_pt1/histo_WJets"); 
  TH1F* h_DATA_eta = (TH1F*)file_hadd->Get("numerator/abs_mu_eta1/histo_DATA"); 
  TH1F* h_DY_eta = (TH1F*)file_hadd->Get("numerator/abs_mu_eta1/histo_DY"); 
  TH1F* h_WJets_eta = (TH1F*)file_hadd->Get("numerator/abs_mu_eta1/histo_WJets"); 
  TH1F* h_denominator_DATA_eta = (TH1F*)file_hadd->Get("denominator/abs_mu_eta1/histo_DATA"); 
  TH1F* h_denominator_DY_eta = (TH1F*)file_hadd->Get("denominator/abs_mu_eta1/histo_DY"); 
  TH1F* h_denominator_WJets_eta = (TH1F*)file_hadd->Get("denominator/abs_mu_eta1/histo_WJets"); 

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
  
  TCanvas *c1= new TCanvas();
  h_num->Draw();//c1->SaveAs("division_TightMuon_num_pt.gif");
  h_den->Draw();//c1->SaveAs("division_TightMuon_den_pt.gif");
  h_div->Draw(); h_div->GetYaxis()->SetRangeUser(0,1); h_div->SetTitle("TightMuon_cut_Tight80x_HWWW"); h_div->GetYaxis()->SetTitle("Muon fake rate"); h_div->SetLineColor(2); h_div->GetXaxis()->SetTitle("Pt1 [GeV]");
  h_div_noEWKcorr->Draw("same"); h_div_noEWKcorr->SetLineColor(1);c1->SetGrid();
  c1->SaveAs("division_TightMuon_pt.gif");
  h_relEWKcont_numerator->Draw();h_relEWKcont_numerator->SetTitle("Muon EWK contamination"); h_relEWKcont_numerator->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_numerator->GetXaxis()->SetTitle("Pt1 [GeV]");c1->SaveAs("EWK_contamination_muonTightWP_numerator.gif");
  h_relEWKcont_denominator->Draw();h_relEWKcont_denominator->SetTitle("Muon EWK contamination"); h_relEWKcont_denominator->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_denominator->GetXaxis()->SetTitle("Pt1 [GeV]");c1->SaveAs("EWK_contamination_muonTightWP_denominator.gif");

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
  
  TCanvas *c2= new TCanvas();
  h_num_eta->Draw();//c2->SaveAs("division_TightMuon_num_eta.gif");
  h_den_eta->Draw();//c2->SaveAs("division_TightMuon_den_eta.gif");
  h_div_eta->Draw(); h_div_eta->GetYaxis()->SetRangeUser(0,1); h_div_eta->SetTitle("TightMuon_cut_Tight80x_HWWW"); h_div_eta->GetYaxis()->SetTitle("Muon fake rate"); h_div_eta->SetLineColor(2); h_div_eta->GetXaxis()->SetTitle("|Eta1|");
  h_div_noEWKcorr_eta->Draw("same"); h_div_noEWKcorr_eta->SetLineColor(1);c2->SetGrid();
  c2->SaveAs("division_TightMuon_eta.gif");
 
  cout<<"THE END"<<endl;
 
}



 
