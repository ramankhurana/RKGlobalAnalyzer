import sys
sys.argv.append( '-b-' )


from ROOT import TFile, TH1F, gDirectory, TCanvas
from ROOT import gStyle
from ROOT import gROOT
from ROOT import TStyle
from ROOT import TLegend
from ROOT import TPaveText
#import Helpers
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
    
    inputfile=[]
    for ifile_ in range(len(fileVec)):
        print ("opening file  "+fileVec[ifile_])
        inputfile = TFile( fileVec[ifile_] )
        print "fetching histograms"
        for ihisto_ in range(len(histVec)):
            print ("printing histo "+str(histVec[ihisto_]))
            #histo = inputfile.Get(histVec[ihisto_])
            histo = gDirectory.Get(histVec[ihisto_])
            #histo = inputfile.FindObject(histVec[ihisto_])
            print ('type = '+str(type(histo)))
            histList.append(histo)
            print histo.Integral()
            histo.Rebin(xRange[2])
            histo.Scale(1.0/histo.Integral())
            
            histo.Draw("same")
            histo.SetLineColor(colors[ii])
            histo.SetLineWidth(2)
            
            histo.GetXaxis().SetTitleSize(0.05)
            histo.GetXaxis().SetLabelSize(.05)
            histo.GetXaxis().SetTitleOffset(0.97)
            histo.GetXaxis().SetTitleFont(22)
            histo.GetXaxis().SetLabelFont(22)
            histo.GetYaxis().SetTitle(titleVec[1])
            histo.GetYaxis().SetTitleSize(0.05)
            histo.GetYaxis().SetTitleOffset(1.09)
            histo.GetYaxis().SetTitleFont(22)
            histo.GetYaxis().SetLabelFont(22)
            histo.GetYaxis().SetLabelSize(.05)
            histo.GetXaxis().SetTitle(titleVec[0])
            histo.GetXaxis().SetRangeUser(xRange[0],xRange[1])
            histo.GetXaxis().SetNdivisions(508)
            histo.GetXaxis().SetNdivisions(510)
            leg.AddEntry(histo,legendtext[ii],"L")
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
files=['/afs/hep.wisc.edu/cms/khurana/Script/Validation_7475/Merged_SingleElectron_Run2015B-TwoRuns_75_diff_RLE-runallAnalysis.root','/afs/hep.wisc.edu/cms/khurana/Script/Validation_7475/Merged_SingleElectron_Run2015B-TwoRuns_74_diff_RLE-runallAnalysis.root']
ytitle='# of Events (Normalized to 1)'
legend =['75x','74x']
#legend=['p_{T}>10 GeV','p_{T}>15 GeV','p_{T}>20 GeV','p_{T}>25 GeV','p_{T}>30 GeV']

#DrawOverlap(files, ['MonoHJetISRVetoStudy/h_nAddJetspt10','MonoHJetISRVetoStudy/h_nAddJetspt15','MonoHJetISRVetoStudy/h_nAddJetspt20','MonoHJetISRVetoStudy/h_nAddJetspt25','MonoHJetISRVetoStudy/h_nAddJetspt30'],['nJets',ytitle], legend,'nJets')

DrawOverlap(files, ['Charge/h_pt'],['p_{T}^{ee}', ytitle], legend,'Dielectronpt')

#xrange_ = [0,5,2]
#DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt10','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt15','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt20','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt25','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt30'],['#DeltaR(b1-j1)',ytitle], legend,'deltaRLeadingB0',xrange_)

