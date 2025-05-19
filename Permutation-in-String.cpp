class Solution {
private:
    bool checkEqual(int str[26], int str2[26]){
        for(int i = 0; i<26; i++){
            if(str[i] != str2[i]){
                return 0;
            }
        }
        return 1;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
      int arr1[26]={0} ;
      for(int i=0; i<s1.length(); i++){
        int number = s1[i]-'a';
        arr1[number]++;
      } 
      int i = 0;
      int arr2[26] = {0};
      int windowsize = s1.length();
      while( i < windowsize && i < s2.length()){
        int number = s2[i]-'a';
        arr2[number]++;
        i++;
      }
      if(checkEqual(arr1 , arr2)){
        return 1;
      }
      while(i<s2.length()){
        char newchar = s2[i];
        int number = newchar-'a';
        arr2[number]++;

        char oldchar = s2[i-windowsize];
        number = oldchar - 'a';
        arr2[number]--;
        i++;
        if(checkEqual(arr1 , arr2)){
        return 1;
      }

      }
      return 0;
    }
};