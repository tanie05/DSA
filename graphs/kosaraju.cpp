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
        cout<<i<<"-->";
        for(auto j : graph[i])
        {
            cout<<j<<" ";
        }cout<<endl;
        

    }
    
}
void dfs(list<int> graph[], int curr, bool visited[])
{
    visited[curr]=true;
    cout<<curr<<" ";

    for(auto i : graph[curr])
    {
        if(!visited[i])
        {
            dfs(graph, i, visited);
        }
    }


}
void topoSort(list<int> graph[], int curr, bool visited[], stack<int> &st)
{
    visited[curr]=true;
    
    for(auto i : graph[curr])
    {
        if(!visited[i])
        {
            topoSort(graph, i, visited, st);
        }
    }
    st.push(curr);
}
void kosarajuAlgo(list<int> graph[], int n)
{
    //step1 -> create a topologically sorted stack
    stack<int> st;
    bool visited[n];
    
    for(int i=0;i<n;i++)
    visited[i]=false;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        topoSort(graph, i, visited, st);
    }

    //step 2 -> create a transpose graph
    list<int> transpose[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        //for each vertex
        for(auto j : graph[i])
        {
            //add i into list of j
            addEgde(transpose, j, i);
        }

    }

    //pop out each element and run dfs over the transpose graph 
    while(!st.empty())
    {
        int curr = st.top();
        st.pop();

        if(!visited[curr])
        {
            dfs(transpose, curr, visited);
            cout<<endl;
        }
        
    }



}
int main()
{
    list<int> graph[5];
    addEgde(graph,0,3);
    addEgde(graph,0,2);
    addEgde(graph,1,0);
    addEgde(graph,2,1);
    addEgde(graph,3,4);


    displayList(graph, 5);
    kosarajuAlgo(graph, 5);

    




}