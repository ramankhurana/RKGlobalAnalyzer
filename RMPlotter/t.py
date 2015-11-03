import sys
sys.argv.append( '-b-' )


from ROOT import TFile, TH1F, gDirectory, TCanvas
from ROOT import gStyle
from ROOT import gROOT
from ROOT import TStyle
from ROOT import TLegend
from ROOT import TPaveText
from  Helpers import *
import os

def OpenFile(filename,histVec):
    fin = TFile( filename,'READ' )
    fin.cd('NMinusOne')
    histogram = gDirectory.Get(histVec)
    print ("type in open file",type(histogram))
    histogram.SetDirectory(0)
    fin.Close()
    return histogram


##
##print "calling the plotter"
##files=['../OutputRootFile/analysis.root','../OutputRootFile/analysis2.root',0]
##point=['1000','2000']
##ytitle='#e_{Signal}'
##legend=['M_{Z`} = 1000 GeV']
##
##fout = TFile('Out.root','RECREATE')
##fout.cd()
##
##
#### Add Histogram to Root File
###for ip in range(len(files)):
##h_name='FatJetCSV_'+point[0]
##FatJetCSV = DrawOverlap(files[0], 'NMinusOne/h_FatJetCSVbcsv',['CSIVv2',ytitle], legend,h_name,1)
###fout.cd()
###FatJetCSV.Write()
##
##h_name1='FatJetCSV1_'+point[1]
##FatJetCSV1 = DrawOverlap(files[1], 'NMinusOne/h_FatJetCSVbcsv',['CSIVv2',ytitle], legend,h_name1,[-99999,99999,1])
##fout.cd()
##FatJetCSV1.Write()
##
##                           
##
##
##
##
