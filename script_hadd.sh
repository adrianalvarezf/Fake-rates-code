
cd outputsFR_17dec

rm -r WJets_mu.root
rm -r DY_mu.root
rm -r Data_mu.root
rm -r WJets_ele.root
rm -r DY_ele.root
rm -r Data_ele.root

hadd -f -k WJets_mu.root *WJets*mu.root
hadd -f -k DY_mu.root *DY*mu.root
hadd -f -k Data_mu.root *DoubleMuon*mu.root
hadd -f -k WJets_ele.root *WJets*ele.root
hadd -f -k DY_ele.root *DY*ele.root
hadd -f -k Data_ele.root *SingleElectron*ele.root