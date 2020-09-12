/*
 *  leds-custom.c - The simplest kernel module.
 */
#include <linux/module.h>   /* Needed by all modules */
#include <linux/kernel.h>   /* Needed for KERN_INFO */
#include <linux/gpio.h>     /* Needed for gpio pins */

#include <linux/init.h>    /* Needed for the macros */
#include <linux/version.h> /* Needed for check linux version for ioctl functions */
#include <linux/errno.h>   /* Needed for check errors */
#include <linux/device.h>  /* Needed for devices driver */
#include <linux/cdev.h>    /* Needed for character devices */
#include <linux/fs.h>      /* Needed for file operations */
#include <linux/uaccess.h> /* Needed for user access to kernel */

#define	GPIO26	26
#define FIRST_MINOR 0
#define MINOR_CNT   1

static dev_t dev;
static struct cdev c_dev;
static struct class *cl;

enum {
	SET_OFF	=	0,
	SET_ON	=	1,
};

enum {
	INPUT	=	0,
	OUTPUT	=	1,
};

static int leds_open(struct inode *i, struct file *f)
{
    printk(KERN_INFO "Kernel module driver: leds custom open.\n");
    return 0;
}

static int leds_close(struct inode *i, struct file *f)
{
    printk(KERN_INFO "Kernel module driver: leds custom close.\n");
    return 0;
}

static ssize_t leds_read(struct file *f, char __user *buf, size_t len, loff_t *off)
{
    printk(KERN_INFO "Kernel module driver: leds custom read.\n");
    return 0;
}

static int leds_write(struct file *f, const char __user *buf, size_t len, loff_t *off)
{
    printk(KERN_INFO "Kernel module driver: leds custom write.\n");
    return len;
}

static struct file_operations leds_custom_fops =
{
    .owner = THIS_MODULE,
    .open = leds_open,
    .release = leds_close,
    .read = leds_read,
    .write = leds_write
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

    if (alloc_chrdev_region(&dev, FIRST_MINOR, MINOR_CNT, "leds_custom") < 0) {
        return -1;
    }
    if ((cl = class_create(THIS_MODULE, "leds_custom_chardrv")) == NULL) {
        unregister_chrdev_region(dev, MINOR_CNT);
        printk(KERN_INFO "Error character device create!\n");
        return -1;
    }
    if (device_create(cl, NULL, dev, NULL, "leds_custom") == NULL) {
        class_destroy(cl);
        unregister_chrdev_region(dev, MINOR_CNT);
        printk(KERN_INFO "Error device create!\n");
        return -1;
    }
    cdev_init(&c_dev, &leds_custom_fops);
    if (cdev_add(&c_dev, dev, MINOR_CNT) == -1) {
        device_destroy(cl, dev);
        class_destroy(cl);
        unregister_chrdev_region(dev, MINOR_CNT);
        printk(KERN_INFO "Error adding character device!\n");
        return -1;
    }
    return 0;
}

static void __exit cleanup_module_leds_custom(void)
{
    unsubscribe_gpios();
    printk(KERN_INFO "Unload kernel module: leds custom.\n");

    cdev_del(&c_dev);
    device_destroy(cl, dev);
    class_destroy(cl);
    unregister_chrdev_region(dev, MINOR_CNT);
}

module_init(init_module_leds_custom);
module_exit(cleanup_module_leds_custom);

MODULE_LICENSE("GPL v2");
