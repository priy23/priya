#include <iostream>
using namespace std;

const int MAX = 100;
int adj[MAX][MAX]; // adjacency matrix
bool visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if (rear == MAX - 1) {
        cout << "Queue is full\n";
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

// Dequeue operation
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// BFS function
void BFS(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = false;

    enqueue(start);
    visited[start] = true;

    while (front <= rear) {
        int node = dequeue();
        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    int u, v;
    for (int i = 0; i < e; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // for undirected graph
    }

    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    cout << "BFS Traversal: ";
    BFS(start, n);

    return 0;
}
