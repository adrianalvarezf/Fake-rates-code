
# How to get the fake rates : 

  python condorsubmit_mc.py 2017

(and condorsubmit_data.mc) will send the jobs to condor. You can also use years 2016 and 2018. All the related code is in Fake_rates.C , but for 2018 MC trigger weights is missing.

Then you use

  ./script_hadd.sh foldername
  
to merge the files and with 

  root -q -b "division_forfakes_withmc.C(\"foldername\")"

you get the plots. 
If there is no MC available or you only want to use data, there is also division_forfakes_dataonly.C , which can also make comparison plots between two years, like 2017 vs 2018. (Not used lately)

Finally, to produce a txt table of yields you can use

  root -q "Tableyields.C(3,\"foldername\")"

(3 is the default and means cut in away jet pt of 25 GeV).  The value in brackets can range from 0 to 7 (10 to 45 GeV).


# Btag update :

Now the FR is computed in bins of btagscore. In condorsubmit you can edit and choose if you want 3 or 4 bins. Then, after the division_forfakes_withmc.C step you can use the treeadder.C program to make the rootfiles with the 2D histograms than then are used in NanoGardener/python/data/ in the latinos' framework:


   root -b -q "treeadder.C(\"mainfoldername\",\"channel\",\"binnumber\")"

Channel must be Ele or Muon for naming consistency and binnumber 4 (bveto,loose,medium,tight) or 3 (bveto,loose,mediumtight).

You can also use the option "none" for btag in condorsubmit if you want to have the inclusive FR with no btag requirement. 
