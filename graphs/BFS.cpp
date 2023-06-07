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
void BFS(list<int> graph[], int src, int n)
{
    queue<int> q;
    bool visited[n];
    vector<int> bfs;

    for(int i=0;i<n;i++)
    visited[i]=false;

    q.push(src);
    visited[src]=true;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        bfs.push_back(curr);

        
        //add the non visited neighbours of curr
        for(auto i : graph[curr])
        {
            if(visited[i] == false)
            {
                visited[i]=true;
                q.push(i);
            }
            
        }
    }
    for(auto i : bfs)
    cout<<i<<" ";
    cout<<endl;


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

    
    BFS(graph, 0, 7);





}