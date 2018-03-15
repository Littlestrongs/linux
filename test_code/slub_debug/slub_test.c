#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>

static char *buf;

static void create_slub_error(void)
{
  buf = kmalloc(32, GFP_KERNEL);
  if(buf) {
    memset(buf, 0x55, 36);
  }
}

static int __init my_test_init(void)
{
  printk("al: slub error test init\n");
  create_slub_error();
  return 0;
}

static int __exit my_test_exit(void)
{
  printk("al: slub error test exit\n");
  return 0;
}

MODULE_LICENSE("GPL");
module_init(my_test_init);
module_exit(my_test_exit);
