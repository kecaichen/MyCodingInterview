#include "ListCommon.hpp"

void DeleteNode(ListNode **pHead, ListNode *pToBeDeleted)
{
    if (pHead == nullptr || pToBeDeleted == nullptr)
    {
        return;
    }
    
    if (pToBeDeleted->m_pNext != nullptr)//次节点不是尾巴节点
    {
        pToBeDeleted->m_nValue = pToBeDeleted->m_pNext->m_nValue;
        ListNode *pDeleted = pToBeDeleted->m_pNext;
        pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;

        delete pDeleted;
        pDeleted = nullptr;
    }
    else if (pToBeDeleted == *pHead)//考虑链表只有当前一个节点
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;

        *pHead = nullptr;
    }
    else//链表有多个节点，且当前节点是尾节点，需要从头遍历删除尾结点
    {
        ListNode *pNode = *pHead;
        while (pNode->m_pNext != pToBeDeleted)
        {
            pNode = pNode->m_pNext;
        }
        
        pNode->m_pNext = nullptr;

        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }     
}

void Test1()
{
    ListNode *pHead = nullptr;

    AddToTail(&pHead, 4);
    AddToTail(&pHead, 3);
    AddToTail(&pHead, 4);
    ListNode *pToBeDeleted = AddToTail(&pHead, 9);
    AddToTail(&pHead, 5);
    AddToTail(&pHead, 6);
    AddToTail(&pHead, 8);

    PrintList(pHead);

    DeleteNode(&pHead, pToBeDeleted);

    PrintList(pHead);
}

int main()
{
    Test1();
    return 0;
}