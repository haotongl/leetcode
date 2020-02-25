// faster than 14%
// mem less than 86%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        string cur("");
        int cur_l = 0;
        int max_l = 0;
        
        for (int i=0; i<s.length(); i++) {
            if (cur.find(string(1, s[i])) != string::npos) {
                i = i + cur.find(string(1, s[i])) - cur.length();
                cur = "";
                if (cur_l > max_l) max_l = cur_l;
                cur_l = 0;
            }
            else {
                cur.push_back(s[i]);
                cur_l+=1;
            }
        }
        
        return max(max_l, cur_l);
    }
};
