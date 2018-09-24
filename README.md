# How to use: 

Important note: This code does not work by itself, you need to have the latinos code (it uses mkShapes.py).

Copy the folders in your_directory/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/ 

In CMSSW_9_4_7/src , write:   eval `scramv1 runtime -sh`

-hen, move to one of the folders, e.g. code_electron_fakes , and write:

mkShapes.py --pycfg=configuration_fakes.py --inputDir=/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Study2017/MCl1loose2017__baseW__hadd/   --doBatch=True --batchSplit=AsMuchAsPossible --batchQueue=8nh

This will send the jobs to batch. After it is done you can hadd the rootfiles:

mkShapes.py --pycfg=configuration_fakes.py --inputDir=/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Study2017/MCl1loose2017__baseW__hadd/   --doHadd=True --batchSplit=AsMuchAsPossible 

And use the programs that make the plots, dividing the histograms:

root -q -b "division_forfakes.C(\"Iso_WP80\")"
(For the rest of the programs you don't need any arguments, e.g. root -q -b "division_promptfakes.C()" ).

