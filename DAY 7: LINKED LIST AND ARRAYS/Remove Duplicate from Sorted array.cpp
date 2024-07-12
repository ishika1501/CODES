//BRUTE FORCE :
//We think of a data strcture hat doesn't contain duplicates 

int removeDuplicates(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}

//OPTIMAL APPROACH 

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int j=0;
        int n=arr.size();
        for(int i =0 ;i<n ;i++){
            if(arr[j]!=arr[i]){
                j++;
                arr[j]=arr[i];
            }
        }
        return j+1;
    }
};

