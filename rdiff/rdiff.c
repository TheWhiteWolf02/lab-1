#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

//int main(int argc, char** argv) {
//    void *buffer;
//    FILE *f1, *f2;
//    int read, count;
//    long long int size1, size2;
//
//    if((f1 = fopen(argv[1], "r")) && (f2 = fopen(argv[2], "r")))
//    {
//        fseek(f1, 0, SEEK_END); // seek to end of file
//        size1 = ftell(f1); // get current file pointer
//
//        fseek(f2, 0, SEEK_END); // seek to end of file
//        size2 = ftell(f2); // get current file pointer
//
//        if(size1 != size2)
//        {
//            printf("files are not equal size\n");
//            exit(1);
//        }
//
//        fseek(f1, 0, SEEK_SET); // seek back to beginning of file
//        fseek(f2, 0, SEEK_SET); // seek back to beginning of file
//
//        fseek(f1, -1L, 2);
//        while(!feof(f2) && !feof(f1))
//        {
//            if(fgetc(f1) != fgetc(f2))
//            {
//                printf("character mismatch\n");
//                exit(1);
//            }
//            fseek(f1, -2L, 1); // shifts the pointer to the previous character
//        }
//    }
//    fclose(f1);
//    fclose(f2);
//    return 0;
//}

int main(int argc, char** argv)
{
    FILE *f1,*f2;
    int ft,i=0,ft2;
    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");
    if(f1==NULL)
    {
        printf("ERROR");
        return 0;
    }

    fseek(f1,0,SEEK_END);
    ft=ftell(f1);

    fseek(f2,0,SEEK_END);
    ft2 = ftell(f2);

    if(ft != ft2)
    {
        printf("size mismatch\n");
        exit(1);
    }
    else
    {
        fseek(f2,0,SEEK_SET);
    }

    while(i<ft)
    {
        i++;
        fseek(f1,-i,SEEK_END);
        if(fgetc(f1) != fgetc(f2))
        {
            printf("character mismatch\n");
            exit(1);
        }
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
