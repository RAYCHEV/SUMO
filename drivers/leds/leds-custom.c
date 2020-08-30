/*
 *  leds-custom.c - The simplest kernel module.
 */
#include <linux/module.h>   /* Needed by all modules */
#include <linux/kernel.h>   /* Needed for KERN_INFO */
#include <linux/gpio.h>     /* Needed for gpio pins */

#define	GPIO26	26

enum {
	SET_OFF	=	0,
	SET_ON	=	1,
};

enum {
	INPUT	=	0,
	OUTPUT	=	1,
};

static void subscribe_gpios(void) {
    gpio_export(GPIO26, false);
    gpio_request(GPIO26, "sysfs");
    gpio_direction_output(GPIO26, OUTPUT);

    printk(KERN_INFO "Set gpio on.\n");
    gpio_set_value(GPIO26, SET_ON);
}

static void unsubscribe_gpios(void) {
    printk(KERN_INFO "Set gpio off.\n");
    gpio_set_value(GPIO26, SET_OFF);

    gpio_export(GPIO26, false);
    gpio_unexport(GPIO26);
    gpio_free(GPIO26);
}

static int __init init_module_leds_custom(void)
{
    printk(KERN_INFO "Load kernel module: leds custom.\n");
    subscribe_gpios();
    return 0;
}

static void __exit cleanup_module_leds_custom(void)
{
    unsubscribe_gpios();
    printk(KERN_INFO "Unload kernel module: leds custom.\n");
}

module_init(init_module_leds_custom);
module_exit(cleanup_module_leds_custom);

MODULE_LICENSE("GPL v2");
