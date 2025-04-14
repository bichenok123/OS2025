//Программа, илюстрирующая создание процесса ребенка при помощи системного вызова fork()
// с разными действиями процесса ребенка и процесса родителя
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
        pid_t prid, parprid;
	int a = 0, c;
	prid = getpid();
	parprid = getppid() ;
	printf ("До выполнения fork() :\n");
	printf("Ид. текущего процесса: %d\n", prid);
	printf("Ид. родительского процесса: %d\n", parprid);
	printf("Начальное значение переменной а: %d", a);
        c = fork(); 
        if(c<0)  {
	        printf("Ошибка привызове fork()");
		exit(-1) ;	 
	}
	else if (c==0) {
	        printf("Выполнентие дочернего процесса");
	        a = a+1 ;
	        prid = getpid();
	        parprid = getppid() ;
	        printf ("Поесла выполнения fork() :\n");
	        printf("Ид. текущего процесса: %d\n", prid);
	        printf("Ид. родительского процесса: %d\n", parprid);
	        printf("Зачальное значение переменной а: %d\n", a);
	}
	else {
	     printf("Выполнение родительского процесса, порожден процесс c ид. %d\n", c);
	     a = a+1000;
	     prid = getpid();
	     parprid = getppid();
	     printf("После выполнение fork() для родительсого процесса:\n");
             printf("Ид. текущего процесса : %d\nИд родительского процесса: %d\n" , prid, parprid);
	     printf("Значение переменной a: %d\n", a);
	}
	return 0;
}
