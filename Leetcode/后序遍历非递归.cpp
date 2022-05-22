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
	//��������У����һ�����ʵ��Ǹ��ڵ㣬��pre�������ж��Ƿ� 
	Treenode* pre = NULL;
	stack<Treenode*> helper;
	while(cur != NULL || !helper.empty()){
		if(cur != NULL){
			helper.push(cur); 
			cur = cur->left;
		}else{
		//��ʾ������������ͷ/���ڳ�ջ 
		cur = helper.top();
		if(cur->right == NULL || cur->right == pre ) { //û�����ҵĿռ䣬�������ߣ��ص����ڵ㡣 
		//��һ����������������ص����ڵ㣬û���������� 
		//�ڶ�����������������ص����ڵ㡣 
		//�����������Ҫ�Ƚ��������������������������ٷ��ء� 
		    helper.pop();
			res.push_back(cur->val);
			pre = cur;
			cur = NULL;
		}else{ //���������ߵĿռ䣬�ͼ������� 
			cur = cur->right;
		}
      }    	
	}
	for(int i = 0;i < data.size();i ++){
		cout<<res[i]<<endl;
	}
	return 0;
}
