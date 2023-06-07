#include<iostream>
#include<list>
#include<iterator>
#include<vector>
using namespace std;
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
void addEgde(list<int> graph[], int src, int dest)
{
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}

int main()
{
    int vertices, edges;
    cout<<"enter number of vertices - ";
    cin>>vertices;

    cout<<"enter number of edges - ";
    cin>>edges;

    list<int> graph[vertices];

    for(int i=0;i<edges;i++)
    {
        int src, dest;
        cout<<"enter src and dest for edge "<<i+1<<endl;
        cin>>src>>dest;

        addEgde(graph, src, dest);
    }


    cout<<endl<<"******The graph in form of adjancy list******"<<endl;
    displayList(graph, vertices);

}