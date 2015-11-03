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

colors=[1,2,3,4,5,6,7,8,9,10,11,12,13,14]

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
    leg = TLegend(0.6, 0.72, 0.91, 0.89)#,NULL,"brNDC");
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
        histList[ih].GetXaxis().SetNdivisions(512)
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
    
    histname='HHbbbbPlots/'+pngname
    c.SaveAs(histname+'.png')
    c.SaveAs(histname+'.pdf')


print "calling the plotter"
files=['../FatJetOptimination/Merged_Signal/Merged_1000.root','../FatJetOptimination/Merged_Signal/Merged_2000.root','../FatJetOptimination/Merged_QCD/Merged_2000-Inf.root']
ytitle='# of Events (Normalized to 1)'
legend=['M1000','M2000', 'QCDHT2000-Inf']

DrawOverlap(files, ['nFatJets'],['nJets',ytitle], legend,'nFatJets')
DrawOverlap(files, ['DR'],['#DeltaR',ytitle], legend,'DR')
DrawOverlap(files, ['DPhi'],['#Delta#phi',ytitle], legend,'DPhi')

path='../FatJetOptimination/Merged_Signal/'
allfiles=[path+'Merged_1000.root', path+'Merged_1400.root',path+'Merged_2000.root',path+'Merged_2500.root',path+'Merged_3000.root',path+'Merged_3500.root',path+'Merged_4000.root',path+'Merged_4500.root']
alllegend=['M1000','M1400','M2000','M2500','M3000','M3500','M4000','M4500']
DrawOverlap(allfiles, ['XMass'],['M_{BG}',ytitle], alllegend,'XMass')
