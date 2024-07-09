BRUTE FORCE:

MULTIPLY THAT ANY TIMES :
double myPow(double x, int n) {
      double ans = 1.0;
      for (int i = 0; i < n; i++) {
        ans = ans * x;
      }
      return ans;
}


OPTIMAL APPROACH :

double myPow(double x, int y) {
        double ans = 1.0;
        long long n =y;
        if(n<0)n=(-1)*n;

        while(n){
            if(n%2){
                ans=ans*x;
                n=n-1;
            }
            else{
                x=x*x;
                n=n/2;
            }
        }
        if(y<0) ans= 1/ans;
        return ans;
}