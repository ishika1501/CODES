Given an integer array nums, find the subarray(A subarray is a contiguous non-empty sequence of elements within an array.)
with the largest sum, and return its sum.


1. We need to fist figure out the possible subarry 
2. we can run 2 for loops that willl gie us the range of the subarray from (i-j)
3. then use another loop to get the sum inside that 
4. then find the max among them 

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}


BETTER APPROACH :

We can see that we can use it with 2 for loop sitself 
int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}


OPTIMAL APPROACH :

The intuition of the algorithm is not to consider the subarray as a part of the answer
if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer 
and so this type of subarray cannot be a part of the subarray with maximum sum.

long long maxSubarraySum(int arr[], int n) {
    int ans=0 ;
    int sum=0;
    for(int i=0 ;i<n ;i++){
        sum+=arr[i];

        if(ans<sum){
            ans=sum;
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    return ans;
}