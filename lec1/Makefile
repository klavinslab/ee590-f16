all: hello balance fsm
	
hello: hello.c
		gcc -o hello hello.c

balance: balance.c
		gcc -o balance balance.c

fsm: main.c fsm.c fsm.h
		gcc -c main.c fsm.c
		gcc -o fsm main.o fsm.o

clean:
		rm -f hello balance fsm *.o
