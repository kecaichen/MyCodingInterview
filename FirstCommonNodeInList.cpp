#include "ListCommon.hpp"
#include <stack>

ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr || pHead2 == nullptr)
    {
        return nullptr;
    }

    ListNode *pNode1 = pHead1;
    ListNode *pNode2 = pHead2;

    std::stack<ListNode*> stack1;    
    while (pNode1)
    {
        stack1.push(pNode1);
        pNode1 = pNode1->m_pNext;
    }
    
    std::stack<ListNode*> stack2;
    while (pNode2)
    {
        stack2.push(pNode2);
        pNode2 = pNode2->m_pNext;
    }

     ListNode *pNodePop1;
     pNodePop1 = stack1.top();
     stack1.pop();
    
     ListNode *pNodePop2;
     pNodePop2 = stack2.top();
     stack2.pop();

    ListNode *pCommonNode = nullptr;
    while (pNodePop1 == pNodePop2)
    {
        pCommonNode = pNodePop1;

        pNodePop1 = stack1.top(); stack1.pop();
        pNodePop2 = stack2.top(); stack2.pop();
    }
    
    return pCommonNode;
}

ListNode *FindFirstCommonNodeEx(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr || pHead2 == nullptr)
    {
        return nullptr;
    }

    size_t nLen1 = GetListLength(pHead1);
    size_t nLen2 = GetListLength(pHead2);

    ListNode *pNodeLong = pHead1;
    ListNode *pNodeShort = pHead2;
    size_t nDiff = nLen1 - nLen2;

    if (nLen1 < nLen2)
    {
        nDiff = nLen2 - nLen1;
        pNodeLong = pHead2;
        pNodeShort = pHead1;
    }

    for (size_t i = 0; i < nDiff; i++)
    {
        if (pNodeLong)
        {
            pNodeLong = pNodeLong->m_pNext;
        }
        else
        {
            break;
        }           
    }
    
    ListNode *pCommonNode = nullptr;
    while (pNodeLong && pNodeShort)
    {
        if (pNodeLong == pNodeShort)
        {
            pCommonNode = pNodeLong;
            break;
        }
        
        pNodeLong = pNodeLong->m_pNext;
        pNodeShort = pNodeShort->m_pNext;
    }
    
    return pCommonNode;

}

void Test()
{
    ListNode *pHead1 = nullptr;

    AddToTail(&pHead1, 4);
    AddToTail(&pHead1, 3);
    AddToTail(&pHead1, 4);
    ListNode *pCommonNode = AddToTail(&pHead1, 9);
    AddToTail(&pHead1, 5);
    AddToTail(&pHead1, 6);
    AddToTail(&pHead1, 8);

    ListNode *pHead2 = nullptr;
    AddToTail(&pHead2, 23);
    AddToTail(&pHead2, 44);
    AddToTail(&pHead2, 53);
    AddToTail(&pHead2, 88);

    AppendToTail(&pHead2, pCommonNode);

    std::cout << "------------------Head1-------------------" << std::endl;
    PrintList(pHead1);

    std::cout << "------------------Head2-------------------" << std::endl;
    PrintList(pHead2);

    //ListNode *pCommonNodeResult = FindFirstCommonNode(pHead1, pHead2);
    ListNode *pCommonNodeResult = FindFirstCommonNodeEx(pHead1, pHead2);

    if (pCommonNodeResult)
    {
        std::cout << "First common node: " << pCommonNodeResult->m_nValue << std::endl;    
    }
    else
    {
        std::cout << "First common node: " << "null" << std::endl;
    }
}

int main()
{
    Test();
    return 0;
}