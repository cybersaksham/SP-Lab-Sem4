#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

const char *get_filename_ext(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

int main() {
	char buf;
	int ans = creat("merge.out", 0666);
	
	DIR *d1 = opendir("./");
	struct dirent *p = readdir(d1);
	
	while((p = readdir(d1)) != NULL) {
		if(strcmp(get_filename_ext(p->d_name), "txt") == 0) {
			printf("%s\n", p->d_name);
			
			int f1 = open(p->d_name, O_RDONLY, 0);
			if(f1 == -1) continue;
			while(read(f1, &buf, 1)) {
				write(ans, &buf, 1);
			}
			close(f1);
		}
	}
	closedir(d1);
	close(ans);
	
	return 0;
}
