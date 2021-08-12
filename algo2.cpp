//
// Created by 67598 on 2021/6/22.
//
// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。
#include <cstdio>
bool duplicate(int numbers[], int length, int* duplication)
{
    if(numbers== nullptr||length<=0) //检查数据合法性
        return false;

    for(int i=0;i<length;i++){ //依然是检查数据合法性
        if(numbers[i]<0 || numbers[i]>length-1)
            return false;
    }

    for(int i=0;i<length;i++){
        while(numbers[i]!=i) {
            if (numbers[i] == numbers[numbers[i]]) {
                *duplication = numbers[i];
                return true;
            }

            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}

// ====================测试代码====================
bool contains(int array[], int length, int number){
    for(int i=0;i<length;i++){
        if(array[i]==number)
            return true;
    }
    return false;
}

void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);//测试，函数返回值

    if(validArgument == validInput)//和预期一致
    {
        if(validArgument)//数组中有重复元素
        {
            if(contains(expected, expectedExpected, duplication))//看看我们函数返回的在不在预期答案里面
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

//重复的数字是数组里最小的数字
void test1(){
    int numbers[]={2,1,3,1,4};
    int duplications[]={1};
    test("Test1", numbers, sizeof(numbers)/sizeof(int),duplications,sizeof(duplications)/sizeof(int), true);
}

//重复的数字是数组中最大的数字
void test2(){
    int numbers[]={2,4,3,1,4};
    int duplications[]={4};
    test("Test1", numbers, sizeof(numbers)/sizeof(int),duplications,sizeof(duplications)/sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
    int* numbers = nullptr;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

void test7()
{
    int numbers[] = {0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int duplications[] = { 11 };
    test("Test7", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

int main()
{
    //学习一下测试代码是怎么写的
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
}