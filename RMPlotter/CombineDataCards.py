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
    
    
    bb='SR='+dirname+'/MonoHFatJetSelection_JetAndLeptonVeto_DataCard_M'+(str(massvec[imass]))+'GeV_MonoHbb_13TeV.txt '
    znunu='ZbCR='+dirname+'/ZLight_DataCard_M'+(str(massvec[imass]))+'GeV_MonoHbb_13TeV.txt '
    wjets='WbCR='+dirname+'/WHeavy_DataCard_M'+(str(massvec[imass]))+'GeV_MonoHbb_13TeV.txt '
    rateparm='rateparam.txt'
    #ttbar='TTCR='+dirname+'TTBar/DataCard_M'+(str(massvec[imass]))+'GeV_MonoHbb_13TeV.txt '
    
    #allcards=bb+znunu+ttbar+wjets
    allcards=bb+znunu+wjets
    
    splusbdir    = dirname+'/SPlusB/'
    #splusbFitdir = dirname+'/SPlusBFit/'
    os.system('mkdir '+splusbdir)
    #os.system('mkdir '+splusbFitdir)
    
    #splusbdir    = dirname
    splusbFitdir = dirname
    
    datacardname=splusbdir+'/DataCard_S_Plus_B_M'+(str(massvec[imass]))+'GeV_MonoHbb_13TeV.txt'
    datacardnamefit=splusbFitdir+'/DataCard_S_Plus_B_M'+(str(massvec[imass]))+'GeV_MonoHbb_13TeV.txt'
    os.system('combineCards.py  '+allcards+' >& '+datacardname)
    
    tmpdcard = 'tmpcard.txt'
    dcard = open(datacardname,'r')
    dcardnew = open(tmpdcard ,'w')
    
    for line in dcard:
        line = line.replace(dirname+'/','')
        line = line.replace('kmax 46','kmax 48')
        dcardnew.write(line)
        
        
    dcard.close()
    dcardnew.close()
    
    os.system('cat '+tmpdcard+' '+rateparm+' >& '+  datacardnamefit)
    
    #os.system('mv ')

