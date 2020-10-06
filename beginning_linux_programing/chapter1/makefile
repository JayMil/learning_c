.PHONY: run
run:
	gcc -c bill.c fred.c
	gcc -c program.c
	gcc -o program program.o bill.o
	./program

.PHONY: archive
archive:
	gcc -c bill.c fred.c
	ar crv libfoo.a bill.o fred.o
	ranlib libfoo.a
	gcc -o program program.o libfoo.a
	./program
