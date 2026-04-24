class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lcount = 0;
        int rcount = 0;
        int gap = 0;

        for(char c: moves){
            if(c=='R') rcount++;
            else if(c=='L') lcount++;
            else gap++;
        }
        return abs(lcount-rcount)+gap;
    }
};