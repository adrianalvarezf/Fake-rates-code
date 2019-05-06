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

void treeadder(TString dir ,TString channel, int bins){

  //Channel is Ele or Muon
  if(channel!="Ele" && channel!="Muon"){cout<<"Error: channel must be Ele or Muon"<<endl;return -1;}
  //Bins are 3 or 4
  if(bins!=3 && bins!=4){cout<<"Error: number of bins must be 3 or 4"<<endl;return -1;}

  for(int j=0;j<8;j++){
    int jetcut = 10 + j*5;
    TString file = Form(channel+"FR_jet%d.root",jetcut);
    TString subdir = dir; subdir.ReplaceAll("FR","plots"); subdir.ReplaceAll("_exclusive","");
    TFile *f_all = new TFile(dir+"/"+file,"recreate");
    TFile *f[bins-1];
    f[0]=new TFile(dir+"/"+ subdir +"_bvetobtag"+"_exclusive/"+file);
    f[1]=new TFile(dir+"/"+ subdir +"_loosebtag"+"_exclusive/"+file);
    if(bins==4){
      f[2]=new TFile(dir+"/"+ subdir +"_mediumbtag"+"_exclusive/"+file);
      f[3]=new TFile(dir+"/"+ subdir +"_tightbtag"+"_exclusive/"+file);
    }
    else if(bins==3) f[2]=new TFile(dir+"/"+ subdir +"_mediumtightbtag"+"_exclusive/"+file);
   
    TDirectory *btagwp[4];
    TH1F *FR_pT_eta; TH1F *FR_pT_eta_numerator; TH1F *FR_pT_eta_denominator; TH1F *FR_pT_eta_EWKcorr; TH1F *FR_pT_eta_EWKcorr_numerator; TH1F *FR_pT_eta_EWKcorr_denominator;

    TString dirname=dir; dirname.ReplaceAll("_DeepCSV_exclusive","files");
    system("mkdir -p "+dir+"/"+dirname+Form("_%dbins",bins));
    chdir(dirname);

    for(int b=0;b<bins;b++){
      FR_pT_eta = (TH1F*)f[b]->Get("FR_pT_eta");
      FR_pT_eta_numerator = (TH1F*)f[b]->Get("FR_pT_eta_numerator"); 
      FR_pT_eta_denominator = (TH1F*)f[b]->Get("FR_pT_eta_denominator"); 
      FR_pT_eta_EWKcorr = (TH1F*)f[b]->Get("FR_pT_eta_EWKcorr");
      FR_pT_eta_EWKcorr_numerator = (TH1F*)f[b]->Get("FR_pT_eta_EWKcorr_numerator");
      FR_pT_eta_EWKcorr_denominator = (TH1F*)f[b]->Get("FR_pT_eta_EWKcorr_denominator");
      if(b==0)btagwp[b]=f_all->mkdir("bveto");
      else if(b==1)btagwp[b]=f_all->mkdir("loosebtag");
      else if(b==2&&bins==4)btagwp[b]=f_all->mkdir("mediumbtag");
      else if(b==3&&bins==4)btagwp[b]=f_all->mkdir("tightbtag");
      else if(b==2&&bins==3)btagwp[b]=f_all->mkdir("mediumtightbtag");
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
