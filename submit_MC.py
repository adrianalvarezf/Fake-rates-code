import os
import sys

# HOW TO USE:
# python submit_MC.py > launch_MC.sh

SAMPLES= set()

#for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017v2__MCCorr2017test__fakeSelMC/"):
for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017v2/"):

	if 'DYJetsToLL_M-50__' in ii : SAMPLES.add(ii)
	elif 'WJetsToLNu-LO__' in ii : SAMPLES.add(ii) 

#SAMPLES={"DYJetsToLL_M-50__part0","DYJetsToLL_M-50__part1","DYJetsToLL_M-50__part2","DYJetsToLL_M-50__part3","DYJetsToLL_M-50__part4","DYJetsToLL_M-50__part5","DYJetsToLL_M-50__part6","DYJetsToLL_M-50__part7","DYJetsToLL_M-50__part8","DYJetsToLL_M-50__part9","DYJetsToLL_M-50__part10","DYJetsToLL_M-50__part11","DYJetsToLL_M-50__part12","DYJetsToLL_M-50__part13","DYJetsToLL_M-50__part14","DYJetsToLL_M-50__part15","DYJetsToLL_M-50__part16","DYJetsToLL_M-50__part17","DYJetsToLL_M-50__part18","DYJetsToLL_M-50__part19","DYJetsToLL_M-50__part20","WJetsToLNu-LO__part0","WJetsToLNu-LO__part1","WJetsToLNu-LO__part2"} 

CHANNEL={"ele","mu"}


for s in SAMPLES:
	for ch in CHANNEL:
		print 'bsub -q 2nd -u alvareza submit_batch_FR.sh ' + s + '  ' + ch 
