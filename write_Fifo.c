#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <stdio.h>

  
int main(int argc, char *argv[]) 
{ printf("Number of arguments are : %d\n", argc - 1);
    //printf("Your argument is :%s\n", argv[1]);
    int fd1; 
  
    // FIFO file path 
    char * myfifo = argv[1]; 
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>,<permission>) 
    mkfifo(myfifo, 0666); 
    char str2[80];
    //char *str1=(char*)malloc(500); 
    while (1) 
    { 
        // Now open in write mode and write 
        // string taken from user. 
        fd1 = open(myfifo,O_WRONLY); 
        fgets(str2, 80, stdin); 
        write(fd1, str2, strlen(str2)+1); 
        close(fd1); 


        //system("cat /dev/null > myfifo");
    //break;
    }

return 0;
}