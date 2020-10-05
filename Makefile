program1: program1.o
	gcc -o unsync program1.c -pthread -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast	
	gcc -DPTHREAD_SYNC -o sync program1.c -pthread			

clean:
	rm *.o *.err
