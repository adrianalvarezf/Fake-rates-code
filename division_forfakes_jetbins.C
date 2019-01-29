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
  //char* h_name_pt_tight[5];//={"jetcut_0/h_pt1_tight_0","jetcut_1/h_pt1_tight_1","jetcut_2/h_pt1_tight_2","jetcut_3/h_pt1_tight_3","jetcut_4/h_pt1_tight_4"};
  //char* h_name_eta_tight[5];//={"jetcut_0/h_eta1_tight_0","jetcut_1/h_eta1_tight_1","jetcut_2/h_eta1_tight_2","jetcut_3/h_eta1_tight_3","jetcut_4/h_eta1_tight_4"};
  //char* h_name_pt_loose[5];//={"jetcut_0/h_pt1_loose_0","jetcut_1/h_pt1_loose_1","jetcut_2/h_pt1_loose_2","jetcut_3/h_pt1_loose_3","jetcut_4/h_pt1_loose_4"};
  //char* h_name_eta_loose[5];//={"jetcut_0/h_eta1_loose_0","jetcut_1/h_eta1_loose_1","jetcut_2/h_eta1_loose_2","jetcut_3/h_eta1_loose_3","jetcut_4/h_eta1_loose_4"};
  //cout<<h_name_pt_tight[0]<<" aaa "<<endl;
  //for(int j=0;j++;j<5){
  //h_name_pt_tight[j]=Form("jetcut_%d/h_pt1_tight_%d",j,j);
  //cout<<h_name_pt_tight[j]<<" aaaa"<<endl;
  //h_name_eta_tight[j]=Form("jetcut_%d/h_eta1_tight_%d",j,j);
  //h_name_pt_loose[j]=Form("jetcut_%d/h_pt1_loose_%d",j,j);
  //h_name_eta_loose[j]=Form("jetcut_%d/h_eta1_loose_%d",j,j);
  h_DATA_ele[0] = (TH1F*)file_Data_ele->Get("jetcut_0/h_pt1_tight_0"); 
  h_DY_ele[0] = (TH1F*)file_DY_ele->Get("jetcut_0/h_pt1_tight_0"); 
  h_WJets_ele[0] = (TH1F*)file_WJets_ele->Get("jetcut_0/h_pt1_tight_0"); 
  h_denominator_DATA_ele[0] = (TH1F*)file_Data_ele->Get("jetcut_0/h_pt1_loose_0");
  h_denominator_DY_ele[0] = (TH1F*)file_DY_ele->Get("jetcut_0/h_pt1_loose_0");
  h_denominator_WJets_ele[0] = (TH1F*)file_WJets_ele->Get("jetcut_0/h_pt1_loose_0");
  h_DATA_eta_ele[0] = (TH1F*)file_Data_ele->Get("jetcut_0/h_eta1_tight_0");
  h_DY_eta_ele[0] = (TH1F*)file_DY_ele->Get("jetcut_0/h_eta1_tight_0");
  h_WJets_eta_ele[0] = (TH1F*)file_WJets_ele->Get("jetcut_0/h_eta1_tight_0");
  h_denominator_DATA_eta_ele[0] = (TH1F*)file_Data_ele->Get("jetcut_0/h_eta1_loose_0");
  h_denominator_DY_eta_ele[0] = (TH1F*)file_DY_ele->Get("jetcut_0/h_eta1_loose_0");
  h_denominator_WJets_eta_ele[0] = (TH1F*)file_WJets_ele->Get("jetcut_0/h_eta1_loose_0");
  h_DATA_mu[0] = (TH1F*)file_Data_mu->Get("jetcut_0/h_pt1_tight_0"); 
  h_DY_mu[0] = (TH1F*)file_DY_mu->Get("jetcut_0/h_pt1_tight_0"); 
  h_WJets_mu[0] = (TH1F*)file_WJets_mu->Get("jetcut_0/h_pt1_tight_0"); 
  h_denominator_DATA_mu[0] = (TH1F*)file_Data_mu->Get("jetcut_0/h_pt1_loose_0");
  h_denominator_DY_mu[0] = (TH1F*)file_DY_mu->Get("jetcut_0/h_pt1_loose_0");
  h_denominator_WJets_mu[0] = (TH1F*)file_WJets_mu->Get("jetcut_0/h_pt1_loose_0");
  h_DATA_eta_mu[0] = (TH1F*)file_Data_mu->Get("jetcut_0/h_eta1_tight_0");
  h_DY_eta_mu[0] = (TH1F*)file_DY_mu->Get("jetcut_0/h_eta1_tight_0");
  h_WJets_eta_mu[0] = (TH1F*)file_WJets_mu->Get("jetcut_0/h_eta1_tight_0");
  h_denominator_DATA_eta_mu[0] = (TH1F*)file_Data_mu->Get("jetcut_0/h_eta1_loose_0");
  h_denominator_DY_eta_mu[0] = (TH1F*)file_DY_mu->Get("jetcut_0/h_eta1_loose_0");
  h_denominator_WJets_eta_mu[0] = (TH1F*)file_WJets_mu->Get("jetcut_0/h_eta1_loose_0");
   h_DATA_ele[1] = (TH1F*)file_Data_ele->Get("jetcut_1/h_pt1_tight_1"); 
  h_DY_ele[1] = (TH1F*)file_DY_ele->Get("jetcut_1/h_pt1_tight_1"); 
  h_WJets_ele[1] = (TH1F*)file_WJets_ele->Get("jetcut_1/h_pt1_tight_1"); 
  h_denominator_DATA_ele[1] = (TH1F*)file_Data_ele->Get("jetcut_1/h_pt1_loose_1");
  h_denominator_DY_ele[1] = (TH1F*)file_DY_ele->Get("jetcut_1/h_pt1_loose_1");
  h_denominator_WJets_ele[1] = (TH1F*)file_WJets_ele->Get("jetcut_1/h_pt1_loose_1");
  h_DATA_eta_ele[1] = (TH1F*)file_Data_ele->Get("jetcut_1/h_eta1_tight_1");
  h_DY_eta_ele[1] = (TH1F*)file_DY_ele->Get("jetcut_1/h_eta1_tight_1");
  h_WJets_eta_ele[1] = (TH1F*)file_WJets_ele->Get("jetcut_1/h_eta1_tight_1");
  h_denominator_DATA_eta_ele[1] = (TH1F*)file_Data_ele->Get("jetcut_1/h_eta1_loose_1");
  h_denominator_DY_eta_ele[1] = (TH1F*)file_DY_ele->Get("jetcut_1/h_eta1_loose_1");
  h_denominator_WJets_eta_ele[1] = (TH1F*)file_WJets_ele->Get("jetcut_1/h_eta1_loose_1");
  h_DATA_mu[1] = (TH1F*)file_Data_mu->Get("jetcut_1/h_pt1_tight_1"); 
  h_DY_mu[1] = (TH1F*)file_DY_mu->Get("jetcut_1/h_pt1_tight_1"); 
  h_WJets_mu[1] = (TH1F*)file_WJets_mu->Get("jetcut_1/h_pt1_tight_1"); 
  h_denominator_DATA_mu[1] = (TH1F*)file_Data_mu->Get("jetcut_1/h_pt1_loose_1");
  h_denominator_DY_mu[1] = (TH1F*)file_DY_mu->Get("jetcut_1/h_pt1_loose_1");
  h_denominator_WJets_mu[1] = (TH1F*)file_WJets_mu->Get("jetcut_1/h_pt1_loose_1");
  h_DATA_eta_mu[1] = (TH1F*)file_Data_mu->Get("jetcut_1/h_eta1_tight_1");
  h_DY_eta_mu[1] = (TH1F*)file_DY_mu->Get("jetcut_1/h_eta1_tight_1");
  h_WJets_eta_mu[1] = (TH1F*)file_WJets_mu->Get("jetcut_1/h_eta1_tight_1");
  h_denominator_DATA_eta_mu[1] = (TH1F*)file_Data_mu->Get("jetcut_1/h_eta1_loose_1");
  h_denominator_DY_eta_mu[1] = (TH1F*)file_DY_mu->Get("jetcut_1/h_eta1_loose_1");
  h_denominator_WJets_eta_mu[1] = (TH1F*)file_WJets_mu->Get("jetcut_1/h_eta1_loose_1");
  h_DATA_ele[2] = (TH1F*)file_Data_ele->Get("jetcut_2/h_pt1_tight_2"); 
  h_DY_ele[2] = (TH1F*)file_DY_ele->Get("jetcut_2/h_pt1_tight_2"); 
  h_WJets_ele[2] = (TH1F*)file_WJets_ele->Get("jetcut_2/h_pt1_tight_2"); 
  h_denominator_DATA_ele[2] = (TH1F*)file_Data_ele->Get("jetcut_2/h_pt1_loose_2");
  h_denominator_DY_ele[2] = (TH1F*)file_DY_ele->Get("jetcut_2/h_pt1_loose_2");
  h_denominator_WJets_ele[2] = (TH1F*)file_WJets_ele->Get("jetcut_2/h_pt1_loose_2");
  h_DATA_eta_ele[2] = (TH1F*)file_Data_ele->Get("jetcut_2/h_eta1_tight_2");
  h_DY_eta_ele[2] = (TH1F*)file_DY_ele->Get("jetcut_2/h_eta1_tight_2");
  h_WJets_eta_ele[2] = (TH1F*)file_WJets_ele->Get("jetcut_2/h_eta1_tight_2");
  h_denominator_DATA_eta_ele[2] = (TH1F*)file_Data_ele->Get("jetcut_2/h_eta1_loose_2");
  h_denominator_DY_eta_ele[2] = (TH1F*)file_DY_ele->Get("jetcut_2/h_eta1_loose_2");
  h_denominator_WJets_eta_ele[2] = (TH1F*)file_WJets_ele->Get("jetcut_2/h_eta1_loose_2");
  h_DATA_mu[2] = (TH1F*)file_Data_mu->Get("jetcut_2/h_pt1_tight_2"); 
  h_DY_mu[2] = (TH1F*)file_DY_mu->Get("jetcut_2/h_pt1_tight_2"); 
  h_WJets_mu[2] = (TH1F*)file_WJets_mu->Get("jetcut_2/h_pt1_tight_2"); 
  h_denominator_DATA_mu[2] = (TH1F*)file_Data_mu->Get("jetcut_2/h_pt1_loose_2");
  h_denominator_DY_mu[2] = (TH1F*)file_DY_mu->Get("jetcut_2/h_pt1_loose_2");
  h_denominator_WJets_mu[2] = (TH1F*)file_WJets_mu->Get("jetcut_2/h_pt1_loose_2");
  h_DATA_eta_mu[2] = (TH1F*)file_Data_mu->Get("jetcut_2/h_eta1_tight_2");
  h_DY_eta_mu[2] = (TH1F*)file_DY_mu->Get("jetcut_2/h_eta1_tight_2");
  h_WJets_eta_mu[2] = (TH1F*)file_WJets_mu->Get("jetcut_2/h_eta1_tight_2");
  h_denominator_DATA_eta_mu[2] = (TH1F*)file_Data_mu->Get("jetcut_2/h_eta1_loose_2");
  h_denominator_DY_eta_mu[2] = (TH1F*)file_DY_mu->Get("jetcut_2/h_eta1_loose_2");
  h_denominator_WJets_eta_mu[2] = (TH1F*)file_WJets_mu->Get("jetcut_2/h_eta1_loose_2");
  h_DATA_ele[3] = (TH1F*)file_Data_ele->Get("jetcut_3/h_pt1_tight_3"); 
  h_DY_ele[3] = (TH1F*)file_DY_ele->Get("jetcut_3/h_pt1_tight_3"); 
  h_WJets_ele[3] = (TH1F*)file_WJets_ele->Get("jetcut_3/h_pt1_tight_3"); 
  h_denominator_DATA_ele[3] = (TH1F*)file_Data_ele->Get("jetcut_3/h_pt1_loose_3");
  h_denominator_DY_ele[3] = (TH1F*)file_DY_ele->Get("jetcut_3/h_pt1_loose_3");
  h_denominator_WJets_ele[3] = (TH1F*)file_WJets_ele->Get("jetcut_3/h_pt1_loose_3");
  h_DATA_eta_ele[3] = (TH1F*)file_Data_ele->Get("jetcut_3/h_eta1_tight_3");
  h_DY_eta_ele[3] = (TH1F*)file_DY_ele->Get("jetcut_3/h_eta1_tight_3");
  h_WJets_eta_ele[3] = (TH1F*)file_WJets_ele->Get("jetcut_3/h_eta1_tight_3");
  h_denominator_DATA_eta_ele[3] = (TH1F*)file_Data_ele->Get("jetcut_3/h_eta1_loose_3");
  h_denominator_DY_eta_ele[3] = (TH1F*)file_DY_ele->Get("jetcut_3/h_eta1_loose_3");
  h_denominator_WJets_eta_ele[3] = (TH1F*)file_WJets_ele->Get("jetcut_3/h_eta1_loose_3");
  h_DATA_mu[3] = (TH1F*)file_Data_mu->Get("jetcut_3/h_pt1_tight_3"); 
  h_DY_mu[3] = (TH1F*)file_DY_mu->Get("jetcut_3/h_pt1_tight_3"); 
  h_WJets_mu[3] = (TH1F*)file_WJets_mu->Get("jetcut_3/h_pt1_tight_3"); 
  h_denominator_DATA_mu[3] = (TH1F*)file_Data_mu->Get("jetcut_3/h_pt1_loose_3");
  h_denominator_DY_mu[3] = (TH1F*)file_DY_mu->Get("jetcut_3/h_pt1_loose_3");
  h_denominator_WJets_mu[3] = (TH1F*)file_WJets_mu->Get("jetcut_3/h_pt1_loose_3");
  h_DATA_eta_mu[3] = (TH1F*)file_Data_mu->Get("jetcut_3/h_eta1_tight_3");
  h_DY_eta_mu[3] = (TH1F*)file_DY_mu->Get("jetcut_3/h_eta1_tight_3");
  h_WJets_eta_mu[3] = (TH1F*)file_WJets_mu->Get("jetcut_3/h_eta1_tight_3");
  h_denominator_DATA_eta_mu[3] = (TH1F*)file_Data_mu->Get("jetcut_3/h_eta1_loose_3");
  h_denominator_DY_eta_mu[3] = (TH1F*)file_DY_mu->Get("jetcut_3/h_eta1_loose_3");
  h_denominator_WJets_eta_mu[3] = (TH1F*)file_WJets_mu->Get("jetcut_3/h_eta1_loose_3");
  h_DATA_ele[4] = (TH1F*)file_Data_ele->Get("jetcut_4/h_pt1_tight_4"); 
  h_DY_ele[4] = (TH1F*)file_DY_ele->Get("jetcut_4/h_pt1_tight_4"); 
  h_WJets_ele[4] = (TH1F*)file_WJets_ele->Get("jetcut_4/h_pt1_tight_4"); 
  h_denominator_DATA_ele[4] = (TH1F*)file_Data_ele->Get("jetcut_4/h_pt1_loose_4");
  h_denominator_DY_ele[4] = (TH1F*)file_DY_ele->Get("jetcut_4/h_pt1_loose_4");
  h_denominator_WJets_ele[4] = (TH1F*)file_WJets_ele->Get("jetcut_4/h_pt1_loose_4");
  h_DATA_eta_ele[4] = (TH1F*)file_Data_ele->Get("jetcut_4/h_eta1_tight_4");
  h_DY_eta_ele[4] = (TH1F*)file_DY_ele->Get("jetcut_4/h_eta1_tight_4");
  h_WJets_eta_ele[4] = (TH1F*)file_WJets_ele->Get("jetcut_4/h_eta1_tight_4");
  h_denominator_DATA_eta_ele[4] = (TH1F*)file_Data_ele->Get("jetcut_4/h_eta1_loose_4");
  h_denominator_DY_eta_ele[4] = (TH1F*)file_DY_ele->Get("jetcut_4/h_eta1_loose_4");
  h_denominator_WJets_eta_ele[4] = (TH1F*)file_WJets_ele->Get("jetcut_4/h_eta1_loose_4");
  h_DATA_mu[4] = (TH1F*)file_Data_mu->Get("jetcut_4/h_pt1_tight_4"); 
  h_DY_mu[4] = (TH1F*)file_DY_mu->Get("jetcut_4/h_pt1_tight_4"); 
  h_WJets_mu[4] = (TH1F*)file_WJets_mu->Get("jetcut_4/h_pt1_tight_4"); 
  h_denominator_DATA_mu[4] = (TH1F*)file_Data_mu->Get("jetcut_4/h_pt1_loose_4");
  h_denominator_DY_mu[4] = (TH1F*)file_DY_mu->Get("jetcut_4/h_pt1_loose_4");
  h_denominator_WJets_mu[4] = (TH1F*)file_WJets_mu->Get("jetcut_4/h_pt1_loose_4");
  h_DATA_eta_mu[4] = (TH1F*)file_Data_mu->Get("jetcut_4/h_eta1_tight_4");
  h_DY_eta_mu[4] = (TH1F*)file_DY_mu->Get("jetcut_4/h_eta1_tight_4");
  h_WJets_eta_mu[4] = (TH1F*)file_WJets_mu->Get("jetcut_4/h_eta1_tight_4");
  h_denominator_DATA_eta_mu[4] = (TH1F*)file_Data_mu->Get("jetcut_4/h_eta1_loose_4");
  h_denominator_DY_eta_mu[4] = (TH1F*)file_DY_mu->Get("jetcut_4/h_eta1_loose_4");
  h_denominator_WJets_eta_mu[4] = (TH1F*)file_WJets_mu->Get("jetcut_4/h_eta1_loose_4");
  //}
 
  gStyle->SetOptStat(0);
  TH1F* h_num_ele[5];TH1F* h_den_ele[5];TH1F* h_div_ele[5];TH1F* h_div_noEWKcorr_ele[5];
  h_div_noEWKcorr_ele[0] = (TH1F*)h_DATA_ele[0]->Clone(Form("h_div_noEWKcorr_ele_%d",0));
  h_div_noEWKcorr_ele[1] = (TH1F*)h_DATA_ele[1]->Clone(Form("h_div_noEWKcorr_ele_%d",1));
  h_div_noEWKcorr_ele[0]->Divide(h_denominator_DATA_ele[0]);
  h_div_noEWKcorr_ele[1]->Divide(h_denominator_DATA_ele[1]);
 h_div_noEWKcorr_ele[0]->Draw();
 h_div_noEWKcorr_ele[1]->Draw("same");


  for(int j=0;j++;j<5){
    h_num_ele[j] = (TH1F*)h_DATA_ele[j]->Clone(Form("h_num_ele_%d",j));
    h_num_ele[j]->Add(h_DY_ele[j],-1);
    h_num_ele[j]->Add(h_WJets_ele[j],-1);
    h_den_ele[j] = (TH1F*)h_denominator_DATA_ele[j]->Clone(Form("h_den_ele_%d",j));
    h_den_ele[j]->Add(h_denominator_DY_ele[j],-1);
    h_den_ele[j]->Add(h_denominator_WJets_ele[j],-1);
    h_div_ele[j] = (TH1F*)h_num_ele[j]->Clone(Form("h_div_ele_%d",j));
    h_div_ele[j]->Divide(h_den_ele[j]);
    h_div_noEWKcorr_ele[j] = (TH1F*)h_DATA_ele[j]->Clone(Form("h_div_noEWKcorr_ele_%d",j));
    h_div_noEWKcorr_ele[j]->Divide(h_denominator_DATA_ele[j]);
  }
  //h_div_noEWKcorr_ele[0]->Draw();/////////////////////////////////////////////////////////////////////////TEST

  TH1F* h_num_mu[5];TH1F* h_den_mu[5];TH1F* h_div_mu[5];TH1F* h_div_noEWKcorr_mu[5];
  for(int j=0;j++;j<5){
    h_num_mu[j] = (TH1F*)h_DATA_mu[j]->Clone(Form("h_num_mu_%d",j));
    h_num_mu[j]->Add(h_DY_mu[j],-1);
    h_num_mu[j]->Add(h_WJets_mu[j],-1);
    h_den_mu[j] = (TH1F*)h_denominator_DATA_mu[j]->Clone(Form("h_den_mu_%d",j));
    h_den_mu[j]->Add(h_denominator_DY_mu[j],-1);
    h_den_mu[j]->Add(h_denominator_WJets_mu[j],-1);
    h_div_mu[j] = (TH1F*)h_num_mu[j]->Clone(Form("h_div_mu_%d",j));
    h_div_mu[j]->Divide(h_den_mu[j]);
    h_div_noEWKcorr_mu[j] = (TH1F*)h_DATA_mu[j]->Clone(Form("h_div_noEWKcorr_mu_%d",j));
    h_div_noEWKcorr_mu[j]->Divide(h_denominator_DATA_mu[j]);
  }
  TH1F* h_relEWKcont_ele[5];TH1F* h_relEWKcont_numerator_ele[5];TH1F* h_relEWKcont2_ele[5];TH1F* h_relEWKcont_denominator_ele[5];
  for(int j=0;j++;j<5){
    h_relEWKcont_ele[j] = (TH1F*)h_DY_ele[j]->Clone(Form("h_relEWKcont_%d",j));
    h_relEWKcont_ele[j]->Add(h_WJets_ele[j],1);
    h_relEWKcont_numerator_ele[j] = (TH1F*)h_relEWKcont_ele[j]->Clone(Form("h_relEWKcont_numerator_%d",j));
    h_relEWKcont_numerator_ele[j]->Divide(h_DATA_ele[j]);
    h_relEWKcont2_ele[j] = (TH1F*)h_denominator_DY_ele[j]->Clone(Form("h_relEWKcont2_%d",j));
    h_relEWKcont2_ele[j]->Add(h_denominator_WJets_ele[j],1);
    h_relEWKcont_denominator_ele[j] = (TH1F*)h_relEWKcont2_ele[j]->Clone(Form("h_relEWKcont_denominator_%d",j));
    h_relEWKcont_denominator_ele[j]->Divide(h_denominator_DATA_ele[j]);
  }
  TH1F* h_relEWKcont_mu[5];TH1F* h_relEWKcont_numerator_mu[5];TH1F* h_relEWKcont2_mu[5];TH1F* h_relEWKcont_denominator_mu[5];
  for(int j=0;j++;j<5){
    h_relEWKcont_mu[j] = (TH1F*)h_DY_mu[j]->Clone(Form("h_relEWKcont_%d",j));
    h_relEWKcont_mu[j]->Add(h_WJets_mu[j],1);
    h_relEWKcont_numerator_mu[j] = (TH1F*)h_relEWKcont_mu[j]->Clone(Form("h_relEWKcont_numerator_%d",j));
    h_relEWKcont_numerator_mu[j]->Divide(h_DATA_mu[j]);
    h_relEWKcont2_mu[j] = (TH1F*)h_denominator_DY_mu[j]->Clone(Form("h_relEWKcont2_%d",j));
    h_relEWKcont2_mu[j]->Add(h_denominator_WJets_mu[j],1);
    h_relEWKcont_denominator_mu[j] = (TH1F*)h_relEWKcont2_mu[j]->Clone(Form("h_relEWKcont_denominator_%d",j));
    h_relEWKcont_denominator_mu[j]->Divide(h_denominator_DATA_mu[j]);
  }

  TH1F* h_num_eta_ele[5];TH1F* h_den_eta_ele[5];TH1F* h_div_eta_ele[5];TH1F* h_div_noEWKcorr_eta_ele[5];
  for(int j=0;j++;j<5){
    h_num_eta_ele[j] = (TH1F*)h_DATA_eta_ele[j]->Clone(Form("h_num_eta_ele_%d",j));
    h_num_eta_ele[j]->Add(h_DY_eta_ele[j],-1);
    h_num_eta_ele[j]->Add(h_WJets_eta_ele[j],-1);
    h_den_eta_ele[j] = (TH1F*)h_denominator_DATA_eta_ele[j]->Clone(Form("h_den_eta_ele_%d",j));
    h_den_eta_ele[j]->Add(h_denominator_DY_eta_ele[j],-1);
    h_den_eta_ele[j]->Add(h_denominator_WJets_eta_ele[j],-1);
    h_div_eta_ele[j] = (TH1F*)h_num_ele[j]->Clone(Form("h_div_eta_ele_%d",j));
    h_div_eta_ele[j]->Divide(h_den_eta_ele[j]);
    h_div_noEWKcorr_eta_ele[j] = (TH1F*)h_DATA_eta_ele[j]->Clone(Form("h_div_noEWKcorr_eta_ele_%d",j));
    h_div_noEWKcorr_eta_ele[j]->Divide(h_denominator_DATA_eta_ele[j]);
  }
  TH1F* h_num_eta_mu[5];TH1F* h_den_eta_mu[5];TH1F* h_div_eta_mu[5];TH1F* h_div_noEWKcorr_eta_mu[5];
  for(int j=0;j++;j<5){
    h_num_eta_mu[j] = (TH1F*)h_DATA_eta_mu[j]->Clone(Form("h_num_eta_mu_%d",j));
    h_num_eta_mu[j]->Add(h_DY_eta_mu[j],-1);
    h_num_eta_mu[j]->Add(h_WJets_eta_mu[j],-1);
    h_den_eta_mu[j] = (TH1F*)h_denominator_DATA_eta_mu[j]->Clone(Form("h_den_eta_mu_%d",j));
    h_den_eta_mu[j]->Add(h_denominator_DY_eta_mu[j],-1);
    h_den_eta_mu[j]->Add(h_denominator_WJets_eta_mu[j],-1);
    h_div_eta_mu[j] = (TH1F*)h_num_mu[j]->Clone(Form("h_div_eta_mu_%d",j));
    h_div_eta_mu[j]->Divide(h_den_eta_mu[j]);
    h_div_noEWKcorr_eta_mu[j] = (TH1F*)h_DATA_eta_mu[j]->Clone(Form("h_div_noEWKcorr_eta_mu_%d",j));
    h_div_noEWKcorr_eta_mu[j]->Divide(h_denominator_DATA_eta_mu[j]);
  }
  
  TLegend *leg= new TLegend(0.1,0.7,0.48,0.9);
  leg->AddEntry(h_div_noEWKcorr_ele[0],"Without EWK correction");
  leg->AddEntry(h_div_ele[0],"With EWK correction");
    
  /////////////Efficiency errors //////////////////
  float binvalue ;
  float totaln ;
  float newerror ;
 
  for(int j=0;j++;j<5){
    for (int i=1; i<= 8; i++) {
      binvalue = h_div_ele[j]->GetBinContent(i);
      totaln = h_den_ele[j]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_ele[j]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 8; i++) {
      binvalue = h_div_noEWKcorr_ele[j]->GetBinContent(i);
      totaln = h_denominator_DATA_ele[j]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_noEWKcorr_ele[j]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 5; i++) {
      binvalue = h_div_eta_ele[j]->GetBinContent(i);
      totaln = h_den_eta_ele[j]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_eta_ele[j]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 5; i++) {
      binvalue = h_div_noEWKcorr_eta_ele[j]->GetBinContent(i);
      totaln = h_denominator_DATA_eta_ele[j]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_noEWKcorr_eta_ele[j]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 8; i++) {
      binvalue = h_div_mu[j]->GetBinContent(i);
      totaln = h_den_mu[j]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_mu[j]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 8; i++) {
      binvalue = h_div_noEWKcorr_mu[j]->GetBinContent(i);
      totaln = h_denominator_DATA_mu[j]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_noEWKcorr_mu[j]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 5; i++) {
      binvalue = h_div_eta_mu[j]->GetBinContent(i);
      totaln = h_den_eta_mu[j]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_eta_mu[j]->SetBinError(i,newerror);
    }
    for (int i=1; i<= 5; i++) {
      binvalue = h_div_noEWKcorr_eta_mu[j]->GetBinContent(i);
      totaln = h_denominator_DATA_eta_mu[j]->GetBinContent(i);
      newerror = sqrt((binvalue*(1-binvalue))/totaln);
      h_div_noEWKcorr_eta_mu[j]->SetBinError(i,newerror);
    }
  }
  /////////////////////////////////////////////
     
  TCanvas *c[3][2][5];
  for(int j=0;j++;j<5){
    c[0][0][j]= new TCanvas();c[0][0][j]->cd();
    h_div_ele[j]->Draw("E"); h_div_ele[j]->GetYaxis()->SetRangeUser(0,1); h_div_ele[j]->SetTitle("Electron_mvaFall17Iso_WP90 fake rate"); h_div_ele[j]->SetLineColor(2); h_div_ele[j]->GetXaxis()->SetTitle("p_{T} [GeV]"); h_div_ele[j]->GetYaxis()->SetTitle("Ele fake rate");c[0][0][j]->SetGridx(1);c[0][0][j]->SetGridy(1); h_div_ele[j]->SetLineWidth(2); h_div_ele[j]->SetMarkerColor(2);  h_div_ele[j]->SetMarkerStyle(kFullCircle);
    h_div_noEWKcorr_ele[j]->Draw("sameE"); h_div_noEWKcorr_ele[j]->SetLineColor(1);h_div_noEWKcorr_ele[j]->SetLineWidth(2); h_div_noEWKcorr_ele[j]->SetMarkerColor(1);  h_div_noEWKcorr_ele[j]->SetMarkerStyle(kFullCircle);
    leg->Draw();c[0][0][j]->SaveAs(Form("eleFR_pt_jet%d.gif",j*5+20));
    c[0][1][j]= new TCanvas();c[0][1][j]->cd();
    h_div_mu[j]->Draw("E"); h_div_mu[j]->GetYaxis()->SetRangeUser(0,1); h_div_mu[j]->SetTitle("TightMuon_cut_Tight_HWWW fake rate"); h_div_mu[j]->SetLineColor(2); h_div_mu[j]->GetXaxis()->SetTitle("p_{T} [GeV]"); h_div_mu[j]->GetYaxis()->SetTitle("Mu fake rate");c[0][1][j]->SetGridx(1);c[0][1][j]->SetGridy(1); h_div_mu[j]->SetLineWidth(2); h_div_mu[j]->SetMarkerColor(2);  h_div_mu[j]->SetMarkerStyle(kFullCircle);
    h_div_noEWKcorr_mu[j]->Draw("sameE"); h_div_noEWKcorr_mu[j]->SetLineColor(1);h_div_noEWKcorr_mu[j]->SetLineWidth(2); h_div_noEWKcorr_mu[j]->SetMarkerColor(1);  h_div_noEWKcorr_mu[j]->SetMarkerStyle(kFullCircle);
    leg->Draw();c[0][1][j]->SaveAs(Form("muFR_pt_jet%d.gif",j*5+20));

    c[1][0][j]= new TCanvas();c[1][0][j]->cd();
    h_relEWKcont_numerator_ele[j]->Draw();h_relEWKcont_numerator_ele[j]->GetYaxis()->SetRangeUser(0,1);h_relEWKcont_numerator_ele[j]->SetTitle("Electron EWK contamination (numerator)"); h_relEWKcont_numerator_ele[j]->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_numerator_ele[j]->GetXaxis()->SetTitle("Pt1 [GeV]");c[1][0][j]->SaveAs(Form("EWK_contamination_ele_numerator_jet%d.gif",j*5+20));
    h_relEWKcont_denominator_ele[j]->Draw();h_relEWKcont_denominator_ele[j]->GetYaxis()->SetRangeUser(0,1);h_relEWKcont_denominator_ele[j]->SetTitle("Electron EWK contamination (denominator)"); h_relEWKcont_denominator_ele[j]->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_denominator_ele[j]->GetXaxis()->SetTitle("Pt1 [GeV]");c[1][0][j]->SaveAs(Form("EWK_contamination_ele_denominator_jet%d.gif",j*5+20));
    c[1][1][j]= new TCanvas();c[1][0][j]->cd();
    h_relEWKcont_numerator_mu[j]->Draw();h_relEWKcont_numerator_mu[j]->GetYaxis()->SetRangeUser(0,1);h_relEWKcont_numerator_mu[j]->SetTitle("Muon EWK contamination (numerator)"); h_relEWKcont_numerator_mu[j]->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_numerator_mu[j]->GetXaxis()->SetTitle("Pt1 [GeV]");c[1][1][j]->SaveAs(Form("EWK_contamination_mu_numerator_jet%d.gif",j*5+20));
    h_relEWKcont_denominator_mu[j]->Draw();h_relEWKcont_denominator_mu[j]->GetYaxis()->SetRangeUser(0,1);h_relEWKcont_denominator_mu[j]->SetTitle("Muon EWK contamination (denominator)"); h_relEWKcont_denominator_mu[j]->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_denominator_mu[j]->GetXaxis()->SetTitle("Pt1 [GeV]");c[1][1][j]->SaveAs(Form("EWK_contamination_mu_denominator_jet%d.gif",j*5+20));

    c[2][0][j]= new TCanvas();c[2][0][j]->cd();
    h_div_eta_ele[j]->Draw("E"); h_div_eta_ele[j]->GetYaxis()->SetRangeUser(0,1); h_div_eta_ele[j]->SetTitle("Electron_mvaFall17Iso_WP90 fake rate"); h_div_eta_ele[j]->SetLineColor(2); h_div_eta_ele[j]->GetXaxis()->SetTitle("p_{T} [GeV]"); h_div_eta_ele[j]->GetYaxis()->SetTitle("Ele fake rate");c[2][0][j]->SetGridx(1);c[2][0][j]->SetGridy(1); h_div_eta_ele[j]->SetLineWidth(2); h_div_eta_ele[j]->SetMarkerColor(2);  h_div_eta_ele[j]->SetMarkerStyle(kFullCircle);
    h_div_noEWKcorr_eta_ele[j]->Draw("sameE"); h_div_noEWKcorr_eta_ele[j]->SetLineColor(1);h_div_noEWKcorr_eta_ele[j]->SetLineWidth(2); h_div_noEWKcorr_eta_ele[j]->SetMarkerColor(1);  h_div_noEWKcorr_eta_ele[j]->SetMarkerStyle(kFullCircle);
    leg->Draw();c[2][0][j]->SaveAs(Form("eleFR_eta_jet%d.gif",j*5+20));
    c[2][1][j]= new TCanvas();c[2][1][j]->cd();
    h_div_eta_mu[j]->Draw("E"); h_div_eta_mu[j]->GetYaxis()->SetRangeUser(0,1); h_div_eta_mu[j]->SetTitle("TightMuon_cut_Tight_HWWW fake rate"); h_div_eta_mu[j]->SetLineColor(2); h_div_eta_mu[j]->GetXaxis()->SetTitle("p_{T} [GeV]"); h_div_eta_mu[j]->GetYaxis()->SetTitle("Mu fake rate");c[2][1][j]->SetGridx(1);c[2][1][j]->SetGridy(1); h_div_eta_mu[j]->SetLineWidth(2); h_div_eta_mu[j]->SetMarkerColor(2);  h_div_eta_mu[j]->SetMarkerStyle(kFullCircle);
    h_div_noEWKcorr_eta_mu[j]->Draw("sameE"); h_div_noEWKcorr_eta_mu[j]->SetLineColor(1);h_div_noEWKcorr_eta_mu[j]->SetLineWidth(2); h_div_noEWKcorr_eta_mu[j]->SetMarkerColor(1);  h_div_noEWKcorr_eta_mu[j]->SetMarkerStyle(kFullCircle);
    leg->Draw();c[2][1][j]->SaveAs(Form("muFR_eta_jet%d.gif",j*5+20));
  }
 
  cout<<"THE END"<<endl;
 
}



 
