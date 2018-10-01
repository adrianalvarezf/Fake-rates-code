# cuts

#cuts = {}
# && (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele8_CaloIdM_TrackIdM_PFJet30 || HLT_Ele17_CaloIdM_TrackIdM_PFJet30 || HLT_Ele23_CaloIdM_TrackIdM_PFJet30) \

#&& (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30) \
supercut = 'nLepton>1 \
            && HLT_Mu17_TrkIsoVVL \
            && MET_pt<20 \
            && nMuon>1 \
            && Lepton_muonIdx[0]>=0 && Lepton_muonIdx[1]>=0 \
            && (Lepton_pt[0]>20 && fabs(Lepton_eta[0])<2.5) \
            && (Lepton_pt[1]>10 && fabs(Lepton_eta[1])<2.5) \
            && (Lepton_isTightMuon_cut_Tight80x_HWWW[0]>0.5) \
            && mll<110 && mll>70 \
           '            
         

#Numerators
cuts['numerator']  = 'Lepton_muonIdx[1]>=0 && Lepton_isTightMuon_cut_Tight80x_HWWW[1]>0.5'                 

#Denominators
cuts['denominator'] = 'Lepton_muonIdx[0]>=0'



