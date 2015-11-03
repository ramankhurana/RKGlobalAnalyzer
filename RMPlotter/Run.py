import sys
sys.argv.append( '-b-' )


from ROOT import TFile, TH1F, gDirectory, TCanvas
from ROOT import gStyle
from ROOT import gROOT
from ROOT import TStyle
from ROOT import TLegend
from ROOT import TPaveText
from  Raman import *
import os


print "calling the plotter"
files=['../OutputRootFile/analysis.root','../OutputRootFile/analysis2.root',0]
point=['1000','2000']
ytitle='#e_{Signal}'
legend=['M_{Z`} = 1000 GeV']

fout = TFile('Out.root','RECREATE')
fout.cd()


## Add Histogram to Root File
#for ip in range(len(files)):
h_name='FatJetCSV_'+point[0]
#print "type in main code ",type(OpenFile(files[0],'NMinusOne/h_FatJetCSVbcsv'))
#FatJetCSV = DrawOverlap(OpenFile(files[0],'NMinusOne/h_FatJetCSVbcsv'),['CSIVv2',ytitle], legend,h_name,1)
FatJetCSV = DrawOverlap(files[0],'h_FatJetCSVbcsv',['CSIVv2',ytitle], legend,h_name,[-99999,99999,1],0)
#fout.cd()
#FatJetCSV.Write()

h_name1='FatJetCSV1_'+point[1]

FatJetCSV1 = DrawOverlap(files[1], 'h_FatJetCSVbcsv',['CSIVv2',ytitle], legend,h_name1,[-99999,99999,1])
fout.cd()
FatJetCSV1.Write()

                           





#DrawOverlap(files, ['MonoHJetISRVetoStudy/h_nAddJetspt10','MonoHJetISRVetoStudy/h_nAddJetspt15','MonoHJetISRVetoStudy/h_nAddJetspt20','MonoHJetISRVetoStudy/h_nAddJetspt25','MonoHJetISRVetoStudy/h_nAddJetspt30'],['nJets',ytitle], legend,'nJets')

##xrange_ = [0,5,2]
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt10','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt15','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt20','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt25','MonoHJetISRVetoStudy/h_DeltaRLeadingB0pt30'],['#DeltaR(b1-j1)',ytitle], legend,'deltaRLeadingB0',xrange_)
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRSubLeadingB0pt10','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB0pt15','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB0pt20','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB0pt25','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB0pt30'],['#DeltaR(b2-j1)',ytitle], legend,'deltaRSubLeadingB0',xrange_)
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRLeadingB1pt10','MonoHJetISRVetoStudy/h_DeltaRLeadingB1pt15','MonoHJetISRVetoStudy/h_DeltaRLeadingB1pt20','MonoHJetISRVetoStudy/h_DeltaRLeadingB1pt25','MonoHJetISRVetoStudy/h_DeltaRLeadingB1pt30'],['#DeltaR(b1-j2)',ytitle], legend,'deltaRLeadingB1',xrange_)
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRSubLeadingB1pt10','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB1pt15','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB1pt20','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB1pt25','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB1pt30'],['#DeltaR(b2-j2)',ytitle], legend,'deltaRSubLeadingB1',xrange_)
##
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRLeadingB2pt10','MonoHJetISRVetoStudy/h_DeltaRLeadingB2pt15','MonoHJetISRVetoStudy/h_DeltaRLeadingB2pt20','MonoHJetISRVetoStudy/h_DeltaRLeadingB2pt25','MonoHJetISRVetoStudy/h_DeltaRLeadingB2pt30'],['#DeltaR(b1-j3)',ytitle], legend,'deltaRLeadingB2',xrange_)
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRSubLeadingB2pt10','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB2pt15','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB2pt20','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB2pt25','MonoHJetISRVetoStudy/h_DeltaRSubLeadingB2pt30'],['#DeltaR(b2-j3)',ytitle], legend,'deltaRSubLeadingB2',xrange_)
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_DeltaRClosestB0pt10','MonoHJetISRVetoStudy/h_DeltaRClosestB0pt15','MonoHJetISRVetoStudy/h_DeltaRClosestB0pt20','MonoHJetISRVetoStudy/h_DeltaRClosestB0pt25','MonoHJetISRVetoStudy/h_DeltaRClosestB0pt30'],['#DeltaR(b_{closest}-j1)',ytitle], legend,'deltaRLeadingClosestB',xrange_)
##
##DrawOverlap(files, ['MonoHJetISRVetoStudy/h_pTAddJet0','MonoHJetISRVetoStudy/h_pTAddJet1','MonoHJetISRVetoStudy/h_pTAddJet2'],['p_{T}^{add. Jet}',ytitle], ['leading','sub-lead','3^{rd}-lead'],'pTAdditionalJet',[0,150.,2])
