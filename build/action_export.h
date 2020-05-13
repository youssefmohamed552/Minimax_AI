
#ifndef ACTION_EXPORT_H
#define ACTION_EXPORT_H

#ifdef ACTION_STATIC_DEFINE
#  define ACTION_EXPORT
#  define ACTION_NO_EXPORT
#else
#  ifndef ACTION_EXPORT
#    ifdef action_EXPORTS
        /* We are building this library */
#      define ACTION_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ACTION_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ACTION_NO_EXPORT
#    define ACTION_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ACTION_DEPRECATED
#  define ACTION_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ACTION_DEPRECATED_EXPORT
#  define ACTION_DEPRECATED_EXPORT ACTION_EXPORT ACTION_DEPRECATED
#endif

#ifndef ACTION_DEPRECATED_NO_EXPORT
#  define ACTION_DEPRECATED_NO_EXPORT ACTION_NO_EXPORT ACTION_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ACTION_NO_DEPRECATED
#    define ACTION_NO_DEPRECATED
#  endif
#endif

#endif /* ACTION_EXPORT_H */
