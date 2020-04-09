# build c files without linking
# 	Note: this makefile intentionally doesn't use makefile best practices
# 	and exists just to show the different compilation methods


# compile with single command then run
.PHONY: run-single-compile
run-single-compile:
	gcc main.c hello.c -o hello
	./hello

# compile object files without linking, then link the object and build executable, then run
.PHONY: run-compile-without-linking
run-two-step-compile:
	gcc -c main.c		# this makes main.o
	gcc -c hello.c		# this makes hello.o
	gcc *.o -o hello	# this links the objs and makes executable ./hello
	./hello


.PHONY: clean
clean:
	rm *.o		# remove object files
	rm hello	# remvoe hello executable
	ls -la		# show current directory state
