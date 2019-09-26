#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode * root) {
		// write your code here
		vector<int> w;
		vector<vector<int>> vec;
		stack<vector<int>> s;
		queue<TreeNode*> q;

		if (root == nullptr)
			return vec;

		q.push(root);

		while (!q.empty()){
			int size = q.size();
			while (size--){
				TreeNode* front = q.front();
				w.push_back(front->val);
				q.pop();
				if (front->left != nullptr)
					q.push(front->left);
				if (front->right != nullptr)
					q.push(front->right);
			}
			s.push(w);
			w.clear();
		}

		while (!s.empty()){
			vec.push_back(s.top());
			s.pop();
		}

		return vec;

	}
};

