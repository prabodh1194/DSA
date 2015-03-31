%.o: %.c 
	gcc -Wall -c $^
insert: insertion.o driver.o
	gcc -g -pg -Wall insertion.o driver.o -o insert
merge: merge.o driver.o
	gcc -g -pg -Wall merge.c driver.o -o merge
quickFirst: pivot.o quick.o driver.o
	gcc -g -pg -Wall pivot.o quick.o driver.o -o quickFirst
clean:
	rm *.o
	rm insert merge quickFirst
	rm profile*
	rm *.out
