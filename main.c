#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute(char * input, const char * separators){

    while (input != NULL)
    {
        printf("Executing %s\n", input);
        input = strtok(NULL, separators);
    }
    
}

int main() {
    printf("You are in the nuSH Shell!\n");
    char buff[100];

    while (1){

    printf("C:> ");
    fgets(buff, sizeof(buff), stdin);

    // find the \n from fgets and replace value with '\0'
    buff[strcspn(buff, "\n")] = '\0';

    if(strncmp(buff, "exit", 4) == 0){
        printf("Goodbye");
        break;
    }  
       else if (strncmp(buff, "help", 4) == 0){
        printf("THis is going to help you.\n");
        continue;
    } 
    else{
        const char * separators = " -/";
        char * pBuff = strtok(buff, separators);
        execute(pBuff, separators);
    }
    }

    
    return 0;
}