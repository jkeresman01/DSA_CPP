#include "AVL.h"

#include <algorithm>
#include <cstddef>

template <typename T>
void AVL<T>::Insert(const T &value)
{
    
}

template <typename T>
void AVL<T>::Remove(const T &value)
{
    
}

template <typename T>
int32_t AVL<T>::GetHeight(BSTNode<T> * node) const
{
    return node->Height;
}

template <typename T>
void AVL<T>::RotateRight(BSTNode<T> * node)
{
    BSTNode<T> * balancedNode = node->Left;

    balancedNode->Parent = node->Parent;
    node->Parent = balancedNode;

    node->Left = balancedNode->Right;

    if(balancedNode->Right != NULL)
    {
        balancedNode->Right->Parent = node;
    }

    balancedNode->Right = node;

    node->Height = std::max(
            GetHeight(node->Left), GetHeight(node->Right)) + 1;

    balancedNode->Height = std::max(
        GetHeight(balancedNode->Left), GetHeight(balancedNode->Right)) + 1;

    return balancedNode;
}

template <typename T>
void AVL<T>::RotateLeft(BSTNode<T> * node)
{
    BSTNode<T> * balancedNode = node->Right;

    balancedNode->Parent = node->Parent;

    node->Parent = balancedNode->Parent;
    node->Right = balancedNode->Left;

    if(balancedNode->Left != NULL)
    {
        balancedNode->Left->Parent = node;
    }

    balancedNode->Left = node;

    node->Height = std::max(
            GetHeight(node->Left), GetHeight(node->Right)) + 1;

    balancedNode->Height = std::max(
        GetHeight(balancedNode->Left), GetHeight(balancedNode->Right)) + 1;

    return balancedNode;
}

template <typename T>
void AVL<T>::Insert(BSTNode<T> * node, const T &key)
{
    
}

template <typename T>
void AVL<T>::Remove(BSTNode<T> * node, const T &key)
{
    
}
