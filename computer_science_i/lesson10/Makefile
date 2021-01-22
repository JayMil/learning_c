runl: loggy
	./loggy
	echo == Log File Contents ==
	cat data/data.log

runw: writefile
	./writefile
	echo File Contents
	cat data/data.txt

runr: readfile
	./readfile

writefile: writefile.o
	cc -Wall -o writefile writefile.o

readfile: readfile.o
	cc -Wall -o readfile readfile.o

loggy: loggy.o
	cc -Wall -o loggy loggy.o

readfile.o:
writefile.o:
loggy.o:
