#include "TCanvas.h"
#include "TTree.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

void division_forfakes_jetbins()
{
  TFile* file_Data_ele= new TFile("outputsFR_24jan_jetbins/Data_ele.root");
  TFile* file_DY_ele= new TFile("outputsFR_24jan_jetbins/DY_ele.root");
  TFile* file_WJets_ele= new TFile("outputsFR_24jan_jetbins/WJets_ele.root");
  TFile* file_TT_ele= new TFile("outputsFR_24jan_jetbins/TT_ele.root");
  TFile* file_Data_mu= new TFile("outputsFR_24jan_jetbins/Data_mu.root");
  TFile* file_DY_mu= new TFile("outputsFR_24jan_jetbins/DY_mu.root");
  TFile* file_WJets_mu= new TFile("outputsFR_24jan_jetbins/WJets_mu.root");
  TFile* file_TT_mu= new TFile("outputsFR_24jan_jetbins/TT_mu.root");
  
  TH1F* h_DATA_ele[5];
  TH1F* h_DY_ele[5]; 
  TH1F* h_WJets_ele[5];
  TH1F* h_denominator_DATA_ele[5];
  TH1F* h_denominator_DY_ele[5];
  TH1F* h_denominator_WJets_ele[5];
  TH1F* h_DATA_eta_ele[5];
  TH1F* h_DY_eta_ele[5];
  TH1F* h_WJets_eta_ele[5];
  TH1F* h_denominator_DATA_eta_ele[5];
  TH1F* h_denominator_DY_eta_ele[5];
  TH1F* h_denominator_WJets_eta_ele[5];
  TH1F* h_DATA_mu[5];
  TH1F* h_DY_mu[5]; 
  TH1F* h_WJets_mu[5];
  TH1F* h_denominator_DATA_mu[5];
  TH1F* h_denominator_DY_mu[5];
  TH1F* h_denominator_WJets_mu[5];
  TH1F* h_DATA_eta_mu[5];
  TH1F* h_DY_eta_mu[5];
  TH1F* h_WJets_eta_mu[5];
  TH1F* h_denominator_DATA_eta_mu[5];
  TH1F* h_denominator_DY_eta_mu[5];
  TH1F* h_denominator_WJets_eta_mu[5];
 
  h_DATA_ele[1] = (TH1F*)file_Data_ele->Get("jetcut_0/h_pt1_tight_0"); 
  h_DY_ele[1] = (TH1F*)file_DY_ele->Get("jetcut_0/h_pt1_tight_0"); 
  h_WJets_ele[1] = (TH1F*)file_WJets_ele->Get("jetcut_0/h_pt1_tight_0"); 
  h_denominator_DATA_ele[1] = (TH1F*)file_Data_ele->Get("jetcut_0/h_pt1_loose_0");
  h_denominator_DY_ele[1] = (TH1F*)file_DY_ele->Get("jetcut_0/h_pt1_loose_0");
  h_denominator_WJets_ele[1] = (TH1F*)file_WJets_ele->Get("jetcut_0/h_pt1_loose_0");
  h_DATA_eta_ele[1] = (TH1F*)file_Data_ele->Get("jetcut_0/h_eta1_tight_0");
  h_DY_eta_ele[1] = (TH1F*)file_DY_ele->Get("jetcut_0/h_eta1_tight_0");
  h_WJets_eta_ele[1] = (TH1F*)file_WJets_ele->Get("jetcut_0/h_eta1_tight_0");
  h_denominator_DATA_eta_ele[1] = (TH1F*)file_Data_ele->Get("jetcut_0/h_eta1_loose_0");
  h_denominator_DY_eta_ele[1] = (TH1F*)file_DY_ele->Get("jetcut_0/h_eta1_loose_0");
  h_denominator_WJets_eta_ele[1] = (TH1F*)file_WJets_ele->Get("jetcut_0/h_eta1_loose_0");
  h_DATA_mu[1] = (TH1F*)file_Data_mu->Get("jetcut_0/h_pt1_tight_0"); 
  h_DY_mu[1] = (TH1F*)file_DY_mu->Get("jetcut_0/h_pt1_tight_0"); 
  h_WJets_mu[1] = (TH1F*)file_WJets_mu->Get("jetcut_0/h_pt1_tight_0"); 
  h_denominator_DATA_mu[1] = (TH1F*)file_Data_mu->Get("jetcut_0/h_pt1_loose_0");
  h_denominator_DY_mu[1] = (TH1F*)file_DY_mu->Get("jetcut_0/h_pt1_loose_0");
  h_denominator_WJets_mu[1] = (TH1F*)file_WJets_mu->Get("jetcut_0/h_pt1_loose_0");
  h_DATA_eta_mu[1] = (TH1F*)file_Data_mu->Get("jetcut_0/h_eta1_tight_0");
  h_DY_eta_mu[1] = (TH1F*)file_DY_mu->Get("jetcut_0/h_eta1_tight_0");
  h_WJets_eta_mu[1] = (TH1F*)file_WJets_mu->Get("jetcut_0/h_eta1_tight_0");
  h_denominator_DATA_eta_mu[1] = (TH1F*)file_Data_mu->Get("jetcut_0/h_eta1_loose_0");
  h_denominator_DY_eta_mu[1] = (TH1F*)file_DY_mu->Get("jetcut_0/h_eta1_loose_0");
  h_denominator_WJets_eta_mu[1] = (TH1F*)file_WJets_mu->Get("jetcut_0/h_eta1_loose_0");
 
  gStyle->SetOptStat(0);
  TH1F* h_num_ele[5];TH1F* h_den_ele[5];TH1F* h_div_ele[5];TH1F* h_div_noEWKcorr_ele[5];
  //for(int j=0;j++;j<5){
    h_num_ele[1] = (TH1F*)h_DATA_ele[1]->Clone(Form("h_num_ele_%d",1));
    h_num_ele[1]->Add(h_DY_ele[1],-1);
    h_num_ele[1]->Add(h_WJets_ele[1],-1);
    h_den_ele[1] = (TH1F*)h_denominator_DATA_ele[1]->Clone(Form("h_den_ele_%d",1));
    h_den_ele[1]->Add(h_denominator_DY_ele[1],-1);
    h_den_ele[1]->Add(h_denominator_WJets_ele[1],-1);
    h_div_ele[1] = (TH1F*)h_num_ele[1]->Clone(Form("h_div_ele_%d",1));
    h_div_ele[1]->Divide(h_den_ele[1]);
    h_div_noEWKcorr_ele[1] = (TH1F*)h_DATA_ele[1]->Clone(Form("h_div_noEWKcorr_ele_%d",1));
    h_div_noEWKcorr_ele[1]->Divide(h_denominator_DATA_ele[1]);
    //}

  TH1F* h_num_mu[5];TH1F* h_den_mu[5];TH1F* h_div_mu[5];TH1F* h_div_noEWKcorr_mu[5];
  //for(int j=0;j++;j<5){
    h_num_mu[1] = (TH1F*)h_DATA_mu[1]->Clone(Form("h_num_mu_%d",1));
    h_num_mu[1]->Add(h_DY_mu[1],-1);
    h_num_mu[1]->Add(h_WJets_mu[1],-1);
    h_den_mu[1] = (TH1F*)h_denominator_DATA_mu[1]->Clone(Form("h_den_mu_%d",1));
    h_den_mu[1]->Add(h_denominator_DY_mu[1],-1);
    h_den_mu[1]->Add(h_denominator_WJets_mu[1],-1);
    h_div_mu[1] = (TH1F*)h_num_mu[1]->Clone(Form("h_div_mu_%d",1));
    h_div_mu[1]->Divide(h_den_mu[1]);
    h_div_noEWKcorr_mu[1] = (TH1F*)h_DATA_mu[1]->Clone(Form("h_div_noEWKcorr_mu_%d",1));
    h_div_noEWKcorr_mu[1]->Divide(h_denominator_DATA_mu[1]);
    //}  

  TH1F* h_relEWKcont_ele[5];TH1F* h_relEWKcont_numerator_ele[5];TH1F* h_relEWKcont2_ele[5];TH1F* h_relEWKcont_denominator_ele[5];
  //for(int j=0;j++;j<5){
    h_relEWKcont_ele[1] = (TH1F*)h_DY_ele[1]->Clone(Form("h_relEWKcont_ele_%d",1));
    h_relEWKcont_ele[1]->Add(h_WJets_ele[1],1);
    h_relEWKcont_numerator_ele[1] = (TH1F*)h_relEWKcont_ele[1]->Clone(Form("h_relEWKcont_numerator_ele_%d",1));
    h_relEWKcont_numerator_ele[1]->Divide(h_DATA_ele[1]);
    h_relEWKcont2_ele[1] = (TH1F*)h_denominator_DY_ele[1]->Clone(Form("h_relEWKcont2_ele_%d",1));
    h_relEWKcont2_ele[1]->Add(h_denominator_WJets_ele[1],1);
    h_relEWKcont_denominator_ele[1] = (TH1F*)h_relEWKcont2_ele[1]->Clone(Form("h_relEWKcont_denominator_ele_%d",1));
    h_relEWKcont_denominator_ele[1]->Divide(h_denominator_DATA_ele[1]);
    //}

  TH1F* h_relEWKcont_mu[5];TH1F* h_relEWKcont_numerator_mu[5];TH1F* h_relEWKcont2_mu[5];TH1F* h_relEWKcont_denominator_mu[5];
//for(int j=0;j++;j<5){
    h_relEWKcont_mu[1] = (TH1F*)h_DY_mu[1]->Clone(Form("h_relEWKcont_mu_%d",1));
    h_relEWKcont_mu[1]->Add(h_WJets_mu[1],1);
    h_relEWKcont_numerator_mu[1] = (TH1F*)h_relEWKcont_mu[1]->Clone(Form("h_relEWKcont_numerator_mu_%d",1));
    h_relEWKcont_numerator_mu[1]->Divide(h_DATA_mu[1]);
    h_relEWKcont2_mu[1] = (TH1F*)h_denominator_DY_mu[1]->Clone(Form("h_relEWKcont2_mu_%d",1));
    h_relEWKcont2_mu[1]->Add(h_denominator_WJets_mu[1],1);
    h_relEWKcont_denominator_mu[1] = (TH1F*)h_relEWKcont2_mu[1]->Clone(Form("h_relEWKcont_denominator_mu_%d",1));
    h_relEWKcont_denominator_mu[1]->Divide(h_denominator_DATA_mu[1]);
    //}

  TH1F* h_num_eta_ele[5];TH1F* h_den_eta_ele[5];TH1F* h_div_eta_ele[5];TH1F* h_div_noEWKcorr_eta_ele[5];
  //for(int j=0;j++;j<5){
    h_num_eta_ele[1] = (TH1F*)h_DATA_eta_ele[1]->Clone(Form("h_num_eta_ele_%d",1));
    h_num_eta_ele[1]->Add(h_DY_eta_ele[1],-1);
    h_num_eta_ele[1]->Add(h_WJets_eta_ele[1],-1);
    h_den_eta_ele[1] = (TH1F*)h_denominator_DATA_eta_ele[1]->Clone(Form("h_den_eta_ele_%d",1));
    h_den_eta_ele[1]->Add(h_denominator_DY_eta_ele[1],-1);
    h_den_eta_ele[1]->Add(h_denominator_WJets_eta_ele[1],-1);
    h_div_eta_ele[1] = (TH1F*)h_num_eta_ele[1]->Clone(Form("h_div_eta_ele_%d",1));
    h_div_eta_ele[1]->Divide(h_den_eta_ele[1]);
    h_div_noEWKcorr_eta_ele[1] = (TH1F*)h_DATA_eta_ele[1]->Clone(Form("h_div_noEWKcorr_eta_ele_%d",1));
    h_div_noEWKcorr_eta_ele[1]->Divide(h_denominator_DATA_eta_ele[1]);
    //}

  TH1F* h_num_eta_mu[5];TH1F* h_den_eta_mu[5];TH1F* h_div_eta_mu[5];TH1F* h_div_noEWKcorr_eta_mu[5];
  //for(int j=0;j++;j<5){
    h_num_eta_mu[1] = (TH1F*)h_DATA_eta_mu[1]->Clone(Form("h_num_eta_mu_%d",1));
    h_num_eta_mu[1]->Add(h_DY_eta_mu[1],-1);
    h_num_eta_mu[1]->Add(h_WJets_eta_mu[1],-1);
    h_den_eta_mu[1] = (TH1F*)h_denominator_DATA_eta_mu[1]->Clone(Form("h_den_eta_mu_%d",1));
    h_den_eta_mu[1]->Add(h_denominator_DY_eta_mu[1],-1);
    h_den_eta_mu[1]->Add(h_denominator_WJets_eta_mu[1],-1);
    h_div_eta_mu[1] = (TH1F*)h_num_eta_mu[1]->Clone(Form("h_div_eta_mu_%d",1));
    h_div_eta_mu[1]->Divide(h_den_eta_mu[1]);
    h_div_noEWKcorr_eta_mu[1] = (TH1F*)h_DATA_eta_mu[1]->Clone(Form("h_div_noEWKcorr_eta_mu_%d",1));
    h_div_noEWKcorr_eta_mu[1]->Divide(h_denominator_DATA_eta_mu[1]);
    //}

  TLegend *leg= new TLegend(0.1,0.7,0.48,0.9);
  leg->AddEntry(h_div_noEWKcorr_ele[1],"Without EWK correction");
  leg->AddEntry(h_div_ele[1],"With EWK correction");

  /////////////Efficiency errors //////////////////
  float binvalue ;
  float totaln ;
  float newerror ;
 
  //for(int j=0;j++;j<5){
    for (int i=1; i<= 8; i++) {
      binvalue = h_div_ele[1]->GetBinContent(i);
      totaln = h_den_ele[1]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_ele[1]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 8; i++) {
      binvalue = h_div_noEWKcorr_ele[1]->GetBinContent(i);
      totaln = h_denominator_DATA_ele[1]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_noEWKcorr_ele[1]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 5; i++) {
      binvalue = h_div_eta_ele[1]->GetBinContent(i);
      totaln = h_den_eta_ele[1]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_eta_ele[1]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 5; i++) {
      binvalue = h_div_noEWKcorr_eta_ele[1]->GetBinContent(i);
      totaln = h_denominator_DATA_eta_ele[1]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_noEWKcorr_eta_ele[1]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 8; i++) {
      binvalue = h_div_mu[1]->GetBinContent(i);
      totaln = h_den_mu[1]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_mu[1]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 8; i++) {
      binvalue = h_div_noEWKcorr_mu[1]->GetBinContent(i);
      totaln = h_denominator_DATA_mu[1]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_noEWKcorr_mu[1]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 5; i++) {
      binvalue = h_div_eta_mu[1]->GetBinContent(i);
      totaln = h_den_eta_mu[1]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_eta_mu[1]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 5; i++) {
      binvalue = h_div_noEWKcorr_eta_mu[1]->GetBinContent(i);
      totaln = h_denominator_DATA_eta_mu[1]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_noEWKcorr_eta_mu[1]->SetBinError(i,newerror);
    }
    //}
  /////////////////////////////////////////////
     
  TCanvas *c[3][2][5];
  //for(int j=0;j++;j<5){
    c[0][0][1]= new TCanvas();c[0][0][1]->cd();
    h_div_ele[1]->Draw("E"); h_div_ele[1]->GetYaxis()->SetRangeUser(0,1); h_div_ele[1]->SetTitle("Electron_mvaFall17Iso_WP90 fake rate"); h_div_ele[1]->SetLineColor(2); h_div_ele[1]->GetXaxis()->SetTitle("p_{T} [GeV]"); h_div_ele[1]->GetYaxis()->SetTitle("Ele fake rate");c[0][0][1]->SetGridx(1);c[0][0][1]->SetGridy(1); h_div_ele[1]->SetLineWidth(2); h_div_ele[1]->SetMarkerColor(2);  h_div_ele[1]->SetMarkerStyle(kFullCircle);
    h_div_noEWKcorr_ele[1]->Draw("sameE"); h_div_noEWKcorr_ele[1]->SetLineColor(1);h_div_noEWKcorr_ele[1]->SetLineWidth(2); h_div_noEWKcorr_ele[1]->SetMarkerColor(1);  h_div_noEWKcorr_ele[1]->SetMarkerStyle(kFullCircle);
    leg->Draw();c[0][0][1]->SaveAs(Form("eleFR_pt_jet%d.gif",1*5+20));
    c[0][1][1]= new TCanvas();c[0][1][1]->cd();
    h_div_mu[1]->Draw("E"); h_div_mu[1]->GetYaxis()->SetRangeUser(0,1); h_div_mu[1]->SetTitle("TightMuon_cut_Tight_HWWW fake rate"); h_div_mu[1]->SetLineColor(2); h_div_mu[1]->GetXaxis()->SetTitle("p_{T} [GeV]"); h_div_mu[1]->GetYaxis()->SetTitle("Mu fake rate");c[0][1][1]->SetGridx(1);c[0][1][1]->SetGridy(1); h_div_mu[1]->SetLineWidth(2); h_div_mu[1]->SetMarkerColor(2);  h_div_mu[1]->SetMarkerStyle(kFullCircle);
    h_div_noEWKcorr_mu[1]->Draw("sameE"); h_div_noEWKcorr_mu[1]->SetLineColor(1);h_div_noEWKcorr_mu[1]->SetLineWidth(2); h_div_noEWKcorr_mu[1]->SetMarkerColor(1);  h_div_noEWKcorr_mu[1]->SetMarkerStyle(kFullCircle);
    leg->Draw();c[0][1][1]->SaveAs(Form("muFR_pt_jet%d.gif",1*5+20));

    c[1][0][1]= new TCanvas();c[1][0][1]->cd();
    h_relEWKcont_numerator_ele[1]->Draw();h_relEWKcont_numerator_ele[1]->GetYaxis()->SetRangeUser(0,1);h_relEWKcont_numerator_ele[1]->SetTitle("Electron EWK contamination (numerator)"); h_relEWKcont_numerator_ele[1]->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_numerator_ele[1]->GetXaxis()->SetTitle("Pt1 [GeV]");c[1][0][1]->SaveAs(Form("EWK_contamination_ele_numerator_jet%d.gif",1*5+20));
    h_relEWKcont_denominator_ele[1]->Draw();h_relEWKcont_denominator_ele[1]->GetYaxis()->SetRangeUser(0,1);h_relEWKcont_denominator_ele[1]->SetTitle("Electron EWK contamination (denominator)"); h_relEWKcont_denominator_ele[1]->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_denominator_ele[1]->GetXaxis()->SetTitle("Pt1 [GeV]");c[1][0][1]->SaveAs(Form("EWK_contamination_ele_denominator_jet%d.gif",1*5+20));
    c[1][1][1]= new TCanvas();c[1][1][1]->cd();
    h_relEWKcont_numerator_mu[1]->Draw();h_relEWKcont_numerator_mu[1]->GetYaxis()->SetRangeUser(0,1);h_relEWKcont_numerator_mu[1]->SetTitle("Muon EWK contamination (numerator)"); h_relEWKcont_numerator_mu[1]->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_numerator_mu[1]->GetXaxis()->SetTitle("Pt1 [GeV]");c[1][1][1]->SaveAs(Form("EWK_contamination_mu_numerator_jet%d.gif",1*5+20));
    h_relEWKcont_denominator_mu[1]->Draw();h_relEWKcont_denominator_mu[1]->GetYaxis()->SetRangeUser(0,1);h_relEWKcont_denominator_mu[1]->SetTitle("Muon EWK contamination (denominator)"); h_relEWKcont_denominator_mu[1]->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_denominator_mu[1]->GetXaxis()->SetTitle("Pt1 [GeV]");c[1][1][1]->SaveAs(Form("EWK_contamination_mu_denominator_jet%d.gif",1*5+20));

    c[2][0][1]= new TCanvas();c[2][0][1]->cd();
    h_div_eta_ele[1]->Draw("E"); h_div_eta_ele[1]->GetYaxis()->SetRangeUser(0,1); h_div_eta_ele[1]->SetTitle("Electron_mvaFall17Iso_WP90 fake rate"); h_div_eta_ele[1]->SetLineColor(2); h_div_eta_ele[1]->GetXaxis()->SetTitle("p_{T} [GeV]"); h_div_eta_ele[1]->GetYaxis()->SetTitle("Ele fake rate");c[2][0][1]->SetGridx(1);c[2][0][1]->SetGridy(1); h_div_eta_ele[1]->SetLineWidth(2); h_div_eta_ele[1]->SetMarkerColor(2);  h_div_eta_ele[1]->SetMarkerStyle(kFullCircle);
    h_div_noEWKcorr_eta_ele[1]->Draw("sameE"); h_div_noEWKcorr_eta_ele[1]->SetLineColor(1);h_div_noEWKcorr_eta_ele[1]->SetLineWidth(2); h_div_noEWKcorr_eta_ele[1]->SetMarkerColor(1);  h_div_noEWKcorr_eta_ele[1]->SetMarkerStyle(kFullCircle);
    leg->Draw();c[2][0][1]->SaveAs(Form("eleFR_eta_jet%d.gif",1*5+20));
    c[2][1][1]= new TCanvas();c[2][1][1]->cd();
    h_div_eta_mu[1]->Draw("E"); h_div_eta_mu[1]->GetYaxis()->SetRangeUser(0,1); h_div_eta_mu[1]->SetTitle("TightMuon_cut_Tight_HWWW fake rate"); h_div_eta_mu[1]->SetLineColor(2); h_div_eta_mu[1]->GetXaxis()->SetTitle("p_{T} [GeV]"); h_div_eta_mu[1]->GetYaxis()->SetTitle("Mu fake rate");c[2][1][1]->SetGridx(1);c[2][1][1]->SetGridy(1); h_div_eta_mu[1]->SetLineWidth(2); h_div_eta_mu[1]->SetMarkerColor(2);  h_div_eta_mu[1]->SetMarkerStyle(kFullCircle);
    h_div_noEWKcorr_eta_mu[1]->Draw("sameE"); h_div_noEWKcorr_eta_mu[1]->SetLineColor(1);h_div_noEWKcorr_eta_mu[1]->SetLineWidth(2); h_div_noEWKcorr_eta_mu[1]->SetMarkerColor(1);  h_div_noEWKcorr_eta_mu[1]->SetMarkerStyle(kFullCircle);
    leg->Draw();c[2][1][1]->SaveAs(Form("muFR_eta_jet%d.gif",1*5+20));
    //}
 
  cout<<"THE END"<<endl;
 
}



 
