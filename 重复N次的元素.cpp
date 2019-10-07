#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		size_t N = A.size() / 2;
		// 用unordered_map统计每个元素出现的次数
		unordered_map<int, int> m;
		for (auto e : A)
			m[e]++;
		// 找出出现次数为N的元素  
		for (auto& e : m)
		{
			if (e.second == N)
				return e.first;
		}
		return 0;
	}
};