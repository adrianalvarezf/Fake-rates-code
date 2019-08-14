#include <iostream>
#include <fstream>
#include <stdio.h>
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

void Prompt_rates(TString sample,  TString channel, TString year) {

  //Options
  //--------------------------------------------------------------------------------------------------------------------------------------
  if (channel != "ele" && channel != "mu") {printf("ERROR: Channel must be ele or mu \n");return -1;}
  if (year!="2016"&&year!="2017"&&year!="2018"){cout<<"ERROR: Year is not valid!"<<endl;return -1;}

  // Import the nanoLatino Tree
  //--------------------------------------------------------------------------------------------------------------------------------------
  TChain* tree = new TChain("Events");
  ////////////////////////////////////////////MC//////////////////////////////////
  TString myFolderMC ="";
  if(year=="2018") myFolderMC = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Autumn18_102X_nAODv4_GTv16_Full2018v4/MCl1loose2018__MCCorr2018/"; //2018 v4   
  if(year=="2017") myFolderMC = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_102X_nAODv4_Full2017v5/MCl1loose2017v5__MCCorr2017v5/";  //2017 v5
  if(year=="2016") myFolderMC = "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Summer16_102X_nAODv4_Full2016v5/MCl1loose2016v5__MCCorr2016v5/"; //2016 v5
  //////////////////OUTPUT///////////////////

  TString dirname = "PR_"+year+"_12aug_v5_tight80X";
  TString subdirname =dirname; subdirname.ReplaceAll("PR","outputsPR");
  TString outputdir ="/afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code/"+dirname+"/"+subdirname+"/";
  system("mkdir -p "+outputdir);

  TString file = "";
  bool isDY = false;  bool isMC =false;
  double weight = 1;
  if(sample.Contains("DY")){ file = myFolderMC +sample ; isMC=true;}
  else{cout<<"Wrong sample for PR, not DY"<<endl;return 0;}
 
  TFile* root_output = new TFile(outputdir +"output_" +channel+"_"+ sample, "recreate");
  
  //////////////Working Points//////////////////////////////
  TString ele2016wp= "cut_WP_Tight80X";//"mva_90p_Iso2016_SS";
  TString ele2017wp= "mvaFall17V1Iso_WP90";
  TString ele2018wp= "mvaFall17V1Iso_WP90";

  TString mu2016wp= "cut_Tight80x";
  TString mu2017wp= "cut_Tight_HWWW";
  TString mu2018wp= "cut_Tight_HWWW";

  TString elewp="Lepton_isTightElectron_";  TString muwp="Lepton_isTightMuon_";

  if(year=="2016"){elewp+=ele2016wp;muwp+=mu2016wp;}
  if(year=="2017"){elewp+=ele2017wp;muwp+=mu2017wp;}
  if(year=="2018"){elewp+=ele2018wp;muwp+=mu2018wp;}

  ///////////////////////////////////
  cout<<file<<endl;
  if(ifstream(file))tree->Add(file);
  else{ cout<<"ERROR: File not loaded"<<endl; return 0;}
     
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
  Int_t Electron_jetIdx[200];
  tree->SetBranchAddress("Electron_jetIdx",&Electron_jetIdx);
  Int_t Muon_jetIdx[200];
  tree->SetBranchAddress("Muon_jetIdx",&Muon_jetIdx);
  Int_t Lepton_pdgId[200];
  tree->SetBranchAddress("Lepton_pdgId",&Lepton_pdgId);
  Bool_t Lepton_isTightElectron_mvaFall17Iso_WP90[200];
  if (tree->GetBranch("Lepton_isTightElectron_mvaFall17Iso_WP90"))  tree->SetBranchAddress("Lepton_isTightElectron_mvaFall17Iso_WP90",&Lepton_isTightElectron_mvaFall17Iso_WP90);
  Bool_t Lepton_isTightElectron_mvaFall17Iso_WP90_SS[200];
  if (tree->GetBranch("Lepton_isTightElectron_mvaFall17Iso_WP90_SS"))tree->SetBranchAddress("Lepton_isTightElectron_mvaFall17Iso_WP90_SS",&Lepton_isTightElectron_mvaFall17Iso_WP90_SS);
  Bool_t Lepton_isTightElectron_mvaFall17V1Iso_WP90[200];
  if (tree->GetBranch("Lepton_isTightElectron_mvaFall17V1Iso_WP90"))tree->SetBranchAddress("Lepton_isTightElectron_mvaFall17V1Iso_WP90",&Lepton_isTightElectron_mvaFall17V1Iso_WP90);
  Bool_t Lepton_isTightElectron_mvaFall17V1Iso_WP90_SS[200];
  if (tree->GetBranch("Lepton_isTightElectron_mvaFall17V1Iso_WP90_SS"))tree->SetBranchAddress("Lepton_isTightElectron_mvaFall17V1Iso_WP90_SS",&Lepton_isTightElectron_mvaFall17V1Iso_WP90_SS);
  Bool_t Lepton_isTightElectron_mvaFall17V2Iso_WP90[200];
  if (tree->GetBranch("Lepton_isTightElectron_mvaFall17V2Iso_WP90"))tree->SetBranchAddress("Lepton_isTightElectron_mvaFall17V2Iso_WP90",&Lepton_isTightElectron_mvaFall17V2Iso_WP90);
  Bool_t Lepton_isTightElectron_mvaFall17V2Iso_WP90_SS[200];
  if (tree->GetBranch("Lepton_isTightElectron_mvaFall17V2Iso_WP90_SS"))tree->SetBranchAddress("Lepton_isTightElectron_mvaFall17V2Iso_WP90_SS",&Lepton_isTightElectron_mvaFall17V2Iso_WP90_SS);
  Bool_t Lepton_isTightElectron_mva_90p_Iso2016[200];
  if (tree->GetBranch("Lepton_isTightElectron_mva_90p_Iso2016"))tree->SetBranchAddress("Lepton_isTightElectron_mva_90p_Iso2016",&Lepton_isTightElectron_mva_90p_Iso2016);
  Bool_t Lepton_isTightElectron_cut_WP_Tight80X[200];
  if (tree->GetBranch("Lepton_isTightElectron_cut_WP_Tight80X"))tree->SetBranchAddress("Lepton_isTightElectron_cut_WP_Tight80X",&Lepton_isTightElectron_cut_WP_Tight80X);
  Bool_t Lepton_isTightElectron_mva_90p_Iso2016_SS[200];
  if (tree->GetBranch("Lepton_isTightElectron_mva_90p_Iso2016_SS"))tree->SetBranchAddress("Lepton_isTightElectron_mva_90p_Iso2016_SS",&Lepton_isTightElectron_mva_90p_Iso2016_SS);
  Bool_t Lepton_isTightElectron_cut_WP_Tight80X_SS[200];
  if (tree->GetBranch("Lepton_isTightElectron_cut_WP_Tight80X_SS"))tree->SetBranchAddress("Lepton_isTightElectron_cut_WP_Tight80X_SS",&Lepton_isTightElectron_cut_WP_Tight80X_SS);
  Bool_t Lepton_isTightMuon_cut_Tight_HWWW[200];
  if (tree->GetBranch("Lepton_isTightMuon_cut_Tight_HWWW"))tree->SetBranchAddress("Lepton_isTightMuon_cut_Tight_HWWW",&Lepton_isTightMuon_cut_Tight_HWWW);
  Bool_t Lepton_isTightMuon_cut_Tight80x[200];
  if (tree->GetBranch("Lepton_isTightMuon_cut_Tight80x"))tree->SetBranchAddress("Lepton_isTightMuon_cut_Tight80x",&Lepton_isTightMuon_cut_Tight80x);
  Bool_t isTightMuon[200];
  tree->SetBranchAddress(muwp,&isTightMuon);
  Bool_t isTightElectron[200];
  tree->SetBranchAddress(elewp,&isTightElectron);
  Float_t Electron_cutBased[200];
  tree->SetBranchAddress("Electron_cutBased",&Electron_cutBased);
  Bool_t Electron_convVeto[200];
  tree->SetBranchAddress("Electron_convVeto",&Electron_convVeto);
  Float_t Electron_dxy[200];
  tree->SetBranchAddress("Electron_dxy",&Electron_dxy);
  Float_t Electron_dz[200];
  tree->SetBranchAddress("Electron_dz",&Electron_dz);
  Float_t Electron_pfRelIso03_all[200];
  tree->SetBranchAddress("Electron_pfRelIso03_all",&Electron_pfRelIso03_all);
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
  Float_t PuppiMET_pt;
  tree->SetBranchAddress("PuppiMET_pt",&PuppiMET_pt);
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
  Float_t Jet_btagDeepB[200];
  tree->SetBranchAddress("Jet_btagDeepB",&Jet_btagDeepB);
  Float_t CleanJet_pt[200];
  tree->SetBranchAddress("CleanJet_pt",&CleanJet_pt);
  Float_t Jet_pt[200];
  tree->SetBranchAddress("Jet_pt",&Jet_pt);
  Float_t CleanJet_eta[200];
  tree->SetBranchAddress("CleanJet_eta",&CleanJet_eta);
  Float_t CleanJet_phi[200];
  tree->SetBranchAddress("CleanJet_phi",&CleanJet_phi);
  Int_t Jet_partonFlavour[200];
  if (tree->GetBranch("Jet_partonFlavour"))tree->SetBranchAddress("Jet_partonFlavour",&Jet_partonFlavour);
  Int_t GenJet_partonFlavour[200];
  if (tree->GetBranch("GenJet_partonFlavour"))tree->SetBranchAddress("GenJet_partonFlavour",&GenJet_partonFlavour);
  Float_t puWeight;
  if (tree->GetBranch("puWeight"))tree->SetBranchAddress("puWeight",&puWeight);
  Float_t baseW;
  if (tree->GetBranch("baseW"))tree->SetBranchAddress("baseW",&baseW);
  Float_t Generator_weight;
  if (tree->GetBranch("Generator_weight"))tree->SetBranchAddress("Generator_weight",&Generator_weight);

  //Int_t event;
  //tree->SetBranchAddress("event",&event);
  Bool_t HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30;
  tree->SetBranchAddress("HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30",&HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30);
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

  cout<<"Begin..."<<endl;

  // Create the output histograms
  //--------------------------------------------------------------------------------------------------------------------------------------
  TH1::SetDefaultSumw2();

  //Prompt rates
  TH1F* h_PR_pt_loose_ele;
  TH1F* h_PR_eta_loose_ele;
  TH1F* h_PR_pt_loose_mu;
  TH1F* h_PR_eta_loose_mu;
  TH1F* h_PR_pt_tight_ele;
  TH1F* h_PR_eta_tight_ele;
  TH1F* h_PR_pt_tight_mu;
  TH1F* h_PR_eta_tight_mu;

  TH2D * PR_pT_eta_loose_ele;
  TH2D * PR_pT_eta_tight_ele;
  TH2D * PR_pT_eta_loose_mu;
  TH2D * PR_pT_eta_tight_mu;

  h_PR_pt_loose_ele    = new TH1F("h_PR_pt_loose_ele","h_PR_pt_loose_ele",8,10,50);
  h_PR_eta_loose_ele   = new TH1F("h_PR_eta_loose_ele","h_PR_eta_loose_ele",5,0,2.5);
  h_PR_pt_loose_mu     = new TH1F("h_PR_pt_loose_mu","h_PR_pt_loose_mu",8,10,50);
  h_PR_eta_loose_mu    = new TH1F("h_PR_eta_loose_mu","h_PR_eta_loose_mu",5,0,2.5);
  h_PR_pt_tight_ele    = new TH1F("h_PR_pt_tight_ele","h_PR_pt_tight_ele",8,10,50);
  h_PR_eta_tight_ele   = new TH1F("h_PR_eta_tight_ele","h_PR_eta_tight_ele",5,0,2.5);
  h_PR_pt_tight_mu     = new TH1F("h_PR_pt_tight_mu","h_PR_pt_tight_mu",8,10,50);
  h_PR_eta_tight_mu    = new TH1F("h_PR_eta_tight_mu","h_PR_eta_tight_mu",5,0,2.5);
  PR_pT_eta_loose_ele  = new TH2D("PR_pT_eta_loose_ele","PR_pT_eta_loose_ele",8,10,50,5,0,2.5);
  PR_pT_eta_tight_ele  = new TH2D("PR_pT_eta_tight_ele","PR_pT_eta_tight_ele",8,10,50,5,0,2.5);
  PR_pT_eta_loose_mu   = new TH2D("PR_pT_eta_loose_mu","PR_pT_eta_loose_mu",8,10,50,5,0,2.5);
  PR_pT_eta_tight_mu   = new TH2D("PR_pT_eta_tight_mu","PR_pT_eta_tight_mu",8,10,50,5,0,2.5);


  // Loop over the tree events
  //--------------------------------------------------------------------------------------------------------------------------------------
  for (int j = 0; j < tree->GetEntries(); ++j){
    tree->GetEntry(j);
    int nentries = tree->GetEntriesFast();
    if(fmod(j,100000)==0) printf(" ..... event %d of %d", int(j), int(nentries));

    // Make Z candidate
    //------------------------------------------------------------------------  
    TString Zlepton2type   = "loose";    TString Zlepton1type   = "loose";
    double m2l = -1; double Zdecay;
    int lepton1Index=0,lepton2Index=0;
    TLorentzVector tlv1,tlv2;
    if (nLepton < 2) continue;

    for (unsigned int iLep1=0; iLep1<nLepton; iLep1++) {
      if (Lepton_pt[iLep1] < 25.) continue;

      if ((fabs(Lepton_pdgId[iLep1]) ==11 && isTightElectron[iLep1] < 0.5)||(fabs(Lepton_pdgId[iLep1]) ==13 && isTightMuon[iLep1] < 0.5))
	continue; //First lepton always tight
      Zlepton1type = "tight";
      for (unsigned int iLep2=iLep1+1; iLep2<nLepton; iLep2++) {
	if (Lepton_pt[iLep2] < 10.) continue;
	if (Lepton_pdgId[iLep1] + Lepton_pdgId[iLep2] != 0) continue;
	float mass1 = (fabs(Lepton_pdgId[iLep1]) == 11) ? 0.000511 : 0.106;
	float mass2 = (fabs(Lepton_pdgId[iLep2]) == 11) ? 0.000511 : 0.106;

	tlv1.SetPtEtaPhiM(Lepton_pt[iLep1], Lepton_eta[iLep1], Lepton_phi[iLep1], mass1);
	tlv2.SetPtEtaPhiM(Lepton_pt[iLep2], Lepton_eta[iLep2], Lepton_phi[iLep2], mass2);

	float inv_mass = (tlv1 + tlv2).M();

	if (m2l < 0 || fabs(inv_mass - 91.188) < fabs(m2l - 91.188)) {
	  m2l = inv_mass;
	  lepton2Index = iLep2;
	  lepton1Index = iLep1;
	  Zdecay = fabs(Lepton_pdgId[iLep1]);
	  //cout<<"nlepton "<<nLepton<<" l1 "<<lepton1Index<<" l2 "<<lepton2Index<<" m2l "<<m2l<<" Zdecay  "<<Zdecay<<endl;    
	  //cout<<" l1 "<<fabs(Lepton_pdgId[iLep1])<<" e? "<<isTightElectron[iLep1]<<", mu? "<<isTightMuon[iLep1]<<endl; 
	  //cout<<" l2 "<<fabs(Lepton_pdgId[iLep2])<<" e? "<<isTightElectron[iLep2]<<", mu? "<<isTightMuon[iLep2]<<endl; 
	  // Is the second lepton tight?

	  if ((fabs(Lepton_pdgId[iLep2]) ==11 && isTightElectron[iLep2] > 0.5)||(fabs(Lepton_pdgId[iLep2]) ==13 && isTightMuon[iLep2] > 0.5)){
	    Zlepton2type="tight";
	  }
	}	  
      } //2nd lepton
    } //1st lepton


    //---------------------------Trigger------------------------
    bool passTrigger = false;
    if (channel == "mu") {
      if (Lepton_pt[lepton1Index] <= 20. && HLT_Mu8_TrkIsoVVL > 0.5)       passTrigger = true;
      else if (Lepton_pt[lepton1Index] > 20. && HLT_Mu17_TrkIsoVVL > 0.5)  passTrigger = true;
    }
    if (channel == "ele") {
      if (year=="2016" && Lepton_pt[lepton1Index] <= 25. && HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 > 0.5)         passTrigger = true;
      else if (year!="2016" && Lepton_pt[lepton1Index] <= 25. && HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 > 0.5)     passTrigger = true;
      else if (Lepton_pt[lepton1Index] > 25. && HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 > 0.5)                     passTrigger = true;
    }

    //------------------------------ Preselection --------------------------------------
    if (m2l<76. || m2l>106.){continue;}
    if (passTrigger != true){continue;}

    //------------------Channel loop--------------------------------------
    if (channel=="ele"){
      if (Zdecay != 11) continue;
      if (Lepton_pt[lepton1Index]<13 || fabs(Lepton_eta[lepton1Index])>2.5)continue;
      /// Loose WP
      PR_pT_eta_loose_ele ->Fill(Lepton_pt[lepton2Index],fabs(Lepton_eta[lepton2Index]),weight);
      h_PR_pt_loose_ele ->Fill(Lepton_pt[lepton2Index],weight);
      h_PR_eta_loose_ele ->Fill(fabs(Lepton_eta[lepton2Index]),weight);
      /// Tight WP	 
      if(Zlepton2type=="tight"){
	PR_pT_eta_tight_ele ->Fill(Lepton_pt[lepton2Index],fabs(Lepton_eta[lepton2Index]),weight);
	h_PR_pt_tight_ele ->Fill(Lepton_pt[lepton2Index],weight);
	h_PR_eta_tight_ele ->Fill(fabs(Lepton_eta[lepton2Index]),weight);
      }

    }// Close ele channel

    if (channel=="mu"){
      if (Zdecay != 13) continue;
      if (Lepton_pt[lepton1Index]<10 || fabs(Lepton_eta[lepton1Index])>2.4)continue;
      /// Loose WP
      PR_pT_eta_loose_mu ->Fill(Lepton_pt[lepton2Index],fabs(Lepton_eta[lepton2Index]),weight);
      h_PR_pt_loose_mu ->Fill(Lepton_pt[lepton2Index],weight);
      h_PR_eta_loose_mu ->Fill(fabs(Lepton_eta[lepton2Index]),weight);
      /// Tight WP
      if(Zlepton2type=="tight"){
	PR_pT_eta_tight_mu ->Fill(Lepton_pt[lepton2Index],fabs(Lepton_eta[lepton2Index]),weight);
	h_PR_pt_tight_mu ->Fill(Lepton_pt[lepton2Index],weight);
	h_PR_eta_tight_mu ->Fill(fabs(Lepton_eta[lepton2Index]),weight);
      }
	
    }//Close mu channel

  }//Close loop in entries

  //Write histograms in root output
  TDirectory *dir;
  dir  = root_output->mkdir("PR");
  dir ->cd();
  if(channel=="ele"){
    h_PR_pt_loose_ele ->Write();
    h_PR_eta_loose_ele ->Write();
    h_PR_pt_tight_ele ->Write();
    h_PR_eta_tight_ele ->Write();
    PR_pT_eta_loose_ele ->Write();
    PR_pT_eta_tight_ele ->Write();
  }
  else if(channel=="mu"){
    h_PR_pt_loose_mu ->Write();
    h_PR_eta_loose_mu ->Write();
    h_PR_pt_tight_mu ->Write();
    h_PR_eta_tight_mu ->Write();
    PR_pT_eta_loose_mu ->Write();
    PR_pT_eta_tight_mu ->Write();
  }
  root_output->Close();
  
  cout << endl;
  cout << "-------- Done ---------";
  cout << endl;

}
