#include <iostream>
using namespace std;
struct node
{
    int value;
    node* next;
};
struct adjlist
{
    int value;
    node* next;
};
struct graph
{
    adjlist* adjlist;
};
graph creategraph(int v)
{
    graph g;
    g.adjlist = new(adjlist[v]) ;
    for(int i=0;i<v;i++)
    {
        g.adjlist[i].value = i;
        g.adjlist[i].next = NULL;
    }
    return g;
}
void addedge(graph g,int x,int y)
{
    if(g.adjlist == NULL)
    {
        cout<<"please create graph then you can add edges"<<endl;
        return;
    }
    if(g.adjlist[x].next == NULL)
    {
        g.adjlist[x].next = new(node);
        g.adjlist[x].next->next = NULL;
        g.adjlist[x].next->value = y;
    }
    node* temp = new(node);
    temp ->value = y;
    temp->next = g.adjlist[x].next->next;
     g.adjlist[x].next = temp;

}
void dfsutil(graph g, int source,bool visited[])
{
    visited[source] = true;
    cout<<g.adjlist[source].value<<endl;
    node* temp = g.adjlist[source].next->next;
    while(temp->next)
    {
        if(!visited[g.adjlist[temp->value].value])
        {
            dfsutil(g,temp->value,visited);
        }
    }
}
void dfs(graph g,int v,int source)
{
    bool visited[v];
    for(int i=0; i<v;i++)
    {
        visited[i] = false;
    }
    dfsutil(g,source,visited);
}
int main()
{
    cout<<"press 1 for create graph"<<endl;
    cout<<"press 2 for add edges in graph"<<endl;
    cout<<"press 3 for dfs"<<endl;
    int choice;
    graph g;
    int v;
    g.adjlist = NULL;
    while(1)
    {

        cout<<"enter your choice"<<endl;
        cin>>choice;
    switch(choice)
    {
        case 1:
            {
                cout<<"enter number of vertex in graph"<<endl;
                cin>>v;
                g = creategraph(v);
            }
            break;
        case 2:
            {
                cout<<"enter source and destination vertex respectively"<<endl;
                int x,y;
                cin>>x>>y;
                addedge(g,x,y);
            }
            break;
        case 3:
            {
                dfs(g,v,0);
            }
            break;
    }
    }
}
