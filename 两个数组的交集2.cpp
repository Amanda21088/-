class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> s1;
		for (auto e : nums1)
		{
			s1[e]++;
		}
		unordered_map<int, int> s2;
		for (auto e : nums2)
		{
			s2[e]++;
		}
		vector<int> v;
		for (auto e : s1)
		{
			auto s2tmp = s2.find(e.first);
			if (s2tmp != s2.end())
			{
				int tmp = s2tmp->second < e.second ? s2tmp->second : e.second;
				while (tmp--)
				{
					v.push_back(e.first);
				}
			}
		}
		return v;
	}
};