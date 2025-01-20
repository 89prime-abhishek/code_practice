class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return kSum(nums,target,0,4);
    }
    vector<vector<int>> kSum(vector<int>& nums, long long target, int start,int k){
        vector<vector<int>> res;
        if (start == nums.size()) {
            return res;
        }
        long long average_value = target / k;

        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest
        // value in nums is smaller than target / k.
        if (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for(int i= start;i<nums.size();++i){
            if(i==start || nums[i-1]!= nums[i]){
               for (vector<int>& subset :
                     kSum(nums, static_cast<long long>(target) - nums[i], i + 1,
                          k - 1)) {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset),
                                      end(subset));
                } 
            }
        }
        return res;
    }                         
    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start){
        vector<vector<int>> res;
        int left = start, right = int(nums.size())-1;

        while(left<right){
            int cur_sum = nums[left] + nums[right];
            if(cur_sum < target || (left>start && nums[left]== nums[left-1])){
                ++left;
            }
            else if (cur_sum>target || (right< nums.size()-1 && nums[right]==nums[right+1])){
                --right;
            }
            else{
                res.push_back({nums[left++],nums[right--]});
            }
        }
        return res;
    }
};