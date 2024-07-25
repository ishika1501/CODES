
//

// it's like the card game 
void insertionSort(int n, vector<int> &arr){
    for(int i=0 ;i<n; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}