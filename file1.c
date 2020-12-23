#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main(){
    mkfifo("outpu", 0644);

    int fd;

    while(1){
        char line[100];
        fd = open("inpu", O_RDONLY);
        read(fd,line,sizeof(line));
        close(fd);

        printf("Processing Input...\n");
        sleep(.5);
        for(int i = 0; line[i]; i++){
                line[i] = tolower(line[i]);
        }

        fd = open("outpu", O_WRONLY);
        write(fd,line,sizeof(line));
        close(fd);

    }
    
}
