
Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

1. we need to deaclare vector of vector of the given size n;
2. Then we can runa  for loop through which we can putthe values.
3.we can directly use the brute force formule so that would be easy :
        v[i][j]=v[i-1][j-1]+v[i-1][j];
4. first we need to resize each row every time we try to fill that row 
5. then set the fist and the last element of that row as 1 for calculation 
6. use another for loop to put the values.


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>>v(n,vector<int>(n,0));
        for(int i=0 ;i<n ;i++){
            v[i].resize(i+1);
            v[i][0]=v[i][i]=1;
            for(int j=1; j<i; j++)v[i][j]=v[i-1][j-1]+v[i-1][j];
        }
        return v;
    }
};

approch 2:
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}


Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void pascalTriangle(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}