class Solution {
public:
    int compress(vector<char>& chars) {
        int i =0;
        int index = 0;
        while(i< chars.size()){
            char current = chars[i];
            int count =0;
            while(i < chars.size() && chars[i] == current){
                i++;
                count++;
            }
            chars[index++] = current;

            if(count > 1){
                string strcnt = to_string(count);
                for(char ch: strcnt){
                    chars[index++]  = ch;
                }
            }
        }
        return index;
    }
};