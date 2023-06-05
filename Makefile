hello.bin : hello.c
	# mkdir bin
	gcc -c main.c -o ./Release/main.o
	gcc ./Include/fileOperate.h  ./Source/fileOperate.c -o ./Release/fileOperate.o
	gcc ./Release/main.o ./Release/fileOperate.o -o ./Bin/run.bin



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
