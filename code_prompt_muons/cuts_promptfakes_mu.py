# cuts

#cuts = {}
# && (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele8_CaloIdM_TrackIdM_PFJet30 || HLT_Ele17_CaloIdM_TrackIdM_PFJet30 || HLT_Ele23_CaloIdM_TrackIdM_PFJet30) \

#&& (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30) \
supercut = 'nLepton>1 \
            && Lepton_pdgId[0]*Lepton_pdgId[1]==-13*13 \
            && (Lepton_pt[0]>25 && fabs(Lepton_eta[0])<2.4) \
            && (Lepton_isTightMuon_cut_Tight80x_HWWW[0]) \
            && (Lepton_pt[1]>10 && fabs(Lepton_eta[1])<2.4) \
            && mll<106 && mll>76 \
            '            
         

#Numerators
cuts['numerator']  = '(Lepton_muonIdx[1]>=0 &&  Lepton_isTightMuon_cut_Tight80x_HWWW[1])' 

#Denominators
cuts['denominator'] = 'Lepton_muonIdx[1]>=0'



