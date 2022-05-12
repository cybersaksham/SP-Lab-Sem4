#include <unistd.h>
#include <stdlib.h>

int main() {
    int n = 128;
    char buffer[n];

    int nread;
    nread = read(0, buffer, n);
    if(nread == -1) write(2, "An error has occurred on reading \n", 26);

    if((write(1, buffer, nread)) != nread) write(2, "An error has occurrred on writing\n", 27);

    exit(0);
}
