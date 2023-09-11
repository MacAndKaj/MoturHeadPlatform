#ifndef MOTOROS_COMMON__VISIBILITY_CONTROL_H_
#define MOTOROS_COMMON__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define MOTOROS_COMMON_EXPORT __attribute__ ((dllexport))
    #define MOTOROS_COMMON_IMPORT __attribute__ ((dllimport))
  #else
    #define MOTOROS_COMMON_EXPORT __declspec(dllexport)
    #define MOTOROS_COMMON_IMPORT __declspec(dllimport)
  #endif
  #ifdef MOTOROS_COMMON_BUILDING_LIBRARY
    #define MOTOROS_COMMON_PUBLIC MOTOROS_COMMON_EXPORT
  #else
    #define MOTOROS_COMMON_PUBLIC MOTOROS_COMMON_IMPORT
  #endif
  #define MOTOROS_COMMON_PUBLIC_TYPE MOTOROS_COMMON_PUBLIC
  #define MOTOROS_COMMON_LOCAL
#else
  #define MOTOROS_COMMON_EXPORT __attribute__ ((visibility("default")))
  #define MOTOROS_COMMON_IMPORT
  #if __GNUC__ >= 4
    #define MOTOROS_COMMON_PUBLIC __attribute__ ((visibility("default")))
    #define MOTOROS_COMMON_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MOTOROS_COMMON_PUBLIC
    #define MOTOROS_COMMON_LOCAL
  #endif
  #define MOTOROS_COMMON_PUBLIC_TYPE
#endif

#endif  // MOTOROS_COMMON__VISIBILITY_CONTROL_H_
