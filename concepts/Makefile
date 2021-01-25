TIME=time -f "Program: %C\nTotal time: %E\nUser Mode (s) %U\nKernel Mode (s) %S\nCPU: %P"

run: datatypes
	./datatypes

time: datatypes
	$(TIME) ./datatypes

datatypes : datatypes.o
	#$(ECHO) building $@
	cc -o datatypes datatypes.o

datatypes.o :

.PHONY: clean
clean :
	-rm *.o

