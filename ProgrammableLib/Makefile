target: application

application: application.o lapp.a
	gcc application.o -o application -L . -lapp
application.o: application.c
	gcc -c application.c -o application.o
lapp.a: dll.o
	ar rs libapp.a dll.o
dll.o: dll.c
	gcc -c dll.c -o dll.o

clean:
	rm dll.o
	rm libapp.a
	rm application.o
	rm application
