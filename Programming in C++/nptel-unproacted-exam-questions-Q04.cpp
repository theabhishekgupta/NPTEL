#include<iostream>
using namespace std;

class WaterHabitat{
    string name;
    int amt;
    
    public:
        WaterHabitat(string _name ,int _amt): name(_name),amt(_amt){
            
        }
        virtual void eat(){
            cout<<name <<"eats "<< amt <<" kg in water" <<endl;
        }
    
};
class LandHabitat{
    string name;
    int amt;
    
    public:
        LandHabitat(string _name ,int _amt): name(_name),amt(_amt){
            
        }
        virtual void eat(){
            cout<<name <<"eats "<< amt <<" kg on land" <<endl;
        }
    
};

class Amphibians : public WaterHabitat ,public LandHabitat{
    public:
    Amphibians(string name ,int _amt1,int _amt2):WaterHabitat(name ,_amt1 ),LandHabitat(name ,_amt2){}
    void eat(){
        WaterHabitat::eat();
        LandHabitat::eat();
    }
    
};







int main(){
    string s;
    int a,b;
    cin>>s;
    cin>>a>>b;
    
    Amphibians an1(s,a,b);
    an1.eat();
    
    return 0;
}