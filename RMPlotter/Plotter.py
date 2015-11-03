import sys
sys.argv.append( '-b-' )


from ROOT import TFile, TH1F, gDirectory, TCanvas
from ROOT import gStyle
from ROOT import gROOT
from ROOT import TStyle
from ROOT import TLegend
from ROOT import TPaveText
import Helpers
import os

colors=[1,2,3,4,5,6,7]

def DrawOverlap(fileVec, histVec, titleVec,legendtext,pngname,xRange=[0,99999,1]):
    gStyle.SetOptTitle(0)
    gStyle.SetOptStat(0)
    gStyle.SetTitleOffset(1.1,"Y");
    gStyle.SetTitleOffset(0.9,"X");
    gStyle.SetLineWidth(3)
    gStyle.SetFrameLineWidth(3);
    i=0
    ii=0
    histList_=[]
    histList=[]
    maximum=[]
    
    ## Legend
    leg = TLegend(0.72, 0.72, 0.89, 0.89)#,NULL,"brNDC");
    leg.SetBorderSize(0)
    leg.SetLineColor(1)
    leg.SetLineStyle(1)
    leg.SetLineWidth(1)
    leg.SetFillColor(0)
    leg.SetFillStyle(0)
    leg.SetTextFont(22)

     
    c = TCanvas("c1", "c1",0,0,560,560)
    c.SetBottomMargin(0.15)
    c.SetLeftMargin(0.15)
    print ("you have provided "+str(len(fileVec))+" files and "+str(len(histVec))+" histograms to make a overlapping plot" )
    print "opening rootfiles"
    
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
            histList[ii].Rebin(xRange[2])
            histList[ii].Scale(1.0/histList[ii].Integral())
            maximum.append(histList[ii].GetMaximum())
            ii=ii+1

    
    for ih in range(len(histList)):
        histList[ih].SetMaximum(max(maximum)*1.3)
        histList[ih].Draw("same")
        histList[ih].SetLineColor(colors[ih])
        histList[ih].SetLineWidth(2)
        
        histList[ih].GetXaxis().SetTitleSize(0.05)
        histList[ih].GetXaxis().SetLabelSize(.05)
        histList[ih].GetXaxis().SetTitleOffset(0.97)
        histList[ih].GetXaxis().SetTitleFont(22)
        histList[ih].GetXaxis().SetLabelFont(22)
        histList[ih].GetYaxis().SetTitle(titleVec[1])
        histList[ih].GetYaxis().SetTitleSize(0.05)
        histList[ih].GetYaxis().SetTitleOffset(1.09)
        histList[ih].GetYaxis().SetTitleFont(22)
        histList[ih].GetYaxis().SetLabelFont(22)
        histList[ih].GetYaxis().SetLabelSize(.05)
        histList[ih].GetXaxis().SetTitle(titleVec[0])
        histList[ih].GetXaxis().SetRangeUser(xRange[0],xRange[1])
        histList[ih].GetXaxis().SetNdivisions(508)
        histList[ih].GetXaxis().SetNdivisions(510)
        leg.AddEntry(histList[ih],legendtext[ih],"L")
        i=i+1
        
    
    pt = TPaveText(0.1577181,0.9,0.9580537,0.96,"brNDC")
    pt.SetBorderSize(0)
    pt.SetTextAlign(12)
    pt.SetFillStyle(0)
    pt.SetTextFont(22)
    pt.SetTextSize(0.045)
    text = pt.AddText(0.01,0.5,"CMS Simulation")
    text = pt.AddText(0.4,0.5,"#sqrt{s} = 13 TeV")
    pt.Draw()
    leg.Draw()
    
    histname='Plots/'+pngname
    c.SaveAs(histname+'.png')
    c.SaveAs(histname+'.pdf')


print "calling the plotter"
files=['../OutputRootFile/analysis.root','../OutputRootFile/analysis2.root']
ytitle='# of Events (Normalized to 1)'
legend=['p_{T}>10 GeV','p_{T}>15 GeV','p_{T}>20 GeV','p_{T}>25 GeV','p_{T}>30 GeV']

DrawOverlap(files, ['nEvents'],['nJets',ytitle], legend,'del')
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
