
pwd

#btagWP=("")

#for btagbin in ${btagWP[@]} 
#do
cd $1"/outputs"$1 #$btagbin #"btag"
pwd

rm -r WJets_mu.root
rm -r DY_mu.root
rm -r Data_mu.root

rm -r WJets_ele.root
rm -r DY_ele.root
rm -r Data_ele.root

hadd -f -k WJets_mu.root *mu*WJets*.root
hadd -f -k DY_mu.root *mu*DY*.root
hadd -f -k Data_mu.root *mu*DoubleMuon*.root

hadd -f -k WJets_ele.root *ele*WJets*.root
hadd -f -k DY_ele.root *ele*DY*.root

if   [[ $1 == *"2016"* ]]; then
    hadd -f -k Data_ele.root  *ele*DoubleEG*.root        #2016
elif [[ $1 == *"2017"* ]]; then
    hadd -f -k Data_ele.root *ele*SingleElectron*.root   #2017
elif [[ $1 == *"2018"* ]]; then
    hadd -f -k Data_ele.root *ele*EGamma*.root           #2018
fi

cd -
#done
