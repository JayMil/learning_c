.PHONY: exercise111
exercise111:
	gcc exercise111/wordcount.c
	@echo "== Test Text =="
	echo "Hello There Buddy" | ./a.out
	@echo "== Test File =="
	cat exercise111/testfile.txt | ./a.out
	@echo "== Test Blank File =="
	cat exercise111/blank.txt | ./a.out
	@echo "== Test Special File =="
	cat exercise111/specialChars.txt | ./a.out


.PHONY: exercise110
exercise110:
	gcc exercise110/replaceChars.c
	@echo "== Test File =="
	cat exercise110/testfile.txt | ./a.out
	@echo "== Test User Input =="
	./a.out

.PHONY: exercise109
exercise109:
	gcc exercise109/reduceBlanks.c
	@echo "== Test No Blank Lines =="
	echo "1234567890" | ./a.out
	@echo "== Test Single Blank Lines =="
	echo "1 3 5 7 9 " | ./a.out
	@echo "== Test Multiple Blank Lines =="
	echo "123    890" | ./a.out
	@echo "== Test Starting and Ending Blank Lines =="
	echo "   4567   " | ./a.out

.PHONY: exercise108
exercise108:
	gcc exercise108/countLines.c
	cat exercise108/exercise108.testfile.txt | ./a.out

.PHONY: exercise107
exercise107:
	gcc exercise107/copyChars.c
	cat exercise107/exercise107.testfile.txt | ./a.out

.PHONY: exercise106
exercise106:
	gcc exercise106/copyChars.c
	cat exercise106/exercise106.testfile.txt | ./a.out

.PHONY: exercise105
exercise105:
	gcc exercise105/tempConvert.c
	./a.out

.PHONY: exercise104
exercise104:
	gcc exercise104/tempConvert.c
	./a.out

.PHONY: exercise103
exercise103:
	gcc exercise103/tempConvert.c
	./a.out

.PHONY: exercise102
exercise102:
	gcc exercise102/hello.c
	./a.out

.PHONY: exercise101
exercise101:
	gcc -Wall exercise101/hello.c
	./a.out
