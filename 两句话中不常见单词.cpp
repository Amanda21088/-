#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	vector<string> uncommonFromSentences(string A, string B) {
		unordered_map<string, int> um;
		vector<string> v;
		PartionWord(A, um);
		PartionWord(B, um);

		for (auto e : um)
		{
			if (e.second == 1)
				v.push_back(e.first);
		}
		return v;
	}
	void PartionWord(const string& str, unordered_map<string, int>& m)
	{
		string Word;
		int start = 0;
		int last = 0;
		do
		{
			last = str.find(' ', start);
			Word = str.substr(start, last - start);
			m[Word]++;
			start = last + 1;
		} while (last != -1);
	}
};
