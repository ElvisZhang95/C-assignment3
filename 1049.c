/*
	80833 Accepted to 1049.c
	Name: Shuhao Zhang  Id: 201138949 x5sz2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//define the structure of node
struct node
{
	int data;
	int priority;
	struct node* next;
};
struct node* head=NULL;
struct node* prev = NULL;

//method used to insert node
void insert_node(int data, int priority);
int pop_node();

int main(){
	//two string for comparing the user's input
	char *s1="Insert";
	char *s2="Pop";
	//store user's input
	//constant is 10, because the number of letters of the operation is no more than 10
	char s[10];
	//integer is the number that user insert
	//priority is the priority of inserted node
	int integer;
	int priority;
	//answer is the value of popped node
	int answer;
	//reveive commands until EOF
	while(scanf("%s",s)!=EOF)
	{	
		//recognize the operations
		if(strcmp(s1,s)==0)
		{
			scanf("%d %d",&integer,&priority);
			insert_node(integer,priority);
		}
		if(strcmp(s2,s)==0)
		{
			answer=pop_node();
			printf("%d\n",answer);
		}
	}
	//avoid memory leak and free the memory
	while(head!=NULL){
		pop_node();
	}

	return 0;
}

//insert new node to the priority queue
//arrange elements in queue from high priority to low priority
void insert_node(int data, int priority)
{
	struct node* temp = head;

	//allocate memory for new node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	//add data to the new node
	new_node->data=data;
	new_node->priority=priority;

	//if the queue is empty
	if(head==NULL)
	{
		new_node->next=NULL;
		head=new_node;
		
	}else{
		
		//find the suitable position for new node based on the priority
		while(temp!=NULL){
		
			if(temp->priority>=priority)
			{
				prev=temp;
				temp=temp->next;
				

			}else{
				//add new node to the head of queue
				if(temp==head)
				{
					new_node->next =temp;
					head = new_node;
				}else{
					//add new node between two nodes
					prev->next=new_node;
					new_node->next =temp;
				}
				
			return;
			}
		}
		//add to the end of queue
		prev->next = new_node;
		new_node->next=NULL;
	}
}

//pop the highest priority element in the queue
int pop_node(){
	//store the value of removed node
	int number;
	struct node* temp=head;
	
	if(temp!=NULL)
	{
		//get the value of the first node
		number = head->data;
		//if there is onli one node in the queue
		if(head->next==NULL){
		head=NULL;
		}else{
		//remove node
		head = temp->next;
		}
	}else{
	//if the queue is empty
	number=-1;
	}
	//release the memory
	free(temp);

	return number;
}


