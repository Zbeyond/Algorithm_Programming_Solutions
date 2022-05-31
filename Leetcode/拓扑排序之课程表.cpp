/*
�������ܹ��� numCourses �ſ���Ҫѡ����Ϊ 0 �� numCourses - 1������һ������ prerequisites ������ prerequisites[i] = [ai, bi] ��
��ʾ��ѡ�޿γ� ai ǰ ���� ��ѡ�� bi ��

���磬��Ҫѧϰ�γ� 0 ������Ҫ����ɿγ� 1 ��������һ��ƥ������ʾ��[0,1] ��
������Ϊ��ѧ�����пγ������ŵ�ѧϰ˳�򡣿��ܻ��ж����ȷ��˳����ֻҪ���� ����һ�� �Ϳ����ˡ�
���������������пγ̣����� һ�������� ��

*/ 

# include<iostream>
# include<vector>
# include<map>
# include<queue>
# include<algorithm> 
using namespace std;
int main(){
//	int numCourses; 
//	cin>>numCourses;
	int n;  // prerequisites�ĳ���
	cin>>n;
	vector<vector<int> > prerequisites;
	for(int i = 0;i < n;i ++){
		vector<int> temp;
		int a,b;
		cin>>a;
		cin>>b;
		temp.push_back(a);
		temp.push_back(b);
		prerequisites.push_back(temp);
	}
	
	/*
	��һ���֣���ͼ��ͬʱͳ��ÿ���ڵ����ȡ� 
	*/ 
	map<int,vector<int> > graph; //ͼ 
	map<int,int> indegree; //��ʾÿ���������� 
	for(int i = 0;i < prerequisites.size();i ++){
		vector<int> item = prerequisites[i];
		graph[item[0]].push_back(item[1]);
	    indegree[item[1]] ++; 
	}
	queue<int> q;
	
	
	
	//�ڶ����֣������Ϊ0�Ľڵ�push�������� 
	//Ϊ�˲���©�������ԭͼ���б���������indgree�����磬[[0,1],[0,2]]�У�0�����Ϊ0.
	//��ͳ��indegreeʱ��ֻͳ��������ĵڶ���Ԫ�ؼ�1��2��indegree[0]��û�еģ����ᱻ�������� 
	for(map<int,vector<int> >::iterator it = graph.begin();it != graph.end();it ++){
		if(indegree[it->first]== 0){
			q.push(it->first);
		} 
	}
	
	//�������֣�bfs������ 
	vector<int> res;
	while(!q.empty()){
		int cur = q.front();
		res.push_back(cur);
		q.pop();
		for(int i = 0;i < graph[cur].size();i ++){
			indegree[graph[cur][i]] --;
			if(indegree[graph[cur][i]] == 0){
				q.push(graph[cur][i]);
			}
		}
	} 
	reverse(res.begin(),res.end());
	for(int i = 0;i < res.size();i ++){
		cout<<res[i]<<endl;
	}
	return 0;
} 
