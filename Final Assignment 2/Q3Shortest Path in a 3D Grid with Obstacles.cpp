#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y, z;
};

bool isValid(Point p, int X, int Y, int Z, const vector<vector<vector<int>>>& grid, const vector<vector<vector<bool>>>& visited) {
    return p.x >= 0 && p.x < X &&
           p.y >= 0 && p.y < Y &&
           p.z >= 0 && p.z < Z &&
           grid[p.x][p.y][p.z] == 0 &&
           !visited[p.x][p.y][p.z];
}

int shortestPath3DGrid(int X, int Y, int Z, Point start, Point end, const vector<vector<vector<int>>>& grid) {
    if (grid[start.x][start.y][start.z] == 1 || grid[end.x][end.y][end.z] == 1) {
        return -1;
    }

    vector<vector<vector<bool>>> visited(X, vector<vector<bool>>(Y, vector<bool>(Z, false)));
    vector<Point> directions = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
    queue<pair<Point, int>> q;

    q.push({start, 0});
    visited[start.x][start.y][start.z] = true;

    while (!q.empty()) {
        auto current = q.front();
        Point point = current.first;
        int dist = current.second;
        q.pop();

        if (point.x == end.x && point.y == end.y && point.z == end.z) {
            return dist;
        }

        for (auto dir : directions) {
            Point next = {point.x + dir.x, point.y + dir.y, point.z + dir.z};
            if (isValid(next, X, Y, Z, grid, visited)) {
                visited[next.x][next.y][next.z] = true;
                q.push({next, dist + 1});
            }
        }
    }

    return -1;
}

int main() {
    int X, Y, Z;
    cout << "Enter dimensions X, Y, Z: ";
    cin >> X >> Y >> Z;

    vector<vector<vector<int>>> grid(X, vector<vector<int>>(Y, vector<int>(Z)));
    cout << "Enter the grid values (0 for free, 1 for blocked):" << endl;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {
                cin >> grid[i][j][k];
            }
        }
    }

    Point start, end;
    cout << "Enter the start coordinates (x y z): ";
    cin >> start.x >> start.y >> start.z;
    cout << "Enter the end coordinates (x y z): ";
    cin >> end.x >> end.y >> end.z;

    int result = shortestPath3DGrid(X, Y, Z, start, end, grid);

    if (result != -1) {
        cout << "Shortest path length is " << result << endl;
    } else {
        cout << "No path exists" << endl;
    }

    return 0;
}

