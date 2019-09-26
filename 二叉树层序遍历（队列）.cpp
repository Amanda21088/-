#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> v;
		if (root == NULL)
			return v;

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			int size = q.size();
			vector<int> vec;
			while (size--)
			{
				TreeNode* t = q.front();
				vec.push_back(q.front()->value);

				if (t->left)
				{
					q.push(t->left);
				}

				if (t->right)
				{
					q.push(t->right);
				}
			}
			v.push_back(vec);
		}
		return v;
	}
};
