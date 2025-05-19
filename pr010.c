//обмен данными через FIFO (именнованный pipe)
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BYTES 69
int main() {
	        int fd, result;
		size_t size;
		char resstring[BYTES];
		char name[] = "fifo.file";
		if(mknod(name, S_IFIFO | 0664, 0) < 0) {
	        printf("Не удалось создать FIFO\n");	
		exit(-1);
		}
if((result = fork())<0) {
	                printf("Не удалось создать дочернй процесс\n");
			exit(-1);
 }
else if (result > 0) {
	printf("родительский процесс начал работу\n");
	if((fd = open(name, O_WRONLY)) < 0) {
	 printf("не удалось открыть FIFO на запись\n");
	 exit(-1);					
	}
size = write(fd, "Строка для чтения процессом-ребёнком",BYTES);
                if (size != BYTES) {
 printf("не удалось записать всю строку в FIFO\n");
   exit(-1);
 }
	 printf("Строка записана в FIFO процессом-родителем\n");
	 if (close(fd)<0){
	printf("Не удалось закрыть FIFO для процесса-родителя\n"); 
	exit(-1);
 }
	printf("Родитель завершил работу\n");
	 }
else {
  printf("Процесс-ребёнок начал работу\n");
  if((fd = open(name, O_RDONLY)) < 0); {
 printf("Не удалось открыть FIFO на чтение\n");
 exit(-1);
  }
  size = read(fd, resstring, BYTES);
if(size < 0) {	
printf("Не удалось прочитать строку из FIFO\n");
 exit(-1);
 }
 printf("Прочитанна строка: %s\n", resstring);
 if(close(fd)<0) 
 printf("Не удалось закрыть FIFO для процес-ребёнка\n");
exit(-1);
	printf("Процесс-ребёнок завершил работу\n");
}
	return 0;
}
