class Solution {
public:
    string longestPalindrome(string s) {
        int resLen = 0;
        string res = "";

        for(int i=0; i<s.size(); i++) {
            int l = i;
            int r = i;
            //In case of odd
            while (l>=0 && r < s.size() && s[l] == s[r]) {
                if(resLen < r-l+1) {
                    resLen = r - l + 1;
                    res = s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
            l = i;
            r = i+1;
            //In case of odd
            while (l>=0 && r < s.size() && s[l] == s[r]) {
                if(resLen < r-l+1) {
                    resLen = r - l + 1;
                    res = s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};
