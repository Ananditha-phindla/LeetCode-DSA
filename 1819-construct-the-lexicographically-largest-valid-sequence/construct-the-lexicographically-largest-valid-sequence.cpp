class Solution {
public:
    vector<int> ans;
    bool backtrack(int n, int l, vector<int>& arr, vector<bool>& used) {
        if (l == arr.size()) {
            ans = arr;
            return true;
        }

        if (arr[l] != -1) return backtrack(n, l + 1, arr, used);

        for (int num = n; num >= 1; --num) {
            if (used[num]) continue;

            int r = (num == 1) ? l : l + num;
            if (r < arr.size() && arr[r] == -1) {
                arr[l] = arr[r] = num;
                used[num] = true;

                if (backtrack(n, l + 1, arr, used)) return true;

                arr[l] = arr[r] = -1;
                used[num] = false;
            }
        }

        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        ans.clear();
        vector<int> arr(2 * n - 1, -1);
        vector<bool> used(n + 1, false);
        backtrack(n, 0, arr, used);
        return ans;
    }
};