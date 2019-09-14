#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int rc = EXIT_SUCCESS;
    int r;
    const char file[] = "fwrite.txt";
    char arr[] = "this is the string";
    char str[20] = {'\0'};
    FILE *fp = fopen(file, "w+b");
    if (fp == 0)
    {
        fprintf(stderr, "Failed to open file %s for reading and writing\n", file);
        rc = EXIT_FAILURE;
    }
    else
    {
        if (fwrite(arr, 1, sizeof(arr), fp) != sizeof(arr))
        {
            fprintf(stderr, "Failed to write to file %s\n", file);
            rc = EXIT_FAILURE;
        }
        else
        {
            fseek(fp, 0, SEEK_SET);
            r = fread(str, 1, sizeof(arr), fp);
            if (r == sizeof(arr))
            {
                printf("read successful\n");
                printf("read = %d bytes\n", r);
                printf("read data [%s]\n", str);
            }
            else
            {
                printf("read unsuccessful\n");
                rc = EXIT_FAILURE;
            }
        }
        fclose(fp);
    }
    return rc;
}