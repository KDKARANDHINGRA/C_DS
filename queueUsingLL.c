#include<stdio.h>
#include<stdlib.h>
const int size = 10;
int n = 0;
struct Node{
	int data;
	struct Node *link
};
struct Node *front = NULL;
struct Node *rear = NULL;
void enqueue(int val){
	if(n>=size){
		printf("Overflow Occured\n");
		return;
	}
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->link = NULL;
	if(rear==NULL){
		rear = newNode;
	       	front = newNode;
	}
	else{
		rear->link = newNode;
		rear = newNode;
	}
	n++;
}
void dequeue(){
	if(front==NULL || n == 0){
		printf("Empty queue!!\n");
		rear = front;
	}
	else{
		printf("Dequeued element is: %d\n",front->data);
		struct Node *temp = front;
		front = front->link;
		free(temp);
		n--;
	}
}
void display(){
	if(front==NULL){
		printf("Empty queue!!\n");
		rear = front;
	}
	else{
		struct Node *temp = front;
		while(temp != NULL){
			printf("%d <--",temp->data);
			temp = temp->link;
		}
		printf("NULL\n");
	}
}
int main(){
	int val, op;
	while(1){
		printf("Select the operation to be performed (1.Enqueue, 2.Dequeue, 3.Display, 4.Exit): ");
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
			default:printf("Enter the correct operation!!\n");
		}
	}
	return 1;
}
