class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0; 
        int h = s.size() - 1;
        while(l < h) {
            if(!isalnum(s[l])) {
                l++;
                continue;
            }

            if(!isalnum(s[h])) {
                h--;
                continue;
            }

            if(tolower(s[l]) == tolower(s[h])) {
                l++; h--;
            } else {
                return false;
            }
        }

        return true;
    }
};
