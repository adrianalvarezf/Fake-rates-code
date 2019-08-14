import os
import sys


def submit():
	if len(sys.argv)==1 :
                print "You need to provide the year as an argument"
                return 1

	SAMPLESMC= set()
	
	year =  sys.argv[1]

        if year=="2016":
                for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Summer16_102X_nAODv4_Full2016v5/MCl1loose2016v5__MCCorr2016v5__fakeSelMC/"):        #2016 v5
                        if '_DYJetsToLL_M-50_ext2__' in ii : SAMPLESMC.add(ii)
                        elif '_DYJetsToLL_M-10to50-LO__' in ii : SAMPLESMC.add(ii)

	if year=="2017":
                for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_102X_nAODv4_Full2017v5/MCl1loose2017v5__MCCorr2017v5__fakeSelMC/"):  #2017 v5 
			if '_DYJetsToLL_M-10to50-LO__' in ii : SAMPLESMC.add(ii)
			elif '_DYJetsToLL_M-50__' in ii : SAMPLESMC.add(ii)

	if year=="2018":
		for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Autumn18_102X_nAODv4_GTv16_Full2018v4/MCl1loose2018__MCCorr2018__fakeSelMC/"):    #2018
			if '_DYJetsToLL_M-10to50-LO_-' in ii : SAMPLESMC.add(ii)
			elif '_DYJetsToLL_M-50-LO__' in ii : SAMPLESMC.add(ii)

	print "PR file list loaded..."		
	print " Year " ,year
	print " Number of files ", len(SAMPLESMC)

	CHANNEL={"ele","mu"}
	#CHANNEL={"ele"}
	#CHANNEL={"mu"}

	outputDir="/afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code/jobscondor_pr/"
	queue="tomorrow"
	mcsamples=0

	for s in SAMPLESMC:
		for ch in CHANNEL:

				jobFileName = outputDir+s[:-5]+"_"+ch+"_FR.sh"
				subFileName = outputDir+s[:-5]+"_"+ch+"_FR.sub"
				errFileName = outputDir+s[:-5]+"_"+ch+"_FR.err"
				outFileName = outputDir+s[:-5]+"_"+ch+"_FR.out"
				logFileName = outputDir+s[:-5]+"_"+ch+"_FR.log"
				jidFileName = outputDir+s[:-5]+"_"+ch+"_FR.jid"

				jobFile = open(jobFileName, "w+")
				jobFile.write("#!/bin/sh \n")
				jobFile.write("cd /afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code \n")
				jobFile.write("eval `scramv1 runtime -sh` \n")
				jobFile.write("root -l -b -q 'Prompt_rates.C(\"" + s +"\",\""+ ch+"\",\""+ year +"\")'")
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

	print "PR submission finished, "+ str(mcsamples) +" jobs have been submitted. \n"   

if __name__ == "__main__":
    submit()
