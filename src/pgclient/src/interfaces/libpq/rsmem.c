/*-------------------------------------------------------------------------
*
* Copyright(c) 2020, Amazon.com, Inc. or Its Affiliates. All rights reserved.
*
* Author: igarish
*-------------------------------------------------------------------------
*/

#include "rsmem.h"

/*====================================================================================================================================================*/

//---------------------------------------------------------------------------------------------------------igarish
// Allocate memory.
//
void *rs_malloc(size_t size)
{
    return malloc(size);
}

/*====================================================================================================================================================*/

//---------------------------------------------------------------------------------------------------------igarish
// Allocate and initialize memory with zeroes.
//
void *rs_calloc(size_t numOfElements, size_t sizeOfElements)
{
    return calloc(numOfElements, sizeOfElements);
}

/*====================================================================================================================================================*/

//---------------------------------------------------------------------------------------------------------igarish
// Reallocate memory.
//
void *rs_realloc(void *memory, size_t newSize)
{
    return realloc(memory, newSize);
}

/*====================================================================================================================================================*/

//---------------------------------------------------------------------------------------------------------igarish
// Free the allocated memory.
//
void *rs_free(void * block)
{
    if(block)
        free(block);

    return NULL;
}
