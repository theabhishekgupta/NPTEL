#include<iostream>
using namespace std;

class Account{
    static long s1;//
    long acc_no;
    string name;
    mutable double balance;
    public:
        Account(string _name ,double _balance):acc_no(++s1) ,name(_name),balance(_balance){}
    
        void change( double _b)const{
            balance=_b;
        }
        void print() const{
            cout<<acc_no <<":"<< name <<":" <<balance<<endl;
            
        }
};

long Account::s1=10000;

int main(){
    const Account *ac[3];
    for(int i=0; i<3;i++){
        string n;
        double b;
        cin>>n>>b;
        ac[i]=new Account(n,b);
        
    }
    for(int i=0;i<3;i++){
        double cb;
        cin>>cb;
        ac[i]->change(cb);
        
    }
    for(int i=0;i<3;i++){
        ac[i]->print();
    }
    return 0;
}