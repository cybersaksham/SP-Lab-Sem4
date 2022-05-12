#include <unistd.h>
#include <stdlib.h>

int main() {
    char buf[] = "Here is some data \n";
    int size = sizeof(buf);
    char err[] = "A write error has occurred on file descriptor 1\n";
    int err_size = sizeof(err);
    if((write(1, buf, size)) != size) write(2, err, err_size);
    exit(0);
}
