class Solution {
public:
    bool checkPowersOfThree(int n) {
        int i = 0;
        int temp = n;
        int x = 0;
        while(temp > 0){
            int r = temp % 3;
            if(r != 0){
                x += pow(3,i);
            }
            i++;
            temp = temp/3;
        }
        return (x == n);
    }
};