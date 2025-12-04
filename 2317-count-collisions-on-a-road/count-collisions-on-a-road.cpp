class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();

        // remove cars that will never collide
        int i = 0;
        while (i < n && s[i] == 'L') i++;

        int j = n - 1;
        while (j >= 0 && s[j] == 'R') j--;

        int count = 0;

        // between i and j, every non-'S' car collides
        for (int k = i; k <= j; k++) {
            if (s[k] != 'S') count++;
        }

        return count;
    }
};
