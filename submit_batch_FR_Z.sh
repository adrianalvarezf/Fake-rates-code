#!/bin/sh

cd `dirname $0`
eval `scramv1 runtime -sh`

SAMPLE=$1

root -l -q -b "/afs/cern.ch/work/a/alvareza/public/CMSSW_9_4_7/src/PlotsConfigurations/Configurations/Fake-rates-code/Fake_ratesZ.C(\"$SAMPLE\")"



