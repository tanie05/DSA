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
        cout<<i<<" --> ";
        for(auto j : graph[i])
        {
            cout<<j<<" ";
        }cout<<endl;
        

    }

}
void allPaths(list<int> graph[], int curr, bool visited[], int target, vector<int> &path)
{
    
    path.push_back(curr);
    if(curr == target)
    {
        for(auto i : path)
        cout<<i;
        cout<<endl;
        path.pop_back();
        return;
    } 
    visited[curr]=true;

    for(auto i : graph[curr])
    {
        if(visited[i] == false)
        {
            allPaths(graph, i, visited, target, path);
            visited[i] = false;
        }
    }
    visited[curr] = false;
    path.pop_back();


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

    vector<int> path;
    cout<<"All paths from 0 to 5 are - "<<endl;
    allPaths(graph, 0, visited, 5 , path);

}