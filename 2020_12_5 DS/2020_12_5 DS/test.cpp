#include<iostream>
#include<vector>

using namespace std;

//��ȱʧ���ĸ�����0~n֮��
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



//����������
//class Solution {
//public:
//	vector<int> singleNumbers(vector<int>& nums) {
//		int sum = 0;
//		for (int i = 0; i < nums.size(); ++i) {
//			sum ^= nums[i];     //�����������---------����Ϊ1
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
