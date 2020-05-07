/**
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
**/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
	public:
	bool isCousins(TreeNode* root, int x, int y)
	{
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty())
		{
			int s=q.size();
			int xx=0;
			int yy=0;
			for(int i=0;i<s;i++)
			{
				TreeNode* p=q.front();
				q.pop();
				int left=0,right=0;
				if(p->left!=NULL)
				{
					left=1;
					q.push(p->left);
				}
				if(p->right!=NULL)
				{
					right=1;
					q.push(p->right);
				}
				if(left==1 && right==1)
				{
					if((p->left->val==x && p->right->val==y) || (p->left->val==y && p->right->val==x))
						return false;
				}
				if(left==1)
				{
					if(p->left->val==x)
						xx=1;
					if(p->left->val==y)
						yy=1;
				}
				if(right==1)
				{
					if(p->right->val==x)
						xx=1;
					if(p->right->val==y)
						yy=1;
				}
			}
			if(xx==1 && yy==1)
				return true;
		}
		return false;
	}
};
