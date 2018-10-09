
# variables

#variables = {}
    
#'fold' : # 0 = not fold (default), 1 = fold underflowbin, 2 = fold overflow bin, 3 = fold underflow and overflow
   
variables['events']  = { 'name': '1',      
                         'range' : (1,0,2),  
                         'xaxis' : 'events', 
                         'fold' : 3
                        }

#variables['dphill'] = { 'name': 'dphill',
#                        'range' : (20,-3.2,3.2),
#                        'xaxis' : 'dphi_{ll}',
#                        'fold' : 0
#                        }

variables['ele_pt2']  = {   'name': 'Lepton_pt[1]',     
                        'range' : (8,10,50),   
                        'xaxis' : 'p_{T} 2nd electron',
                        'fold'  : 0                         
                        }

###variables['pt2']  = {   'name': 'Lepton_pt[1]',     
#                        'range' : (25,0,50),   
#                        'xaxis' : 'p_{T} 2nd lep',
#                        'fold'  : 0                         
#                        }

variables['abs_ele_eta2']  = {  'name': 'fabs(Lepton_eta[1])',     
                        'range' : (5,0,2.5),   
                        'xaxis' : 'eta 2nd electron',
                        'fold'  : 0                         
                        }

#variables['eta2_vs_pt2']  = {  'name': 'Electron_pt[Lepton_electronIdx[1]]', 'fabs(Electron_eta[Lepton_electronIdx[1]])',     
#                        'range' : (8,10,50),(5,0,2.5),   
#                        'xaxis' : 'p_{T} 2nd electron',
#                        'yaxis' : 'eta 2nd electron',
#                        'fold'  : 0                         
#                        }

#variables['mllVSmth'] = {   'name': 'mll:mth',          
#                        'range' : (300,0,200, 100,0,200),            
#                        'xaxis' : 'm_{ll} : m_{T}^{H}',   
#                         'fold' : 3
#                        }

#variables['eta2']  = {  'name': 'Lepton_eta[1]',     
#                        'range' : (25,-2.5,2.5),   
#                        'xaxis' : 'eta 2nd lep',
#                        'fold'  : 0                         
 #                       }

#variables['mll']  = {   'name': 'mll',            #   variable name    
#                        'range' : (20,10,200),    #   variable range
#                        'xaxis' : 'm_{ll} [GeV]',  #   x axis name
#                        'fold' : 0
#                        }

#variables['mth']  = {   'name': 'mth',            #   variable name    
#                        'range' : (10,60,200),    #   variable range
#                        'xaxis' : 'm_{T}^{H} [GeV]',  #   x axis name
#                        'fold' : 0
#                        }

#variables['ptll']  = {  'name': 'ptll',            #   variable name
#                        'range' : (20,30,200),    #   variable range
#                        'xaxis' : 'ptll [GeV]',  #   x axis name
#                        'fold' : 3
#                        }
                        
#variables['met']  = {   'name': 'MET_pt',            #   variable name    
#                        'range' : (20,0,200),    #   variable range
#                        'xaxis' : 'pfmet [GeV]',  #   x axis name
#                        'fold' : 0
#                        }

#variables['dphiele1j1']  = {   'name': 'fabs(Jet_phi[0]-Electron_phi[0])',  #   variable name    
#                        'range' : (20,0,3.2),    #   variable range
#                        'xaxis' : 'delta phi ele1 jet1',  #   x axis name
#                        'fold' : 0
#                        }
