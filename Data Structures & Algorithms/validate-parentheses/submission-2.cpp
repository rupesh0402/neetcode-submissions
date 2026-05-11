class Solution {
public:
    bool isValid(string s) {
        stack<char> stac; 

        for(auto c: s) {
            if(c == '(' || c == '{' || c == '[') {
                stac.push(c);
            } else {
                char brac;
                if(!stac.empty()) {
                brac = stac.top();
                stac.pop();
                } else {
                    return false;
                }
                
                if(c == ')' && brac == '(') {
                    continue;
                } else if(c == ']' && brac == '[') {
                    continue;
                } else if (c == '}' && brac == '{') {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return stac.empty() ? true : false;
    }
};
