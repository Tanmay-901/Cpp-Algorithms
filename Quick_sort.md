Quick sort is a divide and conquer algorithm that has an average case time complexity of O(nlogn). It picks an element as pivot and partitions the given array around the picked pivot. It has O(1) space complexity.



Cpp

/*   Quick Sort Implementation in C++   */


#include<bits/stdc++.h>
using namespace std;

int Partition(int *A, int start, int end) {
    int pivot = A[end];

    int partitionIndex = start;    // set partition index as start initially

    for (int i = start; i < end; i++) {
        if (A[i] <= pivot) {
            swap( A[i], A[partitionIndex] );   // swap if element is lesser than pivot
            partitionIndex++;
        }
    }
    swap(A[partitionIndex], A[end]);  //swap pivot with element in partition index
    return partitionIndex;
}

void QuickSort(int *A, int start, int end) {

    if (start < end ) {

        int partitionIndex = Partition(A, start, end); // calling partition
        QuickSort(A, start, partitionIndex - 1);
        QuickSort(A, partitionIndex + 1, end);
    }
}

int main() {
    int A[] = {7, 6, 5, 4, 3, 2, 1, 0};

    QuickSort(A, 0, 7);

    for (int i = 0; i < 8; i++) cout << A[i] << " ";


}





Python 


/*   Quick Sort Implementation in Python   */

def partition(arr,low,high): 
    i = ( low-1 )         # index of smaller element 
    pivot = arr[high]     # pivot 
  
    for j in range(low , high): 
  
        # If current element is smaller than the pivot 
        if   arr[j] < pivot: 
          
            # increment index of smaller element 
            i = i+1 
            arr[i],arr[j] = arr[j],arr[i] 
  
    arr[i+1],arr[high] = arr[high],arr[i+1] 
    return ( i+1 ) 
  
 
def quickSort(arr,low,high): 
    if low < high: 
  
        # pi is partitioning index, arr[p] is now 
        # at right place 
        pi = partition(arr,low,high) 
  
        # Separately sort elements before 
        # partition and after partition 
        quickSort(arr, low, pi-1) 
        quickSort(arr, pi+1, high) 
  
# Driver code  
arr = [10, 7, 8, 9, 1, 5] 
n = len(arr) 
quickSort(arr,0,n-1) 
print ("Sorted array is:") 
for i in range(n): 
    print ("%d" %arr[i]), 
