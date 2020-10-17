//QUICK SORT
//Time Complexity: -Worst Case O(n^2)
//Time Complexity: -Best Case O(n*log n)

#include<stdio.h> 
int swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 
int pt(int arr[], int low, int high) 
{ 
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++) 
	{ 
		if (arr[j] < pivot) 
		{ 
			i++;
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 
int qs(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = pt(arr, low, high); 
		qs(arr, low, pi - 1); 
		qs(arr, pi + 1, high); 
	} 
} 
int show(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 
 
int main() 
{ 
	int n;
	int arr[100];
	printf("Range: ");
	scanf("%d",&n);
	printf("Enter The Values: ");
	for(int i=0; i<n; i++)
	{
	    scanf("%d",&arr[i]);
	}
	printf("Value Given is: \n"); 
	show(arr, n); 
	qs(arr, 0, n-1); 
	printf("Quick Sorted : \n"); 
	show(arr, n); 
	return 0; 
}
