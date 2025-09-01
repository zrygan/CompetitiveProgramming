/**
 * A DYNAMIC ARRAY is an array whose size grows up to a maximum to
 * allow for more elements to me put inside.
 * 
 * This implementation uses an array.
 * 
 * Here we have _ functions:
 *  initDynamicArray: initializes a new dynamic array structure
 * 
 * by: Zhean Ganituen
 */

#include <stdlib.h>
#include <stdbool.h>

/**
 * DynamicArray Structure.
 * 
 * fields:
 *  elems (int*): the elements in the dynamic array
 *  size (int): the current size of the dynamic array, | elems |
 *  maxSize (int): the maximum capacity or size of the dynamic array
 *  resize (bool): a boolean flag that allows for the dynamic array to 
 *      be resized if size + 1 >= maxSize
 */
typedef struct
{
    int *elems;
    int size;
    int maxSize;
    bool resize;
} DynamicArray;

/**
 * Initialize dynamic array.
 * 
 * params:
 *  maxSize (int): the maximum capacity of that DynamicArray
 * 
 * ensure:
 *  dynamic array structure
 */
DynamicArray *initDynamicArray(int maxSize, bool resize)
{
    DynamicArray *da = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (da == NULL)
    {
        return NULL;
    }

    da->elems = (int*)malloc(maxSize * sizeof(int));
    if (da->elems == NULL)
    {
        free(da);
        return NULL;
    }

    da->size = 0;
    da->maxSize = maxSize;
    da->resize = resize;

    return da;
}

/**
 * Add a new element to the dynamic array. If DynamicArray.resize is
 * true then resize the array as needed.
 * 
 * params:
 *  da (DynamicArray*): the dynamic array structure
 *  addElem (int): the element to be added to the dunamic array
 * 
 * ensures:
 *  addElem at DynamicArray.elems[DynamicArray.size], if possible.
 */
void addElement(DynamicArray* da, int addElem)
{
    if (da == NULL)
        return;

    if (da->size + 1 >= da->maxSize)
    {
        if (!da->resize)
            return;
        else
        {
            int newMaxSize = da->maxSize * 2;
            int* newElems = realloc(da->elems, newMaxSize * sizeof(int));
            if (newElems == NULL)
                return;

            da->elems = newElems;
            da->maxSize = newMaxSize;
        }
    }

    da->elems[da->size++] = addElem;
}