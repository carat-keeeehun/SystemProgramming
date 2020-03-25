#include <stdio.h>
#include "LRU.h"

//This function makes new node contatining item_.
//It will return the new node.
Node* newNode(int item_) {
    //TODO
	Node *N = (Node*)malloc(sizeof(Node));
	N->item = item_;
	N->next = NULL;
	N->prev = NULL;
	return N;
}

//This function makes new empty queue with size.
//It will return empty queue which can contain items up to size.
Queue* createQueue(int size) {
    //TODO
	Queue *qq = (Queue*)malloc(sizeof(Queue));
	qq->queue_size = size;
	qq->count_ = 0;
	qq->head = NULL;
	qq->tail = NULL;
	return qq;
}

//This function will check whether queue is empty or not.
int isQueueEmpty(Queue* queue_) {
    //TODO
	if(queue_->count_==0) return 1;
	else return 0;
}

//This function will remove last element(tail) in queue_.
void DeQueue(Queue* queue_) {
    //TODO
	Queue *qd = queue_;
	qd->tail = qd->tail->prev;
	qd->tail->next = NULL;
	qd->count_--;
}

//This function roles add the node containing item_ in queue_ at head.
void EnQueue(Queue* queue_, int item_) {
    //TODO
	Queue *qe = queue_;
	Node *Ae = newNode(item_);
	Ae->next = qe->head;
	qe->head->prev = Ae;
	qe->head = Ae;
}

//This function mention item_ in queue. So the queue should be modified along LRU.
//If item_ is not in queue, it should be added,
//If item_ is in queue_, it should be placed in front of queue_.
void Reference(Queue* queue_, int item_) {
    //TODO
	Queue *qr = queue_;
	Node *Ar = newNode(item_);
	int check = 1;

	if(isQueueEmpty(qr)){
		qr->head = Ar;
		qr->tail = Ar;
		qr->count_++;}
	else{
		Node *temp = qr->head;
		while(1){
		    if(item_==temp->item){
			if(check==1){
			    qr->head = temp->next;
			    temp->next->prev = NULL;
			    temp->next = NULL;}
			else if(check==qr->count_){
			    qr->tail = temp->prev;
			    temp->prev->next = NULL;
			    temp->prev = NULL;}
			else{
			    temp->prev->next = temp->next;
			    temp->next->prev = temp->prev;}
			qr->count_--;
			break;}
		    if(check==qr->count_) break;
		    temp = temp->next;
		    check++;}
		EnQueue(qr,item_);
		qr->count_++;
		if(qr->count_>qr->queue_size) DeQueue(qr);}
}

//This function clear the queue_.
void ClearQueue(Queue* queue_) {
    //TODO
	Queue *qc = queue_;
	Node *temp = qc->head;
	int check = 1;
	
	while(check <= qc->count_){
		if(check<qc->count_) temp = temp->next;
		free(qc->head);
		qc->head = temp;
		check++;}
	free(qc);
}

void PrintQueue(Queue* queue_) {
    Node* it = queue_->head;
    int index = 0;
    printf("------------------------\n");
    printf("Queue size : %d\n", queue_->count_);
    printf("Queue capacity : %d\n", queue_->queue_size);
    while (it != NULL) {
        printf("Queue %d Element : %d\n", index, it->item);
        index++;
        it = it->next;
    }
    printf("------------------------\n");
}
