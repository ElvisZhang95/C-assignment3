/*
	80794 Accepted to 1053.c
	Name: Shuhao Zhang	Id: 201138949 x5sz2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define the structure of node
typedef struct node
{
	struct node *next;
	int data;
}node;

struct node *head=NULL;
struct node *tail=NULL;
//method used to push element to stack
void push_node(int num);
//pop the top element
int pop_node();

int main()
{
	//two string for comparing the user's input
	char *s1="Push";
	char *s2="Pop";
	//store user's input
	//constant is 10, because the number of letters of the operation is no more than 10
	char s[10];
	//integer is the number that user input
	int integer;
	//answer is the value of popped node
	int answer;
		//receive commands until EOF
		while(scanf("%s",s)!=EOF){
		if(strcmp(s1,s)==0)
    	{
    		//recognize the operations
    		scanf("%d",&integer);
    		push_node(integer);
    	}
    	if(strcmp(s2,s)==0)
    	{
    		answer=pop_node();
			printf("%d popped\n",answer);
    	}

    	
	}
	//avoid memory leak and free the memory
	while(head!=NULL){
		pop_node();
	}


	return 0;
}
//push new node to the top of stack
void push_node(int num)
{
	//allocate memory for new node
	node* new_node = (node*)malloc(sizeof(node));
	//add data to the new node
	new_node->data=num;
	new_node->next=NULL;
	//if the stack is empty
	if(tail==NULL)
	{
		head=tail=new_node;
		printf("%d pushed\n",num);
	}else{
		//add the head of the linked list
		new_node->next=head;
		head= new_node;
	
		printf("%d pushed\n",num);
	}
}

//popped the top node of stack
int pop_node()
{
	//store the value of top node
	int number;
	//if the stack is empty
	if(head==NULL){
		number= -1;
	}else{
	//get the value of top element in stack
	node* remove_node =head;
	number =head -> data;
	//if there is only one element in the stack
	if(head==tail)
	{
		head=tail=NULL;
	}else
	{
		//remove the element
		head = head->next;
	}
	//release the memory
	free(remove_node);
}

	
	return number;
}