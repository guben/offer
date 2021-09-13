//
// Created by 67598 on 2021/9/10.
//

//
// Created by 67598 on 2021/9/10.
//

// 面试题52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。

#include <cstdio>
#include "Utilities\List.h"

unsigned int GetListLength(ListNode* pHead);

ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
    if(pHead2== nullptr || pHead1== nullptr)
        return nullptr;
    unsigned int length1=GetListLength(pHead1);
    unsigned int length2=GetListLength(pHead2);
    if(length1<length2){
        ListNode* temp=pHead2;
        pHead2=pHead1;
        pHead1=temp;
        unsigned int templ=length2;
        length2=length1;
        length1=templ;
    }
    unsigned int dif=length1-length2;
    ListNode* p1=pHead1;
    ListNode* p2=pHead2;
    while(dif!=0){
        dif--;
        p1=p1->m_pNext;
    }
    while(p1!=p2){
        p1=p1->m_pNext;
        p2=p2->m_pNext;
    }
    return p1;

}

unsigned int GetListLength(ListNode* pHead)
{
    unsigned int nLength = 0;
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        ++nLength;
        pNode = pNode->m_pNext;
    }

    return nLength;
}


// ====================测试代码====================
void DestroyNode(ListNode* pNode);

void Test(char* testName, ListNode* pHead1, ListNode* pHead2, ListNode* pExpected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ListNode* pResult = FindFirstCommonNode(pHead1, pHead2);
    if(pResult == pExpected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 第一个公共结点在链表中间
// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode6);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test("Test1", pNode1, pNode4, pNode6);

    DestroyNode(pNode1);
    DestroyNode(pNode2);
    DestroyNode(pNode3);
    DestroyNode(pNode4);
    DestroyNode(pNode5);
    DestroyNode(pNode6);
    DestroyNode(pNode7);
}

// 没有公共结点
// 1 - 2 - 3 - 4
//
// 5 - 6 - 7
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test("Test2", pNode1, pNode5, nullptr);

    DestroyList(pNode1);
    DestroyList(pNode5);
}

// 公共结点是最后一个结点
// 1 - 2 - 3 - 4 \
//                7
//         5 - 6 /
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode7);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test("Test3", pNode1, pNode5, pNode7);

    DestroyNode(pNode1);
    DestroyNode(pNode2);
    DestroyNode(pNode3);
    DestroyNode(pNode4);
    DestroyNode(pNode5);
    DestroyNode(pNode6);
    DestroyNode(pNode7);
}

// 公共结点是第一个结点
// 1 - 2 - 3 - 4 - 5
// 两个链表完全重合
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test4", pNode1, pNode1, pNode1);

    DestroyList(pNode1);
}

// 输入的两个链表有一个空链表
void Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test5", nullptr, pNode1, nullptr);

    DestroyList(pNode1);
}

// 输入的两个链表有一个空链表
void Test6()
{
    Test("Test6", nullptr, nullptr, nullptr);
}

void DestroyNode(ListNode* pNode)
{
    delete pNode;
    pNode = nullptr;
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
