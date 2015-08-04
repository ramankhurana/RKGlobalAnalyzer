import os
import ROOT
ROOT.gROOT.SetBatch(True)  
from DataSetInfo import *

## prepare template datacard and store in this variable. 
## do whatever change you want to do 
## and keep variables in capital letters with prefix "T" e.g. signal strength can be written as TSIGNAL and DYJets can be TDYJETS
## these can be replaced by either a python or shell script to make datacards for a specific mass point and analysis. 
templatecard='''
imax    1       number of channels
jmax    *       number of backgrounds
kmax    *       number of nuisance parameters (sources of systematical uncertainties)

-------------------------------------------------------------------------------------------------

--shapes *     MONOHBB  ROOTFILENAME $PROCESS $PROCESS_$SYSTEMATIC

-------------------------------------------------------------------------------------------------
bin                      MONOHBB
observation              0

-------------------------------------------------------------------------------------------------

bin                      MONOHBB   MONOHBB    MONOHBB    MONOHBB    MONOHBB    MONOHBB
process                  Sig       DYJets      WJets      ZH          TT        QCD 

-------------------------------------------------------------------------------------------------

process                  0                1          2             3          4         5  

rate                SIGNALRATE       DYJetsRATE    WJetsRATE    ZHRATE      TTRATE    QCDRATE 

-------------------------------------------------------------------------------------------------

lumi_13TeV             lnN            1.044  1.044  1.044   1.044   1.044    -  

CMS_xs_Sig             lnN            1.10   -      -       -       -        -
CMS_xs_DYJets          lnN            -      1.10   -       -       -        -
CMS_xs_WJets           lnN            -      -      1.10    -       -        -
CMS_xs_ZH              lnN            -      -      -       1.10    -        -
CMS_xs_TT              lnN            -      -      -       -       1.10     -
CMS_xs_QCD             lnN            -      1.10   -       -       -        1.10




CMS_Sig                lnN            1.10   -      -       -       -        -
CMS_DYJets             lnN            -      1.10   -       -       -        -
CMS_WJets              lnN            -      -      1.10    -       -        -
CMS_ZH                 lnN            -      -      -       1.10    -        -
CMS_TT                 lnN            -      -      -       -       1.10     -
CMS_QCD                lnN            -      1.10   -       -       -        1.10

'''

## template datacard ends here 

#print templatecard


datacard = open('DataCard_MXXXGeV.txt','w')
datacard.write(templatecard)
datacard.close()

def Normalize(n,xs,tot):
    yield_ = n*xs*1./tot
    return yield_


## map of placeholder
nameinnumber=['QCD',
              'TT',
              'DIBOSON',
              'ZH',
              'DYJET',
              'WJETS',
              'DATA']

## create the names of place holders
placeholder = [x + "RATE" for x in nameinnumber]
print placeholder


## valuemap
valuemap = {
    "default" : 0.0
    }

## Read the signal background numbers from rootfile.
numbers = open('sigbkg.txt','r')
for iline in numbers:
    a,b = iline.split()
    for iname in range(len(nameinnumber)):
        if a==nameinnumber[iname]:
            stringtoprint = nameinnumber[iname]+" value is "+b
            print stringtoprint
            ratename = nameinnumber[iname]+"RATE"
            valuemap[ratename]=b

print valuemap


sigTFile = ROOT.TFile('Merged_DMHistosSpring15_1/main-NCUGlobalTuples_M1500.root','READ')
sigEvent  = sigTFile.Get('CutFlowAndEachCut/h_cutflow_0')
sigTEvent = sigTFile.Get('nEvents')
print sigEvent.GetBinContent(7)
scaledsig = Normalize(sigEvent.GetBinContent(7), SignalXS['M1500'],sigTEvent.GetEntries())
print scaledsig
datacard = open('DataCard_MXXXGeV.txt','r')
os.system('rm DataCard_M600GeV.txt')
datacard600 = open('DataCard_M600GeV.txt','w')
for line in datacard:
    #line = line.replace('SIGNALRATE',str(scaledsig))
    line = line.replace(placeholder[0],valuemap[placeholder[0]])
    datacard600.write(line)

datacard600.close()
    




