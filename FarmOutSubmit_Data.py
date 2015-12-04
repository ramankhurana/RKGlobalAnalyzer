import os
outputdirname="DYNew20150805_New/"
inputprefix="--input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/"
cmsswpath="/afs/hep.wisc.edu/cms/khurana/Monika/CMSSW_7_4_5"
exepath="/afs/hep.wisc.edu/cms/khurana/Monika/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe"

fout = open("samplestorun.txt","w")

## list of samples will appear here. 
samples='''SingleElectron_Run2015B-PromptReco-v2 SingleElectron/crab_SingleElectron_Run2015B-PromptReco-v1_WZJSON_V2 
'''

fout.write(samples)
fout.close()

f = open('samplestorun.txt','r')
for line in f:
    a,b = line.split()
    datasetdet=[a,b]
    #os.system("farmoutAnalysisJobs "+outputdirname+"datasetdet[0] "+inputprefix+datasetdet[1]+cmsswpath+exepath+" --fwklite --input-files-per-job=1")
    jobcommand = ("farmoutAnalysisJobs "+outputdirname+datasetdet[0]+" "+inputprefix+datasetdet[1]+" "+cmsswpath+" "+exepath+" --fwklite --input-files-per-job=1000")
    print "submitting jobs for"+datasetdet[0]
    os.system(jobcommand)
### Monika Files
### SingleElectron/crab_SingleElectron_Run2015B-PromptReco-v1_WZJSON_V1/ // 40 pb
### SingleElectron/crab_SingleElectron_Run2015B-PromptReco-v1_WZJSON_V2/ // 7pb

###1_JSON/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=5
###
###isc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=5
#farmoutAnalysisJobs DMHistosRun2015B_19July/SingleElectron_2015_07_19_1 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/SingleElectron/crab_SingleElectron_Run2015B-PromptReco-v1_1/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=5
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_2015_07_19 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_HLT/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/WZ_TuneCUETP8M1_13TeV-pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/WZ_TuneCUETP8M1_13TeV-pythia8/crab_WZ_TuneCUETP8M1_13TeV-pythia8/150713_082013/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/ZZ_TuneCUETP8M1_13TeV-pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/ZZ_TuneCUETP8M1_13TeV-pythia8/crab_ZZ_TuneCUETP8M1_13TeV-pythia8/150713_081913/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/WW_TuneCUETP8M1_13TeV-pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/WW_TuneCUETP8M1_13TeV-pythia8/crab_WW_TuneCUETP8M1_13TeV-pythia8/150713_081813/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/150713_081712/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/150713_081609/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_470to600_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_470to600_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_50to80_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_50to80_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_2400to3200_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_2400to3200_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_1800to2400_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_1800to2400_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_1400to1800_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_1400to1800_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_600to800_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_600to800_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_10to15_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_10to15_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_15to30_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_15to30_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_80to120_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_80to120_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_800to1000_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_800to1000_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_3200toInf_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_3200toInf_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_120to170_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_120to170_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
####
####farmoutAnalysisJobs DMHistosRun2015B_19July/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8 --input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8 /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/ /afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe --fwklite --input-files-per-job=1
