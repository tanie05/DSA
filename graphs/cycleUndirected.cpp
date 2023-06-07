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

bool cycleDetection(list<int> graph[], int curr, bool visited[], int par)
{
    visited[curr] = true;

    for(auto i : graph[curr])
    {
        if(i!=par)
        {
            if(visited[i] == true)
            return true;
            else if (cycleDetection(graph, i, visited, curr) == true)
            return true;


        }
        
    }
    return false;
   

}
int main()
{
    
    list<int> graph[6];
    
    addEgde(graph, 0, 1);
    addEgde(graph, 0, 4);
    addEgde(graph, 1, 4);
    addEgde(graph, 1, 2);
    addEgde(graph, 2, 3);
    addEgde(graph, 4, 5);

    // addEdge(graph, 2, 3);
    // addEgde(graph, 0, 1);
    // addEgde(graph, 0, 2);
    // addEgde(graph, 1, 2);
    


    displayList(graph, 6);

    bool visited[6];
    for(int i=0;i<6;i++)
    visited[i] = false;


    for(int i=0;i<6;i++)
    {
        if(cycleDetection(graph, i, visited, -1))
        {
            cout<<"cycle exists"<<endl;
            break;
        }
        else
        {
            cout<<"No cycle exists"<<endl;
            break;
        }
        
    }

    
    

}