CC=g++ `root-config --cflags`

CFLAGS=-c -Wall

all: runallAnalysis.exe

runallAnalysis.exe: Main.o RKAnalyzer.o JetValidator.o ElectronValidator.o METValidator.o SelectionBitsProducer.o CutFlowAndEachCut.o NMinusOne.o HistFactory.o ABCDMethod.o ElectronSelectionBitsProducer.o ElectronNMinusOne.o 
	$(CC)  Main.o RKAnalyzer.o JetValidator.o ElectronValidator.o METValidator.o SelectionBitsProducer.o CutFlowAndEachCut.o NMinusOne.o HistFactory.o ABCDMethod.o ElectronSelectionBitsProducer.o ElectronNMinusOne.o -o runallAnalysis.exe  `root-config --libs`

Main.o: RKAnalysisController/src/Main.C
	$(CC) $(CFLAGS)  RKAnalysisController/src/Main.C

RKAnalyzer.o: RKAnalysisController/src/RKAnalyzer.C
	$(CC) $(CFLAGS)  RKAnalysisController/src/RKAnalyzer.C -c

JetValidator.o: RKObjectValidator/src/JetValidator.C
	$(CC) $(CFLAGS)   RKObjectValidator/src/JetValidator.C -c 

ElectronValidator.o: RKObjectValidator/src/ElectronValidator.C
	$(CC) $(CFLAGS)   RKObjectValidator/src/ElectronValidator.C -c 

METValidator.o: RKObjectValidator/src/METValidator.C
	$(CC) $(CFLAGS)   RKObjectValidator/src/METValidator.C -c 

SelectionBitsProducer.o: RKMonoHAnalyzer/src/SelectionBitsProducer.C
	$(CC) $(CFLAGS)   RKMonoHAnalyzer/src/SelectionBitsProducer.C  -c 

CutFlowAndEachCut.o: RKMonoHAnalyzer/src/CutFlowAndEachCut.C
	$(CC) $(CFLAGS)   RKMonoHAnalyzer/src/CutFlowAndEachCut.C  -c 

NMinusOne.o: RKMonoHAnalyzer/src/NMinusOne.C
	$(CC) $(CFLAGS)   RKMonoHAnalyzer/src/NMinusOne.C  -c 

HistFactory.o: RKMonoHAnalyzer/src/HistFactory.C
	$(CC) $(CFLAGS)   RKMonoHAnalyzer/src/HistFactory.C  -c 

ABCDMethod.o: RKMonoHAnalyzer/src/ABCDMethod.C
	$(CC) $(CFLAGS)   RKMonoHAnalyzer/src/ABCDMethod.C  -c 

ElectronSelectionBitsProducer.o: RKDYAnalysis/src/ElectronSelectionBitsProducer.C
	$(CC) $(CFLAGS)   RKDYAnalysis/src/ElectronSelectionBitsProducer.C -c 

ElectronNMinusOne.o: RKDYAnalysis/src/ElectronNMinusOne.C
	$(CC) $(CFLAGS)   RKDYAnalysis/src/ElectronNMinusOne.C -c 


clean:
	rm -r *.o runallAnalysis.exe
#g++ `root-config --cflags` RKAnalysisController/src/Main.C RKAnalyzer.o JetValidator.o ElectronValidator.o METValidator.o SelectionBitsProducer.o CutFlowAndEachCut.o NMinusOne.o HistFactory.o ABCDMethod.o ElectronSelectionBitsProducer.o ElectronNMinusOne.o -o main.exe `root-config --libs`

#g++ `root-config --cflags` RKAnalysisController/src/MyfarmoutAnalyzer.cc 

## This can be used instead of previous line in order to submit using farmout analysis
#g++ `root-config --cflags` RKAnalysisController/src/MyfarmoutAnalyzer.cc RKAnalyzer.o JetValidator.o ElectronValidator.o METValidator.o SelectionBitsProducer.o CutFlowAndEachCut.o NMinusOne.o HistFactory.o ABCDMethod.o   -o main.exe `root-config --libs`

