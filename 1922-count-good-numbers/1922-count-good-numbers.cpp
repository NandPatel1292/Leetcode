class Solution {
public:
    long long mod = 1000000000+7;
    long long solve(long long n, long long r){
        long long ans;
        if(r == 0){
            return 1;
        }
        
        ans = solve(n,r/2)%mod;
        
        if(r%2 != 0){
            return (n*ans*ans)%mod;
        }
        else{
            return (ans*ans)%mod;
        }
        
        
    }
    
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even;
        if(n%2 == 0){
            even = n/2;
        }
        else{
            even = n/2 + 1;
        }
//         even : 0 2 4 6 8
//         odd : 2 3 5 7
        return (solve(5,even)*solve(4,odd))%mod;
    }
};