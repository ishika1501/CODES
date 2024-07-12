
//BRUTE FORCE :
For each index, we have to find the amount of water that can be stored and we have to sum it up
.If we observe carefully the amount the water stored at a particular index
is the minimum of maximum elevation to the left and right of the index minus the elevation at that index.

int trap(vector < int > & arr) {
  int n = arr.size();
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    int leftMax = 0, rightMax = 0;
    while (j >= 0) {
      leftMax = max(leftMax, arr[j]);
      j--;
    }
    j = i;
    while (j < n) {
      rightMax = max(rightMax, arr[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - arr[i];
  }
  return waterTrapped;
}

//OPTIMAL APPROACH :

Take 2 array prefix and suffix array and precompute the leftMax and rightMax
for each index beforehand. Then use the formula min(prefix[I], suffix[i])-arr[i] to compute water trapped at each index.

int trap(vector < int > & arr) {
  int n = arr.size();
  int prefix[n], suffix[n];
  prefix[0] = arr[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = max(prefix[i - 1], arr[i]);
  }
  suffix[n - 1] = arr[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix[i] = max(suffix[i + 1], arr[i]);
  }
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    waterTrapped += min(prefix[i], suffix[i]) - arr[i];
  }
  return waterTrapped;
}


//MOST OPTIMAL SOLUTION :

2 pointer approach 
on in the left and other in the extreme right 


class Solution {
public:
    int trap(vector<int>& heights) {
    int n = heights.size();
        int res = 0;
        int left = 0, right = n - 1;
        int maxLeft = 0, maxRight = 0;
        
        while (left <= right) {
            if (heights[left] <= heights[right]) {
                if (heights[left] >= maxLeft) {
                    maxLeft = heights[left];
                } else {
                    res += maxLeft - heights[left];
                }
                left++;
            } else {
                if (heights[right] >= maxRight) {
                    maxRight = heights[right];
                } else {
                    res += maxRight - heights[right];
                }
                right--;
            }
        }
        return res;
   }
};