obj-m += nl_serv.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	gcc -o clnt nl_clnt.c
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm clnt