import os
import sys


def submit():
	SAMPLESMU= set()
        SAMPLESELE= set()

	#for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2017_nAOD_v1_Full2017v2/DATAl1loose2017v2__DATACorr2017__fakeSel/"):   #2017
        #        if   'DoubleMuon_Run2017' in ii and '2017B' not in ii: SAMPLESMU.add(ii)
        #        elif 'SingleElectron_Run2017' in ii and '2017B' not in ii: SAMPLESELE.add(ii)
	for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2018_102X_nAODv4_14Sep_Full2018/DATAl1loose2018__fakeSel/"):          #2018      
		if   'DoubleMuon_Run2018' in ii : SAMPLESMU.add(ii)
                elif 'EGamma_Run2018'     in ii : SAMPLESELE.add(ii)
		
	
        print "Data file list loaded..."

	outputDir="/afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code/jobscondor/"
        queue="tomorrow"
	musamples=0
        elesamples=0
	
	for s in SAMPLESMU:
		if '2017' in s: year="2017"
		elif '2018' in s: year="2018"
		CH="mu"
		jobFileName = outputDir+s[:-5]+"_"+CH+".sh"
		subFileName = outputDir+s[:-5]+"_"+CH+".sub"
		errFileName = outputDir+s[:-5]+"_"+CH+".err"
		outFileName = outputDir+s[:-5]+"_"+CH+".out"
		logFileName = outputDir+s[:-5]+"_"+CH+".log"
		jidFileName = outputDir+s[:-5]+"_"+CH+".jid"

		jobFile = open(jobFileName, "w+")
		jobFile.write("#!/bin/sh \n")
		jobFile.write("cd /afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code \n")
		jobFile.write("eval `scramv1 runtime -sh` \n")
		jobFile.write("root -l -b -q 'Fake_rates.C(\"" + s +"\",\""+CH+"\",\""+year+"\")'")
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
		musamples+=1
	print "muon data submission finished, "+ str(musamples) +" jobs have been submitted. \n"
	
	for s in SAMPLESELE:
		if '2017' in s: year="2017"
		elif '2018' in s: year="2018"
		CH="ele"
		jobFileName = outputDir+s[:-5]+"_"+CH+".sh"
		subFileName = outputDir+s[:-5]+"_"+CH+".sub"
		errFileName = outputDir+s[:-5]+"_"+CH+".err"
		outFileName = outputDir+s[:-5]+"_"+CH+".out"
		logFileName = outputDir+s[:-5]+"_"+CH+".log"
		jidFileName = outputDir+s[:-5]+"_"+CH+".jid"

		jobFile = open(jobFileName, "w+")
		jobFile.write("#!/bin/sh \n")
		jobFile.write("cd /afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code \n")
		jobFile.write("eval `scramv1 runtime -sh` \n")
		jobFile.write("root -l -b -q 'Fake_rates.C(\"" + s +"\",\""+CH+"\",\""+year+"\")'")
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
		print subFileName ," submitted"
		elesamples+=1
	print "electron data submission finished, "+ str(elesamples) +" jobs have been submitted. \n"


if __name__ == "__main__":
    submit()
