#! /usr/bin/env python
import sys
import os
samplename='SingleMuon'
eospath='/store/user/khurana/'
eos='/afs/cern.ch/project/eos/installation/0.3.84-aquamarine/bin/eos.select ls '
fullsamplename=eospath+'/'+samplename



def listdirs(path):
    shellcommand=eos+path
    os.system(shellcommand+' >& dirlist.txt')
    dirlist=open('dirlist.txt','r')
    dirs=[]
    for line in dirlist:
        dirs.append(line.rstrip())
        
    dirlist.close()
    os.system('rm dirlist.txt')
    return dirs


def isFileOrDir(name):
    if 'NCUGlobal' in name : 
        return 'file'
    else :
        return 'dir'
    

inputFileList=open('inputfileslist.txt','w')


def ListFiles(fullsamplename_):
    print ('-------------------',fullsamplename_)
    dirs=[]
    if isinstance(fullsamplename_,str) :
        dirs=listdirs(fullsamplename_)
    
    if isinstance(fullsamplename_,list) :
        dirs=fullsamplename_
    newdirs=[]
    for dirname in dirs:
        name=fullsamplename_+'/'+dirname
        print ('name ',name)
        status=isFileOrDir(name)
        print status
        if status=='file' :
            #if name.count('NCUGlobal')==1:
            inputFileList.write(name+'\n')
            print 'written in file'
        elif status=='dir' :
            print ("status in dir",status)
            newdirlist=listdirs(name)
            print ('newdirlist',newdirlist)
            for newdir_ in newdirlist:
                #print ('new dir', name+'/'+newdir_)
                print ('new dir', newdir_)
                #newdirs.append(name+'/'+newdir_)
                if isFileOrDir(newdir_) == 'file' :
                    inputFileList.write(name+'/'+newdir_+'\n')
                elif isFileOrDir(newdir_)== 'dir' :
                    ListFiles(name+'/'+newdir_)
                
            print '**********************'
        else :
            return 0
    return 0
newlistPath=ListFiles(fullsamplename)
print newlistPath
