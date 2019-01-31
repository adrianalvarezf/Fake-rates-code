import os
import sys


def submit():
	SAMPLESMC= set()
	
	for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017v2__MCCorr2017/"):
		
		if 'DYJetsToLL_M-50__' in ii : SAMPLESMC.add(ii)
		elif 'WJetsToLNu-LO__' in ii : SAMPLESMC.add(ii) 

	print "MC file list loaded..."		

	CHANNEL={"ele","mu"}
	outputDir="/afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code/jobscondor/"
	queue="tomorrow"
	mcsamples=0

	for s in SAMPLESMC:
		for ch in CHANNEL:

			jobFileName = outputDir+s[:-5]+"_"+ch+".sh"
			subFileName = outputDir+s[:-5]+"_"+ch+".sub"
			errFileName = outputDir+s[:-5]+"_"+ch+".err"
			outFileName = outputDir+s[:-5]+"_"+ch+".out"
			logFileName = outputDir+s[:-5]+"_"+ch+".log"
			jidFileName = outputDir+s[:-5]+"_"+ch+".jid"

			jobFile = open(jobFileName, "w+")
			jobFile.write("#!/bin/sh \n")
			jobFile.write("cd /afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code \n")
			jobFile.write("eval `scramv1 runtime -sh` \n")
			jobFile.write("root -l -b -q 'Fake_rates.C(\"" + s +"\",\""+ ch+"\")'")
			jobFile.close()

			subFile = open(subFileName, "w+")
			subFile.write('executable = '+jobFileName+'\n')
			subFile.write('universe = vanilla\n')
			subFile.write('output = '+ outFileName +'\n')
			subFile.write('error = '+ errFileName +'\n')
			subFile.write('log = '+ logFileName +'\n')
			subFile.write('+JobFlavour  = '+ queue +'\n')
			subFile.write('queue \n')
			subFile.close()

			os.system('condor_submit '+subFileName+' > ' +jidFileName)
			print subFileName , "submitted"
			mcsamples+=1

	print "MC submission finished, "+ str(mcsamples) +" jobs have been submitted. \n"   

if __name__ == "__main__":
    submit()
