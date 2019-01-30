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

void Fake_rates(TString sample,  TString channel ) {

  //if (argc<3) {
  //  printf('Ejemplo: root -b -q "Fake_rates(sample , mu)" ');
  //  return -1;
  // }

  //Options
  //--------------------------------------------------------------------------------------------------------------------------------------

  if (channel != "ele" && channel != "mu") {printf("channel must be ele or mu \n");return -1;}

  // Import the nanoLatino Tree
  //--------------------------------------------------------------------------------------------------------------------------------------
  TChain* tree = new TChain("Events");
  //DATA
  TString myFolderData = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2017_nAOD_v1_Full2017v2/DATAl1loose2017v2__DATACorr2017__fakeSel/"; 
  //TString myFolderData = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2017_nAOD_v1_Full2017v2/DATAl1loose2017v2__DATACorr2017/";   
  //MC
  //TString myFolder = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017v2__MCCorr2017test__fakeSelMC/";
  TString myFolder = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017v2__MCCorr2017/";

  TString outputdir ="/afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code/outputsFR_24jan_jetbins/";

  TString file = "";
  bool isData = false;  bool isDY =false;  bool isWj =false; bool isTT =false;
  double weight = 1;
  if(sample.Contains("Run")){ file = myFolderData + sample ; isData=true; }
  else{ file = myFolder +sample ; if(sample.Contains("DY"))isDY=true; if(sample.Contains("WJets"))isWj=true; if(sample.Contains("TT"))isTT=true;}

  TFile* root_output = new TFile(outputdir +"output_" +channel+"_"+ sample, "recreate");

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

  Float_t eletight[5] = {0};
  Float_t eleloose[5] = {0};
  Float_t mutight[5] = {0};
  Float_t muloose[5] = {0};
  cout<<"Begin..."<<endl;

  // Create the output histograms
  //--------------------------------------------------------------------------------------------------------------------------------------
  TH1F* h_pt1_tight[5];
  TH1F* h_eta1_tight[5];
  TH1F* h_pt1_loose[5];
  TH1F* h_eta1_loose[5];
  for(int jet=0;jet<5;jet++){
    h_pt1_tight[jet]   = new TH1F(Form("h_pt1_tight_%d",jet),Form("h_pt1_tight_%d",jet),8,10,50);
    h_eta1_tight[jet]  = new TH1F(Form("h_eta1_tight_%d",jet),Form("h_eta1_tight_%d",jet),5,0,2.5);
    h_pt1_loose[jet]   = new TH1F(Form("h_pt1_loose_%d",jet),Form("h_pt1_loose_%d",jet),8,10,50);
    h_eta1_loose[jet]  = new TH1F(Form("h_eta1_loose_%d",jet),Form("h_eta1_loose_%d",jet),5,0,2.5);
  }

  // Loop over the tree events
  //--------------------------------------------------------------------------------------------------------------------------------------
  for (int j = 0; j < tree->GetEntries(); ++j){
    tree->GetEntry(j);
    int nentries = tree->GetEntriesFast();
    if(fmod(j,100000)==0) Printf(" ..... event %d of %d", int(j), int(nentries));

    //------------------------------ Preselection --------------------------------------
    if (nLepton!=1){continue;}
    if (MET_pt>20){continue;}
    if (mtw1>20){continue;}
     
    //-------------------- jet cuts------------------------------------------
    for(int jetcut=0;jetcut<5;jetcut++){
      if(isData==false) weight=baseW*Generator_weight*puWeight;
      int passjets =0;
      for (int jet=0; jet<nCleanJet; jet++){
	if(CleanJet_pt[jet]>=20.+5*jetcut && sqrt(deltaPhi(CleanJet_phi[jet],Lepton_phi[0])*deltaPhi(CleanJet_phi[jet],Lepton_phi[0])+(CleanJet_eta[jet]-Lepton_eta[0])*(CleanJet_eta[jet]-Lepton_eta[0]))>=1.) passjets=1;
      }
      if (passjets==0)continue;

      if (channel=="ele"){
	if (abs(Lepton_pdgId[0])!=11) continue;
	if (Lepton_pt[0]<13 || fabs(Lepton_eta[0])>=2.5)continue;
	if (Lepton_pt[0] <= 25.){
	  if (HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 < 0.5)continue;
	  else {
	    if(isData==false)weight*=0.027699;
	    eleloose[jetcut]+=weight; h_pt1_loose[jetcut]->Fill(Lepton_pt[0],weight); h_eta1_loose[jetcut]->Fill(fabs(Lepton_eta[0]),weight);
	    if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[0]]>0.5){// && fabs(Electron_dz[Lepton_electronIdx[0]])< 0.1 && ((Lepton_pt[0]>20 && fabs(Electron_dxy[Lepton_electronIdx[0]])< 0.02)||(Lepton_pt[0]<=20 && fabs(Electron_dxy[Lepton_electronIdx[0]])< 0.01))){
	      eletight[jetcut]+=weight; h_pt1_tight[jetcut]->Fill(Lepton_pt[0],weight); h_eta1_tight[jetcut]->Fill(fabs(Lepton_eta[0]),weight);}
	  }
	}
	if (Lepton_pt[0] > 25.){
	  if (HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 < 0.5)continue;
	  else{
	    if(isData==false)weight*=0.043469;
	    eleloose[jetcut]+=weight; h_pt1_loose[jetcut]->Fill(Lepton_pt[0],weight); h_eta1_loose[jetcut]->Fill(fabs(Lepton_eta[0]),weight); 
	    if(Electron_mvaFall17Iso_WP90[Lepton_electronIdx[0]]>0.5){// && fabs(Electron_dz[Lepton_electronIdx[0]])< 0.1 && fabs(Electron_dxy[Lepton_electronIdx[0]])< 0.02){
	      eletight[jetcut]+=weight; h_pt1_tight[jetcut]->Fill(Lepton_pt[0],weight); h_eta1_tight[jetcut]->Fill(fabs(Lepton_eta[0]),weight);}
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
	    muloose[jetcut]+=weight; h_pt1_loose[jetcut]->Fill(Lepton_pt[0],weight); h_eta1_loose[jetcut]->Fill(fabs(Lepton_eta[0]),weight);
	    if(Lepton_isTightMuon_cut_Tight_HWWW[0]>0.5){
	      mutight[jetcut]+=weight; h_pt1_tight[jetcut]->Fill(Lepton_pt[0],weight); h_eta1_tight[jetcut]->Fill(fabs(Lepton_eta[0]),weight);}
	  }
	}
	if (Lepton_pt[0] > 20.){
	  if (HLT_Mu17_TrkIsoVVL < 0.5)continue;
	  else{
	    if(isData==false)weight*=0.065944;
	    muloose[jetcut]+=weight; h_pt1_loose[jetcut]->Fill(Lepton_pt[0],weight); h_eta1_loose[jetcut]->Fill(fabs(Lepton_eta[0]),weight); 
	    if(Lepton_isTightMuon_cut_Tight_HWWW[0]>0.5){
	      mutight[jetcut]+=weight; h_pt1_tight[jetcut]->Fill(Lepton_pt[0],weight); h_eta1_tight[jetcut]->Fill(fabs(Lepton_eta[0]),weight);}
	  } 
	}
      }

    }//Close loop in jetcut
  }//Close loop in entries

  //Write histograms in root output
  TDirectory *dir[5];
  for(int jetcut=0;jetcut<5;jetcut++){
    dir[jetcut] = root_output->mkdir(Form("jetcut_%d",jetcut));
    dir[jetcut]->cd();
    h_pt1_tight[jetcut] ->Write();
    h_eta1_tight[jetcut]->Write();
    h_pt1_loose[jetcut] ->Write();
    h_eta1_loose[jetcut]->Write();
  }
  root_output->Close();
 
  //Print number of events
  for(int jetcut=0;jetcut<5;jetcut++){
    cout<< "-----------Jet pt >"<<jetcut+20<<"-------"<<endl;
    if(channel=="mu"){
      printf("loose muons: %f \n", muloose[jetcut]);
      printf("tight muons: %f \n", mutight[jetcut]);
    }  
    if(channel=="ele"){
      printf("loose electrons: %f \n",  eleloose[jetcut]);
      printf("tight electrons: %f \n",  eletight[jetcut]);
    }
  }
  cout << endl;
  cout << "-------- Done ---------";
  cout << endl;

}
