#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if(argc != 3) {
		printf("2 filenames required\n");
		return 0;
	}
	
	char buf;
	
	int f1 = open(argv[1], O_RDONLY, 0);
	if(f1 == -1) {
		printf("Cannot open file %s\n", argv[1]);
		close(f1);
		return 0;
	}
	
	int f2 = creat(argv[2], 0666);
	
	while(read(f1, &buf, 1)) {
		write(f2, &buf, 1);
	}
	printf("Done copying...\n");
	
	close(f1);
	close(f2);
	
	return 0;
}
