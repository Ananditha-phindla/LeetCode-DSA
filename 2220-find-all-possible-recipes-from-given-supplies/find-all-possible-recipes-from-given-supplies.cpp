class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string>ans;
        unordered_set<string>myset(supplies.begin(),supplies.end());
        int n = recipes.size();
        for(int i=0;i<n;i++){
            for(int i=0;i<n;i++){
            if(!myset.count(recipes[i])){
            bool f = true;
            for(int j=0;j<ingredients[i].size();j++){
                if(!myset.count(ingredients[i][j]))
                    f = false;
            }
            if(f){
                myset.insert(recipes[i]);
                ans.push_back(recipes[i]);
            }
            }
        }
        }
        
        return ans;
    }
};