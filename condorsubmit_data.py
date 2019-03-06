import os
import sys


def submit():
	if len(sys.argv)==1 :
		print "You need to provide the year as an argument"
		return 1	
        SAMPLESMU= set()
        SAMPLESELE= set()
	
	year =	sys.argv[1]

	if year == "2016":
		for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2016_94X_nAODv3_Full2016v2/DATAl1loose2016__fakeSel/"):   #2016
			if   'DoubleMuon_Run2016' in ii : SAMPLESMU.add(ii)
                        elif 'DoubleEG_Run2016' in ii : SAMPLESELE.add(ii)
 
	if year == "2017":
		for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2017_nAOD_v1_Full2017v2/DATAl1loose2017v2__DATACorr2017__fakeSel/"):   #2017
			if   'DoubleMuon_Run2017' in ii and '2017B' not in ii: SAMPLESMU.add(ii)
			elif 'SingleElectron_Run2017' in ii and '2017B' not in ii: SAMPLESELE.add(ii)

	if year == "2018":
		for ii in os.listdir("/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Run2018_102X_nAODv4_14Sep_Full2018/DATAl1loose2018__fakeSel/"):          #2018      
			if   'DoubleMuon_Run2018' in ii : SAMPLESMU.add(ii)
			elif 'EGamma_Run2018'     in ii : SAMPLESELE.add(ii)
		
	
        print "Data file list loaded..."
	print " Year ", year
	print " Number of muon data files ", len(SAMPLESMU)
	print " Number of electron data files ", len(SAMPLESELE)

	outputDir="/afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code/jobscondor/"
        queue="tomorrow"
	musamples=0
        elesamples=0
	
	for s in SAMPLESMU:
		CH="mu"
		jobFileName = outputDir+s[:-5]+"_"+CH+"_FR.sh"
		subFileName = outputDir+s[:-5]+"_"+CH+"_FR.sub"
		errFileName = outputDir+s[:-5]+"_"+CH+"_FR.err"
		outFileName = outputDir+s[:-5]+"_"+CH+"_FR.out"
		logFileName = outputDir+s[:-5]+"_"+CH+"_FR.log"
		jidFileName = outputDir+s[:-5]+"_"+CH+"_FR.jid"

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
		CH="ele"
		jobFileName = outputDir+s[:-5]+"_"+CH+"_FR.sh"
		subFileName = outputDir+s[:-5]+"_"+CH+"_FR.sub"
		errFileName = outputDir+s[:-5]+"_"+CH+"_FR.err"
		outFileName = outputDir+s[:-5]+"_"+CH+"_FR.out"
		logFileName = outputDir+s[:-5]+"_"+CH+"_FR.log"
		jidFileName = outputDir+s[:-5]+"_"+CH+"_FR.jid"

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
