import os
outputdirname="Raman/MonoHFatJetAnalysis_AllMCWithPU_V3/"
inputprefix="--input-dir=root://cmsxrootd.hep.wisc.edu//store/user/khurana/"
cmsswpath="/afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/"
exepath="/afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/runallAnalysis.exe"

fout = open("samplestorun.txt","w")

## list of samples will appear here. 
samples='''crab_MET-Run2015B-PromptReco-v120150921WithFilters MET/crab_MET-Run2015B-PromptReco-v120150921WithFilters/
crab_MET-Run2015C-PromptReco-v120150921WithFilters MET/crab_MET-Run2015C-PromptReco-v120150921WithFilters/
crab_MET-Run2015B-17Jul2015-v120150921WithFilters MET/crab_MET-Run2015B-17Jul2015-v120150921WithFilters/
ZJetsToNuNu_HT-600ToInf_13TeV-madgraph ZJetsToNuNu_HT-600ToInf_13TeV-madgraph/crab_ZJetsToNuNu_HT-600ToInf_13TeV-madgraph_0803
ZJetsToNuNu_HT-400To600_13TeV-madgraph ZJetsToNuNu_HT-400To600_13TeV-madgraph/crab_ZJetsToNuNu_HT-400To600_13TeV-madgraph_0803
ZJetsToNuNu_HT-200To400_13TeV-madgraph ZJetsToNuNu_HT-200To400_13TeV-madgraph/crab_ZJetsToNuNu_HT-200To400_13TeV-madgraph_0803
ZJetsToNuNu_HT-100To200_13TeV-madgraph ZJetsToNuNu_HT-100To200_13TeV-madgraph/crab_ZJetsToNuNu_HT-100To200_13TeV-madgraph_0803
DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8  DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0826
DYJetsToLL_M-50_HT-600toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 DYJetsToLL_M-50_HT-600toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-600toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0826
DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0826
DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8 DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/crab_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_0826
SignalFiles_0804 SignalFiles_0804/
ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8 ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8/crab_ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8_0826/
ZH_HToBB_ZToNuNu_M120_13TeV_amcatnloFXFX_madspin_pythia8 ZH_HToBB_ZToNuNu_M120_13TeV_amcatnloFXFX_madspin_pythia8/crab_ZH_HToBB_ZToNuNu_M120_13TeV_amcatnloFXFX_madspin_pythia8_0826/
TT_TuneCUETP8M1_13TeV-powheg-pythia8 TT_TuneCUETP8M1_13TeV-powheg-pythia8/crab_TT_TuneCUETP8M1_13TeV-powheg-pythia8_0826/
DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_0826/
WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8 WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_0826
WZ_TuneCUETP8M1_13TeV-pythia8 WZ_TuneCUETP8M1_13TeV-pythia8/crab_WZ_TuneCUETP8M1_13TeV-pythia8_0826
ZZ_TuneCUETP8M1_13TeV-pythia8 ZZ_TuneCUETP8M1_13TeV-pythia8/crab_ZZ_TuneCUETP8M1_13TeV-pythia8_0826/
WW_TuneCUETP8M1_13TeV-pythia8 WW_TuneCUETP8M1_13TeV-pythia8/crab_WW_TuneCUETP8M1_13TeV-pythia8_0826/
SignalSamples  MonoHSignalTreesMerged_20150919'''
##MET-Run2015B-PromptReco-v1TotalV3 MET/crab_MET-Run2015B-PromptReco-v1TotalV3/150803_172741/0000



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

f = open('samplestorun.txt','r')
for line in f:
    a,b = line.split()
    datasetdet=[a,b]
    #os.system("farmoutAnalysisJobs "+outputdirname+"datasetdet[0] "+inputprefix+datasetdet[1]+cmsswpath+exepath+" --fwklite --input-files-per-job=1")
    jobcommand = ("farmoutAnalysisJobs "+outputdirname+"/"+datasetdet[0]+" "+inputprefix+datasetdet[1]+" "+cmsswpath+" "+exepath+" --fwklite --input-files-per-job=1")
    print "submitting jobs for"+datasetdet[0]
    os.system(jobcommand)
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
