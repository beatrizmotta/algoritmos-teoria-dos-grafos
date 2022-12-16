#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
int dijkstra(vector<vector<int> > &adj, int s, int f);

int main() {
    int vertices, edges; 
    cout << "Insira a quantidade de vertices e arestas:\n";
    cin >> vertices >> edges; 
    vector<vector<int> > adjacencia(vertices, vector<int> (vertices, 0)); 

    cout << "Insira as ligações (vertice A, vertice B, peso):\n";
    int u, v, peso; 
    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> peso;

        adjacencia[u][v] = peso; 
        adjacencia[v][u] = peso; 

    }

    int fonte, destino; 
    cout << "\nInsira vertice fonte:\n";
    cin >> fonte; 
    cout << "Insira vertice destino:\n";
    cin >> destino;

    // for (int i = 0; i < vertices; i++) {
    //     for (int j = 0; j < vertices; j++) {
    //         cout << adjacencia[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    dijkstra(adjacencia, fonte, destino);

    return 0;
}

// Função para achar o vértice com menor distância atual
// que ainda não foi visitado
int min(vector<int> &dist, vector<bool> &visited) {

    int mininum = INT_MAX;
    int index; 

    for (int i = 0; i < dist.size(); i++) {

        if (visited[i] == false && dist[i] <= mininum) {
            mininum = dist[i];
            index = i; 
        }

    }

    return index; 

}
void printCaminho(vector<int> &pai, int final) {
    if (pai[final] != final) {
        printCaminho(pai, pai[final]);
    }
    cout << final << " ";
}

int dijkstra(vector<vector<int> > &adj, int s, int f) {
    int size = adj.size();
    vector<int> dist (size, INT_MAX); 
    vector<int> pai (size, -1);
    vector<bool> visited (size, false); 

    dist[s] = 0; 
    pai[s] = s;

    for (int i = 0; i < size; i++) {
        int m = min(dist, visited);
        visited[m] = true; 

        for (int j = 0; j < size; j++) {

            if (!visited[j] &&
                adj[m][j] && dist[m] != INT_MAX
                && dist[m] + adj[m][j] < dist[j]
            ){
                dist[j] = dist[m] + adj[m][j];
                pai[j] = m; 
    
                // dist[adj[j][1]] = dist[adj[j][0]] + adj[j][2];
                // pai[adj[j][1]] = adj[j][0]; 
            }

        }

    }

    cout << "Menor caminho de " << s << " ate os demais vertices:\n";
    for (int i = 0; i < size; i++) {
        cout << s << " -> " << i << ": ";
        if (dist[i] == INT_MAX) {
            cout << "infinito";
        } else {
            cout << dist[i];
        }
        cout << '\n';
    }
    cout << "Caminho de " << s << " ate " << f << ":\n";
    printCaminho(pai, f);

}