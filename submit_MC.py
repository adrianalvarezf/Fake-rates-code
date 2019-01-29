import os
import sys

# HOW TO USE:
# python submit_MC.py > launch_MC.sh

SAMPLES= set()

#for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017v2__MCCorr2017test__fakeSelMC/"):
for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017v2__MCCorr2017/"):

	if 'DYJetsToLL_M-50__' in ii : SAMPLES.add(ii)
	elif 'WJetsToLNu-LO__' in ii : SAMPLES.add(ii) 
	if 'TTToSemiLeptonic__' in ii : SAMPLES.add(ii)

CHANNEL={"ele","mu"}


for s in SAMPLES:
	for ch in CHANNEL:
		print 'bsub -q 2nd -u alvareza submit_batch_FR.sh ' + s + '  ' + ch 
