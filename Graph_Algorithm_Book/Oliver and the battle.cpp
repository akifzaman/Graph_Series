#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,1,-1,-1,0,1};

bool check(int x, int y, int r, int c){
 if(x>=0 && x<r && y>=0 && y<c) return 1;
 return 0;
}

int main(){
 int t;
 cin>>t;
 while(t--){
 int r, c;
 cin>>r>>c;
 int mat[r][c];
 for(int i=0;i<r;i++) for(int j = 0;j<c;j++) cin>>mat[i][j];
 int visited[r+3][c+3];
 memset(visited,0,sizeof(visited));
 int troop =0, cnt=0;

for(int i=0;i<r;i++){
 for(int j = 0;j<c;j++){
 int cn=0;
 if(visited[i][j]==0 && mat[i][j]==1){
 queue<pair<int,int>> q;
 q.push(make_pair(i,j));
 visited[i][j] = 1;
 cn = 1;
 while(!q.empty()){
 pair<int,int> p = q.front();
 q.pop();
 int X = p.first;
 int Y = p.second;
 for(int i=0;i<8;i++){
 int newx = X + dx[i];
 int newy = Y + dy[i];
 if(check(newx,newy,r,c) && visited[newx][newy]==0 && mat[newx][newy]){
 q.push(make_pair(newx,newy));
 visited[newx][newy] = 1;
 cn++;
 }
 }
 }
 cnt = max(cnt, cn);
 troop++;
 }
 }
 }
cout<<troop<<" "<<cnt<<endl;
 }
 return 0;
}
