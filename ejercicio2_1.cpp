#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int,int> myPair;
class Graph{
    private:
        int V;
        list<myPair> *adj;
        vector<string> keys;
        map<string, pair<int, string>> teselia;
        vector<vector<int>> *adjacentMatrix;
        vector<vector<int>> *prevMatrix;
        map<string, int> Teselia_;
        int k = 0;
    public:
        Graph(int V);
        void addEdge(int u,int v,int w);
        void shortestPath(int src);
        void getAdjacentMatrix();
        void printPath(string , string);
        void mappingTeselia(vector<string> );
        void addWeights(vector<tuple<string, string, int>>);
};
Graph::Graph(int V_){
    V = V_;
    adj = new list<myPair>[V];
    adjacentMatrix = new vector<vector<int>>[V];
    prevMatrix = new vector<vector<int>>[V];
}

void Graph::addEdge(int u,int v,int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

void Graph::mappingTeselia(vector<string> keys_){
    keys = keys_;
    for(int i = 0; i < V; i++){
        Teselia_.insert({keys_[i], i});
    }
    /*
    for(map<string, int>::iterator it = Teselia_.begin(); it!= Teselia_.end(); it++){
        cout<<it->first<<" : "<<it->second<<endl;
    }*/
}
//Dijkstra
void Graph::shortestPath(int src){
    //pair<peso,label>
    priority_queue<myPair,vector<myPair>,greater<myPair> > pq;
    vector<int> dist(V,INF);
    vector<int> prev(V);
    dist[src] = 0;
    prev[src] = -1;
    list<myPair>::iterator it;

    pq.push({0,src});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(it = adj[u].begin();it!=adj[u].end();++it){
            int v = it->first;
            int w = it->second;
            if(dist[v] > dist[u] + w){

                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v],v});
            }
        }
    }
    //Print single-source shortest paths
    for(int i=0;i<V;i++){
        cout << i << " - " << dist[i] <<" - prev - "<< prev[i]<< endl;
    }
}

void Graph::getAdjacentMatrix(){
    //pair<peso,label>

    for(int i = 0; i<V; i++){
        priority_queue<myPair,vector<myPair>,greater<myPair> > pq;
        vector<int> dist(V,INF);
        vector<int> prev(V);
        int src = i;
        dist[src] = 0;
        prev[src] = -1;
        list<myPair>::iterator it;

        pq.push({0,src});

        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();

            for(it = adj[u].begin();it!=adj[u].end();++it){
                int v = it->first;
                int w = it->second;
                if(dist[v] > dist[u] + w){

                    dist[v] = dist[u] + w;
                    prev[v] = u;
                    pq.push({dist[v],v});
                }
            }
        }
        adjacentMatrix[i].push_back(dist);
        prevMatrix[i].push_back(prev);
    }
    //Print single-source shortest paths
    /*for(int i = 0; i<V; i++){
        for(auto it = adjacentMatrix[i][0].begin(); it != adjacentMatrix[i][0].end(); it++){
            cout<< *it<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0; i<V; i++){
        for(auto it = prevMatrix[i][0].begin(); it != prevMatrix[i][0].end(); it++){
            cout<< *it<<"\t";
        }
        cout<<endl;
    }*/
}
void Graph::printPath(string u_, string v_){
    int u = Teselia_[u_], v = Teselia_[v_];

    int aux = v;
    vector<int> path;
    while(aux != -1){
        path.push_back(aux);
        auto it = prevMatrix[u][0].begin() + aux;
        aux = *it;
    }
    if(v_=="L1"){
        for(int i = path.size()-1; i>=0; i--){
        cout<<keys[path[i]]<<endl;
        }
    }
    else{
        for(int i = path.size()-1; i>0; i--){
        cout<<keys[path[i]]<<endl;
        }
    }
}

void Graph::addWeights(vector<tuple<string, string, int>> weights){
    for(vector<tuple<string, string, int>>::iterator it = weights.begin(); it != weights.end(); it++){
        string aux1 = get<0>(*it);
        string aux2 = get<1>(*it);
        addEdge(Teselia_[aux1], Teselia_[aux2], get<2>(*it));
    }
}

int main(){

    /*vector<string> keys =   {"L1","T1","C1","L2","M1","L3",
                                "C2","A1","F","M2","N","O","H",
                                "P","E1","G","T2","E2","A2"};

    vector<string> cities = {"Liga Pokemon","Ciudad Teja","Ciudad Caolin","Pueblo Ladrillo",
                        "Ciudad Marga" ,"Ciudad Loza"  ,"Pueblo Chamota","Pueblo Arenisca",
                        "Ciudad Fayenza","Ciudad Mayolica" ,"Ciudad Negra","Pueblo Ocre",
                        "Ciudad Hormigon","Ciudad Porcelana","Ciudad Esmalte","Ciudad Gres",
                        "Pueblo Terracota","Ciudad Engobe","Pueblo Arcilla"};

    vector<tuple<string, string, int>> weights_ =   {{"E2","O",10},
                                                    {"O","H",5},
                                                    {"H","P",13},
                                                    {"P","E1",19},
                                                    {"E1","G",8},
                                                    {"G","T2",8},
                                                    {"T2","A2",13},
                                                    {"P","M2",16},
                                                    {"M2","N",10},
                                                    {"N","A1",14},
                                                    {"A1","L2",9},
                                                    {"L2","C1",20},
                                                    {"C1","T1",6},
                                                    {"T1","L3",18},
                                                    {"L3","F",14},
                                                    {"F","M2",10},
                                                    {"A1","C2",13},
                                                    {"A1","M1",15},
                                                    {"M1","L1",5}};*/
    vector<string> keys;
    vector<tuple<string, string, int>> weights_;

    vector<string> route;

    int n, m, w, k;
    cin>>n;
    string aux, aux2;
    for(int i = 0; i<n; i++){
        cin>>aux;
        keys.push_back(aux);
    }
    cin>>m;
    for(int i = 0; i<m; i++){
        cin>>aux>>aux2>>w;
        weights_.push_back({aux, aux2, w});
    }
    cin>>k;
    route.push_back("A2");
    for(int i = 0; i<k; i++){
        cin>>aux;
        route.push_back(aux);
    }
    route.push_back("L1");

    Graph graphTeselia(n);
    graphTeselia.mappingTeselia(keys);
    graphTeselia.addWeights(weights_);
    cout<<"\n\n-------RECORRIDO TOTAL-------\n"<<endl;
    graphTeselia.getAdjacentMatrix();
    for(auto it = route.begin(); it!= route.end()-1; it++){
        graphTeselia.printPath(*it,*(it+1));
    }

    return 0;
}
