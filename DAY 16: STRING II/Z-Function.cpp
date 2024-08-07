
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    vector<int> z = z_function(s);
    
    cout << "Z-function values: ";
    for (int value : z) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
