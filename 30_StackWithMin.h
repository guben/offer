//
// Created by 67598 on 2021/8/26.
//

#ifndef OFFER_30_STACKWITHMIN_H
#define OFFER_30_STACKWITHMIN_H

#endif //OFFER_30_STACKWITHMIN_H

#include<stack>
#include<assert.h>
using namespace std;

template<class T>
class StackWithMin
{
public:
    StackWithMin();
    virtual ~StackWithMin();

    T& top();
    void pop();
    void push(int val);
    const T& min() const;
    bool empty() const;
    size_t size() const;
private:
    stack<T> m_data;
    stack<T> m_min;
};

template<class T>
StackWithMin<T>::StackWithMin() {

}

template<class T>
StackWithMin<T>::~StackWithMin() {

}

template<class T>
T &StackWithMin<T>::top() {
    return m_data.top();
}

template<class T>
void StackWithMin<T>::pop() {
    assert(m_data.size() > 0 && m_min.size() > 0);

    m_data.pop();
    m_min.pop();

}

template<class T>
void StackWithMin<T>::push(int val) {
    m_data.push(val);
    if(m_min.empty() || val<m_min.top())
        m_min.push(val);
    else
        m_min.push(m_min.top());
}

template<class T>
const T &StackWithMin<T>::min() const{
    assert(m_data.size() > 0 && m_min.size() > 0);
    return m_min.top();
}

template<class T>
bool StackWithMin<T>::empty() const {
    return m_data.empty();
}

template<class T>
size_t StackWithMin<T>::size() const {
    return m_data.size();
}

