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
Treenode* buildTree(vector<int>& data,int loc){
	if(loc >= data.size()){
		return NULL;
	}
	Treenode* node = new Treenode(data[loc]);
	node->left = buildTree(data,2*loc+1);
	node->right = buildTree(data,2*loc+2);
	return node;
}
int main(){
	stack<Treenode*> helper;
	int n;
	cin>>n;
	vector<int> data;
	for(int i = 0;i < n;i ++){
		int a;
		cin>>a;
		data.push_back(a);
	}
    Treenode* node = new Treenode(data[0]);
    node = buildTree(data,0);
    //上面是处理输入，包括接收输入以及建树过程。
    Treenode* cur = node;
    vector<int> res;
 
    while(!helper.empty() || cur != NULL){
    	while(cur){
    		helper.push(cur);
    		//前序遍历时，边往左下角走边加入结果。 
    		res.push_back(cur->val);
    		cur = cur->left;
		}
		cur = helper.top();
		helper.pop();
		cur = cur->right;
		//走投无路时才走右边 
	}
	for(int i = 0;i < data.size();i ++){
		cout<<res[i]<<endl;
	}
	return 0;
}
