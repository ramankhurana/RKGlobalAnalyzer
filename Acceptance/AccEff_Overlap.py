### Overlapping script for TGraph for MET Scanning ###
#### MONIka MIttal khurana#####################################

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
    leg = TLegend(0.44, 0.25, 0.75, 0.35)#,NULL,"brNDC");
    leg.SetNColumns(1);
    leg.SetBorderSize(0)
    leg.SetLineColor(1)
    leg.SetLineStyle(1)
    leg.SetLineWidth(1)
    leg.SetFillColor(0)
    leg.SetFillStyle(0)
    leg.SetTextFont(22)
    leg.SetTextSize(0.045)
     
    c = TCanvas("c1", "c1",0,0,700,500)
    c.SetBottomMargin(0.15)
    c.SetLeftMargin(0.15)
    c.SetLogy(0)
    c.SetLogx(1)
    c.SetGridx()
    c.SetGridy()    
    
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
#            histList[ii].Rebin(4)
#            if NORMALIZETO1 :
#                histList[ii].Scale(1.0/histList[ii].Integral())

#            if NORMALIZETO1 == False :
#                if ii > 0 :
#                    histList[ii].Scale(histList[0].Integral()/histList[ii].Integral())

            maximum.append(histList[ii].GetMaximum())
            ii=ii+1

    print histList
    for ih in range(len(histList)):
        histList[ih].SetMaximum(1.0) #1.4 for log
        histList[ih].SetMinimum(0.0)
        print ih
        if ih > 0 :
#            histList[ih].SetLineColor(colors[ih])
#            histList[ih].SetLineWidth(2)
            
            histList[ih].Draw("PE1 same") 
        if ih == 0 :
        #    histList[ih].SetMarkerStyle(20)
            histList[ih].Draw("PE1") 
        
        histList[ih].SetMarkerStyle(20)
        histList[ih].SetMarkerColor(colors[ih])
        histList[ih].SetMarkerSize(0.95)
        histList[ih].SetMarkerStyle(markerStyle[ih])        
        histList[ih].GetXaxis().SetTitleSize(0.05)
        histList[ih].GetXaxis().SetLabelSize(.05)
        histList[ih].GetXaxis().SetMoreLogLabels() 
        histList[ih].GetXaxis().SetNoExponent()
        histList[ih].GetXaxis().SetTitleOffset(0.95)
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
        histList[ih].GetXaxis().SetNdivisions(508)
        histList[ih].GetYaxis().SetNdivisions(508)
        histList[1].GetXaxis().SetLabelOffset(0.01);
 #       histList[1].GetXaxis().SetLabelSize(0);
#        histList[ih].Draw("same")
        if ih > 0 :        
            leg.AddEntry(histList[ih],legendtext[ih],"P")
        if ih == 0 :
            leg.AddEntry(histList[ih],legendtext[ih],"P")
        i=i+1



    pt = TPaveText(0.05028736,0.8305085,0.8807471,0.8919492,"brNDC")    
 ## pt = TPaveText(0.1277181,0.9,0.9580537,0.96,"brNDC")
    pt.SetBorderSize(0)
    pt.SetTextAlign(22)
    pt.SetFillStyle(0)
    pt.SetTextFont(61)
    pt.SetTextSize(0.043)
    text = pt.AddText(0.20,0.5,"CMS")
     # text = pt.AddText(0.4,0.8,"2015, 13 TeV")  #scale[0.45]{#int}L= 1.1 fb^{-1}")
    pt.Draw()


    pt2 = TPaveText(0.05028736,0.7817797,0.8807471,0.8432203,"brNDC");
     ## pt = TPaveText(0.1277181,0.9,0.9580537,0.96,"brNDC")
    pt2.SetBorderSize(0)
    pt2.SetTextAlign(22)
    pt2.SetFillStyle(0)
    pt2.SetTextFont(52)
    pt2.SetTextSize(0.043)
    text = pt2.AddText(0.22,0.5,"Simulation")
     # text = pt.AddText(0.4,0.8,"2015, 13 TeV")  #scale[0.45]{#int}L= 1.1 fb^{-1}")
    pt2.Draw()

    


    pt1 =TPaveText(0.1277181,0.9,0.9580537,0.96,"brNDC")
    pt1.SetBorderSize(0)
    pt1.SetTextAlign(12)
    pt1.SetFillStyle(0)
    pt1.SetTextFont(22)
    pt1.SetTextSize(0.043)
    text = pt1.AddText(0.7,0.5,"2015, 13 TeV")
    pt1.Draw()

    leg.Draw()
                  

    
    histname='DYPlots/'+pngname
    c.SaveAs(histname+'.png')
    c.SaveAs(histname+'.pdf')
    c.SaveAs(histname+'.root')


print "calling the plotter"

#files=['AccAndEff.root']
files=['AccEff_All4.root']
files1=['METScan_EffAnalysisHistoFilterFix.root','METScan_EffAnalysisHistoFilterFixHBHEFix.root']
ytitle='Acceptance'
legend =['Reco','Gen']
legend1 =['HCALStrp','AllCSCTH2015','AllCSCTHMu','AllHCALStrp','AllCSCTH2015HCALStrp','AllCSCTH2015HCALStrpIsolation','AllCSCTH2015Isolatn']




DrawOverlap(files,['h_ZMass_Acc_Reco_h_ZMass','h_ZMass_Acc_Gen_h_ZMass'],['Gen-Level Post-FSR M_{ee} [GeV]',ytitle],legend,'AcceptanceFinal')
DrawOverlap(files,['h_ZMass_Trig_h_ZMass_Acc_Gen','h_ZMass_TrigDE_h_ZMass_Acc_Gen'],['Gen-Level Post-FSR M_{ee} [GeV]','Efficiency'],['Ele22_eta2p1_WP75','Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ'],'TriggerFinal')
DrawOverlap(files,['h_ZMass_ID_h_ZMass_Acc_Gen','h_ZMass_HEEPID_h_ZMass_Acc_Gen','h_ZMass_HEEPID_NoIso_h_ZMass_Acc_Gen'],['Gen-Level Post-FSR M_{ee} [GeV]','Efficiency'],['Medium ID','HEEP ID','HEEP ID (No Isolation)'], 'IDFinal')

DrawOverlap(files,[ 'h_ZMass_AE_DETrig_h_ZMass_Acc_Gen','h_ZMass_AE_DETrig_HEEP_h_ZMass_Acc_Gen','h_ZMass_AE_DETrig_HEEP_NoIso_h_ZMass_Acc_Gen'],['Gen-Level Post-FSR M_{ee} [GeV]','Efficiency'],['Medium ID+ DE Trig','HEEP ID + DE Trig','HEEP ID(no Iso)+DE Trig'], 'EffDEFinal')
DrawOverlap(files,[ 'h_ZMass_AE_h_ZMass_Acc_Gen','h_ZMass_AE_Trig_HEEP_h_ZMass_Acc_Gen','h_ZMass_AE_Trig_HEEP_NoIso_h_ZMass_Acc_Gen'],['Gen-Level Post-FSR M_{ee} [GeV]','Efficiency'],['Medium ID+ SE Trig','HEEP ID + SE Trig','HEEP ID(no Iso)+SE Trig'], 'EffSEFinal')

DrawOverlap(files,[ 'h_ZMass_AE_DETrig_h_ZMass','h_ZMass_AE_DETrig_HEEP_h_ZMass','h_ZMass_AE_DETrig_HEEP_NoIso_h_ZMass'],['Gen-Level Post-FSR M_{ee} [GeV]','Acceptance*Efficiency'],['Medium ID+ DE Trig','HEEP ID + DE Trig','HEEP ID(no Iso)+DE Trig'], 'AEDEFinal')
DrawOverlap(files,[ 'h_ZMass_AE_h_ZMass','h_ZMass_AE_Trig_HEEP_h_ZMass','h_ZMass_AE_Trig_HEEP_NoIso_h_ZMass'],['Gen-Level Post-FSR M_{ee} [GeV]','Acceptance*Efficiency'],['Medium ID+ SE Trig','HEEP ID + SE Trig','HEEP ID(no Iso)+SE Trig'], 'AESEFinal')




