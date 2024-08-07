//help us to find a perticular string is present in that biigger string or not 


const int BASE = 31;
const int MOD = 1e9 + 7;

vector<int> power;

int hashChar(char ch) {
    return ch - 'A' + 1;
}

int getHash(string str) {
    int n = str.size(), sum = 0;
    
    for(int i = n-1; i >= 0; i--) {
        int curr = str[i];
        
        sum = (sum + (hashChar(curr) * 1LL * power[n-1-i]) % MOD) % MOD;
    }
    
    return sum;
}

bool checkEqual(string &str, string &pat, int start, int n) {
    
    bool retVal = 1;
    
    for(int i = 0; i < n; i++) {
        if(str[i + start] != pat[i]) {
            retVal = 0;
            break;
        }
    }
    
    return retVal;
}

vector<int> stringMatch(string &str, string &pat) {
    int n = pat.size(), m = str.size();
    power = vector<int> (n, 1);
    
    for(int i = 1; i < n; i++) {
        power[i] = (BASE * 1LL * power[i-1]) % MOD;
    }
    
    vector <int> ans;
    
    int patHash = getHash(pat);
    int rollHash = getHash(str.substr(0, n));
    
    int l = 0, r = n-1;
    
    do {
        if(patHash == rollHash && checkEqual(str, pat, l, n)) {
            ans.push_back(l);
        }
           
        char left, right;
        left = str[l];
           
        // Remove Left character
        rollHash = (rollHash - (hashChar(left) * 1LL * power[n-1]) % MOD + MOD) % MOD;
        
        l++, r++;
        
        if(r < m) {
            right = str[r];
            
            // Right Shift
            rollHash = ((rollHash * 1LL * BASE) % MOD 
                        
                // Add next character also
                + (hashChar(right) * 1LL * power[0]) % MOD) % MOD;
        }
        
    } while(r < m);
           
    return ans;
}