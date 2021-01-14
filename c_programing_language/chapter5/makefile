.PHONY: exercise505
exercise505: gentags
	gcc -Wall -g -o exercise505/test exercise505/*.c
	exercise505/test

.PHONY: debug
debug:
	gdb exercise505/test


.PHONY: exercise504
exercise504: gentags
	gcc -Wall -o exercise504/strend exercise504/strend.c
	exercise504/strend

.PHONY: exercise503
exercise503: gentags
	gcc -Wall -o exercise503/strcat exercise503/strcat.c
	exercise503/strcat

.PHONY: gentags
gentags:
	ctags -R .
