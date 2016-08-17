for which in 0; do
    root -l -b -q subjStudy.cc++\($which\)
done

dirname=Histograms_CMSSW76X_Approval_NoMassCut_V$1
#dirname=Histograms_CMSSW76X_2DScanV_V$1
mkdir $dirname
mv AnalysisHistograms_V0 $dirname
#mv AnalysisHistograms_V1 $dirname
#mv AnalysisHistograms_V2 $dirname
#mv AnalysisHistograms_V3 $dirname

