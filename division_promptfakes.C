#include "TCanvas.h"
#include "TTree.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>


void division_promptfakes()
{

  //TFile* file_hadd= new TFile("rootFile_11September_PromptFakes/plots__11September_PromptFakes.root");
  TFile* file_hadd= new TFile("rootFile_17September_PromptFakes_lumiHLT/plots__17September_PromptFakes_lumiHLT.root");
  TH1F* h_DATA = (TH1F*)file_hadd->Get("numerator/ele_pt2/histo_DATA"); 
  TH1F* h_DY = (TH1F*)file_hadd->Get("numerator/ele_pt2/histo_DY"); 
 
  TH1F* h_denominator_DATA = (TH1F*)file_hadd->Get("denominator/ele_pt2/histo_DATA"); 
  TH1F* h_denominator_DY = (TH1F*)file_hadd->Get("denominator/ele_pt2/histo_DY"); 
 
  TH1F* h_DATA_eta = (TH1F*)file_hadd->Get("numerator/abs_ele_eta2/histo_DATA"); 
  TH1F* h_DY_eta = (TH1F*)file_hadd->Get("numerator/abs_ele_eta2/histo_DY"); 
 
  TH1F* h_denominator_DATA_eta = (TH1F*)file_hadd->Get("denominator/abs_ele_eta2/histo_DATA"); 
  TH1F* h_denominator_DY_eta = (TH1F*)file_hadd->Get("denominator/abs_ele_eta2/histo_DY"); 
 

  gStyle->SetOptStat(0);
 
  TH1F* h_div = (TH1F*)h_DATA->Clone("h_div");
  h_div->Divide(h_denominator_DATA);
 
  TCanvas *c1= new TCanvas();
  h_div->Draw(); h_div->GetYaxis()->SetRangeUser(0,1); h_div->SetTitle("Prompt fake rate"); h_div->GetXaxis()->SetTitle("Pt2 [GeV]");h_div->GetYaxis()->SetTitle("Ele fake rate");c1->SetGrid();
  c1->SaveAs("promptfakes_pt.gif");
 
  //TH1F* h_div_eta = (TH1F*)h_DATA_eta->Clone("h_div_eta");
  //h_div_eta->Divide(h_denominator_DATA_eta);
 
  //TCanvas *c2= new TCanvas();
  //h_div_eta->Draw(); h_div_eta->GetYaxis()->SetRangeUser(0,1); h_div_eta->SetTitle("prompt fake rate"); h_div_eta->GetXaxis()->SetTitle("|Eta2|");
  //c2->SaveAs("promptfakes_eta.gif");
 
  TH1F* h_div_DY = (TH1F*)h_DY->Clone("h_div_DY");
  h_div_DY->Divide(h_denominator_DY);
 
  TCanvas *c3= new TCanvas();
  h_div_DY->Draw(); h_div_DY->GetYaxis()->SetRangeUser(0,1); h_div_DY->SetTitle("Prompt fake rate"); h_div_DY->GetXaxis()->SetTitle("Pt2 [GeV]");h_div_DY->GetYaxis()->SetTitle("Ele fake rate");c3->SetGrid();
  c3->SaveAs("promptfakes_DY_pt.gif");
 
  //TH1F* h_div_DY_eta = (TH1F*)h_DY_eta->Clone("h_div_DY_eta");
  //h_div_DY_eta->Divide(h_denominator_DY_eta);
 
  //TCanvas *c4= new TCanvas();
  //h_div_DY_eta->Draw(); h_div_DY_eta->GetYaxis()->SetRangeUser(0,1); h_div_DY_eta->SetTitle("prompt fake rate"); h_div_DY_eta->GetXaxis()->SetTitle("|Eta2|");
  //c4->SaveAs("promptfakes_DY_eta.gif");

  cout<<"THE END"<<endl;
 
}



 
