#include "ListCommon.hpp"

ComplexListNode *Clone(ComplexListNode *pHead)
{
    if (!pHead)
    {
        return nullptr;
    }

    //扩展原链表
    ComplexListNode *pNode = pHead;
    while (pNode)
    {
        ComplexListNode *pNew = new ComplexListNode;
        pNew->m_nValue = pNode->m_nValue;
        pNew->m_pNext = pNode->m_pNext;
        pNew->m_pSibling = nullptr;

        pNode->m_pNext = pNew;

        pNode = pNew->m_pNext;
    }

    //Add sibling point
    pNode = pHead;
    while (pNode)
    {
        if (pNode->m_pSibling)
        {
            pNode->m_pNext->m_pSibling = pNode->m_pSibling->m_pNext;
        }
        
        pNode = pNode->m_pNext->m_pNext;
    }

    //Cutout list to origin and clone list
    ComplexListNode *pClone = pHead->m_pNext;

    pNode = pHead;
    while (pNode)
    {
        ComplexListNode *pNew = pNode->m_pNext;
        pNode->m_pNext = pNew->m_pNext;

        pNode = pNode->m_pNext;
        pNew->m_pNext = pNode ? pNode->m_pNext : nullptr;
    }
    
    
    return pClone;
}

void Test()
{
    ComplexListNode *pHead = nullptr;

    ComplexListNode *pComplex1 = AddToTail(&pHead, 4);
    ComplexListNode *pComplex2 = AddToTail(&pHead, 3);
    ComplexListNode *pComplex3 = AddToTail(&pHead, 4);
    ComplexListNode *pComplex4 = AddToTail(&pHead, 5);
    ComplexListNode *pComplex5 = AddToTail(&pHead, 6);
    ComplexListNode *pComplex6 = AddToTail(&pHead, 8);

    AddSibling(pComplex1, pComplex4);
    AddSibling(pComplex2, pComplex5);
    AddSibling(pComplex6, pComplex3);

    std::cout << "------------------Before clone------------------" << std::endl; 
    PrintComplexList(pHead);

    ComplexListNode *pClone = Clone(pHead);
    std::cout << "------------------Clone------------------" << std::endl; 
    PrintComplexList(pHead);

    std::cout << "------------------After clone------------------" << std::endl; 
    PrintComplexList(pClone);
}

int main()
{
    Test();
    return 0;
}