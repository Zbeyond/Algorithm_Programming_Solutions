/* 
����һ������������?2-9?���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء�

�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
	    {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
*/ 


# include<iostream>
# include<string>
# include<map>
# include<vector>
using namespace std;
map<char,string> dict{
	    {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
	};
void dfs(string& s,string temp,vector<string>& res,int loc){
	if(s.size() == temp.size()){
		res.push_back(temp);
		return;
	}
	char c = s[loc];
	const string& letters = dict.at(c);
	for(int i = 0;i < letters.size();i ++){
		temp.push_back(letters[i]);
		dfs(s,temp,res,loc+1);
		temp.pop_back();
	} 
}
int main (){
	string s;
	cin>>s;
	vector<string> res;

	dfs(s,"",res,0);
	for(int i = 0;i < res.size();i ++){
		cout<<res[i]<<endl;
	}
	return 0;
}
