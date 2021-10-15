#include <stdio.h>
#include "./../../threads/thread.h"
#include "./../../threads/interrupt.h"

int total_thread_no;

static void universal_func();
static void print_thread_info();

void my_test_create_threads(){
    thread_create ("my_thread_0", PRI_DEFAULT, universal_func, NULL);
    thread_create ("my_thread_1", PRI_DEFAULT, universal_func, NULL);
    thread_create ("my_thread_2", PRI_DEFAULT, universal_func, NULL);
    thread_create ("my_thread_3", PRI_DEFAULT, universal_func, NULL);
    thread_create ("my_thread_4", PRI_DEFAULT, universal_func, NULL);
}

static void 
universal_func(){
    printf("Thread %s with tid %d created\n", thread_name(), thread_tid());
    //part 1
    // print_thread_info(thread_current());
    //part 2.1
    intr_disable();
    thread_foreach(print_thread_info, NULL);
    intr_enable();
    printf("Thread %s with tid %d finished\n", thread_name(), thread_tid());
}

static void
print_thread_info(struct thread *th){
    // part 2
    // printf("Number of running threads: %d\n", total_thread_no);
    // printf("Thread info:\n\tName: %s\n\ttid:%d\n\tparent_tid:%d\n\tPriority:%d\n\tStatus:%d\n", 
    //         th->name, th->tid, th->parent_tid, th->priority, th->status);

    //part 2.2
    if(th->status == THREAD_READY){
        printf("Number of running threads: %d\n", total_thread_no);
        printf("Thread info:\n\tName: %s\n\ttid:%d\n\tparent_tid:%d\n\tPriority:%d\n\tStatus:%d\n", 
            th->name, th->tid, th->parent_tid, th->priority, th->status);
    }
}