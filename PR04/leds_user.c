#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <math.h>

static int fd;

void wave();
void binary();
void disco();

int main() {
	
	fd = open("/dev/chardev_leds", O_RDWR);

	bool valid = false;
	int option = 0;
	printf("Choose an option:\n");
	printf("1 : Wave\n");
	printf("2 : Binary\n");
	printf("3 : Disco\n");
	while (!valid) {
		scanf("%d", &option);
		if (option >= 1 && option <= 3) valid = true;
		else printf("Wrong option! Try again:\n");
	}
	
	switch (option) {
		case 1:
			wave();
			break;
		case 2:
			binary();
			break;
		case 3:
			disco();
			break;
	}
	
	printf("Program finished!\n");
	write(fd, "", 0);
	close(fd);
	return 0;
	
}

void wave() {
	int i, n = 3;
	for (i = 0; i < n; i++) {
		write(fd, "1", 1);
		usleep(500000);
		write(fd, "2", 1);
		usleep(500000);
		write(fd, "3", 1);
		usleep(500000);
	}
}

void binary() {
	write(fd, "3", 1);
	usleep(500000);
	write(fd, "2", 1);
	usleep(500000);
	write(fd, "23", 2);
	usleep(500000);
	write(fd, "1", 1);
	usleep(500000);
	write(fd, "13", 2);
	usleep(500000);
	write(fd, "12", 2);
	usleep(500000);
	write(fd, "123", 3);
	usleep(500000);
}

void disco() {
	time_t t;
	srand((unsigned) time(&t));
	char* buff;
	char aux[1];
	int i, num;
	for (i = 0; i < 50; i++) {
		num = (random() % 3) + 1;
		sprintf(aux, "%d", num);
		buff = aux;
		write(fd, buff, 1);
		usleep(100000);
	}
}
