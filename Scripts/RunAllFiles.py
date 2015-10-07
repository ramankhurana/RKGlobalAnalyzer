import os

inputfilepath='/hdfs/store/user/khurana/Raman/MonoHFatJetAnalysis_AllMCWithPU_V3/SignalFiles_0804-runallAnalysis/'
outputfilepath='trial'

## create output dir 
## add protection here
os.system('mkdir '+outputfilepath)

## list file name in text file
## add protection here
os.system('ls -1 '+inputfilepath+' >& files.txt')
os.system('root -l -b -q RootMacro.C++')

filelist = open('files.txt','r')
for ifile in filelist:
    filename =  ifile.rstrip()
    inputfilename = inputfilepath+'/'+filename
    outputfilename = outputfilepath+'/'+filename
    print (filename, inputfilename, outputfilename)
    os.system('root -l -b -q RootMacro.C\(\\"'+inputfilename+'\\",\\"'+outputfilename+'\\"\)')
