//
// Created by 67598 on 2021/9/2.
//
// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
// 数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。
#include<cstdio>
#include<iostream>
#include<climits>
#include<vector>
using namespace std;
bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
    if(pData== nullptr||nLength<=0){
        g_InvalidInput=true;
        return 0;
    }
    g_InvalidInput=false;

//    int curSum=0;
//    int maxVal=INT_MIN;
//    for(int*p=pData,i=0;i<nLength;i++){
//        if(curSum>=0){
//            curSum+=*(p+i);
//        }
//        else{
//            curSum=*(p+i);
//        }
//        if(curSum>maxVal)
//            maxVal=curSum;
//    }
//    return maxVal;
    vector<int>dp(nLength);
    dp[0]=pData[0];
    int maxV=INT_MIN;
    for(int i=1;i<nLength;i++){
        if(dp[i-1]>0){
            dp[i]=dp[i-1]+pData[i];

        }else{
            dp[i]=pData[i];
        }
        if(maxV<dp[i])
            maxV=dp[i];
    }

    return maxV;
}

// ====================测试代码====================
void Test(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    int result = FindGreatestSumOfSubArray(pData, nLength);
    if(result == expected && expectedFlag == g_InvalidInput)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test4()
{
    Test("Test4", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
