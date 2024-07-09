Brute Force Approach:

1. we can cout all the 1's , 2's 0's and then put them in a vector using seperate loop 

BETTER : we can use the sort funtion 

OPTIMAL :

1. we can use 3 pointers ,frst  last and mid .
2. place the mid and the first at index 0 ;
3. run the loop till mid<=high

void sortArray(vector<int>& arr, int n) {

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}