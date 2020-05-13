
#ifndef PLAYER_EXPORT_H
#define PLAYER_EXPORT_H

#ifdef PLAYER_STATIC_DEFINE
#  define PLAYER_EXPORT
#  define PLAYER_NO_EXPORT
#else
#  ifndef PLAYER_EXPORT
#    ifdef player_EXPORTS
        /* We are building this library */
#      define PLAYER_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define PLAYER_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef PLAYER_NO_EXPORT
#    define PLAYER_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef PLAYER_DEPRECATED
#  define PLAYER_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef PLAYER_DEPRECATED_EXPORT
#  define PLAYER_DEPRECATED_EXPORT PLAYER_EXPORT PLAYER_DEPRECATED
#endif

#ifndef PLAYER_DEPRECATED_NO_EXPORT
#  define PLAYER_DEPRECATED_NO_EXPORT PLAYER_NO_EXPORT PLAYER_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PLAYER_NO_DEPRECATED
#    define PLAYER_NO_DEPRECATED
#  endif
#endif

#endif /* PLAYER_EXPORT_H */
