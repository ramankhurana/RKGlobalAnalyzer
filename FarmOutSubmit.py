import os
outputdirname="Monika/Electron_SET_SingleDataset_data/"
#inputprefix="--input-dir=root://cmsxrootd.hep.wisc.edu//hdfs/store/user/khurana/"
inputprefix="--input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/"
#inputprefix="--input-dir=/store/user/khurana/"
cmsswpath="/afs/hep.wisc.edu/cms/khurana/Monika/CMSSW_7_4_5/"
exepath="/afs/hep.wisc.edu/cms/khurana/Monika/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe"

fout = open("samplestorun.txt","w")

## list of samples will appear here. 
## 25ns data

mples='''DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToLL/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJets
ToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20151026/
DoubleEG_Run2015C_25ns-05Oct201520160112 DoubleEG/crab_DoubleEG-Run2015C_25ns-05Oct201520160112_FullDataSet_2p2FB_SkipEventsOldFile29Oct/
DoubleEG-Run2015D-05Oct201520160112 DoubleEG/crab_DoubleEG-Run2015D-05Oct201520160112_FullDataSet_2p2FB_SkipEventsOldFile29Oct/     
DoubleEG-Run2015D-PromptReco-V420160112 DoubleEG/crab_DoubleEG-Run2015D-PromptReco-V420160112_FullDataSet_2p2FB_SkipEventsOldFile29Oct/'''
samples='''SingleElectron-Run2015D-05Oct2015 SingleElectron/crab_SingleElectron-Run2015D-05Oct2015-v1_20151117_2p2fb_SingleEleTextFile/
SingleElectron-Run2015D-PromptReco SingleElectron/crab_SingleElectron-Run2015D-PromptReco-V420151117_2p2fb_SingleEleTextFile/'''
ples='''WZ_TuneCUETP8M1_13TeV-pythia8 WZ_TuneCUETP8M1_13TeV-pythia8/crab_WZ_TuneCUETP8M1_13TeV-pythia8_MC25ns_ReMiniAOD_20151026/
ZZ_TuneCUETP8M1_13TeV-pythia8 ZZ_TuneCUETP8M1_13TeV-pythia8/crab_ZZ_TuneCUETP8M1_13TeV-pythia8_MC25ns_ReMiniAOD_20151026/
WW_TuneCUETP8M1_13TeV-pythia8 WW_TuneCUETP8M1_13TeV-pythia8/crab_WW_TuneCUETP8M1_13TeV-pythia8_MC25ns_ReMiniAOD_20151026/
WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026                                                                                                        
WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8  WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/                                                                                                      
WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/                                                                                                       
WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/                                                                                                       
WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/                                                                                                     
WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/                                                                                                   
WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/
WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20151026/
TT_TuneCUETP8M1_13TeV-powheg-pythia8 TT_TuneCUETP8M1_13TeV-powheg-pythia8/crab_TT_TuneCUETP8M1_13TeV-powheg-pythia8_MC25ns_ReMiniAOD_20151105/
DYJetsToTauTau_M-50to200_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToTauTau/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20151026/
DYJetsToTauTau_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToTauTau/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_NewMiniIso_Extended/
DYJetsToTauTau_M-200to400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToTauTau/DYJetsToLL_M-200to400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-200to400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToTauTau_M-400to500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToTauTau/DYJetsToLL_M-400to500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-400to500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToTauTau_M-500to700_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToTauTau/DYJetsToLL_M-500to700_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-500to700_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToTauTau_M-700to800_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToTauTau/DYJetsToLL_M-700to800_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-700to800_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToTauTau_M-800to1000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToTauTau/DYJetsToLL_M-800to1000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-800to1000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToTauTau_M-1500to2000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToTauTau/DYJetsToLL_M-1500to2000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-1500to2000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToTauTau_M-2000to3000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToTauTau/DYJetsToLL_M-2000to3000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-2000to3000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToTauTau_M-1000to1500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToTauTau/DYJetsToLL_M-1000to1500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-1000to1500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8ForMassBinSamples/
DYJetsToEE_M-200to400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToEE/DYJetsToLL_M-200to400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-200to400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToEE_M-400to500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToEE/DYJetsToLL_M-400to500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-400to500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToEE_M-500to700_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToEE/DYJetsToLL_M-500to700_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-500to700_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToEE_M-700to800_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToEE/DYJetsToLL_M-700to800_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-700to800_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToEE_M-800to1000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToEE/DYJetsToLL_M-800to1000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-800to1000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToEE_M-1000to1500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToEE/DYJetsToLL_M-1000to1500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-1000to1500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8ForMassBinSamples/
DYJetsToEE_M-1500to2000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToEE/DYJetsToLL_M-1500to2000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-1500to2000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToEE_M-2000to3000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToEE/DYJetsToLL_M-2000to3000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-2000to3000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20160124/
DYJetsToEE_M-50to200_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToEE/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20151026/
DYJetsToEE_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToEE/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_NewMiniIso_Extended/'''



## 50ns data
#DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_new DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8TreeMaker_MC50ns_1009/
#SingleElectron_Run2015B-PromptReco-v1_50ns SingleElectron/crab_SingleElectron_Run2015B-PromptReco-v1_50ns_20151012/
#SingleElectron_Run2015C-PromptReco-v1_50ns SingleElectron/crab_SingleElectron_Run2015C-PromptReco-v1_50ns_20151012/
#DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8TreeMaker_MC50ns_1009/
#DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8TreeMaker_MC50ns_1009/
#WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8TreeMaker_MC50ns_1009/
#WZ_TuneCUETP8M1_13TeV-pythia8 WZ_TuneCUETP8M1_13TeV-pythia8/crab_WZ_TuneCUETP8M1_13TeV-pythia8TreeMaker_MC50ns_1009/
#ZZ_TuneCUETP8M1_13TeV-pythia8 ZZ_TuneCUETP8M1_13TeV-pythia8/crab_ZZ_TuneCUETP8M1_13TeV-pythia8TreeMaker_MC50ns_1009/
#WW_TuneCUETP8M1_13TeV-pythia8 WW_TuneCUETP8M1_13TeV-pythia8/crab_WW_TuneCUETP8M1_13TeV-pythia8TreeMaker_MC50ns_1009/
#TT_TuneCUETP8M1_13TeV-pythia8 TT_TuneCUETP8M1_13TeV-powheg-pythia8/crab_TT_TuneCUETP8M1_13TeV-powheg-pythia8TreeMaker_MC50ns_1009/
#'''
########
###DoubleEG_Run2015B-PromptReco-v1_31082015_DoubleTrigg_New DoubleEG/crab_DoubleEG_Run2015B-PromptReco-v1_TriggerChanged_07092015/
###'''SingleElectron_Run2015B-TwoRuns_74_diff_RLE_detail SingleElectron/crab_SingleElectron_Run2015B-ReReco_251643_251721_74x_1/
### '''DoubleEG_Run2015B-PromptReco-v1_31082015_DoubleTrigg_No DoubleEG/crab_DoubleEG_Run2015B-PromptReco-v1_31082015/
###SingleElectron_Run2015B-TwoRuns_75_diff_RLE_detail SingleElectron/crab_SingleElectron_Run2015B-ReReco_251643_251721_75x_1/
###'''                                     
#####DoubleEG_Run2015B-PromptReco-v1_0819_JSONV2_Full40  DoubleEG/crab_DoubleEG_Run2015B-PromptReco-v1_0819_JSONV2
####DoubleEG_Run2015B-PromptReco-v1_0819_Full40  DoubleEG/crab_DoubleEG_Run2015B-PromptReco-v1_0819/
####DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_0803/
####DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_0803/
####TT_TuneCUETP8M1_13TeV-powheg-pythia8 TT_TuneCUETP8M1_13TeV-powheg-pythia8/crab_TT_TuneCUETP8M1_13TeV-powheg-pythia8_0803/
####WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_0803/
####WZ_TuneCUETP8M1_13TeV-pythia8 WZ_TuneCUETP8M1_13TeV-pythia8/crab_WZ_TuneCUETP8M1_13TeV-pythia8_0803/
####ZZ_TuneCUETP8M1_13TeV-pythia8 ZZ_TuneCUETP8M1_13TeV-pythia8/crab_ZZ_TuneCUETP8M1_13TeV-pythia8_0803/
####WW_TuneCUETP8M1_13TeV-pythia8 WW_TuneCUETP8M1_13TeV-pythia8/crab_WW_TuneCUETP8M1_13TeV-pythia8_0803/
####'''


fout.write(samples)
fout.close()

###SingleElectron_Run2015B-PromptReco-Full7 SingleElectron/crab_SingleElectron_Run2015B-PromptReco-v1_WZJSON_V3/'''
###SingleElectron_Run2015B-PromptReco-Full40_TM_0815 SingleElectron/crab_SingleElectron_Run2015B-PromptReco-v1_40p6pb_TM_0814/
f = open('samplestorun.txt','r')
for line in f:
    a,b = line.split()
    datasetdet=[a,b]
    #os.system("farmoutAnalysisJobs "+outputdirname+"datasetdet[0] "+inputprefix+datasetdet[1]+cmsswpath+exepath+" --fwklite --input-files-per-job=1")
    jobcommand = ("farmoutAnalysisJobs "+outputdirname+datasetdet[0]+" "+inputprefix+datasetdet[1]+" "+cmsswpath+" "+exepath+" --fwklite --input-files-per-job=5")# --resubmit-failed-jobs")
    print "submitting jobs for"+datasetdet[0]
    os.system(jobcommand)
  ##  --resubmit-failed-jobs
### Monika Files
###
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
