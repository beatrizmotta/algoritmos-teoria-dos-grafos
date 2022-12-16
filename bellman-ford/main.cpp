#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
void bellmanford(vector<vector<int> > &adj, int s, int f, int n, int m);

int main() {
    int vertices, edges; 
    cout << "Insira a quantidade de vertices e arestas:\n";
    cin >> vertices >> edges; 
    vector<vector<int> > adjacencia(edges * 2, vector<int> (3, 0)); 

    cout << "Insira as ligações [grafo direcionado] (vertice A, vertice B, peso):\n";
    int u, v, peso; 
    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> peso;
        adjacencia[i] = {u, v, peso};
    }

    int fonte, destino; 
    cout << "\nInsira vertice fonte:\n";
    cin >> fonte; 
    cout << "Insira vertice destino:\n";
    cin >> destino;
    bellmanford(adjacencia, fonte, destino, vertices, edges);

    return 0; 
}

void printCaminho(vector<int> &pai, int final) {
    if (pai[final] != final) {
        printCaminho(pai, pai[final]);
    }
    cout << final << " ";
}

void bellmanford(vector<vector<int> > &adj, int s, int f, int n, int m) {

    vector<int> dist (n, INT_MAX);
    vector<int> pai (n, -1);

    dist[s] = 0; 
    pai[s] = s; 

    // Processo de relaxamento das arestas no máximo v - 1 vezes. 
    for (int i = 1; i < n - 1; i++) {

        for (int j = 0; j < m; j++) {

           if (
                dist[adj[j][0]] != INT_MAX &&
                dist[adj[j][0]] + adj[j][2] < dist[adj[j][1]]
           ) {
                dist[adj[j][1]] = dist[adj[j][0]] + adj[j][2];
                pai[adj[j][1]] = adj[j][0]; 
           }

        }

    }

    // Checagem ciclo negativo

    for (int i = 0; i < m; i++) {
        int v1 = adj[i][0];
        int v2 = adj[i][1];
        int peso = adj[i][2];

        if (dist[v1] != INT_MAX && 
            dist[v1] + peso < dist[v2]
        ) {
            cout << "\nEsse grafo possui um ciclo negativo\n";
            exit(0);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << pai[i] << " ";
    // }
    // cout << "\n";
    
    
    cout << "Menor de caminho " << s << " ate os demais vertices:\n";
    for (int i = 0; i < n; i++) {
        cout << s << " -> " << i << ": ";
        if (dist[i] == INT_MAX) {
            cout << "infinito";
        } else {
            cout << dist[i];
        }
        cout << '\n';
    }
    cout << "Caminho de " << s << " ate " << f << ":\n";
    if (dist[f] == INT_MAX) {
        cout << "Nao ha caminho possivel ate " << f;
        exit(0);
    } else {
        printCaminho(pai, f);
    }
    
}