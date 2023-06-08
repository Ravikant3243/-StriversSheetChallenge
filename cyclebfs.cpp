#include<bits/stdc++.h>


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
int detectCycleInDirectedGraph(int v, vector < pair < int, int >> & edges) {
         vector<int>ind(v+1,0);
         vector<int>adj[v+1];
         vector<int>vis(v+1,0);
         vector<int>ans;
          for(int i=0;i<edges.size();i++){
              int fi=edges[i].first;
              int sec=edges[i].second;
              adj[fi].push_back(sec);
              ind[sec]++;

          }
          for (int i = 1; i <= v; i++) {
            if (!vis[i] and ind[i] == 0)
              bfs(i, ans, adj, vis, ind);
          }
          if(ans.size()==v)return 0;
          return 1;
}
