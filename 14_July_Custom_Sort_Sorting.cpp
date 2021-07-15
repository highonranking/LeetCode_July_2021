class Solution {
public:
    string customSortString(string order, string str) {
        unordered_map<char, int> dir;
        int i = 0;
        transform(order.begin(), order.end(), inserter(dir, dir.end()),
                  [&](char &a) { return make_pair(a, ++i); });
        sort(str.begin(), str.end(),
             [&](char a, char b) { return dir[a] < dir[b]; });
        return str; 
    }
};
