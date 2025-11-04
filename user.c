#include <linux/init.h>
#include <linux/module.h>

extern int trivial_sub(int, int);
extern char MY_NAME[];

static int __init user_init(void) {
  pr_info("Hello World.\n");
  pr_info("%s", MY_NAME);
  pr_info("\n");

  return trivial_sub(1, 1);
}

static void __exit user_exit(void) { pr_info("Goodbye World.\n"); }

module_init(user_init);
module_exit(user_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Uses the defined externs from provider.c");
