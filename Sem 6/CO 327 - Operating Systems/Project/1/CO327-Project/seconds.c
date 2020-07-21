#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include  <linux/jiffies.h>
#include <asm/param.h>

#define BUFFER_SIZE 128
#define PROC_NAME "seconds"

long unsigned int t;

ssize_t proc_read(struct file *file,char __user *usr_buf,size_t count,loff_t *pos);

static struct file_operations proc_ops = {
	.owner = THIS_MODULE,
	.read = proc_read,
};

/*This function is called when the module is loaded.*/
int proc_init(void){

	t = jiffies;

	/*creates the/proc/hello entry*/
	proc_create(PROC_NAME,0666,NULL,&proc_ops);
	return 0;
}

/*This function is called when the module is removed.*/
void proc_exit(void){
	/*removes the /proc/hello entry*/
	remove_proc_entry(PROC_NAME,NULL);
}

/*This function is called eash time /proc/hello is read*/
ssize_t proc_read(struct file *file,char __user *usr_buf,size_t count,loff_t *pos){
	int rv = 0;
	char buffer[BUFFER_SIZE];
	static int completed = 0;
	uint64_t p_time = 1000/HZ;
	uint64_t val = (jiffies-t)*p_time;
	
	if(completed){
		completed = 0;
		return 0;
	}

	completed = 1;

	//Elapsed time is in miliseconds because linux kernal do not support floating points
	rv = sprintf(buffer,"Elapsed Time (ms) = %llu\n",val);

	/*copies kernel space buffer to user space usr_buf*/
	copy_to_user(usr_buf,buffer,rv);

	return rv;
}

module_init(proc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Elapsed Time in seconds Module");
MODULE_AUTHOR("SGG");