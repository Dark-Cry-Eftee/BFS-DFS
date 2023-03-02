#include<bits/stdc++.h>
using namespace std;
vector<int>Node_Vec[100];
int parent[10];
int level[10];
void BFS(int source)
{
    queue<int>q;
    for(int i=1;i<8;i++)
    {
        level[i] = -1;
        parent[i]=i;
    }
    level[source] = 0;
    q.push(source);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int j = 0; j < Node_Vec[u].size(); j++)
        {
            int v = Node_Vec[u][j];
            if(level[v] == -1)
            {
                level[v] = level[u]+1;
                q.push(v);
                parent[v] = u;
            }
        }
    }
}
void path(int destination)
{
    if(parent[destination] != destination)
    {
       cout<<destination<<"->";
       path(parent[destination]);
    }
}
int main()
{
    int node_no, edge_no,input;
    printf("Enter the number of nodes: ");
    scanf("%d", &node_no);
    printf("Enter the number of edges: ");
    scanf("%d", &edge_no);
    cout<<"Enter connection : "<<endl;
    for(int i = 1; i <= edge_no; i++)
    {
        int nodeA, nodeB;
        scanf("%d %d", &nodeA, &nodeB);
        Node_Vec[nodeA].push_back(nodeB); // for directed graph
        Node_Vec[nodeB].push_back(nodeA);
    }
    cout<<"Adjacency List:"<<endl;
//Print Node Adjacency List by traversing the list
    for(int i = 1; i <= node_no; i++)
    {
        printf("%d -> ", i);
        for(int j = 0; j < Node_Vec[i].size(); j++)
        {
            cout<<(Node_Vec[i][j]);
        }
        cout<<endl;
    }
    BFS(1);

    for(int i=0;i<node_no;i++)
    {

        cout<<level[i]<<endl;
    }
    cout<<"Enter the node u want to go to:";
    cin>>input;
    path(input);


}

