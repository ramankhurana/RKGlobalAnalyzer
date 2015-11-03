import ROOT
import os
import sys
ROOT.gROOT.SetBatch(True)

if len(sys.argv) < 2 :
    print "insufficient options provided "
    print "please provide directory in which all textfiles for optimization are kept"
    print "this script will create Datacard directory for each of these text files."

if len(sys.argv) == 2 :
    print ('Now taking text files from directory '+sys.argv[1])

dirname=sys.argv[1]
outdir='Datacards_'+dirname
os.system('mkdir '+outdir)

os.system('ls -1 '+dirname+' | grep .txt >& tmpfiles.txt')

filein = open('tmpfiles.txt','r')
for line in filein :
    filename =  line.rstrip()
    dirname = filename.split('.txt')[0]
    ##print (filename, dirname)
    os.system('python MakeDataCards.py '+filename+' '+dirname)
    os.system('mv '+dirname+' '+outdir)
os.system('rm tmpfiles.txt')
