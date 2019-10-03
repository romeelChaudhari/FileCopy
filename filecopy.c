
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//You may also add more include directives as well.

// THIS VALUE CANNOT BE CHANGED.
// You should use this value when creating your buffer.
// And also to limit the amount of bytes each read CAN do.
#define BUFF_MAX 13
// DO NOT CHANGE ABOVE



int main(int argc, char const *argv[])
{
    ssize_t totalBytes = 0, bytesr = 0 , bytesw = 0;
    char buffer [BUFF_MAX]; // buffer size 13
    int Reader = 1;
    int Writer = 1;
    char fileReader[300];
    char fileWriter[300];
    printf("Welcome to the File Copy Program by Romeel Chaudhari! \n");
    printf("Enter the name of the file to copy from: ");
    scanf("%s", fileReader);
    printf("Enter the name of the file to copy to: ");
    scanf("%s", fileWriter);
    Writer = open(fileWriter, O_CREAT|O_EXCL|O_RDWR);// open the Write file
    if(Writer < 0)
    {
        perror("Openning Write File Failed!");
        return -1;// error searching
    }
    Reader = open(fileReader, O_RDONLY);// open the Read file
    if(Reader< 0){
        perror("Openning Read File Failed!");
        return -1;
        // error searching
    }
    do {
        bytesr = read(Reader, buffer, 13);// read buffer 13 bytes
        if(bytesr < 0) {
            perror("Reading File Failed!");
            return -1;// error
        }
        bytesw = write(Writer, buffer, bytesr);// write buffer 13 bytes
        if(bytesw < 0){
            perror("Writing File Failed!");
            return -1;//  error
        }
        totalBytes= totalBytes+ bytesw;
    } while(bytesr != 0);
    printf("File Copy Successful, %zd bytes copied.\n", totalBytes);
    close(Reader);
    close(Writer);
    return 0;// closes both the files
}



