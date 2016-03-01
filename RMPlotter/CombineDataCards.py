import sys 
import os 
if len(sys.argv) < 2 :
    print "insufficient options provided see help function "
    exit (1)

if len(sys.argv) > 1 :
    print ('You are running limits for ')
    for i in range(len(sys.argv)):
        print sys.argv[i]


dirname=sys.argv[1]
massvec=['600','800','1000','1200','1400','1700','2000','2500']
#massvec=['600']
#os.system('mkdir -p oneplustwo')
for imass in range(len(massvec)):
    
    
    bb='SR='+dirname+'MonoHFatJetSelection_JetAndLeptonVeto/DataCard_M'+(str(massvec[imass]))+'GeV_MonoHbb_13TeV.txt '
    znunu='ZbCR='+dirname+'ZLight/DataCard_M'+(str(massvec[imass]))+'GeV_MonoHbb_13TeV.txt '
    #ttbar='TTCR='+dirname+'TTBar/DataCard_M'+(str(massvec[imass]))+'GeV_MonoHbb_13TeV.txt '
    wjets='WbCR='+dirname+'WHeavy/DataCard_M'+(str(massvec[imass]))+'GeV_MonoHbb_13TeV.txt '
    rateparm='rateparam.txt'
    
    #allcards=bb+znunu+ttbar+wjets
    allcards=bb+znunu+wjets
    
    splusbdir    = dirname+'/SPlusB/'
    splusbFitdir = dirname+'/SPlusBFit/'
    os.system('mkdir '+splusbdir)
    os.system('mkdir '+splusbFitdir)
    
    datacardname=splusbdir+'/DataCard_S_Plus_B_M'+(str(massvec[imass]))+'GeV_MonoHbb_13TeV.txt'
    datacardnamefit=splusbFitdir+'/DataCard_S_Plus_B_M'+(str(massvec[imass]))+'GeV_MonoHbb_13TeV.txt'
    os.system('combineCards.py '+allcards+' >& '+datacardname)
    os.system('cat '+datacardname+' '+rateparm+' >& '+  datacardnamefit)
    

