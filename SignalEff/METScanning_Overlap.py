### Overlapping script for TGraph for MET Scanning ###
#### MONIka MIttal khuaran#####################################

import sys
sys.argv.append( '-b-' )


from ROOT import TFile, TH1F, gDirectory, TCanvas, TPad, TProfile,TGraph, TGraphAsymmErrors
from ROOT import gStyle
from ROOT import gROOT
from ROOT import TStyle
from ROOT import TLegend
from ROOT import TPaveText
import os

colors=[1,2,3,4,5,6,7]
markerStyle=[20,21,22,23,24,25,26,27]
def DrawOverlap(fileVec, histVec, titleVec,legendtext,pngname, xRange=[-99999,99999,1]):
    gStyle.SetOptTitle(0)
    gStyle.SetOptStat(0)
    gStyle.SetTitleOffset(1.1,"Y");
    gStyle.SetTitleOffset(0.9,"X");
    gStyle.SetLineWidth(3)
    gStyle.SetFrameLineWidth(3);
    i=0

    histList_=[]
    histList=[]
    maximum=[]
    
    ## Legend
    leg = TLegend(0.14, 0.80, 0.85, 0.88)#,NULL,"brNDC");
    leg.SetNColumns(2);
    leg.SetBorderSize(0)
    leg.SetLineColor(1)
    leg.SetLineStyle(1)
    leg.SetLineWidth(1)
    leg.SetFillColor(0)
    leg.SetFillStyle(0)
    leg.SetTextFont(22)
    leg.SetTextSize(0.026)
     
    c = TCanvas("c1", "c1",0,0,500,500)
    c.SetBottomMargin(0.15)
    c.SetLeftMargin(0.15)
    c.SetLogy(0)
    
    print ("you have provided "+str(len(fileVec))+" files and "+str(len(histVec))+" histograms to make a overlapping plot" )
    print "opening rootfiles"
    c.cd()
    ii=0    
    inputfile={}
    for ifile_ in range(len(fileVec)):
        print ("opening file  "+fileVec[ifile_])
        inputfile[ifile_] = TFile( fileVec[ifile_] )
        print "fetching histograms"
        for ihisto_ in range(len(histVec)):
            print ("printing histo "+str(histVec[ihisto_]))
            #histo = gDirectory.Get(histVec[ihisto_])
            histo = inputfile[ifile_].Get(histVec[ihisto_])
            histList.append(histo)
            print histList[ii].Integral()
#            histList[ii].Rebin(xRange[2])
#            if NORMALIZETO1 :
#                histList[ii].Scale(1.0/histList[ii].Integral())

#            if NORMALIZETO1 == False :
#                if ii > 0 :
#                    histList[ii].Scale(histList[0].Integral()/histList[ii].Integral())

            maximum.append(histList[ii].GetMaximum())
            ii=ii+1

    print histList
    for ih in range(len(histList)):
        histList[ih].SetMaximum(1.2) #1.4 for log
        histList[ih].SetMinimum(0.1)
        print ih
        if ih > 0 :
#            histList[ih].SetLineColor(colors[ih])
#            histList[ih].SetLineWidth(2)
            histList[ih].Draw("P same") 
        if ih == 0 :
#            histList[ih].SetMarkerStyle(20);
            histList[ih].Draw("AP") 
       
        histList[ih].SetMarkerColor(colors[ih]);
        histList[ih].SetMarkerSize(1.0);   
        histList[ih].SetMarkerStyle(markerStyle[ih])        
        histList[ih].GetXaxis().SetTitleSize(0.05)
        histList[ih].GetXaxis().SetLabelSize(.05)
        histList[ih].GetXaxis().SetTitleOffset(0.97)
        histList[ih].GetXaxis().SetTitleFont(22)
        histList[ih].GetXaxis().SetLabelFont(22)
        histList[ih].GetYaxis().SetTitle(titleVec[1])
        histList[ih].GetYaxis().SetTitleSize(0.05)
        histList[ih].GetYaxis().SetTitleOffset(1.2)
        histList[ih].GetYaxis().SetTitleFont(22)
        histList[ih].GetYaxis().SetLabelFont(22)
        histList[ih].GetYaxis().SetLabelSize(.05)
        histList[ih].GetXaxis().SetTitle(titleVec[0])
        histList[ih].GetXaxis().SetRangeUser(xRange[0],xRange[1])
        histList[ih].GetXaxis().SetNdivisions(510)
        histList[ih].GetYaxis().SetNdivisions(508)
        histList[1].GetXaxis().SetLabelOffset(999);
        histList[1].GetXaxis().SetLabelSize(0);
#        histList[ih].Draw("same")
        if ih > 0 :        
            leg.AddEntry(histList[ih],legendtext[ih],"P")
        if ih == 0 :
            leg.AddEntry(histList[ih],legendtext[ih],"P")
        i=i+1
    
    pt = TPaveText(0.1277181,0.9,0.9580537,0.96,"brNDC")
    pt.SetBorderSize(0)
    pt.SetTextAlign(12)
    pt.SetFillStyle(0)
    pt.SetTextFont(22)
    pt.SetTextSize(0.043)
    text = pt.AddText(0.01,0.5,"CMS Preliminary")
    text = pt.AddText(0.4,0.5,"#sqrt{s} = 13 TeV  #scale[0.45]{#int}L= 71.3 pb^{-1}")
    pt.Draw()
    leg.Draw()
                  

    
    histname='METPlots/'+pngname
    c.SaveAs(histname+'.png')
    c.SaveAs(histname+'.pdf')


print "calling the plotter"

files=['METScan_Eff.root']
ytitle='Efficiency'
legend =['hbhet','csct','EESCBad','ECDCTP','CSCTH2015','CSCTHMu']
legend1 =['HCALStrp','AllCSCTH2015','AllCSCTHMu','AllHCALStrp','AllCSCTH2015HCALStrp','AllCSCTH2015HCALStrpIsolation']

DrawOverlap(files,['h_nVtxhbhet','h_nVtxcsct','h_nVtxEESCBad','h_nVtxECDCTP','h_nVtxCSCTH2015','h_nVtxCSCTHMu'],['nVtx',ytitle],legend,'nvtxEff1_6')

DrawOverlap(files,['h_nVtxHCALStrp','h_nVtxAllCSCTH2015','h_nVtxAllCSCTHMu','h_nVtxAllHCALStrp','h_nVtxAllCSCTH2015HCALStrp','h_nVtxAllCSCTH2015HCALStrpIsolation'],['nVtx',ytitle],legend1,'nvtxEff6_12')

DrawOverlap(files,['h_RunNumberhbhet','h_RunNumbercsct','h_RunNumberEESCBad','h_RunNumberECDCTP','h_RunNumberCSCTH2015','h_RunNumberCSCTHMu'],['Run No.',ytitle],legend,'RunEff1_6')

DrawOverlap(files,['h_RunNumberHCALStrp','h_RunNumberAllCSCTH2015','h_RunNumberAllCSCTHMu','h_RunNumberAllHCALStrp','h_RunNumberAllCSCTH2015HCALStrp','h_RunNumberAllCSCTH2015HCALStrpIsolation'],['Run No.',ytitle],legend1,'RunEff6_12')


