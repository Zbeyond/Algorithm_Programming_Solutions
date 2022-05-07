/*
定义代金券，花xi元购买可以当yi元使用，保证后者大于前者，只能购买一张
对于餐厅里的每种菜品,有价格ai和能够给予给他们的满意度bi,每种菜品至多只会点一份。
代金券是一次性无找零的，若本次消费的价格不高于代金券可以抵用的价，若本次消费的价格不高于代金券可以抵用的价格,那么可以使用代金券来抵付本次的所有消费;若本次消费的价格高于可抵用价格,那么还需要支付超出的部分
假设他们这次吃饭的预算是k元，请问他们能得到的最高满意度是多少?
输入第一行3个整数nmk,分别表示有n种代金券，餐厅的菜单有m种菜品，及预算为k元 
*/ 


# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
bool cmp1(vector<int>& a,vector<int>& b){
	return a[1] > b[1]; 
}
 
int main (){
	int m;
	int n;
	int k;
	cin>>n; 
	cin>>m;
	cin>>k;
	vector<vector<int> > ticket;
	vector<vector<int> > eat;
	for(int i = 0;i < n;i ++){
		vector<int> temp;
		int a;
		cin>>a;
		int b;
		cin>>b;
		temp.push_back(a);
		temp.push_back(b);
		ticket.push_back(temp);
	} 
	for(int i = 0;i < m;i ++){
		vector<int> temp;
		int a;
		cin>>a;
		int b;
		cin>>b;
		temp.push_back(a);
		temp.push_back(b);
		eat.push_back(temp);
	}
	sort(ticket.begin(),ticket.end(),cmp1);
	for(int i = 0;i < n;i ++){
		if(ticket[i][0] < k){
			k = k - ticket[i][0] + ticket[i][1];
			break;
		}
	}

	vector<vector<int> > dp(m,vector<int>(k+1,0));//m为物品的种类数量，k为背包容量，即为钱数 
	for(int i = 0;i < m;i ++){ //一分钱没有 
		dp[i][0] = 0;
   }

	for(int j = 1;j <= k;j ++){
		for(int i = 1;i < m;i ++){
		if(j >= eat[i][0]) {
		   dp[i][j] = max(dp[i-1][j],dp[i-1][j-eat[i][0]]+eat[i][1]);//不选这种物品 or 将这种物品放入背包 
		}
	}
}
	cout<<dp[m-1][k]<<endl;
	return 0;
}
