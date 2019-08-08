#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
}*head = NULL;
int count = 0;
void insertBeg(int val){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->next = NULL;
	if(head==NULL){
		head = newNode;
		head->next = head;
		printf("Head Created");
	}
	else{
		struct Node *temp = head;
		while(temp->next!=head)
		      temp=temp->next;
  		temp->next=newNode;
		newNode->next = head;
		head = newNode;		
	}
	count++;
}
void insertEnd(int val){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->next = NULL;
	if(head==NULL){
		head = newNode;
		head->next = head;
		printf("Head Created");
	}
	else{
		struct Node *temp = head;
		while(temp->next!=head)
		      temp=temp->next;
  		temp->next=newNode;
		newNode->next = head;		
	}
	count++;
}
void insertSpecific(int val,int pos){
	if(pos<=1)
		insertBeg(val);
	else if(pos>=count)
		insertEnd(val);
	else{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = val;
		newNode->next = NULL;
		int i = 1;
		struct Node *temp = head;
		while(i<pos-1){
			temp = temp->next;
			i++;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		count++;
	}
}
void deleteBeg(){
	if(head==NULL)
		printf("Empty list, Count = %d\n",count);
	else{
		if(head->next==head){
			head = NULL;
			free(head);
		}
		else{
			struct Node *temp = head;
			while(temp->next!=head)
				temp = temp->next;
			temp->next = head->next;
			temp = head;
			head = head->next;
			free(temp);
		}
		count--;
	}
}
void deleteEnd(){
	if(head==NULL)
		printf("Empty List, Count = %d\n",count);
	else{
		if(head->next==head){
			head= NULL;
			free(head);
		}
		else{
			struct Node *temp = head, *prev;
			while(temp->next!=head){
				prev = temp;
				temp = temp->next;
			}
			prev->next = head;
			free(temp);
		}
	count--;
	}
}
void deleteSpecific(int pos){
	if(pos<=1)
		deleteBeg();
	else if(pos == count)
		deleteEnd();
	else if(pos >=count)
		printf("Deletion not possible");
	else{
		int i = 1;
		struct Node *temp = head, *prev;
		while(i<pos){
			prev = temp;
			temp = temp->next;
			i++;
		}
		prev->next = temp->next;
		free(temp);
		count--;		
	}
}
void display(){
	if(head==NULL)
		printf("Empty List, Count : %d",count);
	else{
		struct Node *temp = head;
		while(temp->next!=head){
			printf(" %d",temp->data);
			temp = temp->next;
		}
		printf(" %d",temp->data);
		printf("\nNo. of Nodes: %d\n",count);
	}
}
int main(){
	int op, choice, val, pos;
	while(1){
		printf("...Menu...(Circular Linked List)\n1.Insertion\t2.Deletion\t3.Display\t4.Exit\tEnter your choice: ");
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
			case 2:printf("Enter the choice for deletion (1.Beginning, 2.End, 3. Specific position): ");
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

