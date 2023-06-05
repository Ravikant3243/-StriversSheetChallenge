#include <bits/stdc++.h> 
void bfs(int st,vector<int>&ans,vector<int>adj[],vector<int>&vis,vector<int>&ind){
     queue<int>q;
     q.push(st);
     vis[st]=1;
     while(!q.empty()){
          st=q.front();
          q.pop();
          ans.push_back(st);
          for(auto e:adj[st]){
              if(!vis[e]){
                  ind[e]--;
                  if(ind[e]==0){
                      vis[e]=1;
                      q.push(e);
                  }
              }
          }
     }
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
         vector<int>ind(v,0);
         vector<int>adj[v];
         vector<int>vis(v,0);
         vector<int>ans;
          for(int i=0;i<e;i++){
              ind[edges[i][1]]++;
              adj[edges[i][0]].push_back(edges[i][1]);
          }
         for(int i=0;i<v;i++){
             if(!vis[i] and ind[i]==0)bfs(i,ans,adj,vis,ind);
         }
         return ans;
}
