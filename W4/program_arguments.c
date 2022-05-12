#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char **env[]) {
    int arg;
    for(arg=1; arg<argc; arg++) {
        if(argv[arg][0] == '-') printf("options: %s\n", argv[arg] + 1);
        else printf("argument %d: %s\n", arg, argv[arg]);
    }
    exit(0);
}
