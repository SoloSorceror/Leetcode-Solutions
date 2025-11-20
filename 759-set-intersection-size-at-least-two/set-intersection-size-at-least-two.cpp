class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end increasing; if tie, start decreasing
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        // Our chosen numbers
        vector<int> nums;

        // Track the last two chosen numbers
        // p = last picked, q = second last picked
        int p = -1, q = -1;

        for (auto &in : intervals) {
            int start = in[0], end = in[1];

            bool p_in = (p >= start && p <= end);
            bool q_in = (q >= start && q <= end);

            // Case 1: We already have 2 points inside → OK
            if (p_in && q_in) continue;

            // Case 2: Only 1 point (say only p is inside)
            if (p_in || q_in) {
                // Add the rightmost possible new point
                nums.push_back(end);

                // Shift the old p -> q
                q = p;  
                p = end;
            }
            else {
                // Case 3: No chosen points in this interval
                // We need to add the last two possible points: end-1, end
                nums.push_back(end - 1);
                nums.push_back(end);

                q = end - 1;
                p = end;
            }
        }

        return nums.size();
    }
};
