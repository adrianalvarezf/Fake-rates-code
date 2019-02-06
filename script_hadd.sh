
cd outputsFR_4feb_moreplots

#rm -r TT_mu.root
rm -r WJets_mu.root
rm -r DY_mu.root
rm -r Data_mu.root
#rm -r TT_ele.root
rm -r WJets_ele.root
rm -r DY_ele.root
rm -r Data_ele.root

rm -r QCD_mu.root
rm -r QCD_EM.root
rm -r QCD_DoubleEM.root 

#hadd -f -k TT_mu.root *mu*TTToSemiLeptonic*.root
hadd -f -k WJets_mu.root *mu*WJets*.root
hadd -f -k DY_mu.root *mu*DY*.root
hadd -f -k Data_mu.root *mu*DoubleMuon*.root
#hadd -f -k TT_ele.root *ele*TTToSemiLeptonic*.root
hadd -f -k WJets_ele.root *ele*WJets*.root
hadd -f -k DY_ele.root *ele*DY*.root
hadd -f -k Data_ele.root *ele*SingleElectron*.root

hadd -f -k QCD_mu.root *QCD*Mu*.root
hadd -f -k QCD_DoubleEM.root *QCD*DoubleEM*.root
hadd -f -k QCD_EM.root *QCD*_EM*.root