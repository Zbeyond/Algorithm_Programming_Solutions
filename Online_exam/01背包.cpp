/*
�������ȯ����xiԪ������Ե�yiԪʹ�ã���֤���ߴ���ǰ�ߣ�ֻ�ܹ���һ��
���ڲ������ÿ�ֲ�Ʒ,�м۸�ai���ܹ���������ǵ������bi,ÿ�ֲ�Ʒ����ֻ���һ�ݡ�
����ȯ��һ����������ģ����������ѵļ۸񲻸��ڴ���ȯ���Ե��õļۣ����������ѵļ۸񲻸��ڴ���ȯ���Ե��õļ۸�,��ô����ʹ�ô���ȯ���ָ����ε���������;���������ѵļ۸���ڿɵ��ü۸�,��ô����Ҫ֧�������Ĳ���
����������γԷ���Ԥ����kԪ�����������ܵõ������������Ƕ���?
�����һ��3������nmk,�ֱ��ʾ��n�ִ���ȯ�������Ĳ˵���m�ֲ�Ʒ����Ԥ��ΪkԪ 
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

	vector<vector<int> > dp(m,vector<int>(k+1,0));//mΪ��Ʒ������������kΪ������������ΪǮ�� 
	for(int i = 0;i < m;i ++){ //һ��Ǯû�� 
		dp[i][0] = 0;
   }

	for(int j = 1;j <= k;j ++){
		for(int i = 1;i < m;i ++){
		if(j >= eat[i][0]) {
		   dp[i][j] = max(dp[i-1][j],dp[i-1][j-eat[i][0]]+eat[i][1]);//��ѡ������Ʒ or ��������Ʒ���뱳�� 
		}
	}
}
	cout<<dp[m-1][k]<<endl;
	return 0;
}
