# cuts

#cuts = {}
# && (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele8_CaloIdM_TrackIdM_PFJet30 || HLT_Ele17_CaloIdM_TrackIdM_PFJet30 || HLT_Ele23_CaloIdM_TrackIdM_PFJet30) \

#&& (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30) \
supercut = 'nLepton>1 \
            && HLT_Ele35_WPTight_Gsf \
            && nElectron>1 \
            && Lepton_electronIdx[0]>=0 && Lepton_electronIdx[1]>=0 \
            && (Lepton_pt[0]>35 && fabs(Lepton_eta[0])<2.5) \
            && (Lepton_pt[1]>13 && fabs(Lepton_eta[1])<2.5) \
            && Electron_mvaFall17Iso_WP80[Lepton_electronIdx[0]] \
            && Electron_dz[Lepton_electronIdx[0]]< 0.1 \
            && ((Electron_pt[Lepton_electronIdx[0]]>20 && Electron_dxy[Lepton_electronIdx[0]]< 0.02)||(Electron_pt[Lepton_electronIdx[0]]<=20 && Electron_dxy[Lepton_electronIdx[0]]< 0.01)) \
            && mll<110 && mll>70 \
            '            
         

#Numerators
cuts['numerator']  = 'Lepton_electronIdx[1]>=0 && Electron_mvaFall17Iso_WP80[Lepton_electronIdx[1]]  \
                      && Electron_dz[Lepton_electronIdx[1]]< 0.1 \
                      && ((Electron_pt[Lepton_electronIdx[1]]>20 && Electron_dxy[Lepton_electronIdx[1]]< 0.02)||(Electron_pt[Lepton_electronIdx[1]]<=20 && Electron_dxy[Lepton_electronIdx[1]]< 0.01)) \
                     ' 

#Denominators
cuts['denominator'] = 'Lepton_electronIdx[0]>=0'



