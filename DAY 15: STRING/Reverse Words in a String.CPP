
class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int n=s.length();
        string result;

        for(int i=0 ;i<n ;i++){
            string word;
            if(s[i]==' ')continue;
            while(i<s.size() && s[i]!=' '){
                word+=s[i];
                i++;
            }
            st.push(word);
        }

        while(!st.empty()) {
            result += st.top(); 
            st.pop();
            if(!st.empty()) result += " ";
        }

        return result;
    }
};