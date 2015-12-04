a=[]
b=[]
c=[]
d=[]
e=[]
f=[]
g=[]
h=[]
i=[]
j=[]
k=[]
var75=[]
var74=[]
#var75 =[a,b,c,d,e,f,g,h,i,j,k]
file1='ListofSameEvents.txt'
iterator=0
iterator1=0

file2 = open('ListofEvents_75.txt','r')
for line2 in file2:
    print line2
    a,b,c,d,e,f,g,h,i,j,k = line2.split()
    var75.append([])
    var75[iterator] =[a,b,c,d,e,f,g,h,i,j,k]
    print var75[iterator][1]
    iterator=iterator+1
    
file3 = open('ListofEvents_74.txt','r')    
for line3 in file3:
    print line3
    a,b,c,d,e,f,g,h,i,j,k = line3.split()
    var74.append([])
    var74[iterator1] =[a,b,c,d,e,f,g,h,i,j,k]
    print var74[iterator1][1]
    iterator1=iterator1+1
            
   #  var74 = [a,b,c,d,e,f,g,h,i,j,k]
  #  print var74

    
