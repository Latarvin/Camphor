    #include <stdio.h>  
    #include <stdlib.h>  
    #include <unistd.h>//管道所在的头文件    
    #include <string.h>//用来测定字体长度strlen()的头文件    
    #define MAX_LINE 1024//设置缓冲区的大小    
    int main(int argc,char* argv[]){    
        if(argv[1]==NULL||argv[1]==NULL){    
            printf("请输入两个文件路径，第一个为源，第二个为目的！\n");    
            exit(1);    
        }    
        char* source_path=argv[1];//取用户输入的第一个参数    
        char* destination_path=argv[2];//取用户输入的第二个参数      
        FILE *in,*out;//定义两个文件流，分别用于文件的读取和写入int len;    
        if((in=fopen(source_path,"r"))==NULL){//打开源文件的文件流    
            printf("源文件不存在，请检查路径输入是否存在！\n");    
            exit(1);    
        }    
        if((out=fopen(destination_path,"w"))==NULL){//打开目标文件的文件流    
            printf("创建目标文件流失败！\n");    
            exit(1);    
        }  
        char buffer[MAX_LINE+1];  
        int myPipe[2];  
        int len;//记录读取与写入长度  
        if(pipe(myPipe)==0){//创建管道  
            pid_t fpid=fork();    
            if(fpid<0){       
                printf("创建父子进程失败！");    
            }    
            else if(fpid==0){             
                while((len=fread(buffer,1,MAX_LINE,in))>0){  
                    write(myPipe[1],buffer,len);//对管道写入读到的文件东西  
                }   
            }      
            else{    
                int len=read(myPipe[0],buffer,MAX_LINE);//将管道的东西读到缓冲区  
                fwrite(buffer,1,len,out);//将缓冲区的数据写到目标文件中  
                printf("复制成功完成！\n");    
            }      
            waitpid(fpid,NULL,0);    
            fclose(out);    
            fclose(in);   
        }     
        //一般管道的管道的开启与关闭成轴对称    
        close(myPipe[0]);    
        close(myPipe[1]);   
        return 0;  
    }    
