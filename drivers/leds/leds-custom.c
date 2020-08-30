/*
 *  leds-custom.c - The simplest kernel module.
 */
#include <linux/module.h>   /* Needed by all modules */
#include <linux/kernel.h>   /* Needed for KERN_INFO */

int init_module(void)
{
    printk(KERN_INFO "Load kernel module: leds custom.\n");

    return 0;
}

void cleanup_module(void)
{
    printk(KERN_INFO "Unload kernel module: leds custom.\n");
}

MODULE_LICENSE("GPL v2");
