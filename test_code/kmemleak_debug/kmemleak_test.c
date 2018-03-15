#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>

static char *buf;

void create_kmemleak(void)
{
  buf = kmalloc(120, GFP_KERNEL);
  buf = vmalloc(4096);

}

static int __init my_test_init(void)
{
  printk("al: kmemleak test init\n");
  create_kmemleak();
  return 0;
}

static int __exit my_test_exit(void)
{
  printk("al: kmemleak test exit\n");
  return 0;
}

MODULE_LICENSE("GPL");
module_init(my_test_init);
module_exit(my_test_exit);
