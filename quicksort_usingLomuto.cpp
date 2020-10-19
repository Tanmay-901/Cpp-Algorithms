// Quick sort using lomuto partitioning
// In lomuto partitioning we take the last elemets of the array as the pivot element, i.e the element we wants to sort and place at correct position in the array
// Partitioning func return the p(partition) index, i.e the index of the element which is sorted
// Now the elements before and after than index p needs tobe sorted, therefore we call qsortL again for (l,p-1) and (p+1,l)

/*  time complexity: Best:   O(n)
                    Worts:  O(n^2)
                    Avergae:O(nlogn)
    Space complexity: O(n)
                      Though its an in-place sorting algorithm but it take O(n) for the recursive function calls.
*/
#include<iostream>
using namespace std;
void swap(int *a,int *b){                   //swap function for two values
    int c=*a;
    *a=*b;
    *b=c;
}
int lomuto(int arr[],int l,int r){          //Lomuto partitioning method, postion the last element of the array to its sorted position in the unsorted array
    int pivot=arr[r],i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[++i],&arr[r]);               // Elements till idx i are smaller than pivot, therefore ++i and then swap pivot element
    return i;
}
void qsortLomuto(int arr[],int l,int r){    // l=left idx, r=right idx
    if(l<r){
        int p=lomuto(arr,l,r);              // Index of the sorted element
        qsortLomuto(arr,l,p-1);             // Call for the left half of the unsorted array
        qsortLomuto(arr,p+1,r);             // Call for the right half of the unsorted array
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    qsortLomuto(arr,0,n-1);
    cout<<endl<<"After: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}