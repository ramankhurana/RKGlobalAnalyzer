g++ `root-config --cflags` RKAnalysisController/src/RKAnalyzer.C -c
g++ `root-config --cflags` RKObjectValidator/src/JetValidator.C -c 
g++ `root-config --cflags` RKObjectValidator/src/METValidator.C -c 
g++ `root-config --cflags` RKMonoHAnalyzer/src/SelectionBitsProducer.C  -c 
g++ `root-config --cflags` RKMonoHAnalyzer/src/CutFlowAndEachCut.C  -c 
g++ `root-config --cflags` RKMonoHAnalyzer/src/NMinusOne.C  -c 
g++ `root-config --cflags` RKMonoHAnalyzer/src/HistFactory.C  -c 
g++ `root-config --cflags` RKMonoHAnalyzer/src/ABCDMethod.C  -c 
g++ `root-config --cflags` RKAnalysisController/src/Main.C RKAnalyzer.o JetValidator.o METValidator.o SelectionBitsProducer.o CutFlowAndEachCut.o NMinusOne.o HistFactory.o ABCDMethod.o -o main.exe `root-config --libs`
## This can be used instead of previous line in order to submit using farmout analysis
#g++ `root-config --cflags` RKAnalysisController/src/MyfarmoutAnalyzer.cc RKAnalyzer.o JetValidator.o METValidator.o SelectionBitsProducer.o CutFlowAndEachCut.o NMinusOne.o  -o main.exe `root-config --libs`

