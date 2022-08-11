struct Edge{
    int nodeNo;
    // extra goes here
    ll ai;
    ll bi;
};
struct Graph{
    int nodes;
    vector<vector<Edge>> graph;


    void addBiEdge(int u, int v, int ai, int bi){
        graph[u].push_back({v, ai, bi});
        graph[v].push_back({u, ai, bi});
    }


    void clear(){
        graph.clear();
    }

    void initialize(int node){
        clear();
        nodes = node;
        graph.resize(nodes + 1);
    }
};
