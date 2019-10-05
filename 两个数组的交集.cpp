class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		//对num1去重
		unordered_set<int> s1;
		for (auto e : nums1)
		{
			s1.insert(e);
		}
		//对num2去重
		unordered_set<int> s2;
		for (auto e : nums2)
		{
			s2.insert(e);
		}
		vector<int> v;
		for (auto e : s1)
		{
			if (s2.find(e) == s2.end())
				continue;
			else
				v.push_back(e);
		}
		return v;
	}
};