storepath=/afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/FatJetOptimination/
dirname=$1
outputfirname=Merged_$dirname
mkdir $outputfirname
filename=dirname.txt
rm $filename
fullpath=$storepath/$dirname
echo $fullpath
ls -1 $fullpath >& $filename
for which in `less $filename`
do 
    files=`find  $fullpath/$which  -name "*.root" | gawk '{ORS=" "}{print $1}'`
    hadd Merged_${which}.root $files
    mv Merged_${which}.root $outputfirname
done 
