#include <linux/init.h>
#include <linux/module.h>

const char MY_NAME[] = "James Blackburn";

EXPORT_SYMBOL(MY_NAME);

int trivial_sub(int a, int b) { return a - b; }

EXPORT_SYMBOL(trivial_sub);

static int __init provider_init(void) {
  pr_info("Hello World.\n");

  return 0;
}

static void __exit provider_exit(void) { pr_info("Goodbye World.\n"); }

module_init(provider_init);
module_exit(provider_exit);

MODULE_LICENSE("GPL");
