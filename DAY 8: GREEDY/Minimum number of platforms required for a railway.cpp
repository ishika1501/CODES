
int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int ans=0, count=0;
    	int i=0,j=0;
    	while(i<n && j<n){
    	    if(arr[i]<dep[j]){
    	        count++;
    	        i++;
    	    }else{
    	        count--;
    	        j++;
    	    }
    	    ans=max(ans,count); //updating the value with the current maximum
        }
        return ans;
    }