//
// Created by 67598 on 2021/8/12.
//
#include<iostream>
#include<algorithm>
#include<exception>
using namespace std;

//先写一个partition函数，二分！
int partition(int data[],int length, int start, int end){
    if(data==nullptr || start<0 || start>end){
        throw new exception();
    }
    int index=start;
    swap(data[index],data[end]);

    int small=start-1;
    for(index=start;index<end;++index){
        if(data[index]<data[end]){
            ++small;
            if(index!=small){
                swap(data[index],data[small]);
            }
        }
    }
    ++small;
    swap(data[small],data[end]);
    return small;
}

//在写一个快速排序函数
void QuickSort(int data[],int length,int start,int end){
    if(start==end)
        return;
    int index=partition(data,length,start,end);
    if(start<index)
        QuickSort(data,length,start,index-1);
    if(index<end)
        QuickSort(data,length,index+1,end);
}

int myPartition(int data[],int left,int right){
    if(left>right)
        throw new exception();
    int temp = data[left];
    int i,j;
    for(i=left,j=right; i<j;){
        while(data[j]>=temp)j--;
        if(i<j ){
            swap(data[j],data[i]);
            ++i;
        }
        while(data[i]<temp)i++;
        if(i<j ){
            swap(data[j],data[i]);
            --j;
        }
    }
    data[i]=temp;
    return i;
}
void myQuickSort(int data[],int start,int end){
    if(start>end)
        throw new exception();
    int index=myPartition(data,start,end);
    if(index>start)
        myQuickSort(data,start,index-1);
    if(index<end)
        myQuickSort(data,index+1,end);
}





int main(){
//    int data[]={3,4,1,3,3,3,3,5,2,10,9,8,6,0,7};
//    QuickSort(data,sizeof(data)/sizeof(data[0]),0,10);
//    for(auto &x:data)
//        cout<<x<<" ";
//    cout<<endl;
//    myQuickSort(data,0,sizeof(data)/sizeof(data[0])-1);
//    for(auto &x:data)
//        cout<<x<<" ";
//    cout<<endl;


}


