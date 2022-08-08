### Naming convention for library

`lib<Library_name>.a` ---> Static Library

`lib<Library_name>.so` ---> Dynamic Library

**Static Library :**

`gcc -c file_name.c -o file_name.o`
`
ar rs library_name.a file_name.o` 

**Dynamic library :**

`gcc -c -fPIC file_name.c -o file_name.o`

`gcc file_name.o -shared -o library_name.so`
