#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct Node {
	int data;
	struct Node *link;
}*head = NULL;
void insertBeg(int val){
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	if(head == NULL)
		printf("Head created");
	newNode->link = head;
	head = newNode;
	count++;
}
void insertEnd(int val){
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->link = NULL;
	if(head == NULL){
		head = newNode;
		printf("Head Created\n");
	}
	else{
		struct Node *temp = head;
		while(temp->link != NULL)
			temp = temp->link;
		temp->link = newNode;
	}
	count++;
}
void insertSpecific(int val,int pos){
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	if(pos<=1){
		if(head==NULL){
			head = newNode;
			printf("Head created");
		}
		else{
			newNode->next = head;
			head = newNode;
		}
	}
	else{
	int i = 1;
	struct Node *temp = head;
	while(temp->link != NULL && i < pos){
		temp = temp->link;
		i++;
	}
	newNode->link = temp->link;
	temp->link = newNode;
	}
	count++;
}
void deleteBeg(){
	if(head == NULL)
		printf("No list exist!");
	else if(head->link==NULL){
		head = NULL;
		free(head);
		count--;
	}
	else{
		struct Node *temp = head;
		head = temp->link;
		free(temp);
		count--;
	}
}
void deleteEnd(){
	if(head == NULL)
		printf("No list exist!");
	else if(head->link == NULL){
		head = NULL;
		free(head);
		count--;
	}
	else{
		struct Node *prev = head;
		struct Node *next = head;
		while(next->link != NULL){
			prev = next;
			next = next->link;
		}
		prev->link = NULL;
		free(next);
		count--;
	}
}
void deleteSpecific(int pos){
	if(head == NULL)
		printf("No list exist!");
	else if(pos > count)
		printf("Deletion not possible");
	else if(pos <= 1){
		if(head->link==NULL){
			head = NULL;
			free(head);
		}
		else{
			struct Node *temp = head;
			head = head->link;
			free(temp);
		}
		count--;
	}
	else{
		struct Node *prev = head;
		struct Node *next = head;
		int i = 1;
		while(next->link != NULL && i<pos){
			prev = next;
			next = next->link;
			i++;
		}
		prev->link = next->link;
		free(next);
		count--;
	}
}
void display(){
	if(head==NULL){
		printf("\nNo list exist!\n");
		return;
	}
	struct Node *temp = head;
	while(temp != NULL){
		printf("%d -->",temp->data);
		temp = temp->link;
	}
	printf("NULL\nNo. of Nodes : %d\n",count);
}
int main(){
	int op, choice, val, pos;
	while(1){
		printf("...Menu...\n1.Insertion\t2.Deletion\t3.Display\t4.Exit\tEnter your choice: ");
		scanf("%d",&op);
		switch(op){
			case 1:printf("Enter the value to be inserted: ");
			       scanf("%d",&val);
			       printf("Enter choice for insertion (1. Beginning, 2. End, 3. Specific position): ");
			       scanf("%d",&choice);
			       switch(choice){
				       case 1: insertBeg(val);
					       break;
				       case 2: insertEnd(val);
					       break;
				       case 3: printf("Enter the specific position for insertion: ");
					       scanf("%d",&pos);
					       insertSpecific(val,pos);
					       break;
				       default: printf("Enter the correct choices!!");
			       }
			       break;	       
			case 2:printf("Enter the choice for deletion: (1.Beginning, 2.End, 3. Specific position)");
			       scanf("%d",&choice);
			       switch(choice){
				       case 1: deleteBeg();
				       	       break;
				       case 2: deleteEnd();
					       break;
				       case 3: printf("Enter the specific position for deletionn: ");
				       	       scanf("%d",&pos);
					       deleteSpecific(pos);
					       break;
				       default:printf("Enter the correct choices!!");
			       }
			       break;
			case 3:display();
			       break;
			case 4:printf("\nExiting!!\n");
			       exit(1);
			       break;
			default:printf("Enter the correct operation code!!");
		}
	}
	return 1;
}
