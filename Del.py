import sys
sys.argv.append( '-b-' )


from ROOT import TFile, TH1F, gDirectory, TCanvas
from ROOT import gStyle
from ROOT import gROOT
from ROOT import TStyle
from ROOT import TLegend
from ROOT import TPaveText
import os

colors=[1,2,3,4,5,6,7]

def DrawOverlap(fileVec, histVec, titleVec,legendtext,pngname,xRange=[-99999,99999,1]):
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
    c.SetLogy(1)
    c.SetLogx(0)
    print ("you have provided "+str(len(fileVec))+" files and "+str(len(histVec))+" histograms to make a overlapping plot" )
    print "opening rootfiles"
    
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
            histList[ii].Rebin(xRange[2])
            histList[ii].Scale(1.0/histList[ii].Integral())
            maximum.append(histList[ii].GetMaximum())
            ii=ii+1

    print histList
    for ih in range(len(histList)):
        histList[ih].SetMaximum(max(maximum)*1.4)
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
    text = pt.AddText(0.01,0.5,"CMS Validation")
    text = pt.AddText(0.4,0.5,"#sqrt{s} = 13 TeV  #scale[0.45]{#int}L=14.65 pb^{-1}")
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

DrawOverlap(files, ['Charge/h_InvMass'],['M_{ee}', ytitle], legend,'Dielectronmass',[0,400,1])
DrawOverlap(files, ['Charge/h_InvMass'],['M_{ee}', ytitle], legend,'Dielectronmass60120',[60,120,1])
DrawOverlap(files, ['Charge/h_InvMass'],['M_{ee}', ytitle], legend,'Dielectronmass060',[0,60,1])
DrawOverlap(files, ['Charge/h_InvMass'],['M_{ee}', ytitle], legend,'Dielectronmass120300',[120,300,1])

DrawOverlap(files, ['Charge/h_pt'],['p_{T}^{ee}', ytitle], legend,'Dielectronpt',[0,200,2])
DrawOverlap(files, ['Charge/h_eta'],['#eta_{ee}', ytitle], legend,'Dielectroneta')
DrawOverlap(files, ['Charge/h_phi'],['#phi_{ee} ', ytitle], legend,'Dielectronphi')
DrawOverlap(files, ['Charge/h_rapidity'],['Rapidity_{ee}', ytitle], legend,'DielectronRapidity')

DrawOverlap(files, ['Charge/h_DeltaR'],['#DeltaR_{ee}', ytitle], legend,'DielectronDeltaR')
DrawOverlap(files, ['Charge/h_DeltaPhi'],['#Delta#phi_{ee}', ytitle], legend,'DielectronDeltaphi')
DrawOverlap(files, ['Charge/h_DeltaEta'],['#Delta#eta_{ee}', ytitle], legend,'DielectronDeltaeta')

DrawOverlap(files, ['Electron_NoCut_/h_pt4'],['p_{T}^{ele}', ytitle], legend,'Electronpt',[0,400,1])
DrawOverlap(files, ['Electron_NoCut_/h_eta4'],['#eta_{ele}', ytitle], legend,'Electroneta')
DrawOverlap(files, ['Electron_NoCut_/h_phi4'],['#phi_{ele}', ytitle], legend,'Electronphi')

DrawOverlap(files, ['Electron_NoCut_/h_pt0'],['p_{T}^{ele}(leading)', ytitle], legend,'Electronptle',[0,400,1])
DrawOverlap(files, ['Electron_NoCut_/h_eta0'],['#eta_{ele}(leading)', ytitle], legend,'Electronetale')
DrawOverlap(files, ['Electron_NoCut_/h_phi0'],['#phi_{ele}(leading)', ytitle], legend,'Electronphile')

DrawOverlap(files, ['Electron_NoCut_/h_pt1'],['p_{T}^{ele}(sub-leading)', ytitle], legend,'Electronptsub',[0,400,1])
DrawOverlap(files, ['Electron_NoCut_/h_eta1'],['#eta_{ele}(sub-leading)', ytitle], legend,'Electronetasub')
DrawOverlap(files, ['Electron_NoCut_/h_phi1'],['#phi_{ele}(sub-leading)', ytitle], legend,'Electronphisub')




#DrawOverlap(files, ['Charge/h_'],['', ytitle], legend,'Dielectron')







#xrange_ = [0,5,2]
#DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt10','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt15','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt20','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt25','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt30'],['#DeltaR(b1-j1)',ytitle], legend,'deltaRLeadingB0',xrange_)

