#define _CRT_SECURE_NO_WARNINGS 1
class Solution{
public:
	int singleNumber(vector<int>& nums)
	{
		int value = 0;
		for (size_t i = 0; i < nums.size(); i++)
		{
			value ^= nums[i];//相同为0，不同为1
		}
		return value;
	}
};