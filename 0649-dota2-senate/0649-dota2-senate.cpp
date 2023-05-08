class Solution {
public:
    string predictPartyVictory(string s) {
        int r = count(s.begin(),s.end(),'R');
        int d = s.size() - r;
        
        auto ban = [&](char toBan, int start){
            bool loop = false;
            int pointer = start;
            
            while(true){
                if(pointer == 0){
                    loop = true;
                }    
                if(s[pointer] == toBan){
                    s.erase(s.begin() + pointer);
                    break;
                }
                pointer = (pointer + 1)%s.size();
            }
            
            return loop;
        };
        
        int turn = 0;
        while(r > 0 && d > 0){
            if(s[turn] == 'R'){
                bool banBefore = ban('D',(turn + 1)%s.size());
                d--;
                if(banBefore){
                    turn--;
                }
            }
            else{
                bool banBefore = ban('R',(turn + 1)%s.size());
                r--;
                if(banBefore){
                    turn--;
                }
            }
            turn = (turn + 1)%s.size();
        }
        
        return d == 0 ? "Radiant" : "Dire";
    }
};