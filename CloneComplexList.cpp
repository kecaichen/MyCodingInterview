#include "ListCommon.hpp"

ComplexListNode *Clone(ComplexListNode *pHead)
{
    if (!pHead)
    {
        return nullptr;
    }
    
    return nullptr;
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
    PrintComplexList(pHead);

    // ComplexListNode *pClone = Clone(pHead);

    // PrintComplexList(pClone);
}

int main()
{
    Test();
    return 0;
}