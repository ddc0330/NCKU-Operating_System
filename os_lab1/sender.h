#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <time.h>

typedef struct {
    int flag;      // 1 for message passing, 2 for shared memory
    union{
        int msqid; // system V api //message queue id
        char* shm_addr; //shared memory address
    }storage;
} mailbox_t;


typedef struct {
    char text[1024];
} message_t;

void send(message_t message, mailbox_t* mailbox_ptr);