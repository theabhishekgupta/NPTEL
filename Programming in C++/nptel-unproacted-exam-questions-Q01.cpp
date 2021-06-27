#include<iostream>
#include<cstring>
using namespace std;

char * Allocateessage(char * , char*);


typedef char* (*fun_ptr)(char*);


char * Allocateessage(char *str ,char *msg){
    char *s =new char[(strlen(str)+strlen(msg))-1];
    return s;
}


char * CreateMessage(char *s ,char*str ,char *msg){
    strcpy(s,str);
    strcat(s,msg);
    return s;
}

char * client1(char *msg){
    char str[]="client1: ";
    char *s =Allocateessage(str,msg);
    char *s1 =CreateMessage(s,str,msg);
    return s1;
}

char * client2(char * msg){
    char str[]="client2: ";
    char *s=Allocateessage(str ,msg);
    char *s1= CreateMessage(s,str,msg);
    return s1;
    
}

char * client3(char * msg){
    char str[]="client3: ";
    char *s=Allocateessage(str ,msg);
    char *s1= CreateMessage(s,str,msg);
    return s1;
    
}


int main(){
    int i;
    char msg[80];
    fun_ptr fp[3]={&client1,&client2,&client3};
    
    cin>>i>>msg;
    const char * caller(fun_ptr *,int ,char*);
    const char *s =caller(fp ,i,msg);
    cout<<s;
    return 0;
}
const char* caller(fun_ptr *fp ,int i ,char* msg){
    if(i>=0 && i<3){
        fp[i](msg);
        }
        else
        {
            const char *s ="unknown client";
            return s;
        }
}
