from MakeRootFilesForDataCards import *

def RunMakeDataCards(eta, isolation, eveto, Closure):
    MakeHistoMacro("RECREATE","Pass", eta, isolation, eveto, Closure)
    MakeDataCard("Pass", eta,  isolation, eveto , "TemplateDataCard_PASS.txt")
    
    MakeHistoMacro("RECREATE","Fail", eta,  isolation, eveto, Closure)
    MakeDataCard("Fail", eta ,  isolation, eveto , "TemplateDataCard_FAIL.txt")
    return 0.0

#isovector=["LoosedbetaIso","LooseMVAIso"]
isovector=["LoosedbetaIso"]
etavector=["barrel","endcap"]
evetovector=["LooseMVA3EV","MediumMVA3EV","TightMVA3EV","VTightMVA3EV"]

#evetovector=["LooseMVA3EV","MediumMVA3EV","TightMVA3EV","VTightMVA3EV",
#             "LooseEV","MediumEV","TightEV"]

os.system('rm combinecards.sh runlimit.sh')
f = open('combinecards.sh','a')
f.write('cp -r /cmshome/khurana/EleTauFR/CMSSW_5_3_5/src/Scripts/files .  \n')

f1 = open('runlimit.sh','a')

mass=0
for Iisovector in range(len(isovector)):
    for Ietavector in range(len(etavector)):
        for Ievetovector in range(len(evetovector)):
            ## set last variable to 0 for read data instead of closure test
            RunMakeDataCards( etavector[Ietavector], isovector[Iisovector], evetovector[Ievetovector],1)
            f.write('combineCards.py pass=files/Datacard_Pass_'+etavector[Ietavector]+'_'+isovector[Iisovector]+'_'+evetovector[Ievetovector]+'.txt fail=files/Datacard_Fail_'+etavector[Ietavector]+'_'+isovector[Iisovector]+'_'+evetovector[Ievetovector]+'.txt  >& Datacard_PASSFAIL_'+etavector[Ietavector]+'_'+isovector[Iisovector]+'_'+evetovector[Ievetovector]+'.txt \n')
            f1.write('echo \" Datacard_PASSFAIL_'+etavector[Ietavector]+'_'+isovector[Iisovector]+'_'+evetovector[Ievetovector]+'.txt  \" \n')
            f1.write('combine -M MaxLikelihoodFit --saveNormalizations --saveShapes --saveWithUncertainties --oldNormNames Datacard_PASSFAIL_'+etavector[Ietavector]+'_'+isovector[Iisovector]+'_'+evetovector[Ievetovector]+'.txt -m '+str(mass)+' \n')
            f1.write('mv mlfit.root mlfit_'+etavector[Ietavector]+'_'+isovector[Iisovector]+'_'+evetovector[Ievetovector]+'.root  \n')
            mass=mass+1
f.close()
f1.close()
            
            
                     
                  
            



os.system('mv Datacard* files')
os.system('mv *.root    files')
os.system('source CreateBBBHostoForAllFiles.sh files')
os.system('cp combinecards.sh /cmshome/khurana/CMSSW_6_1_2/src/HiggsAnalysis/CombinedLimit/FRCards/')
os.system('cp runlimit.sh     /cmshome/khurana/CMSSW_6_1_2/src/HiggsAnalysis/CombinedLimit/FRCards/')
