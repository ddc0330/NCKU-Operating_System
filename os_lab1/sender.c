#include "sender.h"

void send(message_t message, mailbox_t* mailbox_ptr){

    if(mailbox_ptr->flag==1){ //message passing mechanism
        //send message to unique message queue id
        msgsnd(mailbox_ptr->storage.msqid, &message, sizeof(message.text), 0);
    }
    else if(mailbox_ptr->flag==2){ //shared memory mechanism
        //send message to shared memory
        memcpy(mailbox_ptr->storage.shm_addr, &message, sizeof(message.text));
    }
}

int main(int argc, char* argv[]){
    //initialize
    mailbox_t mailbox;
    message_t message;
    mailbox.flag = atoi (argv[1]); //get method
    FILE* file = fopen(argv[2], "r"); // get file name
    sem_t *sender_sem = sem_open("/sender_sem", O_CREAT, 0644, 1); // sender signal , 1 for active at first
    sem_t *receiver_sem = sem_open("/receiver_sem", O_CREAT, 0644, 0); // receiver signal , 0 for closed at first
    struct timespec start, end; // for time counting
    double total_time = 0;

    //create message queue for sendinga
    if(mailbox.flag == 1){
        printf("\033[1;36mPassing Message\n\033[0m");
        key_t key = ftok("receiver.c",'6'); //create unique key
        mailbox.storage.msqid = msgget(key, 0666 | IPC_CREAT); //create message queue id
    }
    else if(mailbox.flag == 2){
        printf("\033[1;36mShared Memory\n\033[m");
        key_t key = ftok("receiver.c", '9'); 
        int shmid = shmget(key, 1024, 0666 | IPC_CREAT); // create shared memoty
        mailbox.storage.shm_addr = shmat(shmid, NULL, 0); // locate it
    }

    //read message and send
    while (fgets(message.text, sizeof(message.text), file) != NULL) {
        sem_wait(sender_sem); // wait for signal, 
        clock_gettime(CLOCK_MONOTONIC, &start); // start clock
        send(message, &mailbox); 
        clock_gettime(CLOCK_MONOTONIC, &end); // close clock
        if (strcmp(message.text, "gg") != 0) printf("\033[1;36mSending Message:\033[0m %s", message.text); //print message if not gg
        total_time += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
        sem_post(receiver_sem); 
    }
    printf("\n\033[1;31mEnd of input file! exit!\n\033[0m");
    //send close message
    strcpy(message.text, "gg");
    sem_wait(sender_sem);
    send(message, &mailbox);
    sem_post(receiver_sem);

    //close everything
    fclose(file);
    sem_close(sender_sem);
    sem_close(receiver_sem);
    sem_unlink("/sender_sem");
    sem_unlink("/receiver_sem");
    //print total time
    printf("Total time taken in sending msg: %f s\n", total_time);
}
