
Basic Outline of the approach:-

1.Sort the jobs in descending order of profit. 
2.If the maximum deadline is x, make an array of size x 
  Each array index is set to -1 initially as no jobs have been performed yet.
3.For every job check if it can be performed on its last day.
4.If possible mark that index with the job id and add the profit to our answer. 
5.If not possible, loop through the previous indexes until an empty slot is found.


class Solution 
{
    public:
    
    bool static comp(Job a, Job b) {
        return (a.profit > b.profit);
    }
    
    vector<int> JobScheduling(Job arr[], int n) { 
        
        sort(arr, arr+n , comp);
        int maxi=arr[0].dead;
        for(int i=1 ;i<n ;i++){
            maxi=max(maxi , arr[i].dead);
        }
        
        int slot[maxi + 1];

        for (int i = 0; i <= maxi; i++)slot[i] = -1;

        int countJobs = 0, jobProfit = 0;
        
        
        for (int i = 0; i < n; i++) {
         for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }

      vector<int> result = {countJobs, jobProfit};
        return result;
    } 
};