//weighted directed graph
#include<bits/stdc++.h>
using namespace std;
void addEgde(list<pair<int,int>> graph[], int src, int dest, int weight)
{
    graph[src].push_back(make_pair(dest, weight));
    
}
void displayList(list<pair<int,int>> graph[], int n)
{
    
    for(int i=0;i<n;i++)
    {
        cout<<i<<"-->";
        for(auto j : graph[i])
        {
            cout<<j.first<<"("<<j.second<<") ";
        }cout<<endl;
        

    }

}
void bellmanFord(list<pair<int,int>> graph[], int n, int src)
{
    int dist[n];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[src]=0;

    //for O(V)
    //we take here n-1 because at max n-1 nodes will be present in the path between any two nodes
    for(int k=0;k<n-1;k++)
    {
        //for O(E)
        for(int i=0;i<n;i++)
    {
        for(auto edge : graph[i])
        {
            int u=i;
            int v=edge.first;
            if(dist[u] != INT_MAX && dist[v] > dist[u] + edge.second)
            {
                dist[v] = dist[u] + edge.second;
            }
        }
    }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    cout<<i<<" ->"<<dist[i]<<endl;
    cout<<endl;
    //detecting negative weight cycle
    for(int i=0;i<n;i++)
    {
        for(auto edge : graph[i])
        {
            int u=i;
            int v=edge.first;
            if(dist[u] != INT_MAX && dist[v] > dist[u] + edge.second)
            {
                cout<<"negative weight cycle detected"<<endl;
                dist[v] = dist[u] + edge.second;
            }
        }
    }
   
    
    
    cout<<endl;
    for(int i=0;i<n;i++)
    cout<<i<<" ->"<<dist[i]<<endl;
    cout<<endl;

}

int main()
{
    list<pair<int,int>> graph[5];
    addEgde(graph, 0, 1, 2);
    addEgde(graph, 0, 2, 4);
    addEgde(graph, 1, 2, -4);
    addEgde(graph, 2, 3, 2);
    addEgde(graph, 3, 4, 4);
    addEgde(graph, 4, 1, -10);

    displayList(graph, 5);
    bellmanFord(graph, 5, 0);

    

    
}