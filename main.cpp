#include<iostream>
using namespace std;
class employee
{
protected:

    char*name ;
    float salary;public:
public:
    employee(float s,char*n){
    this->salary=s;
    this->name=n;
    };
    virtual void paycut(float amt){///dynamic polymorhism
         salary-=amt;
    };
    void payrise(){//static polymorphism
        salary+=100;
    };
    //friend operator overloading
    friend ostream& operator<<(ostream & o,const employee & e){//static polymorphism
        return (o<<e.name<<" paid "<<e.salary);
    };
};
//inheritance
class manager:public employee
{
private:
    int level;
public:
    manager(int l,char*n):employee(1000*l,n){
        level=l;
    };
    //polymorhism
    virtual void paycut(float amt){
        salary-=(level*amt);
    };
    void payrise(){
        salary+=800;
    };
    friend ostream& operator&&(ostream & o,const manager & m){
        return (o<<m<<",at level "<<m.level);
    };

};
//inheritance
class super_manager:public manager
{

public:
    super_manager(char*n): manager(10,n){

    };
    void paycut(float a){
        salary*=2;
    };
};

int main()
{
    employee e(1345.6,"ali");
    cout<<e<<endl;
    e.paycut(300);
    e.payrise();
    cout<<e;
  manager m(5,"hamza");
   cout<<m<<endl;
   (cout&&m)<<endl;
   m.payrise();
   cout<<m<<endl;
   m.paycut(30);
   cout<<m;
   employee *e1=new employee(5,"HT");
   employee *e2=new super_manager("vc");
   cout<<*e1<<endl;
   e1->paycut(300);
   cout<<*e1<<endl;
   e1->payrise();
   cout<<*e1<<endl;
    cout<<*e2<<endl;
   e2->paycut(300);
    cout<<*e2<<endl;
   e2->payrise();
   cout<<*e2<<endl;
    return 0;
}