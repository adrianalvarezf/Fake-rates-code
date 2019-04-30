#include "TCanvas.h"
#include "TTree.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <TLorentzVector.h>
#include "TMath.h"
using namespace std;

void treeadder(TString dir ,TString channel){

  //Channel is Ele or Muon

  for(int j=0;j<8;j++){
    int jetcut = 10 + j*5;
    TString file = Form(channel+"FR_jet%d.root",jetcut);
    TString subdir = dir; subdir.ReplaceAll("FR","plots"); subdir.ReplaceAll("_exclusive","");
    TFile *f_all = new TFile(dir+"/"+file,"recreate");
    TFile *f_no = new TFile(dir+"/"+ subdir +"_nobtag_exclusive"+"/"+file);
    TFile *f_loose = new TFile(dir+"/"+ subdir +"_loosebtag_exclusive"+"/"+file);
    TFile *f_medium = new TFile(dir+"/"+ subdir +"_mediumbtag_exclusive"+"/"+file);
    TFile *f_tight = new TFile(dir+"/"+ subdir +"_tightbtag_exclusive"+"/"+file);
  
    TFile *f[4];
    f[0]=f_no; 
    f[1]=f_loose; 
    f[2]=f_medium; 
    f[3]=f_tight; 

    TDirectory *btagwp[4];

    TH1F *FR_pT_eta; TH1F *FR_pT_eta_numerator; TH1F *FR_pT_eta_denominator; TH1F *FR_pT_eta_EWKcorr; TH1F *FR_pT_eta_EWKcorr_numerator; TH1F *FR_pT_eta_EWKcorr_denominator;

    for(int b=0;b<4;b++){
      FR_pT_eta = (TH1F*)f[b]->Get("FR_pT_eta");
      FR_pT_eta_numerator = (TH1F*)f[b]->Get("FR_pT_eta_numerator"); 
      FR_pT_eta_denominator = (TH1F*)f[b]->Get("FR_pT_eta_denominator"); 
      FR_pT_eta_EWKcorr = (TH1F*)f[b]->Get("FR_pT_eta_EWKcorr");
      FR_pT_eta_EWKcorr_numerator = (TH1F*)f[b]->Get("FR_pT_eta_EWKcorr_numerator");
      FR_pT_eta_EWKcorr_denominator = (TH1F*)f[b]->Get("FR_pT_eta_EWKcorr_denominator");
      if(b==0)btagwp[b]=f_all->mkdir("bveto");
      else if(b==1)btagwp[b]=f_all->mkdir("loosebtag");
      else if(b==2)btagwp[b]=f_all->mkdir("mediumbtag");
      else if(b==3)btagwp[b]=f_all->mkdir("tightbtag");
      btagwp[b]->cd();
      FR_pT_eta->Write();
      FR_pT_eta_numerator->Write();
      FR_pT_eta_denominator->Write();
      FR_pT_eta_EWKcorr->Write();
      FR_pT_eta_EWKcorr_numerator->Write();
      FR_pT_eta_EWKcorr_denominator->Write();
    }
    f_all->Close();

  }


  cout<<"...Done!"<<endl;

}
