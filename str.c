#include<stdio.h>
#include<stdlib.h>
struct node{
	char ch[20];
	struct node *next;
};
struct node* insert(struct node *head,char buffer[20],int length){
	int k;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
			
			for(k=0;k<length;k++){
				temp->ch[k]=buffer[k];
			}
			temp->next=NULL;
			temp->next=head;
			return temp;
			
		}	
struct node* prepareList(char ch[100]){
	char buffer[20];
	int i,k,j=0;
	struct node *head=NULL;
	struct node *temp;
	for(i=0;ch[i]!='\0';i++){
		if(ch[i]!=' '){
		buffer[j++]=ch[i];
		}
		else{
			buffer[j++]='\0';
			head=insert(head,buffer,j);
			j=0;
		}
	}
	buffer[j++]='\0';
		head=insert(head,buffer,j);
	return head;
	 
}
void Print(struct node *temp){

	if(temp!=NULL){
		
	    
		printf(" %s ",temp->ch);
		Print(temp->next);
		
	}
}
int main(){
	char ch[100];
	struct node *head;
	gets(ch);
	head=prepareList(ch);
	Print(head);
	
}
