
static:
	gcc -c mod.c div.c
	ar rc libmddv.a mod.o div.o
	ranlib libmddv.a
	gcc main.c -L. -lmddv -o res
dyn:
	gcc -fPIC -c mod.c
	gcc -fPIC -c div.c
	gcc -shared -o libdvdn.so mod.o div.o
	gcc -c main.c 
	gcc main.o -L. -ldvdn -o res
	gcc main1.c -o main -ldl
clean:
	rm   -f   *.o  *.a  *.so res main