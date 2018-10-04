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
############### HLT ######################
################################################

#passHLT = "HLT_Mu8_TrkIsoVVL"  if  'Lepton_pt[0]' <= 20. else "HLT_Mu17_TrkIsoVVL"

################################################
############### Trigger   ######################
################################################


trigger_weight = "0.002903" if  'Lepton_pt[0]' <= 20. else "0.065944"  #0.070 para HLT_Mu17

#0.004 fb-1 =4 pb-1

################################################
############### CleanJets   ######################
################################################
pass_cleanjets = "0"
jetn ='nCleanJet' 
jetpt ='CleanJet_pt[{0}]'
deltaphi ='abs(CleanJet_phi[{0}]-Lepton_phi[0])>1)'

for i in range(0,10): 
  if jetn > i and jetpt.format(i) >25 and deltaphi.format(i) >1 :
    pass_cleanjets = "1"

###########################################
#############  BACKGROUNDS  ###############
###########################################


###### DY #######

samples['DY'] = {    'name'   :   getSampleFiles(directoryMC,'DYJetsToLL_M-50__part0') ,
                             #   + getSampleFiles(directoryMC,'DYJetsToLL_M-5to50-LO')     ,

                    # 'weight' : XSWeight+'*'+LepWPCut+'*'+PUWeight ,
                    # 'weight' : XSWeight+'*'+PUWeight+'*'+trigger_weight+'*'+passHLT+'*'+pass_cleanjets ,
                     'weight' : XSWeight+'*'+PUWeight+'*'+trigger_weight+'*'+pass_cleanjets ,
                     'FilesPerJob' : 2 ,
                 }


###### W+jets #######

samples['WJets'] = {    'name'   :   getSampleFiles(directoryMC,'WJetsToLNu-LO__part0') ,
                        #'weight' : XSWeight+'*'+LepWPCut+'*'+PUWeight ,
                        #'weight' : XSWeight+'*'+PUWeight+'*'+trigger_weight+'*'+passHLT+'*'+pass_cleanjets ,
                        'weight' : XSWeight+'*'+PUWeight+'*'+trigger_weight+'*'+pass_cleanjets ,
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
DataSets = ['DoubleMuon']


###########################################
################## DATA ###################
###########################################

samples['DATA']  = {   'name': [ ] ,     
                  #     'weight' : passHLT+'*'+pass_cleanjets ,
                       'weight' : pass_cleanjets ,
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

