TZ=UTC
INCLUDE = ./Include

OBJS=readfile
TARGET=mian.o fileOperate.o


./Bin/readfile : ./Release/main.o ./Release/fileOperate.o
	gcc -o ./Release/readfile main.o fileOperate.o

./Release/main.o : main.c
	gcc -c main.c



.PHONY : clean
clean:
	rm -rf ./Bin/*
	rm -rf ./Include/*.gch

.PHONY : test
test:
	./bin/hello.bin

.PHONY : install
install :
	echo "嘿嘿，毛都没干"
