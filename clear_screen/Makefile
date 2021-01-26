time=/usr/bin/time --format="took %E - %S  - %U - %K"
.PHONY: run1
run1: build
	$(time) -o ./time1 ./clearscreen1
	$(time) -o ./time2 ./clearscreen2
	./clearscreen3
	cat ./time1 ./time2

.PHONY: run2
run2: build
	./clearscreen3

.PHONY: build
build:
	gcc -Wall -g -o clearscreen1 clearscreen1.c
	gcc -Wall -g -o clearscreen2 clearscreen2.c
	gcc -Wall -g -o clearscreen3 clearscreen3.c
