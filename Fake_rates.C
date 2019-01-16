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

void Fake_rates(TString sample,  TString channel ,TString nojetcut) {

  //if (argc<3) {
  //  printf('Ejemplo: root -b -q "Fake_rates(sample , mu)" ');
  //  return -1;
  // }

  //Options
  //--------------------------------------------------------------------------------------------------------------------------------------

  if (channel != "ele" && channel != "mu") {printf("channel must be ele or mu \n");return -1;}
  
  Bool_t nojet= false;
  if (nojetcut=="true") nojet=true;

  // Import the nanoLatino Tree
  //--------------------------------------------------------------------------------------------------------------------------------------
 
  TChain* tree = new TChain("Events");

  //DATA
  //TString myFolderData = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2017_nAOD_v1_Study2017/DATAl1loose2017__hadd/";
  //TString myFolderData = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2017_nAOD_v1_Full2017v2/DATAl1loose2017v2__DATACorr2017__fakeSel/"; 
  TString myFolderData = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2017_nAOD_v1_Full2017v2/DATAl1loose2017v2__DATACorr2017/";   
  //MC
  //TString myFolder = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Study2017/MCl1loose2017__baseW__hadd/";
  //TString myFolder = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017v2__MCCorr2017test__fakeSelMC/";
  TString myFolder = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017v2__MCCorr2017/";

  TString outputdir ="/afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code/outputsFR_17dec/";

  TString file = "";
  bool isData = false;  bool isDY =false;  bool isWj =false;
  double weight = 1;
  if(sample.Contains("Run")){ file = myFolderData + "nanoLatino_" + sample + ".root"; isData=true; }
  else{ file = myFolder + "nanoLatino_" +sample + ".root"; if(sample.Contains("DY"))isDY=true; if(sample.Contains("WJets"))isWj=true;}

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

  //Int_t Lepton_isTightMuon_cut_Medium80x[200];
  //tree->SetBranchAddress("Lepton_isTightMuon_cut_Medium80x",&Lepton_isTightMuon_cut_Medium80x);
  //Int_t Lepton_isTightMuon_cut_Tight80x[200];
  //tree->SetBranchAddress("Lepton_isTightMuon_cut_Tight80x",&Lepton_isTightMuon_cut_Tight80x);
  //Int_t Lepton_isTightMuon_cut_Tight80x_HWWW[200];
  //tree->SetBranchAddress("Lepton_isTightMuon_cut_Tight80x_HWWW",&Lepton_isTightMuon_cut_Tight80x_HWWW);
  Int_t Lepton_isTightMuon_cut_Tight_HWWW[200];
  tree->SetBranchAddress("Lepton_isTightMuon_cut_Tight_HWWW",&Lepton_isTightMuon_cut_Tight_HWWW);
  //Int_t Lepton_isTightElectron_mvaFall17Iso[200];
  //tree->SetBranchAddress("Lepton_isTightElectron_mvaFall17Iso",&Lepton_isTightElectron_mvaFall17Iso);
  //Bool_t Electron_mvaFall17Iso_WPL[200];
  //tree->SetBranchAddress("Electron_mvaFall17Iso_WPL",&Electron_mvaFall17Iso_WPL);
  //Bool_t Electron_mvaFall17Iso_WP80[200];
  //tree->SetBranchAddress("Electron_mvaFall17Iso_WP80",&Electron_mvaFall17Iso_WP80);
  Bool_t Electron_mvaFall17Iso_WP90[200];
  tree->SetBranchAddress("Electron_mvaFall17Iso_WP90",&Electron_mvaFall17Iso_WP90);
  //Bool_t Electron_mvaFall17noIso_WPL[200];
  //tree->SetBranchAddress("Electron_mvaFall17noIso_WPL",&Electron_mvaFall17noIso_WPL);
  //Bool_t Electron_mvaFall17noIso_WP80[200];
  //tree->SetBranchAddress("Electron_mvaFall17noIso_WP80",&Electron_mvaFall17noIso_WP80);
  //Bool_t Electron_mvaFall17noIso_WP90[200];
  //tree->SetBranchAddress("Electron_mvaFall17noIso_WP90",&Electron_mvaFall17noIso_WP90);
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
  
  TH1F* h_pt1_tight_jet   = new TH1F("h_pt1_tight_jet","h_pt1_tight_jet",8,10,50);
  TH1F* h_eta1_tight_jet  = new TH1F("h_eta1_tight_jet","h_eta1_tight_jet",5,0,2.5);
  TH1F* h_pt1_loose_jet   = new TH1F("h_pt1_loose_jet","h_pt1_loose_jet",8,10,50);
  TH1F* h_eta1_loose_jet  = new TH1F("h_eta1_loose_jet","h_eta1_loose_jet",5,0,2.5);

  TH1F* h_pt1_tight_low_jet  = new TH1F("h_pt1_tight_low_jet","h_pt1_tight_low_jet",8,10,50);
  TH1F* h_eta1_tight_low_jet = new TH1F("h_eta1_tight_low_jet","h_eta1_tight_low_jet",5,0,2.5);
  TH1F* h_pt1_loose_low_jet  = new TH1F("h_pt1_loose_low_jet","h_pt1_de _low",8,10,50);
  TH1F* h_eta1_loose_low_jet = new TH1F("h_eta1_loose_low_jet","h_eta1_loose_low_jet",5,0,2.5);

  TH1F* h_pt1_tight_high_jet  = new TH1F("h_pt1_tight_high_jet","h_pt1_tight_high_jet",8,10,50);
  TH1F* h_eta1_tight_high_jet = new TH1F("h_eta1_tight_high_jet","h_eta1_tight_high_jet",5,0,2.5);
  TH1F* h_pt1_loose_high_jet  = new TH1F("h_pt1_loose_high_jet","h_pt1_loose_high_jet",8,10,50);
  TH1F* h_eta1_loose_high_jet = new TH1F("h_eta1_loose_high_jet","h_eta1_loose_high_jet",5,0,2.5);


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

    if (nLepton!=1){continue;}
    if (MET_pt>20){continue;}
    if (mtw1>20){continue;}

    if(isData==false) weight=baseW*Generator_weight*puWeight;
    if(nojet==true){

      if (channel=="ele"){
	if (abs(Lepton_pdgId[0])!=11)continue;
	if (Lepton_pt[0]<13 || fabs(Lepton_eta[0])>=2.5)continue;
	if (Lepton_pt[0] <= 25.){
	  if (HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 < 0.5)continue;
	  else {	
	    if(isData==false)weight*=0.027699;
	    elelooselow+=weight; h_pt1_loose->Fill(Lepton_pt[0],weight); h_eta1_loose->Fill(fabs(Lepton_eta[0]),weight); h_pt1_loose_low->Fill(Lepton_pt[0],weight); h_eta1_loose_low->Fill(fabs(Lepton_eta[0]),weight);
	    if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[0]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[0]])< 0.1 && ((Lepton_pt[0]>20 && fabs(Electron_dxy[Lepton_electronIdx[0]])< 0.02)||(Lepton_pt[0]<=20 && fabs(Electron_dxy[Lepton_electronIdx[0]])< 0.01))){
	      eletightlow+=weight; h_pt1_tight->Fill(Lepton_pt[0],weight); h_eta1_tight->Fill(fabs(Lepton_eta[0]),weight); h_pt1_tight_low->Fill(Lepton_pt[0],weight); h_eta1_tight_low->Fill(fabs(Lepton_eta[0]),weight);}
	  }
	}
	if (Lepton_pt[0] > 25.){
	  if (HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 < 0.5)continue;
	  else{ 
	    if(isData==false)weight*=0.043469;
	    eleloosehigh+=weight; h_pt1_loose->Fill(Lepton_pt[0],weight); h_eta1_loose->Fill(fabs(Lepton_eta[0]),weight); h_pt1_loose_high->Fill(Lepton_pt[0],weight); h_eta1_loose_high->Fill(fabs(Lepton_eta[0]),weight);
	    if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[0]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[0]])< 0.1 && fabs(Electron_dxy[Lepton_electronIdx[0]])< 0.02){
	      eletighthigh+=weight; h_pt1_tight->Fill(Lepton_pt[0],weight); h_eta1_tight->Fill(fabs(Lepton_eta[0]),weight); h_pt1_tight_high->Fill(Lepton_pt[0],weight); h_eta1_tight_high->Fill(fabs(Lepton_eta[0]),weight);}
	  } 
	}
      }

      if (channel=="mu"){
	if (abs(Lepton_pdgId[0])!=13)continue;
	if (Lepton_pt[0]<10 || fabs(Lepton_eta[0])>=2.4)continue;
	if (Lepton_pt[0] <= 20.){
	  if (HLT_Mu8_TrkIsoVVL < 0.5)continue;
	  else {
	    if(isData==false)weight*=0.002903;
	    mulooselow+=weight; h_pt1_loose->Fill(Lepton_pt[0],weight); h_eta1_loose->Fill(fabs(Lepton_eta[0]),weight); h_pt1_loose_low->Fill(Lepton_pt[0],weight); h_eta1_loose_low->Fill(fabs(Lepton_eta[0]),weight);
	    if(Lepton_isTightMuon_cut_Tight_HWWW[0]>0.5) {mutightlow+=weight; h_pt1_tight->Fill(Lepton_pt[0],weight); h_eta1_tight->Fill(fabs(Lepton_eta[0]),weight); h_pt1_tight_low->Fill(Lepton_pt[0],weight); h_eta1_tight_low->Fill(fabs(Lepton_eta[0]),weight);}
	  }
	}
	if (Lepton_pt[0] > 20.){
	  if (HLT_Mu17_TrkIsoVVL < 0.5)continue;
	  else{
	    if(isData==false)weight*=0.065944;
	    muloosehigh+=weight; h_pt1_loose->Fill(Lepton_pt[0],weight); h_eta1_loose->Fill(fabs(Lepton_eta[0]),weight); h_pt1_loose_high->Fill(Lepton_pt[0],weight); h_eta1_loose_high->Fill(fabs(Lepton_eta[0]),weight);
	    if(Lepton_isTightMuon_cut_Tight_HWWW[0]>0.5) {mutighthigh+=weight; h_pt1_tight->Fill(Lepton_pt[0],weight); h_eta1_tight->Fill(fabs(Lepton_eta[0]),weight); h_pt1_tight_high->Fill(Lepton_pt[0],weight); h_eta1_tight_high->Fill(fabs(Lepton_eta[0]),weight);}
	  } 
	}
      }
    }
    //--------------------With jet cuts------------------------------------------

    int passjets =0;
    for (int jet=0; jet<nCleanJet; jet++){
      if(CleanJet_pt[jet]>=25. && sqrt(deltaPhi(CleanJet_phi[jet],Lepton_phi[0])*deltaPhi(CleanJet_phi[jet],Lepton_phi[0])+(CleanJet_eta[jet]-Lepton_eta[0])*(CleanJet_eta[jet]-Lepton_eta[0]))>=1.) passjets=1;
    }
    if (passjets==0)continue;

    if (channel=="ele"){
      if (abs(Lepton_pdgId[0])!=11) continue;
      if (Lepton_pt[0]<13 || fabs(Lepton_eta[0])>=2.5)continue;
      if (Lepton_pt[0] <= 25.){
	if (HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 < 0.5)continue;
	else {
	  if(isData==false)weight*=0.027699;
	  elelooselowjet+=weight; h_pt1_loose_jet->Fill(Lepton_pt[0],weight); h_eta1_loose_jet->Fill(fabs(Lepton_eta[0]),weight); h_pt1_loose_low_jet->Fill(Lepton_pt[0],weight); h_eta1_loose_low_jet->Fill(fabs(Lepton_eta[0]),weight);
	  if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[0]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[0]])< 0.1 && ((Lepton_pt[0]>20 && fabs(Electron_dxy[Lepton_electronIdx[0]])< 0.02)||(Lepton_pt[0]<=20 && fabs(Electron_dxy[Lepton_electronIdx[0]])< 0.01))){
	    eletightlowjet+=weight; h_pt1_tight_jet->Fill(Lepton_pt[0],weight); h_eta1_tight_jet->Fill(fabs(Lepton_eta[0]),weight); h_pt1_tight_low_jet->Fill(Lepton_pt[0],weight); h_eta1_tight_low_jet->Fill(fabs(Lepton_eta[0]),weight);}
	}
      }
      if (Lepton_pt[0] > 25.){
	if (HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 < 0.5)continue;
	else{
	    if(isData==false)weight*=0.043469;
	  eleloosehighjet+=weight; h_pt1_loose_jet->Fill(Lepton_pt[0],weight); h_eta1_loose_jet->Fill(fabs(Lepton_eta[0]),weight); h_pt1_loose_high_jet->Fill(Lepton_pt[0],weight); h_eta1_loose_high_jet->Fill(fabs(Lepton_eta[0]),weight);
	  if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[0]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[0]])< 0.1 && fabs(Electron_dxy[Lepton_electronIdx[0]])< 0.02){
	    eletighthighjet+=weight; h_pt1_tight_jet->Fill(Lepton_pt[0],weight); h_eta1_tight_jet->Fill(fabs(Lepton_eta[0]),weight); h_pt1_tight_high_jet->Fill(Lepton_pt[0],weight); h_eta1_tight_high_jet->Fill(fabs(Lepton_eta[0]),weight);}
	} 
      }
    }

    if (channel=="mu"){
      if (abs(Lepton_pdgId[0])!=13) continue;
      if (Lepton_pt[0]<10 || fabs(Lepton_eta[0])>=2.4)continue;
      if (Lepton_pt[0] <= 20.){
	if (HLT_Mu8_TrkIsoVVL < 0.5)continue;
	else {
	    if(isData==false)weight*=0.002903;
	  mulooselowjet+=weight; h_pt1_loose_jet->Fill(Lepton_pt[0],weight); h_eta1_loose_jet->Fill(fabs(Lepton_eta[0]),weight); h_pt1_loose_low_jet->Fill(Lepton_pt[0],weight); h_eta1_loose_low_jet->Fill(fabs(Lepton_eta[0]),weight);
	  if(Lepton_isTightMuon_cut_Tight_HWWW[0]>0.5){
	    mutightlowjet+=weight; h_pt1_tight_jet->Fill(Lepton_pt[0],weight); h_eta1_tight_jet->Fill(fabs(Lepton_eta[0]),weight); h_pt1_tight_low_jet->Fill(Lepton_pt[0],weight); h_eta1_tight_low_jet->Fill(fabs(Lepton_eta[0]),weight);}
	}
      }
      if (Lepton_pt[0] > 20.){
	if (HLT_Mu17_TrkIsoVVL < 0.5)continue;
	else{
	    if(isData==false)weight*=0.065944;
	  muloosehighjet+=weight; h_pt1_loose_jet->Fill(Lepton_pt[0],weight); h_eta1_loose_jet->Fill(fabs(Lepton_eta[0]),weight); h_pt1_loose_high_jet->Fill(Lepton_pt[0],weight); h_eta1_loose_high_jet->Fill(fabs(Lepton_eta[0]),weight);
	  if(Lepton_isTightMuon_cut_Tight_HWWW[0]>0.5){
	    mutighthighjet+=weight; h_pt1_tight_jet->Fill(Lepton_pt[0],weight); h_eta1_tight_jet->Fill(fabs(Lepton_eta[0]),weight); h_pt1_tight_high_jet->Fill(Lepton_pt[0],weight); h_eta1_tight_high_jet->Fill(fabs(Lepton_eta[0]),weight);}
	} 
      }
    }

  }

  //Write histograms in root output

  if(nojet==true){

  TDirectory *without = root_output->mkdir("beforejetcut");
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

  }

  TDirectory *with = root_output->mkdir("afterjetcut");
  with->cd();
  
  h_pt1_tight_jet  ->Write();
  h_eta1_tight_jet ->Write();
  h_pt1_loose_jet  ->Write();
  h_eta1_loose_jet ->Write();

  h_pt1_tight_low_jet->Write();
  h_eta1_tight_low_jet->Write();
  h_pt1_loose_low_jet ->Write();
  h_eta1_loose_low_jet->Write();

  h_pt1_tight_high_jet->Write();
  h_eta1_tight_high_jet->Write();
  h_pt1_loose_high_jet ->Write();
  h_eta1_loose_high_jet->Write();

  root_output->Close();
 
  //Print number of events

  if(nojet==true && channel=="mu"){
    printf(" Without jet cut \n");
    printf("loose muons, low pt: %f \n",  mulooselow);
    printf("loose muons, high pt: %f \n", muloosehigh);
    printf("tight muons, low pt: %f \n",  mutightlow);
    printf("tight muons, high pt: %f \n", mutighthigh);
  }
  if(channel=="mu"){
    printf(" With jet cut \n");
    printf("loose muons, low pt: %f \n",  mulooselowjet);
    printf("loose muons, high pt: %f \n", muloosehighjet);
    printf("tight muons, low pt: %f \n",  mutightlowjet);
    printf("tight muons, high pt: %f \n", mutighthighjet);
  }  
  if(nojet==true && channel=="ele"){
    printf(" Without jet cut \n");
    printf("loose electrons, low pt: %f \n",  elelooselow);
    printf("loose electrons, high pt: %f \n", eleloosehigh);
    printf("tight electrons, low pt: %f \n",  eletightlow);
    printf("tight electrons, high pt: %f \n", eletighthigh);
  }  
  if(channel=="ele"){
    printf(" With jet cut \n");
    printf("loose electrons, low pt: %f \n",  elelooselowjet);
    printf("loose electrons, high pt: %f \n", eleloosehighjet);
    printf("tight electrons, low pt: %f \n",  eletightlowjet);
    printf("tight electrons, high pt: %f \n", eletighthighjet);
  }

  cout << endl;
  cout << "-------- Done ---------";
  cout << endl;


}
