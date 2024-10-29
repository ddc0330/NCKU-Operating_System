#include "receiver.h"

void receive(message_t* message_ptr, mailbox_t* mailbox_ptr){
    if(mailbox_ptr->flag==1){ //message passing mechanism
        msgrcv(mailbox_ptr->storage.msqid, message_ptr, sizeof(message_ptr->text), 0,0);
    }
    else if(mailbox_ptr->flag==2){ //shared memory mechanism
        memcpy(message_ptr->text, mailbox_ptr->storage.shm_addr, sizeof(message_ptr->text));
    }
}

int main(int argc, char* argv[]){
    mailbox_t mailbox;
    message_t message;
    mailbox.flag= atoi(argv[1]); //get mechanism
    sem_t *sender_sem = sem_open("/sender_sem", O_CREAT, 0644, 1); // sender signal , 1 for active at first
    sem_t *receiver_sem = sem_open("/receiver_sem", O_CREAT, 0644, 0); // receiver signal , 0 for closed at first
    struct timespec start, end; // for time counting
    double total_time = 0;

    //create message queue for receiving
    if(mailbox.flag == 1){
        printf("\033[1;36mPassing Message\033[0m\n");
        key_t key = ftok("receiver.c",'6'); //create unique key
        mailbox.storage.msqid = msgget(key, 0666 | IPC_CREAT); //create message queue
    }
    else if(mailbox.flag == 2){
        printf("\033[1;36mShared Memory\033[0m\n");
        key_t key = ftok("receiver.c", '9'); 
        int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
        mailbox.storage.shm_addr = shmat(shmid, NULL, 0);
    }
    //receive message
    while (1) {
        sem_wait(receiver_sem); 
        clock_gettime(CLOCK_MONOTONIC, &start); // start clock
        receive(&message, &mailbox);
        clock_gettime(CLOCK_MONOTONIC, &end); // close clock
        total_time += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
        if (strcmp(message.text, "gg") == 0) { // exit
            break;
        }
        else{
            printf("\033[1;36mReceiving Message:\033[0m %s", message.text);
        }
        sem_post(sender_sem);
    }
    printf("\n\033[1;31mSender exit!\033[0m\n");
    //close everything
    sem_close(sender_sem);
    sem_close(receiver_sem);
    sem_unlink("/sender_sem");
    sem_unlink("/receiver_sem");
    //print total time

    printf("Total time taken in receiving message: %f seconds\n", total_time);
}