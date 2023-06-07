#include<bits/stdc++.h>
using namespace std;

void addEgde(list<int> graph[], int src, int dest)
{
    graph[src].push_back(dest);
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

bool cycleDetection(list<int> graph[], int curr, bool visited[], bool recursion[])
{
    recursion[curr]=true;

    // if(visited[curr] == false)
    // cout<<curr<<" ";

    visited[curr] = true;
    
    for(auto i : graph[curr])
    {
        if(recursion[i] == true)
        return true;
        else if(visited[i] == false)
        {
            if(cycleDetection(graph, i, visited, recursion))
            return true;
        }
                
    }

    recursion[curr]=false;
    return false;

}
int main()
{
    list<int> graph[4];
    // addEgde(graph, 0, 2);
    // addEgde(graph, 1, 0);
    // addEgde(graph, 2, 3);
    // addEgde(graph, 3, 0);

    addEgde(graph, 0, 2);
    addEgde(graph, 1, 2);
    addEgde(graph, 3, 1);
    addEgde(graph, 3, 0);



    displayList(graph, 4);

    bool visited[7];
    for(int i=0;i<4;i++)
    visited[i] = false;

    bool recursion[4];
    for(int i=0;i<4;i++)
    recursion[i]=false;

    int i;
    for(i=0;i<4;i++)
    {
        
        if(!visited[i])
        {
            if(cycleDetection(graph, i, visited, recursion))
            {
                cout<<"cycle exists "<<endl;
                break;
            }
            
        }
        
    }
    if(i==4)
    cout<<"No cycle exists"<<endl;

    
    

}