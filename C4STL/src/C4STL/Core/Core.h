#ifndef C4STL_CORE_H
#define C4STL_CORE_H

#define C4STL_BIT(x) (1 << x)


#define C4STL_PLATFORM_WINDOWS 0
#define C4STL_PLATFORM_MACOS 1
#define C4STL_PLATFORM_IOS 2
#define C4STL_PLATFORM_LINUX 3
#define C4STL_PLATFORM_ANDROID 4
#define C4STL_PLATFORM_WEB 5


#if (defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__))

#ifdef C4STL_PLATFORM
#error "Platform is already defined and cannot be defined twice."
#endif

#define C4STL_PLATFORM C4STL_PLATFORM_WINDOWS
#define C4STL_WINDOWS

#endif


#if ((defined(macintosh) || defined(Macintosh) || defined(__APPLE__) || defined(__MACH__)) && !defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__))

#ifdef C4STL_PLATFORM
#error "Platform is already defined and cannot be defined twice."
#endif

#define C4STL_PLATFORM C4STL_PLATFORM_MACOS
#define C4STL_MACOS

#endif


#if ((defined(__APPLE__) || defined(__MACH__)) && defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__))

#ifdef C4STL_PLATFORM
#error "Platform is already defined and cannot be defined twice."
#endif

#define C4STL_PLATFORM C4STL_PLATFORM_IOS
#define C4STL_IOS

#endif


#if (defined(__linux__) || defined(linux) || defined(__linux))

#ifdef C4STL_PLATFORM
#error "Platform is already defined and cannot be defined twice."
#endif

#define C4STL_PLATFORM C4STL_PLATFORM_LINUX
#define C4STL_LINUX

#endif


#if (defined(__ANDROID__))

#ifdef C4STL_PLATFORM
#error "Platform is already defined and cannot be defined twice."
#endif

#define C4STL_PLATFORM C4STL_PLATFORM_ANDROID
#define C4STL_ANDROID

#endif


#if (defined(__EMSCRIPTEN__))

#ifdef C4STL_PLATFORM
#error "Platform is already defined and cannot be defined twice."
#endif

#define C4STL_PLATFORM C4STL_PLATFORM_WEB
#define C4STL_WEB

#endif


#ifdef C4STL_WINDOWS
#ifdef __C4STL_BUILD
#define C4STL_PUBLIC_API __declspec(dllexport)
#else
#define C4STL_PUBLIC_API __declspec(dllimport)
#endif
#else
#define C4STL_PUBLIC_API __attribute__((visibility("default")))
#endif

#define C4STL_PRIVATE_API __attribute__((visibility("hidden")))


#ifdef __C4STL_NO_FINAL
#define C4STL_FINAL
#else
#define C4STL_FINAL final
#endif


#ifdef __C4STL_NO_NODISCARD
#define C4STL_NODISCARD
#else
#define C4STL_NODISCARD [[nodiscard]]
#endif

#ifdef __C4STL_NO_NOEXCEPT
#define C4STL_NOEXCEPT
#else
#define C4STL_NOEXCEPT noexcept
#endif


#include <cstddef>

#endif
