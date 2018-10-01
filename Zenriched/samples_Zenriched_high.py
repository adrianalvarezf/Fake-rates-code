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
############### Lepton WP ######################
################################################

#... Electron:
#eleWP='Electron_mvaFall17Iso_WP80'


#... Build formula

#LepWPCut        = eleWP+'[Lepton_electronIdx[0]]'

################################################
############### Trigger   ######################
################################################

#if Lepton_pt[0] <= 25. :
#  trigger_weight = 4
#else :
#  trigger_weight = 43

trigger_weight = "0.043"

#0.004 fb-1 =4 pb-1

###########################################
#############  BACKGROUNDS  ###############
###########################################


###### DY #######

#samples['DY'] = {    'name'   :   getSampleFiles(directoryMC,'DYJetsToLL_M-50-LO-ext1') ,
samples['DY'] = {    'name'   :   getSampleFiles(directoryMC,'DYJetsToLL_M-50') ,
                             #   + getSampleFiles(directoryMC,'DYJetsToLL_M-5to50-LO')     ,

                    # 'weight' : XSWeight+'*'+LepWPCut+'*'+PUWeight ,
                     'weight' : XSWeight+'*'+PUWeight+'*'+trigger_weight ,
                    # 'weight' : XSWeight+'*'+PUWeight ,
                     'FilesPerJob' : 2 ,
                 }


################################################
############ DATA DECLARATION ##################
################################################

DataRun = [ 
            #['B','Run2017B-31Mar2018-v1'] , 
            ['C','Run2017C-31Mar2018-v1'] , 
            ['D','Run2017D-31Mar2018-v1'] , 
            ['E','Run2017E-31Mar2018-v1'] , 
            ['F','Run2017F-31Mar2018-v1'] , 
          ] 

#DataSets = ['MuonEG','DoubleMuon','SingleMuon','DoubleEG','SingleElectron']
DataSets = ['SingleElectron']


###########################################
################## DATA ###################
###########################################

samples['DATA']  = {   'name': [ ] ,     
                       'weight' : '1' ,
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

