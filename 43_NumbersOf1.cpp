//
// Created by 67598 on 2021/9/2.
//
// 面试题43：从1到n整数中1出现的次数
// 题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
// 输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。
#include <cstdio>
#include <cstring>
#include <cstdlib>

// ====================方法一====================
int NumberOf1(unsigned int n);

int NumberOf1Between1AndN_Solution1(unsigned int n)
{
    int number=0;
    for(unsigned int i=1;i<=n;i++)
        number+=NumberOf1(i);
    return number;
}
int NumberOf1(unsigned int n)
{
    int number = 0;
    while(n)
    {
        if(n % 10 == 1)
            number ++;

        n = n / 10;
    }

    return number;
}


int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);
int NumberOf1Between1AndN_Solution2(int n)
{
    if(n<=0)
        return 0;
    char strN[50];
    sprintf(strN,"%d",n);
    return NumberOf1(strN);
}

int NumberOf1(const char* strN)
{
    if(!strN || *strN<'0' || *strN>'9' || *strN=='\0')
        return 0;
    int first=strN[0]-'0';
    unsigned int length=static_cast<unsigned int>(strlen(strN));
    if(length==1 && first==0)
        return 0;
    if(length==1 && first>0)
        return 1;

    int numFirstDigit=0;//头是1的情况
    if(first>1)
        numFirstDigit=PowerBase10(length-1);
    else if(first==1)
        numFirstDigit=atoi(strN+1)+1;

    int numOtherDigits=first*(length-1)*PowerBase10(length-2); //除开头是1，别的位置是1
    int numRecursive = NumberOf1(strN+1);
    return numFirstDigit+numOtherDigits+numRecursive;
}

int PowerBase10(unsigned int n) //求小于n的最大的 10^k 返回k,即位数信息
{
    int result = 1;
    for(unsigned int i = 0; i < n; ++ i)
        result *= 10;

    return result;
}
// ====================测试代码====================
void Test(const char* testName, int n, int expected)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    if(NumberOf1Between1AndN_Solution1(n) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if(NumberOf1Between1AndN_Solution2(n) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    printf("\n");
}

void Test()
{
    Test("Test1", 1, 1);
    Test("Test2", 5, 1);
    Test("Test3", 10, 2);
    Test("Test4", 55, 16);
    Test("Test5", 99, 20);
    Test("Test6", 10000, 4001);
    Test("Test7", 21345, 18821);
    Test("Test8", 0, 0);
}

int main(int argc, char* argv[])
{
    Test();

    return 0;
}
