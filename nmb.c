/* Filename : nmb.c */
/* API FOR THE nmb  */

/*The nmb_msgsnd() and nmb_msgrcv() system calls are used, respectively,
to send messages to, and receive messages from, a message queue.
The calling process must have write permission on the message queue
in order to send a message, and read permission to receive a message.

The msgp argument is a pointer to caller-defined structure of the following general form:



    struct msgbuf {
        long mtype;       /* message type, must be > 0
        char mtext[1];    /* message data
    };

The mtext field is an array (or other structure) whose size is specified by
msgsz, a nonnegative integer value. Messages of zero length
(i.e., no mtext field) are permitted. The mtype field must have a strictly
positive integer value. This value can be used by the receiving process
for message selection (see the description of msgrcv() below).

On failure both functions return -1 with errno indicating the error,
otherwise msgsnd() returns 0 and msgrcv() returns the number of bytes actually
copied into the mtext array.

message queue is provided by the nmb_message_queue_id
msgp points to the user defined buffer
msgsz indicates the size ib bytes of the message read.

The argument msgtyp specifies the type of message requested, as follows:

    If msgtyp is equal to zero, the first message on the queue is received.
    If msgtyp is greater than 0, the first message of type, msgtyp, is received.
    If msgtyp is less than 0, the first message of the lowest type that is less
    than or equal to the absolute value of msgtyp is received.
    If successful, the following actions are taken with respect to the
     data structure, msgiq_ds, associated with msgid:

        msg_qnum is decremented by 1.
        msg_lrpid is set equal to the process ID of the calling process.
        msg_rtime is set equal to the current time.


 */
#include "lib.h"


MessageBuffer dummyMSG(nmb_t nmbid) {
  MessageBuffer msg;
  int p;

}
