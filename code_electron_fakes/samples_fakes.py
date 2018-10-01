import os
import subprocess
import string
from LatinoAnalysis.Tools.commonTools import *

# samples

#samples = {}

##############################################
###### Tree Directory according to site ######
##############################################

treeBaseDir = '/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/'

#directoryData = treeBaseDir+'Run2017_nAOD_v1_Study2017/DATAl1loose2017'
directoryData = treeBaseDir+'Run2017_nAOD_v1_Study2017/DATAl1loose2017__hadd'
directoryMC = treeBaseDir+'Fall2017_nAOD_v1_Study2017/MCl1loose2017__baseW__hadd'

################################################
############ BASIC MC WEIGHTS ##################
################################################

#XSWeight      = 'baseW* Generator_weight/abs(Generator_weight)'
XSWeight      = 'baseW* Generator_weight'
PUWeight      = 'puWeight'

################################################
############### HLT  ######################
################################################

passHLT = "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30" if  'Lepton_pt[0]' <= 25. else "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30"

################################################
############### Trigger   ######################
################################################

trigger_weight = "0.0277" if  'Lepton_pt[0]' <= 25. else "0.0435"

#0.043 fb-1 = 43 pb-1

################################################
############### CleanJets   ######################
################################################
#lep_1 = ROOT.TLorentzVector()
#jet_v = ROOT.TLorentzVector()

#pass_cleanjets = 

#for i in range(1,nCleanJet): 
#  jet_v.SetPtEtaPhiM(CleanJet_pt[i-1], CleanJet_eta[i-1], CleanJet_phi[i-1], 0); 
#  lep_1.SetPtEtaPhiM(Lepton_pt[0], Lepton_eta[0], Lepton_phi[0], 0); 
#  if CleanJet_pt[i]>25 and (jet_v.DeltaR(lep_1)>1) :
#    pass_cleanjets = "1"



###########################################
#############  BACKGROUNDS  ###############
###########################################


###### DY #######

samples['DY'] = {    'name'   :   getSampleFiles(directoryMC,'DYJetsToLL_M-50__part0') ,
                             #   + getSampleFiles(directoryMC,'DYJetsToLL_M-5to50-LO')     ,
                     'weight' : XSWeight+'*'+PUWeight+'*'+trigger_weight+'*'+passHLT ,
                     'FilesPerJob' : 2 ,
                 }


###### W+jets #######

samples['WJets'] = {    'name'   :   getSampleFiles(directoryMC,'WJetsToLNu-LO__part0') ,
                        'weight' : XSWeight+'*'+PUWeight+'*'+trigger_weight+'*'+passHLT ,
                        'FilesPerJob' : 2 ,
                 }

################################################
############ DATA DECLARATION ##################
################################################

DataRun = [ 
            #['B','Run2017B-31Mar2018-v1'] , 
            ['C','Run2017C-31Mar2018-v1__part0'] , 
            #['D','Run2017D-31Mar2018-v1'] , 
            #['E','Run2017E-31Mar2018-v1'] , 
            #['F','Run2017F-31Mar2018-v1'] , 
          ] 

#DataSets = ['MuonEG','DoubleMuon','SingleMuon','DoubleEG','SingleElectron']
DataSets = ['SingleElectron']
#DataSets = ['DoubleEG']


###########################################
################## DATA ###################
###########################################

samples['DATA']  = {   'name': [ ] ,     
                       'weight' : passHLT ,
                       'weights' : [ ],
                       'isData': ['all'],                            
                       'FilesPerJob' : 6 ,
                  }

for Run in DataRun :
  for DataSet in DataSets :
    #FileTarget = getSampleFiles(directoryData,DataSet+'_'+Run[1]+'__part0',True)
    FileTarget = getSampleFiles(directoryData,DataSet+'_'+Run[1],True)
    for iFile in FileTarget:
      samples['DATA']['name'].append(iFile)
      samples['DATA']['weights'].append("1")

