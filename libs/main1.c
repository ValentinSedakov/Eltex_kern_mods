#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

//extern int mod_f(int divisible, int divisor);
//extern double div_f(int divisible, int divisor);

int main(int argc, char *argv[])

{
    void *ext_library;
    int divisible = strtol(argv[2], NULL, 10);
    int divisor = strtol(argv[3], NULL, 10);;
	int (*current_func1)(int divisible, int divisor);
    double (*current_func2)(int divisible, int divisor);
    //загрузка библиотеки
	ext_library = dlopen("/home/userval/C_eltex/kern_mods/libs/libdvdn.so",RTLD_LAZY);
	if (!ext_library){
		//если ошибка, то вывести ее на экран
		fprintf(stderr, "dlopen() error: %s\n", dlerror());
		return 1;
	};
    if(strcmp("mod_f", argv[1]) == 0)
    {
        current_func1 = dlsym(ext_library, argv[1]);
        printf("%s(%d, %d) = %d\n",argv[1],divisible, divisor,
        (*current_func1)(divisible, divisor));
    }
    else if(strcmp("div_f", argv[1]) == 0)
    {
        current_func2 = dlsym(ext_library, argv[1]);
        printf("%s(%d, %d) = %.2lf\n",argv[1],divisible, divisor,
        (*current_func2)(divisible, divisor));
    }
    else
    {
        printf("Function \"%s\" does not exist!\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    dlclose(ext_library);
    exit(EXIT_SUCCESS);
}