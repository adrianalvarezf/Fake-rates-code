# cuts

#cuts = {}
# && (HLT_Ele8_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30 || HLT_Ele8_CaloIdM_TrackIdM_PFJet30 || HLT_Ele17_CaloIdM_TrackIdM_PFJet30 || HLT_Ele23_CaloIdM_TrackIdM_PFJet30) \

#            && (Lepton_pt[0]>10 && fabs(Lepton_eta[0])<2.5) \
supercut = 'nLepton>0 \
            && (HLT_Mu17_TrkIsoVVL || HLT_Mu8_TrkIsoVVL) \
            && MET_pt<20 \
            && mtw1<20 \
            && nMuon>0 \
            && Lepton_muonIdx[0]>=0 \
            && (Lepton_pt[0]>10 && fabs(Lepton_eta[0])<2.5) \
            && (nLepton==1 || Lepton_pt[1]<10) \
            && (nCleanJet>0 && CleanJet_pt[0]>25 && fabs(CleanJet_phi[0]-Lepton_phi[0])>1) \
            '
#&& (nJet<2 || fabs(Jet_phi[1]-Lepton_phi[0])>1) \
#&& (nJet<3 || fabs(Jet_phi[2]-Lepton_phi[0])>1) \
#&& (nJet<4 || fabs(Jet_phi[3]-Lepton_phi[0])>1) \
#&& (nJet<5 || fabs(Jet_phi[4]-Lepton_phi[0])>1) \
#&& (nJet<6 || fabs(Jet_phi[5]-Lepton_phi[0])>1) \
#&& (nJet<7 || fabs(Jet_phi[6]-Lepton_phi[0])>1) \
#&& (nJet<8 || fabs(Jet_phi[7]-Lepton_phi[0])>1) \
#&& (nJet<9 || fabs(Jet_phi[8]-Lepton_phi[0])>1) \
#&& (nJet<10 || fabs(Jet_phi[9]-Lepton_phi[0])>1) \
#'
#
                        

#Numerators
#cuts['Electron_mvaFall17noIso']       = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17noIso[Lepton_electronIdx[0]]'
#cuts['Electron_mvaFall17noIso_WP80']  = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17noIso_WP80[Lepton_electronIdx[0]]'
#cuts['Electron_mvaFall17noIso_WP90']  = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17noIso_WP90[Lepton_electronIdx[0]]'
#cuts['Electron_mvaFall17noIso_WPL']   = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17noIso_WPL[Lepton_electronIdx[0]]'

#cuts['Electron_mvaFall17Iso']       = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17Iso[Lepton_electronIdx[0]]'
cuts['numerator']  = 'Lepton_muonIdx[0]>=0 && Lepton_isTightMuon_cut_Tight80x_HWWW[0]'
#cuts['Electron_mvaFall17Iso_WP90']  = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17Iso_WP90[Lepton_electronIdx[0]]'
#cuts['Electron_mvaFall17Iso_WPL']   = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17Iso_WPL[Lepton_electronIdx[0]]'

#Denominators
cuts['denominator'] = 'Lepton_muonIdx[0]>=0'



#Numerators
#cuts['Electron_mvaFall17noIso_barrel']       = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17noIso[Lepton_electronIdx[0]]       && fabs(Lepton_eta[0]) <1.479'
#cuts['Electron_mvaFall17noIso_WP80_barrel']  = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17noIso_WP80[Lepton_electronIdx[0]]  && fabs(Lepton_eta[0]) <1.479'
#cuts['Electron_mvaFall17noIso_WP90_barrel']  = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17noIso_WP90[Lepton_electronIdx[0]]  && fabs(Lepton_eta[0]) <1.479'
#cuts['Electron_mvaFall17noIso_WPL_barrel']   = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17noIso_WPL[Lepton_electronIdx[0]]   && fabs(Lepton_eta[0]) <1.479'

#cuts['Electron_mvaFall17Iso_barrel']       = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17Iso[Lepton_electronIdx[0]]       && fabs(Lepton_eta[0]) <1.479'
#cuts['Electron_mvaFall17Iso_WP80_barrel']  = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17Iso_WP80[Lepton_electronIdx[0]]  && fabs(Lepton_eta[0]) <1.479'
#cuts['Electron_mvaFall17Iso_WP90_barrel']  = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17Iso_WP90[Lepton_electronIdx[0]]  && fabs(Lepton_eta[0]) <1.479'
#cuts['Electron_mvaFall17Iso_WPL_barrel']   = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17Iso_WPL[Lepton_electronIdx[0]]   && fabs(Lepton_eta[0]) <1.479'

#cuts['Electron_mvaFall17noIso_endcap']       = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17noIso[Lepton_electronIdx[0]]       && fabs(Lepton_eta[0]) <1.479'
#cuts['Electron_mvaFall17noIso_WP80_endcap']  = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17noIso_WP80[Lepton_electronIdx[0]]  && fabs(Lepton_eta[0]) <1.479'
#cuts['Electron_mvaFall17noIso_WP90_endcap']  = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17noIso_WP90[Lepton_electronIdx[0]]  && fabs(Lepton_eta[0]) <1.479'
#cuts['Electron_mvaFall17noIso_WPL_endcap']   = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17noIso_WPL[Lepton_electronIdx[0]]   && fabs(Lepton_eta[0]) <1.479'

#cuts['Electron_mvaFall17Iso_endcap']       = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17Iso[Lepton_electronIdx[0]]       && fabs(Lepton_eta[0]) <1.479'
#cuts['Electron_mvaFall17Iso_WP80_endcap']  = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17Iso_WP80[Lepton_electronIdx[0]]  && fabs(Lepton_eta[0]) <1.479'
#cuts['Electron_mvaFall17Iso_WP90_endcap']  = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17Iso_WP90[Lepton_electronIdx[0]]  && fabs(Lepton_eta[0]) <1.479'
#cuts['Electron_mvaFall17Iso_WPL_endcap']   = 'Lepton_electronIdx[0]>=0 && Electron_mvaFall17Iso_WPL[Lepton_electronIdx[0]]   && fabs(Lepton_eta[0]) <1.479'

#Denominators
#cuts['barrel'] = 'Lepton_electronIdx[0]>=0 && fabs(Lepton_eta[0]) <1.479'
#cuts['endcap'] = 'Lepton_electronIdx[0]>=0 && fabs(Lepton_eta[0]) >1.479'

