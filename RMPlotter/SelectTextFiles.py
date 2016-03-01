import os
import sys

inputdirname=sys.argv[1]
ControlRegions=['WHeavy','MonoHFatJetSelection_JetAndLeptonVeto','ZLight']
textFilesList=[]
for whichCR in ControlRegions:
    for files in  os.listdir(inputdirname) :
        if whichCR in files:
            if "Integral.txt" in files:
                #print files
                textFilesList.append(files)

datacardsdir='DataCards_'+inputdirname
os.system('rm -rf '+datacardsdir)
os.system(' mkdir '+datacardsdir)

for itextfiles in range(len(textFilesList)):
    os.system ('python MakeDataCards.py '+inputdirname+'/'+textFilesList[itextfiles]+' '+inputdirname+'/'+ControlRegions[itextfiles])
    os.system(' mv '+inputdirname+'/'+ControlRegions[itextfiles]+' '+datacardsdir)
#print textFilesList
