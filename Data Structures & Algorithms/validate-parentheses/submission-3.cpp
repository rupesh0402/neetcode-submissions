class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        unordered_map<char, char> match = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c : s) {
            // If it's a closing bracket
            if(match.count(c)) {
                if(st.empty() || st.top() != match[c])
                    return false;
                st.pop();
            } 
            else {
                // It's an opening bracket
                st.push(c);
            }
        }

        return st.empty();
    }
};