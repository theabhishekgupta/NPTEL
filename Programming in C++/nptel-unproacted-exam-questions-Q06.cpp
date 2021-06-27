#include<iostream>
#include<cstring>
using namespace std;

class NegativeValException{
    int _what;
    char _what_str[80];
    public:
    NegativeValException(const int what ,const char* what_str):_what((what))
    {
        strcpy(_what_str,what_str);
    }
    
    friend ostream& operator<<(ostream & ,NegativeValException &);
    
};
ostream& operator<<(ostream &os,NegativeValException &e){
    os<< e._what_str<<" : "<<e._what;
    return os;
}

class Data{
    int val;
    public:
        void setVal(int _val){
            try{
                if(_val <0){
                    val=0;
                    throw NegativeValException(_val ,"negative value x 10");
        
                }
                val=_val;
            }
            catch(NegativeValException &e){
                cout<<e;
                
            }
        }
        int getVal(){
            return val;
        }
};

int  main(){
    Data d;
    int i;
    cin>>i;
    d.setVal(i);
    cout<<d.getVal();
    return 0;
}