//
// Created by 67598 on 2021/8/13.
//
// 面试题12：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。

#include<iostream>
#include<cmath>
using namespace std;
bool g_InvalidInput =false; //使用一个全局变量作为函数调用结果的判断，这个变量用于判断输入是否正确
bool equal(double num1, double num2);//一定要非常注意小数的等于判断！
double PowerWithUnsignedExponent(double base,unsigned int exponent);//优化正整数次幂的运算

double Power(double base,int exponent){
    g_InvalidInput=false;
    if(equal(base,0.0) && exponent<0){
        g_InvalidInput=true;
        return 0.0;
    }

    unsigned int absExponent=(unsigned int)(exponent);
    if(exponent<0)
        absExponent=(unsigned int)(-exponent);
    double result=PowerWithUnsignedExponent(base,absExponent);
    if(exponent<0)
        result=1.0/result;

    return result;
}

bool equal(double num1,double num2){
    return num1 - num2 > -1e-7 && num1 - num2 < 1e-7;
}

double PowerWithUnsignedExponent(double base,unsigned int exponent) {
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if ((exponent & 0x01) == 1)
        result *= base;
    return result;
}

void Test(const char* testname,double base,int exponent,double expectedResult,bool expectedFlag){
    double result=Power(base,exponent);
//    std::cout<<result<<" "<<expectedResult<<std::endl;
    if(equal(result,expectedResult) && g_InvalidInput==expectedFlag)
        std::cout<<testname<<" passed"<<std::endl;
    else
        std::cout<<testname<<" failed"<<std::endl;
}

int main(int argc, char* argv[])
{
    // 底数、指数都为正数
    Test("Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    Test("Test2", -2, 3, -8, false);

    // 指数为负数
    Test("Test3", 2, -3, 0.125, false);

    // 指数为0
    Test("Test4", 2, 0, 1, false);

    // 底数、指数都为0
    Test("Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    Test("Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    Test("Test7", 0, -4, 0, true);

    // 大一点的计算
    Test("Test8", 3.44, 4, pow(3.44,4), false);
    return 0;
}