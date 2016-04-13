import os
import sys
if len(sys.argv) < 2 :
    print "insufficient options provided see help function "
    exit (1)

if len(sys.argv) == 2 :
    print ('You are running limits for '+sys.argv[1]+' case')

inputdir=sys.argv[1]

masspoints=[#'600',
            #'800',
            '1000',
            '1200',
            '1400',
            '1700',
            '2000',
            '2500' ]
#masspoints=['1000']
for imass in range(len(masspoints)):
    #datacardname= inputdir+'/DataCard_M'+str(masspoints[imass])+'GeV_MonoHbb_13TeV.txt'
    #datacardname= inputdir+'/DataCard_M'+str(masspoints[imass])+'GeV_MonoHbb_13TeV.txt'
    datacardname= inputdir+'/DataCard_S_Plus_B_M'+str(masspoints[imass])+'GeV_MonoHbb_13TeV.txt'
    #    datacard_WW_zp1000.txt
    #datacardname= inputdir+'/datacard_WW_zp'+str(masspoints[imass])+'.txt'
    #datacardname= inputdir+'/combine_'+str(masspoints[imass])+'_card.txt'
    #datacardname= inputdir+'/hhxx_Phys14_card_MZP'+str(masspoints[imass])+'.txt'
    print "================="
    print "estimating limit for ",datacardname
    print "================="
    os.system('combine -M Asymptotic '+datacardname+ ' -m '+str(masspoints[imass]))
    print "================="
    print "========moving rootfile to =========",sys.argv[1]
    os.system('mv higgsCombineTest.Asymptotic.mH'+str(masspoints[imass])+'.root '+sys.argv[1])
    print "================="
