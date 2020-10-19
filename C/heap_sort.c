#include<stdio.h>
#include<conio.h>
int Parent(int); //Declareing parent node
int Left(int);	//Declaring Left Node
int Right(int);		//Declaring Right Node
void Heapify(int [],int,int);	//Declaring Heapify method
void BuildHeap(int [],int);	//Declaring Buildheap
void HeapSort(int [],int);	//Declaring Heapsort
void main()
{
	int x[20],n,i;	
	printf("\n Enter number of elements to be sorted");
	scanf("%d",&n);
	printf("\n Enter %d elements".n);
	for(i=0;i<n;i++)			//adding elements in array
		scanf("%d",&x[i]);
	HeapSort(x,n);				//calling heapsort function
	printf("The sorted array");
	for(i=0;i<n;i++)			//displaying the sorted array
		printf("%4d",x[i]);
}
int Parent(int i){
	return(i/2); 		//getting the position of child node
}
int Left(int i){
	return(2*i+1);		//accessing the parent element of left node
}
int Right(int i){
	return(2*i+2);		//accessing the parent element of right node
}
void Heapify(int a[],int i,int n)
{
	int i,r,large,temp;
	l=Left(i);	//left child
	r=Right(i);	//right child
	if((l<=n-1) && (a[l]>a[i]))	//comparing the largest among them
		large=l;
	else
		large=i;
	if((r<=n-1) && (a[r]>a[large]))
		large=r
	if(large!=i)			//swapping the largest element with the target element
	{
		temp=a[i];
		a[i]=a[large];
		a[large]=temp;
		Heapify(a,large,n);	//after swapping, heapifying again the remaining elements
	}
}
void BuildHeap(int a[],int n){
	int i;
	for(i=(n-1)/2;i>=0;i--)		//building for each element
		Heapify(a,i,n);
}
void HeapSort(int a[],int n){
	int i,m,temp;
	BuildHeap(a,n);  //Building the max heap
	m=n;
	for(i=n-1;i>=1;i--)
	{
		temp=a[0];		//swapping with the first element
		a[0]=a[i];
		a[i]=temp;
		m=m-1;
		Heapify(a,0,m);  //Heapifying the remaning elements after removing the topmost element
	}
}
