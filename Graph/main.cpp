#include <iostream>
#include "graphtype.cpp"
using namespace std;

void EdgeFound(bool b){
    if(b)
        cout << "There is an edge." << endl;
    else
        cout << "There is no edge." << endl;
}

int main() {

    GraphType<char> g;                           // Create a graph object

    g.AddVertex('A');                            // Add specified number of vertices to the graph
    g.AddVertex('B');
    g.AddVertex('C');
    g.AddVertex('D');
    g.AddVertex('E');
    g.AddVertex('F');
    g.AddVertex('G');
    g.AddVertex('H');

    g.AddEdge('A', 'B', 1);                      // Add edges to the vertices assuming edge cost is 1
    g.AddEdge('A', 'C', 1);
    g.AddEdge('A', 'D', 1);

    g.AddEdge('B', 'A', 1);

    g.AddEdge('D', 'A', 1);
    g.AddEdge('D', 'E', 1);
    g.AddEdge('D', 'G', 1);

    g.AddEdge('G', 'F', 1);
    g.AddEdge('F', 'H', 1);
    g.AddEdge('H', 'E', 1);

    cout << g.OutDegree('D') << endl;            // Print outdegree of vertex D

    EdgeFound(g.FoundEdge('A', 'D'));                // Print if there is an edge between vertices A and D
    EdgeFound(g.FoundEdge('B', 'D'));                // Print if there is an edge between vertices B and D

    g.DepthFirstSearch('B', 'E');                // Use DFS in order to find if there is a path from B to E
    g.DepthFirstSearch('E', 'B');                // Use DFS in order to find if there is a path from E to B

    g.BreadthFirstSearch('B', 'E');              // Use BFS in order to find if there is a path from B to E
    g.BreadthFirstSearch('E', 'B');              // Use BFS in order to find if there is a path from E to B

    g.BreadthFirstSearch('B', 'E');              // Use BFS to print the length of the shortest path
    return 0;
}
