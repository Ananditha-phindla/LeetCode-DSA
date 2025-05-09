class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto i : tokens){
            if(i == "+" || i == "-" || i == "*" || i == "/"){
                int a,b;
                if(!st.empty()){
                    a = st.top();
                st.pop();
                if(!st.empty())
                    b = st.top();
                st.pop();
                if(i == "+")
                    st.push(a+b);
                else if(i == "-")
                    st.push(b-a);
                else if(i == "*")
                    st.push(a*b);
                else
                    st.push(b/a);
                }
            }
            else{
                int x = stoi(i);
                st.push(x);
            }
            cout << st.top() << " ";
        }
        return st.top();
    }
};