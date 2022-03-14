#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

int main(int argc, char** argv)
{
    FILE *f1,*f2;
    int ft,i=0;
    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "w");
    if(f1==NULL)
    {
        printf("ERROR");
        return 0;
    }
    fseek(f1,0,SEEK_END);
    ft=ftell(f1);
    while(i<ft)
    {
        i++;
        fseek(f1,-i,SEEK_END);
        fputc(fgetc(f1), f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
