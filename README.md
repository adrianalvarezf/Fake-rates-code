
# How to get the fake rates: 

  python condorsubmit_mc.py 

(or data) will send the jobs to condor. All the related code is in Fake_rates.C .

Then you use script_hadd.sh to merge the files and with 

  root -q  division_forfakes_jetbins.C

you get the plots. 



