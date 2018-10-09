# cuts

#cuts = {}
# && (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele8_CaloIdM_TrackIdM_PFJet30 || HLT_Ele17_CaloIdM_TrackIdM_PFJet30 || HLT_Ele23_CaloIdM_TrackIdM_PFJet30) \

#&& (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30) \
supercut = 'nLepton>1 \
            && Lepton_pdgId[0]*Lepton_pdgId[1]==-11*11 \
            && (Lepton_pt[0]>25 && fabs(Lepton_eta[0])<2.5) \
            && (Lepton_pt[1]>13 && fabs(Lepton_eta[1])<2.5) \
            && Electron_mvaFall17Iso_WP80[Lepton_electronIdx[0]] \
            && Electron_dz[Lepton_electronIdx[0]]< 0.1 \
            && ((Electron_pt[Lepton_electronIdx[0]]>20 && Electron_dxy[Lepton_electronIdx[0]]< 0.02)||(Electron_pt[Lepton_electronIdx[0]]<=20 && Electron_dxy[Lepton_electronIdx[0]]< 0.01)) \
            && mll<106 && mll>76 \
            '            
         

#Numerators
cuts['numerator']  = 'Lepton_electronIdx[1]>=0 && Electron_mvaFall17Iso_WP80[Lepton_electronIdx[1]]  \
                      && Electron_dz[Lepton_electronIdx[1]]< 0.1 \
                      && ((Electron_pt[Lepton_electronIdx[1]]>20 && Electron_dxy[Lepton_electronIdx[1]]< 0.02)||(Electron_pt[Lepton_electronIdx[1]]<=20 && Electron_dxy[Lepton_electronIdx[1]]< 0.01)) \
                     ' 

#Denominators
cuts['denominator'] = 'Lepton_electronIdx[1]>=0'



