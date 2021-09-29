#include "FreeList.h"

namespace C4STL {

    template<typename __TYPE>
    FreeList<__TYPE>::FreeList() C4STL_NOEXCEPT {}

    template<typename __TYPE>
    FreeList<__TYPE>::~FreeList() C4STL_NOEXCEPT {
        for(size_t i = 0; i < m_Memory.Size(); i++) {
            delete m_Memory[i];
        }
    }

    template<typename __TYPE>
    __TYPE &FreeList<__TYPE>::Front() {
        if(m_Size > 0) {
            return m_Memory[0][0];
        }

        // TODO: Throw exception
    }

    template<typename __TYPE>
    __TYPE &FreeList<__TYPE>::Back() {
        if(m_Size > 0) {
            return m_Memory.Back()[m_SizeChunks.Back() - 1];
        }

        // TODO: Throw exception
    }

    template<typename __TYPE>
    __TYPE &FreeList<__TYPE>::At(size_t index) {
        for(size_t i = 0; i < m_SizeChunks.Size(); i++) {
            if(index < m_SizeChunks[i]) {
                return m_Memory[index];
            }
            else {
                index -= m_SizeChunks[i];
            }
        }

        // TODO: throw exception
    }

    template<typename __TYPE>
    __TYPE &FreeList<__TYPE>::operator[](size_t index) {
        for(size_t i = 0; i < m_SizeChunks.Size(); i++) {
            if(index < m_SizeChunks[i]) {
                return m_Memory[index];
            }
            else {
                index -= m_SizeChunks[i];
            }
        }

        // TODO: throw exception
    }

    template<typename __TYPE>
    void FreeList<__TYPE>::AddMemoryChunk(__TYPE *memory, size_t memSize) C4STL_NOEXCEPT {
        if(memory && memSize > 0) {
            m_Size += memSize;
            m_Memory.PushBack(memory);
            m_SizeChunks.PushBack(memSize);
        }
    }

    template<typename __TYPE>
    void FreeList<__TYPE>::DeleteMemoryChunk(__TYPE *memory) C4STL_NOEXCEPT {
        if(memory) {
            for(size_t i = 0; i < m_Memory.Size(); i++) {
                if(memory == m_Memory[i]) {
                    m_Memory.Delete(i);
                    delete[] memory;
                    m_Size -= m_SizeChunks[i];
                    m_SizeChunks.Delete(i);
                }
            }
        }
    }

    template<typename __TYPE>
    void FreeList<__TYPE>::DeleteMemoryChunk(size_t index) {
        // TODO: check index out of bounds

        __TYPE* mem = m_Memory[index];
        m_Memory.Delete(index);
        delete[] mem;
        m_Size -= m_SizeChunks[index];
        m_SizeChunks.Delete(index);
    }
}