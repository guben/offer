//
// Created by 67598 on 2021/8/29.
//
// 面试题41：数据流中的中位数
// 题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么
// 中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
// 那么中位数就是所有数值排序之后中间两个数的平均值。

//学习两个东西：
//1. 数组构造的堆！（完全二叉树）
//2. make_heap push_heap pop_heap 算法库的操作！

#include<cstdio>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

template<typename T> class DynamicArray{
public:
    void Insert(T num){
        if(maxHeap.size()==minHeap.size()){//相等，插入最小堆
            if(maxHeap.size()>0 && maxHeap[0]>num){//但是，num小于maxHeap堆顶
                //最大堆顶元素取出，加到最小堆，然后num加入最大堆
                maxHeap.push_back(num);
                push_heap(maxHeap.begin(),maxHeap.end(),less<int>());

                num=maxHeap[0];

                pop_heap(maxHeap.begin(),maxHeap.end(),less<int>());
                maxHeap.pop_back();
            }
            minHeap.push_back(num);
            push_heap(minHeap.begin(),minHeap.end(),greater<int>());
        }else{//不相等，那么一定是最小堆大一点，插入最大堆
            if(minHeap.size()>0 && minHeap[0]<num){//但是最小堆的堆顶小于num
                minHeap.push_back(num);
                push_heap(minHeap.begin(),minHeap.end(),greater<int>());

                num=minHeap[0];
                pop_heap(minHeap.begin(),minHeap.end(),greater<int>());
                minHeap.pop_back();
            }
            maxHeap.push_back(num);
            push_heap(maxHeap.begin(),maxHeap.end(),less<int>());
        }
    }
    T GetMedian(){
        if(minHeap.size()==0)
            throw exception();

        if(maxHeap.size()==minHeap.size())
            return (maxHeap[0]+minHeap[0])/2;
        else
            return minHeap[0];
    }
private:
    vector<T> maxHeap;
    vector<T> minHeap;
};
// ====================测试代码====================
void Test(char* testName, DynamicArray<double>& numbers, double expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if((numbers.GetMedian() - expected) < 0.0000001 || (numbers.GetMedian() - expected)>-0.0000001)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    DynamicArray<double> numbers;

    printf("Test1 begins: ");
    try
    {
        numbers.GetMedian();
        printf("FAILED.\n");
    }
    catch(const exception&)
    {
        printf("Passed.\n");
    }

    numbers.Insert(5);
    Test("Test2", numbers, 5);

    numbers.Insert(2);
    Test("Test3", numbers, 3.5);

    numbers.Insert(3);
    Test("Test4", numbers, 3);

    numbers.Insert(4);
    Test("Test6", numbers, 3.5);

    numbers.Insert(1);
    Test("Test5", numbers, 3);

    numbers.Insert(6);
    Test("Test7", numbers, 3.5);

    numbers.Insert(7);
    Test("Test8", numbers, 4);

    numbers.Insert(0);
    Test("Test9", numbers, 3.5);

    numbers.Insert(8);
    Test("Test10", numbers, 4);

    return 0;
}