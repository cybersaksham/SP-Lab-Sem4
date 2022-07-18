#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int foo(int fd, char* buf, int b_size, int n, int skip) {
	if(fd == -1) return -1;
	
	int ans = 0;
	while(read(fd, &buf, b_size)) {
		read(fd, &buf, skip);
		ans += b_size;
	}
	
	return ans;
}

int main() {
	char buf;	
	int f1 = open("1.txt", O_RDONLY, 0);
	
	printf("%d\n", foo(f1, &buf, 8, 10, 4));
	
	return 0;
}
