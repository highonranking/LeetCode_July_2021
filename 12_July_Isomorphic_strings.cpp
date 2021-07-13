class Solution {
    #define MAX_CHARS 256
public:
    bool isIsomorphic(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        if(l1!=l2)
            return false;
        bool marked[MAX_CHARS] = {false};

        int map[MAX_CHARS];
        memset(map, -1, sizeof(map));
        for(int i=0; i<l1; i++){
            if(map[s[i]] == -1){
                if(marked[t[i]] == true)
                    return false;
                marked[t[i]] = true;
                map[s[i]] = t[i];
            }
            else if(map[s[i]] != t[i])
                return false;
        }
        
        return true;
    }
};
