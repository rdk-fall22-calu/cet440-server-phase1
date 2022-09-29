//save command output to a variable result

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fpipe;
    int active_users_count;
    char *command = "who";
    char result[1024]={0x0};
    char active_users[50][50];
    char *token;

    if (0 == (fpipe = (FILE*)popen(command, "r")))
    {
        perror("popen() failed.");
        exit(EXIT_FAILURE);
    }

    active_users_count = 0;
    while( fgets(result, sizeof(result), fpipe) != NULL )
    {
        token = strtok(result, " ");
        printf("token: %s\n", token);
        memcpy(active_users[active_users_count], token);
        active_users_count++;
        printf("%s\n", active_users[active_users_count]);
    }

    pclose(fpipe);

    return EXIT_SUCCESS;
}


