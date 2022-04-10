TARGET:exe

exe: application.o ldll.a
	gcc application.o -o exe -L . -ldll
application.o:application.c
	gcc -c application.c -o application.o
ldll.a:dll.o dll_utils.o
	ar rs libdll.a dll.o dll_utils.o
dll.o:dll.c
	gcc -c dll.c -o dll.o
dll_utils.o:dll_utils.c
	gcc -c dll_utils.c -o dll_utils.o
clean:
	rm application.o
	rm dll.o
	rm dll_utils.o
	rm libdll.a
	rm exe
