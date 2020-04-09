# Compile and run
# 	Note: this makefile intentionally doesn't use makefile best practices
# 	and exists just to show the different compilation methods


# compile and run
.PHONY: run-global
run-global:
	gcc -Wall global-main.c apples.c -o global-variables
	./global-variables

.PHONY: run-local
run-local:
	gcc local-main.c -o local-variables
	./local-variables

.PHONY: clean
clean:
	rm *.o				# remove object files
	rm local-variables	# remvoe hello executable
	rm global-variables	# remvoe hello executable
	ls -la				# show current directory state
