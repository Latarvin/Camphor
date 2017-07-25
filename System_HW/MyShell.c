#include <stdio.h>
#include <unistd.h>

int main() {
    // return -1 when exec function err
    char s[50];
    printf("myshell>>");
    gets(s);
    if ( execlp(s, s, "-l", NULL) == -1 )
        perror("Error Executing Command.\n");
    return 0;
}
