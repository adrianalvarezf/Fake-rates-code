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

Double_t Inv_mass(Int_t A, Int_t B){

  const Double_t MUON_MASS     = 0.106;     // [GeV]
  const Double_t ELECTRON_MASS = 0.000511; // [GeV]
  TLorentzVector lep1;
  TLorentzVector lep2;
  TLorentzVector ll;
  Double_t mass_1,mass_2;

  if (Lepton_electronIdx[A] >= 0){
    mass_1  = ELECTRON_MASS;
  }  
  else if (Lepton_muonIdx[A] >= 0){
    mass_1  = MUON_MASS;
  }
  if (Lepton_electronIdx[B] >= 0){
    mass_2  = ELECTRON_MASS;
  }  
  else if (Lepton_muonIdx[B] >= 0){
    mass_2  = MUON_MASS;
  }

  lep1.SetPtEtaPhiM(Lepton_pt[A], Lepton_eta[A], Lepton_phi[A], mass_1); 
  lep2.SetPtEtaPhiM(Lepton_pt[B], Lepton_eta[B], Lepton_phi[B], mass_2); 
  ll = lep1 + lep2;

  return ll.M();

}

void Fake_ratesZ(TString sample) {

  // Import the nanoLatino Tree
  //--------------------------------------------------------------------------------------------------------------------------------------
 
  TChain* tree = new TChain("Events");

  //DATA
  TString myFolderData = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2017_nAOD_v1_Full2017v2/DATAl1loose2017v2__DATACorr2017/";   
  //MC
  TString myFolder = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017v2__MCCorr2017/";

  TString outputdir ="/afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code/outputsFR_Z/";

  TString file = "";
  bool isData = false;  bool isDY =false;  bool isWj =false;
  double weight = 1;
  if(sample.Contains("Run")){ file = myFolderData + "nanoLatino_" + sample + ".root"; isData=true; }
  else{ file = myFolder + "nanoLatino_" +sample + ".root"; if(sample.Contains("DY"))isDY=true; }

  TFile* root_output = new TFile(outputdir +"output_" + sample +"_"+channel+".root", "recreate");

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
  Bool_t HLT_Mu8_TrkIsoVVL;
  tree->SetBranchAddress("HLT_Mu8_TrkIsoVVL",&HLT_Mu8_TrkIsoVVL);
  Bool_t HLT_Mu17_TrkIsoVVL;
  tree->SetBranchAddress("HLT_Mu17_TrkIsoVVL",&HLT_Mu17_TrkIsoVVL);


  TLorentzVector lep1;
  TLorentzVector lep2;
  TLorentzVector ll;
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

  Float_t eletightlow = 0;
  Float_t eletighthigh = 0;
  Float_t elelooselow = 0;
  Float_t eleloosehigh = 0;
  Float_t mutightlow = 0;
  Float_t mutighthigh = 0;
  Float_t mulooselow = 0;
  Float_t muloosehigh = 0;
  Float_t eletightlowjet = 0;
  Float_t eletighthighjet = 0;
  Float_t elelooselowjet = 0;
  Float_t eleloosehighjet = 0;
  Float_t mutightlowjet = 0;
  Float_t mutighthighjet = 0;
  Float_t mulooselowjet = 0;
  Float_t muloosehighjet = 0;
  cout<<"Begin..."<<endl;

  // Create the output histograms
  //--------------------------------------------------------------------------------------------------------------------------------------
 
  TH1F* h_pt1_tight   = new TH1F("h_pt1_tight","h_pt1_tight",8,10,50);
  TH1F* h_eta1_tight  = new TH1F("h_eta1_tight ","h_eta1_tight",5,0,2.5);
  TH1F* h_pt1_loose   = new TH1F("h_pt1_loose","h_pt1_loose",8,10,50);
  TH1F* h_eta1_loose  = new TH1F("h_eta1_loose","h_eta1_loose",5,0,2.5);

  TH1F* h_pt1_tight_low  = new TH1F("h_pt1_tight_low","h_pt1_tight_low",8,10,50);
  TH1F* h_eta1_tight_low = new TH1F("h_eta1_tight_low","h_eta1_tight_low",5,0,2.5);
  TH1F* h_pt1_loose_low  = new TH1F("h_pt1_loose_low","h_pt1_de _low",8,10,50);
  TH1F* h_eta1_loose_low = new TH1F("h_eta1_loose_low","h_eta1_loose_low",5,0,2.5);

  TH1F* h_pt1_tight_high  = new TH1F("h_pt1_tight_high","h_pt1_tight_high",8,10,50);
  TH1F* h_eta1_tight_high = new TH1F("h_eta1_tight_high","h_eta1_tight_high",5,0,2.5);
  TH1F* h_pt1_loose_high  = new TH1F("h_pt1_loose_high","h_pt1_loose_high",8,10,50);
  TH1F* h_eta1_loose_high = new TH1F("h_eta1_loose_high","h_eta1_loose_high",5,0,2.5);
  
  
  // Loop over the tree events
  //--------------------------------------------------------------------------------------------------------------------------------------

  //for (int j = 0; j < 200000; ++j){
  for (int j = 0; j < tree->GetEntries(); ++j){
    tree->GetEntry(j);
    int nentries = tree->GetEntriesFast();
    if(fmod(j,100000)==0) Printf(" ..... event %d of %d", int(j), int(nentries));

    // if(j > MaxEvents){
    //   cout << "finished for " << MaxEvents << " events" << endl;
    //   break;
    // }

    //------------------------------ Preselection --------------------------------------

    if (nLepton!=3){continue;}
    
    int fakelep;
    TString channel="";
    if (fabs(Inv_mass(0,1)-91.18) <= fabs(Inv_mass(0,2)-91.18) ) fakelep=1;
    else fakelep=2;
    if(fabs(Inv_mass(0,fakelep)-91.18)>15){continue;}
    if (Lepton_electronIdx[fakelep] >= 0) channel="ele";
    else channel="mu"; 

    if(isData==false) weight=baseW*Generator_weight*puWeight;
   
    if (channel=="ele"){
      if (abs(Lepton_pdgId[fakelep])!=11)continue;
      if (Lepton_pt[fakelep]<13 || fabs(Lepton_eta[fakelep])>=2.5)continue;
      if (Lepton_pt[fakelep] <= 25.){
	if (HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 < 0.5)continue;
	else {	
	  if(isData==false)weight*=0.027699;
	  elelooselow+=weight; h_pt1_loose->Fill(Lepton_pt[fakelep],weight); h_eta1_loose->Fill(Lepton_eta[fakelep],weight); h_pt1_loose_low->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_low->Fill(Lepton_eta[fakelep],weight);
	  if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[fakelep]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[fakelep]])< 0.1 && ((Lepton_pt[fakelep]>20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.02)||(Lepton_pt[fakelep]<=20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.01))){
	    eletightlow+=weight; h_pt1_tight->Fill(Lepton_pt[fakelep],weight); h_eta1_tight->Fill(Lepton_eta[fakelep],weight); h_pt1_tight_low->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_low->Fill(Lepton_eta[fakelep],weight);}
	}
      }
      if (Lepton_pt[fakelep] > 25.){
	if (HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 < 0.5)continue;
	else{ 
	  if(isData==false)weight*=0.043469;
	  eleloosehigh+=weight; h_pt1_loose->Fill(Lepton_pt[fakelep],weight); h_eta1_loose->Fill(Lepton_eta[fakelep],weight); h_pt1_loose_high->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_high->Fill(Lepton_eta[fakelep],weight);
	  if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[fakelep]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[fakelep]])< 0.1 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.02){
	    eletighthigh+=weight; h_pt1_tight->Fill(Lepton_pt[fakelep],weight); h_eta1_tight->Fill(Lepton_eta[fakelep],weight); h_pt1_tight_high->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_high->Fill(Lepton_eta[fakelep],weight);}
	} 
      }
    }

    if (channel=="mu"){
      if (abs(Lepton_pdgId[fakelep])!=13)continue;
      if (Lepton_pt[fakelep]<10 || fabs(Lepton_eta[fakelep])>=2.4)continue;
      if (Lepton_pt[fakelep] <= 20.){
	if (HLT_Mu8_TrkIsoVVL < 0.5)continue;
	else {
	  if(isData==false)weight*=0.002903;
	  mulooselow+=weight; h_pt1_loose->Fill(Lepton_pt[fakelep],weight); h_eta1_loose->Fill(Lepton_eta[fakelep],weight); h_pt1_loose_low->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_low->Fill(Lepton_eta[fakelep],weight);
	  if(Lepton_isTightMuon_cut_Tight_HWWW[fakelep]>0.5) {mutightlow+=weight; h_pt1_tight->Fill(Lepton_pt[fakelep],weight); h_eta1_tight->Fill(Lepton_eta[fakelep],weight); h_pt1_tight_low->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_low->Fill(Lepton_eta[fakelep],weight);}
	}
      }
      if (Lepton_pt[fakelep] > 20.){
	if (HLT_Mu17_TrkIsoVVL < 0.5)continue;
	else{
	  if(isData==false)weight*=0.065944;
	  muloosehigh+=weight; h_pt1_loose->Fill(Lepton_pt[fakelep],weight); h_eta1_loose->Fill(Lepton_eta[fakelep],weight); h_pt1_loose_high->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_high->Fill(Lepton_eta[fakelep],weight);
	  if(Lepton_isTightMuon_cut_Tight_HWWW[fakelep]>0.5) {mutighthigh+=weight; h_pt1_tight->Fill(Lepton_pt[fakelep],weight); h_eta1_tight->Fill(Lepton_eta[fakelep],weight); h_pt1_tight_high->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_high->Fill(Lepton_eta[fakelep],weight);}
	} 
      }
    }
    
  }

  //Write histograms in root output

  TDirectory *without = root_output->mkdir("output");
  without->cd();

  h_pt1_tight->Write();  
  h_eta1_tight->Write();
  h_pt1_loose ->Write();
  h_eta1_loose->Write();

  h_pt1_tight_low->Write(); 
  h_eta1_tight_low->Write();
  h_pt1_loose_low ->Write();
  h_eta1_loose_low->Write();

  h_pt1_tight_high->Write();
  h_eta1_tight_high->Write();
  h_pt1_loose_high ->Write();
  h_eta1_loose_high->Write();
 
  root_output->Close();
 
  //Print number of events
  
  if(channel=="mu"){
    printf(" With jet cut \n");
    printf("loose muons, low pt: %f \n",  mulooselow);
    printf("loose muons, high pt: %f \n", muloosehigh);
    printf("tight muons, low pt: %f \n",  mutightlow);
    printf("tight muons, high pt: %f \n", mutighthigh);
  }  
  
  if(channel=="ele"){
    printf(" With jet cut \n");
    printf("loose electrons, low pt: %f \n",  elelooselow);
    printf("loose electrons, high pt: %f \n", eleloosehigh);
    printf("tight electrons, low pt: %f \n",  eletightlow);
    printf("tight electrons, high pt: %f \n", eletighthigh);
  }
  
  
  cout << endl;
  cout << "-------- Done ---------";
  cout << endl;

}
