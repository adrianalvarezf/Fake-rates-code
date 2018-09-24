# cuts

#cuts = {}
# && (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele8_CaloIdM_TrackIdM_PFJet30 || HLT_Ele17_CaloIdM_TrackIdM_PFJet30 || HLT_Ele23_CaloIdM_TrackIdM_PFJet30) \

#&& (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30) \
supercut = 'nLepton>1 \
            && HLT_IsoMu27 \
            && nMuon>1 \
            && Lepton_muonIdx[0]>=0 && Lepton_muonIdx[1]>=0 \
            && (Lepton_pt[0]>30 && fabs(Lepton_eta[0])<2.5) \
            && (Lepton_isTightMuon_cut_Tight80x_HWWW[0]) \
            && (Lepton_pt[1]>10 && fabs(Lepton_eta[1])<2.5) \
            && Muon_dz[Lepton_muonIdx[0]]< 0.1 \
            && ((Muon_pt[Lepton_muonIdx[0]]>20 && Muon_dxy[Lepton_muonIdx[0]]< 0.02)||(Muon_pt[Lepton_muonIdx[0]]<=20 && Muon_dxy[Lepton_muonIdx[0]]< 0.01)) \
            && mll<110 && mll>70 \
            '            
         

#Numerators
cuts['numerator']  = '(Lepton_muonIdx[1]>=0 &&  Lepton_isTightMuon_cut_Tight80x_HWWW[1]) \
                      && Muon_dz[Lepton_muonIdx[1]]< 0.1 \
                      && ((Muon_pt[Lepton_muonIdx[1]]>20 && Muon_dxy[Lepton_muonIdx[1]]< 0.02)||(Muon_pt[Lepton_muonIdx[1]]<=20 && Muon_dxy[Lepton_muonIdx[1]]< 0.01)) \
                     ' 

#Denominators
cuts['denominator'] = 'Lepton_muonIdx[0]>=0'



