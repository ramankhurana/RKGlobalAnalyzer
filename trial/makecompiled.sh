g++ `root-config --cflags` t2.C -c 
g++ `root-config --cflags` frclass.C -c 
g++ `root-config --cflags` Main.C t2.o frclass.o  -o main.exe `root-config --libs`
