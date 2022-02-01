//
// file: package.c
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
#include "miok/queue.h"

#include <stdlib.h>

enum
{
    failed,
    success
}; // end of local enums

//
// This is the official definition for the Miok Libraries
// 'QueueNode' type.
//
// Members:
// > [_data] is the private data member that represents the
//           data in the structure
// > [_next_ptr] is the pointer to the next node in the stack
//
typedef struct QueueNode
{
    char *_data;
    struct QueueNode *_next_ptr;
} QueueNode; // end of struct

//
// This is the official definition for the Miok Libraries
// 'QueueOf' type.
//
// Members:
// > _begin_ptr is the pointer to queue begin
// > _end_ptr is the pointer to queue end
//
struct QueueOf
{
    size_t _size;
    struct QueueNode *_end_ptr;
    struct QueueNode *_begin_ptr;
}; // end of struct

//
// Should return a newly hatched data structure object if
// it pass the not nullptr test. But if it was a bad egg
// we just return nullptr.
//
// Param list:
// -> There is none to speak of at this time.
//
QueueOf *miok_queue_create(void)
{
    QueueOf *new_structure = malloc(sizeof(*new_structure));
    if (!new_structure)
    {
        return NULL;
    } // end if
    new_structure->_begin_ptr = NULL;
    new_structure->_end_ptr = NULL;
    new_structure->_size = 0;
    return new_structure;
} // end of function miok_queue_create

//
// Should erase the queue structure if it’s not nullptr else
// do nothing.
//
// Param list:
// -> [structure_ref]: Reference pointer to your structure
//
void miok_queue_erase(QueueOf **structure_ref)
{
    if (!structure_ref || !*structure_ref)
    {
        return;
    } // end if

    while (miok_queue_not_empty(*structure_ref))
    {
        miok_queue_pop(*structure_ref);
    } // end while

    free(*structure_ref);
    *structure_ref = NULL;
} // end of function miok_queue_erase

//
// Should push a new recored into the queue if the
// structure is not nullptr. Else nothing.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
// -> [data]: Your data being passed in
//
void miok_queue_push(QueueOf *structure_ptr, const char *data)
{
    if (!structure_ptr)
    {
        return;
    } // end if

    QueueNode *temp = malloc(sizeof(*temp));
    if (!temp)
    {
        return;
    } // end if

    temp->_data = (char *)data;
    temp->_next_ptr = NULL;

    //
    // If queue is empty, then set the new node to both begin and end
    if (!structure_ptr->_end_ptr)
    {
        structure_ptr->_begin_ptr = structure_ptr->_end_ptr = temp;
    } // end if
    else
    {
        structure_ptr->_end_ptr->_next_ptr = temp;
        structure_ptr->_end_ptr = temp;
    } // end else

    ++structure_ptr->_size;
} // end of function miok_queue_push

//
// Should return the value stored in the removed node from
// structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
const char *miok_queue_pop(QueueOf *structure_ptr)
{
    if (!structure_ptr || !structure_ptr->_begin_ptr)
    {
        return NULL;
    } // end if

    //
    // Here we store previous node to begin and move it close to end
    QueueNode *temp = structure_ptr->_begin_ptr;
    structure_ptr->_begin_ptr = structure_ptr->_begin_ptr->_next_ptr;

    if (!structure_ptr->_begin_ptr)
    {
        structure_ptr->_end_ptr = NULL;
        return NULL;
    } // end if
    else
    {
        return temp->_data;
    } // end else
} // end of function miok_queue_pop

//
// Should return the value stored in begin pointer from
// structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
const char *miok_queue_peek(QueueOf *structure_ptr)
{
    if (!structure_ptr || !structure_ptr->_begin_ptr)
    {
        return NULL;
    } // end if
    return structure_ptr->_begin_ptr->_data;
} // end of function miok_queue_peek

//
// Should return a success value if the structure is an
// empty structure.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
unsigned int miok_queue_its_empty(QueueOf *structure_ptr)
{
    return (!structure_ptr->_begin_ptr) ? success : failed;
} // end of functions miok_queue_its_empty

//
// Should return a success value if the structure is not
// empty in anyway.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
unsigned int miok_queue_not_empty(QueueOf *structure_ptr)
{
    return (structure_ptr->_begin_ptr) ? success : failed;
} // end of functions miok_queue_not_empty