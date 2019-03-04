import os
import sys


def submit():
	if len(sys.argv)==1 :
                print "You need to provide the year as an argument"
                return 1

	SAMPLESMC= set()
	
	year =  sys.argv[1]
	#year="2017"
        if year=="2016":
		for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Summer16_94X_nAODv3_Full2016v2/MCl1loose2016__MCCorr2016__fakeSelMC/"):        #2016
                        if '_DYJetsToLL_M-50_ext2__' in ii : SAMPLESMC.add(ii)
                        elif '_WJetsToLNu__' in ii : SAMPLESMC.add(ii)
			
	if year=="2017":
                for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Full2017v2/MCl1loose2017v2__MCCorr2017__btagPerEvent/"):        #2017
			if '_DYJetsToLL_M-50__' in ii : SAMPLESMC.add(ii)
			elif '_WJetsToLNu-LO__' in ii : SAMPLESMC.add(ii) 
			elif '_TTToSemiLeptonic__' in ii : SAMPLESMC.add(ii) 

	print "MC file list loaded..."		
	print " Year " ,year
	print " Number of files ", len(SAMPLESMC)

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
			jobFile.write("root -l -b -q 'Fake_rates.C(\"" + s +"\",\""+ ch+"\",\""+ year +"\")'")
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
