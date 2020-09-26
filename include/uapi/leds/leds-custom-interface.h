/*
 * leds-custom-interface.h
 *
 * The file is using for connection
 * between userspace and kernel
 */
#ifndef _LEDS_CUSTOM_INTERFACE_
#define _LEDS_CUSTOM_INTERFACE_

#include <linux/ioctl.h>

typedef struct {
    int status;
} query_arg_t;

#define QUERY_SET_VARIABLES _IOW('q', 1, query_arg_t *)
#define QUERY_GET_VARIABLES _IOR('q', 2, query_arg_t *)

#endif /* _LEDS_CUSTOM_INTERFACE_ */
