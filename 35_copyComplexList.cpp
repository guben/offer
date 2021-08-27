//
// Created by 67598 on 2021/8/27.
//
#include <cstdio>
#include <iostream>
using namespace std;

struct ComplexListNode
{    explicit ComplexListNode(){
        m_nValue=0;
        m_pNext=nullptr;
        m_pSibling=nullptr;
    }
    explicit ComplexListNode(int v){
        m_nValue=v;
        m_pNext=nullptr;
        m_pSibling=nullptr;
    }
    int                 m_nValue;
    ComplexListNode*    m_pNext;
    ComplexListNode*    m_pSibling;
};

//工具函数
ComplexListNode* CreateNode(int nValue);
void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling);
void PrintList(ComplexListNode* pHead);

//实际函数
void CloneNodes(ComplexListNode* pHead);
void ConnectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);
ComplexListNode* Clone(ComplexListNode* pHead) //入口
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}



void CloneNodes(ComplexListNode* pHead){
    if(pHead==nullptr)
        return;
    ComplexListNode* p=pHead;
    while(p!=nullptr){
        ComplexListNode* pClone=new ComplexListNode(p->m_nValue);
        pClone->m_pNext=p->m_pNext;
        p->m_pNext=pClone;
        p=pClone->m_pNext;
    }
}

void ConnectSiblingNodes(ComplexListNode* pHead){
    if (pHead==nullptr)
        return;
    ComplexListNode* p=pHead;
    while(p!=nullptr){
        ComplexListNode* pClone=p->m_pNext;
        if(p->m_pSibling!=nullptr)
            pClone->m_pSibling=p->m_pSibling->m_pNext;
        p=pClone->m_pNext;
    }
}
ComplexListNode* ReconnectNodes(ComplexListNode* pHead){
    ComplexListNode* p=pHead;
    if(pHead==nullptr)
        return nullptr;
    ComplexListNode* pRet=p->m_pNext;
    while(p!=nullptr){
        ComplexListNode* pClone=p->m_pNext;
        p->m_pNext=pClone->m_pNext;
        if(p->m_pNext!=nullptr)
            pClone->m_pNext=p->m_pNext->m_pNext;
        p=p->m_pNext;
    }
    return pRet;
}


ComplexListNode* CreateNode(int nValue)
{
    ComplexListNode* pNode = new ComplexListNode();

    pNode->m_nValue = nValue;
    pNode->m_pNext = nullptr;
    pNode->m_pSibling = nullptr;

    return pNode;
}

void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    if(pNode != nullptr)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}

void PrintList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("The value of this node is: %d.\n", pNode->m_nValue);

        if(pNode->m_pSibling != nullptr)
            printf("The value of its sibling is: %d.\n", pNode->m_pSibling->m_nValue);
        else
            printf("This node does not have a sibling.\n");

        printf("\n");

        pNode = pNode->m_pNext;
    }
}

// ====================测试代码====================
void Test(const char* testName, ComplexListNode* pHead)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode* pClonedHead = Clone(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, pNode3);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// 只有一个结点
void Test4()
{
    ComplexListNode* pNode1 = CreateNode(1);
    BuildNodes(pNode1, nullptr, pNode1);

    Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5()
{
    Test("Test5", nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
