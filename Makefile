CC=g++ `root-config --cflags`

CFLAGS=-c -Wall

all: runallAnalysis.exe

runallAnalysis.exe: bin/Main.o bin/RKAnalyzer.o bin/JetValidator.o bin/ElectronValidator.o bin/METValidator.o bin/SelectionBitsProducer.o bin/CutFlowAndEachCut.o bin/NMinusOne.o bin/HistFactory.o bin/ABCDMethod.o bin/ElectronSelectionBitsProducer.o bin/ElectronNMinusOne.o 
	$(CC) bin/Main.o bin/RKAnalyzer.o bin/JetValidator.o bin/ElectronValidator.o bin/METValidator.o bin/SelectionBitsProducer.o bin/CutFlowAndEachCut.o bin/NMinusOne.o bin/HistFactory.o bin/ABCDMethod.o bin/ElectronSelectionBitsProducer.o bin/ElectronNMinusOne.o  -o runallAnalysis.exe  `root-config --libs`

bin/Main.o: RKAnalysisController/src/Main.C
	$(CC) $(CFLAGS)  RKAnalysisController/src/Main.C -o bin/Main.o

bin/RKAnalyzer.o: RKAnalysisController/src/RKAnalyzer.C
	$(CC) $(CFLAGS)  RKAnalysisController/src/RKAnalyzer.C -o bin/RKAnalyzer.o 

bin/JetValidator.o: RKObjectValidator/src/JetValidator.C
	$(CC) $(CFLAGS)   RKObjectValidator/src/JetValidator.C -o bin/JetValidator.o 

bin/ElectronValidator.o: RKObjectValidator/src/ElectronValidator.C
	$(CC) $(CFLAGS)   RKObjectValidator/src/ElectronValidator.C -o bin/ElectronValidator.o

bin/METValidator.o: RKObjectValidator/src/METValidator.C
	$(CC) $(CFLAGS)   RKObjectValidator/src/METValidator.C -o bin/METValidator.o 

bin/SelectionBitsProducer.o: RKMonoHAnalyzer/src/SelectionBitsProducer.C
	$(CC) $(CFLAGS)   RKMonoHAnalyzer/src/SelectionBitsProducer.C  -o bin/SelectionBitsProducer.o

bin/CutFlowAndEachCut.o: RKMonoHAnalyzer/src/CutFlowAndEachCut.C
	$(CC) $(CFLAGS)   RKMonoHAnalyzer/src/CutFlowAndEachCut.C  -o bin/CutFlowAndEachCut.o

bin/NMinusOne.o: RKMonoHAnalyzer/src/NMinusOne.C
	$(CC) $(CFLAGS)   RKMonoHAnalyzer/src/NMinusOne.C  -o bin/NMinusOne.o

bin/HistFactory.o: RKMonoHAnalyzer/src/HistFactory.C
	$(CC) $(CFLAGS)   RKMonoHAnalyzer/src/HistFactory.C  -o bin/HistFactory.o 

bin/ABCDMethod.o: RKMonoHAnalyzer/src/ABCDMethod.C
	$(CC) $(CFLAGS)   RKMonoHAnalyzer/src/ABCDMethod.C  -o bin/ABCDMethod.o

bin/ElectronSelectionBitsProducer.o: RKDYAnalysis/src/ElectronSelectionBitsProducer.C
	$(CC) $(CFLAGS)   RKDYAnalysis/src/ElectronSelectionBitsProducer.C -o bin/ElectronSelectionBitsProducer.o

bin/ElectronNMinusOne.o: RKDYAnalysis/src/ElectronNMinusOne.C
	$(CC) $(CFLAGS)   RKDYAnalysis/src/ElectronNMinusOne.C -o bin/ElectronNMinusOne.o


clean:
	rm -r bin/*.o runallAnalysis.exe
#g++ `root-config --cflags` RKAnalysisController/src/Main.C RKAnalyzer.o JetValidator.o ElectronValidator.o METValidator.o SelectionBitsProducer.o CutFlowAndEachCut.o NMinusOne.o HistFactory.o ABCDMethod.o ElectronSelectionBitsProducer.o ElectronNMinusOne.o -o main.exe `root-config --libs`

#g++ `root-config --cflags` RKAnalysisController/src/MyfarmoutAnalyzer.cc 

## This can be used instead of previous line in order to submit using farmout analysis
#g++ `root-config --cflags` RKAnalysisController/src/MyfarmoutAnalyzer.cc RKAnalyzer.o JetValidator.o ElectronValidator.o METValidator.o SelectionBitsProducer.o CutFlowAndEachCut.o NMinusOne.o HistFactory.o ABCDMethod.o   -o main.exe `root-config --libs`

