#include "DoubleLinkedList.h"

namespace C4STL {

    template<typename __TYPE>
    DoubleLinkedList<__TYPE>::DoubleLinkedList() C4STL_NOEXCEPT : m_Head(nullptr), m_Tail(nullptr) {}

    template<typename __TYPE>
    DoubleLinkedList<__TYPE>::~DoubleLinkedList() C4STL_NOEXCEPT {
        for(ListNode** current = &m_Head; current && *current && *(current)->next; ) {
            ListNode* temp = *current;
            *current = *(current)->next;
            delete temp;
        }
    }

    template<typename __TYPE>
    __TYPE& DoubleLinkedList<__TYPE>::Head() C4STL_NOEXCEPT {
        return m_Head->value;
    }

    template<typename __TYPE>
    __TYPE& DoubleLinkedList<__TYPE>::Tail() noexcept {
        return m_Tail->value;
    }

    template<typename __TYPE>
    __TYPE& DoubleLinkedList<__TYPE>::Next(const __TYPE &value) C4STL_NOEXCEPT {
        for(ListNode** current = &m_Head; current && *current; current = &(*(current)->next)) {
            if(*(current)->value == value) {
                if(*(current)->next) {
                    return *(current)->next->value;
                }
                else {
                    // TODO: Add exception for the tail
                }
            }
        }

        // TODO: Add exception for non-existent value
    }

    template<typename __TYPE>
    __TYPE& DoubleLinkedList<__TYPE>::Previous(const __TYPE &value) noexcept {
        for(ListNode** current = &m_Head; current && *current && *(current)->next; current = &(*(current)->next)) {
            if(*(current)->value == value) {
                if(*(current)->previous) {
                    return *(current)->previous->value;
                }
                else {
                    // TODO: Add exception for the head
                }
            }
        }

        // TODO: Add exception for empty list or no value
    }

    template<typename __TYPE>
    void DoubleLinkedList<__TYPE>::Add(const __TYPE &value) C4STL_NOEXCEPT {
        ListNode* node = new ListNode();
        node->value = value;
        node->previous = m_Tail;

        if(m_Tail) {
            m_Tail->next = node;
        }
        else {
            m_Head = node;
        }

        m_Tail = node;

        m_Size++;
    }

    template<typename __TYPE>
    void DoubleLinkedList<__TYPE>::Remove(const __TYPE &value) C4STL_NOEXCEPT {
        for(ListNode** current = &m_Head; current && *current && !*(current)->next; current = &(*(current)->next)) {
            if(*(current)->value == value) {
                if(m_Head == m_Tail) {
                    delete m_Head;
                    m_Head = nullptr;
                    m_Tail = nullptr;
                }

                if(!*(current)->next) {
                    m_Tail = *(current)->previous;
                }

                if(*(current)->previous) {
                    *(current)->previous->next = *(current)->next;
                    *(current)->next->previous = *(current)->previous;
                    delete *current;
                    m_Size--;
                }
                else {
                    m_Head = *(current)->next;
                    *(current)->next->previous = m_Head;
                    delete *current;
                    m_Size--;
                }

                return;
            }
        }
    }

    template<typename __TYPE>
    void DoubleLinkedList<__TYPE>::RemoveAll(const __TYPE &value) C4STL_NOEXCEPT {
        for(ListNode** current = &m_Head; current && *current && !*(current)->next; current = &(*(current)->next)) {
            if(*(current)->value == value) {
                ListNode** temp = &(*(current)->previous);

                if(m_Head == m_Tail) {
                    delete m_Head;
                    m_Head = nullptr;
                    m_Tail = nullptr;
                }

                if(!*(current)->next) {
                    m_Tail = *(current)->previous;
                }

                if(*(current)->previous) {
                    *(current)->previous->next = *(current)->next;
                    *(current)->next->previous = *(current)->previous;
                    delete *current;
                    m_Size--;
                }
                else {
                    m_Head = *(current)->next;
                    *(current)->next->previous = m_Head;
                    delete *current;
                    m_Size--;
                }

                current = temp;
            }
        }
    }

    template<typename __TYPE>
    void DoubleLinkedList<__TYPE>::Insert(const __TYPE &value, size_t index) C4STL_NOEXCEPT {
        if(index >= m_Size) {
            // Throw exception
        }

        if(index == 0) {
            ListNode* node = new ListNode();
            node->value = value;
            node->next = m_Head->next;
            m_Head = node;

            if(m_Head == m_Tail) {
                m_Tail = node;
            }

            return;
        }

        if(index == m_Size - 1) {
            ListNode* node = new ListNode();
            node->value = value;
            node->previous = m_Tail->previous;
            m_Tail = node;

            if(m_Head == m_Tail) {
                m_Head = node;
            }

            return;
        }

        size_t i = 0;

        for(ListNode** current = &m_Head; current && *current && !*(current)->next; current = &(*(current)->next)) {
            if(i == index) {
                ListNode* newNode = new ListNode();
                newNode->value = value;
                newNode->next = *current;
                newNode->previous = *(current)->previous;

                *(current)->previous->next = newNode;
                *(current)->previous = newNode;
            }

            i++;
        }

        // TODO: Add list empty exception
    }
}