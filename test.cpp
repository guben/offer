//
// Created by 67598 on 2021/7/22.
//

#include<iostream>
#include<string>
using namespace std;
class A{
private:
    int a;
public:
    A():a(0){}
    A(int _a):a(_a){cout<<"A constructor\n";}
    ~A(){cout<<"A destructor\n";}
};
class B: public A{
private:
    int b;
public:
    B():A(),b(1){}
    B(int _a,int _b):A(_a),b(_b){cout<<"B constructor\n";}
    ~B(){cout<<"B destructor\n";}
};
int main(){
//    string a("aaa");
//    cout<<a<<endl;
//    if(a[3]=='\0')
//        cout<<"nice";
    string* p=new string("aaa");
    string* k=p;
    cout<<*p<<endl;
    delete k;
    if(p==nullptr)
        cout<<"ok"<<endl;
    cout<<*p<<endl;
}