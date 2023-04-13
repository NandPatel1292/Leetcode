class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         stack<int> st;
        
//         int j = 0; 
        
//         for(auto val : pushed){
//             st.push(val); 
//             while(st.size() > 0 && st.top() == popped[j]){ 
//                 st.pop(); 
//                 j++; 
//             }
//         }
//         return st.size() == 0;
        
        stack<int> s;
        int j = 0;
        
        for(auto i : pushed){
            s.push(i);
            while(!s.empty() &&( s.top() == popped[j]) && j < popped.size()){
                s.pop();
                j++;
            }
        }
        return j == popped.size();
    }
};