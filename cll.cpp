#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node* insert(struct node *head,int data)
{
if(head==NULL)
{
head=(struct node*)malloc(sizeof(struct node));
head->data=data;
head->next=head;
return head;
}
else
{
struct node *temp;
struct node *temp2;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->next=head;
temp2=head;
while(temp2->next!=head)
{
temp2=temp2->next;
}
temp2->next=temp;
return temp;
}
}
struct node* del(struct node *head)
{
struct node *temp,*temp2;
if(head==NULL)
{
	printf("LIST IS EMPTY");
return NULL;
}
else if(head->next==head)
{

	free (head);
return NULL;
}
else
{
temp=head;
head=head->next;
temp2=head;
while(temp2->next!=temp)
{
temp2=temp2->next;
}
temp2->next=head;
free(temp);
return head;
}
}
void search(struct node *head,int data)
{
struct node *temp;
head=temp;
if(head==NULL)
printf("list is empty");
while(temp->next!=head)
{

	if(temp->data==data){
	
	printf("ELEMENT FOUND"); return;}
}
	if(temp->data==data){
	printf("ELEMENT FOUND");return;}
		printf("element not found");

	return;
}
void display(struct node *head)
{
struct node *temp;
temp=head;
while(temp->next!=head)
{
printf("%d \t",temp->data);
temp=temp->next;
}
printf("%d \t",temp->data);
}
int main()
{
int data,ch;
struct node *ogl=NULL;
printf("1.insert an element \t 2.delete\t3.search \t 4.display");
printf("enter a valid choice");
scanf("%d",&ch);
while(ch<=4)
{
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
ogl=del(ogl);
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
