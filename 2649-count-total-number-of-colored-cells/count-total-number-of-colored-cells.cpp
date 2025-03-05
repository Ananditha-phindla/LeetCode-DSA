class Solution {
public:
    long long helper(int curr,long long prev,int n){
        if(curr == n)
            return prev;
        return helper(curr+1,(curr*4)+prev,n);
    }
    long long coloredCells(int n) {
        return helper(1,1,n);
    }
};