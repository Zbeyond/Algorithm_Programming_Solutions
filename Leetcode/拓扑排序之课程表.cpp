/*
现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，
表示在选修课程 ai 前 必须 先选修 bi 。

例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。
如果不可能完成所有课程，返回 一个空数组 。

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
	int n;  // prerequisites的长度
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
	第一部分：建图，同时统计每个节点的入度。 
	*/ 
	map<int,vector<int> > graph; //图 
	map<int,int> indegree; //表示每个顶点的入度 
	for(int i = 0;i < prerequisites.size();i ++){
		vector<int> item = prerequisites[i];
		graph[item[0]].push_back(item[1]);
	    indegree[item[1]] ++; 
	}
	queue<int> q;
	
	
	
	//第二部分：将入度为0的节点push到队列中 
	//为了不遗漏，必须对原图进行遍历，而非indgree。例如，[[0,1],[0,2]]中，0的入度为0.
	//而统计indegree时，只统计子数组的第二个元素即1和2，indegree[0]是没有的，不会被遍历到。 
	for(map<int,vector<int> >::iterator it = graph.begin();it != graph.end();it ++){
		if(indegree[it->first]== 0){
			q.push(it->first);
		} 
	}
	
	//第三部分：bfs输出结果 
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
