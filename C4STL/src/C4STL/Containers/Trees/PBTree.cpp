//
// Created by jankr on 10-Oct-21.
//

#include "PBTree.h"
#include "../Queue.h"
#include "../Stack.h"

#include <cmath>

namespace C4STL {

    template<typename __TYPE>
    PBTree<__TYPE>::PBTree() C4STL_NOEXCEPT = default;

    template<typename __TYPE>
    PBTree<__TYPE>::~PBTree() C4STL_NOEXCEPT {
        TreeToBackbone();
        BackboneDelete();
    }

    template<typename __TYPE>
    void PBTree<__TYPE>::Insert(const __TYPE &val)  C4STL_NOEXCEPT {
        InsertDSW(val);
        m_Size++;
    }

    template<typename __TYPE>
    void PBTree<__TYPE>::RemoveHead() C4STL_NOEXCEPT {
        RemoveByValue(m_Head->value);
    }

    template<typename __TYPE>
    __TYPE &PBTree<__TYPE>::GetByValue(const __TYPE &val) {
        return FindNode(val)->value;
    }

    template<typename __TYPE>
    bool PBTree<__TYPE>::RemoveByValue(const __TYPE &val) {
        TreeToBackbone();

        if(m_Head->value == val) {
            TreeNode* temp = m_Head;
            m_Head = m_Head->rightChild;
            m_Head->parent = nullptr;
            delete temp;
            return true;
        }

        for(TreeNode* node = m_Head; node; node = node->rightChild) {
            if(node->value == val) {
                node->rightChild->parent = node->parent;
                node->parent->rightChild = node->rightChild;
                delete node;
                return true;
            }
        }

        BackboneToTree();

        return false;
    }

    template<typename __TYPE>
    DynamicArray<__TYPE> PBTree<__TYPE>::GetPath(const __TYPE &val) {
        DynamicArray<__TYPE> array;
        TreeNode* node = FindNode(val);

        Stack<__TYPE> stack;

        for(; node; node = node->parent) {
            stack.Push(node->value);
        }

        while(!stack.Empty()) {
            array.PushBack(stack.Pop());
        }

        return array;
    }

    template<typename __TYPE>
    DynamicArray<__TYPE> PBTree<__TYPE>::GetSortedData() C4STL_NOEXCEPT {
        DynamicArray<__TYPE> array(m_Size);

        TreeToBackbone();

        for(TreeNode* current = m_Head; current; current = current->rightChild) {
            array.PushBack(current->value);
        }

        BackboneToTree();

        return array;
    }

    template<typename __TYPE>
    void PBTree<__TYPE>::RotateRight(TreeNode *node) C4STL_NOEXCEPT {
        if(node != node->parent->leftChild) {
            return;
        }

        TreeNode* newParent = node->parent->parent;
        TreeNode* newLeft = node->rightChild;
        TreeNode* newRight = node->parent;

        node->parent = newParent;
        node->rightChild = newRight;
        node->rightChild->leftChild = newLeft;

        newParent->rightChild = node;
        newRight->parent = node;

        if(!node->parent) {
            m_Head = node;
        }
    }

    template<typename __TYPE>
    void PBTree<__TYPE>::RotateLeft(TreeNode *node) C4STL_NOEXCEPT {
        if(node != node->parent->rightChild) {
            return;
        }

        TreeNode* newParent = node->parent->parent;
        TreeNode* newLeft = node->parent;
        TreeNode* newRight = node->leftChild;

        node->parent = newParent;
        newRight->leftChild = newLeft;
        node->leftChild->rightChild = newRight;

        newParent->leftChild = node;
        newLeft->parent = node;

        if(!node->parent) {
            m_Head = node;
        }
    }

    template<typename __TYPE>
    void PBTree<__TYPE>::TreeToBackbone() C4STL_NOEXCEPT {
        for(TreeNode* current; current; ) {
            if(current->leftChild) {
                current = current->leftChild;
                RotateRight(current);
            }
            else {
                current = current->rightChild;
            }
        }
    }

    template<typename __TYPE>
    void PBTree<__TYPE>::BackboneToTree() C4STL_NOEXCEPT {
        int h = static_cast<int>(log2(m_Size + 1));
        int k = static_cast<int>(pow(2, h)) - 1;

        while(k > 1) {
            k /= 2;

            TreeNode* current = m_Head->rightChild;
            for(size_t i = 0; i < k; i++) {
                RotateLeft(current);
                current = current->rightChild->rightChild;
            }
        }
    }

    template<typename __TYPE>
    void PBTree<__TYPE>::InsertToBackbone(const __TYPE &val) C4STL_NOEXCEPT {
        if(val < m_Head->value) {
            TreeNode* newNode = new TreeNode(val);
            newNode->rightChild = m_Head;
            m_Head = newNode;
            return;
        }

        for(TreeNode* node = m_Head; node; node = node->rightChild) {
            if((node->value < val && node->rightChild->value >= val) || (!node->rightChild)) {
                TreeNode newNode = new TreeNode(val);
                newNode.parent = node;
                newNode.rightChild = node->rightChild;
                node->rightChild = newNode;
                return;
            }
        }
    }

    template<typename __TYPE>
    void PBTree<__TYPE>::InsertDSW(const __TYPE &val) C4STL_NOEXCEPT {
        TreeToBackbone();
        InsertToBackbone(val);
        BackboneToTree();
    }

    template<typename __TYPE>
    void PBTree<__TYPE>::BackboneDelete() C4STL_NOEXCEPT {
        for(TreeNode* node = m_Head; node; ) {
            TreeNode* temp = node;
            node = node->rightChild;
            delete temp;
        }
    }

    template<typename __TYPE>
    typename PBTree<__TYPE>::TreeNode* PBTree<__TYPE>::FindNode(const __TYPE &val) noexcept {
        Queue<TreeNode*> nodes;
        nodes.Push(m_Head);

        while(!nodes.Empty()) {
            TreeNode* node = nodes.Pop();

            if(node->value == val) {
                return node;
            }
            else {
                if(node->leftChild) {
                    nodes.Push(node->leftChild);
                }
                if(node->rightChild) {
                    nodes.Push(node->rightChild);
                }
            }
        }

        return nullptr;
    }
}
