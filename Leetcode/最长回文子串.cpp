//给你一个字符串 s，找到 s 中最长的回文子串。


# include<iostream>
# include<string>
# include<vector>
using namespace std;
vector<int> helper(string s,int left,int right);
int main(){
	string in;
	cin>>in;
	int len = in.size();
	int length = 1;
	int start = 0;
	int end = 0;
	for(int i = 0;i < len;i ++){
		vector<int> res1 = helper(in,i,i);
		vector<int> res2 = helper(in,i,i+1);
		if(res1.size() > length){
			start = res1[0];
			end = res1[1];
		    length = end-start+1;
		}
		if(res2.size() > length){
			start = res2[0];
			end = res2[1];
		    length = end-start+1;
		}
	}
	cout<<in.substr(start,length)<<endl;
	return 0;
}
vector<int> helper(string s,int left,int right){
	while(left >= 0 && right < s.size() && s[left] == s[right]){
		left --;
		right ++;
	}
	vector<int> res;
	res.push_back(left+1);
	res.push_back(right-1);
	return res;
}
