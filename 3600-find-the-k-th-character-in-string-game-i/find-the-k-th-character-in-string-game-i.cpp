class Solution {
public:
    char solve(int k,string &word,string PrevWord){
        if(word.length() >= k){
            return word[k-1];
        }
        for(int i=0;i<PrevWord.length();i++){
            if(word[i] == 'z'){
                word += 'a';
            }
            else{
                word += char(int(word[i])+1);
            }
        }
        return solve(k,word,word);
    }
    char kthCharacter(int k) {
        string word = "a";
        return solve(k,word,"a");
    }
};