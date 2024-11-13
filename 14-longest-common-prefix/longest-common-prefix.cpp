class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(),strs.end());
        string str1 = strs[0], str2 = strs[strs.size()-1];
        int length = min(str1.size(), str2.size());
        for (int i = 0; i < length; i++) {
            if (str1.substr(i, 1) != str2.substr(i, 1)) {
                return ans;
            }
            ans += str1.substr(i, 1);
        }
        return ans;
    

    }
};