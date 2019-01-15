import os
import sys

# HOW TO USE:                                                                                                                                                                                                     # python submit_DATA.py > launch_DATA.sh                                                                                                                                                                               
SAMPLESMU= set()
SAMPLESELE= set()

for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2017_nAOD_v1_Full2017v2/DATAl1loose2017v2__DATACorr2017__fakeSel/"):

        if   'DoubleMuon_Run' in ii : SAMPLESMU.add(ii)
        elif 'SingleElectron_Run' in ii : SAMPLESELE.add(ii)

#SAMPLESMU={"DoubleMuon_Run2017C-31Mar2018-v1__part0","DoubleMuon_Run2017C-31Mar2018-v1__part1","DoubleMuon_Run2017C-31Mar2018-v1__part2","DoubleMuon_Run2017D-31Mar2018-v1__part0","DoubleMuon_Run2017D-31Mar2018-v1__part1","DoubleMuon_Run2017E-31Mar2018-v1__part0","DoubleMuon_Run2017E-31Mar2018-v1__part1","DoubleMuon_Run2017E-31Mar2018-v1__part2","DoubleMuon_Run2017E-31Mar2018-v1__part3","DoubleMuon_Run2017F-31Mar2018-v1__part0","DoubleMuon_Run2017F-31Mar2018-v1__part1","DoubleMuon_Run2017F-31Mar2018-v1__part2","DoubleMuon_Run2017F-31Mar2018-v1__part3","DoubleMuon_Run2017F-31Mar2018-v1__part4","DoubleMuon_Run2017F-31Mar2018-v1__part5"}

#SAMPLESELE={"SingleElectron_Run2017C-31Mar2018-v1__part0","SingleElectron_Run2017C-31Mar2018-v1__part1","SingleElectron_Run2017C-31Mar2018-v1__part2","SingleElectron_Run2017C-31Mar2018-v1__part3","SingleElectron_Run2017C-31Mar2018-v1__part4","SingleElectron_Run2017D-31Mar2018-v1__part0","SingleElectron_Run2017D-31Mar2018-v1__part1","SingleElectron_Run2017E-31Mar2018-v1__part0","SingleElectron_Run2017E-31Mar2018-v1__part1","SingleElectron_Run2017E-31Mar2018-v1__part2","SingleElectron_Run2017E-31Mar2018-v1__part3","SingleElectron_Run2017F-31Mar2018-v1__part0","SingleElectron_Run2017F-31Mar2018-v1__part1","SingleElectron_Run2017F-31Mar2018-v1__part2","SingleElectron_Run2017F-31Mar2018-v1__part3","SingleElectron_Run2017F-31Mar2018-v1__part4"}


for s in SAMPLESMU:
    print 'bsub -q 2nd -u alvareza submit_batch_FR.sh ' + s + '  ' + "mu" 

for s in SAMPLESELE:
    print 'bsub -q 2nd -u alvareza submit_batch_FR.sh ' + s + '  ' + "ele"


 
