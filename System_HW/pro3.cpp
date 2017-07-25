#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

#include <sys/mman.h>
#include <cstdio>
using namespace std;
#define MAXLINE 80
#define BUFFERSIZE 50
#define COMMANDSIZE 100
char buffer[BUFFERSIZE];

char *command[10][MAXLINE/2+1];
int sametime[10];
int len[10];
int comnum=0;

void setup(char inputBuffer[], char *args[],int *background)
{
	int i=0, j=0, k=0;
	bool flag = 1;
	args[j] = new char[MAXLINE];
	for( i=0; i<MAXLINE; ++i )
	{
		if( inputBuffer[i] == '\n' )
		{
			args[j][k] = '\0';
			break;
		}
		if( inputBuffer[i] == ' ' || inputBuffer[i] == '\t' )
		{
			flag = 0;
			continue;
		}
		if( flag != 0 )
		{
			args[j][k] = inputBuffer[i];
			k++;
		}
		if( flag == 0 )
		{
			args[j][k] = '\0';
			j = j + 1;
			args[j] = new char[MAXLINE/2+1];
			k = 0;
			flag = 1;
			args[j][k] = inputBuffer[i];
			k++;
		}
	}
	if( args[j][0] == '&' && args[j][1] == '\0' )
	{
		*background = 1;
		args[j] = NULL;
	}
	args[j+1] = NULL;

	if( comnum < 10 )
	{
		int a = 0;
		while(args[a])
		{
			command[comnum][a] = new char[MAXLINE/2+1];
			strcpy(command[comnum][a],args[a]);
			a++;
		}
		command[comnum%10][a] = NULL;
	}
	else
	{
		int a = 0;
		while(args[a])
		{
			if( !command[comnum%10][a] )
				command[comnum%10][a] = new char[MAXLINE/2+1];
			strcpy(command[comnum%10][a],args[a]);
			a++;
		}
		command[comnum%10][a] = NULL;
	}
	if(*background)
	{
		len[comnum%10] = j - 1;
		sametime[comnum%10] = 1;
	}
	else
	{
		len[comnum%10] = j;
		sametime[comnum%10] = 0;
	}
	comnum++;
	//test
/*
	if(strcmp("cd",args[0])==0){
		char *tmpargs[MAXLINE/2+1];
		for(int hh=0;hh<=j;++hh)tmpargs[hh]=new char[MAXLINE];
		for(int hh=0;hh<=j;++hh)strcpy(tmpargs[hh],args[hh]);
		strcpy(args[0],"bash");
		strcpy(args[1],"-c");
		args[j+1] = new char[MAXLINE];
		args[j+2] = new char[MAXLINE];
		for(int hh=0;hh<=j;++hh)strcpy(args[hh+2],tmpargs[hh]);
		j+=2;
	}
for(int hh=0;hh<=j;++hh)cout<<args[hh]<<endl;
	//if(strcmp(args[0],"cd")==0)
	//test end
*/
}

void handle_SIGINT(int sig)
{
	int i;
	cout << endl;
	for( i = 10; i > 0; i-- )
	{
		if( comnum-i >= 0 )
		{
			cout << comnum - i + 1 << "\t";
			for( int j=0; j < len[(comnum-i)%10]+1; j++ )
				cout << command[(comnum-i)%10][j] << " ";
			if( sametime[(comnum-i)%10] )
				cout << "&";
			cout << endl;
		}
	}

	char rbuf[MAXLINE];
	while(true)
	{
		fgets( rbuf, MAXLINE, stdin );
		if( rbuf[0] == 'q' )
		{
			if( rbuf[1] != '\n' )
			{
				cout << "It is a wrong command!1" << endl;
			}
			else
			{
				break;
			}
		}
		else if( rbuf[0] == 'r' )
		{
			if( rbuf[1] == '\n' )
			{
					pid_t pid;
					pid = fork();

					if( pid < 0 )
					{
						printf("%s","fork faild");
						exit(-1);
					}
					else if( pid == 0 )
					{
						execvp( command[(comnum-1)%10][0], command[(comnum-1)%10] );
						exit(0);
					}
					else
					{
						if( !sametime[(comnum-1)%10] )
							waitpid( pid, NULL, 0 );
					}
					int a = 0;
					if( comnum < 10 )
					{
						int a = 0;
						while(command[(comnum-1)%10][a])
						{
							command[comnum][a] = new char[MAXLINE/2+1];
							strcpy(command[comnum][a],command[(comnum-1)%10][a]);
							a++;
						}
						command[comnum%10][a] = NULL;
						comnum++;
					}
					else
					{
						int a = 0;
						while(command[(comnum-1)%10][a])
						{
							if( !command[comnum%10][a] )
								command[comnum%10][a] = new char[MAXLINE/2+1];
							strcpy(command[comnum%10][a],command[(comnum-1)%10][a]);
							a++;
						}
						comnum++;
						command[comnum%10][a] = NULL;
					}
			}
			else if( rbuf[1] != ' ' )
			{
				cout << "It is a wrong command!2" << endl;
			}
			else
			{
				if( rbuf[3] != '\n' )
				{
					cout << "It is a wrong command!3" << endl;
				}
				else
				{
					int b;
					for( b=0; b<10; ++b )
					{
						if( comnum-b == 0 )
						{
							break;
						}
						if( command[(comnum-b-1)%10][0][0] == rbuf[2] )
						{
							pid_t pid;
							pid = fork();

							if( pid < 0 )
							{
								printf("%s","fork faild");
								exit(-1);
							}
							else if( pid == 0 )
							{
								execvp(command[(comnum-b-1)%10][0],command[(comnum-b-1)%10]);
								exit(0);
							}
							else
							{
								if( !sametime[(comnum-b-1)%10] )
									waitpid(pid,NULL,0);
							}
							int a = 0;
							if( comnum < 10 )
							{
								int a = 0;
								while(command[(comnum-b-1)%10][a])
								{
									command[comnum][a] = new char[MAXLINE/2+1];
									strcpy(command[comnum][a],command[(comnum-b-1)%10][a]);
									a++;
								}
								command[comnum%10][a] = NULL;
								comnum++;

							}
							else
							{
								int a = 0;
								while(command[(comnum-b-1)%10][a])
								{
									if( !command[comnum%10][a] )
										command[comnum%10][a] = new char[MAXLINE/2+1];
									strcpy(command[comnum%10][a],command[(comnum-b-1)%10][a]);
									a++;
								}
								command[comnum%10][a] = NULL;
								comnum++;
							}
							break;
						}
					}
					if( b==10 || comnum==b+1 )
					{
						cout << "There is no command that the first letter is " << rbuf[2] << endl;
					}
				}
			}
		}
	}
}

void handle_SIGTSTP(int sig)
{
	exit(0);
}

int main(void)
{
/*	struct sigaction handler;
	handler.sa_handler=handle_SIGINT;
	sigaction(SIGINT,&handler,NULL);

	strcpy(buffer,"Caught COntrol C");
*/
	signal(SIGINT,handle_SIGINT);
	signal(SIGTSTP,handle_SIGTSTP);
	char *inputBuffer = new char[MAXLINE];
	int *background = new int;
	char *args[MAXLINE/2+1];
	while(1)
	{
		*background = 0;

		printf("COMMAND-->");
		fgets(inputBuffer,MAXLINE,stdin);
		setup(inputBuffer,args,background);
		pid_t pid;
		pid = fork();

		if( pid < 0 )
		{
			printf("%s","fork faild");
			exit(-1);
		}
		else if( pid == 0 )
		{
			execvp(args[0],args);
			exit(0);
		}
		else
		{
			if(strcmp("cd",args[0])==0)chdir(args[1]);
			if(!(*background))
				waitpid(pid,NULL,0);
		}
		//wait();
		int i = 0;
		while(args[i])
		{
			delete []args[i];
			args[i]=NULL;
			i++;
		}

	}

	return 0;
}
