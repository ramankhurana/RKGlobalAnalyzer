import sys
sys.argv.append( '-b-' )
from ROOT import TFile, TH1F, gDirectory, TCanvas, TPad, TProfile, TGraph, TGraphAsymmErrors
from ROOT import gStyle
from ROOT import gROOT
from ROOT import TStyle
from ROOT import TLegend
from ROOT import TPaveText
import os

colors=[1,2,3,4,6,7,8]
markerStyle=[20,21,22,23,24,25,26,27]
def DrawOverlap(fileVec, histVec, titleVec,legendtext,pngname,xRange=[-99999,99999,1]):
    gStyle.SetOptTitle(0)
    gStyle.SetOptStat(0)
    gStyle.SetTitleOffset(1.1,"Y");
    gStyle.SetTitleOffset(0.9,"X");
    gStyle.SetLineWidth(3)
    gStyle.SetFrameLineWidth(3);
    i=0

    histList_=[]
    maximum=[]
    histList=[]
    
    ## Legend
    leg = TLegend(0.72, 0.72, 0.89, 0.89)#,NULL,"brNDC");
    leg.SetBorderSize(0)
    leg.SetLineColor(1)
    leg.SetLineStyle(1)
    leg.SetLineWidth(1)
    leg.SetFillColor(0)
    leg.SetFillStyle(0)
    leg.SetTextFont(22)

     
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
            print ihisto_           
            histList.append(histo)
         #   print histList[ii].Integral()
         #   histList[ii].Rebin(xRange[2])
         #   histList[ii].Scale(1.0/histList[ii].Integral())
         #   maximum.append(histList[ii].GetMaximum())
            ii=ii+1

    print histList
    for ih in range(len(histList)):
        histList[ih].SetMaximum(1) #1.4 for log
        histList[ih].SetMinimum(0)
        if ih == 0 :      
            histList[ih].Draw("AP")
        if ih > 0 :
            histList[ih].Draw("sameP")
        
        #histList[ih].SetLineColor(colors[ih])
        #histList[ih].SetLineWidth(2)
        
        histList[ih].SetMarkerColor(colors[ih])
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
       # histList[ih].GetXaxis().SetRangeUser()
          
        histList[ih].GetXaxis().SetNdivisions(510)
        histList[ih].GetYaxis().SetNdivisions(508)
        histList[1].GetXaxis().SetLabelOffset(999);
        histList[1].GetXaxis().SetLabelSize(0);
        
        leg.AddEntry(histList[ih],legendtext[ih],"P")
        i=i+1
    pt = TPaveText(0.1277181,0.9,0.9580537,0.96,"brNDC")
    pt.SetBorderSize(0)
    pt.SetTextAlign(12)
    pt.SetFillStyle(0)
    pt.SetTextFont(22)
    pt.SetTextSize(0.043)
    text = pt.AddText(0.01,0.5,"CMS Simulation")
    text = pt.AddText(0.4,0.5,"#sqrt{s} = 13 TeV" ) #scale[0.45]{#int}L= 40 pb^{-1}")
    pt.Draw()
    leg.Draw()
                  

    
    histname='PlotsRaman_VeniceConf/'+pngname
    c.SaveAs(histname+'.png')
    c.SaveAs(histname+'.pdf')


print "calling the plotter"
files=['/afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_7_patch1/src/RootFiles/fatjet.root','/afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_7_patch1/src/RootFiles/twosubjets.root', '/afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_7_patch1/src/RootFiles/onesubjets.root', '/afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_7_patch1/src/RootFiles/drsubjets.root', '/afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_7_patch1/src/RootFiles/drsubjets.root' ]
##ytitle='# of Events (Normalized to 1)'
ytitle='\#Sigma_{Z`\#rightarrowA0 h\#rightarrow 2DM bb}'
legend =['AK8jet ','2Subjet','1Subjet','\#Delta R','2SJ+1SJ']
#legend=['p_{T}>10 GeV','p_{T}>15 GeV','p_{T}>20 GeV','p_{T}>25 GeV','p_{T}>30 GeV']


DrawOverlap(files,['LimitExpectedCLs'],['M_{Z`}',ytitle],legend,'Limit')



#DrawOverlap(['SignalEff_Graph_Bin_2.root'], ['CutFlowAndEachCutFatJet','CutFlowAndEachCutFatJet_2subj','CutFlowAndEachCutFatJet_1subj','CutFlowAndEachCutFatJet_DRsubj','Subjet1PlusSubjet2'],['M_{Z`}','Efficiency'], legend,'SignalEff_2')
#DrawOverlap(['SignalEff_Graph_Bin_5.root'], ['CutFlowAndEachCutFatJet','CutFlowAndEachCutFatJet_2subj','CutFlowAndEachCutFatJet_1subj','CutFlowAndEachCutFatJet_DRsubj','Subjet1PlusSubjet2'],['M_{Z`}','Efficiency'], legend,'SignalEff_5')






####DrawOverlap(files, ['Electron_NoCut_/h_phi1'],['#phi_{ele}(sub-leading)', ytitle], legend,'Electronphisub')

