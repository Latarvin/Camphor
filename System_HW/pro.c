#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<malloc.h>
#include<signal.h>
#include<string.h>

#define NONE          "\033[m"
#define LIGHT_BLUE    "\033[1;34m"
#define COLOR_LIGHT_CYAN    "\033[1;36m"
#define COLOR_PURPLE        "\033[0;35m"
#define MAX_ARGS 20

char **command;
char **commandList[1000]={0};
int commandNow=0;

void acceptCommand();
void execute(int commandNum);
void handle(int signalNum);

int main()
{
    chdir("~");
    char *file_path_getcwd;
    file_path_getcwd=(char *)malloc(60);

    signal(SIGINT,handle);               //Set handle of SIGINT signal

    while(1){
//ask for a space for current command
        command =(char **) calloc(MAX_ARGS,sizeof(char*));         

        //print the header
        getcwd(file_path_getcwd,60);
        printf(LIGHT_BLUE"emile@lsh"NONE);          
printf(":");

printf(COLOR_LIGHT_CYAN"%s"NONE,!(strcmp(file_path_getcwd,"/home/emile"))?"~":file_path_getcwd);
        printf("$ ");
        fflush(stdout);

        acceptCommand();
    }

}



void acceptCommand()
{
    int i=0;
    while(1){
        command[i]=(char *)calloc(20,sizeof(char));
        scanf("%s",command[i++]);

        char signal=getchar();
        if(i==80)break;
        if(signal=='\n')break;
    }

    if(!strcmp(command[0],"r"))
    {
        //for r and r x command
        if(command[1]==NULL)
        {
            //r
            commandList[commandNow]=commandList[commandNow-1];
            ++commandNow;
            execute(commandNow-1);
        }
        else{
             //r x
            char x=*command[1];
            for(int i=commandNow-1;i>=0&&i>=commandNow-10;--i){
                if(*commandList[i][0]==x) {
                    commandList[commandNow++]=commandList[i];
                    execute(i);
                    return;
                }
            }
            printf("No Command found!\n");
            fflush(stdout);
        }
    }
    else{
        commandList[commandNow++]=command;
        execute(commandNow-1);
    }

    return ;
}

void execute(int commandNum)
{
     //Copy the target command for modifying.
     char **command_p=commandList[commandNum];
     char **temp;
     temp=(char **) calloc(MAX_ARGS,sizeof(char*));
     for(int i=0;i<MAX_ARGS;++i){
         if(command_p[i]){
            temp[i]=(char *)calloc(20,sizeof(char));
            strcpy(temp[i],command_p[i]);
         }
         else break;
     }


    if(!strcmp(temp[0],"cd")){
        if(temp[1][0]=='~')
        {
            int error=0;

            char * path;
            path=(char *) calloc(80,sizeof(char));
            strcpy(path,"/home/emile");

            int i=1;
            while(temp[1][i])
            {
                path[10+i]=temp[1][i];
                ++i;
            }
            path[10+i]=0;
            error=chdir(path);
            if(error==-1)
            {
                printf("emile@lsh: cd: %s: No such file or directory\n",path);
            }
        }
        else
        {
            int error;
            error=chdir(temp[1]);
            if(error==-1)
            {
                printf("emile@lsh: cd: %s: No such file or directory\n",temp[1]);
            }
        }
    }
    else{
         //find the last argue position;
         int bgflag=0;
         while(temp[bgflag]) ++bgflag;
         --bgflag;

         //call temp command
         pid_t pid;

         if(*temp[bgflag]=='&'){                 //Background Mode
                temp[bgflag]=NULL;
                pid=fork();
                if(pid==0) execvp(temp[0],(char * const)temp);
            }
            else{        //Front Mode
                int i;
                pid=fork();
                if(pid==0) {
                        i=execvp(temp[0],(char * const)temp);
                        if(i==-1)   exit(NULL);
                        }
                else waitpid(pid,NULL,0);
            }
    }

     free(temp);
     return ;
}


void handle(int signalNum)
{
    if(signalNum==2){
//Set the begin command to print
        int pos=commandNow>=10?commandNow-10:0;       
for(int i=pos;i<commandNow;++i)
        {
            printf("\n%d: ",i);
            char **arg=commandList[i];
            while (*arg) printf("%s ",*(arg++));
            fflush(stdout);
        }

//print the input hint;
        printf(LIGHT_BLUE"\nemile@lsh:~$ "NONE);
        fflush(stdout);
    }
    return;
}
