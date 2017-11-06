#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node* insert(struct node *head,int data)
{
	 struct node *temp1;
	if(head==NULL)
     { 
     head=(struct node*)malloc(sizeof(struct node));
	 head->data=data;
	 head->next=NULL;
	 return head;
	 }
     else
     {
     	struct node *temp;
     	temp=(struct node*)malloc(sizeof(struct node));
	    temp->data=data;
	    temp->next=NULL;
	    temp1=head;
	    while(temp1->next!=NULL) temp1=temp1->next;
	    head->next=temp;
	     return head;
	 }
}
	struct node* delete(struct node *head)
	{
	if(head==NULL)

	printf("list is empty");

else{
		struct node *temp;
		temp=head;
		head=head->next;
		free(temp);
		return head;
	}
}
void search(struct node *head,int data)
{
while(head!=NULL)
{
	if(head->data==data)
	{
	printf("element found");
return;
	}
	head=head->next;
}
printf("element found");
}
void display(struct node *head)
{
while(head!=NULL)
{
	
printf("%d\t",head->data);
head=head->next;
}
printf("\n");

}
int main()
{
int data,ch;
struct node *ogl=NULL;
printf("1.insert an element \t 2.delete\t3.search \t 4.display");
printf("enter a valid choice");
scanf("%d",&ch);
while(ch<=4){
switch(ch)
{
case 1:
printf("enter an element to insert");

scanf("%d",&data);
ogl=insert(ogl,data);
display(ogl);
break;
case 2:
printf("before deletion \n");
display(ogl);
ogl=delete(ogl);
printf("\nafter deletion \n");
display(ogl);
break;
case 3:
printf("enter element to be searched");
scanf("%d",&data);
search(ogl,data);
break;
case 4:
display(ogl);
break;
     default:
	break;
}
printf("\nenter a valid choice");
scanf("%d",&ch);
}
return 0;
}
