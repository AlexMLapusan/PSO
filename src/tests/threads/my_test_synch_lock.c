#include <stdio.h>

#include "./../../threads/synch.h"
#include "./../../threads/thread.h"

static void universal_lock_func();


void my_test_synch_lock(){
    
    struct lock my_lock;
    lock_init_name(&my_lock, "the_test_lock");
    for(int i = 0; i<10; i++){
        char name[16];

        snprintf(name, sizeof name, "thread_%d", i);

        thread_create(name, PRI_DEFAULT, universal_lock_func, &my_lock);

    }
}

static void universal_lock_func(struct lock *my_lock){
    struct thread *c_thread = thread_current();
    printf("%s before acquire\n", c_thread->name);

    lock_acquire(my_lock);
    printf("%s during acquire\n",c_thread->name);
    lock_release(my_lock);

    printf("%s after lock release\n",c_thread->name);
};
