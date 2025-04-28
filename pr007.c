//Изменение пользовательского контекста процесса
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
        printf("Внути программы pr007.out\n");
	printf("Переключение пользовательского контекста на программу cat\n\n");

	(void) execle("/bin/cat", "/bin/cat", "pr007.c", 0, envp);
	printf("Ошибка при выполнение системного вызова exec\n"),
	exit(-1);
	return 0;	
}
