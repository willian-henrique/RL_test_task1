
#ifdef EMBEEDED

    #define uint_16         unsigned int
    #define uint_32         unsigned long

    #define int_16          int
    #define int_32          long
#else

    #include <stdint.h>

    #define uint_16         uint16_t
    #define uint_32         uint32_t

    #define int_16          int16_t
    #define int_32          int32_t

#endif