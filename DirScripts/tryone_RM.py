import sys
sys.argv.append( '-b-' )

from Helpers import *
from ROOT import TFile, TH1F, TH2F, gDirectory, TCanvas
from ROOT import gStyle
from ROOT import gROOT
from ROOT import TStyle
from ROOT import TLegend
from ROOT import TPaveText
import os

def FileToList(fileName):
    row = [[]] 
    crimefile = open(fileName, 'r') 
    for line in crimefile.readlines(): 
        tmp = []
        for element in line[0:-1].split(' '):
            tmp.append(element)
        row.append(tmp)
    return row

list74=FileToList('ListofEvents_74_ori.txt')
list75=FileToList('ListofEvents_75_ori.txt')
listsame=FileToList('ListofSameEvents.txt')



def FindIndex(list_, eventnum):
    index_=-1
    for i74 in range(len(list_)):
        if i74 ==0 : continue 
        if list_[i74][0] == eventnum :
            index_ = i74
    return index_



def SaveHisto(value_, histinfo):
    SetStyle()
    leg = SetLegend()
    c   = SetCanvas()
    c.SetLogy(0)
    mass_diff = TH1F(histinfo[0],histinfo[0],histinfo[1],histinfo[2],histinfo[3])
    for i in range(len(value_)):
        mass_ = value_[i]
        mass_diff.Fill(float(mass_[0])- float(mass_[1]))
        
    
    c.cd()
    mass_diff.Draw()
    mass_diff.GetXaxis().SetTitle(histinfo[4])
    mass_diff.GetXaxis().SetTitleSize(0.05);
    mass_diff.GetXaxis().SetTitleOffset(0.97);
    mass_diff.GetXaxis().SetTitleFont(22);
    mass_diff.GetXaxis().SetLabelFont(22);
    mass_diff.GetXaxis().SetLabelSize(.05);
    mass_diff.GetYaxis().SetTitleSize(0.05);
    mass_diff.GetYaxis().SetTitleOffset(1.);
    mass_diff.GetYaxis().SetTitleFont(22);
    mass_diff.GetYaxis().SetLabelFont(22);
    mass_diff.GetYaxis().SetLabelSize(.05);
    mass_diff.GetYaxis().SetTitle("Events")
    pt = SetPaveText("CMS Validation", "#sqrt{s}=13 TeV  #scale[0.45]{#int}L=14.65 pb^{-1}")
    pt.Draw()
    leg.Draw()
    SavePlots(histinfo[0],c)

def SaveHisto2D(value_, histinfo):
    SetStyle()
    leg = SetLegend()
    c   = SetCanvas()
    c.SetLogy(0)
    mass_2D = TH2F(histinfo[0], histinfo[0],histinfo[1],histinfo[2],histinfo[3] ,histinfo[1],histinfo[2],histinfo[3])
    for i in range(len(value_)):
        mass_ = value_[i]
        mass_2D.Fill(float(mass_[0]),float(mass_[1]))

    c.cd()
    mass_2D.Draw("colz")
    mass_2D.GetXaxis().SetTitle(histinfo[4])
    mass_2D.GetYaxis().SetTitle(histinfo[5])
    mass_2D.GetXaxis().SetTitleSize(0.05);
    mass_2D.GetXaxis().SetTitleOffset(0.97);
    mass_2D.GetXaxis().SetTitleFont(22);
    mass_2D.GetXaxis().SetLabelFont(22);
    mass_2D.GetXaxis().SetLabelSize(.05);
    mass_2D.GetYaxis().SetTitleSize(0.05);
    mass_2D.GetYaxis().SetTitleOffset(1.);
    mass_2D.GetYaxis().SetTitleFont(22);
    mass_2D.GetYaxis().SetLabelFont(22);
    mass_2D.GetYaxis().SetLabelSize(.05);
    pt = SetPaveText("CMS Validation", "#sqrt{s}=13 TeV  #scale[0.45]{#int}L=14.65 pb^{-1}")
    pt.Draw()
    leg.Draw()
    SavePlots(histinfo[0],c)

 

mass=[]
pt=[]
rapidity=[]
phi=[]
leadpt=[]
subleadpt=[]
leadeta=[]
leadphi=[]
subleadeta=[]
subleadphi=[]
for isameE in range(len(listsame)):
    if isameE ==0 : continue
        
    idx74 = FindIndex(list74,listsame[isameE][0])
    if idx74 ==-1 : continue
    idx75 = FindIndex(list75,listsame[isameE][0])
    if idx75 ==-1 : continue
    mass.append([list74[idx74][1],list75[idx75][1]])
    pt.append([list74[idx74][2],list75[idx75][2]])
    rapidity.append([list74[idx74][3],list75[idx75][3]])
    phi.append([list74[idx74][4],list75[idx75][4]])
    leadpt.append([list74[idx74][5],list75[idx75][5]])
    subleadpt.append([list74[idx74][6],list75[idx75][6]])
    leadeta.append([list74[idx74][7],list75[idx75][7]])
    subleadeta.append([list74[idx74][8],list75[idx75][8]])
    leadphi.append([list74[idx74][9],list75[idx75][9]])
    subleadphi.append([list74[idx74][10],list75[idx75][10]])

    tmppt = ([list74[idx74][2],list75[idx75][2]])
    diffpt = float(tmppt[0]) - float(tmppt[1])

    tmpptlead = ([list74[idx74][5],list75[idx75][5]])
    diffleadpt = float(tmpptlead[0]) - float(tmpptlead[1])

    tmpptsublead = ([list74[idx74][6],list75[idx75][6]])
    diffptsublead = float(tmpptsublead[0]) - float(tmpptsublead[1])

    tmpmass = ([list74[idx74][1],list75[idx75][1]])
    diffmass = float(tmpmass[0]) - float(tmpmass[1])
    

    
    if abs(diffleadpt) > 0.6 :
        print ( listsame[isameE][0].rjust(20) +"   "+ str(diffpt).rjust(9) +"    "+ str(diffleadpt).rjust(10) +"    "+str(diffptsublead).rjust(10)+ "    "+str(diffmass).rjust(10) )

SaveHisto(mass,['mass_diff',1000,-10,10,'M_{ee}'])
SaveHisto(pt,['pt_diff',1000,-10,10,'p_{T}^{ee}'])
SaveHisto(rapidity,['rapidity_diff',1000,-10,10,'Rapidity_{ee}'])
SaveHisto(phi,['phi_diff',1000,-10,10,'#phi_{ee}'])
SaveHisto(leadpt,['leadpt_diff',1000,-10,10,'p_{T}^{e}(leading)'])
SaveHisto(subleadpt,['subleadpt_diff',1000,-10,10,'p_{T}^{e}(sub-leading)'])
SaveHisto(leadeta,['leadeta_diff',1000,-10,10,'#eta_{e}(leading)'])
SaveHisto(subleadeta,['subleadeta_diff',1000,-10,10,'#eta_{e}(sub-leading)'])
SaveHisto(leadphi,['leadphi_diff',1000,-10,10,'#phi_{e}(leading)'])
SaveHisto(subleadphi,['subleadphi_diff',1000,-10,10,'#phi_{e}(sub-leading)'])

SaveHisto2D(mass,['mass2D', 60, 60,120, 'M_{ee}(74x)', 'M_{ee}(75x)'])
SaveHisto2D(pt,['pt2D',30,0,300,'p_{T}^{ee}(74x)','p_{T}^{ee}(75x)'])
SaveHisto2D(rapidity,['rapidity2D',48,-2.4,2.4,'Rapidity_{ee}(74x)', 'Rapidity_{ee}(75x)'])
SaveHisto2D(phi,['phi2D',70,-3.5,3.5,'#phi_{ee}(74x)', '#phi_{ee}(75x)'])
SaveHisto2D(leadpt,['leadpt2D',60,0,300,'p_{T}^{e}(leading)(74x)', 'p_{T}^{e}(leading)(75x)'])
SaveHisto2D(subleadpt,['subleadpt2D',60,0,300,'p_{T}^{e}(sub-leading)(74x)', 'p_{T}^{e}(sub-leading)(75x)'])
SaveHisto2D(leadeta,['leadeta2D',48,-2.4,2.4,'#eta_{e}(leading)(74x)', '#eta_{e}(leading)(75x)'])
SaveHisto2D(subleadeta,['subleadeta2D',48,-2.4,2.4,'#eta_{e}(sub-leading)(74x)','#eta_{e}(sub-leading)(75x)'])
SaveHisto2D(leadphi,['leadphi2D',70,-3.5,3.5,'#phi_{e}(leading)(74x)','#phi_{e}(leading)(75x)'])
SaveHisto2D(subleadphi,['subleadphi2D',70,-3.5,3.5,'#phi_{e}(sub-leading)(74x)','#phi_{e}(sub-leading)(75x)'])
