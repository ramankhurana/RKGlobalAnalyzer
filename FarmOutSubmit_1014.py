import os
outputdirname="Raman/AnalysisTuples_V58/"
inputprefix="--input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/"
cmsswpath="/afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/"
exepath="/afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe"

fout = open("samplestorun.txt","w")
##WJetsToLNu_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/



## list of samples will appear here. 
#crab_MET-Run2015D-05Oct2015V120160112_FullDataSet_2p2FB_SkipEventsOldFile29Oct MET/crab_MET-Run2015D-05Oct2015V120160112_FullDataSet_2p2FB_SkipEventsOldFile29Oct/
#crab_MET-Run2015D-PromptReco-V420160112_FullDataSet_2p2FB_SkipEventsOldFile29Oct MET/crab_MET-Run2015D-PromptReco-V420160112_FullDataSet_2p2FB_SkipEventsOldFile29Oct/
#WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/
#ZJetsToNuNu_HT-600ToInf_13TeV-madgraph ZJetsToNuNu_HT-600ToInf_13TeV-madgraph/crab_ZJetsToNuNu_HT-600ToInf_13TeV-madgraphWithJECV7UsingGT/160306_223925/0000/
#crab_MET-Run2015C_25ns-05Oct2015V120160203_FullDataSet_2p2FB_WithoutMETFiltering MET/crab_MET-Run2015C_25ns-05Oct2015V120160203_FullDataSet_2p2FB_WithoutMETFiltering
#crab_MET-Run2015D-05Oct2015V120160203_FullDataSet_2p2FB_WithoutMETFiltering MET/crab_MET-Run2015D-05Oct2015V120160203_FullDataSet_2p2FB_WithoutMETFiltering
#crab_MET-Run2015D-PromptReco-V420160203_FullDataSet_2p2FB_WithoutMETFiltering MET/crab_MET-Run2015D-PromptReco-V420160203_FullDataSet_2p2FB_WithoutMETFiltering

samples='''crab_QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT/160306_222712/ 
crab_QCD_HT200to300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT QCD_HT200to300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT200to300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT/160306_222343/
crab_QCD_HT100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT QCD_HT100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT/160306_222247/
crab_QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT/160306_222527
crab_QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT/160306_222616
crab_QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT/160306_222854
crab_QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT/160306_222432
crab_QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8WithJECV7UsingGT/160306_222759
crab_MET-Run2015D-05Oct2015V120160203_FullDataSet_2p2FB_SkipEventsOldFile29Oct MET/crab_MET-Run2015D-05Oct2015V120160203_FullDataSet_2p2FB_SkipEventsOldFile29Oct
crab_MET-Run2015D-PromptReco-V420160203_FullDataSet_2p2FB_SkipEventsOldFile29Oct MET/crab_MET-Run2015D-PromptReco-V420160203_FullDataSet_2p2FB_SkipEventsOldFile29Oct
crab_MET-Run2015C_25ns-05Oct2015V120160203_FullDataSet_2p2FB_SkipEventsOldFile29Oct MET/crab_MET-Run2015C_25ns-05Oct2015V120160203_FullDataSet_2p2FB_SkipEventsOldFile29Oct
ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1 SingleTopReminiAODSim_20151026/ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1/crab_ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1_MC25ns_ReMiniAOD_20151026/151026_000332
ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1 SingleTopReminiAODSim_20151026/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/crab_ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_MC25ns_ReMiniAOD_20151026/151026_000558/
ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1 SingleTopReminiAODSim_20151026/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1/crab_ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_MC25ns_ReMiniAOD_20151026/151026_000652
ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1 SingleTopReminiAODSim_20151026/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/crab_ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1_MC25ns_ReMiniAOD_20151026/151026_000418
ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1 SingleTopReminiAODSim_20151026/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1/crab_ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1_MC25ns_ReMiniAOD_20151026/151026_000513
WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026
WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8  WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/
WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/
WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/
WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/
WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/
WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 WJetsHTBinSampleReMiniAOD/crab_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026/
ZJetsToNuNu_HT-600ToInf_13TeV-madgraph ZJetsToNuNu_HT_ReMiniAOD/crab_ZJetsToNuNu_HT-600ToInf_13TeV-madgraph_MC25ns_ReMiniAOD_20151026
ZJetsToNuNu_HT-400To600_13TeV-madgraph ZJetsToNuNu_HT_ReMiniAOD/crab_ZJetsToNuNu_HT-400To600_13TeV-madgraph_MC25ns_ReMiniAOD_20151026
ZJetsToNuNu_HT-200To400_13TeV-madgraph ZJetsToNuNu_HT_ReMiniAOD/crab_ZJetsToNuNu_HT-200To400_13TeV-madgraph_MC25ns_ReMiniAOD_20151026
ZJetsToNuNu_HT-100To200_13TeV-madgraph ZJetsToNuNu_HT_ReMiniAOD/crab_ZJetsToNuNu_HT-100To200_13TeV-madgraph_MC25ns_ReMiniAOD_20151026
ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8 ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8/crab_ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8_MC25ns_ReMiniAOD_20151026
ZH_HToBB_ZToNuNu_M120_13TeV_amcatnloFXFX_madspin_pythia8 ZH_HToBB_ZToNuNu_M120_13TeV_amcatnloFXFX_madspin_pythia8/crab_ZH_HToBB_ZToNuNu_M120_13TeV_amcatnloFXFX_madspin_pythia8MC25ns_eleIDjet_CMSSW7412_20151006/
TT_TuneCUETP8M1_13TeV-powheg-pythia8 TT_TuneCUETP8M1_13TeV-powheg-pythia8/crab_TT_TuneCUETP8M1_13TeV-powheg-pythia8_MC25ns_ReMiniAOD_20151105
WZ_TuneCUETP8M1_13TeV-pythia8 WZ_TuneCUETP8M1_13TeV-pythia8/crab_WZ_TuneCUETP8M1_13TeV-pythia8_MC25ns_ReMiniAOD_20151026
ZZ_TuneCUETP8M1_13TeV-pythia8 ZZ_TuneCUETP8M1_13TeV-pythia8/crab_ZZ_TuneCUETP8M1_13TeV-pythia8_MC25ns_ReMiniAOD_20151026/
WW_TuneCUETP8M1_13TeV-pythia8 WW_TuneCUETP8M1_13TeV-pythia8/crab_WW_TuneCUETP8M1_13TeV-pythia8_MC25ns_ReMiniAOD_20151026/
MonoHToBBarMZp-600GeV_MA0-300GeV MonoHToBBarMZp-600GeV_MA0-300GeV//crab_MonoHToBBarMZp-600GeV_MA0-300GeV_MC25ns_ReMiniAOD_20151108/
MonoHToBBarMZp-800GeV_MA0-300GeV MonoHToBBarMZp-800GeV_MA0-300GeV/crab_MonoHToBBarMZp-800GeV_MA0-300GeV_MC25ns_ReMiniAOD_20151108/
MonoHToBBarMZp-1000GeV_MA0-300GeV MonoHToBBarMZp-1000GeV_MA0-300GeV/crab_MonoHToBBarMZp-1000GeV_MA0-300GeV_MC25ns_ReMiniAOD_20151108/
MonoHToBBarMZp-1200GeV_MA0-300GeV MonoHToBBarMZp-1200GeV_MA0-300GeV/crab_MonoHToBBarMZp-1200GeV_MA0-300GeV_MC25ns_ReMiniAOD_20151108/
MonoHToBBarMZp-1400GeV_MA0-300GeV MonoHToBBarMZp-1400GeV_MA0-300GeV/crab_MonoHToBBarMZp-1400GeV_MA0-300GeV_MC25ns_ReMiniAOD_20151108/
MonoHToBBarMZp-1700GeV_MA0-300GeV MonoHToBBarMZp-1700GeV_MA0-300GeV/crab_MonoHToBBarMZp-1700GeV_MA0-300GeV_MC25ns_ReMiniAOD_20151108/
MonoHToBBarMZp-2000GeV_MA0-300GeV MonoHToBBarMZp-2000GeV_MA0-300GeV/crab_MonoHToBBarMZp-2000GeV_MA0-300GeV_MC25ns_ReMiniAOD_20151108/
MonoHToBBarMZp-2500GeV_MA0-300GeV MonoHToBBarMZp-2500GeV_MA0-300GeV/crab_MonoHToBBarMZp-2500GeV_MA0-300GeV_MC25ns_ReMiniAOD_20151108/'''

a='''DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 DYJetsToLL_M-50_HT_ReMiniAOD/DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026
DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 DYJetsToLL_M-50_HT_ReMiniAOD/DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026
DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 DYJetsToLL_M-50_HT_ReMiniAOD/DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026
DYJetsToLL_M-50_HT-600toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 DYJetsToLL_M-50_HT_ReMiniAOD/DYJetsToLL_M-50_HT-600toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-600toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_MC25ns_ReMiniAOD_20151026
MonoHToBBarMZp-600GeV_MA0-300GeV  MonoHSignalTrees_20151012/crab_MonoHToBBarMZp-600GeV_MA0-300GeVTreeMaker_20151012
MonoHToBBarMZp-800GeV_MA0-300GeV  MonoHSignalTrees_20151012/crab_MonoHToBBarMZp-800GeV_MA0-300GeVTreeMaker_20151012
MonoHToBBarMZp-1000GeV_MA0-300GeV  MonoHSignalTrees_20151012/crab_MonoHToBBarMZp-1000GeV_MA0-300GeVTreeMaker_20151012
MonoHToBBarMZp-1200GeV_MA0-300GeV  MonoHSignalTrees_20151012/crab_MonoHToBBarMZp-1200GeV_MA0-300GeVTreeMaker_20151012
MonoHToBBarMZp-1400GeV_MA0-300GeV  MonoHSignalTrees_20151012/crab_MonoHToBBarMZp-1400GeV_MA0-300GeVTreeMaker_20151012
MonoHToBBarMZp-1700GeV_MA0-300GeV  MonoHSignalTrees_20151012/crab_MonoHToBBarMZp-1700GeV_MA0-300GeVTreeMaker_20151012
MonoHToBBarMZp-2000GeV_MA0-300GeV  MonoHSignalTrees_20151012/crab_MonoHToBBarMZp-2000GeV_MA0-300GeVTreeMaker_20151012
MonoHToBBarMZp-2500GeV_MA0-300GeV  MonoHSignalTrees_20151012/crab_MonoHToBBarMZp-2500GeV_MA0-300GeVTreeMaker_20151012'''






##M800GeV Signal/Step3/800/
##M900GeV Signal/Step3/900/ 
##M1000GeV Signal/Step3/1000/
##M1500GeV Signal/Step3/1500/
##


##DoubleEG_Run2015C-PromptReco-v1 DoubleEG/DoubleEG_Run2015C-PromptReco-v1
##TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0826/
##TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0803/
##QCD_Pt-15TTo7000_TuneZ2star-Flat_13TeV_pythia6 QCD_Pt-15TTo7000_TuneZ2star-Flat_13TeV_pythia6/crab_QCD_Pt-15TTo7000_TuneZ2star-Flat_13TeV_pythia6_0803/

##


fout.write(samples)
fout.close()

## 
f = open('samplestorun.txt','r')
for line in f:
    a,b = line.split()
    datasetdet=[a,b]
    #jobcommand = ("farmoutAnalysisJobs "+outputdirname+"/"+datasetdet[0]+" "+inputprefix+datasetdet[1]+" "+cmsswpath+" "+exepath+" --fwklite --input-files-per-job=30 --resubmit-failed-jobs")
    #jobcommand = ("farmoutAnalysisJobs "+outputdirname+"/"+datasetdet[0]+" "+inputprefix+datasetdet[1]+" "+cmsswpath+" "+exepath+" --fwklite --input-files-per-job=30")
    jobcommand = ("farmoutAnalysisJobs "+outputdirname+"/"+datasetdet[0]+" "+inputprefix+datasetdet[1]+" "+cmsswpath+" "+exepath+" --fwklite --input-files-per-job=10 --extra-inputs=CSVv2.csv  ")
    
    print "--------------------------------------------------------------"
    print "submitting jobs for"+datasetdet[0]
    print "--------------------------------------------------------------"
    print jobcommand
    os.system(jobcommand)
    #os.system('sleep 30')
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


old='''crab_MET-Run2015D-PromptReco-V420151027_1p2fb MET/crab_MET-Run2015D-PromptReco-V420151027_1p2fb
crab_MET-Run2015D-05Oct2015V120151027_1p2fb MET/crab_MET-Run2015D-05Oct2015V120151027_1p2fb'''

