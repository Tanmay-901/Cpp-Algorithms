//MERGE SORT: Time Complexity O(n*Log n)

#include <stdio.h> 
#include <stdlib.h> 
int merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 
	int L[n1], R[n2]; 
	for (i = 0; i < n1; i++) 
		{L[i] = arr[l + i];}
	for (j = 0; j < n2; j++) 
		{R[j] = arr[m + 1 + j]; }
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else
 { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 
	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 
	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 
int mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) { 
		int m = l + (r - l) / 2; 
		mergeSort(arr, l, m); 
		mergeSort(arr, m + 1, r); 
		merge(arr, l, m, r); 
	} 
} 
int show(int A[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
	{
		printf("%d ", A[i]); 
	}
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
	mergeSort(arr, 0, n - 1); 
	printf("\nMerge Sorted Values is: \n"); 
	show(arr, n); 
}
