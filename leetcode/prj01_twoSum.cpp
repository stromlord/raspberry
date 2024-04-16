#include<iostream>
#include<vector>
using namespace std;

/* 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。
*/

class Solution{
	public:
		vector<int> twoSum(vector<int>& nums, int target){
			int n = nums.size();
			for (int i=0; i<n; ++i){
				for (int j=i+1; j<n; ++j){
					if (nums[i] + nums[j] == target){return {i, j};}
				}
			}
			return {};
		}
};

int main(){
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	Solution s;
	vector<int> result = s.twoSum(nums, target);
	cout << "{" << result[0] << ", " << result[1] << "}" << endl; 
	return 0;
}
