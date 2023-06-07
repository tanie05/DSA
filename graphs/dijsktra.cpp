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
void dijkstra(list<pair<int,int>> graph[], int n, int src)
{
    bool visited[n];
    for(int i=0;i<n;i++)
    visited[i]=false;

    int dist[n];
    for(int i=0;i<n;i++)
    dist[i]=INT_MAX;

    dist[src]=0;

    //calculate the unvisited with minimum distance
    int node, minDist=INT_MAX;
    cout<<endl<<"The minimum distance from 0 to all the nodes are - "<<endl;
    while(1)
    {
        for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(dist[i] < minDist)
            {
                node = i;
                minDist=dist[i];
            }
        }
    }
    if(minDist == INT_MAX)
    break;
    //print it and change the dist of its neighbors
    cout<<node<<" -> "<<dist[node]<<endl;
    visited[node]=true;
    for(auto i : graph[node])
    {   
        if(dist[i.first] > dist[node]+i.second);
        dist[i.first] = dist[node]+i.second;
    }
    
    minDist = INT_MAX;
    
    }

    
}
class Compare
{
public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.second>b.second;
    }
};
void dijkstraPQ(list<pair<int,int>> graph[], int n, int src)
{

    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    int dist[n];
    bool visited[n];


    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    
    dist[src]=0;
    pq.push({src,0});

    while(!pq.empty())
    {
        pair<int, int> curr = pq.top();
        pq.pop();
        //cout<<curr.first<<"-> "<<curr.second<<endl;


        if(!visited[curr.first])
        {
            visited[curr.first] = true;
            for(auto i : graph[curr.first])
            {
                int neigh = i.first;
                int weight = i.second;
                if(dist[neigh] > dist[curr.first] + weight)
                {
                   dist[neigh] = dist[curr.first] + weight;
                   pq.push({neigh, dist[neigh]});
                }
                  
                
            }
        
        }
        
        
    }
    for(int i=0;i<n;i++)
        cout<<i<<"->"<<dist[i]<<endl;
        cout<<endl;
    

}

int main()
{
    list<pair<int,int>> graph[6];
    addEgde(graph, 0, 1, 2);
    addEgde(graph, 0, 2, 4);
    addEgde(graph, 1, 3, 7);
    addEgde(graph, 4, 3, 2);
    addEgde(graph, 3, 5, 1);
    addEgde(graph, 4, 5, 5);
    addEgde(graph, 2, 4, 3);
    addEgde(graph, 1, 2, 1);

    displayList(graph, 6);

    dijkstra(graph, 6, 0);
    cout<<"***************************************"<<endl;
    dijkstraPQ(graph, 6, 0);

    
}