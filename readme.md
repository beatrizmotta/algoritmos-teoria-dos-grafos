# Projeto AB2 - Algoritmos para Grafos
![Badge em Desenvolvimento](https://img.shields.io/badge/COMPILADOR-c+11-green)
Foram escolhidos os seguintes quatro algoritmos:

* Bellman-Ford:
    * Implementado para grafos direcionados.
    * Como rodar:
    ```
        cd .\bellman-ford\
        g++ .\main.cpp -o main -std=c++11
    ```
    * Vai mostrar para o usuário:
        * Distância de vértice fonte para os outros;
        * Caminho mais curto entre vértice fonte e vértice final;
* Dijkstra
    * Implementado para grafos não-direcionados.
    * Como rodar:
    ```
        cd .\dijkstra\
        g++ .\main.cpp -o main -std=c++11
    ```
    * Vai mostrar para o usuário:
        * Distância de vértice fonte para os outros;
        * Caminho mais curto entre vértice fonte e vértice final;
* Floyd-Warshall
    * Implementado para grafos não-direcionados.
    * Como rodar:
    ```
        cd .\floyd-warshall\
        g++ .\main.cpp -o main -std=c++11
    ```
    * Vai mostrar para o usuário:
        * Distância de todos os vértices para todos os vértices;
* Prim
    * Implementado para grafos não-direcionados.
    * Como rodar:
    ```
        cd .\prim\
        g++ .\main.cpp -o main -std=c++11
    ```
    * Vai mostrar para o usuário:
        * Árvore geradora mínima;
        * Custo da árvore geradora mínima;