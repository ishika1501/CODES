

bool comparePairs(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int findLongestChain(vector<vector<int>>& pairs) {

    sort(pairs.begin(), pairs.end(), comparePairs);
    
    int current_end = INT_MIN;
    
    int longest_chain = 0;
    
    for (const auto& pair : pairs) {
        if (pair[0] > current_end) {
            current_end = pair[1];
            longest_chain++;
        }
    }
    
    return longest_chain;
}