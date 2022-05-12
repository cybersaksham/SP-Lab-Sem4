#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#define SSIZE 1000

struct Character {
    char ch;
    int freq;
};

int checkCharInd(struct Character chars[], char c, int charsize) {
    int i;
    for(i=0; i<charsize; i++) {
	if(chars[i].ch == c) return i;
    }
    return -1;
}

int cmpChar(const void *a, const void *b) {
    struct Character *s1;
    struct Character *s2;
    s1 = (struct Character *)a;
    s2 = (struct Character *)b;

    if(s1->freq == s2->freq) return s1->ch >= s2->ch;
    else return s1->freq <= s2->freq;
}

int main(int argc, char *argv[]) {
    int in, out1, out2, charsize, wordsize, ind, i;
    char c;
    char *pch; 
    struct Character chars[SSIZE];
    charsize = 0;
    wordsize = 0;

    if(argc != 2) {
        char err[] = "Input filename required\n";
	write(1, err, sizeof(err));
	exit(1);
    }

    in = open(argv[1], O_RDONLY);
    out1 = open("file1.txt", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    out2 = open("file2.txt", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);

    // Character Count
    while(read(in, &c, 1) == 1) {
	ind = checkCharInd(chars, c, charsize);
	if(ind == -1) {
            chars[charsize].ch = c;
	    chars[charsize].freq = 1;
	    charsize++;
	}
	else chars[ind].freq = chars[ind].freq + 1;
	ind = -1;
    }
    qsort(chars, charsize, sizeof(struct Character), cmpChar);
    for(i=0; i<charsize; i++) {
	c = chars[i].ch;
	write(out1, &c, 1);
	c = '-';
        write(out1, &c, 1);
	c = (char)(chars[i].freq + 48);
        write(out1, &c, 1);
	c = '\n';
        write(out1, &c, 1);
    }

    // Word Count
   
    exit(0);
}
