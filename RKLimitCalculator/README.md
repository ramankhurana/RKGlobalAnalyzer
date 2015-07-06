# LimitHelper
helping scripts to get the limit using Higgs combination tool "combine"

You can find detailed information @ https://twiki.cern.ch/twiki/bin/viewauth/CMS/SWGuideHiggsAnalysisCombinedLimit#Datacard_for_Shape_analyses

TemplateDataCard_PASS.txt : One template cards, modify according to your analysis. 
MakeRootFilesForDataCards.py : This creates rootfiles for limit with proper normalizations. 
RunMakeDataCards.py : Prepares the datacards
CreateBBBHostoForAllFiles.sh & CreateBinByBinUncertainityHistograms.C : add bbb histograms to the input file. 
combinecards.sh : how to combine cards when you have more than one analysis. 
runlimit.sh : You can run combine tool using commands in this file. But it has many features you will not need and you will need asymptotic limit. 