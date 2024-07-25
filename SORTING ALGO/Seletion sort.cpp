
Selection sort is one of the sorting algorithms 
that works by repeatedly finding the minimum element
from the unsorted part of the array and putting it at
 the beginning of the unsorted region of the array.


 #include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    for(int i=0 ;i<n-1 ;i++){
        int idx=i;
        for(int j=i+1 ;j<n; j++){
            if(arr[j]<arr[idx]){
                idx=j;
            }
        }
        swap(arr[i],arr[idx]);
    }
}