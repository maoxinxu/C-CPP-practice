TZ=UTC
INCLUDE = ./Include

OBJS=readfile
TARGET=mian.o fileOperate.o

readfile : main.o fileOperate.o
	gcc main.o fileOperate.o -o readfile

main.o : main.c
	gcc -c main.c

fileOperate.o :fileOperate.c
	gcc -c fileOperate.c

.PHONY : clean test install
clean:
	rm -rf ./*.o
	rm -rf ./readfile

test:
	./readfile

install :
	echo "嘿嘿，毛都没干"
