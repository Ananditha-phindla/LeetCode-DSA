class Solution {
public:
    vector<int>li;
    vector<int>primeInRange;
    void seive(int n){
        vector<bool>prime(n+1,true);
        prime[0] = false;
        prime[1] = false;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j] = false;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(prime[i])
                li.push_back(i);
        }
    }

    void extended_seive(int left,int right){
        vector<bool>atobprime(right-left+1,true);
        for(auto i : li){
            int p = left;
            if(left % i != 0)
                p += i - (left % i);
            for(int j=p;j<=right;j+=i){
                if(j != i)
                    atobprime[j-left] = false;
            }
        }

        for(int i=0;i<=right-left;i++){
            if(atobprime[i] && i+left > 1)
                primeInRange.push_back(i+left);
        }
    }

    vector<int> closestPrimes(int left, int right) {
        seive(sqrt(right));
        extended_seive(left,right);
        int n = primeInRange.size();
        int dis = INT_MAX;
        int num1 = -1,num2 = -1;

        for(int i=0;i<li.size();i++){
            cout << li[i] << " ";
        }
        cout << endl;
        for(int i=0;i<n;i++){
            cout << primeInRange[i] << " ";
        }
        for(int i=1;i<n;i++){
            if(primeInRange[i] - primeInRange[i-1] < dis){
                dis = primeInRange[i] - primeInRange[i-1];
                num1 = primeInRange[i-1];
                num2 = primeInRange[i];
            }
        }
        li.clear();
        primeInRange.clear();
        return {num1,num2};
    }
};