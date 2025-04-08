class Solution {
public:
    bool isPalindrome(int start, int end, string s){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++, end--;

        }
        return true;
    }
    void backtrack(int start, vector<string>& path, vector<vector<string>>& result, string s){
        //Base Case
        if(start == s.length()){
            result.push_back(path);
            return;
        }
        for(int end = start; end<s.length(); end++){
            if(isPalindrome(start, end ,s)){
                path.push_back(s.substr(start , end-start+1));
                backtrack(end+1, path , result, s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(0, path, result, s);
        return result;
    }
};