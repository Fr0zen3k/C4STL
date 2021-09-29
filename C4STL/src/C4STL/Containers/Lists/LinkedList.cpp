#include "LinkedList.h"

namespace C4STL
{
    template<typename __TYPE>
	LinkedList<__TYPE>::LinkedList() C4STL_NOEXCEPT : m_Head(nullptr) {}

    template<typename __TYPE>
    LinkedList<__TYPE>::~LinkedList() C4STL_NOEXCEPT {
        for(ListNode** current = &m_Head; current && *current && *(current)->next; ) {
            ListNode* temp = *current;
            *current = *(current)->next;
            delete temp;
        }
    }

    template<typename __TYPE>
    __TYPE& LinkedList<__TYPE>::Head() C4STL_NOEXCEPT {
        return m_Head->value;
    }

    template<typename __TYPE>
    __TYPE& LinkedList<__TYPE>::Tail() C4STL_NOEXCEPT {
        for(ListNode** current = &m_Head; current && *current; ) {
            if(*(current)->next) {
                current = &(*(current)->next);
            }
            else {
                return *(current)->value;
            }
        }

        // TODO: Add exception throwing when no tail
    }

    template<typename __TYPE>
    __TYPE& LinkedList<__TYPE>::Next(const __TYPE &value) C4STL_NOEXCEPT {
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
    __TYPE& LinkedList<__TYPE>::Previous(const __TYPE &value) noexcept {
        ListNode** previous = nullptr;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; current = &(*(current)->next)) {
            if(*(current)->value == value) {
                if(previous) {
                    return *(previous)->value;
                }
                else {
                    // TODO: Add exception for the head
                }
            }

            previous = current;
        }

        // TODO: Add exception for empty list or no value
    }

    template<typename __TYPE>
    void LinkedList<__TYPE>::Add(const __TYPE &value) C4STL_NOEXCEPT {
        if(m_Head) {
            for(ListNode** current = &m_Head; current && *current; current = &(*(current)->next)) {
                if(!*(current)->next) {
                    *(current)->next = new ListNode();
                    *(current)->next->value = value;
                    m_Size++;
                    return;
                }
            }
        }
        else {
            m_Head = new ListNode();
            m_Head->value = value;
            m_Size++;
        }
    }

    template<typename __TYPE>
    void LinkedList<__TYPE>::Remove(const __TYPE &value) C4STL_NOEXCEPT {
        ListNode** previous = nullptr;
        for(ListNode** current = &m_Head; current && *current && !*(current)->next; current = &(*(current)->next)) {
            if(*(current)->value == value) {
                if(previous) {
                    *(previous)->next = *(current)->next;
                    delete *current;
                    m_Size--;
                }
                else {
                    m_Head = *(current)->next;
                    delete *current;
                    m_Size--;
                }

                return;
            }

            previous = current;
        }
    }

    template<typename __TYPE>
    void LinkedList<__TYPE>::RemoveAll(const __TYPE &value) C4STL_NOEXCEPT {
        ListNode** previous = nullptr;
        for(ListNode** current = &m_Head; current && *current && !*(current)->next; current = &(*(current)->next)) {
            if(*(current)->value == value) {
                if(previous) {
                    *(previous)->next = *(current)->next;
                    delete *current;
                    m_Size--;
                }
                else {
                    m_Head = *(current)->next;
                    delete *current;
                    m_Size--;
                }

                current = previous;
            }

            previous = current;
        }
    }

    template<typename __TYPE>
    void LinkedList<__TYPE>::Insert(const __TYPE &value, size_t index) C4STL_NOEXCEPT {
        ListNode** previous = nullptr;

        size_t i = 0;

        for(ListNode** current = &m_Head; current && *current && !*(current)->next; current = &(*(current)->next)) {
            if(i == index) {
                ListNode* newNode = new ListNode();
                newNode->value = value;
                newNode->next = *current;

                if(previous) {
                    *(previous)->next = newNode;
                    m_Size++;
                }
                else {
                    m_Head = newNode;
                    m_Size++;
                }
                return;
            }

            previous = current;
            i++;
        }

        // TODO: Add list empty exception
    }
}