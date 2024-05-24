class Solution {
public:
    int solve(int ind, vector<int>nums, int k, unordered_map<int,int>&mp){
        if(ind == nums.size()){
            // ans.push_back(tmp);
            return 1;
        }
        
        // int x = nums[ind];
        // solve(ind+1, nums, tmp,ans);
        // tmp.push_back(x);
        // solve(ind+1, nums, tmp, ans);
        
        int c = solve(ind+1, nums, k ,mp);
        
        if(!mp[nums[ind]-k]){
            mp[nums[ind]]++;
            
            c += solve(ind+1, nums, k, mp);
            
            mp[nums[ind]]--;
        }
        
        return c;
    }
    
    int solve2(vector<pair<int,int>>&sub, int size, int k, int ind){
        if(ind == size){
            return 1;
        }
        
        int skip = solve2(sub, size, k, ind+1);
        
        int take = (1 << sub[ind].second) - 1;
        
        if(ind+1 < size && sub[ind+1].first - sub[ind].first == k){
            take *= solve2(sub, size, k, ind+2);
        } 
        else{
            take *= solve2(sub, size, k, ind+1);
        }
        
        return take + skip;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        
        // unordered_map<int,int>mp;
        // sort(nums.begin(),nums.end());
        
        // return solve(0,nums,k,mp)-1;
        
        int c = 1;
        map<int,map<int,int>> mp;
        
        for(auto i : nums){
            mp[i%k][i]++;
        }
        
        // for(auto j : mp){
        //     cout<<j.first<<" ";
        //     for(auto k : j.second){
        //         cout<<k.first<<" "<<k.second<<endl;
        //     }
        //     cout<<endl;
        // }
        
        for(auto i : mp){
            vector<pair<int,int>> subsets(i.second.begin(), i.second.end());
            c *= solve2(subsets, subsets.size(), k, 0);
        }
    
        return c-1;
    }
};