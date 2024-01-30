#include <stdio.h>
#include <stdbool.h>

#define ROWS 8
#define COLS 21

typedef struct {
    int row;
    int col;
} Point;

int row_direction[] = {1, -1, 0, 0};
int col_direction[] = {0, 0, 1, -1};

bool is_valid_move(int row, int col, char maze[ROWS][COLS], bool visited[ROWS][COLS]) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && !visited[row][col] && maze[row][col] != '1';
}

bool bfs(char maze[ROWS][COLS], Point start, int *collectibles) {
    bool visited[ROWS][COLS] = {false};
    visited[start.row][start.col] = true;

    // Queue for BFS
    Point queue[ROWS * COLS];
    int front = 0, rear = 0;
    queue[rear++] = start;

    // Variables to keep track of exit
    int exit_reached = 0;

    while (front != rear) {
        Point current = queue[front++];

        if (maze[current.row][current.col] == 'C') {
            (*collectibles)++;
            maze[current.row][current.col] = '0'; // Mark the collectible as collected
        } else if (maze[current.row][current.col] == 'E') {
            exit_reached = 1;
        }

        for (int i = 0; i < 4; i++) {
            int next_row = current.row + row_direction[i];
            int next_col = current.col + col_direction[i];

            if (is_valid_move(next_row, next_col, maze, visited)) {
                visited[next_row][next_col] = true;
                Point next_point = {next_row, next_col};
                queue[rear++] = next_point;
            }
        }
    }

    return exit_reached;
}

int main() {
    char maze[ROWS][COLS] = {
        "11111111111111111111",
        "1P0CE000C00000000001",
        "10000000000C00010001",
        "10000000000C00010001",
        "10000000000C00010001",
        "10000000000C00010001",
        "10000000000C00010001",
        "11111111111111111111"
    };

    Point start;

    // Find the starting position of the player ('P')
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 'P') {
                start.row = i;
                start.col = j;
                break;
            }
        }
    }

    int collectibles = 0;

    if (bfs(maze, start, &collectibles) && collectibles == 7) {
        printf("Player can collect all collectibles and reach the exit.\n");
    } else {
        printf("Player cannot collect all collectibles and reach the exit.\n");
    }

    return 0;
}
