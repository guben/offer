//
// Created by 67598 on 2021/8/17.
//

// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

#include<cstdio>
#include<memory.h>
#include<string>
#include<iostream>
using namespace std;

bool Increment(char *number);
void PrintNumber(char *number);
void Print1ToMaxOfNDigits(int n);


//大数加法
void Print1ToMaxOfNDigits(int n){
    if(n<0)
        return ;
    char *number=new char[n+1];
    memset(number,'0',n);
    number[n]='\0';
    while(!Increment(number)){
        PrintNumber(number);
    }
    delete []number;
}

bool Increment(char *number){
    bool isOverflow=false;
    int len=strlen(number);
    int takeover=1;
    for(int i=len-1;i>=0;i--){
        int sumI=number[i]-'0';
        sumI+=takeover;
        if(i==0 && takeover>0){
            isOverflow=true;
        }
        int k=sumI%10;
        number[i]='0'+k;
        takeover=sumI/10;
        if(takeover==0)
            break;
    }
    return isOverflow;
}

void PrintNumber(char *number){
    bool isBeginning0=true;
    int nlength=strlen(number);
    for(int i=0;i<nlength;i++){
        if(isBeginning0 && number[i]!='0')
            isBeginning0 = false;
        if(!isBeginning0){
            printf("%c",number[i]);
        }
    }
    printf("\n");
}

//递归解法，全排列！
void helperRecursive(char *number,int data,int index){
    number[index]='0'+data;
    if(index==0) {
        PrintNumber(number);
        return;
    }
    for(int i=0;i<10;i++){
        helperRecursive(number,i,index-1);

    }
}

void Print1ToMaxOfNDigitsRecursively(int n){
    char *number=new char[n+1];
    memset(number,'0',n);
    number[n]='\0';

    int length=strlen(number);
//    cout<<number<<endl;
//    cout<<length<<endl;
    for(int i=1;i<10;i++){
        helperRecursive(number,i,length-1);
    }
    delete [] number;
}

// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    Print1ToMaxOfNDigits(n);
    Print1ToMaxOfNDigitsRecursively(n);

    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    return 0;
}