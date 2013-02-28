
#include "zrt.h"

extern int (*__zcall_fcntl) (int fd, int cmd, ...);

void
init_zcalls_nonsyscalls(void);

#define INIT_ZCALLS {							\
	/*IRT syscalls can be redefined, it's totally saves nacl implementation*/ \
	struct zcalls_init_t* zcalls;					\
	if ( ZCALLS_INIT == __query_zcalls(ZCALLS_INIT, (void**)&zcalls) && \
	     zcalls ){							\
	    /*basic calls*/						\
	    __nacl_irt_exit        = zcalls->exit;			\
	    __nacl_irt_gettod      = zcalls->gettod;			\
	    __nacl_irt_clock       = zcalls->clock;			\
	    __nacl_irt_nanosleep   = zcalls->nanosleep;			\
	    __nacl_irt_sched_yield = zcalls->sched_yield;		\
	    __nacl_irt_sysconf     = zcalls->sysconf;			\
	    /*fdio calls*/						\
	    __nacl_irt_close       = zcalls->close;			\
	    __nacl_irt_dup         = zcalls->dup;			\
	    __nacl_irt_dup2        = zcalls->dup2;			\
	    __nacl_irt_read        = zcalls->read;			\
	    __nacl_irt_write       = zcalls->write;			\
	    __nacl_irt_seek        = zcalls->seek;			\
	    __nacl_irt_fstat       = zcalls->fstat;			\
	    __nacl_irt_getdents    = zcalls->getdents;			\
	    /*filename calls*/						\
	    __nacl_irt_open        = zcalls->open;			\
	    __nacl_irt_stat        = zcalls->stat;			\
	    /*memory calls*/						\
	    __nacl_irt_sysbrk      = zcalls->sysbrk;			\
	    __nacl_irt_mmap        = zcalls->mmap;			\
	    __nacl_irt_munmap      = zcalls->munmap;			\
	    /*dyncode calls*/						\
	    __nacl_irt_dyncode_create = zcalls->dyncode_create;		\
	    __nacl_irt_dyncode_modify = zcalls->dyncode_modify;		\
	    __nacl_irt_dyncode_delete = zcalls->dyncode_delete;		\
	    /*thread calls*/						\
	    __nacl_irt_thread_create = zcalls->thread_create;		\
	    __nacl_irt_thread_exit = zcalls->thread_exit;		\
	    __nacl_irt_thread_nice = zcalls->thread_nice;		\
	    /*mutes calls*/						\
	    __nacl_irt_mutex_create = zcalls->mutex_create;		\
	    __nacl_irt_mutex_destroy = zcalls->mutex_destroy;		\
	    __nacl_irt_mutex_lock  = zcalls->mutex_lock;		\
	    __nacl_irt_mutex_unlock = zcalls->mutex_unlock;		\
	    __nacl_irt_mutex_trylock = zcalls->mutex_trylock;		\
	    /*cond calls*/						\
	    __nacl_irt_cond_create  = zcalls->cond_create;		\
	    __nacl_irt_cond_destroy = zcalls->cond_destroy;		\
	    __nacl_irt_cond_signal  = zcalls->cond_signal;		\
	    __nacl_irt_cond_broadcast = zcalls->cond_broadcast;		\
	    __nacl_irt_cond_wait      = zcalls->cond_wait;		\
	    __nacl_irt_cond_timed_wait_abs = zcalls->cond_timed_wait_abs; \
	    /*tls calls*/						\
	    __nacl_irt_tls_init       = zcalls->tls_init;		\
	    __nacl_irt_tls_get        = zcalls->tls_get;		\
	    /*open_resource calls*/					\
	    __nacl_irt_open_resource  = zcalls->open_resource;		\
	    /*clock calls*/						\
	    __nacl_irt_clock_getres   = zcalls->getres;			\
	    __nacl_irt_clock_gettime  = zcalls->gettime;		\
									\
	    /*run zcall init*/						\
	    zcalls->init();						\
	}								\
    }

