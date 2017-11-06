#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node* insert(struct node *root,int data)
{
if(root==NULL)
{
root=(struct node*)malloc(sizeof(struct node));
root->data=data;
root->left=NULL;
root->right=NULL;
return root;
}
if(data<root->data)
{
  root->left=insert(root->left,data);
return root;
}
if(data>=root->data)
{
root->right=insert(root->right,data);
return root;
}
}
struct node* del(struct node* root,int data)
{
int larg;
if(root==NULL)
{
printf("NOT FOUNd");
return NULL;
}
else if(data<root->data)
{
root->left=del(root->left,data);
return root;
}
else if(data>root->data)
{
root->right=del(root->right,data);
return root;
}
else
{
if(root->left==NULL)
return root->right;
else if(root->right==NULL)
return root->left;
else
{
larg=largest(root->left);
root->data=larg;
root->left=del(root->left,larg);
return root;
}
}
}
void search(struct node* root,int data,int height)
{
if(root==NULL)
{
printf("element not found");
}
else if(data<root->data)
{
search(root->left,data,height+1);
}
else if(data>root->data)
{
search(root->right,data,height+1);
}
else
printf("elment is found at %d heaight",height);
}
int largest(struct node *head)
{
if(head->right==NULL)
return head->data;
else
return largest(head->right);
}
int main()
{
int data,ch;
struct node *ogl=NULL;
printf("1.insert an element \t 2.delete\t3.search \t 4.largest");
printf("enter a valid choice");
scanf("%d",&ch);
while(ch<=4){
switch(ch)
{
case 1:
printf("enter an element to insert");
scanf("%d",&data);
ogl=insert(ogl,data);
break;
case 2:
printf("enter an element to delete \n");
scanf("%d",&data);
ogl=del(ogl,data);
break;
case 3:
printf("enter element to be searched");
scanf("%d",&data);
search(ogl,data,1);
break;
case 4:
data=largest(ogl);
printf("largest data %d",data);
break;
     default:
	break;
}
printf("\nenter a valid choice");
scanf("%d",&ch);
}
return 0;
}
