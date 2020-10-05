<<<<<<< HEAD
fib: fib.o
	gcc -o fib fib.c -pthread -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast

=======
program1: program1.o
	gcc -o unsync program1.c -pthread -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast	
	gcc -DPTHREAD_SYNC -o sync program1.c -pthread			

clean:
	rm *.o *.err
>>>>>>> 62e5a9832dcfa3ed4921fb9d580bbeb048e700f1
