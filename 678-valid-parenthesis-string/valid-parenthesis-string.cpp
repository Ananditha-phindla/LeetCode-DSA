class Solution {
public:
    bool checkValidString(string s) {
        stack<char>open;
        stack<char>star;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(')
                open.push(i);
            else if(s[i] == '*')
                star.push(i);
            else{
                if(open.size() > 0)
                    open.pop();
                else if(star.size() > 0)
                    star.pop();
                else
                    return false;
            }
        }
        if(!open.empty()){
            if(open.size() > star.size())
                return false;
            while(!open.empty()){
                if(open.top() > star.top())
                    return false;
                star.pop();
                open.pop();
            }
        }
        return true;
    }
};