#!/bin/sh

for i in {1..180}
do
    number=`condor_q khurana | grep running | gawk '{print $9}'`
    number1=`condor_q khurana | grep running | gawk '{print $1}'`
    number7=`condor_q khurana | grep running | gawk '{print $7}'`
    sleep 60
    echo $number
    if [[ $number -eq 0 && number1 -eq 0 && number7 -eq 0 ]]
    then 
	echo -e "\a \a \a \a \a \a \a \a \a \a \a \a \a \a \a \a \a \a "
	exit 0
    fi
done
