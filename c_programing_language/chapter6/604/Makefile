CFLAGS=-Wall -g
RM=rm -f
OBJS=src/main.o src/binarytree.o src/input.o src/sortedarray.o
HEADERS=src/binarytree.h src/input.h src/sortedarray.h
EXECDIR=./bin
EXEC=$(EXECDIR)/main

all: run

.PHONY: run
run: $(EXEC)
	echo a a b a c h h c a d | $(EXEC)
	#cat src/*.c | $(EXEC)

$(EXEC) : $(OBJS) | $(EXECDIR)
	cc $(CFLAGS) $^ -o $@


$(OBJS) : $(HEADERS)


tags:
	ctags -R *


.PHONY: $(EXECDIR)
$(EXECDIR):
	mkdir -p $(EXECDIR)


.PHONY: clean
clean:
	$(RM) $(OBJS)
	$(RM) -dr $(EXECDIR)
	$(RM) tags
