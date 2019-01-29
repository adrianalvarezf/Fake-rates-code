
THIS README IS OUTDATED , I no longer use mkShapes

# How to use: 

Important note: This code does not work by itself, you need to have the latinos code (it uses mkShapes.py).

Copy the folders in your_directory/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/    (git clone https://github.com/adrianalvarezf/Fake-rates-code)

In CMSSW_9_4_7/src , write "cmsenv"

Then, move to one of the folders, e.g. code_electron_fakes , and write:

mkShapes.py --pycfg=configuration_fakes.py --inputDir=/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Study2017/MCl1loose2017__baseW__hadd/   --doBatch=True --batchSplit=AsMuchAsPossible --batchQueue=8nh

This will send the jobs to batch. Use "bjobs" to check the progress and after it is done you can add the rootfiles:

mkShapes.py --pycfg=configuration_fakes.py --inputDir=/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano/Fall2017_nAOD_v1_Study2017/MCl1loose2017__baseW__hadd/   --doHadd=True --batchSplit=AsMuchAsPossible 

And use the programs that make the plots, dividing the histograms:

root -q -b "division_forfakes.C()"



