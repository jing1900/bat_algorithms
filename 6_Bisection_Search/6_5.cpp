/*
		问题：
			给定一颗完全二叉树的头结点head，返回这颗树的节点数，如果完全二叉树的节点数为N，请事先时间复杂度低于O（N）的解法
			
		解题思路：
			最优解的思路来自二分搜索。完全二叉树，添加节点是从最后一层节点开始，从左往后添加，这一层满了，才开始下一层。删除过程也是同样的逆过程。
			1，先找到二叉树最左的节点，（用来统计二叉树的高度）。其最左的节点，一定是在最后一层上的，
			2，我们先找到二叉树的跟节点的右子树的最左节点，如果这个的最左节点能到最后一层，那么说明这颗二叉树根节点的左子树一定是棵满二叉树。可以根据满二叉树的节点公式，计算出左子树的节点个数，再加上根的，剩下的就是右子树的节点个数了。我们可以用递归的方式，在右子树上进行同样的过程。
			3，但如果右子树没能到最后一层，说明右子树同样也是一颗满二叉树，用满二叉树的性质即可计算右子树的节点。左边的递归即可。
			最优解的时间复杂度为O（logH^2),H为树高。

*/
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class CountCompleteTree
{
public:
	//传入二叉树的根节点，返回树的节点数
	int count(TreeNode* root)
	{
		if(!root)
			return 0;
		//计算左子树高度
		int lenOfLeft = DepthOfTree((*root).left);
		//计算右子树高度
		int lenOfRight = DepthOfTree((*root).right);
		//如果左右子树等高，那么左子树一定是个满二叉树，套用节点公式2^树高-1，对于右子树则递归求解
		if(lenOfLeft == lenOfRight)
			//这里的-1刚好和根节点抵消
			return pow(2.0,lenOfLeft)+count((*root).right);
		//如果左右两边不等高，根据完全二叉树的性质，右边肯定满二叉树
		else
			return pow(2.0,lenOfRight)+count((*root).left);
	}

	//返回传入树的高度
	int DepthOfTree(TreeNode *root)
	{
		if(!root)
			return 0;
		TreeNode *p = root;
		//树高
		int len = 0;
		while(p)
		{
			len++;
			//一直沿着左孩子走
			p = (*p).left;
		}
		return len;
	}
};
int main()
{
	return 0;
}
