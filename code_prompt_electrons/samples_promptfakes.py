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

###############################################
############ BASIC MC WEIGHTS ##################
################################################

#XSWeight      = 'baseW* Generator_weight/abs(Generator_weight)'
XSWeight      = 'baseW* Generator_weight'
PUWeight      = 'puWeight'

################################################
############### Trigger   ######################
################################################

#if Lepton_pt[0] <= 25. :
#  trigger_weight = 4
#else :
#  trigger_weight = 43

trigger_weight = "41.527"

#0.004 fb-1 =4 pb-1

###########################################
#############  BACKGROUNDS  ###############
###########################################


###### DY #######

samples['DY'] = {    'name'   :   getSampleFiles(directoryMC,'DYJetsToLL_M-50') ,
                             #   + getSampleFiles(directoryMC,'DYJetsToLL_M-5to50-LO')     ,

                    # 'weight' : XSWeight+'*'+LepWPCut+'*'+PUWeight ,
                    # 'weight' : XSWeight+'*'+PUWeight+'*'+trigger_weight ,
                     'weight' : "1" ,
                     'FilesPerJob' : 2 ,
                 }
