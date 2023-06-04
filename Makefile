hello.bin : hello.c
	mkdir bin
	gcc -c hello.c -o ./bin/hello.o
	gcc ./bin/hello.o -o ./bin/hello.bin


.PHONY : clean
clean:
	rm -rf ./bin

.PHONY : test
test:
	./bin/hello.bin

.PHONY : install
install :
	echo "嘿嘿，毛都没干"
