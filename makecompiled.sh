g++ `root-config --cflags` RKAnalysisController/src/RKAnalyzer.C -c
g++ `root-config --cflags` RKObjectValidator/src/JetValidator.C -c 
g++ `root-config --cflags` RKObjectValidator/src/METValidator.C -c 
g++ `root-config --cflags` RKMonoHAnalyzer/src/SelectionBitsProducer.C  -c 
g++ `root-config --cflags` RKMonoHAnalyzer/src/CutFlowAndEachCut.C  -c 
g++ `root-config --cflags` RKMonoHAnalyzer/src/NMinusOne.C  -c 
#g++ `root-config --cflags` RKAnalysisController/src/Main.C RKAnalyzer.o JetValidator.o METValidator.o SelectionBitsProducer.o CutFlowAndEachCut.o NMinusOne.o  -o main.exe `root-config --libs`
g++ `root-config --cflags` RKAnalysisController/src/MyfarmoutAnalyzer.cc RKAnalyzer.o JetValidator.o METValidator.o SelectionBitsProducer.o CutFlowAndEachCut.o NMinusOne.o  -o main.exe `root-config --libs`
#g++ `root-config --cflags` RKAnalysisController/src/Main.C RKAnalyzer.o JetValidator.o METValidator.o  TwoObjectCombination.o -o main.exe `root-config --libs`
