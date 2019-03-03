#include<iostream>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
using namespace std;

class System
{
public:
   /* System(char * name ,int passwd)
    {
        _name = new char[20];
        _passwd = passwd;
    }*/
    


 //   ~System();
   /*
    void choose()
    {
        cout<<"please choose to login or register\nregiste   login"<<endl;
        char buff[20]={0};
        fgets(buff,20,stdin);
        buff[strlen(buff)-1]=0;
        if(strcmp(buff,"registe") == 0)
        {
            registe();
            login();
        }
        if(strcmp(buff,"login") == 0)
        {
            login();
        }
    }
    */  
    void  registe()
    {
        int fd = open("date.txt",O_RDWR|O_CREAT|O_APPEND,0600);
        if( fd == -1)
        {
            cout<<"open error"<<endl;
        }

        char buff[1024]={0};
        cout<<"请设置用户名:"<<endl;

        fgets(buff,1024,stdin);
        buff[strlen(buff)-1]=0; 
        char buff1[2]=":";
        strcat(buff,buff1);
    
        write(fd,buff,strlen(buff));
        
        memset(buff,0,strlen(buff));
        cout<<"请设置登录密码:"<<endl;
        
        fgets(buff,1024,stdin);
        buff[strlen(buff)-1]=0;
        char buff2[2]=";";
        strcat(buff,buff2);
        write(fd,buff,strlen(buff));
        
        close(fd);   
    }
    void  login()
    {
        int fd = open("date.txt",O_RDONLY);
        if( fd ==-1)
        {
            cout<<"open error"<<endl;
        }
        char recv[1000] = {0};
        char buff[256]={0};
        int num = 0;
        while(( num = read(fd,buff,256)) > 0)
        {
            strcat(recv,buff);

        }
        close(fd);
        char * idps[1024]={0};
        char * s = strtok(recv,";");
        int i = 0;
        while(s != NULL)
        {
            idps[i++]=s;
            s = strtok(NULL,";");
        }
        char buff1[1024];
        cout<<"请输入用户名："<<endl;
        fgets(buff1,1024,stdin);
        buff1[strlen(buff1)-1]=0;
        char a[2]=":";
        strcat(buff1,a); 

        char ps[20]={0};
        cout<<"请输入登录密码："<<endl;
        fgets(ps,20,stdin);
        ps[strlen(ps)-1]=0;
        strcat(buff1,ps);

        int j=0;
        while(idps[j]!=NULL)
        {
            if ((strcmp(buff1,idps[j])) == 0)
            {
                cout<<"login success!"<<endl;
                break;
            }
            
            if((strcmp(buff1,idps[j]))!=0 && j==i-1)
            {
                cout<<"user name or password error!login again piease."<<endl;
                login();
            }
        
            j++;
        }
      /*
        while(1)
        {
            for(;j<i;j++)
            {
                int n = strcmp(buff1,idps[j]);
                if( n == 0)
                {
                cout<<"login success!"<<endl;

                }
            }
            cout<<"login failure"<<endl;
        }*/
    }   
private:
    char *_name;
    int  _passwd;   
};



int main()
{
    System a;
   // a.choose();
   // a.registe();
   // a.login();
    return 0;
}
