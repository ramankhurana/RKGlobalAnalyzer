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
observation              DATARATE

-------------------------------------------------------------------------------------------------

bin                      MONOHBB   MONOHBB    MONOHBB    MONOHBB    MONOHBB    MONOHBB
process                  Sig       DYJets      WJets      ZH          TT        QCD 

-------------------------------------------------------------------------------------------------

process                  0                1          2             3          4         5  

rate                SIGNALRATE       DYJETSRATE    WJETSRATE    ZHRATE      TTRATE    QCDRATE 

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
              'DYJETS',
              'WJETS',
              'DATA']

signalnameinnumber=['M600',
                    'M700',
                    'M800',
                    'M900',
                    'M1000',
                    'M1200',
                    'M1500']

## create the names of place holders
placeholder = [x + "RATE" for x in nameinnumber]
print placeholder


## valuemap
valuemap = {
    "default" : 0.0
    }

signalvaluemap = {
    "default" : 0.0
    }

## Read the signal background numbers from rootfile.
## this value map is used later to get the datacard by replacing the
## place holders with values stored in this map.
numbers = open('sigbkg.txt','r')
for iline in numbers:
    a,b = iline.split()
    for iname in range(len(nameinnumber)):
        if a==nameinnumber[iname]:
            stringtoprint = nameinnumber[iname]+" value is "+b
            print stringtoprint
            ratename = nameinnumber[iname]+"RATE"
            valuemap[ratename]=b
    ### Following lines fill the 
    ### value map for signal points
    for isigname in range(len(signalnameinnumber)):
        if a==signalnameinnumber[isigname]:
            stringtoprint = signalnameinnumber[isigname]+" value is "+b
            print stringtoprint
            ratename = signalnameinnumber[isigname]+"RATE"
            signalvaluemap[ratename]=b

print valuemap
print signalvaluemap

## Method to access the rootfiles
## Use it to clone and then 
sigTFile = ROOT.TFile('Merged_DMHistosSpring15_1/main-NCUGlobalTuples_M1500.root','READ')
sigEvent  = sigTFile.Get('CutFlowAndEachCut/h_cutflow_0')
sigTEvent = sigTFile.Get('nEvents')
print sigEvent.GetBinContent(7)
scaledsig = Normalize(sigEvent.GetBinContent(7), SignalXS['M1500'],sigTEvent.GetEntries())
print scaledsig


def MakeDataCard(masspoint):
    datacard = open('DataCard_MXXXGeV.txt','r')
    newdatacardname = 'DataCard_'+masspoint+'GeV_MonoHbb_13TeV.txt'
    os.system('rm '+newdatacardname)
    datacard600 = open(newdatacardname,'w')
    
    for line in datacard:
        ## replace the background values.
        for ival in range(len(placeholder)):
            line = line.replace(placeholder[ival],valuemap[placeholder[ival]])
        
        ## replace the signal values
        masspointrate = masspoint + "RATE"
        line = line.replace('SIGNALRATE', signalvaluemap[masspointrate])
        datacard600.write(line)
    datacard600.close()



for imasspoint in range(len(signalnameinnumber)):
    MakeDataCard(signalnameinnumber[imasspoint])


print "datacards produced"



