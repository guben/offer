////
//// Created by 67598 on 2021/6/22.
////
//#include <iostream>
//using namespace std;
//class Point3d{
//public:
//    static Point3d origin;
//    float x,y,z;
//};
//int main(int argc,char* argv[]){
//    Point3d p;
//    cout<<sizeof(Point3d)<<endl;
//    cout<<&p<<endl;
//    cout<<&p.x<<endl;
//    cout<<&p.y<<endl;
//    cout<<&p.z<<endl;
//    printf("%d\n",&Point3d::x);
//    printf("%d\n",&Point3d::y);
//    printf("%d\n",&Point3d::z);
//}



#include<iostream>
using namespace std;

class C {
public:
    void fn() {
        std::printf("%p\n", &C::v_);
        std::printf("%p\n", &C::x_);
        std::printf("%p\n", &(C::v_));
        std::printf("%p\n", &(C::x_));
    }
    virtual gn(){
        cout<<"caoshiliangmama"<<endl;
    }
    virtual g2n(){
        cout<<"caoshiliangmama"<<endl;
    }
//private:
public:
    int v_;
    int x_;
};

int main() {
    C c;
    c.fn();
    std::printf("%p\n", &c.v_);
    std::printf("%p\n", &c.x_);
    cout<<"***********"<<endl;
    C c1;
    c1.fn();
    std::printf("%p\n", &c1.v_);
    std::printf("%p\n", &c1.x_);
    cout<<"***********"<<endl;
    std::printf("%p\n", &c1.gn);
    std::printf("%p\n", &c1.g2n);
    return 0;
}