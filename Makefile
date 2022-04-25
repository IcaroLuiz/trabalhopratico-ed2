all: printy
 
printy: main.o acesso.o
    gcc -o printy main.o acesso.o
 
main.o: main.c acesso.h
    gcc -o main.o main.c -c -W -Wall
 
acesso.o: acesso.c acesso.h
    gcc -o acesso.o acesso.c -c -W -Wall 
 
clean:
    rm -rf *.o *~ printy