root -l -b  <<EOF
.L EffandAcc.C++
TTree *t =0;
EffandAcc *tmva;
tmva = new EffandAcc(t, "/hdfs/store/user/khurana/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_NewMiniIso_Extended/151124_182452/0000/NCUGlobalTuples_1.root","DYJetsToLL_M-10to50/AnalysisOutput_10.root");
tmva->Loop();
EOF