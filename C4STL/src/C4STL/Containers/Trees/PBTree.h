//
// Created by jankr on 10-Oct-21.
//

#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_PBTREE_H
#define C4STL_PBTREE_H

#include "C4STL/Core/Core.h"
#include "C4STL/Containers/Arrays/DynamicArray.h"

namespace C4STL {

    template<typename __TYPE>
    class C4STL_PUBLIC_API PBTree {
    public:
        PBTree() C4STL_NOEXCEPT;
        virtual ~PBTree() C4STL_NOEXCEPT;

        void Insert(const __TYPE& val) C4STL_NOEXCEPT;

        inline size_t Size() C4STL_NOEXCEPT { return m_Size; }

        inline __TYPE& GetHead() { return m_Head->value; }
        void RemoveHead() C4STL_NOEXCEPT;

        __TYPE& GetByValue(const __TYPE& val);
        bool RemoveByValue(const __TYPE& val);

        DynamicArray<__TYPE> GetPath(const __TYPE& val);
        DynamicArray<__TYPE> GetSortedData() C4STL_NOEXCEPT;

    private:
        struct TreeNode {
            explicit TreeNode(__TYPE val) C4STL_NOEXCEPT : value(val) {}

            __TYPE value;
            TreeNode* parent = nullptr;
            TreeNode* leftChild = nullptr;
            TreeNode* rightChild = nullptr;
        };

        void RotateRight(TreeNode* node) C4STL_NOEXCEPT;
        void RotateLeft(TreeNode* node) C4STL_NOEXCEPT;
        void TreeToBackbone() C4STL_NOEXCEPT;
        void BackboneToTree() C4STL_NOEXCEPT;
        void InsertToBackbone(const __TYPE& val) C4STL_NOEXCEPT;
        void InsertDSW(const __TYPE& val) C4STL_NOEXCEPT;
        void BackboneDelete() C4STL_NOEXCEPT;
        TreeNode* FindNode(const __TYPE& val) C4STL_NOEXCEPT;

    private:
        TreeNode* m_Head = nullptr;
        size_t m_Size = 0;
    };

}

#endif //C4STL_PBTREE_H


#if defined (_MSC_VER)
#pragma warning(pop)
#endif