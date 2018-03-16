#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/freezer.h>
#include <linux/mutex.h>
#include <linux/delay.h>


DEFINE_MUTEX(mutex_a);
struct delayed_work delay_task;
void lockdep_timefunc(unsigned long );
DEFINE_TIMER(lockdep_timer, lockdep_timefunc, 0, 0);

void lockdep_timefunc(unsigned long dummy)
{
  //printk("lockdep_timefunc expired\n");
  schedule_delayed_work(&delay_task, 10);
  mod_timer(&lockdep_timer, jiffies + msecs_to_jiffies(100));
}

void lockdep_test_worker(struct work_struct *work)
{
  //printk("lockdep_test_worker running\n");
  mutex_lock(&mutex_a);
  mdelay(300);
  mutex_unlock(&mutex_a);
}

int lockdep_thread(void *data)
{
  set_freezable();
  set_user_nice(current, 0);

  while(!kthread_should_stop()) {
    //printk("lockdep_test thread running.\n");
    mdelay(500);
    mutex_lock(&mutex_a);
    cancel_delayed_work_sync(&delay_task);
    mutex_unlock(&mutex_a);
  }

  return 0;
}


static int __init lockdep_test_init(void)
{
  struct task_struct *lock_thread;

  printk("al: lockdep error test exit\n");
  lock_thread = kthread_run(lockdep_thread, NULL, "lockdep_test");
  INIT_DELAYED_WORK(&delay_task, lockdep_test_worker);
  lockdep_timer.expires = jiffies + msecs_to_jiffies(500);
  add_timer(&lockdep_timer);

  return 0;
}

static int __exit lockdep_test_exit(void)
{
  printk("al: lockdep error test exit\n");

  return 0;
}

MODULE_LICENSE("GPL");
module_init(lockdep_test_init);
module_exit(lockdep_test_exit);
