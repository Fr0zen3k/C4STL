#if defined (_MSC_VER)
#pragma once
#pragma warning(push)
#pragma warning(disable: 4251)
#endif

#ifndef C4STL_STRING_H
#define C4STL_STRING_H

#include "Core.h"
#include "C4STL/Containers/Arrays/DynamicArray.h"

#include <cstdint>

namespace C4STL
{
    typedef char Char8;
    typedef uint16_t Char16;
    typedef uint32_t Char32;

    enum class UTF {
        UTF-8           = 0,
        UTF-16          = 1,
        UTF-32          = 2
    };

    class C4STL_PUBLIC_API String {
    public:
        String(Char8* = nullptr) C4STL_NOEXCEPT;
        String(Char16* = nullptr) C4STL_NOEXCEPT;
        String(Char32* = nullptr) C4STL_NOEXCEPT;
        virtual ~String() C4STL_NOEXCEPT = default;

        inline size_t Size() C4STL_NOEXCEPT { return m_StringData.Size(); }

        void Clear() C4STL_NOEXCEPT;

        bool Empty() C4STL_NOEXCEPT;

        Char8* Str8() C4STL_NOEXCEPT;
        Char16* Str16() C4STL_NOEXCEPT;
        Char32* Str32() C4STL_NOEXCEPT;

        void* GetConverted(UTF type) C4STL_NOEXCEPT;

        Char8* ConvertedStr8() C4STL_NOEXCEPT;
        Char16* ConvertedStr16() C4STL_NOEXCEPT;
        Char32* ConvertedStr32() C4STL_NOEXCEPT;

        void Concat(const String& str) C4STL_NOEXCEPT;
        void Concat(const Char8* const str) C4STL_NOEXCEPT;
        void Concat(const Char16* const str) C4STL_NOEXCEPT;
        void Concat(const Char32* const str) C4STL_NOEXCEPT;

        bool Remove(const String& str) C4STL_NOEXCEPT;
        bool Remove(const Char8* const str) C4STL_NOEXCEPT;
        bool Remove(const Char16* const str) C4STL_NOEXCEPT;
        bool Remove(const Char32* const str) C4STL_NOEXCEPT;

        size_t Find(const String& str);
        size_t Find(const Char8* const str);
        size_t Find(const Char16* const str);
        size_t Find(const Char32* const str);

        Char8& Char8At(size_t index);
        Char16& Char8At(size_t index);
        Char32& Char8At(size_t index);

        Char8& operator [] (size_t index);
        Char16& operator [] (size_t index);
        Char32& operator [] (size_t index);

        void operator + (const String& str) C4STL_NOEXCEPT;
        void operator + (const Char8* const str) C4STL_NOEXCEPT;
        void operator + (const Char16* const str) C4STL_NOEXCEPT;
        void operator + (const Char32* const str) C4STL_NOEXCEPT;

        bool operator - (const String& str) C4STL_NOEXCEPT;
        bool operator - (const Char8* const str) C4STL_NOEXCEPT;
        bool operator - (const Char16* const str) C4STL_NOEXCEPT;
        bool operator - (const Char32* const str) C4STL_NOEXCEPT;

    private:
        DynamicArray<Char32> m_StringData;
    };
}

#endif

#if defined (_MSC_VER)
#pragma warning(pop)
#endif