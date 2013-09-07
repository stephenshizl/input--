#ifndef _LIGDBG_CMN__
#define _LIGDBG_CMN__

void mod_cmn_main(int argc, char **argv);
u32 lidbg_get_ns_count(void);
int lidbg_launch_user( char bin_path[], char argv1[],char argv2[]);
int lidbg_readwrite_file(const char *filename, char *rbuf,const char *wbuf, size_t length);
int lidbg_task_kill_select(char *task_name);
int lidbg_get_current_time(char *time_string,struct rtc_time *ptm);

#ifdef BUILD_FOR_RECOVERY
#define INSMOD_PATH "/sbin/insmod"
#define CHMOD_PATH  "/sbin/chmod"

#else
#define INSMOD_PATH "/system/bin/insmod"
#define CHMOD_PATH "/system/bin/chmod"

#endif

#endif

