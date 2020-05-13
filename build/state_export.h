
#ifndef STATE_EXPORT_H
#define STATE_EXPORT_H

#ifdef STATE_STATIC_DEFINE
#  define STATE_EXPORT
#  define STATE_NO_EXPORT
#else
#  ifndef STATE_EXPORT
#    ifdef state_EXPORTS
        /* We are building this library */
#      define STATE_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define STATE_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef STATE_NO_EXPORT
#    define STATE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef STATE_DEPRECATED
#  define STATE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef STATE_DEPRECATED_EXPORT
#  define STATE_DEPRECATED_EXPORT STATE_EXPORT STATE_DEPRECATED
#endif

#ifndef STATE_DEPRECATED_NO_EXPORT
#  define STATE_DEPRECATED_NO_EXPORT STATE_NO_EXPORT STATE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef STATE_NO_DEPRECATED
#    define STATE_NO_DEPRECATED
#  endif
#endif

#endif /* STATE_EXPORT_H */
