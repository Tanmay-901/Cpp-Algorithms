// Quick sort using hoare's partitioning
// In hoare's partitioning we take the first elemets of the array as the pivot element, i.e the element about which we wants to sort the array
// Partitioning func return the p(partition) index, i.e the index of the element which satisfy all_left_elements<pivot and all_right_elements>=pivot
// Now the elements till and after than index p needs tobe sorted, therefore we call qsortL again for (l,p) and (p+1,l)

/*  ** Better than lomuto because it do 3 times less swapping
    time complexity: Best:   O(n)
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
int Hoares(int arr[],int l,int r){          //Hoares partitioning method, partition the array as elements at left<pivot and right>=pivot
    int pivot=arr[l];
    int i=l-1,j=r+1;
    while(true){
        do{                                 //finding element greater or equal to pivot
            i++;
        }while(arr[i]<pivot);
        do{                                 //finding element less or equal to pivot
            j--;
        }while(arr[j]>pivot);
        if(i>=j){                       
            return j;
        }
        swap(&arr[i],&arr[j]);
    }
}
void qsortHoares(int arr[],int l,int r){    // l=left idx, r=right idx
    if(l<r){
        int p=Hoares(arr,l,r);              // partitioning index
        qsortHoares(arr,l,p);               // Call for the left half, i.e <pivot
        qsortHoares(arr,p+1,r);             // Call for the right half, i.e >=pivot
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
    qsortHoares(arr,0,n-1);
    cout<<endl<<"After: "<<" ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}