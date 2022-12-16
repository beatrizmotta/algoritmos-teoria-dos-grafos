#include <iostream>
#include <vector> 

using namespace std; 
void prim(vector<vector<int> > &adj, int s);
int main() {
    int vertices, edges; 
    cout << "Insira a quantidade de vertices e arestas:\n";
    cin >> vertices >> edges; 
    vector<vector<int> > adjacencia(vertices, vector<int> (vertices, 0));
    
    cout << "Insira as ligações (vertice A, vertice B, peso):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, peso; 
        cin >> u >> v >> peso;
        adjacencia[i][i] = 0;
        adjacencia[u][v] = peso;
        adjacencia[v][u] = peso;
    }
    
    int fonte; 
    cout << "Insira o vertice fonte:\n";
    cin >> fonte;

    prim(adjacencia, fonte);

    return 0;
}

void printTree(vector<int> &pai, vector<vector<int> > &adj) {
    cout << "Aresta \tPeso\n";
    int n = pai.size();
    int custo_minimo_total = 0;
    for (int i = 1; i < n; i++) {
        custo_minimo_total += adj[i][pai[i]];
        cout << pai[i] << " - " << i << " \t"
             << adj[i][pai[i]] << " \n";
    }
    cout << "Custo minimo total: " << custo_minimo_total;

}

int min(vector<int> &key, vector<bool> &visited) {
    
    int min = INT_MAX, index;
    int n = visited.size();

    for (int v = 0; v < n; v++)
        if (visited[v] == false && key[v] < min)
            min = key[v], index = v;
 
    return index; 
}

void prim(vector<vector<int> > &adj, int s) {
	int n = adj.size();
    vector<int> pai;
    pai.resize(n);
	vector<int> key (n, INT_MAX);
	vector<bool> visited (n, false);

	// for (int i = 0; i < n; i++)
	// 	key[i] = INT_MAX, visited[i] = false;

	key[s] = 0;
	pai[s] = -1;

	for (int i = 0; i < n - 1; i++) {
		int u = min(key, visited);
		visited[u] = true;

		for (int v = 0; v < n; v++)
			if (adj[u][v] && visited[v] == false
				&& adj[u][v] < key[v]) 
            {
				pai[v] = u, key[v] = adj[u][v];
            }
	}

	printTree(pai, adj);
}