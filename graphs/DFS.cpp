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
void DFS(list<int> graph[], int curr, bool visited[])
{
    if(visited[curr] == false)
    cout<<curr<<" ";

    visited[curr] = true;
    
    for(auto i : graph[curr])
    {
        if(visited[i] == true)
        continue;
        else
        DFS(graph, i, visited);
    }

}
int main()
{
    list<int> graph[7];
    addEgde(graph, 0, 1);
    addEgde(graph, 0, 2);
    addEgde(graph, 1, 3);
    addEgde(graph, 3, 4);
    addEgde(graph, 4, 5);
    addEgde(graph, 5, 6);
    addEgde(graph, 2, 4);
    addEgde(graph, 3, 5);

    displayList(graph, 7);

    bool visited[7];
    for(int i=0;i<7;i++)
    visited[i] = false;

    for(int i=0;i<7;i++)
    DFS(graph, i, visited);

}