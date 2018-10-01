# example of configuration file

date = '_27September_Zenriched_high'

tag = date


# used by mkShape to define output directory for root files
outputDir = 'rootFile'+date


# file with list of variables
variablesFile = 'variables_Zenriched.py'

# file with list of cuts
cutsFile = 'cuts_Zenriched_high.py' 

# file with list of samples
samplesFile = 'samples_Zenriched_high.py' 

# file with list of samples
plotFile = 'plot.py' 



# luminosity to normalize to (in 1/fb)
#lumi = 9.9 #Period C
#lumi = 36.9 #Periods C,D,E and F
lumi = 1 #test
# used by mkPlot to define output directory for plots
# different from "outputDir" to do things more tidy
outputDirPlots = 'plotFakes'+date


# used by mkDatacards to define output directory for datacards
outputDirDatacard = 'datacards'+date


# structure file for datacard
structureFile = 'structure.py'


# nuisances file for mkDatacards and for mkShape
nuisancesFile = 'nuisances_none.py'


