//save command output to a variable result

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fpipe;
    char *command = "who";
    char result[1024]={0x0};

    if (0 == (fpipe = (FILE*)popen(command, "r")))
    {
        perror("popen() failed.");
        exit(EXIT_FAILURE);
    }

    while (fgets(result, sizeof(result), fpipe) !=NULL)
           printf("%s", result);

    pclose(fpipe);

    return EXIT_SUCCESS;
}


