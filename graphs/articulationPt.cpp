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
void dfs(list<int> graph[], int curr, int par, int dt[], int lt[], bool articulation[], bool visited[], int time)
{
    visited[curr]=true;
    dt[curr]=lt[curr]=time++;
    int children=0;

    for(auto neigh : graph[curr])
    {
        if(neigh == par)
        continue;

        else if(visited[neigh])
        lt[curr] = min(lt[curr], dt[neigh]);

        else if(!visited[neigh])
        {
            dfs(graph, neigh, curr, dt, lt, articulation, visited, time);
            lt[curr] = min(lt[curr], lt[neigh]);

            if(dt[curr] <= lt[neigh] && par != -1)
            articulation[curr]=true;

            children++;
        }
    }
    if(par==-1 && children > 1)
    articulation[curr]=true;

}
void articulationPt(list<int> graph[], int n)
{
    int dt[n], lt[n];
    bool visited[n], articulation[n];
    int time=0;
    for(int i=0;i<n;i++)
    {
        dt[i]=0;
        lt[i]=0;
        visited[i]=false;
        articulation[i]=false;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        dfs(graph, i, -1, dt, lt, articulation, visited, time);
    }
    for(int i=0;i<n;i++)
    {
        if(articulation[i]==true)
        cout<<"AP:"<<i<<endl;
    }

}

int main()
{
    list<int> graph[5];

    addEgde(graph,0,1);
    addEgde(graph,1,2);
    addEgde(graph,0,2);
    addEgde(graph,0,3);
    addEgde(graph,3,4);

    displayList(graph,5);
    articulationPt(graph,5);

    
    
    

    




}