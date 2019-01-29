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

  TString outputdir ="/afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code/outputsFR_Z_singletrigs_Jan22/";

  TString file = "";
  TString datastream = "";
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

  Bool_t HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;
  tree->SetBranchAddress("HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL",&HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL);
  Bool_t HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
  tree->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL",&HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL);
  Bool_t HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ;
  tree->SetBranchAddress("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ",&HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ);
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

  Float_t leptight_fakeele = 0;
  Float_t leploose_fakeele = 0;
  Float_t leptight_mutrig_fakeele = 0;
  Float_t leploose_mutrig_fakeele = 0;
  Float_t leptight_eletrig_fakeele = 0;
  Float_t leploose_eletrig_fakeele = 0;
  Float_t leptight_fakemu = 0;
  Float_t leploose_fakemu = 0;
  Float_t leptight_mutrig_fakemu = 0;
  Float_t leploose_mutrig_fakemu = 0;
  Float_t leptight_eletrig_fakemu = 0;
  Float_t leploose_eletrig_fakemu = 0;
  cout<<"Begin..."<<endl;

  // Create the output histograms
  //--------------------------------------------------------------------------------------------------------------------------------------
 
  TH1F* h_pt1_tight_fakeele   = new TH1F("h_pt1_tight_fakeele","h_pt1_tight_fakeele",3,0,50);
  TH1F* h_eta1_tight_fakeele  = new TH1F("h_eta1_tight_fakeele","h_eta1_tight_fakeele",3,0,2.5);
  TH1F* h_pt1_loose_fakeele   = new TH1F("h_pt1_loose_fakeele","h_pt1_loose_fakeele",3,0,50);
  TH1F* h_eta1_loose_fakeele  = new TH1F("h_eta1_loose_fakeele","h_eta1_loose_fakeele",3,0,2.5);
  TH1F* h_pt1_tight_mutrig_fakeele   = new TH1F("h_pt1_tight_mutrig_fakeele","h_pt1_tight_mutrig_fakeele",3,0,50);
  TH1F* h_eta1_tight_mutrig_fakeele  = new TH1F("h_eta1_tight_mutrig_fakeele","h_eta1_tight_mutrig_fakeele",3,0,2.5);
  TH1F* h_pt1_loose_mutrig_fakeele   = new TH1F("h_pt1_loose_mutrig_fakeele","h_pt1_loose_mutrig_fakeele",3,0,50);
  TH1F* h_eta1_loose_mutrig_fakeele  = new TH1F("h_eta1_loose_mutrig_fakeele","h_eta1_loose_mutrig_fakeele",3,0,2.5);
  TH1F* h_pt1_tight_eletrig_fakeele   = new TH1F("h_pt1_tight_eletrig_fakeele","h_pt1_tight_eletrig_fakeele",3,0,50);
  TH1F* h_eta1_tight_eletrig_fakeele  = new TH1F("h_eta1_tight_eletrig_fakeele","h_eta1_tight_eletrig_fakeele",3,0,2.5);
  TH1F* h_pt1_loose_eletrig_fakeele   = new TH1F("h_pt1_loose_eletrig_fakeele","h_pt1_loose_eletrig_fakeele",3,0,50);
  TH1F* h_eta1_loose_eletrig_fakeele  = new TH1F("h_eta1_loose_eletrig_fakeele","h_eta1_loose_eletrig_fakeele",3,0,2.5);
  TH1F* h_pt1_tight_fakemu   = new TH1F("h_pt1_tight_fakemu","h_pt1_tight_fakemu",3,0,50);
  TH1F* h_eta1_tight_fakemu  = new TH1F("h_eta1_tight_fakemu","h_eta1_tight_fakemu",3,0,2.5);
  TH1F* h_pt1_loose_fakemu   = new TH1F("h_pt1_loose_fakemu","h_pt1_loose_fakemu",3,0,50);
  TH1F* h_eta1_loose_fakemu  = new TH1F("h_eta1_loose_fakemu","h_eta1_loose_fakemu",3,0,2.5);
  TH1F* h_pt1_tight_mutrig_fakemu   = new TH1F("h_pt1_tight_mutrig_fakemu","h_pt1_tight_mutrig_fakemu",3,0,50);
  TH1F* h_eta1_tight_mutrig_fakemu  = new TH1F("h_eta1_tight_mutrig_fakemu","h_eta1_tight_mutrig_fakemu",3,0,2.5);
  TH1F* h_pt1_loose_mutrig_fakemu   = new TH1F("h_pt1_loose_mutrig_fakemu","h_pt1_loose_mutrig_fakemu",3,0,50);
  TH1F* h_eta1_loose_mutrig_fakemu  = new TH1F("h_eta1_loose_mutrig_fakemu","h_eta1_loose_mutrig_fakemu",3,0,2.5);
  TH1F* h_pt1_tight_eletrig_fakemu   = new TH1F("h_pt1_tight_eletrig_fakemu","h_pt1_tight_eletrig_fakemu",3,0,50);
  TH1F* h_eta1_tight_eletrig_fakemu  = new TH1F("h_eta1_tight_eletrig_fakemu","h_eta1_tight_eletrig_fakemu",3,0,2.5);
  TH1F* h_pt1_loose_eletrig_fakemu   = new TH1F("h_pt1_loose_eletrig_fakemu","h_pt1_loose_eletrig_fakemu",3,0,50);
  TH1F* h_eta1_loose_eletrig_fakemu  = new TH1F("h_eta1_loose_eletrig_fakemu","h_eta1_loose_eletrig_fakemu",3,0,2.5);
  TH1F* h_mll_Zee_fakeele_loose  = new TH1F("h_mll_Zee_fakeele_loose","h_mll_Zee_fakeele_loose",8,70,110);
  TH1F* h_mll_Zee_fakemu_loose   = new TH1F("h_mll_Zee_fakemu_loose","h_mll_Zee_fakemu_loose",8,70,110);
  TH1F* h_mll_Zmm_fakeele_loose  = new TH1F("h_mll_Zmm_fakeele_loose","h_mll_Zmm_fakeele_loose",8,70,110);
  TH1F* h_mll_Zmm_fakemu_loose   = new TH1F("h_mll_Zmm_fakemu_loose","h_mll_Zmm_fakemu_loose",8,70,110);
  TH1F* h_mll_Zee_fakeele_tight  = new TH1F("h_mll_Zee_fakeele_tight","h_mll_Zee_fakeele_tight",8,70,110);
  TH1F* h_mll_Zee_fakemu_tight   = new TH1F("h_mll_Zee_fakemu_tight","h_mll_Zee_fakemu_tight",8,70,110);
  TH1F* h_mll_Zmm_fakeele_tight  = new TH1F("h_mll_Zmm_fakeele_tight","h_mll_Zmm_fakeele_tight",8,70,110);
  TH1F* h_mll_Zmm_fakemu_tight   = new TH1F("h_mll_Zmm_fakemu_tight","h_mll_Zmm_fakemu_tight",8,70,110);
  const Double_t MUON_MASS     = 0.106;     // [GeV]
  const Double_t ELECTRON_MASS = 0.000511; // [GeV]
  TLorentzVector lep1,lep2,lep3,l1l2,l1l3,ll;
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
    //cout<<"start preselection"<<endl;
    if (nLepton!=3){continue;}
    //if (nCleanJet>0) {if (CleanJet_pt[0]>40){continue;}}
    if (MET_pt>20){continue;}

    if (isData==false){weight=baseW*Generator_weight*puWeight*41.527;}
    else weight=1;
    //cout<<"after weights declaration"<<endl;
    int fakelep;
    TString channel="";

    if(Lepton_pdgId[0]==-1*Lepton_pdgId[1] && Lepton_pdgId[0]==-1*Lepton_pdgId[2] ){
      if ((fabs(l1l2.M()-91.18) <= fabs(l1l3.M()-91.18))&& fabs(l1l2.M()-91.18)<=15){fakelep=2; ll=l1l2;}
      else if((fabs(l1l3.M()-91.18) <= fabs(l1l2.M()-91.18))&& fabs(l1l3.M()-91.18)<=15){fakelep=1; ll=l1l3;}
      else {continue;}
    }
    else if(Lepton_pdgId[0]==-1*Lepton_pdgId[1]){
      if (fabs(l1l2.M()-91.18)<=15){fakelep=2; ll=l1l2;}
    }
    else if(Lepton_pdgId[0]==-1*Lepton_pdgId[2]){
      if (fabs(l1l3.M()-91.18)<=15){fakelep=1; ll=l1l3;}
    }
    else {continue;}
    //cout<<"after filling mZ histograms"<<endl;
    if  (Lepton_electronIdx[fakelep] >= 0) channel="ele";
    else if (Lepton_muonIdx[fakelep] >= 0) channel="mu"; 
    if (Lepton_pt[fakelep]<10||fabs(Lepton_eta[fakelep])>2.5)continue;

    //DATA
    if (isData==true){
      if (datastream=="electronstream" && (HLT_Ele35_WPTight_Gsf < 0.5 || Lepton_pt[0]<36 || fabs(Lepton_eta[0])>=2.5 || Electron_mvaFall17Iso_WP90[Lepton_electronIdx[0]]<0.5 || fabs(Electron_dz[Lepton_electronIdx[0]])> 0.1 || fabs(Electron_dxy[Lepton_electronIdx[0]])> 0.02 )  )continue;
      //if (datastream=="electronstream" && (HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL < 0.5 || Lepton_pt[0]<25 || fabs(Lepton_eta[0])>=2.5 || Electron_mvaFall17Iso_WP90[Lepton_electronIdx[0]]<0.5 || fabs(Electron_dz[Lepton_electronIdx[0]])> 0.1 || fabs(Electron_dxy[Lepton_electronIdx[0]])> 0.02 )  )continue;
      else if (datastream=="muonstream" && ( HLT_IsoMu27 < 0.5 || Lepton_pt[0]<28 || fabs(Lepton_eta[0])>=2.4 || Lepton_isTightMuon_cut_Tight_HWWW[0]<0.5) )continue;
      //else if (datastream=="muonstream" && ( (HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL < 0.5 &&HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ < 0.5) || Lepton_pt[0]<19 || fabs(Lepton_eta[0])>=2.4 || Lepton_isTightMuon_cut_Tight_HWWW[0]<0.5) )continue;
      if (channel=="ele"){
	leploose_fakeele+=weight; h_pt1_loose_fakeele->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_fakeele->Fill(fabs(Lepton_eta[fakelep]),weight);
	if (datastream=="electronstream")h_mll_Zee_fakeele_loose->Fill(ll.M());
	else if(datastream=="muonstream")h_mll_Zmm_fakeele_loose->Fill(ll.M());
	if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[fakelep]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[fakelep]])< 0.1 && ((Lepton_pt[fakelep]>20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.02)||(Lepton_pt[fakelep]<=20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.01))){
	  leptight_fakeele+=weight; h_pt1_tight_fakeele->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_fakeele->Fill(fabs(Lepton_eta[fakelep]),weight);
	  if (datastream=="electronstream")h_mll_Zee_fakeele_tight->Fill(ll.M());
	  else if(datastream=="muonstream")h_mll_Zmm_fakeele_tight->Fill(ll.M());
	}
      }
      if (channel=="mu"){
	leploose_fakemu+=weight; h_pt1_loose_fakemu->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_fakemu->Fill(fabs(Lepton_eta[fakelep]),weight);
	if (datastream=="electronstream")h_mll_Zee_fakemu_loose->Fill(ll.M());
	else if(datastream=="muonstream")h_mll_Zmm_fakemu_loose->Fill(ll.M());
	if(Lepton_isTightMuon_cut_Tight_HWWW[fakelep]>0.5) {
	  leptight_fakemu+=weight; h_pt1_tight_fakemu->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_fakemu->Fill(fabs(Lepton_eta[fakelep]),weight);
	  if (datastream=="electronstream")h_mll_Zee_fakemu_tight->Fill(ll.M());
	  else if(datastream=="muonstream")h_mll_Zmm_fakemu_tight->Fill(ll.M());
	}
      }
    }

    //MC
    else{
      if( HLT_Ele35_WPTight_Gsf > 0.5 && Lepton_pt[0]>36 && fabs(Lepton_eta[0])<=2.5 &&  Electron_mvaFall17Iso_WP90[Lepton_electronIdx[0]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[0]])< 0.1 && fabs(Electron_dxy[Lepton_electronIdx[0]])< 0.02  ){//MC for comparing with the electron data
	//if(HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL  > 0.5 && Lepton_pt[0]>25 && fabs(Lepton_eta[0])<=2.5 &&  Electron_mvaFall17Iso_WP90[Lepton_electronIdx[0]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[0]])< 0.1 && fabs(Electron_dxy[Lepton_electronIdx[0]])< 0.02  ){//MC for comparing with the electron data
	if (channel=="ele"){
	  leploose_eletrig_fakeele+=weight; h_pt1_loose_eletrig_fakeele->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_eletrig_fakeele->Fill(fabs(Lepton_eta[fakelep]),weight);h_mll_Zee_fakeele_loose->Fill(ll.M());
	  if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[fakelep]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[fakelep]])< 0.1 && ((Lepton_pt[fakelep]>20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.02)||(Lepton_pt[fakelep]<=20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.01))){
	    leptight_eletrig_fakeele+=weight; h_pt1_tight_eletrig_fakeele->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_eletrig_fakeele->Fill(fabs(Lepton_eta[fakelep]),weight);h_mll_Zee_fakeele_tight->Fill(ll.M());}
	}
	if (channel=="mu"){
	  leploose_eletrig_fakemu+=weight; h_pt1_loose_eletrig_fakemu->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_eletrig_fakemu->Fill(fabs(Lepton_eta[fakelep]),weight);h_mll_Zee_fakemu_loose->Fill(ll.M());
	  if(Lepton_isTightMuon_cut_Tight_HWWW[fakelep]>0.5) {
	    leptight_eletrig_fakemu+=weight; h_pt1_tight_eletrig_fakemu->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_eletrig_fakemu->Fill(fabs(Lepton_eta[fakelep]),weight);h_mll_Zee_fakemu_tight->Fill(ll.M());}
	}
      }
      if( HLT_IsoMu27 > 0.5 && Lepton_pt[0]>28 && fabs(Lepton_eta[0])<=2.4 && Lepton_isTightMuon_cut_Tight_HWWW[0]>0.5){//MC for the muon data
	//if( (HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL || HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ) > 0.5 && Lepton_pt[0]>19 && fabs(Lepton_eta[0])<=2.4 && Lepton_isTightMuon_cut_Tight_HWWW[0]>0.5){//MC for the muon data
	if (channel=="ele"){
	  leploose_mutrig_fakeele+=weight; h_pt1_loose_mutrig_fakeele->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_mutrig_fakeele->Fill(fabs(Lepton_eta[fakelep]),weight);h_mll_Zmm_fakeele_loose->Fill(ll.M());
	  if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[fakelep]]>0.5 && fabs(Electron_dz[Lepton_electronIdx[fakelep]])< 0.1 && ((Lepton_pt[fakelep]>20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.02)||(Lepton_pt[fakelep]<=20 && fabs(Electron_dxy[Lepton_electronIdx[fakelep]])< 0.01))){
	    leptight_mutrig_fakeele+=weight; h_pt1_tight_mutrig_fakeele->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_mutrig_fakeele->Fill(fabs(Lepton_eta[fakelep]),weight);h_mll_Zmm_fakeele_tight->Fill(ll.M());}
	}
	if (channel=="mu"){
	  leploose_mutrig_fakemu+=weight; h_pt1_loose_mutrig_fakemu->Fill(Lepton_pt[fakelep],weight); h_eta1_loose_mutrig_fakemu->Fill(fabs(Lepton_eta[fakelep]),weight);h_mll_Zmm_fakemu_loose->Fill(ll.M());
	  if(Lepton_isTightMuon_cut_Tight_HWWW[fakelep]>0.5) {
	    leptight_mutrig_fakemu+=weight; h_pt1_tight_mutrig_fakemu->Fill(Lepton_pt[fakelep],weight); h_eta1_tight_mutrig_fakemu->Fill(fabs(Lepton_eta[fakelep]),weight);h_mll_Zmm_fakemu_tight->Fill(ll.M());}
	}
      }
      //cout<<"after filling tight/loose histograms"<<endl;
    }//close if MC
  }//close event loop
  //cout<<"before writing"<<endl;
  //Write histograms in root output
  if(isData==1){
    h_pt1_tight_fakemu ->Write();  
    h_eta1_tight_fakemu->Write();
    h_pt1_loose_fakemu ->Write();
    h_eta1_loose_fakemu->Write();
    h_pt1_tight_fakeele ->Write();  
    h_eta1_tight_fakeele->Write();
    h_pt1_loose_fakeele ->Write();
    h_eta1_loose_fakeele->Write();
  }
  else{
    h_pt1_tight_eletrig_fakemu ->Write();  
    h_eta1_tight_eletrig_fakemu->Write();
    h_pt1_loose_eletrig_fakemu ->Write();
    h_eta1_loose_eletrig_fakemu->Write();
    h_pt1_tight_mutrig_fakemu ->Write();  
    h_eta1_tight_mutrig_fakemu->Write();
    h_pt1_loose_mutrig_fakemu ->Write();
    h_eta1_loose_mutrig_fakemu->Write();
    h_pt1_tight_eletrig_fakeele ->Write();  
    h_eta1_tight_eletrig_fakeele->Write();
    h_pt1_loose_eletrig_fakeele ->Write();
    h_eta1_loose_eletrig_fakeele->Write();
    h_pt1_tight_mutrig_fakeele ->Write();  
    h_eta1_tight_mutrig_fakeele->Write();
    h_pt1_loose_mutrig_fakeele ->Write();
    h_eta1_loose_mutrig_fakeele->Write();
  }
  h_mll_Zee_fakeele_loose->Write();
  h_mll_Zee_fakeele_tight->Write();
  h_mll_Zee_fakemu_loose->Write();
  h_mll_Zee_fakemu_tight->Write();
  h_mll_Zmm_fakeele_loose->Write();
  h_mll_Zmm_fakeele_tight->Write();
  h_mll_Zmm_fakemu_loose->Write();
  h_mll_Zmm_fakemu_tight->Write();
  root_output->Close();
 
  //Print number of events
  if(isData==1){
    printf("loose electrons: %f \n", leploose_fakeele);
    printf("tight electrons: %f \n", leptight_fakeele);
    printf("loose muons: %f \n", leploose_fakemu);
    printf("tight muons: %f \n", leptight_fakemu);
  }
  else{
    printf("loose electrons, mu trigger: %f \n", leploose_mutrig_fakeele);
    printf("tight electrons, mu trigger: %f \n", leptight_mutrig_fakeele);
    printf("loose electrons, ele trigger: %f \n", leploose_eletrig_fakeele);
    printf("tight electrons, ele trigger: %f \n", leptight_eletrig_fakeele);
    printf("loose muons, mu trigger: %f \n", leploose_mutrig_fakemu);
    printf("tight muons, mu trigger: %f \n", leptight_mutrig_fakemu);
    printf("loose muons, ele trigger: %f \n", leploose_eletrig_fakemu);
    printf("tight muons, ele trigger: %f \n", leptight_eletrig_fakemu);
  }
  cout << endl;
  cout << "-------- Done ---------";
  cout << endl;

}
