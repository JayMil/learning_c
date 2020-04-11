
# c files that have dependencies can be compiled to output files using the -c flag

# given files main.c and hello.c
gcc main.c 
gcc hello.c

# both of these lines will fail as main.c cannot find the hello function
# and hello.c will fail becuase it doesn't have a main function

# this is becuase the files are being compiled and linked to make an executable
# these files can be compiled individuallly if not linked with the -c flag
gcc -c main.c
gcc -c hello.c

# this will produce two output files
main.o
hello.o

# these output files can then be linked and compiled into an executable
gcc main.o hello.o 
gcc *.o

# both of these lines will compile the output files into an executable (a.out)

