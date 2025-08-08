class Solution {
public:
    char solve(int k,string &word){
        if(word.length() >= k){
            return word[k-1];
        }
        int n = word.length();
        for(int i=0;i<n;i++){
            if(word[i] == 'z'){
                word += 'a';
            }
            else{
                word += word[i]+1;
            }
        }
        return solve(k,word);
    }
    char kthCharacter(int k) {
        string word = "a";
        return solve(k,word);
    }
};