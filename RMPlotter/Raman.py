import sys
sys.argv.append( '-b-' )


from ROOT import TFile, TH1F, gDirectory, TCanvas
from ROOT import gStyle
from ROOT import gROOT
from ROOT import TStyle
from ROOT import TLegend
from ROOT import TPaveText
from  Helpers import *
import os

colors=[1,2,3,4,5,6,7]


files=[]
def OpenFile(filename,histVec,if_):
    fin = TFile( filename,'READ' )
    files.append(fin)
    files[if_].cd('NMinusOne')
    histogram = gDirectory.Get(histVec)
    print ("type in open file",type(histogram))
    histogram.SetDirectory(0)
    files[if_].Close()
    return histogram

histo=[]
def DrawOverlap(fileVec, histVec, titleVec,legendtext,pngname,xRange=[0,99999,1]):
    SetStyle()
    leg = SetLegend()
    c   = SetCanvas()
    
    i=0
    ii=0
    histList_=[]
    histList=[]
    maximum=[]
    
    print ("you have provided "+str(len(fileVec))+" files and "+str(len(histVec))+" histograms to make a overlapping plot" )
    print "opening rootfiles"
    
    inputfile={}
    for ifile_ in range(len(fileVec)):
        print ("opening file  "+fileVec[ifile_])
        inputfile[ifile_] = TFile( fileVec[ifile_] )
        print "fetching histograms"
        for ihisto_ in range(len(histVec)):
            print ("printing histo "+str(histVec[ihisto_]))
            histo = inputfile[ifile_].Get(histVec[ihisto_])
            histList.append(histo)
            print histList[ii].Integral()
            histList[ii].Rebin(xRange[2])
            histList[ii].Scale(1.0/histList[ii].Integral())
            maximum.append(histList[ii].GetMaximum())
            ii=ii+1

    
    for ih in range(len(histList)):
        print type(histo)
        nbins = histList[ih].GetNbinsX()
        xlow  = histList[ih].GetXaxis().GetXmin()
        xhigh = histList[ih].GetXaxis().GetXmax()
        efficiency = TH1F(pngname,"efficiency",nbins,xlow,xhigh)
        
        for ibin in range(nbins):
            eff =  histList[ih].Integral(ibin+1,nbins)/float(histList[ih].Integral())
            efficiency.SetBinContent(ibin,eff)
            
        efficiency.Draw()
        efficiency.SetMaximum(1.0)
        efficiency.SetLineColor(2)
        efficiency.SetLineWidth(3)
        
        i=i+1
        
    
    pt = SetPaveText()
    pt.Draw()
    leg.Draw()
    SavePlots(pngname,c)
    efficiency.SetDirectory(0)
    return efficiency



print "calling the plotter"
files=['../OutputRootFile/analysis.root','../OutputRootFile/analysis.root']
point=['1000','2000']
ytitle='#e_{Signal}'
legend=['M_{Z`} = 1000 GeV']

fout = TFile('Out.root','RECREATE')
fout.cd()


## Add Histogram to Root File
dir_='NMinusOne/'
histoNameVec=['h_FatJetCSVbcsv','h_FatJetpTapteta','h_DPhiFatJetMETcDPHIJetMet','h_METemetpt']
histVec=[]
for histname in histoNameVec: 
    histVec.append(dir_+histname)

print histVec

for ih in range(len(histVec)):
    h_name=histoNameVec[ih]
    h = DrawOverlap([files[0]], [histVec[ih]],['CSIVv2',ytitle], legend,h_name)
    fout.cd()
    h.Write()

#
#h_name1='FatJetpT_'+point[0]
#FatJetCSV1 = DrawOverlap([files[0]], ['NMinusOne/h_FatJetpTapteta'],['p_{T}^{AK8Jet}',ytitle], legend,h_name1)
#fout.cd()
#FatJetCSV1.Write()
#
#                           




