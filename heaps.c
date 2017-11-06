#include<stdio.h>
#include<stdlib.h>
void reheapup(int *a,int index)
{
if(index!=0)
{
int parent=(index-1)/2;
if(a[parent]<a[index])
{
int temp=a[parent];
a[parent]=a[index];
a[index]=temp;
reheapup(a,parent);
}
}
}
void reheapdown(int *a,int i,int last)
{
int rightkey,leftkey,largest;
if((2*i+1)<=last)
{
leftkey=a[2*i+1];
if((2*i+2)<=last)
rightkey=a[2*i+2];
else
rightkey=-1;
if(leftkey>=rightkey)
largest=(2*i+1);
else
largest=(2*i+2);
if(a[i]<a[largest])
{
 int temp=a[i];
a[i]=a[largest];
a[largest]=temp;
reheapdown(a,largest,last);
}
}
}
void buildheap(int *a,int last)
{
int i;
for(i=0;i<=last;i++)
{
reheapup(a,i);
}
}
void insert(int *a,int data,int last)
{
a[last+1]=data;
reheapup(a,last+1);
}
void delete(int *a,int last)
{
a[0]=a[last];
reheapdown(a,0,last-1);
}
void heapsort(int *a,int last)
{
buildheap(a,last);
int temp;
while(last!=0)
{
temp=a[0];
a[0]=a[last];
a[last]=temp;
last--;
reheapdown(a,0,last);
}
}
void display(int *a,int last)
{
int i;
for(i=0;i<=last;i++)
printf("%d\t",a[i]);
}
void main()
{
int *a;
int n,k,last=-1,ch,data;
a=(int*)malloc(100*sizeof(int));
printf("enter choice1.heap\t2.heapsort");
scanf("%d",&k);
if(k==1)
{
printf("\nenter choice1.insert\t2.delete");
scanf("%d",&ch);
while(ch==1 ||ch==2)
{
if(ch==1)
{
printf("\nenter data");
scanf("%d",&data);
insert(a,data,last);
last++;
display(a,last);
}
if(ch==2)
{
delete(a,last);
last--;
display(a,last);
}
printf("\nenter choice1.insert\t2.delete");
scanf("%d",&ch);
}
}
if(k==2)
{
int size,i;
printf("enter size");
scanf("%d",&size);
for(i=0;i<size;i++)
{
scanf("%d",&a[i]);
}
heapsort(a,size-1);
display(a,size-1);
}
}
