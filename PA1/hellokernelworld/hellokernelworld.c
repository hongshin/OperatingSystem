#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");

static 
char hello_name[128] = { 0x0, } ;

static 
int hello_open(struct inode *inode, struct file *file) {
	return 0 ;
}

static 
int hello_release(struct inode *inode, struct file *file) {
	return 0 ;
}

static
ssize_t hello_read(struct file *file, char __user *ubuf, size_t size, loff_t *offset) 
{
	char buf[256] ;
	ssize_t toread ;

	sprintf(buf, "Hello %s from kernel!\n", hello_name) ;

	toread = strlen(buf) >= *offset + size ? size : strlen(buf) - *offset ;

	if (copy_to_user(ubuf, buf + *offset, toread))
		return -EFAULT ;	

	*offset = *offset + toread ;

	return toread ;
}

static 
ssize_t hello_write(struct file *file, const char __user *ubuf, size_t size, loff_t *offset) 
{
	char buf[128] ;

	if (*offset != 0 || size > 128)
		return -EFAULT ;

	if (copy_from_user(buf, ubuf, size))
		return -EFAULT ;

	sscanf(buf,"%128s", hello_name) ;
	*offset = strlen(buf) ;

	return *offset ;
}

static const struct file_operations hello_fops = {
	.owner = 	THIS_MODULE,
	.open = 	hello_open,
	.read = 	hello_read,
	.write = 	hello_write,
	.llseek = 	seq_lseek,
	.release = 	hello_release,
} ;

static 
int __init hello_init(void) {
	proc_create("hellokernelworld", S_IRUGO | S_IWUGO, NULL, &hello_fops) ;
	return 0;
}

static 
void __exit hello_exit(void) {
	remove_proc_entry("hellokernelworld", NULL) ;
}

module_init(hello_init);
module_exit(hello_exit);
