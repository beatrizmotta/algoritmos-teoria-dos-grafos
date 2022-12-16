#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std; 
void print_solve(vector<vector<int> > &matriz);
void floydwarshall(vector<vector<int> > &adj, int s, int f);

int main() {
    int vertices, edges; 
    cout << "Insira a quantidade de vertices e arestas:\n";
    cin >> vertices >> edges; 
    vector<vector<int> > adjacencia(vertices, vector<int> (vertices, INT_MAX));

    cout << "Insira as ligações [grafo nao-direcionado] (vertice A, vertice B, peso):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, peso; 
        cin >> u >> v >> peso;
        adjacencia[i][i] = 0;
        adjacencia[u][v] = peso;
        adjacencia[v][u] = peso;
    }

    // for (int i = 0; i < vertices; i++) {
    //     for (int j = 0; j < vertices; j++) {
    //         cout << adjacencia[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    int fonte, destino; 
    cout << "\nInsira vertice fonte:\n";
    cin >> fonte; 
    cout << "Insira vertice destino:\n";
    cin >> destino;

    floydwarshall(adjacencia, fonte, destino);

    return 0; 
}

void floydwarshall(vector<vector<int> > &adj, int s, int f) {
    int i, j, k;
    int n = adj.size();
    vector<vector<int> > matriz(n, vector<int> (n));
    vector<int> pai (n, -1);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = adj[i][j]; // Copiando 
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {

                if (matriz[i][k] != INT_MAX && matriz[k][j] != INT_MAX
                && matriz[i][k] + matriz[k][j] < matriz[i][j]) {
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                    cout << j << " " << k << "\n";
                }

            }
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matriz[i][k] + matriz[k][j] < matriz[i][j]) {
                    cout << "Esse grafo possui um ciclo negativo\n";
                    exit(0);
                }

            }

        }

    }
    cout << "Tabela de distancias entre cada vertice:\n";

    print_solve(matriz);
   
}

void print_solve(vector<vector<int> > &matriz) {
    int n = matriz.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] == INT_MAX) {
                cout << "infinito";
            } else {
                cout << matriz[i][j] << " ";
            }
        }
        cout << '\n';
    }
    
}