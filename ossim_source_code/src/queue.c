#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
    if(q->size < MAX_QUEUE_SIZE){
    	q->proc[size++] = proc;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
    if(q->size == 0) return NULL;
    struct pcb_t* pcb = NULL;
    int i;
    int m = -1;
    for(i=0;i<q->size;i++){
    	if(pcb==NULL){
    		pcb = (q->proc[i]);
    		m = i;
		}
		else{
			if(q->proc[i]->prio < pcb->prio){
				m = i;
				pcb = (q->proc[i]);
			}
		}
	}
    for(;m<q->size-1;m++){
    	q->proc[m] = q->proc[m+1];
	}
	q->proc[size-1] = NULL;
	size--;
	return pcb;
}

