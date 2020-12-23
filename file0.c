#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
    mkfifo("inpu", 0644);

    int fd;
    printf("All inputs are changed to lower case.\n\n");

    while(1){
        fd = open("inpu", O_WRONLY);
        char line[100];
        printf("Input a string.\n");
        fgets(line,sizeof(line), stdin);
        write(fd,line,sizeof(line));
        close(fd);

        fd = open("outpu",O_RDONLY);
        read(fd,line,sizeof(line));
        printf("Output: %s\n", line);
        close(fd);

    }
    
}