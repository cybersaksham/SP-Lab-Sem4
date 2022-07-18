#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int startsWith(const char *pre, const char *str) {
    size_t lenpre = strlen(pre), lenstr = strlen(str);
    return lenstr < lenpre ? 0 : memcmp(pre, str, lenpre) == 0;
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Provide prefix string\n");
		return 0;
	}
	
	DIR *d1 = opendir("./");
	struct dirent *p = readdir(d1);
	
	while((p = readdir(d1)) != NULL) {
		if(startsWith(argv[1], p->d_name)) {
			printf("%s\n", p->d_name);
		}
	}
	closedir(d1);
	
	return 0;
}
