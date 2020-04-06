#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");

static 
int __init baremin_init(void) {
	printk("baremininum : Hi.\n") ;
	return 0;
}

static 
void __exit baremin_exit(void) {
	printk("bareminimum : Bye.\n") ;
}

module_init(baremin_init);
module_exit(baremin_exit);
