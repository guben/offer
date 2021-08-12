//
// Created by 67598 on 2021/8/11.
//

#include<iostream>
#include<stack>
#include<queue>
#include<exception>
using namespace std;
// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

//带有模板的 队列类(使用两个栈实现)
template <typename T> class CQueue{
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();
private:
    stack<T>s1;
    stack<T>s2;
};

//带有模板的 栈类（使用两个队列实现）
template<class T>
class CStack{
public:
    CStack()= default;
    ~CStack()= default;

    void pushTop(const T& node);
    T popTop();

private:
    queue<T>q1;
    queue<T>q2;
};

template<class T>
void CStack<T>::pushTop(const T &node) {
    if(q2.empty()){
        q1.push(node);
    }
    else if(q1.empty()){
        q2.push(node);
    }
}

template<class T>
T CStack<T>::popTop() {
    if(q1.empty()&&q2.empty()){
        throw new exception();
    }
    else if(q2.empty()){
        while(q1.size()!=1){
            T temp=q1.front();
            q1.pop();
            q2.push(temp);
        }
        T ret=q1.front();
        q1.pop();
        return ret;
    }else if(q1.empty()){
        while(q2.size()!=1){
            T temp=q2.front();
            q2.pop();
            q1.push(temp);
        }
        T ret=q2.front();
        q2.pop();
        return ret;
    }
}

template<typename T>
CQueue<T>::CQueue(void) {

}

template<typename T>
CQueue<T>::~CQueue(void) {

}

template<typename T>
void CQueue<T>::appendTail(const T &node) {
    s1.push(node);
}

template<typename T>
T CQueue<T>::deleteHead() {
    if(s2.empty()){
        while(!s1.empty()){
            T& data=s1.top();
            s1.pop();
            s2.push(data);
        }
    }
    if(s2.empty()){
        throw new exception();
    }
    T ret=s2.top();
    s2.pop();
    return ret;
}


// ====================测试代码====================
void Test(char actual, char expected)
{
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
//    CQueue<char> queue;
//
//    queue.appendTail('a');
//    queue.appendTail('b');
//    queue.appendTail('c');
//
//    char head = queue.deleteHead();
//    Test(head, 'a');
//
//    head = queue.deleteHead();
//    Test(head, 'b');
//
//    queue.appendTail('d');
//    head = queue.deleteHead();
//    Test(head, 'c');
//
//    queue.appendTail('e');
//    head = queue.deleteHead();
//    Test(head, 'd');
//
//    head = queue.deleteHead();
//    Test(head, 'e');

    CStack<char> stack;

    stack.pushTop('a');
    stack.pushTop('b');
    stack.pushTop('c');

    char head = stack.popTop();
    Test(head, 'c');
    cout<<head<<endl;

    head = stack.popTop();
    Test(head, 'b');
    cout<<head<<endl;

    stack.pushTop('d');
    head = stack.popTop();
    Test(head, 'd');
    cout<<head<<endl;

    stack.pushTop('e');
    head = stack.popTop();
    Test(head, 'e');
    cout<<head<<endl;

    head =  stack.popTop();
    Test(head, 'a');
    cout<<head<<endl;

    return 0;
}


