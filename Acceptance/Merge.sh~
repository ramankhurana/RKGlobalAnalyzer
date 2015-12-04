storepath=/afs/hep.wisc.edu/cms/khurana/Monika/CMSSW_7_4_5/src/RKGlobalAnalyzer/Acceptance/
dirname=$1
mkdir $dirname
filename=dirname.txt
rm $filename
fullpath=$storepath/$dirname
ls -1 $fullpath >& $filename
for which in `less $filename`
do 
    files=`find  $fullpath/$which  -name "*.root" | gawk '{ORS=" "}{print $1}'`
    hadd Merged_${which}.root $files
    mv Merged_${which}.root $dirname
done 
