#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct qHead{
	struct node *front;
	int count;
	struct node *rear;
}*q;


void createQueue(struct qHead *q){
	q->front = NULL;
	q->count = 0;
	q->rear  = NULL;
}

void insertToQueue(struct qHead *q, int value){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = value;
	newNode->next = NULL;
	
	if(q->count == 0){
		q->front = newNode;
		q->rear  = newNode;
	}
	else{
		q->rear->next = newNode;
		q->rear = newNode;
	}
	q->count += 1;
}

void deletefromQueue(struct qHead *q){
	if(q->count == 0){
		printf("\nUnderflow\n");
	}
	else{
		struct node *temp;
		temp = q->front;
		q->front = q->front->next;
		printf("Value To Be Deleted : %d\n", temp->data);
		q->count -= 1;
		free(temp);
	}
}

void peek(struct qHead *q){
	if(q->count == 0){
		printf("\nQueue is Empty\n");
	}
	else{
		printf("The first value at front of the queue: %d", q->front->data);
	}
}

void display(struct qHead *q){
	if(q->count == 0){
		printf("\nQueue is Empty\n");
	}
	else{
		struct node *current;
		current = q->front;
		puts(" ");
		while(current != q->rear){
			printf("%d\t", current->data);
			current = current->next;
		}
		printf("%d\t", current->data);
	}
}


int main(){
	
	int deger, option;
	q = (struct qHead*) malloc(sizeof(struct qHead));
	
	createQueue(q);

	do
	{
	 printf("\n *****MAIN MENU*****");
	 printf("\n 0. COUNT");
	 printf("\n 1. INSERT");
	 printf("\n 2. DELETE");
	 printf("\n 3. PEEK");
	 printf("\n 4. DISPLAY");
	 printf("\n 5. EXIT");
	 printf("\n Enter your option : ");
	 scanf("%d", &option);
	
	switch(option)
	{
	
	case 0:
		 printf("\n Number of elements in the queue = %d \n",  q->count);
		 break;
	case 1:
		 printf("\n Enter the number to insert in the queue:");
		 scanf("%d", &deger);
		 insertToQueue(q,deger);
		 break;
	case 2:
		 deletefromQueue(q);
		 break;
	case 3:
		 peek(q);
		 break;
	case 4:
		 display(q);
		 break;
	}
	}while(option != 5);

	return 0;
	
}










