#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> vd;

		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			vector<int> v;
			int size = q.size();
			while (size--)
			{
				TreeNode* t = q.front();
				v.push_back(q.front()->val);
				q.pop();
				if (t->left)
					q.push(t->left);
				if (t->right)
					q.push(t->right);
			}
			double sum = 0;
			for (int i = 0; i < v.size(); i++)
			{
				sum += v[i];
			}
			double tmp = sum / v.size();
			vd.push_back(tmp);
			v.clear();
		}
		return vd;
	}
};

