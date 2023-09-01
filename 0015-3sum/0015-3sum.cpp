class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        
        sort(n.begin(),n.end());
        
        
        if(n.size() < 3){
            return {};
        }
        
        if(n[0] > 0){
            return {};
        }
        
        vector<vector<int>>ans;
        
        for(int i = 0; i<n.size(); i++){
            if(n[i] > 0){
                break;
            }
            if(i > 0 && n[i] == n[i-1]){
                continue;
            }
            
            int low = i+1;
            int high = n.size()-1;
            int sum = 0;
            
            while(low < high){
                sum = n[i] + n[low] + n[high];
                if(sum  > 0){
                    high--;
                }
                else if(sum < 0){
                    low++;
                }
                else{
                    ans.push_back({n[i],n[low],n[high]});
                    int last_low = n[low];
                    int last_high = n[high];
                    
                    while(low<high && n[low] == last_low){
                        low++;
                    }
                    while(low<high && n[high] == last_high){
                        high--;
                    }
                }
            }
        }
        
        return ans;
    }
};