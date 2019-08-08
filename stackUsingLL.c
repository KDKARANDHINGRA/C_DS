#include<stdio.h>
#include<stdlib.h>
int max_size = 10;
int size = 0;
struct Node {
	int data;
	struct node *link;
};
struct Node *head = NULL;
struct Node *top = NULL;
void push(int val){
	if( size == max_size){
		printf("Overflow Occured");
		return;
	}
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->link = NULL;
	if(head == NULL){
		head = newNode;
		top = newNode;
	}
	else{
		top->link = newNode;
		top = newNode;
	}
	size++;
}
void pop(){
	if(top == NULL || size == 0){
		printf("Underflow Occured");
		return;
	}
	if(head->link == NULL){
		printf("%d\n",top->data);
		top = NULL;
		head = NULL;
	}
	else{
		struct Node *prev = head;
		struct Node *next = head;
		while(next->link != NULL){
			prev = next;
			next = next->link;
		}
		prev->link = NULL;
		printf("%d\n",top->data);
		top = prev;
		free(next);
	}
	size--;
}
void display(){
	if(head==NULL){
		printf("\nNo stack exist!\n");
		return;
	}
	struct Node *temp = head;
	while(temp != NULL){
		printf("%d <--",temp->data);
		temp = temp->link;
	}
}
int main(){
	int op, val;
	while(1){
	printf("Enter the choice of operation (1. Push, 2.Pop, 3.Display, 4.Exit): ");
	scanf("%d",&op);
	switch(op){
		case 1: printf("Enter the value to be pushed: ");
			scanf("%d",&val);
			push(val);
			break;
		case 2: pop();
			break;
		case 3: printf("Elements in stack are: ");
			display();
			printf("\n");
			break;
		case 4: exit(0);
			break;
		default:printf("Enter the correct choice!!\n");
	}
	}
	return 1;
}
