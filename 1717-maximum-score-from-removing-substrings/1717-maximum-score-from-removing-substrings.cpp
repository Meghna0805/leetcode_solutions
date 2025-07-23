class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string first, second;
        int res = 0;
        char a, b;
        int val1, val2;
        if (x > y) {
            a = 'a'; b = 'b'; val1 = x; val2 = y;
        } else {
            a = 'b'; b = 'a'; val1 = y; val2 = x;
        }
        for (char c : s) {
            if (!first.empty() && first.back() == a && c == b) {
                first.pop_back();
                res += val1;
            } else {
                first.push_back(c);
            }
        }
        for (char c : first) {
            if (!second.empty() && second.back() == b && c == a) {
                second.pop_back();
                res += val2;
            } else {
                second.push_back(c);
            }
        }
        return res;
    }
};
