class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        for(int c : bills) {
            if(c == 5) {
                fives++;
            }
            else if(c == 10) {
                if(!fives)
                    return false;
                fives--;
                tens++;
            }
            else {
                if(!tens && fives < 3)
                    return false;
                if(tens && !fives)
                    return false;
                if(tens) {
                    tens--;
                    fives--;
                }
                else {
                    fives -= 3;
                }
            }
        }
        return true;
    }
};