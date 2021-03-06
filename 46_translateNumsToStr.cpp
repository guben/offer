//
// Created by 67598 on 2021/9/3.
//
#include <string>
#include <iostream>
using namespace std;
int GetTranslationCount(const string& number);

int GetTranslationCount(int number){
    if(number<0)
        return 0;
    string numInStr=to_string(number);
    return GetTranslationCount(numInStr);
}

int GetTranslationCount(const string& number){
    int length=number.size();
    int * counts=new int[length];
    int count=0;
    for(int i=length-1;i>=0;--i){
        count=0;
        if(i<length-1)
            count=counts[i+1]; //至少有一种解释
        else
            count=1;
        if(i<length-1){
            int digit1=number[i]-'0';
            int digit2=number[i+1]-'0';
            int converted=digit1*10+digit2;
            if(converted>=10 && converted<=25){//可能有第二种解释
                if(i<length-2)
                    count+=counts[i+2];
                else//考虑边界
                    count+=1;
            }
        }
        counts[i]=count;
    }
    count=counts[0];
    delete [] counts;
    return count;
}

// ====================测试代码====================
void Test(const string& testName, int number, int expected)
{
    if(GetTranslationCount(number) == expected)
        cout << testName << " passed." << endl;
    else
        cout << testName << " FAILED." << endl;
}

void Test1()
{
    int number = 0;
    int expected = 1;
    Test("Test1", number, expected);
}

void Test2()
{
    int number = 10;
    int expected = 2;
    Test("Test2", number, expected);
}

void Test3()
{
    int number = 125;
    int expected = 3;
    Test("Test3", number, expected);
}

void Test4()
{
    int number = 126;
    int expected = 2;
    Test("Test4", number, expected);
}

void Test5()
{
    int number = 426;
    int expected = 1;
    Test("Test5", number, expected);
}

void Test6()
{
    int number = 100;
    int expected = 2;
    Test("Test6", number, expected);
}

void Test7()
{
    int number = 101;
    int expected = 2;
    Test("Test7", number, expected);
}

void Test8()
{
    int number = 12258;
    int expected = 5;
    Test("Test8", number, expected);
}

void Test9()
{
    int number = -100;
    int expected = 0;
    Test("Test9", number, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}