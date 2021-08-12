//
// Created by 67598 on 2021/8/12.
//

#include <cstdio>
#include <exception>
int MinInOrder(int* numbers, int index1, int index2);

//int Min(int* numbers, int length)
//{
//    if(numbers == nullptr || length <= 0)
//        throw new std::exception();
//
//    int index1 = 0;
//    int index2 = length - 1;
//    int indexMid = index1;
//    while(numbers[index1] >= numbers[index2]) //保证这是旋转过的，因为 1，2，3，4，5这种旋转为0的也是一种特殊情况
//    {
//        // 如果index1和index2指向相邻的两个数，
//        // 则index1指向第一个递增子数组的最后一个数字，
//        // index2指向第二个子数组的第一个数字，也就是数组中的最小数字
//        if(index2 - index1 == 1)
//        {
//            indexMid = index2;
//            break;
//        }
//
//        // 如果下标为index1、index2和indexMid指向的三个数字相等，
//        // 则只能顺序查找
//        indexMid = (index1 + index2) / 2;
//        if(numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
//            return MinInOrder(numbers, index1, index2);
//
//        // 缩小查找范围
//        if(numbers[indexMid] >= numbers[index1])
//            index1 = indexMid;
//        else if(numbers[indexMid] <= numbers[index2])
//            index2 = indexMid;
//    }
//
//    return numbers[indexMid];
//}

int Min(int *numbers,int length){
    if(numbers==nullptr || length<=0)
        throw new std::exception();
    int index1=0;
    int index2=length-1;
    int mid=index1;
    while(numbers[index1]>=numbers[index2]){
        if(index2-index1==1){
            mid=index2;
            break;
        }

        mid=(index1+index2)/2;
        if(numbers[mid]==numbers[index1] &&
           numbers[mid]==numbers[index2]){
            for(int i=index1;i<index2;i++){
                if(numbers[i]<numbers[mid])
                    mid=i;
            }
            break;
        }
        else if(numbers[mid]>=numbers[index1]){
            index1=mid;
        }
        else if(numbers[mid]<=numbers[index2]){
            index2=mid;
        }
    }
    return numbers[mid];
}

int MinInOrder(int* numbers, int index1, int index2)
{
    int result = numbers[index1];
    for(int i = index1 + 1; i <= index2; ++i)
    {
        if(result > numbers[i])
            result = numbers[i];
    }

    return result;
}

// ====================测试代码====================
void Test(int* numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = Min(numbers, length);

        for(int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if(result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if(numbers == nullptr)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}

//测试模板类
//#include<string>
//template<class NameType=std::string,class AgeType=int>
//class Person{
//public:
//    Person(NameType name,AgeType age):m_Name(name),m_Age(age){}
//    NameType m_Name;
//    AgeType m_Age;
//};
//
//Person<> p("顾犇",25);

int main(int argc, char* argv[])
{
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // 输入nullptr
    Test(nullptr, 0, 0);

    return 0;
}