#include<iostream>
using namespace std;

class inches;
class foot {
    private:
    int val;
    public:
    foot(int _val): val(_val){}
    inches operator()();
    friend inches operator+(foot& f ,inches& i);
};

class inches{
    private:
        int val;
    public:
        inches() :val(){}
        inches(int _val) :val(_val){}
        friend inches operator+(foot& f ,inches& i);
        friend class foot;
        void print();
};

inches foot::operator()(){
    inches i;
    i.val=val*12;
    return i;
}

inches operator+(foot& f ,inches& i){
    inches i1;
    i1.val=i.val+f().val;
    return i1;
}

void inches:: print(){
    cout<<val;
}

int main(){
    int a, b;
    cin>>a>>b;
    foot f(a);
    inches i(b);
    (f+i).print();
    return 0;
}