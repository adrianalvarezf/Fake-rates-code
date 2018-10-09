# cuts

#cuts = {}

#jetcut = '(nCleanJet>0 && CleanJet_pt[0]>25 && fabs(CleanJet_phi[0]-Lepton_phi[0])>1)'
#morecuts ='||(nCleanJet>{0} && CleanJet_pt[{0}]>25 && fabs(CleanJet_phi[{0}]-Lepton_phi[0])>1)'
#for i in range(1,10) :
#    jetcut +=morecuts.format(i)
    
# && (HLT_Mu17_TrkIsoVVL || HLT_Mu8_TrkIsoVVL) \
supercut = 'nLepton==1 \
            && MET_pt<20 \
            && mtw1<20 \
            && abs(Lepton_pdgId[0]) == 13 \
            && (Lepton_pt[0]>=10 && fabs(Lepton_eta[0])<=2.4) \
            && ((Lepton_pt[0] <= 20. && HLT_Mu8_TrkIsoVVL > 0.5) || (Lepton_pt[0] > 20. && HLT_Mu17_TrkIsoVVL > 0.5)) \
            && (nCleanJet>0 && CleanJet_pt[0]>25. && sqrt((CleanJet_phi[0]-Lepton_phi[0])*(CleanJet_phi[0]-Lepton_phi[0])+(CleanJet_eta[0]-Lepton_eta[0])*(CleanJet_eta[0]-Lepton_eta[0]))>1.) \
           '
          # && '+jetcut+'\
          #'
#|| (nCleanJet>1 && CleanJet_pt[1]>25 && fabs(CleanJet_phi[1]-Lepton_phi[0])>1) || (nCleanJet>2 && CleanJet_pt[2]>25 && fabs(CleanJet_phi[2]-Lepton_phi[0])>1) || (nCleanJet>3 && CleanJet_pt[3]>25 && fabs(CleanJet_phi[3]-Lepton_phi[0])>1) || (nCleanJet>4 && CleanJet_pt[4]>25 && fabs(CleanJet_phi[4]-Lepton_phi[0])>1) ||  (nCleanJet>5 && CleanJet_pt[5]>25 && fabs(CleanJet_phi[5]-Lepton_phi[0])>1) || (nCleanJet>6 && CleanJet_pt[6]>25 && fabs(CleanJet_phi[6]-Lepton_phi[0])>1)  || (nCleanJet>7 && CleanJet_pt[7]>25 && fabs(CleanJet_phi[7]-Lepton_phi[0])>1)  || (nCleanJet>8 && CleanJet_pt[8]>25 && fabs(CleanJet_phi[8]-Lepton_phi[0])>1)  || (nCleanJet>9 && CleanJet_pt[9]>25 && fabs(CleanJet_phi[9]-Lepton_phi[0])>1))  \
#           '
             

#Numerators
cuts['numerator']  = 'Lepton_muonIdx[0]>=0 && Lepton_isTightMuon_cut_Tight80x_HWWW[0]'

#Denominators
cuts['denominator'] = 'Lepton_muonIdx[0]>=0'


