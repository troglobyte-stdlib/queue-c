//
// file: package.h
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
#ifndef MIOK_QUEUE_PACKAGE_H
#define MIOK_QUEUE_PACKAGE_H

#ifdef __cplusplus
extern "C"
{
#endif

//
// Macros to control the visibility of functions provided by this package
//
#ifdef BUILDING_MIOK_QUEUE_PACKAGE
#define MIOK_QUEUE_PUBLIC __attribute__((visibility("default")))
#else
#define MIOK_QUEUE_PUBLIC
#endif

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published package with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting c23 standard. If you wish to use a version of this library
// that targets an older version of C append "-support" at the end of the
// package name and everything should just work.
//

typedef struct QueueOf QueueOf;

//
// Constructor and destructor functions
//

MIOK_QUEUE_PUBLIC QueueOf *miok_queue_create(void);
MIOK_QUEUE_PUBLIC void miok_queue_erase(QueueOf **structure_ref);

//
// Operations provided
//

MIOK_QUEUE_PUBLIC void miok_queue_push(QueueOf *structure_ptr, const char *data);
MIOK_QUEUE_PUBLIC const char *miok_queue_pop(QueueOf *structure_ptr);
MIOK_QUEUE_PUBLIC const char *miok_queue_peek(QueueOf *structure_ptr);
MIOK_QUEUE_PUBLIC unsigned int miok_queue_its_empty(QueueOf *structure_ptr);
MIOK_QUEUE_PUBLIC unsigned int miok_queue_not_empty(QueueOf *structure_ptr);
  

#ifdef __cplusplus
}
#endif

#endif // end of MIOK_PACKAGE_H
