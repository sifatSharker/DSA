#include<bits/stdc++.h>
using namespace std;

int main(){
    int nodes;
    cin>>nodes;

    int graph[nodes][nodes];

    int edges;
    cin>>edges;

    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            if(i==j){
                graph[i][j]=0;
            }
            else {
                graph[i][j]=-1;
            }
        }
    }

    for(int i=0;i<edges;i++){
        int v1,v2;
        cin>>v1>>v2;

        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    int root;
    cout<<"Enter root nodes:";
    cin>>root;

    stack<int>q;
    q.push(root);

    int visited[nodes]={0};
    while(!q.empty()){
            int node = q.top();
            q.pop();
            if(visited[node]) continue;
            cout<<node<<" ";
            visited[node]=1;

            for(int adj_node=0;adj_node<nodes;adj_node++){
                if(graph[node][adj_node]>0 && !visited[adj_node]){
                    q.push(adj_node);
                }
            }

    }





    return 0;
}
