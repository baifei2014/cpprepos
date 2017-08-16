#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
// 先序遍历
void DLR(TreeNode* T)
{
    if(T){
        cout<<T->val;
        DLR(T->left);
        DLR(T->right);
    }
}
class Solution {
public:
    vector<vector<int> > result;
    vector<int> lineresult;
    vector<TreeNode*> pack1;
    vector<TreeNode*> pack2;
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<TreeNode*> pack;
        pack.push_back(pRoot);
        getLineStruct(pack, 1);
        return result;
    }
    void getLineStruct(vector<TreeNode*> pack, int pos){
        if(pack.empty()){
            return;
        }
        int i;
        pack1.clear();
        pack2.clear();
        lineresult.clear();
        if(pos % 2 == 0){
            for(i = 0; i < pack.size(); ++i){
                if(pack[i]){
                    lineresult.push_back(pack[i]->val);
                    pack1.push_back(pack[i]->right);
                    pack1.push_back(pack[i]->left);
                }
            }
        }else{
            for(i = 0; i < pack.size(); ++i){
                if(pack[i]){
                    lineresult.push_back(pack[i]->val);
                    pack1.push_back(pack[i]->left);
                    pack1.push_back(pack[i]->right);    
                }
            }
        }
        for(i = pack1.size()-1; i>=0;i--){
            pack2.push_back(pack1[i]);
        }
        result.push_back(lineresult);
        getLineStruct(pack2, pos+1);
    }
    void CreateBiTree(TreeNode* &T)
    {
        int ch;
        cin>>ch;
        if(ch==0) T=NULL;
        else{
            T = new TreeNode(ch);
            CreateBiTree(T->left);
            CreateBiTree(T->right);
        }
    }
    
};
void main(){
    Solution solute;
    TreeNode* T;
    solute.CreateBiTree(T);
    DLR(T);
    vector<vector<int> > result;
    result = solute.Print(T);
    cout<<endl;
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j){
            cout<<result[i][j]<<endl;
        }
    }
}
