void merge(vector<int> &nums, int l, int mid, int high) {
	if (l >= high) return;
	int ll = l, r = mid + 1, k = 0, size = high - l + 1;
	vector<int> sorted(size, 0);
	while (ll <= mid && r <= high)
		sorted[k++] = nums[ll] < nums[r] ? nums[ll++] : nums[r++];
	while (ll <= mid) 
		sorted[k++] = nums[ll++];
	while (r <= high) 
		sorted[k++] = nums[r++];
	for (k = 0; k < size; k++)
		nums[k + l] = sorted[k];
}

void mergeSort(vector<int> &nums, int l, int r) {
	if (l >= r) return;
	int mid = (r - l) / 2 + l;
	mergeSort(nums, l, mid);
	mergeSort(nums, mid + 1, r);
	merge(nums, l, mid, r);
}class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
     return nums;
    }
};
