#include<iostream>
#include<vector>

using namespace std;

//找缺失的哪个数，0~n之间
//int missingNumber(vector<int>& nums)
//{
//	int sum = 0;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		sum ^= i;
//		sum ^= nums[i];
//	}
//	sum ^= nums.size();
//	return sum;
//}



//找两个单身狗
//class Solution {
//public:
//	vector<int> singleNumbers(vector<int>& nums) {
//		int sum = 0;
//		for (int i = 0; i < nums.size(); ++i) {
//			sum ^= nums[i];     //两个数的异或---------相异为1
//		}
//		int m = 1;
//		while ((m&sum) == 0) {
//			m = m << 1;
//		}
//		int a = 0; int b = 0;
//		for (int i = 0; i < nums.size(); ++i) {
//			if ((nums[i] & m) == 0) {
//				a ^= nums[i];
//			}
//			else {
//				b ^= nums[i];
//			}
//		}
//		return vector<int> {a, b};
//	}
//};
