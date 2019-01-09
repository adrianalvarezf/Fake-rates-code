#include <iostream>
#include <fstream>
#include <string>
#include <TLorentzVector.h>
#include "TMath.h"
using namespace std;

Double_t deltaPhi(Double_t Phi0, Double_t Phi1) {
  Double_t dphi = Phi0-Phi1;
  while (dphi >= TMath::Pi()) dphi -= TMath::TwoPi();
  while (dphi < -TMath::Pi()) dphi += TMath::TwoPi();
  return dphi;
} 



void Fake_ratesZ(TString sample) {

  // Import the nanoLatino Tree
  //--------------------------------------------------------------------------------------------------------------------------------------
 
  TChain* tree = new TChain("Events");

  //DATA
  TString myFolderData = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2017_nAOD_v1_Full2017v2/DATAl1loose2017v2__DATACorr2017__fakeSel/";   
  //MC
  TString myFolderMC = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017v2__MCCorr2017__btagPerEvent/";

  TString outputdir ="/afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code/outputsFR_Z_Jan9/";

  TString file = "";
  TString datastream ="";
  bool isData = false;  
  double weight = 1;
  if(sample.Contains("Run")){file = myFolderData + sample ; isData=true; }
  else{file = myFolderMC + sample ; }
  if(isData==true && sample.Contains("Muon"))datastream= "muonstream";
  else if(isData==true && sample.Contains("Electron"))datastream= "electronstream";
  
  TFile* root_output = new TFile(outputdir +"output_" + sample, "recreate");

  cout<<file<<endl;
  if(ifstream(file))tree->Add(file);
  else cout<<"File not loaded"<<endl;
     
  // Import the variables
  //--------------------------------------------------------------------------------------------------------------------------------------
  Int_t nLepton;
  tree->SetBranchAddress("nLepton",&nLepton);
  Int_t nCleanJet;
  tree->SetBranchAddress("nCleanJet",&nCleanJet);
 
  Int_t Lepton_muonIdx[200];
  tree->SetBranchAddress("Lepton_muonIdx",&Lepton_muonIdx);
  Int_t Lepton_electronIdx[200];
  tree->SetBranchAddress("Lepton_electronIdx",&Lepton_electronIdx);
  Int_t CleanJet_jetIdx[200];
  tree->SetBranchAddress("CleanJet_jetIdx",&CleanJet_jetIdx);
  Int_t Lepton_pdgId[200];
  tree->SetBranchAddress("Lepton_pdgId",&Lepton_pdgId);
  Int_t Lepton_isTightMuon_cut_Tight_HWWW[200];
  tree->SetBranchAddress("Lepton_isTightMuon_cut_Tight_HWWW",&Lepton_isTightMuon_cut_Tight_HWWW);
  Bool_t Electron_mvaFall17Iso_WP90[200];
  tree->SetBranchAddress("Electron_mvaFall17Iso_WP90",&Electron_mvaFall17Iso_WP90);
  Int_t Electron_cutBased[200];
  tree->SetBranchAddress("Electron_cutBased",&Electron_cutBased);
  UChar_t Electron_lostHits[200];
  tree->SetBranchAddress("Electron_lostHits",&Electron_lostHits);
  Float_t Electron_dxy[200];
  tree->SetBranchAddress("Electron_dxy",&Electron_dxy);
  Float_t Electron_dz[200];
  tree->SetBranchAddress("Electron_dz",&Electron_dz);

  Float_t Muon_dxy[200];
  tree->SetBranchAddress("Muon_dxy",&Muon_dxy);
  Float_t Muon_dz[200];
  tree->SetBranchAddress("Muon_dz",&Muon_dz);
  Float_t Lepton_pt[200];
  tree->SetBranchAddress("Lepton_pt",&Lepton_pt);
  Float_t Lepton_eta[200];
  tree->SetBranchAddress("Lepton_eta",&Lepton_eta);
  Float_t Lepton_phi[200];
  tree->SetBranchAddress("Lepton_phi",&Lepton_phi);
  Float_t MET_pt;
  tree->SetBranchAddress("MET_pt",&MET_pt);
  Float_t MET_phi;
  tree->SetBranchAddress("MET_phi",&MET_phi);
  Float_t mtw1;
  tree->SetBranchAddress("mtw1",&mtw1);
  Float_t TkMET_pt;
  tree->SetBranchAddress("TkMET_pt",&TkMET_pt);
  Float_t TkMET_phi;
  tree->SetBranchAddress("TkMET_phi",&TkMET_phi);
  Float_t Jet_btagCSVV2[200];
  tree->SetBranchAddress("Jet_btagCSVV2",&Jet_btagCSVV2);
  Float_t CleanJet_pt[200];
  tree->SetBranchAddress("CleanJet_pt",&CleanJet_pt);
  Float_t CleanJet_eta[200];
  tree->SetBranchAddress("CleanJet_eta",&CleanJet_eta);
  Float_t CleanJet_phi[200];
  tree->SetBranchAddress("CleanJet_phi",&CleanJet_phi);
  Float_t puWeight;
  tree->SetBranchAddress("puWeight",&puWeight);
  Float_t baseW;
  tree->SetBranchAddress("baseW",&baseW);
  Float_t Generator_weight;
  tree->SetBranchAddress("Generator_weight",&Generator_weight);

  Int_t event;
  tree->SetBranchAddress("event",&event);

  Bool_t HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30;
  tree->SetBranchAddress("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30",&HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30);
  Bool_t HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30;
  tree->SetBranchAddress("HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30",&HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30);
  Bool_t HLT_Ele35_WPTight_Gsf;
  tree->SetBranchAddress("HLT_Ele35_WPTight_Gsf",&HLT_Ele35_WPTight_Gsf);
  Bool_t HLT_Mu8_TrkIsoVVL;
  tree->SetBranchAddress("HLT_Mu8_TrkIsoVVL",&HLT_Mu8_TrkIsoVVL);
  Bool_t HLT_Mu17_TrkIsoVVL;
  tree->SetBranchAddress("HLT_Mu17_TrkIsoVVL",&HLT_Mu17_TrkIsoVVL);
  Bool_t HLT_IsoMu27;
  tree->SetBranchAddress("HLT_IsoMu27",&HLT_IsoMu27);

  TLorentzVector MET;
  TLorentzVector trkMET;
  Float_t mass_1;
  Float_t mass_2;
  Float_t event_weight;
  Float_t dphil1trkmet;
  Float_t dphil2trkmet;
  Float_t dphiltrkmet;
  Float_t dphil1met;
  Float_t dphil2met;
  Float_t dphilmet;
  Float_t fullpmet;
  Float_t trkpmet;
  Float_t mpmet;
  Float_t dphillmet;
  Float_t mth;
  Float_t mtw2;

  Float_t leptight = 0;
  Float_t leploose = 0;
  Float_t leptight_mutrig = 0;
  Float_t leploose_mutrig = 0;
  Float_t leptight_eletrig = 0;
  Float_t leploose_eletrig = 0;
  cout<<"Begin..."<<endl;

  // Create the output histograms
  //--------------------------------------------------------------------------------------------------------------------------------------
 
  TH1F* h_pt1_tight   = new TH1F("h_pt1_tight","h_pt1_tight",8,10,50);
  TH1F* h_eta1_tight  = new TH1F("h_eta1_tight","h_eta1_tight",5,0,2.5);
  TH1F* h_pt1_loose   = new TH1F("h_pt1_loose","h_pt1_loose",8,10,50);
  TH1F* h_eta1_loose  = new TH1F("h_eta1_loose","h_eta1_loose",5,0,2.5);
  TH1F* h_pt1_tight_mutrig   = new TH1F("h_pt1_tight_mutrig","h_pt1_tight_mutrig",8,10,50);
  TH1F* h_eta1_tight_mutrig  = new TH1F("h_eta1_tight_mutrig","h_eta1_tight_mutrig",5,0,2.5);
  TH1F* h_pt1_loose_mutrig   = new TH1F("h_pt1_loose_mutrig","h_pt1_loose_mutrig",8,10,50);
  TH1F* h_eta1_loose_mutrig  = new TH1F("h_eta1_loose_mutrig","h_eta1_loose_mutrig",5,0,2.5);
  TH1F* h_pt1_tight_eletrig   = new TH1F("h_pt1_tight_eletrig","h_pt1_tight_eletrig",8,10,50);
  TH1F* h_eta1_tight_eletrig  = new TH1F("h_eta1_tight_eletrig","h_eta1_tight_eletrig",5,0,2.5);
  TH1F* h_pt1_loose_eletrig   = new TH1F("h_pt1_loose_eletrig","h_pt1_loose_eletrig",8,10,50);
  TH1F* h_eta1_loose_eletrig  = new TH1F("h_eta1_loose_eletrig","h_eta1_loose_eletrig",5,0,2.5);
  const Double_t MUON_MASS     = 0.106;     // [GeV]
  const Double_t ELECTRON_MASS = 0.000511; // [GeV]
  TLorentzVector lep1,lep2,lep3,l1l2,l1l3;
  Double_t mass[3];
 
  // Loop over the tree events
  //--------------------------------------------------------------------------------------------------------------------------------------

  //for (int j = 0; j < 200000; ++j){
  for (int j = 0; j < tree->GetEntries(); ++j){
    tree->GetEntry(j);
    int nentries = tree->GetEntriesFast();
    if(fmod(j,100000)==0) Printf(" ..... event %d of %d", int(j), int(nentries));

    for(int a=0;a<3;a++){
      if (Lepton_electronIdx[a] >= 0){
	mass[a]  = ELECTRON_MASS;
      }  
      else if (Lepton_muonIdx[a] >= 0){
	mass[a]  = MUON_MASS;
      }
    }
    lep1.SetPtEtaPhiM(Lepton_pt[0], Lepton_eta[0], Lepton_phi[0], mass[0]); 
    lep2.SetPtEtaPhiM(Lepton_pt[1], Lepton_eta[1], Lepton_phi[1], mass[1]); 
    lep3.SetPtEtaPhiM(Lepton_pt[2], Lepton_eta[2], Lepton_phi[2], mass[2]); 
    l1l2 = lep1 + lep2;
    l1l3 = lep1 + lep3;

    // if(j > MaxEvents){
    //   cout << "finished for " << MaxEvents << " events" << endl;
    //   break;
    // }

    //------------------------------ Preselection --------------------------------------

    if (nLepton!=3){continue;}
    
    //DATA
    
    int fakelep;
    TString channel="";
    if ((fabs(l1l2.M()-91.18) <= fabs(l1l3.M()-91.18))&& fabs(l1l2.M()-91.18)<=15) fakelep=1;
    else if((fabs(l1l3.M()-91.18) <= fabs(l1l2.M()-91.18))&& fabs(l1l3.M()-91.18)<=15)fakelep=2;
    else {continue;}
    if (Lepton_electronIdx[fakelep] >= 0) channel="ele";
    else channel="mu"; 

    //DATA
    if (isData==true){
      if (datastream=="electronstream" && HLT_Ele35_WPTight_Gsf < 0.5)continue;
      else if (datastream=="muonstream" && HLT_IsoMu27 < 0.5)continue;

      if (channel=="ele"){
	if (abs(Lepton_pdgId[fakelep])!=11)continue;
	//if (Lepton_pt[fakelep]<13 || fabs(Lepton_eta[fakelep])>=2.5)continue;
	else {	
	  //if(isData==false)weight*=0.041527;
	  leploose+=weight; h_pt1_loose->Fill(Lepton_pt[fakelep],weight); h_eta1_loose->Fill(Lepton_eta[fakelep],weight);
	  if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[fakelep]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[fakelep]])< 0.1 && ((Lepton_pt[fakelep]>20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.02)||(Lepton_pt[fakelep]<=20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.01))){
	    leptight+=weight; h_pt1_tight->Fill(Lepton_pt[fakelep],weight); h_eta1_tight->Fill(Lepton_eta[fakelep],weight);}
	}
      }

      if (channel=="mu"){
	if (abs(Lepton_pdgId[fakelep])!=13)continue;
	//if (Lepton_pt[fakelep]<10 || fabs(Lepton_eta[fakelep])>=2.4)continue;
	else {
	  //if(isData==false)weight*=0.041527;
	  leploose+=weight; h_pt1_loose->Fill(Lepton_pt[fakelep],weight); h_eta1_loose->Fill(Lepton_eta[fakelep],weight);
	  if(Lepton_isTightMuon_cut_Tight_HWWW[fakelep]>0.5) {
	    leptight+=weight; h_pt1_tight->Fill(Lepton_pt[fakelep],weight); h_eta1_tight->Fill(Lepton_eta[fakelep],weight);}
	}
      }
    }

    //MC
    else{
      weight=baseW*Generator_weight*puWeight;
      if( HLT_Ele35_WPTight_Gsf > 0.5){//MC for comparing with the electron data
	if (channel=="ele"){
	  if (abs(Lepton_pdgId[fakelep])!=11)continue;
	  //if (Lepton_pt[fakelep]<13 || fabs(Lepton_eta[fakelep])>=2.5)continue;
	  else {	
	   weight*=0.041527;
	    leploose_eletrig+=weight; h_pt1_loose_eletrig->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_eletrig->Fill(Lepton_eta[fakelep],weight);
	    if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[fakelep]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[fakelep]])< 0.1 && ((Lepton_pt[fakelep]>20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.02)||(Lepton_pt[fakelep]<=20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.01))){
	      leptight_eletrig+=weight; h_pt1_tight_eletrig->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_eletrig->Fill(Lepton_eta[fakelep],weight);}
	  }
	}
	if (channel=="mu"){
	  if (abs(Lepton_pdgId[fakelep])!=13)continue;
	  //if (Lepton_pt[fakelep]<10 || fabs(Lepton_eta[fakelep])>=2.4)continue;
	  else {
	    weight*=0.041527;
	    leploose_eletrig+=weight; h_pt1_loose_eletrig->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_eletrig->Fill(Lepton_eta[fakelep],weight);
	    if(Lepton_isTightMuon_cut_Tight_HWWW[fakelep]>0.5) {
	      leptight_eletrig+=weight; h_pt1_tight_eletrig->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_eletrig->Fill(Lepton_eta[fakelep],weight);}
	  }
	}
      }
      if( HLT_IsoMu27 > 0.5){//MC for the muon data
	if (channel=="ele"){
	  if (abs(Lepton_pdgId[fakelep])!=11)continue;
	  //if (Lepton_pt[fakelep]<13 || fabs(Lepton_eta[fakelep])>=2.5)continue;
	  else {	
	    weight*=0.041527;
	    leploose_mutrig+=weight; h_pt1_loose_mutrig->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_mutrig->Fill(Lepton_eta[fakelep],weight);
	    if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[fakelep]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[fakelep]])< 0.1 && ((Lepton_pt[fakelep]>20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.02)||(Lepton_pt[fakelep]<=20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.01))){
	      leptight_mutrig+=weight; h_pt1_tight_mutrig->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_mutrig->Fill(Lepton_eta[fakelep],weight);}
	  }
	}
	if (channel=="mu"){
	  if (abs(Lepton_pdgId[fakelep])!=13)continue;
	  //if (Lepton_pt[fakelep]<10 || fabs(Lepton_eta[fakelep])>=2.4)continue;
	  else {
	    weight*=0.041527;
	    leploose_mutrig+=weight; h_pt1_loose_mutrig->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_mutrig->Fill(Lepton_eta[fakelep],weight);
	    if(Lepton_isTightMuon_cut_Tight_HWWW[fakelep]>0.5) {
	      leptight_mutrig+=weight; h_pt1_tight_mutrig->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_mutrig->Fill(Lepton_eta[fakelep],weight);}
	  }
	}
      }

    }//close if MC
  }//close event loop

  //Write histograms in root output
  if(isData==1){
    h_pt1_tight ->Write();  
    h_eta1_tight->Write();
    h_pt1_loose ->Write();
    h_eta1_loose->Write();
  }
  else{
    h_pt1_tight_eletrig ->Write();  
    h_eta1_tight_eletrig->Write();
    h_pt1_loose_eletrig ->Write();
    h_eta1_loose_eletrig->Write();
    h_pt1_tight_mutrig ->Write();  
    h_eta1_tight_mutrig->Write();
    h_pt1_loose_mutrig ->Write();
    h_eta1_loose_mutrig->Write();
  }
  root_output->Close();
 
  //Print number of events
  if(isData==1){
    printf("loose leptons: %f \n", leploose);
    printf("tight leptons: %f \n", leptight);
  }
  else{
    printf("loose leptons, mu trigger: %f \n", leploose_mutrig);
    printf("tight leptons, mu trigger: %f \n", leptight_mutrig);
    printf("loose leptons, ele trigger: %f \n", leploose_eletrig);
    printf("tight leptons, ele trigger: %f \n", leptight_eletrig);
  }
  cout << endl;
  cout << "-------- Done ---------";
  cout << endl;

}
