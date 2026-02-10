class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        unordered_map<int,int> map;
        int maxi = 0;
        for(int i=0; i<fruits.size(); i++){
            map[fruits[i]]++;
            while(map.size()>2){
                int leftVal = fruits[left];
                map[leftVal]--;
                if (map[leftVal] == 0) {
                    map.erase(leftVal);
                }
                left++;
            }
            maxi = max(maxi,i-left+1);
        }
        return maxi;
    }
};