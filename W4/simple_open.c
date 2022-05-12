#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    char c;
    int in;
    in = open("ip.txt", O_RDONLY);
    while(read(in, &c,1) == 1) write(1, &c, 1);
    exit(0);
}
