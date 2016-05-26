/*
	80860 Accepted to 1050.c
	Name: Shuhao Zhang	Id: 201138949 x5sz2
*/

#include <stdio.h>
#include <stdlib.h>
//define the structure of node
struct node
{
	//store the id of city
	int num;
	struct node* next;
};

//used to create new node(for building the city)
struct node* create_node(int num);
//used to create the lines between two cities
void add_node(struct node* num,struct node* add);
//method for searching the answer
int search_link(int a, int b, struct node* array[],int city);

int main(){
	//city and link is the integer that user input
	int city;
	int link;
	//store the pair of two city
	int a,b;
	//store the answer of search
	int result;
	scanf("%d", &city);
	scanf("%d", &link);
	//construct array to store the cities
	struct node* array[city];
	int k;
	//create all the cities
	//each city is the head of a linkedlist
	for(k=1;k<=city;k++){
		array[k]=create_node(k);
	}
    int i;
    //add the lines between cities
	for(i=0;i<link;i++){
		scanf("%d %d",&a,&b);
		//only add the larger number(city) of pair to the small number(city)
		//like add node to the linkedlist
		if(a<=b){
		struct node* temp=create_node(b);
		add_node(array[a],temp);
		}else{
		struct node* temp=create_node(a);
		add_node(array[b],temp);
	}
	}
	//input the query
	scanf("%d %d",&a,&b);
	//get the answer by method "search_link"
	result=search_link(a,b,array,city);
	
	if(result==1){
		printf("Yes");
	}
	if(result==0){
		printf("No");
	}

	//release memory to avoid memory leak
	for(k=1;k<=city;k++){
		
		while(array[k]->next!=NULL){
			array[k]=array[k]->next;
			free(array[k]);
		}
	}

	return 0;

}

//allocate memory and construct a new node
struct node* create_node(int num){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->num = num;
	new_node->next=NULL;
    return new_node;
}
//add new node to the linked list
void add_node(struct node* num ,struct node* add){
	struct node* temp =num;
	while(temp->next!=NULL){
		temp=temp->next;
		if(temp->num == add->num){
			return;
		}
	}
	temp->next = add;
}

//using the breadth-first search to find the result
int search_link(int a, int b,struct node* array[], int city){
	 struct node* temp = array[a];
	
	//find this linked list
	 while(temp->next !=NULL){
	 	temp=temp->next;
	 	//if find the answer, return 1
	 	if(temp->num==b){
	 		return 1;
	 	}		
	 	}
	 //move the pointer to the head of the linkedlist
	 temp = array[a];
	 while(temp->next!=NULL){
	 
	 temp=temp->next;
	 //start to find another linkedlist that start from the next node in this linkedlist
	 if(search_link(temp->num, b, array, city)==0){
		 
		 }else{
			 return 1;
			 }
	 }
	 return 0;
}