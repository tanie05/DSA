//weighted directed graph
#include<bits/stdc++.h>
using namespace std;
void addEgde(list<pair<int,int>> graph[], int src, int dest, int weight)
{
    graph[src].push_back(make_pair(dest, weight));
    graph[dest].push_back(make_pair(src, weight));
    
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
class Compare
{
public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.second>b.second;
    }
};
void primsAlgo(list<pair<int,int>> graph[], int n, int src)
{
    vector<int> mstEdges;
    for(int i=0;i<n;i++)
    {
        mstEdges.push_back(0);
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    bool visited[n];
    for(int i=0;i<n;i++)
    visited[i] = false;

    pq.push({src,0});

    int mstCost=0;
    int source=-1;
    
    while(!pq.empty())
    {

        pair<int,int> p = pq.top();
        pq.pop();

        if(!visited[p.first])
        {
            mstEdges[p.first]=p.second;
            
            if(source!=-1)
            cout<<source<<" -> ";
            cout<<p.first<<endl;

            visited[p.first] = true;
            mstCost += p.second;
            for(auto a : graph[p.first])
            {
                int neighbor = a.first;
                int weight = a.second;
                if(!visited[neighbor])
                {
                    pq.push({neighbor,weight});
                }
            }
        }
    }
    cout<<"The cost of minimum spanning tree is "<<mstCost<<endl;
    int num=mstEdges.size();
    for(int i=0;i<n && num>0 ;i++)
    {
        for(auto a : graph[i])
        {
            if(!num) break;
            if(mstEdges[a.first]==a.second)
            {
                cout<<i<<"->"<<a.first<<endl;
                num--;
            }
        }
    }




}


int main()
{
    list<pair<int,int>> graph[3];
    // addEgde(graph, 0, 1, 10);
    // addEgde(graph, 0, 2, 15);
    // addEgde(graph, 0, 3, 30);
    // addEgde(graph, 1, 3, 40);
    // addEgde(graph, 2, 3, 50);


    addEgde(graph,0,1,5);
    addEgde(graph,0,2,1);
    addEgde(graph,1,2,3);
    displayList(graph, 3);
    primsAlgo(graph, 3 , 0);

    

    
}