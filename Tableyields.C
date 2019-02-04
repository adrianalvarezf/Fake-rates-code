#include "TCanvas.h"
#include "TTree.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "TMath.h"

void Tableyields(int jetcut)
{
  TFile* file_DY_ele= new TFile("outputsFR_1feb_jetbins/DY_ele.root");
  TFile* file_WJets_ele= new TFile("outputsFR_1feb_jetbins/WJets_ele.root");
  TFile* file_data_ele= new TFile("outputsFR_1feb_jetbins/Data_ele.root");
  TFile* file_DY_mu= new TFile("outputsFR_1feb_jetbins/DY_mu.root");
  TFile* file_WJets_mu= new TFile("outputsFR_1feb_jetbins/WJets_mu.root");
  TFile* file_data_mu= new TFile("outputsFR_1feb_jetbins/Data_mu.root");
  TH1::SetDefaultSumw2();

  Double_t y_data_ele_tight_low =((TH1F*)file_data_ele->Get(Form("jetcut_%d/h_eta1_tight_low_%d",jetcut,jetcut)))->Integral();
  Double_t y_data_mu_tight_low =((TH1F*)file_data_mu->Get(Form("jetcut_%d/h_eta1_tight_low_%d",jetcut,jetcut)))->Integral();
  Double_t y_data_ele_tight_high =((TH1F*)file_data_ele->Get(Form("jetcut_%d/h_eta1_tight_high_%d",jetcut,jetcut)))->Integral();
  Double_t y_data_mu_tight_high =((TH1F*)file_data_mu->Get(Form("jetcut_%d/h_eta1_tight_high_%d",jetcut,jetcut)))->Integral();
 
  Double_t y_DY_ele_tight_low =((TH1F*)file_DY_ele->Get(Form("jetcut_%d/h_eta1_tight_low_%d",jetcut,jetcut)))->Integral();
  Double_t y_DY_mu_tight_low =((TH1F*)file_DY_mu->Get(Form("jetcut_%d/h_eta1_tight_low_%d",jetcut,jetcut)))->Integral();
  Double_t y_DY_ele_tight_high =((TH1F*)file_DY_ele->Get(Form("jetcut_%d/h_eta1_tight_high_%d",jetcut,jetcut)))->Integral();
  Double_t y_DY_mu_tight_high =((TH1F*)file_DY_mu->Get(Form("jetcut_%d/h_eta1_tight_high_%d",jetcut,jetcut)))->Integral();
  Double_t y_DY_ele_tight_low_weight =((TH1F*)file_DY_ele->Get(Form("jetcut_%d/h_eta1_tight_low_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_DY_mu_tight_low_weight =((TH1F*)file_DY_mu->Get(Form("jetcut_%d/h_eta1_tight_low_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_DY_ele_tight_high_weight =((TH1F*)file_DY_ele->Get(Form("jetcut_%d/h_eta1_tight_high_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_DY_mu_tight_high_weight =((TH1F*)file_DY_mu->Get(Form("jetcut_%d/h_eta1_tight_high_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_DY_ele_tight_low_ratio =y_DY_ele_tight_low/y_DY_ele_tight_low_weight;
  Double_t y_DY_mu_tight_low_ratio =y_DY_mu_tight_low/y_DY_mu_tight_low_weight;
  Double_t y_DY_ele_tight_high_ratio =y_DY_ele_tight_high/y_DY_ele_tight_high_weight;
  Double_t y_DY_mu_tight_high_ratio =y_DY_mu_tight_high/y_DY_mu_tight_high_weight;

  Double_t y_WJets_ele_tight_low =((TH1F*)file_WJets_ele->Get(Form("jetcut_%d/h_eta1_tight_low_%d",jetcut,jetcut)))->Integral();
  Double_t y_WJets_mu_tight_low =((TH1F*)file_WJets_mu->Get(Form("jetcut_%d/h_eta1_tight_low_%d",jetcut,jetcut)))->Integral();
  Double_t y_WJets_ele_tight_high =((TH1F*)file_WJets_ele->Get(Form("jetcut_%d/h_eta1_tight_high_%d",jetcut,jetcut)))->Integral();
  Double_t y_WJets_mu_tight_high =((TH1F*)file_WJets_mu->Get(Form("jetcut_%d/h_eta1_tight_high_%d",jetcut,jetcut)))->Integral();
  Double_t y_WJets_ele_tight_low_weight =((TH1F*)file_WJets_ele->Get(Form("jetcut_%d/h_eta1_tight_low_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_WJets_mu_tight_low_weight =((TH1F*)file_WJets_mu->Get(Form("jetcut_%d/h_eta1_tight_low_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_WJets_ele_tight_high_weight =((TH1F*)file_WJets_ele->Get(Form("jetcut_%d/h_eta1_tight_high_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_WJets_mu_tight_high_weight =((TH1F*)file_WJets_mu->Get(Form("jetcut_%d/h_eta1_tight_high_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_WJets_ele_tight_low_ratio =y_WJets_ele_tight_low/y_WJets_ele_tight_low_weight;
  Double_t y_WJets_mu_tight_low_ratio =y_WJets_mu_tight_low/y_WJets_mu_tight_low_weight;
  Double_t y_WJets_ele_tight_high_ratio =y_WJets_ele_tight_high/y_WJets_ele_tight_high_weight;
  Double_t y_WJets_mu_tight_high_ratio =y_WJets_mu_tight_high/y_WJets_mu_tight_high_weight;

  Double_t y_data_ele_loose_low =((TH1F*)file_data_ele->Get(Form("jetcut_%d/h_eta1_loose_low_%d",jetcut,jetcut)))->Integral();
  Double_t y_data_mu_loose_low =((TH1F*)file_data_mu->Get(Form("jetcut_%d/h_eta1_loose_low_%d",jetcut,jetcut)))->Integral();
  Double_t y_data_ele_loose_high =((TH1F*)file_data_ele->Get(Form("jetcut_%d/h_eta1_loose_high_%d",jetcut,jetcut)))->Integral();
  Double_t y_data_mu_loose_high =((TH1F*)file_data_mu->Get(Form("jetcut_%d/h_eta1_loose_high_%d",jetcut,jetcut)))->Integral();
 
  Double_t y_DY_ele_loose_low =((TH1F*)file_DY_ele->Get(Form("jetcut_%d/h_eta1_loose_low_%d",jetcut,jetcut)))->Integral();
  Double_t y_DY_mu_loose_low =((TH1F*)file_DY_mu->Get(Form("jetcut_%d/h_eta1_loose_low_%d",jetcut,jetcut)))->Integral();
  Double_t y_DY_ele_loose_high =((TH1F*)file_DY_ele->Get(Form("jetcut_%d/h_eta1_loose_high_%d",jetcut,jetcut)))->Integral();
  Double_t y_DY_mu_loose_high =((TH1F*)file_DY_mu->Get(Form("jetcut_%d/h_eta1_loose_high_%d",jetcut,jetcut)))->Integral();
  Double_t y_DY_ele_loose_low_weight =((TH1F*)file_DY_ele->Get(Form("jetcut_%d/h_eta1_loose_low_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_DY_mu_loose_low_weight =((TH1F*)file_DY_mu->Get(Form("jetcut_%d/h_eta1_loose_low_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_DY_ele_loose_high_weight =((TH1F*)file_DY_ele->Get(Form("jetcut_%d/h_eta1_loose_high_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_DY_mu_loose_high_weight =((TH1F*)file_DY_mu->Get(Form("jetcut_%d/h_eta1_loose_high_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_DY_ele_loose_low_ratio =y_DY_ele_loose_low/y_DY_ele_loose_low_weight;
  Double_t y_DY_mu_loose_low_ratio =y_DY_mu_loose_low/y_DY_mu_loose_low_weight;
  Double_t y_DY_ele_loose_high_ratio =y_DY_ele_loose_high/y_DY_ele_loose_high_weight;
  Double_t y_DY_mu_loose_high_ratio =y_DY_mu_loose_high/y_DY_mu_loose_high_weight;

  Double_t y_WJets_ele_loose_low =((TH1F*)file_WJets_ele->Get(Form("jetcut_%d/h_eta1_loose_low_%d",jetcut,jetcut)))->Integral();
  Double_t y_WJets_mu_loose_low =((TH1F*)file_WJets_mu->Get(Form("jetcut_%d/h_eta1_loose_low_%d",jetcut,jetcut)))->Integral();
  Double_t y_WJets_ele_loose_high =((TH1F*)file_WJets_ele->Get(Form("jetcut_%d/h_eta1_loose_high_%d",jetcut,jetcut)))->Integral();
  Double_t y_WJets_mu_loose_high =((TH1F*)file_WJets_mu->Get(Form("jetcut_%d/h_eta1_loose_high_%d",jetcut,jetcut)))->Integral();
  Double_t y_WJets_ele_loose_low_weight =((TH1F*)file_WJets_ele->Get(Form("jetcut_%d/h_eta1_loose_low_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_WJets_mu_loose_low_weight =((TH1F*)file_WJets_mu->Get(Form("jetcut_%d/h_eta1_loose_low_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_WJets_ele_loose_high_weight =((TH1F*)file_WJets_ele->Get(Form("jetcut_%d/h_eta1_loose_high_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_WJets_mu_loose_high_weight =((TH1F*)file_WJets_mu->Get(Form("jetcut_%d/h_eta1_loose_high_%d",jetcut,jetcut)))->GetEntries();
  Double_t y_WJets_ele_loose_low_ratio =y_WJets_ele_loose_low/y_WJets_ele_loose_low_weight;
  Double_t y_WJets_mu_loose_low_ratio =y_WJets_mu_loose_low/y_WJets_mu_loose_low_weight;
  Double_t y_WJets_ele_loose_high_ratio =y_WJets_ele_loose_high/y_WJets_ele_loose_high_weight;
  Double_t y_WJets_mu_loose_high_ratio =y_WJets_mu_loose_high/y_WJets_mu_loose_high_weight;

  ofstream Table(Form("yields_jetcut%d.txt",jetcut*5+20));
  Table<< " ...............Trigger...........Data.....................W+Jets...............................Z+Jets.......... "  <<endl;
  Table<< " ............................................w/o weight.....with....Ratio........w/o weight.....with.....Ratio..... "  <<endl;
  Table<<"Loose Muons"<<"     low pt            "<<Form("%.0f",y_data_mu_loose_low)<<"     "<<Form("%.0f",y_WJets_mu_loose_low_weight)<<"         "<<Form("%.0f",y_WJets_mu_loose_low)<<"         "<<Form("%.3f",y_WJets_mu_loose_low_ratio)<<"          "<<Form("%.0f",y_DY_mu_loose_low)<<"          "<<Form("%.0f",y_DY_mu_loose_low_weight)<<"         "<<Form("%.3f",y_DY_mu_loose_low_ratio)<<"    "<<endl;
  Table<<"           "<<"     high pt           "<<Form("%.0f",y_data_mu_loose_high)<<"    "<<Form("%.0f",y_WJets_mu_loose_high_weight)<<"      "<<Form("%.0f",y_WJets_mu_loose_high)<<"         "<<Form("%.3f",y_WJets_mu_loose_high_ratio)<<"          "<<Form("%.0f",y_DY_mu_loose_high)<<"        "<<Form("%.0f",y_DY_mu_loose_high_weight)<<"         "<<Form("%.3f",y_DY_mu_loose_high_ratio)<<"    "<<endl;
  Table<<"................................................................................................................. "<<endl;
  Table<<"Tight Muons"<<"     low pt            "<<Form("%.0f",y_data_mu_tight_low)<<"    "<<Form("%.0f",y_WJets_mu_tight_low_weight)<<"          "<<Form("%.0f",y_WJets_mu_tight_low)<<"         "<<Form("%.3f",y_WJets_mu_tight_low_ratio)<<"          "<<Form("%.0f",y_DY_mu_tight_low)<<"          "<<Form("%.0f",y_DY_mu_tight_low_weight)<<"         "<<Form("%.3f",y_DY_mu_tight_low_ratio)<<"    "<<endl;
  Table<<"           "<<"     high pt           "<<Form("%.0f",y_data_mu_tight_high)<<"    "<<Form("%.0f",y_WJets_mu_tight_high_weight)<<"       "<<Form("%.0f",y_WJets_mu_tight_high)<<"         "<<Form("%.3f",y_WJets_mu_tight_high_ratio)<<"          "<<Form("%.0f",y_DY_mu_tight_high)<<"        "<<Form("%.0f",y_DY_mu_tight_high_weight)<<"         "<<Form("%.3f",y_DY_mu_tight_high_ratio)<<"    "<<endl;
  Table<<"................................................................................................................. "<<endl;
  Table<<"Loose Electrons"<<" low pt            "<<Form("%.0f",y_data_ele_loose_low)<<"    "<<Form("%.0f",y_WJets_ele_loose_low_weight)<<"         "<<Form("%.0f",y_WJets_ele_loose_low)<<"         "<<Form("%.3f",y_WJets_ele_loose_low_ratio)<<"          "<<Form("%.0f",y_DY_ele_loose_low)<<"         "<<Form("%.0f",y_DY_ele_loose_low_weight)<<"         "<<Form("%.3f",y_DY_ele_loose_low_ratio)<<"    "<<endl;
  Table<<"           "<<"     high pt           "<<Form("%.0f",y_data_ele_loose_high)<<"    "<<Form("%.0f",y_WJets_ele_loose_high_weight)<<"         "<<Form("%.0f",y_WJets_ele_loose_high)<<"         "<<Form("%.3f",y_WJets_ele_loose_high_ratio)<<"          "<<Form("%.0f",y_DY_ele_loose_high)<<"         "<<Form("%.0f",y_DY_ele_loose_high_weight)<<"         "<<Form("%.3f",y_DY_ele_loose_high_ratio)<<"    "<<endl;
  Table<<"................................................................................................................. "<<endl;
  Table<<"Tight Electrons"<<" low pt            "<<Form("%.0f",y_data_ele_tight_low)<<"    "<<Form("%.0f",y_WJets_ele_tight_low_weight)<<"         "<<Form("%.0f",y_WJets_ele_tight_low)<<"         "<<Form("%.3f",y_WJets_ele_tight_low_ratio)<<"          "<<Form("%.0f",y_DY_ele_tight_low)<<"         "<<Form("%.0f",y_DY_ele_tight_low_weight)<<"         "<<Form("%.3f",y_DY_ele_tight_low_ratio)<<"    "<<endl;
  Table<<"           "<<"     high pt           "<<Form("%.0f",y_data_ele_tight_high)<<"     "<<Form("%.0f",y_WJets_ele_tight_high_weight)<<"         "<<Form("%.0f",y_WJets_ele_tight_high)<<"         "<<Form("%.3f",y_WJets_ele_tight_high_ratio)<<"          "<<Form("%.0f",y_DY_ele_tight_high)<<"         "<<Form("%.0f",y_DY_ele_tight_high_weight)<<"         "<<Form("%.3f",y_DY_ele_tight_high_ratio)<<"    "<<endl;
  Table<<"................................................................................................................. "<<endl;
  cout<<"THE END"<<endl;
}

