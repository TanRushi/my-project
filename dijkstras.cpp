#include<iostream>
#include<climits>
using namespace std;
#define MAX_V 100
int minDistance(int dist[],bool visited[],int n){
int min=INT_MAX;
int minIndex= -1;
for(int v=0;v<n;v++){
if(!visited[v] && dist[v]<= min){
min= dist[v];
minIndex= v;
}
}
return minIndex;
}
void dijkstras(int graph[MAX_V][MAX_V],int source,int dist[],int n){
bool visited[MAX_V];
for(int i=0;i<n;i++){
dist[i]=INT_MAX;
visited[i]=false;
}
dist[source]=0;
for(int count=0;count<n-1; count++){
int u=minDistance(dist,visited,n);
visited[u]=true;
for(int v=0;v<n;v++){
if(!visited[v] && graph[u][v] && dist[u]!=INT_MAX &&
dist[u]+graph[u][v]<= dist[v]){
dist[v]= dist[u]+ graph[u][v];
}
}
}
}
int main(){
int n=5;
int graph[MAX_V][MAX_V]={
{0,10,20,0,3},{10,0,5,0,2},{20,5,0,11,0},{0,0,11,0,15},{3,2,0,15,0}
};
int dist[MAX_V];
dijkstras(graph,0,dist,n);
cout<<"Vertex distance from source"<<endl;
for(int i=0;i<n;i++){
cout<< i <<" "<< dist[i] <<endl;
}
return 0;
}
/*
Vertex distance from source
0 0
1 5
2 10
3 18
4 3
[Process completed - press Enter]
*/