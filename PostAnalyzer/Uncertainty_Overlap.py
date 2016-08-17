# In this at the end of filevector I am putting the dirname
# so loop over n-1 files and n will give the name of the output dir.

# In legend also the n element will give the name for the ratio plot y axis label.
#edited by Monika Mittal 
#Script for ratio plot 
import sys
sys.argv.append( '-b-' )

from ROOT import TFile, TH1F, gDirectory, TCanvas, TPad, TProfile#,TGraph, TGraphAsymmErrors
from ROOT import gStyle
from ROOT import gROOT
from ROOT import TStyle
from ROOT import TLegend
from ROOT import TMath
from ROOT import TPaveText
from ROOT import TLatex

import os
colors=[1,2,4,5,6,7,8,2,13]
markerStyle=[20,21,22,23,24,25,26,27,28,29]
linestyle=[1,2,2,1,1,1]

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
    histList1=[]
    maximum=[]
    
    ## Legend    
    leg = TLegend(0.55, 0.70, 0.89, 0.89)#,NULL,"brNDC");
    leg.SetBorderSize(0)
    leg.SetLineColor(1)
    leg.SetLineStyle(1)
    leg.SetLineWidth(1)
    leg.SetFillColor(0)
    leg.SetFillStyle(0)
    leg.SetTextFont(22)
    leg.SetTextSize(0.05)
     
    c = TCanvas("c1", "c1",0,0,500,500)
    #c.SetBottomMargin(0.15)
    #c.SetLeftMargin(0.15)
    #c.SetLogy(0)
    #c.SetLogx(0)
    c1_2 = TPad("c1_2","newpad",0,0.11,1,0.994)
    c1_2.Draw()

    
    print ("you have provided "+str(len(fileVec))+" files and "+str(len(histVec))+" histograms to make a overlapping plot" )
    print "opening rootfiles"
    c.cd()
    c1_2.SetBottomMargin(0.013)
    c1_2.SetLogy(0)
    c1_2.SetLogx(1)
    
    c1_2.cd()
    ii=0    
    inputfile={}
    print str(fileVec[(len(fileVec)-1)])

    for ifile_ in range(len(fileVec)-1):
        print ("opening file  "+fileVec[ifile_])
        inputfile[ifile_] = TFile( fileVec[ifile_] )
        print "fetching histograms"
        for ihisto_ in range(len(histVec)-1):
            print ("printing histo "+str(histVec[ihisto_]))
            histo = inputfile[ifile_].Get(histVec[ihisto_])
            histList.append(histo)
            # for ratio plot as they should nt be normalize 
            histList1.append(histo)
            print histList[ii].Integral()
            #histList[ii].Rebin(xRange[2])
            #histList[ii].Scale(1.0/histList[ii].Integral())
            maximum.append(histList[ii].GetMaximum())
            maximum.sort()
            ii=ii+1

    print histList
    for ih in range(len(histList)):
        histList[ih].SetMaximum(maximum[(len(maximum)-1)]*1.2) #1.4 for log
     #   histList[ih].SetMarkerColor(colors[ih])            
     #   histList[ih].SetMarkerSize(0.6)
        histList[ih].SetLineStyle(linestyle[ih])
        histList[ih].SetLineColor(colors[ih])
        histList[ih].SetLineWidth(3)
      
        if ih == 0 :      
            histList[ih].Draw("hist")
        if ih > 0 :
            #histList[ih].SetLineWidth(2)
            histList[ih].Draw("hist same")
        histList[ih].GetYaxis().SetTitle(titleVec[1])
        histList[ih].GetYaxis().SetTitleSize(0.052)
        histList[ih].GetYaxis().SetTitleOffset(0.88)
        histList[ih].GetYaxis().SetTitleFont(22)
        histList[ih].GetYaxis().SetLabelFont(22)
        histList[ih].GetYaxis().SetLabelSize(.06)
        histList[ih].GetXaxis().SetRangeUser(xRange[0],xRange[1])
        histList[ih].GetXaxis().SetLabelSize(0.0000);
        histList[ih].GetXaxis().SetTitle(titleVec[0])
        histList[ih].GetXaxis().SetLabelSize(0.054)
        histList[ih].GetXaxis().SetTitleSize(0.056)
        histList[ih].GetXaxis().SetTitleOffset(0.91)
        histList[ih].GetXaxis().SetTitleFont(22)
        histList[ih].GetXaxis().SetTickLength(0.07)
        histList[ih].GetXaxis().SetLabelFont(22)
        histList[ih].GetYaxis().SetLabelFont(22) 
        histList[ih].GetXaxis().SetNdivisions(508)
        histList[ih].GetXaxis().SetMoreLogLabels(); 
        histList[ih].GetXaxis().SetNoExponent();
        histList[ih].GetXaxis().SetNdivisions(508);
        leg.AddEntry(histList[ih],legendtext[ih],"L")
        i=i+1
    pt = TPaveText(0.0877181,0.9,0.9580537,0.96,"brNDC")
    pt.SetBorderSize(0)
    pt.SetTextAlign(12)
    pt.SetFillStyle(0)
    pt.SetTextFont(22)
    pt.SetTextSize(0.046)
    text = pt.AddText(0.01,0.5,"CMS Simulation")
    text = pt.AddText(0.41,0.5,"(#sqrt{s} = 13 TeV #scale[0.45]{#int}L=2.3 fb^{-1})")
    pt.Draw()
   
    

    t2a = TPaveText(0.0877181,0.81,0.9580537,0.89,"brNDC")
    t2a.SetBorderSize(0)
    t2a.SetFillStyle(0)
    t2a.SetTextSize(0.040) 
    t2a.SetTextAlign(12)
    t2a.SetTextFont(62)
    histolabel1= str(fileVec[(len(fileVec)-1)])
    text1 = t2a.AddText(0.06,0.5,histolabel1) 
    t2a.Draw()

    t2b = TPaveText(0.5077181,0.60,0.9580537,0.67,"brNDC")
    t2b.SetBorderSize(0)
    t2b.SetFillStyle(0)
    t2b.SetTextSize(0.046) 
    t2b.SetTextAlign(12)
    t2b.SetTextFont(62)
    t2b.SetTextColor(2)
    histolabel =(str(histVec[(len(histVec)-1)]))
    text1 = t2b.AddText(0.40,0.5,histolabel) 
  
    t2b.Draw()

    leg.Draw()









    c.cd()
    outputdirname = 'Uncertainty/'
#    outputdirname = str(fileVec[(len(fileVec)-1)])+'/'
    histname=outputdirname+pngname 
    c.SaveAs(histname+'.png')
    c.SaveAs(histname+'.pdf')
    outputname = 'cp  -r '+ outputdirname +' /afs/hep.wisc.edu/home/khurana/public_html/'
    os.system(outputname) 
    
print "calling the plotter"
files=['/afs/hep.wisc.edu/cms/khurana/Script/CMSSW_7_4_1/src/DarkMatterBkg/MonoHFatJetSelection_JetAndLeptonVeto.root','SR(boosted)']
files1=['/afs/hep.wisc.edu/cms/khurana/Script/CMSSW_7_4_1/src/DarkMatterBkg/histfacFatJet_WHeavy.root','1-lepton CR(boosted)']
files2=['/afs/hep.wisc.edu/cms/khurana/Script/CMSSW_7_4_1/src/DarkMatterBkg/histfacFatJet_ZLight.root','Mass sideband(boosted)']

legend_R =['Nominal','#mu^{R}(Up)','#mu^{R}(Down)']
legend_F =['Nominal','#mu^{F}(Up)','#mu^{F}(Down)']
legend_EWK =['Nominal','EWK(Up)','EWK(Down)']
legend_TT=['Nominal','p_{T}^{reweight}(Up)','p_{T}^{reweight}(Down)']

histoname1=['TTJets','TTJets_muRUp','TTJets_muRDown','Top']
histoname2=['TTJets','TTJets_muFUp','TTJets_muFDown','Top']
histoname3=['TTJets','TTJets_EWKUp','TTJets_EWKDown','Top']

histoname11=['DYJets','DYJets_muRUp','DYJets_muRDown','Zj']
histoname12=['DYJets','DYJets_muFUp','DYJets_muFDown','Zj']
histoname13=['DYJets','DYJets_EWKUp','DYJets_EWKDown','Zj']

histoname21=['WJets','WJets_muRUp','WJets_muRDown','Wj']
histoname22=['WJets','WJets_muFUp','WJets_muFDown','Wj']
histoname23=['WJets','WJets_EWKUp','WJets_EWKDown','Wj']


ytitle='No. of Events'


DrawOverlap(files,histoname1,['E_{T}^{Miss}[GeV]',ytitle],legend_R,'SR_TT_MuR',[0.,3000.] )
DrawOverlap(files,histoname2,['E_{T}^{Miss}[GeV]',ytitle],legend_F,'SR_TT_MuF',[0.,3000.] )
DrawOverlap(files,histoname3,['E_{T}^{Miss}[GeV]',ytitle],legend_TT,'SR_TT_EWK',[0.,3000.] )
DrawOverlap(files,histoname11,['E_{T}^{Miss}[GeV]',ytitle],legend_R,'SR_DY_MuR',[0.,3000.] )
DrawOverlap(files,histoname12,['E_{T}^{Miss}[GeV]',ytitle],legend_F,'SR_DY_MuF',[0.,3000.] )
DrawOverlap(files,histoname13,['E_{T}^{Miss}[GeV]',ytitle],legend_EWK,'SR_DY_EWK',[0.,3000.] )
DrawOverlap(files,histoname21,['E_{T}^{Miss}[GeV]',ytitle],legend_R,'SR_WJets_MuR',[0.,3000.] )
DrawOverlap(files,histoname22,['E_{T}^{Miss}[GeV]',ytitle],legend_F,'SR_WJets_MuF',[0.,3000.] )
DrawOverlap(files,histoname23,['E_{T}^{Miss}[GeV]',ytitle],legend_EWK,'SR_WJets_EWK',[0.,3000.] )

DrawOverlap(files1,histoname1,['E_{T}^{Miss}[GeV]',ytitle],legend_R,'WHeavy_TT_MuR',[0.,3000.] )
DrawOverlap(files1,histoname2,['E_{T}^{Miss}[GeV]',ytitle],legend_F,'WHeavy_TT_MuF',[0.,3000.] )
DrawOverlap(files1,histoname3,['E_{T}^{Miss}[GeV]',ytitle],legend_TT,'WHeavy_TT_EWK',[0.,3000.] )
DrawOverlap(files1,histoname11,['E_{T}^{Miss}[GeV]',ytitle],legend_R,'WHeavy_DY_MuR',[0.,3000.] )
DrawOverlap(files1,histoname12,['E_{T}^{Miss}[GeV]',ytitle],legend_F,'WHeavy_DY_MuF',[0.,3000.] )
DrawOverlap(files1,histoname13,['E_{T}^{Miss}[GeV]',ytitle],legend_EWK,'WHeavy_DY_EWK',[0.,3000.] )
DrawOverlap(files1,histoname21,['E_{T}^{Miss}[GeV]',ytitle],legend_R,'WHeavy_WJets_MuR',[0.,3000.] )
DrawOverlap(files1,histoname22,['E_{T}^{Miss}[GeV]',ytitle],legend_F,'WHeavy_WJets_MuF',[0.,3000.] )
DrawOverlap(files1,histoname23,['E_{T}^{Miss}[GeV]',ytitle],legend_EWK,'WHeavy_WJets_EWK',[0.,3000.] )

DrawOverlap(files2,histoname1,['E_{T}^{Miss}[GeV]',ytitle],legend_R,'ZLight_TT_MuR',[0.,3000.] )
DrawOverlap(files2,histoname2,['E_{T}^{Miss}[GeV]',ytitle],legend_F,'ZLight_TT_MuF',[0.,3000.] )
DrawOverlap(files2,histoname3,['E_{T}^{Miss}[GeV]',ytitle],legend_TT,'ZLight_TT_EWK',[0.,3000.] )
DrawOverlap(files2,histoname11,['E_{T}^{Miss}[GeV]',ytitle],legend_R,'ZLight_DY_MuR',[0.,3000.] )
DrawOverlap(files2,histoname12,['E_{T}^{Miss}[GeV]',ytitle],legend_F,'ZLight_DY_MuF',[0.,3000.] )
DrawOverlap(files2,histoname13,['E_{T}^{Miss}[GeV]',ytitle],legend_EWK,'ZLight_DY_EWK',[0.,3000.] )
DrawOverlap(files2,histoname21,['E_{T}^{Miss}[GeV]',ytitle],legend_R,'ZLight_WJets_MuR',[0.,3000.] )
DrawOverlap(files2,histoname22,['E_{T}^{Miss}[GeV]',ytitle],legend_F,'ZLight_WJets_MuF',[0.,3000.] )
DrawOverlap(files2,histoname23,['E_{T}^{Miss}[GeV]',ytitle],legend_EWK,'ZLight_WJets_EWK',[0.,3000.] )


