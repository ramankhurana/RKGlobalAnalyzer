
def FileToList(fileName):
    row = [[]] 
    crimefile = open(fileName, 'r') 
    for line in crimefile.readlines(): 
        tmp = []
        for element in line[0:-1].split(' '):
            tmp.append(element)
        row.append(tmp)
    return row

list74=FileToList('ListofEvents_74.txt')
list75=FileToList('ListofEvents_75.txt')
listsame=FileToList('ListofSameEvents.txt')



def FindIndex(list_, eventnum):
    index_=-1
    for i74 in range(len(list_)):
        if i74 ==0 : continue 
        if list_[i74][0] == eventnum :
            index_ = i74
    return index_


for isameE in range(len(listsame)):
    if isameE ==0 : continue
    idx74 = FindIndex(list74,listsame[isameE][0])
    idx75 = FindIndex(list75,listsame[isameE][0])
    mass = [list74[idx74][1],list75[idx75][1]]
    print float(mass[0])-float(mass[1])
    
#if len(list74[0]) > 0 :
a='''
for iline in range(len(list74)):
    print list74[iline]
    if len(list74[iline]) > 0 :
        print list74[iline][1]

'''
########for iline in range(len(row)):
########    
########    if len(row[iline]) > 0 :
########        temp=row[iline][1]
########        print temp
#print temp[1]

#
#for iitem in range(len(temp)):
#    if(iitem==1):
#        print temp[iitem]
