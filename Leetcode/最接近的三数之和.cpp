/*
����һ������Ϊ n ����������nums�� һ��Ŀ��ֵ?target������� nums ��ѡ������������ʹ���ǵĺ���?target?��ӽ���

�������������ĺ͡�

�ٶ�ÿ������ֻ����ǡ��һ���⡣

*/


# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> in;
	for(int i = 0;i < n;i ++){
		int c;
		cin>>c;
		in.push_back(c);
	}
	int target;
	cin>>target;
	sort(in.begin(),in.end());
	int res = -9999;
	for(int i = 0;i < in.size();i ++){
		int left = i + 1;
		int right = in.size()-1;
		while(left < right){
			int sum = in[left] + in[right] + in[i];
			if(sum == target){
				cout<<sum<<endl;
				break;
			}
			if(abs(sum-target) < abs(res-target)){
				res = sum;
			}
			if(sum > target){
				right --;
			}
			if(sum < target){
				left ++;
			}
		}
	}
	cout<<res<<endl;
} 
