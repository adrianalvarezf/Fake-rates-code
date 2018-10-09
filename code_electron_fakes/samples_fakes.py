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

#passHLT = "HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30" if  'Lepton_pt[0]' <= 25. else "HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30"

################################################
############### Trigger   ######################
################################################

trigger_weight = "0.027699" if  'Lepton_pt[0]' < 25. else "0.043469"

#0.043 fb-1 = 43 pb-1

################################################
############### CleanJets   ######################
################################################
#pass_cleanjets = "0"
#jetn ='nCleanJet' 
#jetpt ='CleanJet_pt[{0}]'
#deltaR ='sqrt( (CleanJet_phi[{0}]-Lepton_phi[0])*(CleanJet_phi[{0}]-Lepton_phi[0]) + (CleanJet_eta[{0}]-Lepton_eta[0])*(CleanJet_eta[{0}]-Lepton_eta[0]) )'

#for i in range(0,10): 
#  if jetn > i :
#    if jetpt.format(i) >25 and deltaR.format(i) >1 :
#      pass_cleanjets = "1"

###########################################
#############  BACKGROUNDS  ###############
###########################################


###### DY #######

samples['DY'] = {    'name'   :   getSampleFiles(directoryMC,'DYJetsToLL_M-50__part0') ,
                             #   + getSampleFiles(directoryMC,'DYJetsToLL_M-5to50-LO')     ,
                     'weight' : XSWeight+'*'+PUWeight+'*'+trigger_weight ,
                     'FilesPerJob' : 2 ,
                 }


###### W+jets #######

samples['WJets'] = {    'name'   :   getSampleFiles(directoryMC,'WJetsToLNu-LO__part0') ,
                        'weight' : XSWeight+'*'+PUWeight+'*'+trigger_weight ,
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
                       #'weight' : pass_cleanjets ,
                       'weight' : "1" ,
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

