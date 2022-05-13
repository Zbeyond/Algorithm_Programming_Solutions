# include<iostream>
# include<vector>
# include<stack>
using namespace std;
class Treenode{
public:
	int val;
	Treenode(int value){
		this->val = value;
	}
	Treenode* left;
	Treenode* right;
};
Treenode* buildtree(vector<int>& data,int loc){
	if(loc >= data.size()){
		return NULL;
	}
	Treenode* node = new Treenode(data[loc]);
	node->left = buildtree(data,2*loc+1);
	node->right = buildtree(data,2*loc+2);
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
    node = buildtree(data,0);
    //�����Ǵ������룬�������������Լ��������̡�
    Treenode* cur = node;
    vector<int> res;

    while(cur != NULL || !helper.empty()){
    	while(cur != NULL){
    		helper.push(cur);
    		cur = cur->left;
		}//�����ߣ���Ͷ��·�������� 
		cur = helper.top();
	    helper.pop();
	    //�������ʱ��������Ͷ��·������ұ��� 
	    res.push_back(cur->val);
	    cur = cur->right;
	    //��������Ͷ��·���������� 
	}
	for(int i = 0;i < data.size();i ++){
		cout<<res[i]<<endl;
	}
	return 0;
} 
