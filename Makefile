fib: fib.o
	gcc -o fib fib.c -pthread -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast

