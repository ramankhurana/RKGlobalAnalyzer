a=[]
file1='log_75.txt'
file2='log_74.txt'
for line in open(file1):
    #aa = line.split() 
    a.append(line)

b=[]
for line2 in open(file2):
    #bb = line.split()
    b.append(line2)


aminusb=set(a)-set(b)
bminusa=set(b)-set(a)
sameevent=set(a)&set(b)

ab=list(aminusb)
ba=list(bminusa)
same=list(sameevent)

print ("You have provided two files "+file1+" and "+file2)

#print ("Events present in "+file1+" but not in "+file2)
#for jevent in range(len(ab)):
#    print ab[jevent]


#print ("Events present in "+file2+" but not in "+file1)
#for ievent in range(len(ba)):
#    print ba[ievent]

print ("Events present in "+file2+" and  "+file1)
for iievent in range(len(same)):
    print same[iievent].rstrip()

    


print ('# of Events in '+file1+' = '+str(len(a)))
print ('# of Events in '+file2+' = '+str(len(b)))
print ("# of Events when Events present in "+file1+" but not in "+file2+" is =  "+str( len(ab)))
print ("# of Events when Events present in "+file2+" but not in "+file1+" is =  "+str( len(ba)))
print "Number of events which are present in both files =", len(same)
