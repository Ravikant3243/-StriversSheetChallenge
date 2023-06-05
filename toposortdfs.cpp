#include <bits/stdc++.h> 
void dfs(int curr,stack<int>&st,vector<int>adj[],vector<bool>&vis){
               vis[curr]=1;
               for(auto e:adj[curr])if(!vis[e])dfs(e,st,adj,vis);
               st.push(curr); 
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
       vector<int>adj[v];
       stack<int>st;
       vector<bool>vis(v,0);
       for(int i=0;i<e;i++){
           adj[edges[i][0]].push_back(edges[i][1]);
           
       }
       vector<int>ans;
       for(int i=0;i<v;i++){
         if(!vis[i])dfs(i,st,adj,vis);
       }
       while(!st.empty()){
           ans.push_back(st.top());
           st.pop();
       }
       return ans;
}
