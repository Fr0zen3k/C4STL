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
    typename LinkedList<__TYPE>::Iterator LinkedList<__TYPE>::begin() {
        return Iterator(m_Head);
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator LinkedList<__TYPE>::end() {
        return Iterator();
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

    // *********************************** Iterator ***********************************

    template<typename __TYPE>
    LinkedList<__TYPE>::Iterator::Iterator(__TYPE *ptr) C4STL_NOEXCEPT : C4STL::Iterator<__TYPE>(), m_Ptr(ptr) {}

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::advance(const C4STL::Iterator<__TYPE> &iterator) {
        return operator+(iterator);
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::advance(const size_t &position) {
        return operator+(position);
    }

    template<typename __TYPE>
    int32_t LinkedList<__TYPE>::Iterator::distance(const C4STL::Iterator<__TYPE> &iterator) {
        int32_t i = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; i++) {
            if(*(current)->value == *iterator) {
                break;
            }
        }

        int32_t j = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; i++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        return i - j;
    }

    template<typename __TYPE>
    int32_t LinkedList<__TYPE>::Iterator::distance(const size_t &position) {
        int32_t j = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; j++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        return static_cast<int32_t>(position) - j;
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::previous(const C4STL::Iterator<__TYPE> &iterator) {
        __TYPE& val = *iterator;

        __TYPE& target = Previous(val);

        for(ListNode** current = m_Head; current && *current; current = &(*(current)->next)) {
            if(*(current)->value == target) {
                m_Ptr = *current;
            }
        }

        return *this;
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::previous(const size_t &position) {
        ListNode** current = m_Head;

        for(size_t i = 0; i <= position - 1 && current && *current; i++) {
            current = &(*(current)->next);
        }

        m_Ptr = *current;
        return *this;
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::next(const C4STL::Iterator<__TYPE> &iterator) {
        __TYPE& val = *iterator;

        __TYPE& target = Next(val);

        for(ListNode** current = m_Head; current && *current; current = &(*(current)->next)) {
            if(*(current)->value == target) {
                m_Ptr = *current;
            }
        }

        return *this;
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::next(const size_t &position) {
        ListNode** current = m_Head;

        for(size_t i = 0; i <= position + 1 && current && *current; i++) {
            current = &(*(current)->next);
        }

        m_Ptr = *current;
        return *this;
    }

    template<typename __TYPE>
    __TYPE &LinkedList<__TYPE>::Iterator::operator*() {
        return m_Ptr->value;
    }

    template<typename __TYPE>
    __TYPE *LinkedList<__TYPE>::Iterator::operator->() {
        return &m_Ptr->value;
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::operator++() {
        m_Ptr = m_Ptr->next;
        return *this;
    }

    template<typename __TYPE>
    const typename LinkedList<__TYPE>::Iterator LinkedList<__TYPE>::Iterator::operator++(int) {
        LinkedList<__TYPE>::Iterator ret(m_Ptr);
        m_Ptr = m_Ptr->next;
        return ret;
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::operator--() {
        return previous(*this);
    }

    template<typename __TYPE>
    const typename LinkedList<__TYPE>::Iterator LinkedList<__TYPE>::Iterator::operator--(int) {
        LinkedList<__TYPE>::Iterator ret(m_Ptr);
        previous(*this);
        return ret;
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::operator+(const C4STL::Iterator<__TYPE> &iterator) {
        size_t i = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; i++) {
            if(*(current)->value == *iterator) {
                break;
            }
        }

        for(size_t j = 0; j <= i; j++) {
            m_Ptr = m_Ptr->next;
        }

        return *this;
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::operator-(const C4STL::Iterator<__TYPE> &iterator) {
        size_t i = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; i++) {
            if(*(current)->value == *iterator) {
                break;
            }
        }

        size_t j = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; j++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        m_Ptr = m_Head;
        for(size_t k = 0; k < j - i - 1; k++) {
            m_Ptr = m_Ptr->next;
        }

        return *this;
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::operator+(const size_t &position) {
        for(size_t j = 0; j <= position; j++) {
            m_Ptr = m_Ptr->next;
        }

        return *this;
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::operator-(const size_t &position) {
        size_t i = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; i++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        m_Ptr = m_Head;
        for(size_t j = 0; j < i - position - 1; j++) {
            m_Ptr = m_Ptr->next;
        }

        return *this;
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::operator+=(const C4STL::Iterator<__TYPE> &iterator) {
        return operator+(iterator);
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::operator+=(const size_t &position) {
        return operator+(position);
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::operator-=(const C4STL::Iterator<__TYPE> &iterator) {
        return operator-(iterator);
    }

    template<typename __TYPE>
    typename LinkedList<__TYPE>::Iterator &LinkedList<__TYPE>::Iterator::operator-=(const size_t &position) {
        return operator-(position);
    }

    template<typename __TYPE>
    bool LinkedList<__TYPE>::Iterator::operator<(const C4STL::Iterator<__TYPE> &iterator) {
        size_t i = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; i++) {
            if(*(current)->value == *iterator) {
                break;
            }
        }

        size_t j = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; j++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        return j < i;
    }

    template<typename __TYPE>
    bool LinkedList<__TYPE>::Iterator::operator<(const size_t &position) {
        size_t j = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; j++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        return j < position;
    }

    template<typename __TYPE>
    bool LinkedList<__TYPE>::Iterator::operator>(const C4STL::Iterator<__TYPE> &iterator) {
        size_t i = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; i++) {
            if(*(current)->value == *iterator) {
                break;
            }
        }

        size_t j = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; j++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        return j > i;
    }

    template<typename __TYPE>
    bool LinkedList<__TYPE>::Iterator::operator>(const size_t &position) {
        size_t j = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; j++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        return j > position;
    }

    template<typename __TYPE>
    bool LinkedList<__TYPE>::Iterator::operator<=(const C4STL::Iterator<__TYPE> &iterator) {
        size_t i = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; i++) {
            if(*(current)->value == *iterator) {
                break;
            }
        }

        size_t j = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; j++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        return j <= i;
    }

    template<typename __TYPE>
    bool LinkedList<__TYPE>::Iterator::operator<=(const size_t &position) {
        size_t j = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; j++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        return j <= position;
    }

    template<typename __TYPE>
    bool LinkedList<__TYPE>::Iterator::operator>=(const C4STL::Iterator<__TYPE> &iterator) {
        size_t i = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; i++) {
            if(*(current)->value == *iterator) {
                break;
            }
        }

        size_t j = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; j++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        return j >= i;
    }

    template<typename __TYPE>
    bool LinkedList<__TYPE>::Iterator::operator>=(const size_t &position) {
        size_t j = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; j++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        return j >= position;
    }

    template<typename __TYPE>
    bool LinkedList<__TYPE>::Iterator::operator==(const C4STL::Iterator<__TYPE> &iterator) {
        m_Ptr == iterator.operator->();
    }

    template<typename __TYPE>
    bool LinkedList<__TYPE>::Iterator::operator==(const size_t &position) {
        size_t j = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; j++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        return j == position;
    }

    template<typename __TYPE>
    bool LinkedList<__TYPE>::Iterator::operator!=(const C4STL::Iterator<__TYPE> &iterator) {
        m_Ptr != iterator->operator->();
    }

    template<typename __TYPE>
    bool LinkedList<__TYPE>::Iterator::operator!=(const size_t &position) {
        size_t j = 0;

        for(ListNode** current = &m_Head; current && *current && *(current)->next; j++) {
            if(*(current)->value == m_Ptr->value) {
                break;
            }
        }

        return j != position;
    }
}