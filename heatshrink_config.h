#ifndef HEATSHRINK_CONFIG_H
#define HEATSHRINK_CONFIG_H
#include "MemoryCppWrapper.hpp"
/* Should functionality assuming dynamic allocation be used? */
#ifndef HEATSHRINK_DYNAMIC_ALLOC
#define HEATSHRINK_DYNAMIC_ALLOC 1
#endif

#if HEATSHRINK_DYNAMIC_ALLOC
    /* Optional replacement of malloc/free */
    #define HEATSHRINK_MALLOC(SZ) MemoryWrapper_Allocate_Blocking(SZ,"heatshrink_config::MemoryWrapper_Allocate_Blocking",false)
    #define HEATSHRINK_FREE(P, SZ) MemoryWrapper_Free_Source(P,"heatshrink_config::MemoryWrapper_Free_Source")
#else
    /* Required parameters for static configuration */
    #define HEATSHRINK_STATIC_INPUT_BUFFER_SIZE 32
    #define HEATSHRINK_STATIC_WINDOW_BITS 8
    #define HEATSHRINK_STATIC_LOOKAHEAD_BITS 4
#endif

/* Turn on logging for debugging. */
#define HEATSHRINK_DEBUGGING_LOGS 0

/* Use indexing for faster compression. (This requires additional space.) */
#define HEATSHRINK_USE_INDEX 1

#endif
