A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'




long long getInversions(long long *arr, int n){
    // Write your code here.
    int cnt = 0;
    
    for(int i = 0; i<n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[i] > arr[j])
            {
                cnt++;
            }
        }
    }
    
    return cnt;
}