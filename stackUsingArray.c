#include<stdio.h>
#include<stdlib.h>
int top = -1;
int size = 10;
int stack[10];
void push(int val){
	if(top == size-1)
		printf("Overflow occured!!\n");
	else{
		top++;
		stack[top] = val;
	}
}
void pop(){ 
	if(top==-1)
		printf("Underflow occured\n");
	else{
		printf("Popped value is: %d\n", stack[top]);
		top--;
	}
}
void display(){
	if(top == -1)
		printf("No stack exist\n");
	else{
		int i = top;
		while(i>=0){
			printf(" %d", stack[i]);
			i--;	
		}
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
