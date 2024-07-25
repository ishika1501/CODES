
Bubble Sort is one of the sorting algorithms 
that works by repeatedly swapping the adjacent 
elements of the array if they are not in sorted order

#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n){   
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){  
            if(arr[j] > arr[j+1]){  
                swap(arr[j], arr[j+1]);  
            }
        }
    }
}
