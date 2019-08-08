#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
}*head = NULL;
int count = 0;
void insertBeg(int val){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	if(head==NULL){
		head = newNode;
		printf("Head Created\n");
	}
	else{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	count++;
}
void insertEnd(int val){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	if(head==NULL){
		head = newNode;
		printf("Head Created\n");
	}
	else{
		struct Node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		newNode->prev = temp;
		temp->next = newNode;
	}
	count++;
}
void insertSpecific(int val,int pos){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	if(head==NULL){
		head = newNode;
		printf("Head Created\n");
	}
	else{
		struct Node *temp = head;
		int i = 1;
		while(temp->next != NULL && i<pos){
			temp = temp->next;
			i++;
		}
		if(temp->next==NULL && i!=pos){
			temp->next = newNode;
			newNode->prev = temp;
		}
		else{
			newNode->next = temp;
			newNode->prev = temp->prev;
			if(temp->prev!=NULL)
				temp->prev->next = newNode;
			else
				head = newNode;
			temp->prev = newNode;
		}
	}
	count++;
}
void deleteBeg(){
	if(head==NULL)
		printf("Empty list\n");
	else if(head->next==NULL){
		head = NULL;
		free(head);
		count--;
	}
	else{
		struct Node *temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
		count--;
	}
}
void deleteEnd(){
	if(head==NULL)
		printf("Empty list\n");
	else if(head->next==NULL){
		head==NULL;
		free(head);
		count--;
	}
	else{
		struct Node *temp = head;
		while(temp->next!=NULL)
			temp = temp->next;
		temp->prev->next = NULL;
		free(temp);
		count--;
	}
}
void deleteSpecific(int pos){
	if(head==NULL)
		printf("Empty List\n");
	else if(pos>count)
		printf("Deletion Not Possible\n");
	else{
		int i = 1;
		struct Node *temp = head;
		while(temp->next!=NULL && i<pos){
			temp= temp->next;
			i++;
		}
		if(temp->prev==NULL){
			if(temp->next == NULL)
				head = NULL;
			else{
				head = temp->next;
				head->prev = NULL;
			}
		}
		else
			temp->prev->next = temp->next;
		if(temp->next!=NULL)
			 temp->next->prev = temp->prev;
		free(temp);
		count--;
	}
}
void display(){
	if(head == NULL)
		printf("Empty List: Count = %d",count);
	else{
		struct Node *temp = head;
		while(temp!=NULL){
			printf(" %d",temp->data);
			temp = temp->next;	
		}	
	}
	printf("\nNo. of nodes: %d\n",count);
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
				       default: printf("Enter the correct choices!!\n");
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
				       default:printf("Enter the correct choices!!\n");
			       }
			       break;
			case 3:display();
			       break;
			case 4:printf("\nExiting!!\n");
			       exit(1);
			       break;
			default:printf("Enter the correct operation code!!\n");
		}
	}
	return 1;
}
