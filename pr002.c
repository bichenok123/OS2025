#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
        int user_id, group_id;
	user_id = getuid() ;
	group_id = getuid() ;
	printf("Идентификатор пользователя: %d\n", user_id);
	printf("Индетефикатор пользователя: %d\n", group_id);
	return 0;

}
