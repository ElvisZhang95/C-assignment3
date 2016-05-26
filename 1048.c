/*
	80755 Accepted to 1048.c
	Name: Shuhao Zhang  Id:201138949 x5sz2
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

//define the structure of node
typedef struct date
{
	//for storing the month from input
	//constant is 10, because the number of letters of each month is no more than 10
	char month[10];
	//month in number
	int monnum;
	int day;
	int year;
} date;
//the method used in qsort and bsearch
int cmp(const void* first, const void* second);
//the method for transfering month from string to number
int countMonth(char* month, char* montharr[]);

int main(){
	//number of date
	int input;
	//storing all the month
	char* montharr[]={"January", "February", "March", "April", "May", "June", "July", 
		"August", "September", "October", "November", "December"};
	//the month that input
	//constant is 10, because the number of letters of each month is no more than 10
	char m[10];
	//the day and the year
	//i is used in the for loop
	int mon,d,y,i;
	//get the input
	scanf("%d",&input);
	//allocate memory for storing dates
	date* array = (date*)malloc(sizeof(date)*input);
	//add the date to the array
	for(i=0;i<input;i++){
		scanf("%s %d %d",m, &d, &y);
		strcpy(array[i].month,m);
		array[i].day=d;
		array[i].year=y;
		array[i].monnum=countMonth(array[i].month, montharr);
	}
	//sort the array
	qsort(&array[0],input,sizeof(date),cmp);
	//get the date of query
	scanf("%d %d %d", &mon,&d,&y);
	//construct new date for search
	date* a=(date*)malloc(sizeof(date));
	a->day=d;
	a->year=y;
	a->monnum=mon;
	date* answer=(date*)bsearch(a,&array[0],input,sizeof(date),cmp);
	//print out sorted dates in suitable format
	for(i=0;i<input;i++){
		if(array[i].year<10){
			printf("%s %d 0%d\n",array[i].month,array[i].day,array[i].year);
		}else{
			printf("%s %d %d\n",array[i].month,array[i].day,array[i].year);
		}
	}
	//print out the answer for query
	if(answer!=NULL){
		printf("Yes");
	}else{
		printf("No");
	}
	//release the memory
	free(array);
	free(a);
	return 0;
}
int cmp(const void* first, const void* second){
	const date* a=first;
	const date* b=second;
	//compare the dates if the year of date between 90-99
	if((a->year >=90) && (b->year >=90)){
 		if((a->year) == (b->year)){
 			if((a->monnum) == (b->monnum)){
 				if((a->day) == (b->day)){
 				 return 0;
 				}
 				else{
 				return (b->day)-(a->day);
 				}
 				return (b->monnum)-(a->monnum);
 			} 
 		}else{ 
 		return (b->year)-(a->year);
 		}
 	}
	//compare the dates if one is 90-99 another is 00-12
 	if((a->year >=90) && (b->year <90)){
 		return 1;
 	}
 	if((a->year < 90) && (b->year >=90)){
 		return -1;
 	}
	
	//compare the dates if the year of date between 00-12
 	if((a->year <90) && (b->year <90)){
 		if((a->year) == (b->year)){
 			if((a->monnum) == (b->monnum)){
 				if((a->day) == (b->day)){
 					return 0;
 				}else{
 					return (b->day)-(a->day);
 				}

 			}else{
 				return (b->monnum)-(a->monnum);
 			}
 		}else{
 			return (b->year)-(a->year);
 		}
 	}				
	return 0;
}
//transfer the month from string to number
int countMonth(char* month, char* montharr[]){
	int i;
	for(i=0;i<12;i++){
		if(strcmp(month,montharr[i])==0){
			return i+1;
		}
	}
	return -1;
}