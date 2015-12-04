

import os
##
## USAGE : 
##
## Run this python file using 
## python RunAllFiles.py
## This will create a file run.C which can be used later to run on all the files. 
## Now enter root prompt using 
## root -l 
## in root prompt compile you code 
## i have an example code with name RootMacro.C
## .L RootMacro.C++("","")
## this macro taken two inputs, inputfile name and output file name. 
## Once it is compiles and loaded you can run the run.C which has information of input and output files. 
## Run it using :
## .x run.C
## Wait till it is over. 
##
## You can edit is accroding to your needs and include the last two steps to be performed in the ROOT prompt in the script itself. 
##


## Following are the three input variables which you need to pass on.
## For now edit in the py file, if it works and useful then i will make is configurable. 
#inputfilepath='/hdfs/store/user/khurana/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_NewMiniIso_Extended/151124_182452/'
#outputfilepath='DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_NewMiniIso_Extended/'

inputfilepath='/hdfs/store/user/khurana/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20151026/151025_235212/'
outputfilepath='DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_MC25ns_ReMiniAOD_20151026/'
macroname='RootMacro'  ## don't give .C in the name




## create output dir 
## add protection here
os.system('mkdir '+outputfilepath)

## list file name in text file
## add protection here
#os.system('ls -1 '+inputfilepath+' >& files.txt')
os.system('find '+inputfilepath+' -name \'*.root\' >& files.txt')
filelist = open('files.txt','r')
OutputMacro = open('run.C','w')
OutputMacro.write('void run(){ \n')
OutputMacro.write(' \n')
OutputMacro.write('TTree *t =0; \n')
OutputMacro.write('EffandAcc *tmva; \n')
i = 0
for ifile in filelist:
    filename =  ifile.rstrip()
    inputfilename =  filename  #inputfilepath+'/'+filename
    print inputfilename
    tmpname = inputfilename.split('NCUGlobalTuples')
    print tmpname
    #filename = filename.replace(inputfilepath,outputfilepath)
    #outputfilename = filename ##x outputfilepath+'/'+filename
    outputfilename = outputfilepath+'AnalysisOutput'+tmpname[1] ##x outputfilepath+'/'+filename
    OutputMacro.write('tmva = new EffandAcc'+'(t, \"'+inputfilename+'\",\"'+outputfilename+'\"); \n')
    OutputMacro.write('tmva->Loop(); \n')
    i=i+1

OutputMacro.write('} \n')

#outshell = open('run.sh','w')
#outshell.write(' \n')
#outshell.write(' \n')
#outshell.write(' \n')
#os.system ('root -l RootMacro.C++\(\\"'+inputfilename+'\\",\\"'+outputfilename+'\\"\)')
#
#os.system('.x run.C')
