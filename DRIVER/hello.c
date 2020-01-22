#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include<linux/uaccess.h>

#define BL 512
static char kbuf[BL];

ssize_t fileread (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO"File is getting read");
	copy_to_user(buffer,kbuf,length);
	return 0;
}
ssize_t filewrite (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO"File is getting write \n");
	copy_from_user(kbuf,buffer,length);
	printk(KERN_INFO"writing file to device ... \n %s",kbuf);
	return length;
}
int fileopen (struct inode *pinode, struct file *pfile)
{
	printk(KERN_INFO"File opened \n");
	return 0;
}
int fileclose (struct inode *pinode, struct file *pfile)
{
	printk(KERN_INFO"File closed \n");
	return 0;
}



struct file_operations file_operations = {
	.owner = THIS_MODULE,
	.open = fileopen,
	.read = fileread,
	.write = filewrite,
	.release = fileclose,
};




static int __init hello_init(void)
{
	printk(KERN_INFO"entry point ");
	
	register_chrdev(240 , "my char drv" , &file_operations);
	return 0;
} 


static int __exit hello_exit(void)
{
	printk(KERN_INFO"exit point ");
	
	unregister_chrdev(240 , "my char drv");
	return 0;	
} 


module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BHAGYASHRI D");
MODULE_DESCRIPTION("CHARACTER DRIVE");
