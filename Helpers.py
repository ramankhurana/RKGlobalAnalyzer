from ROOT import TFile, TH1F, gDirectory, TCanvas
from ROOT import gStyle
from ROOT import gROOT
from ROOT import TStyle
from ROOT import TLegend
from ROOT import TPaveText
import os

colors=[1,2,3,4,5,6,7]

def SetStyle():
    gStyle.SetOptTitle(0)
    gStyle.SetOptStat(0)
    gStyle.SetTitleOffset(1.1,"Y");
    gStyle.SetTitleOffset(0.9,"X");
    gStyle.SetLineWidth(3)
    gStyle.SetFrameLineWidth(3);
    return 0


def SetLegend():    ## Legend
    leg = TLegend(0.72, 0.72, 0.89, 0.89)#,NULL,"brNDC");
    leg.SetBorderSize(0)
    leg.SetLineColor(1)
    leg.SetLineStyle(1)
    leg.SetLineWidth(1)
    leg.SetFillColor(0)
    leg.SetFillStyle(0)
    leg.SetTextFont(22)
    leg.SetTextSize(0.05);
    return leg


def SetCanvas():
    c = TCanvas("c1", "c1",0,0,560,560)
    c.SetBottomMargin(0.15)
    c.SetLeftMargin(0.15)
    return c

def SetPaveText(left='CMS Simulation',right='#sqrt{s} = 13 TeV'):    
    pt = TPaveText(0.1577181,0.9,0.9580537,0.96,"brNDC")
    pt.SetBorderSize(0)
    pt.SetTextAlign(12)
    pt.SetFillStyle(0)
    pt.SetTextFont(22)
    pt.SetTextSize(0.045)
    text = pt.AddText(0.01,0.5,left)
    text = pt.AddText(0.4,0.5,right)
    return pt

def SavePlots(pngname,c):
    histname='Plots75/'+pngname
    c.SaveAs(histname+'.png')
    c.SaveAs(histname+'.pdf')
    return 0
