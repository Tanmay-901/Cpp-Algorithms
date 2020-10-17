#include<stdio.h>
#include<conio.h>
int Parent(int);
int Left(int);
int Right(int);
void Heapify(int [],int,int);
void BuildHeap(int [],int);
void HeapSort(int [],int);
void main()
{
int x[20],n,i;
printf("\n Enter number of elements to be sorted");
scanf("%d",&n);
printf("\n Enter %d elements".n);
for(i=0;i<n;i++)
scanf("%d",&x[i]);
HeapSort(x,n);
printf("The sorted array");
for(i=0;i<n;i++)
printf("%4d",x[i]);
}
int Parent(int i){
return(i/2);
}
int Left(int i){
return(2*i+1);
}
int Right(int i){
return(2*i+2);
}
void Heapify(int a[],int i,int n)
{
int i,r,large,temp;
l=Left(i);
r=Right(i);
if((l<=n-1) && (a[l]>a[i]))
large=l;
else
large=i;
if((r<=n-1) && (a[r]>a[large]))
large=r
if(large!=i)
{
temp=a[i];
a[i]=a[large];
a[large]=temp;
Heapify(a,large,n);
}
}
void BuildHeap(int a[],int n){
int i;
for(i=(n-1)/2;i>=0;i--)
Heapify(a,i,n);
}
void HeapSort(int a[],int n){
int i,m,temp;
BuildHeap(a,n);  //Building the max heap
m=n;
for(i=n-1;i>=1;i--)
{
temp=a[0];
a[0]=a[i];
a[i]=temp;
m=m-1;
Heapify(a,0,m);  //Heapifying the remaning elements after removing the topmost element
}
}
