#include<stdio.h>
#include<stdlib.h>
int size = 2;
int front = -1;
int rear = -1;
int queue[2];
void enqueue(int val){
	if(rear == size-1)
		printf("Overflow Occured\n");
	else{
		if(front==-1)
			front=0;
		queue[++rear] = val;
	}
}
void dequeue(){
	if(front==-1 || front>rear){
		printf("Underflow Occured!\n");
		front = -1;
		rear = -1;
	}
	else{
		printf("Element deleted from queue is: %d\n",queue[front++]);
	}
}
void display(){
	if(front == -1||front>rear)
		printf("Empty Queue");
	else{
		printf("Elements in queue are: ");
		for(int i = front;i<=rear;i++)
			printf("%d ",queue[i]);
	}
	printf("\n");
}
int main(){
	int op, choice, val;
	while(1){
		printf("Enter the operation to be performed (1.Enqueue, 2.Dequeue, 3.Display, 4.Exit): ");
		scanf("%d",&op);
		switch(op){
			case 1: printf("Enter the value to be enqueued: ");
				scanf("%d",&val);
				enqueue(val);
				break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			case 4: exit(1);
				break;
			default:printf("Enter correct choices!!\n");
		}
	}
}
