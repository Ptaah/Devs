/*
 * This module stop an irq handler on all cpu.
 * */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>

static unsigned int stop_irq = 1;
module_param(stop_irq, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(stop_irq, "irq to stop");


static int __init stop_irq_init(void)
{
    printk(KERN_INFO "Disabling IRQ: %d\n", stop_irq);
    disable_irq(stop_irq);
    return 0;
}

static void __exit stop_irq_exit(void)
{
    printk(KERN_INFO "Enabling IRQ: %d\n", stop_irq);
    enable_irq(stop_irq);
}

module_init(stop_irq_init)
module_exit(stop_irq_exit)
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aurelien Cedeyn");
