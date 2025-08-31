class Solution {
public:
    void getCnt(vector<int>& arr, int lo, int mid, int hi, int &ans){
        int j = mid + 1;
        for(int i=lo;i<=mid;i++){
            while(j <= hi && arr[i] > 2ll * arr[j]){
                j++;
            }
            ans += j - (mid + 1);
        }
    }

    void merge(vector<int>& arr, int lo, int mid, int hi){
        int n = mid - lo + 1;
        int m = hi - mid;
        vector<int>left(n);
        vector<int>right(m);
        for(int i=0;i<n;i++){
            left[i] = arr[i+lo];
        }
        
        for(int i=0;i<m;i++){
            right[i] = arr[i+mid+1];
        }
        
        int i = 0, j = 0, k = lo;
        while(i < n && j < m){
            if(left[i] < right[j]){
                arr[k++] = left[i++];
            }
            else{
                arr[k++] = right[j++];
            }
        }
        
        while(i < n){
            arr[k++] = left[i++];
        }
        
        while(j < m){
            arr[k++] = right[j++];
        }
    }

    void mergeSort(vector<int>& arr, int l, int r,int &ans) {
        // code here
        if(l >= r)
            return;
        int mid = (l + r)/2;
        mergeSort(arr,l,mid,ans);
        mergeSort(arr,mid+1,r,ans);
        getCnt(arr,l,mid,r,ans);
        merge(arr,l,mid,r);
    }

    int reversePairs(vector<int>& nums) {
        int ans = 0;
        mergeSort(nums,0,nums.size()-1,ans);
        return ans;
    }
};