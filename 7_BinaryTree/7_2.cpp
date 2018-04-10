/*
问题：二叉树的按层遍历，要求打印行号或者按行打印。

这道题的难点在于在何处打印换行，

/*
这里用两个指针，last和nlast，分别表示该行和下一行的最后一个元素

对树进行宽度优先遍历，遍历到last，说明该换行了，现在只需将last设为nlast即可

而nlast只需一直更新为宽度优先遍历队列中最新加入的节点即可。它一定是目前发现的下一个行的最右节点

过程：

1，最先让last = root，然后打印这个节点，并将该节点的左孩子和右孩子依次放入队列，
每放入元素时，将nlast更新为指向该元素。

2，此时发现弹出的节点root与last相等，那么该换行了，并令last = nlast，然后弹出队头元素，并将队头元素的左右孩子依次放入
，并更新nlast
*/
#include<bits/stdc++.h>
using namespace std;
struct treenode
{
    int val;
    struct treenode *left,*right;
    treenode(int x):val(x),left(NULL),right(NULL){}
};
class Solution
{
public:
    vector<vector<int> > solution(treenode *root)
    {

        vector<vector<int> > res;
        if(!root)//处理特殊情况
            return res;

        queue<treenode *> q;
        q.push(root);

        treenode *last = root;
        treenode *nlast = NULL;
        treenode *p = NULL;

        vector<int> r;//可以放外面
        while(!q.empty())
        {

            p = q.front();//这里是front
            q.pop();

            if(p->left)
            {
                q.push(p->left);
                nlast = p->left;

            }
            if(p->right)
            {
                q.push(p->right);
                nlast = p->right;
            }
            r.push_back(p->val);
            if(p == last)
            {
                last = nlast;
                res.push_back(r);
                r.clear();//清空vector r
            }
        }
        return res;
    }
};
