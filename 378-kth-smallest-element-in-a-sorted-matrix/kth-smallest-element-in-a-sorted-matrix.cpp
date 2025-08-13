class Solution {
public:
    int BS(vector<vector<int>>& matrix, int val){
        int n = matrix.size();
        int m = matrix[0].size();
        int lessElements = 0;
        for(int i=0;i<n;i++){
            int rowLess = 0;
            int lo = 0;
            int hi = m - 1;
            while(lo <= hi){
                int mid = (lo + hi)/2;
                if(matrix[i][mid] < val){
                    rowLess = mid + 1;
                    lo = mid + 1;
                }
                else
                    hi = mid - 1;
            }
            lessElements += rowLess;
        }
        return lessElements;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = matrix[0][0];
        int hi = matrix[n-1][m-1];
        while(lo <= hi){
            int mid = (lo + hi)/2;
            int lessElements = BS(matrix,mid);
            cout << lessElements << " ";
            if(lessElements < k)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return hi;
    }
};