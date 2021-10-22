#include <stdio.h>

#include "./../../threads/synch.h"
#include "./../../threads/thread.h"

static void universal_sema_func();


void my_test_synch_sema(){
    
    struct semaphore my_sema;
    sema_init_name(&my_sema, 1, "the_test_semaphore");
    for(int i = 0; i<10; i++){
        char name[16];

        snprintf(name, sizeof name, "thread_%d", i);

        thread_create(name, PRI_DEFAULT, universal_sema_func, &my_sema);

    }
}

static void universal_sema_func(struct semaphore *my_sema){
    struct thread *c_thread = thread_current();
    printf("%s before acquire\n", c_thread->name);

    sema_down(my_sema);
    printf("%s during acquire\n",c_thread->name);
    sema_up(my_sema);

    printf("%s after sem release\n",c_thread->name);
};
