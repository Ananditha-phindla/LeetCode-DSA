class ProductOfNumbers {
public:
    vector<long>v;
    int lastidx;
    ProductOfNumbers() {
        for(int i=0;i<v.size();i++)
            cout << v[i] << " ";
        v.clear();
        lastidx = -1;
    }
    
    void add(int num) {
        if(num == 0){
            v.push_back(0);
            lastidx = v.size()-1;
            return;
        }
        if(v.empty() || v.back() == 0)
            v.push_back(num);
        else{
            v.push_back((long)num*v.back());
        }
    }
    
    int getProduct(int k) {
        int n = v.size();
        if(lastidx >= (n-k))
            return 0;
        if( k == v.size() || v[n-k-1] == 0)
            return v[n-1];
        return (v[n-1] / v[n-k-1]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */