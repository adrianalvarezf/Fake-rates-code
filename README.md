
# How to get the fake rates : 

  python condorsubmit_mc.py 2017

(and condorsubmit_data.mc) will send the jobs to condor. You can also use years 2016 and 2018. All the related code is in Fake_rates.C , but for 2018 MC trigger weights is missing.

Then you use

  ./script_hadd.sh foldername
  
to merge the files and with 

  root -q -b "division_forfakes_withmc.C(\"2017\")"

you get the plots. 
If there is no MC available or you only want to use data, there is also division_forfakes_dataonly.C , which can also make comparison plots between two years, like 2017 vs 2018.

Finally, to produce a txt table of yields you can use

  root -q "Tableyields.C(3)"

(3 is the default and means cut in away jet pt of 25 GeV).  The value in brackets can range from 0 to 7 (10 to 45 GeV).

