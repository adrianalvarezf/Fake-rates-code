#include "TCanvas.h"
#include "TTree.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

void division_forfakes_dataonly(TString year)
{

  TFile* file_Data_ele= new TFile("outputsFR_2017_6mar_eleHLT_test/Data_ele.root");
  //TFile* file_Data_ele= new TFile("outputsFR_"+year+"_6mar_Lepton_isTightElectron/Data_ele.root");
  TFile* file_Data_mu = new TFile("outputsFR_"+year+"_6mar_Lepton_isTightElectron/Data_mu.root");
  TFile* file_Data_ele17= new TFile("outputsFR_2017_6mar_Lepton_isTightElectron/Data_ele.root");
  TFile* file_Data_mu17 = new TFile("outputsFR_2017_6mar_Lepton_isTightElectron/Data_mu.root");

  TH1F* h_DATA_ele[8];
  TH1F* h_denominator_DATA_ele[8];
  TH1F* h_DATA_eta_ele[8];
  TH1F* h_denominator_DATA_eta_ele[8];
  TH1F* h_DATA_mu[8];
  TH1F* h_denominator_DATA_mu[8];
  TH1F* h_DATA_eta_mu[8];
  TH1F* h_denominator_DATA_eta_mu[8];
  TH1F* h_DATA_ele17;
  TH1F* h_denominator_DATA_ele17;
  TH1F* h_DATA_eta_ele17;
  TH1F* h_denominator_DATA_eta_ele17;
  TH1F* h_DATA_mu17;
  TH1F* h_denominator_DATA_mu17;
  TH1F* h_DATA_eta_mu17;
  TH1F* h_denominator_DATA_eta_mu17;
  
  for(int j=0;j<8;j++){
    /*
    h_DATA_ele[j] = (TH1F*)file_Data_ele->Get(Form("jetcut_%d/h_pt1_tight_noHLT_%d",j,j)); 
    h_denominator_DATA_ele[j] = (TH1F*)file_Data_ele->Get(Form("jetcut_%d/h_pt1_loose_noHLT_%d",j,j));
    h_DATA_eta_ele[j] = (TH1F*)file_Data_ele->Get(Form("jetcut_%d/h_eta1_tight_noHLT_%d",j,j));
    h_denominator_DATA_eta_ele[j] = (TH1F*)file_Data_ele->Get(Form("jetcut_%d/h_eta1_loose_noHLT_%d",j,j));
    */   
    h_DATA_ele[j] = (TH1F*)file_Data_ele->Get(Form("jetcut_%d/h_pt1_tight_12_%d",j,j)); 
    h_denominator_DATA_ele[j] = (TH1F*)file_Data_ele->Get(Form("jetcut_%d/h_pt1_loose_12_%d",j,j));
    h_DATA_eta_ele[j] = (TH1F*)file_Data_ele->Get(Form("jetcut_%d/h_eta1_tight_12_%d",j,j));
    h_denominator_DATA_eta_ele[j] = (TH1F*)file_Data_ele->Get(Form("jetcut_%d/h_eta1_loose_12_%d",j,j));
    
    /* 
       h_DATA_ele[j] = (TH1F*)file_Data_ele->Get(Form("jetcut_%d/h_pt1_tight_%d",j,j)); 
       h_denominator_DATA_ele[j] = (TH1F*)file_Data_ele->Get(Form("jetcut_%d/h_pt1_loose_%d",j,j));
       h_DATA_eta_ele[j] = (TH1F*)file_Data_ele->Get(Form("jetcut_%d/h_eta1_tight_%d",j,j));
       h_denominator_DATA_eta_ele[j] = (TH1F*)file_Data_ele->Get(Form("jetcut_%d/h_eta1_loose_%d",j,j));
    */   
    h_DATA_mu[j] = (TH1F*)file_Data_mu->Get(Form("jetcut_%d/h_pt1_tight_%d",j,j)); 
    h_denominator_DATA_mu[j] = (TH1F*)file_Data_mu->Get(Form("jetcut_%d/h_pt1_loose_%d",j,j));
    h_DATA_eta_mu[j] = (TH1F*)file_Data_mu->Get(Form("jetcut_%d/h_eta1_tight_%d",j,j));
    h_denominator_DATA_eta_mu[j] = (TH1F*)file_Data_mu->Get(Form("jetcut_%d/h_eta1_loose_%d",j,j));
  }
  
  h_DATA_ele17 = (TH1F*)file_Data_ele17->Get("jetcut_5/h_pt1_tight_5");
  h_denominator_DATA_ele17 = (TH1F*)file_Data_ele17->Get("jetcut_5/h_pt1_loose_5");
  h_DATA_eta_ele17 = (TH1F*)file_Data_ele17->Get("jetcut_5/h_eta1_tight_5");
  h_denominator_DATA_eta_ele17 = (TH1F*)file_Data_ele17->Get("jetcut_5/h_eta1_loose_5");
  h_DATA_mu17 = (TH1F*)file_Data_mu17->Get("jetcut_3/h_pt1_tight_3");
  h_denominator_DATA_mu17 = (TH1F*)file_Data_mu17->Get("jetcut_3/h_pt1_loose_3");
  h_DATA_eta_mu17 = (TH1F*)file_Data_mu17->Get("jetcut_3/h_eta1_tight_3");
  h_denominator_DATA_eta_mu17 = (TH1F*)file_Data_mu17->Get("jetcut_3/h_eta1_loose_3");
  
  gStyle->SetOptStat(0);
  TH1F* h_div_noEWKcorr_ele[8];
  for(int j=0;j<8;j++){
    h_div_noEWKcorr_ele[j] = (TH1F*)h_DATA_ele[j]->Clone(Form("h_div_noEWKcorr_ele_%d",j));
    h_div_noEWKcorr_ele[j]->Divide(h_denominator_DATA_ele[j]);
  }
  TH1F* h_div_noEWKcorr_mu[8];
  for(int j=0;j<8;j++){
    h_div_noEWKcorr_mu[j] = (TH1F*)h_DATA_mu[j]->Clone(Form("h_div_noEWKcorr_mu_%d",j));
    h_div_noEWKcorr_mu[j]->Divide(h_denominator_DATA_mu[j]);
  }  
  TH1F* h_div_noEWKcorr_eta_ele[8];
  for(int j=0;j<8;j++){
    h_div_noEWKcorr_eta_ele[j] = (TH1F*)h_DATA_eta_ele[j]->Clone(Form("h_div_noEWKcorr_eta_ele_%d",j));
    h_div_noEWKcorr_eta_ele[j]->Divide(h_denominator_DATA_eta_ele[j]);
  }
  TH1F* h_div_noEWKcorr_eta_mu[8];
  for(int j=0;j<8;j++){
    h_div_noEWKcorr_eta_mu[j] = (TH1F*)h_DATA_eta_mu[j]->Clone(Form("h_div_noEWKcorr_eta_mu_%d",j));
    h_div_noEWKcorr_eta_mu[j]->Divide(h_denominator_DATA_eta_mu[j]);
  }

  TH1F* h_div_noEWKcorr_ele17; TH1F* h_div_noEWKcorr_mu17; TH1F* h_div_noEWKcorr_eta_ele17; TH1F* h_div_noEWKcorr_eta_mu17;
  h_div_noEWKcorr_ele17 = (TH1F*)h_DATA_ele17->Clone("h_div_noEWKcorr_ele17");
  h_div_noEWKcorr_ele17->Divide(h_denominator_DATA_ele17);
  h_div_noEWKcorr_mu17 = (TH1F*)h_DATA_mu17->Clone("h_div_noEWKcorr_mu17");
  h_div_noEWKcorr_mu17->Divide(h_denominator_DATA_mu17);
  h_div_noEWKcorr_eta_ele17 = (TH1F*)h_DATA_eta_ele17->Clone("h_div_noEWKcorr_eta_ele17");
  h_div_noEWKcorr_eta_ele17->Divide(h_denominator_DATA_eta_ele17);
  h_div_noEWKcorr_eta_mu17 = (TH1F*)h_DATA_eta_mu17->Clone("h_div_noEWKcorr_eta_mu17");
  h_div_noEWKcorr_eta_mu17->Divide(h_denominator_DATA_eta_mu17);
  
  /////////////Efficiency errors //////////////////
  float binvalue ;
  float totaln ;
  float newerror ;
  //2016 or 2018
  for(int j=0;j<8;j++){
    for (int i=1; i<= 8; i++) {
      binvalue = h_div_noEWKcorr_ele[j]->GetBinContent(i);
      totaln = h_denominator_DATA_ele[j]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_noEWKcorr_ele[j]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 5; i++) {
      binvalue = h_div_noEWKcorr_eta_ele[j]->GetBinContent(i);
      totaln = h_denominator_DATA_eta_ele[j]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_noEWKcorr_eta_ele[j]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 8; i++) {
      binvalue = h_div_noEWKcorr_mu[j]->GetBinContent(i);
      totaln = h_denominator_DATA_mu[j]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_noEWKcorr_mu[j]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 5; i++) {
      binvalue = h_div_noEWKcorr_eta_mu[j]->GetBinContent(i);
      totaln = h_denominator_DATA_eta_mu[j]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_noEWKcorr_eta_mu[j]->SetBinError(i,newerror);
    }
  }
  //2017
  for (int i=1; i<= 8; i++) {
    binvalue = h_div_noEWKcorr_ele17->GetBinContent(i);
    totaln = h_denominator_DATA_ele17->GetBinContent(i);
    newerror = sqrt((binvalue*(1-binvalue))/totaln);
    h_div_noEWKcorr_ele17->SetBinError(i,newerror);
  }
  for (int i=1; i<= 5; i++) {
    binvalue = h_div_noEWKcorr_eta_ele17->GetBinContent(i);
    totaln = h_denominator_DATA_eta_ele17->GetBinContent(i);
    newerror = sqrt((binvalue*(1-binvalue))/totaln);
    h_div_noEWKcorr_eta_ele17->SetBinError(i,newerror);
  }
  for (int i=1; i<= 8; i++) {
    binvalue = h_div_noEWKcorr_mu17->GetBinContent(i);
    totaln = h_denominator_DATA_mu17->GetBinContent(i);
    newerror = sqrt((binvalue*(1-binvalue))/totaln);
    h_div_noEWKcorr_mu17->SetBinError(i,newerror);
  }
  for (int i=1; i<= 5; i++) {
    binvalue = h_div_noEWKcorr_eta_mu17->GetBinContent(i);
    totaln = h_denominator_DATA_eta_mu17->GetBinContent(i);
    newerror = sqrt((binvalue*(1-binvalue))/totaln);
    h_div_noEWKcorr_eta_mu17->SetBinError(i,newerror);
  }
  ////////////////////////////////////
  ///Plots 2017 vs 2018-> 25GeV for muons, 35 GeV for electrons////  
  /*
  TLegend *yearleg= new TLegend(0.1,0.7,0.48,0.9);
  yearleg->AddEntry(h_div_noEWKcorr_ele[5], year+" Data");
  yearleg->AddEntry(h_div_noEWKcorr_ele17 ,"2017 Data");  

  TCanvas* c_pt_ele= new TCanvas();
  c_pt_ele->cd();
  h_div_noEWKcorr_ele[5]->Draw(); h_div_noEWKcorr_ele[5]->GetYaxis()->SetRangeUser(0,1); h_div_noEWKcorr_ele[5]->SetTitle("Electron fake rate"); h_div_noEWKcorr_ele[5]->GetXaxis()->SetTitle("p_{T} [GeV]"); 
  h_div_noEWKcorr_ele[5]->GetYaxis()->SetTitle("Ele fake rate");c_pt_ele->SetGridx(1);c_pt_ele->SetGridy(1); h_div_noEWKcorr_ele[5]->SetLineWidth(2); h_div_noEWKcorr_ele[5]->SetMarkerStyle(kFullCircle) ;
  h_div_noEWKcorr_ele[5]->SetLineColor(1); h_div_noEWKcorr_ele[5]->SetMarkerColor(1);
  h_div_noEWKcorr_ele17->Draw("same"); h_div_noEWKcorr_ele17->SetLineColor(2); h_div_noEWKcorr_ele17->SetMarkerColor(2); h_div_noEWKcorr_ele17->SetLineWidth(2); 
  h_div_noEWKcorr_ele17->SetMarkerStyle(kFullCircle); yearleg->Draw(); c_pt_ele->SaveAs("years2017and"+year+"_pt_eleFR.gif");

  TCanvas* c_pt_mu= new TCanvas();
  c_pt_mu->cd();
  h_div_noEWKcorr_mu[3]->Draw(); h_div_noEWKcorr_mu[3]->GetYaxis()->SetRangeUser(0,1); h_div_noEWKcorr_mu[3]->SetTitle("Muon fake rate"); h_div_noEWKcorr_mu[3]->GetXaxis()->SetTitle("p_{T} [GeV]"); 
  h_div_noEWKcorr_mu[3]->GetYaxis()->SetTitle("Mu fake rate");c_pt_mu->SetGridx(1);c_pt_mu->SetGridy(1); h_div_noEWKcorr_mu[3]->SetLineWidth(2); h_div_noEWKcorr_mu[3]->SetMarkerStyle(kFullCircle) ;
  h_div_noEWKcorr_mu[3]->SetLineColor(1); h_div_noEWKcorr_mu[3]->SetMarkerColor(1);
  h_div_noEWKcorr_mu17->Draw("same"); h_div_noEWKcorr_mu17->SetLineColor(2); h_div_noEWKcorr_mu17->SetMarkerColor(2); h_div_noEWKcorr_mu17->SetLineWidth(2); 
  h_div_noEWKcorr_mu17->SetMarkerStyle(kFullCircle); yearleg->Draw(); c_pt_mu->SaveAs("years2017and"+year+"_pt_muFR.gif");

  TCanvas* c_eta_ele= new TCanvas();
  c_eta_ele->cd();
  h_div_noEWKcorr_eta_ele[5]->Draw(); h_div_noEWKcorr_eta_ele[5]->GetYaxis()->SetRangeUser(0,1); h_div_noEWKcorr_eta_ele[5]->SetTitle("Electron fake rate"); h_div_noEWKcorr_eta_ele[5]->GetXaxis()->SetTitle("|#eta|");  h_div_noEWKcorr_eta_ele[5]->GetYaxis()->SetTitle("Ele fake rate");c_eta_ele->SetGridx(1);c_eta_ele->SetGridy(1); h_div_noEWKcorr_eta_ele[5]->SetLineWidth(2); h_div_noEWKcorr_eta_ele[5]->SetMarkerStyle(kFullCircle) ;  h_div_noEWKcorr_eta_ele[5]->SetLineColor(1); h_div_noEWKcorr_eta_ele[5]->SetMarkerColor(1);
  h_div_noEWKcorr_eta_ele17->Draw("same"); h_div_noEWKcorr_eta_ele17->SetLineColor(2); h_div_noEWKcorr_eta_ele17->SetMarkerColor(2); h_div_noEWKcorr_eta_ele17->SetLineWidth(2); 
  h_div_noEWKcorr_eta_ele17->SetMarkerStyle(kFullCircle); yearleg->Draw(); c_eta_ele->SaveAs("years2017and"+year+"_eta_eleFR.gif");

  TCanvas* c_eta_mu= new TCanvas();
  c_eta_mu->cd();
  h_div_noEWKcorr_eta_mu[3]->Draw(); h_div_noEWKcorr_eta_mu[3]->GetYaxis()->SetRangeUser(0,1); h_div_noEWKcorr_eta_mu[3]->SetTitle("Muon fake rate"); h_div_noEWKcorr_eta_mu[3]->GetXaxis()->SetTitle("|#eta|");  h_div_noEWKcorr_eta_mu[3]->GetYaxis()->SetTitle("Mu fake rate");c_eta_mu->SetGridx(1);c_eta_mu->SetGridy(1); h_div_noEWKcorr_eta_mu[3]->SetLineWidth(2); h_div_noEWKcorr_eta_mu[3]->SetMarkerStyle(kFullCircle) ; h_div_noEWKcorr_eta_mu[3]->SetLineColor(1); h_div_noEWKcorr_eta_mu[3]->SetMarkerColor(1);
  h_div_noEWKcorr_eta_mu17->Draw("same"); h_div_noEWKcorr_eta_mu17->SetLineColor(2); h_div_noEWKcorr_eta_mu17->SetMarkerColor(2); h_div_noEWKcorr_eta_mu17->SetLineWidth(2); 
  h_div_noEWKcorr_eta_mu17->SetMarkerStyle(kFullCircle); yearleg->Draw(); c_eta_mu->SaveAs("years2017and"+year+"_eta_muFR.gif");
  */
  /////////////Combined plots//////////////////////
  
  TLegend *combinedleg= new TLegend(0.1,0.7,0.48,0.9);
  combinedleg->AddEntry(h_div_noEWKcorr_ele[0],"jet pt >10 GeV");
  combinedleg->AddEntry(h_div_noEWKcorr_ele[1],"jet pt >15 GeV");
  combinedleg->AddEntry(h_div_noEWKcorr_ele[2],"jet pt >20 GeV");
  combinedleg->AddEntry(h_div_noEWKcorr_ele[3],"jet pt >25 GeV");
  combinedleg->AddEntry(h_div_noEWKcorr_ele[4],"jet pt >30 GeV");
  combinedleg->AddEntry(h_div_noEWKcorr_ele[5],"jet pt >35 GeV");
  combinedleg->AddEntry(h_div_noEWKcorr_ele[6],"jet pt >40 GeV");
  combinedleg->AddEntry(h_div_noEWKcorr_ele[7],"jet pt >45 GeV");

  TCanvas* combined_pt_ele= new TCanvas();
  combined_pt_ele->cd();
  h_div_noEWKcorr_ele[0]->Draw(); h_div_noEWKcorr_ele[0]->GetYaxis()->SetRangeUser(0,1); h_div_noEWKcorr_ele[0]->SetTitle("Electron fake rate"); h_div_noEWKcorr_ele[0]->GetXaxis()->SetTitle("p_{T} [GeV]"); h_div_noEWKcorr_ele[0]->GetYaxis()->SetTitle("Ele fake rate");combined_pt_ele->SetGridx(1);combined_pt_ele->SetGridy(1); h_div_noEWKcorr_ele[0]->SetLineWidth(2);  h_div_noEWKcorr_ele[0]->SetMarkerStyle(kFullCircle); h_div_noEWKcorr_ele[0]->SetLineColor(6); h_div_noEWKcorr_ele[0]->SetMarkerColor(6);
  for(int j=1;j<5;j++){h_div_noEWKcorr_ele[j]->Draw("same"); h_div_noEWKcorr_ele[j]->SetLineColor(j); h_div_noEWKcorr_ele[j]->SetMarkerColor(j); h_div_noEWKcorr_ele[j]->SetLineWidth(2);  h_div_noEWKcorr_ele[j]->SetMarkerStyle(kFullCircle);}
  h_div_noEWKcorr_ele[5]->Draw("same"); h_div_noEWKcorr_ele[5]->SetLineColor(17); h_div_noEWKcorr_ele[5]->SetMarkerColor(17); h_div_noEWKcorr_ele[5]->SetLineWidth(2);  h_div_noEWKcorr_ele[5]->SetMarkerStyle(kFullCircle);
  for(int j=6;j<8;j++){h_div_noEWKcorr_ele[j]->Draw("same"); h_div_noEWKcorr_ele[j]->SetLineColor(j+1); h_div_noEWKcorr_ele[j]->SetMarkerColor(j+1); h_div_noEWKcorr_ele[j]->SetLineWidth(2);  h_div_noEWKcorr_ele[j]->SetMarkerStyle(kFullCircle);}
  combinedleg->Draw(); combined_pt_ele->SaveAs("combined_pt_"+year+"_eleFR.gif");
  TCanvas* combined_eta_ele= new TCanvas(); 
  combined_eta_ele->cd();
  h_div_noEWKcorr_eta_ele[0]->Draw(); h_div_noEWKcorr_eta_ele[0]->GetYaxis()->SetRangeUser(0,1); h_div_noEWKcorr_eta_ele[0]->SetTitle("Electron fake rate"); h_div_noEWKcorr_eta_ele[0]->GetXaxis()->SetTitle("|#eta|"); h_div_noEWKcorr_eta_ele[0]->GetYaxis()->SetTitle("Ele fake rate");combined_eta_ele->SetGridx(1);combined_eta_ele->SetGridy(1); h_div_noEWKcorr_eta_ele[0]->SetLineWidth(2);  h_div_noEWKcorr_eta_ele[0]->SetMarkerStyle(kFullCircle); h_div_noEWKcorr_eta_ele[0]->SetLineColor(6); h_div_noEWKcorr_eta_ele[0]->SetMarkerColor(6);
  for(int j=1;j<5;j++){h_div_noEWKcorr_eta_ele[j]->Draw("same"); h_div_noEWKcorr_eta_ele[j]->SetLineColor(j); h_div_noEWKcorr_eta_ele[j]->SetMarkerColor(j); h_div_noEWKcorr_eta_ele[j]->SetLineWidth(2);  h_div_noEWKcorr_eta_ele[j]->SetMarkerStyle(kFullCircle);}
  h_div_noEWKcorr_eta_ele[5]->Draw("same"); h_div_noEWKcorr_eta_ele[5]->SetLineColor(17); h_div_noEWKcorr_eta_ele[5]->SetMarkerColor(17); h_div_noEWKcorr_eta_ele[5]->SetLineWidth(2);  h_div_noEWKcorr_eta_ele[5]->SetMarkerStyle(kFullCircle);
  for(int j=6;j<8;j++){h_div_noEWKcorr_eta_ele[j]->Draw("same"); h_div_noEWKcorr_eta_ele[j]->SetLineColor(j+1); h_div_noEWKcorr_eta_ele[j]->SetMarkerColor(j+1); h_div_noEWKcorr_eta_ele[j]->SetLineWidth(2);  h_div_noEWKcorr_eta_ele[j]->SetMarkerStyle(kFullCircle);}
  combinedleg->Draw();combined_eta_ele->SaveAs("combined_eta_"+year+"_eleFR.gif");
  /*
TCanvas* combined_pt_mu= new TCanvas();
  combined_pt_mu->cd();
  h_div_noEWKcorr_mu[0]->Draw(); h_div_noEWKcorr_mu[0]->GetYaxis()->SetRangeUser(0,1); h_div_noEWKcorr_mu[0]->SetTitle("Muon fake rate"); h_div_noEWKcorr_mu[0]->GetXaxis()->SetTitle("p_{T} [GeV]"); h_div_noEWKcorr_mu[0]->GetYaxis()->SetTitle("Mu fake rate");combined_pt_mu->SetGridx(1);combined_pt_mu->SetGridy(1); h_div_noEWKcorr_mu[0]->SetLineWidth(2);  h_div_noEWKcorr_mu[0]->SetMarkerStyle(kFullCircle); h_div_noEWKcorr_mu[0]->SetLineColor(6); h_div_noEWKcorr_mu[0]->SetMarkerColor(6);
  for(int j=1;j<5;j++){h_div_noEWKcorr_mu[j]->Draw("same"); h_div_noEWKcorr_mu[j]->SetLineColor(j); h_div_noEWKcorr_mu[j]->SetMarkerColor(j); h_div_noEWKcorr_mu[j]->SetLineWidth(2);  h_div_noEWKcorr_mu[j]->SetMarkerStyle(kFullCircle);}
  h_div_noEWKcorr_mu[5]->Draw("same"); h_div_noEWKcorr_mu[5]->SetLineColor(17); h_div_noEWKcorr_mu[5]->SetMarkerColor(17); h_div_noEWKcorr_mu[5]->SetLineWidth(2);  h_div_noEWKcorr_mu[5]->SetMarkerStyle(kFullCircle);
  for(int j=6;j<8;j++){h_div_noEWKcorr_mu[j]->Draw("same"); h_div_noEWKcorr_mu[j]->SetLineColor(j+1); h_div_noEWKcorr_mu[j]->SetMarkerColor(j+1); h_div_noEWKcorr_mu[j]->SetLineWidth(2);  h_div_noEWKcorr_mu[j]->SetMarkerStyle(kFullCircle);}
  combinedleg->Draw();combined_pt_mu->SaveAs("combined_pt_"+year+"_muFR.gif");
   TCanvas* combined_eta_mu= new TCanvas();
  combined_eta_mu->cd();
  h_div_noEWKcorr_eta_mu[0]->Draw(); h_div_noEWKcorr_eta_mu[0]->GetYaxis()->SetRangeUser(0,1); h_div_noEWKcorr_eta_mu[0]->SetTitle("Muon fake rate"); h_div_noEWKcorr_eta_mu[0]->GetXaxis()->SetTitle("|#eta|"); h_div_noEWKcorr_eta_mu[0]->GetYaxis()->SetTitle("Mu fake rate");combined_eta_mu->SetGridx(1);combined_eta_mu->SetGridy(1); h_div_noEWKcorr_eta_mu[0]->SetLineWidth(2);  h_div_noEWKcorr_eta_mu[0]->SetMarkerStyle(kFullCircle); h_div_noEWKcorr_eta_mu[0]->SetLineColor(6); h_div_noEWKcorr_eta_mu[0]->SetMarkerColor(6);
  for(int j=1;j<5;j++){h_div_noEWKcorr_eta_mu[j]->Draw("same"); h_div_noEWKcorr_eta_mu[j]->SetLineColor(j); h_div_noEWKcorr_eta_mu[j]->SetMarkerColor(j); h_div_noEWKcorr_eta_mu[j]->SetLineWidth(2);  h_div_noEWKcorr_eta_mu[j]->SetMarkerStyle(kFullCircle);}
  h_div_noEWKcorr_eta_mu[5]->Draw("same"); h_div_noEWKcorr_eta_mu[5]->SetLineColor(17); h_div_noEWKcorr_eta_mu[5]->SetMarkerColor(17); h_div_noEWKcorr_eta_mu[5]->SetLineWidth(2);  h_div_noEWKcorr_eta_mu[5]->SetMarkerStyle(kFullCircle);
  for(int j=6;j<8;j++){h_div_noEWKcorr_eta_mu[j]->Draw("same"); h_div_noEWKcorr_eta_mu[j]->SetLineColor(j+1); h_div_noEWKcorr_eta_mu[j]->SetMarkerColor(j+1); h_div_noEWKcorr_eta_mu[j]->SetLineWidth(2);  h_div_noEWKcorr_eta_mu[j]->SetMarkerStyle(kFullCircle);}
  combinedleg->Draw();combined_eta_mu->SaveAs("combined_eta_"+year+"_muFR.gif");
  */
  cout<<"THE END"<<endl;
}



 
