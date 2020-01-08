
#ifndef LIBPITCHER_EXPORTS_H
#define LIBPITCHER_EXPORTS_H

#ifdef SHARED_EXPORTS_BUILT_AS_STATIC
#  define LIBPITCHER_EXPORTS
#  define LIBPITCHER_NO_EXPORT
#else
#  ifndef LIBPITCHER_EXPORTS
#    ifdef libpitcher_EXPORTS
        /* We are building this library */
#      define LIBPITCHER_EXPORTS __declspec(dllexport)
#    else
        /* We are using this library */
#      define LIBPITCHER_EXPORTS __declspec(dllimport)
#    endif
#  endif

#  ifndef LIBPITCHER_NO_EXPORT
#    define LIBPITCHER_NO_EXPORT 
#  endif
#endif

#ifndef LIBPITCHER_DEPRECATED
#  define LIBPITCHER_DEPRECATED __declspec(deprecated)
#endif

#ifndef LIBPITCHER_DEPRECATED_EXPORT
#  define LIBPITCHER_DEPRECATED_EXPORT LIBPITCHER_EXPORTS LIBPITCHER_DEPRECATED
#endif

#ifndef LIBPITCHER_DEPRECATED_NO_EXPORT
#  define LIBPITCHER_DEPRECATED_NO_EXPORT LIBPITCHER_NO_EXPORT LIBPITCHER_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef LIBPITCHER_NO_DEPRECATED
#    define LIBPITCHER_NO_DEPRECATED
#  endif
#endif

#endif /* LIBPITCHER_EXPORTS_H */
