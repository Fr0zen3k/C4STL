#include "OrderedList.h"

namespace C4STL {

    template<typename __TYPE>
    OrderedList<__TYPE>::OrderedList() C4STL_NOEXCEPT : DoubleLinkedList<__TYPE>() {}

    template<typename __TYPE>
    OrderedList<__TYPE>::~OrderedList() C4STL_NOEXCEPT {
        for(ListNode** current = &m_Head; current && *current && *(current)->next; ) {
            ListNode* temp = *current;
            *current = *(current)->next;
            delete temp;
        }
    }

    template<typename __TYPE>
    void OrderedList<__TYPE>::Add(const __TYPE &value) C4STL_NOEXCEPT {
        if(!m_Head) {
            DoubleLinkedList<__TYPE>::ListNode* node = new DoubleLinkedList<__TYPE>::ListNode();
            node->value = value;
            m_Head = node;
            m_Tail= node;
        }

        for(DoubleLinkedList<__TYPE>::ListNode** current = &m_Head; current && *current && *(current)->next; ) {
            if(*(current)->value >= value) {
                DoubleLinkedList<__TYPE>::ListNode* node = new DoubleLinkedList<__TYPE>::ListNode();
                node->value = value;
                node->next = *current;

                if(*(current)->previous) {
                    node->previous = *(current)->previous;
                    *(current)->previous->next = node;
                    *(current)->previous = node;
                }
                else {
                    m_Head = node;
                }

                return;
            }
        }
    }

    template<typename __TYPE>
    void OrderedList<__TYPE>::Insert(const __TYPE &value, size_t index) C4STL_NOEXCEPT {
        Add(value);
    }
}