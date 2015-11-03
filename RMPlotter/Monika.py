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


def DrawOverlap(fileVec, histVec, titleVec,legendtext,pngname,xRange=[-99999,99999,1]):
    
    #histo={}
    SetStyle()
    leg = SetLegend()
    c   = SetCanvas()
    
    print ("you have provided "+str(len(fileVec))+" files and "+str(len(histVec))+" histograms to make a overlapping plot" )
    print "opening rootfiles"

    
    
    print ("opening file  "+fileVec)
    #inputfile = TFile( fileVec,'READ' )
    #inputfile.ls()
    gROOT.cd()
    inputfile = TFile(fileVec)
    print "fetching histograms"
    print ("printing histo "+str(histVec))
#    histo = TH1F()
    histo123={}
#    histo123[0].Reset()
#    histo123[0].SetDirectory(0)
    histo123[0] = inputfile.Get(histVec)
    #histo = gDirectory.Get(histVec)
    print type(histo123[0])
    nbins = histo123[0].GetNbinsX()
    xlow  = histo123[0].GetXaxis().GetXmin()
    xhigh = histo123[0].GetXaxis().GetXmax()
    efficiency = TH1F(pngname,"efficiency",nbins,xlow,xhigh)
    
    for ibin in range(nbins):
        eff =  histo123[0].Integral(ibin+1,nbins)/float(histo123[0].Integral())
        efficiency.SetBinContent(ibin,eff)
        
    efficiency.Draw()
    efficiency.SetMaximum(1.0)
    efficiency.SetLineColor(2)
    efficiency.SetLineWidth(3)
    pt = SetPaveText()
    pt.Draw()
    leg.Draw()
    
    SavePlots(pngname,c)
    efficiency.SetDirectory(0)
    inputfile.Close()
    
    return efficiency


print "calling the plotter"
files=['../OutputRootFile/analysis.root','../OutputRootFile/analysis2.root']
point=['1000','2000']
ytitle='#e_{Signal}'
legend=['M_{Z`} = 1000 GeV']

fout = TFile('Out.root','RECREATE')
fout.cd()


## Add Histogram to Root File
#for ip in range(len(files)):
h_name='FatJetCSV_'+point[0]
FatJetCSV = DrawOverlap(files[0], 'NMinusOne/h_FatJetCSVbcsv',['CSIVv2',ytitle], legend,h_name)
fout.cd()
FatJetCSV.Write()
#fout.Close()

#fout = TFile('Out.root','UPDATE')
h_name='FatJetCSV1_'+point[1]
FatJetCSV1 = DrawOverlap(files[1], 'NMinusOne/h_FatJetCSVbcsv',['CSIVv2',ytitle], legend,h_name)
fout.cd()
FatJetCSV1.Write()

                           





#DrawOverlap(files, ['MonoHJetISRVetoStudy/h_nAddJetspt10','MonoHJetISRVetoStudy/h_nAddJetspt15','MonoHJetISRVetoStudy/h_nAddJetspt20','MonoHJetISRVetoStudy/h_nAddJetspt25','MonoHJetISRVetoStudy/h_nAddJetspt30'],['nJets',ytitle], legend,'nJets')

##xrange_ = [0,5,2]
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt10','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt15','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt20','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt25','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt30'],['#DeltaR(b1-j1)',ytitle], legend,'deltaRLeadingB0',xrange_)
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRSubLeadingB0pt10','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB0pt15','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB0pt20','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB0pt25','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB0pt30'],['#DeltaR(b2-j1)',ytitle], legend,'deltaRSubLeadingB0',xrange_)
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRLeadingB1pt10','MonoHJetISRVetoStudy/h_DeltaRLeadingB1pt15','MonoHJetISRVetoStudy/h_DeltaRLeadingB1pt20','MonoHJetISRVetoStudy/h_DeltaRLeadingB1pt25','MonoHJetISRVetoStudy/h_DeltaRLeadingB1pt30'],['#DeltaR(b1-j2)',ytitle], legend,'deltaRLeadingB1',xrange_)
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRSubLeadingB1pt10','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB1pt15','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB1pt20','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB1pt25','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB1pt30'],['#DeltaR(b2-j2)',ytitle], legend,'deltaRSubLeadingB1',xrange_)
##
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRLeadingB2pt10','MonoHJetISRVetoStudy/h_DeltaRLeadingB2pt15','MonoHJetISRVetoStudy/h_DeltaRLeadingB2pt20','MonoHJetISRVetoStudy/h_DeltaRLeadingB2pt25','MonoHJetISRVetoStudy/h_DeltaRLeadingB2pt30'],['#DeltaR(b1-j3)',ytitle], legend,'deltaRLeadingB2',xrange_)
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRSubLeadingB2pt10','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB2pt15','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB2pt20','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB2pt25','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB2pt30'],['#DeltaR(b2-j3)',ytitle], legend,'deltaRSubLeadingB2',xrange_)
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRClosestB0pt10','MonoHJetISRVetoStudy/h_DeltaRClosestB0pt15','MonoHJetISRVetoStudy/h_DeltaRClosestB0pt20','MonoHJetISRVetoStudy/h_DeltaRClosestB0pt25','MonoHJetISRVetoStudy/h_DeltaRClosestB0pt30'],['#DeltaR(b_{closest}-j1)',ytitle], legend,'deltaRLeadingClosestB',xrange_)
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_pTAddJet0','MonoHJetISRVetoStudy/h_pTAddJet1','MonoHJetISRVetoStudy/h_pTAddJet2'],['p_{T}^{add. Jet}',ytitle], ['leading','sub-lead','3^{rd}-lead'],'pTAdditionalJet',[0,150.,2])
