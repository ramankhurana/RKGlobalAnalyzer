import sys
sys.argv.append( '-b-' )


from ROOT import TFile, TH1F, gDirectory, TCanvas, TPad, TProfile
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
            histList[ii].Rebin(xRange[2])
         #   histList[ii].Scale(1.0/histList[ii].Integral())
            maximum.append(histList[ii].GetMaximum())
            ii=ii+1

    print histList
    for ih in range(len(histList)):
        histList[ih].SetMaximum(max(maximum)*1.2) #1.4 for log
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
        histList[ih].GetYaxis().SetTitleOffset(1.2)
        histList[ih].GetYaxis().SetTitleFont(22)
        histList[ih].GetYaxis().SetLabelFont(22)
        histList[ih].GetYaxis().SetLabelSize(.05)
        histList[ih].GetXaxis().SetTitle(titleVec[0])
        histList[ih].GetXaxis().SetRangeUser(xRange[0],xRange[1])
        histList[ih].GetXaxis().SetNdivisions(508)
        histList[ih].GetYaxis().SetNdivisions(508)
        histList[1].GetXaxis().SetLabelOffset(999);
        histList[1].GetXaxis().SetLabelSize(0);
        
        leg.AddEntry(histList[ih],legendtext[ih],"L")
        i=i+1
    pt = TPaveText(0.1277181,0.9,0.9580537,0.96,"brNDC")
    pt.SetBorderSize(0)
    pt.SetTextAlign(12)
    pt.SetFillStyle(0)
    pt.SetTextFont(22)
    pt.SetTextSize(0.043)
    text = pt.AddText(0.01,0.5,"CMS Preliminary")
    text = pt.AddText(0.4,0.5,"#sqrt{s} = 13 TeV  #scale[0.45]{#int}L= 40 pb^{-1}")
    pt.Draw()
    leg.Draw()
                  

    
    histname='PlotsRaman/'+pngname
    c.SaveAs(histname+'.png')
    c.SaveAs(histname+'.pdf')


print "calling the plotter"
files=['/afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/OutputRootFile/Data.root','/afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/OutputRootFile/MC.root']
##ytitle='# of Events (Normalized to 1)'
ytitle='# of Events'
legend =['Data','MC']
#legend=['p_{T}>10 GeV','p_{T}>15 GeV','p_{T}>20 GeV','p_{T}>25 GeV','p_{T}>30 GeV']


DrawOverlap(files, ['FatJets/p_Nvtx_jetCEmEF'],['# of Vertices','jetCEmEF'], legend,'Profile_Nvtx_jetCEmEF')
DrawOverlap(files, ['FatJets/p_Nvtx_jetCHadEF'],['# of Vertices','jetCHadEF'], legend,'Profile_Nvtx_jetCHadEF')
DrawOverlap(files, ['FatJets/p_Nvtx_jetPhoEF'],['# of Vertices','jetPhoEF'], legend,'Profile_Nvtx_jetPhoEF')
DrawOverlap(files, ['FatJets/p_Nvtx_jetNEmEF'],['# of Vertices','jetNEmEF'], legend,'Profile_Nvtx_jetNEmEF')
DrawOverlap(files, ['FatJets/p_Nvtx_jetNHadEF'],['# of Vertices','jetNHadEF'], legend,'Profile_Nvtx_jetNHadEF')
DrawOverlap(files, ['FatJets/p_Nvtx_jetMuEF'],['# of Vertices','jetMuEF'], legend,'Profile_Nvtx_jetMuEF')
DrawOverlap(files, ['FatJets/p_Nvtx_jetCMulti'],['# of Vertices','jetCMulti'], legend,'Profile_Nvtx_jetCMulti')
DrawOverlap(files, ['FatJets/p_Nvtx_B_CISVV2'],['# of Vertices','CSV'], legend,'Profile_Nvtx_B_CISVV2')
DrawOverlap(files, ['FatJets/p_Nvtx_SDmass'],['# of Vertices','SDmass'], legend,'Profile_Nvtx_SDmass')
DrawOverlap(files, ['FatJets/p_Nvtx_TRmass'],['# of Vertices','TRmass'], legend,'Profile_Nvtx_TRmass')
DrawOverlap(files, ['FatJets/p_Nvtx_PRmass'],['# of Vertices','PRmass'], legend,'Profile_Nvtx_PRmass')
DrawOverlap(files, ['FatJets/p_Nvtx_Fimass'],['# of Vertices','Fimass'], legend,'Profile_Nvtx_Fimass')
DrawOverlap(files, ['FatJets/p_Nvtx_tau21'],['# of Vertices','tau21'], legend,'Profile_Nvtx_tau21') 

DrawOverlap(files, ['FatJets/p_pT_jetCEmEF'],['p_{T}','jetCEmEF'], legend,'Profile_pT_jetCEmEF')
DrawOverlap(files, ['FatJets/p_pT_jetCHadEF'],['p_{T}','jetCHadEF'], legend,'Profile_pT_jetCHadEF')
DrawOverlap(files, ['FatJets/p_pT_jetPhoEF'],['p_{T}','jetPhoEF'], legend,'Profile_pT_jetPhoEF')
DrawOverlap(files, ['FatJets/p_pT_jetNEmEF'],['p_{T}','jetNEmEF'], legend,'Profile_pT_jetNEmEF')
DrawOverlap(files, ['FatJets/p_pT_jetNHadEF'],['p_{T}','jetNHadEF'], legend,'Profile_pT_jetNHadEF')
DrawOverlap(files, ['FatJets/p_pT_jetMuEF'],['p_{T}','jetMuEF'], legend,'Profile_pT_jetMuEF')
DrawOverlap(files, ['FatJets/p_pT_jetCMulti'],['p_{T}','jetCMulti'], legend,'Profile_pT_jetCMulti')
DrawOverlap(files, ['FatJets/p_pT_B_CISVV2'],['p_{T}','CSV'], legend,'Profile_pT_B_CISVV2')
DrawOverlap(files, ['FatJets/p_pT_SDmass'],['p_{T}','SDmass'], legend,'Profile_pT_SDmass')
DrawOverlap(files, ['FatJets/p_pT_TRmass'],['p_{T}','TRmass'], legend,'Profile_pT_TRmass')
DrawOverlap(files, ['FatJets/p_pT_PRmass'],['p_{T}','PRmass'], legend,'Profile_pT_PRmass')
DrawOverlap(files, ['FatJets/p_pT_Fimass'],['p_{T}','Fimass'], legend,'Profile_pT_Fimass')
DrawOverlap(files, ['FatJets/p_pT_tau21'],['p_{T}','tau21'], legend,'Profile_pT_tau21') 


DrawOverlap(files, ['FatJets/p_Eta_jetCEmEF'],['#eta','jetCEmEF'], legend,'Profile_Eta_jetCEmEF')
DrawOverlap(files, ['FatJets/p_Eta_jetCHadEF'],['#eta','jetCHadEF'], legend,'Profile_Eta_jetCHadEF')
DrawOverlap(files, ['FatJets/p_Eta_jetPhoEF'],['#eta','jetPhoEF'], legend,'Profile_Eta_jetPhoEF')
DrawOverlap(files, ['FatJets/p_Eta_jetNEmEF'],['#eta','jetNEmEF'], legend,'Profile_Eta_jetNEmEF')
DrawOverlap(files, ['FatJets/p_Eta_jetNHadEF'],['#eta','jetNHadEF'], legend,'Profile_Eta_jetNHadEF')
DrawOverlap(files, ['FatJets/p_Eta_jetMuEF'],['#eta','jetMuEF'], legend,'Profile_Eta_jetMuEF')
DrawOverlap(files, ['FatJets/p_Eta_jetCMulti'],['#eta','jetCMulti'], legend,'Profile_Eta_jetCMulti')
DrawOverlap(files, ['FatJets/p_Eta_B_CISVV2'],['#eta','CSV'], legend,'Profile_Eta_B_CISVV2')
DrawOverlap(files, ['FatJets/p_Eta_SDmass'],['#eta','SDmass'], legend,'Profile_Eta_SDmass')
DrawOverlap(files, ['FatJets/p_Eta_TRmass'],['#eta','TRmass'], legend,'Profile_Eta_TRmass')
DrawOverlap(files, ['FatJets/p_Eta_PRmass'],['#eta','PRmass'], legend,'Profile_Eta_PRmass')
DrawOverlap(files, ['FatJets/p_Eta_Fimass'],['#eta','Fimass'], legend,'Profile_Eta_Fimass')
DrawOverlap(files, ['FatJets/p_Eta_tau21'],['#eta','tau21'], legend,'Profile_Nvtx_tau21') 


DrawOverlap(files, ['FatJets/p_Phi_jetCEmEF'],['#phi','jetCEmEF'], legend,'Profile_Phi_jetCEmEF')
DrawOverlap(files, ['FatJets/p_Phi_jetCHadEF'],['#phi','jetCHadEF'], legend,'Profile_Phi_jetCHadEF')
DrawOverlap(files, ['FatJets/p_Phi_jetPhoEF'],['#phi','jetPhoEF'], legend,'Profile_Phi_jetPhoEF')
DrawOverlap(files, ['FatJets/p_Phi_jetNEmEF'],['#phi','jetNEmEF'], legend,'Profile_Phi_jetNEmEF')
DrawOverlap(files, ['FatJets/p_Phi_jetNHadEF'],['#phi','jetNHadEF'], legend,'Profile_Phi_jetNHadEF')
DrawOverlap(files, ['FatJets/p_Phi_jetMuEF'],['#phi','jetMuEF'], legend,'Profile_Phi_jetMuEF')
DrawOverlap(files, ['FatJets/p_Phi_jetCMulti'],['#phi','jetCMulti'], legend,'Profile_Phi_jetCMulti')
DrawOverlap(files, ['FatJets/p_Phi_B_CISVV2'],['#phi','CSV'], legend,'Profile_Phi_B_CISVV2')
DrawOverlap(files, ['FatJets/p_Phi_SDmass'],['#phi','SDmass'], legend,'Profile_Phi_SDmass')
DrawOverlap(files, ['FatJets/p_Phi_TRmass'],['#phi','TRmass'], legend,'Profile_Phi_TRmass')
DrawOverlap(files, ['FatJets/p_Phi_PRmass'],['#phi','PRmass'], legend,'Profile_Phi_PRmass')
DrawOverlap(files, ['FatJets/p_Phi_Fimass'],['#phi','Fimass'], legend,'Profile_Phi_Fimass')
DrawOverlap(files, ['FatJets/p_Phi_tau21'],['#phi','tau21'], legend,'Profile_Phi_tau21') 






####DrawOverlap(files, ['Electron_NoCut_/h_phi1'],['#phi_{ele}(sub-leading)', ytitle], legend,'Electronphisub')

