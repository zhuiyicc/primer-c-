#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <stack>
using namespace std;
class BinStrTree;
class TreeNode{
    public:
        friend BinStrTree;
    protected://定义在protected里，让BinStrTree操作TreeNode
        TreeNode(const string& x):value(x),count(1),left(nullptr),right(nullptr){}
        TreeNode(const TreeNode& a):value(a.value),count(a.count),left(a.left),right(a.right){}
        TreeNode& operator=(const TreeNode& a){
            value = a.value;
            count = a.count;
            left = a.left;
            right = a.right;
            return *this;
        }
        ~TreeNode(){}
    private:
        string value;
        int count;
        TreeNode *left;
        TreeNode *right;
        
};
class BinStrTree{
    public:
        BinStrTree(const string& x):root(new TreeNode(x)){}
        BinStrTree(const BinStrTree& a):root(a.root){}
        ~BinStrTree(){
            if(root != nullptr){//删除整颗树
                stack<TreeNode *> st;
                st.push(root);
                for(;!st.empty();){
                    auto p = st.top();
                    st.pop();
                    if(p->left != nullptr) st.push(p->left);
                    if(p->right != nullptr) st.push(p->right);
                    delete p;
                }
                delete root;
            }
        }
    private:
        TreeNode *root;
};
int main(){
    return 0;
}
