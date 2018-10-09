#include "TCanvas.h"
#include "TTree.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>



void division_forfakes()
{

  //TFile* file_hadd= new TFile("code_electron_fakes/rootFile_24September_Fakes_noMCtrigger/plots__24September_Fakes_noMCtrigger.root");
  //TFile* file_hadd= new TFile("code_electron_fakes/rootFile_27September_Fakes_doubleEG/plots__27September_Fakes_doubleEG.root");
  //TFile* file_hadd= new TFile("code_electron_fakes/rootFile_27September_Fakes_triggerhigh/plots__27September_Fakes_triggerhigh.root");
  //TFile* file_hadd= new TFile("code_electron_fakes/rootFile_27September_Fakes_triggerlow/plots__27September_Fakes_triggerlow.root");
  //TFile* file_hadd= new TFile("code_electron_fakes/rootFile_2October_Fake_ele_full_MCtrig/plots__2October_Fake_ele_full_MCtrig.root");
  //TFile* file_hadd= new TFile("code_electron_fakes/rootFile_3October_Fakes_full_updated/plots__3October_Fakes_full_updated.root");
  TFile* file_hadd= new TFile("code_electron_fakes/rootFile_8October_Fakes_full_updated/plots__8October_Fakes_full_updated.root");
  TH1F* h_DATA = (TH1F*)file_hadd->Get("numerator/ele_pt1/histo_DATA"); 
  TH1F* h_DY = (TH1F*)file_hadd->Get("numerator/ele_pt1/histo_DY"); 
  TH1F* h_WJets = (TH1F*)file_hadd->Get("numerator/ele_pt1/histo_WJets"); 
  TH1F* h_denominator_DATA = (TH1F*)file_hadd->Get("denominator/ele_pt1/histo_DATA"); 
  TH1F* h_denominator_DY = (TH1F*)file_hadd->Get("denominator/ele_pt1/histo_DY"); 
  TH1F* h_denominator_WJets = (TH1F*)file_hadd->Get("denominator/ele_pt1/histo_WJets"); 
  TH1F* h_DATA_eta = (TH1F*)file_hadd->Get("numerator/abs_ele_eta1/histo_DATA"); 
  TH1F* h_DY_eta = (TH1F*)file_hadd->Get("numerator/abs_ele_eta1/histo_DY"); 
  TH1F* h_WJets_eta = (TH1F*)file_hadd->Get("numerator/abs_ele_eta1/histo_WJets"); 
  TH1F* h_denominator_DATA_eta = (TH1F*)file_hadd->Get("denominator/abs_ele_eta1/histo_DATA"); 
  TH1F* h_denominator_DY_eta = (TH1F*)file_hadd->Get("denominator/abs_ele_eta1/histo_DY"); 
  TH1F* h_denominator_WJets_eta = (TH1F*)file_hadd->Get("denominator/abs_ele_eta1/histo_WJets"); 

  gStyle->SetOptStat(0);
  TH1F* h_num = (TH1F*)h_DATA->Clone("h_num");
  h_num->Add(h_DY,-1);
  h_num->Add(h_WJets,-1);
  TH1F* h_den = (TH1F*)h_denominator_DATA->Clone("h_den");
  h_den->Add(h_denominator_DY,-1);
  h_den->Add(h_denominator_WJets,-1);
  TH1F* h_div = (TH1F*)h_num->Clone("h_div");
  h_div->Divide(h_den);
  TH1F* h_div_noEWKcorr = (TH1F*)h_DATA->Clone("h_div_noEWKcorr");
  h_div_noEWKcorr->Divide(h_denominator_DATA);

  TH1F* h_relEWKcont = (TH1F*)h_DY->Clone("h_relEWKcont");
  h_relEWKcont->Add(h_WJets,1);
  TH1F* h_relEWKcont_numerator = (TH1F*)h_relEWKcont->Clone("h_relEWKcont_numerator");
  h_relEWKcont_numerator->Divide(h_DATA);
  TH1F* h_relEWKcont2 = (TH1F*)h_denominator_DY->Clone("h_relEWKcont2");
  h_relEWKcont2->Add(h_denominator_WJets,1);
  TH1F* h_relEWKcont_denominator = (TH1F*)h_relEWKcont2->Clone("h_relEWKcont_denominator");
  h_relEWKcont_denominator->Divide(h_denominator_DATA);

  TCanvas *c1= new TCanvas();
  h_num->Draw();//c1->SaveAs("division_TightElectron_Iso_WP80_num_pt.gif");
  h_den->Draw();//c1->SaveAs("division_TightElectron_Iso_WP80_den_pt.gif");
  h_div->Draw(); h_div->GetYaxis()->SetRangeUser(0,1); h_div->SetTitle("Electron_mvaFall17Iso_WP80 fake rate"); h_div->SetLineColor(2); h_div->GetXaxis()->SetTitle("Pt1 [GeV]"); h_div->GetYaxis()->SetTitle("Ele fake rate");c1->SetGrid();
  h_div_noEWKcorr->Draw("same"); h_div_noEWKcorr->SetLineColor(1);
  c1->SaveAs("division_TightElectron_Iso_WP80_pt.gif");
  h_relEWKcont_numerator->Draw();h_relEWKcont_numerator->GetYaxis()->SetRangeUser(0,1);h_relEWKcont_numerator->SetTitle("Electron EWK contamination"); h_relEWKcont_numerator->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_numerator->GetXaxis()->SetTitle("Pt1 [GeV]");c1->SaveAs("EWK_contamination_Iso_WP80_numerator.gif");
  h_relEWKcont_denominator->Draw();h_relEWKcont_denominator->GetYaxis()->SetRangeUser(0,1);h_relEWKcont_denominator->SetTitle("Electron EWK contamination"); h_relEWKcont_denominator->GetYaxis()->SetTitle("EWK MC/DATA");h_relEWKcont_denominator->GetXaxis()->SetTitle("Pt1 [GeV]");c1->SaveAs("EWK_contamination_Iso_WP80_denominator.gif");

  TH1F* h_num_eta = (TH1F*)h_DATA_eta->Clone("h_num_eta");
  h_num_eta->Add(h_DY_eta,-1);
  h_num_eta->Add(h_WJets_eta,-1);
  TH1F* h_den_eta = (TH1F*)h_denominator_DATA_eta->Clone("h_den_eta");
  h_den_eta->Add(h_denominator_DY_eta,-1);
  h_den_eta->Add(h_denominator_WJets_eta,-1);
  TH1F* h_div_eta = (TH1F*)h_num_eta->Clone("h_div_eta");
  h_div_eta->Divide(h_den_eta);
  TH1F* h_div_noEWKcorr_eta = (TH1F*)h_DATA_eta->Clone("h_div_noEWKcorr_eta");
  h_div_noEWKcorr_eta->Divide(h_denominator_DATA_eta);
  
  TCanvas *c2= new TCanvas();
  h_num_eta->Draw();//c2->SaveAs("division_TightElectron_Iso_WP80_num_eta.gif");
  h_den_eta->Draw();//c2->SaveAs("division_TightElectron_Iso_WP80_den_eta.gif");
  h_div_eta->Draw(); h_div_eta->GetYaxis()->SetRangeUser(-0.4,1); h_div_eta->SetTitle("Electron_mvaFall17Iso_WP80fake rate"); h_div_eta->SetLineColor(2); h_div_eta->GetXaxis()->SetTitle("|Eta1|"); h_div_eta->GetYaxis()->SetTitle("Ele fake rate");c2->SetGrid();
  h_div_noEWKcorr_eta->Draw("same"); h_div_noEWKcorr_eta->SetLineColor(1);
  c2->SaveAs("division_TightElectron_Iso_WP80_eta.gif");
 
  cout<<"THE END"<<endl;
 
}



 
