/* 
给定一个仅包含数字?2-9?的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
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
