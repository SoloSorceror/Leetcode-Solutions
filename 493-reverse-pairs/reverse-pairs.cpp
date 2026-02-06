class Solution {
public:
    long long merge(vector<int>& arr, int left, int mid, int right) {
        long long count = 0;

        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // normal merge
        vector<int> temp;
        int i = left;
        j = mid + 1;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
            else temp.push_back(arr[j++]);
        }

        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);

        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }

        return count;
    }

    long long mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        long long count = 0;

        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid + 1, right);
        count += merge(arr, left, mid, right);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
