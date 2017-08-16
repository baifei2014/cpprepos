#include<iostream>
#include<vector>
using namespace std;


/** 
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 先序遍历
void DLR(TreeNode *T)
{
    if(T){
        cout<<T->val;
        DLR(T->left);
        DLR(T->right);
    }
}
// 中序遍历
void LDR(TreeNode *T)
{
    if(T){
        LDR(T->left);
        cout<<T->val;
        LDR(T->right);
    }
}
// 后序遍历
void LRD(TreeNode *T)
{
    if(T){
        LRD(T->left);
        LRD(T->right);
        cout<<T->val;
    }
}
// 输入先序遍历结果和中序遍历结果重建二叉树并返回
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode* T;
        getRoot(T, pre, vin);
        cout<<"先序遍历::"<<endl;
        DLR(T);
        cout<<"\n中序遍历::"<<endl;
        LDR(T);
        cout<<"\n后序遍历::"<<endl;
        LRD(T);
        cout<<endl;
        return T;
    }
    int getRootPos(vector<int> pre, vector<int> vin){
        int *iter, *item;
        for(iter = pre.begin(); iter != pre.end(); ++iter){
            for(item = vin.begin(); item != vin.end(); ++item){
                if(*iter == *item){
                    return *iter;
                }
            }
        }
    }
    void getRoot(TreeNode* &T, vector<int> pre,vector<int> vin){
        if(vin.empty()){
            T = NULL;
            return;
        }
        int root = getRootPos(pre, vin);
        T = new TreeNode(root);
        int tag = 0;
        vector<int> vinl;
        vector<int> vinr;
        for(int i = 0; i<vin.size(); ++i){
            if(vin[i] == root){
                tag = 1;
            }
            if(vin[i] != root && tag == 0){
                vinl.push_back(vin[i]);
            }
            if(vin[i] != root && tag == 1){
                vinr.push_back(vin[i]);
            }
        }

        getRoot(T->left, pre, vinl);
        getRoot(T->right, pre, vinr);

        
    }
};

void main(){
    Solution solute;
    vector<int> pre, vin;
    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(4);
    pre.push_back(7);
    pre.push_back(3);
    pre.push_back(5);
    pre.push_back(6);
    pre.push_back(8);

    vin.push_back(4);
    vin.push_back(7);
    vin.push_back(2);
    vin.push_back(1);
    vin.push_back(5);
    vin.push_back(3);
    vin.push_back(8);
    vin.push_back(6);
    
    solute.reConstructBinaryTree(pre, vin);
}
