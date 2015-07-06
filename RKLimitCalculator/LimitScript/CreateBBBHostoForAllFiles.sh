filename=rootfilenames.txt
if [ -f $filename ] 
    then 
    rm $filename
    echo "removed old file : $filename "
else
    echo "no file to remove"
fi

whichdirtolist=$1
ls -1 ${whichdirtolist} | grep ".root" | gawk '{print "'$whichdirtolist'/"$1 }' >& $filename

for which in `less $filename`; do
    root -l -b -q CreateBinByBinUncertainityHistograms.C\(\"${which}\"\)
done
