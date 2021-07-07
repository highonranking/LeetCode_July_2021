class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for(int it: arr)
            ++cnt[it];
        vector<int> frequencies;
        for(auto [_, freq]: cnt)
            frequencies.push_back(freq);
        sort(frequencies.begin(), frequencies.end());
        
        int res = 0, rem = 0, half = arr.size()/2, i = frequencies.size()-1;
        while(rem < half){
            res++;
            rem += frequencies[i--];
        }
            return res;
    }
};

