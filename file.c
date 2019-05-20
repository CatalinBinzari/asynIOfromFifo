// C program to implement one side of FIFO 
// This side reads first, then reads 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>

int functionMaxFd(int array[],int argc) {
    int maxValue=-999;
    for(int i=0;i<argc-1;i++){
        if(array[i]>=maxValue){
            maxValue=array[i];
        }

    }
 return maxValue;
}
  
int main(int argc, char *argv[]) 
{   printf("Number of arguments are : %d\n", argc - 1);
    //printf("Your argument is :%s\n", argv[1]);
    int fd[20];
    
    //int fd1,fd2; 
    for(int i =0;i<argc-1;i++){
        if( access( argv[i+1], F_OK ) == -1 ) {
            printf("FILE <%s> DOES NOT EXISTS!\n",argv[i+1]);
            continue;
        }
        fd[i]=open(argv[i+1],O_RDWR,O_NONBLOCK);
        
    }
    // FIFO file path 
    //char * myfifo = argv[1]; 
    //char * ourfifo = argv[2]; 
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>,<permission>) 
    //mkfifo(myfifo, 0666); 
    
    //char *str1=(char*)malloc(500); 
    
    fd_set fds;
        int maxfd;
        int res;
        FD_ZERO(&fds);
    char str1[80];
    for(;;){
         // Clear FD set for select
        for(int i =0;i<argc-1;i++){
            FD_SET(fd[i], &fds);
        }
        //FD_SET(fd[0], &fds);
        //FD_SET(fd[1], &fds);
        //printf("fd0: %d fd1= %d \n",fd[0],fd[1] );
        maxfd = functionMaxFd(fd,argc);
        //printf("max fd: %d\n",maxfd);
        select(maxfd + 1, &fds, NULL, NULL, NULL);
        
        for(int i=0;i<argc-1;i++){
            if( FD_ISSET(fd[i], &fds) ){
                
                 // We can read from fileDescriptor1
                 res = read(fd[i], str1, sizeof(str1));
                 if (res > 0)
                 {
                    printf("%s", str1);
                 }
                 break;
                    
            }

        }
        /*
        if (FD_ISSET(fd[0], &fds))
          {
             // We can read from fileDescriptor1
             res = read(fd[0], str1, sizeof(str1));
             if (res > 0)
             {
                printf("%s", str1);
             }
          }
          if (FD_ISSET(fd[1], &fds))
          {
             // We can read from fileDescriptor2
            res = read(fd[1], str1, sizeof(str1));
            if (res > 0)
            {
                 printf("%s", str1);
            }*/
          





        
        
        
        
        //system("cat /dev/null > myfifo");
    //break;
    }
    

return 0;
}