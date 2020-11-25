#include <stdio.h>
#include <stdlib.h>
void pop(),push(char),display();
char stack[100]="\0";
char inputbuffer[100];
int top=-1;
char *ip;
void main(){
	printf("E -> E + E\n");
	printf("E -> E * E\n");
	printf("E -> (E)\n");
	printf("E -> d\n");
	printf("Enter the input string followed by $ \n");
	scanf("%s",inputbuffer);
	ip = inputbuffer;
	push('$');
	printf("STACK\t BUFFER \t ACTION\n");
	printf("-----\t ------ \t ------\n");
	display();
	do{
		if((stack[top] == 'E' && stack[top-1] == '$') && (*(ip)=='$'))
		break;
		if(stack[top] == '$'){
			push(*ip);
			ip++;
			printf("\tShift");
		}
		else if(stack[top]=='d'){
			display();
			pop();
			push('E');
			printf("\tReduce E -> d\n");
		}
		else if(stack[top] == 'E' && stack[top-1] == '+' && stack[top-2] == 'E' && *ip != '*'){
			display();
			pop();
			pop();
			pop();
			push('E');
			printf("\tReduce E -> E + E");
		}
		else if(stack[top] == 'E' && stack[top-1] == '*' && stack[top-2] == 'E'){
			display();
			pop();
			pop();
			pop();
			push('E');
			printf("\tReduce E -> E * E");
		}
		else if(stack[top] == ')' && stack[top-1] == 'E' && stack[top-2] == '('){
			display();
			pop();
			pop();
			pop();
			push('E');
			printf("\tReduce E -> (E)");
		}
		else{
			display();
			push(*ip);
			ip++;
			printf("\tShift");
		}
	}while(1);
	display();
	printf("\tAccept\n\n\n");
}

void push(char c){
	top++;
	stack[top]=c;
}

void pop(){
	stack[top] = '\0';
	top--;
}

void display(){	
	printf("\n%s \t %s \t",stack,ip);
}
