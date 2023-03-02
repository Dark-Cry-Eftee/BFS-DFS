#include<bits/stdc++.h>
using namespace std;
vector<int>Node_Vec[100];
int color[10];
int parent[10];
void DFS(int source)
{
    stack<int>S;
    int white = 0, gray = 1, black = 2;
    for(int i=0; i<=10; i++)
    {
        color[i]=white;
        parent[i]=i;
    }
    S.push(source);
    color[source]=gray;
    while (!S.empty())
    {
        int u=S.top();
        S.pop();

        for(int j=0; j<Node_Vec[u].size(); j++)
        {
            int v =Node_Vec[u][j];
            if(color[v]== white)
            {
                color[v] = gray;
                S.push(v);
                parent[v]=u;

            }
               color[source]=black;
        }

    }
}
void path(int dest)
{
    if(parent[dest] != dest)
    {
        cout<<dest<<"->";
        path(parent[dest]);

    }
}
int main()
{
    int node_no, edge_no, dest;
    cout<<"Enter the number of nodes :";
    cin>>node_no;
    cout<<"Enter the number of edges :";
    cin>>edge_no;
    cout<<"Enter connection : "<<endl;
    for(int i=1; i<=edge_no; i++)
    {
        int nodeA, nodeB;
        cin>>nodeA;
        cin>>nodeB;
        Node_Vec[nodeA].push_back(nodeB);
        Node_Vec[nodeB].push_back(nodeA);
    }
    cout<<"Adjacency List:"<<endl;
    //Print Node Adjacency List by traversing the list
    for(int i=1; i<=node_no; i++)
    {
        printf("%d ->", i);
        for(int j=0; j< Node_Vec[i].size(); j++)
        {
            cout<<Node_Vec[i][j];

        }
        cout<<endl;
    }
    DFS(1);
    for(int i=0; i<10; i++)
    {
        if(color[i]>-1)
        {
            cout<<color[i]<<endl;
        }
    }
    cout<<"Enter the destination: ";
    cin>> dest;
    path(dest);
}

