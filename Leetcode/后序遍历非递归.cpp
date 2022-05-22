# include<iostream>
# include<stack>
# include<vector>
using namespace std;
class Treenode{
public:
	int val;
	Treenode* left;
	Treenode* right;
	Treenode(int val){
		this->val = val;
	}
};
Treenode* buildtree(vector<int>& data,int loc){
	if(loc >= data.size()) return NULL;
	Treenode* node = new Treenode(data[loc]);
	node->left = buildtree(data,2*loc+1);
	node->right = buildtree(data,2*loc+2);
	return node;
}
int main(){
	vector<int> res;
	int n;
	cin>>n;
	vector<int> data;
	for(int i = 0;i < n;i ++){
		int temp;
		cin>>temp;
		data.push_back(temp);
	}
	Treenode* root = buildtree(data,0);
	Treenode* cur = root;
	//后序遍历中，最后一个访问的是根节点，用pre变量来判断是否 
	Treenode* pre = NULL;
	stack<Treenode*> helper;
	while(cur != NULL || !helper.empty()){
		if(cur != NULL){
			helper.push(cur); 
			cur = cur->left;
		}else{
		//表示左子树遍历到头/正在出栈 
		cur = helper.top();
		if(cur->right == NULL || cur->right == pre ) { //没有往右的空间，就往上走，回到根节点。 
		//第一种情况：从左子树回到根节点，没有右子树。 
		//第二种情况：从右子树回到根节点。 
		//这两种情况都要先将左子树或者右子树加入结果后再返回。 
		    helper.pop();
			res.push_back(cur->val);
			pre = cur;
			cur = NULL;
		}else{ //还有往右走的空间，就继续往右 
			cur = cur->right;
		}
      }    	
	}
	for(int i = 0;i < data.size();i ++){
		cout<<res[i]<<endl;
	}
	return 0;
}
