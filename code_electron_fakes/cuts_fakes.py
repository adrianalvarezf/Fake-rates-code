# cuts

#cuts = {}

#jetcut = '((nCleanJet>0 && CleanJet_pt[0]>25 && fabs(CleanJet_phi[0]-Lepton_phi[0])>1)'
#morecuts ='||(nCleanJet>{0} && CleanJet_pt[{0}]>25 && fabs(CleanJet_phi[{0}]-Lepton_phi[0])>1)'
#for i in range(1,10) :
#    jetcut +=morecuts.format(i)

#&& (HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30||HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30) \
supercut = 'nLepton==1 \
            && MET_pt<20 \
            && mtw1<20 \
            && abs(Lepton_pdgId[0]) == 11 \
            && (Lepton_pt[0]>13 && fabs(Lepton_eta[0])<2.5) \
            && ((Lepton_pt[0] <= 25. && HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 > 0.5) || (Lepton_pt[0] > 25. && HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 > 0.5)) \
           '
         #   && '+jetcut+')\
         #  '
#|| (nCleanJet>1 && CleanJet_pt[1]>25 && fabs(CleanJet_phi[0]-Lepton_phi[0])>1) || (nCleanJet>2 && CleanJet_pt[2]>25 && fabs(CleanJet_phi[2]-Lepton_phi[0])>1) || (nCleanJet>3 && CleanJet_pt[3]>25 && fabs(CleanJet_phi[3]-Lepton_phi[0])>1) || (nCleanJet>4 && CleanJet_pt[4]>25 && fabs(CleanJet_phi[4]-Lepton_phi[0])>1) ||  (nCleanJet>5 && CleanJet_pt[5]>25 && fabs(CleanJet_phi[5]-Lepton_phi[0])>1) || (nCleanJet>6 && CleanJet_pt[6]>25 && fabs(CleanJet_phi[6]-Lepton_phi[0])>1)  || (nCleanJet>7 && CleanJet_pt[7]>25 && fabs(CleanJet_phi[7]-Lepton_phi[0])>1)  || (nCleanJet>8 && CleanJet_pt[8]>25 && fabs(CleanJet_phi[8]-Lepton_phi[0])>1)  || (nCleanJet>9 && CleanJet_pt[9]>25 && fabs(CleanJet_phi[9]-Lepton_phi[0])>1))  \
#           '
                     

#Numerator
cuts['numerator']  = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17Iso_WP80[Lepton_electronIdx[0]] \
                      && Electron_dz[Lepton_electronIdx[0]]< 0.1 \
                      && ((Electron_pt[Lepton_electronIdx[0]]>20 && Electron_dxy[Lepton_electronIdx[0]]< 0.02)||(Electron_pt[Lepton_electronIdx[0]]<=20 && Electron_dxy[Lepton_electronIdx[0]]< 0.01)) \
                     '

#Denominator
cuts['denominator'] = 'Lepton_electronIdx[0]>=0'


