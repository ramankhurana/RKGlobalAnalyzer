#inputpath=/hdfs/store/user/khurana/BulkGravTohhTohbbhbb_narrow_M-3500_13TeV-madgraph/crab_BulkGravTohhTohbbhbb_narrow_M-3500_13TeV-madgraph_0902/150902_135407/0000/
#outputpath=Signal/3500/
#inputpath=/hdfs/store/user/khurana/BulkGravTohhTohbbhbb_narrow_M-4000_13TeV-madgraph/crab_BulkGravTohhTohbbhbb_narrow_M-4000_13TeV-madgraph_0902/150902_135457/0000/
#outputpath=Signal/4000/
inputpath=/hdfs/store/user/khurana/BulkGravTohhTohbbhbb_narrow_M-4500_13TeV-madgraph/crab_BulkGravTohhTohbbhbb_narrow_M-4500_13TeV-madgraph_0902/150902_135552/0000/
outputpath=Signal/4500/
mkdir -p $outputpath
ls -1 $inputpath >& list.txt

## compile code only Once 
#root -l <<EOF
#EOF

## Run now the code for all the files 
for which in `cat list.txt`; do
    root -l <<EOF
.L treeMaker.C++
treeMaker a("$inputpath/$which","$outputpath/$which")
a.Loop()
.q
EOF

done
#treeMaker *a = new treeMaker(tree=0)
#a->Loop()