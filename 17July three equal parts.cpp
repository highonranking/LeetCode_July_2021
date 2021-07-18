class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int noOfOnes = count(arr.begin(), arr.end(), 1);
        int n = arr.size();
        if(noOfOnes%3){
            return {-1, -1};
        }
        if(noOfOnes==0)
            return{0, n-1};
        int total = noOfOnes/3;
        int d1=0, d2=0, d3=0;
        int count =0;
        for(int i=0; i<n; i++){
            if(arr[i]==1){
                if(count==0)
                    d1=i;
                else if(count==total)
                    d2 = i;
                else if(count == 2*total)
                    d3=i;
              count++;  
                
            }
        }
        while(d3<n-1){
            d1++;
            d2++;
            d3++;
            if(arr[d1]!=arr[d2]||arr[d2]!=arr[d3]||arr[d1]!=arr[d3])
                return {-1, -1};
            
        }
        return {d1, d2+1};
    }
};
