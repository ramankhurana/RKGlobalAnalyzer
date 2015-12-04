from ROOT import TH1F
from ROOT import TFile
from ROOT import TCanvas
from ROOT import TPad
import numpy as n

print "Writing a tree"

file1 =TFile("tree.root", "recreate")
file1.cd()
c11=TCanvas("c1","c1",0,500,0,500)
g=TH1F("h1","h1",5, 0,5)
g.Fill(1)
g.Fill(3)
g.Fill(2)
g.Fill(5)
c11.cd()
g.Draw()
file1.Write()
file1.Close()
histname='Plots/'+'pngname'
c11.SaveAs(histname+'.png')
##c11.SaveAs('test.png')


