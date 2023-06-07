#include<bits/stdc++.h>
using namespace std;
void addEgde(list<int> graph[], int src, int dest)
{
    graph[src].push_back(dest);
    graph[dest].push_back(src);

}
void displayList(list<int> graph[], int n)
{
    
    for(int i=0;i<n;i++)
    {
        cout<<i<<"--->";
        for(auto j : graph[i])
        {
            cout<<j<<" ";
        }cout<<endl;
        

    }
    
}
int t=0;
void dfs(list<int> graph[], int curr, bool visited[], int dt[], int lt[], int par, int time )
{
    visited[curr]=true;
    dt[curr]=time++;
    lt[curr]=dt[curr];

    for(auto i : graph[curr])
    {
        if(i==par)
        continue;

        else if(!visited[i])
        {
            dfs(graph,i,visited,dt,lt,curr,time);
            lt[curr]=min(lt[curr], lt[i]);
            
            if(dt[curr]<lt[i])
            cout<<curr<<" "<<i<<endl;
        }
        
        else if(visited[i])
        {
            lt[curr] = min(lt[curr], dt[i]);
        }
    }

}
void bridge(list<int> graph[], int n)
{
    int dt[n], lt[n];
    bool visited[n];
    int time=0;
    for(int i=0;i<n;i++)
    {
        dt[i]=0;
        lt[i]=0;
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        dfs(graph, 0, visited, dt, lt, -1, time);
    }
    

}
int main()
{
    
    list<int> graph[4];

    // addEgde(graph,0,1);
    // addEgde(graph,1,2);
    // addEgde(graph,0,2);
    // addEgde(graph,0,3);
    // addEgde(graph,3,4);
    // addEgde(graph,4,5);
    // addEgde(graph,3,5);

    // addEgde(graph,0,1);
    // addEgde(graph,0,2);
    // addEgde(graph,2,3);
    // addEgde(graph,3,4);
    // addEgde(graph,4,5);
    // addEgde(graph,1,2);

    addEgde(graph,0,1);
    addEgde(graph,0,2);
    addEgde(graph,1,2);
    addEgde(graph,1,3);

    displayList(graph,4);
    bridge(graph, 4);

}