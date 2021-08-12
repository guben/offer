//
// Created by 67598 on 2021/7/22.
//

#include<iostream>
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
    B b(1,1);
}