#include<iostream>
using namespace std;

class point 
{
    int x;
    int y;
    public:
        point():x(0),y(0){}
        point(int _x ,int _y):x(_x),y(_y){}
        point operator+(int);
        point operator++(int);
        
        void display(){
            cout<<x<<","<<y<<endl;
        }
        
};

point point::operator++(int){
    point temp;
    x++;
    temp.x=x;
    return temp;
}
point point::operator+(int m){
    point temp;
    temp.x=x+m;
    temp.y=y+m;
    return temp;
}
        
        
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    point p(x,y);
    p=p+z;
    p++;
    p.display();
    return 0;
}
