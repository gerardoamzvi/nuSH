#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Command{ 

    char name[20];
    char ** text;
};

void initialize_command_help();
char (*initialize_command_array())[10];
void execute(char * input, const char * separators);
bool includes(char array[][10], int length,char * value);

int main() {
    printf("You are in the nuSH Shell!\n");
    char buff[100];
    char (*command_list)[10] = initialize_command_array();
    int length = 3; //I'll find a solution later
    printf("%d", length);
    while (1){

    printf("C:> ");
    fgets(buff, sizeof(buff), stdin);

    // find the \n from fgets and replace value with '\0'
    buff[strcspn(buff, "\n")] = '\0';
    
    // Skip space and tabulations at the beginning of your command using pointer algebra
    //char * cmd = buff + strspn(buff, " \t");
    
    // Look for the first character 
    char * first_word = strtok(buff, " \t\n");

    //initialize the command list (Not the best place to do that)




    // if first word is exit and there's no second one just exit
    if (first_word != NULL && strcmp(first_word, "exit") == 0){
        char * next_word = strtok(first_word, " \t\n");
        if (next_word != NULL){
            printf("This is the wrong command did you mean just 'exit' ??");
        }
        else{    
            printf("Goodbye");
            break;
        }
    }

    
    //else if it is help look at second word and look for corresponding info in struct 
    else if (first_word != NULL && strcmp(first_word, "help") == 0){
            char * next_word = strtok(NULL, " \t\n"); // continue looking for the next word in the same buffer 
            if (next_word == NULL){
                printf("This is the default help message\n");
            }
            else{    
                printf("You can't see command help for the moment\n");
            }
            continue;

    } 
    // for all the rest look in the list of commands

        else if (first_word != NULL && includes(command_list, length ,first_word)){
            //char * next_word = strtok(first_word, " \t\n");
            const char * separators = " -/";
            char * pBuff = strtok(buff, separators);
            execute(pBuff, separators);

    } 
    else{
        printf("This is not an existing command\n");
    }
    }

    
    return 0;
}


bool includes(char array[][10], int length,char * value){

    for (int i = 0; i < length; i++){
        if (strcmp(array[i], value) == 0){
            return true;
        }
    }
    return false;
}
void initialize_command_help(){
    //struct Command command[5];
}

char (*initialize_command_array())[10]{
    static char commands[][10] =  {"ls", "cd", "whoami"};
    return commands;
}


void execute(char * input, const char * separators){

    while (input != NULL)
    {
        printf("Executing %s\n", input);
        input = strtok(NULL, separators);
    }
    
}
