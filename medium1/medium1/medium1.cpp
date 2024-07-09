#include <iostream>
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        return numIslands;
    }

    void dfs(std::vector<std::vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0'; // mark as visited

        dfs(grid, i + 1, j); // go down
        dfs(grid, i - 1, j); // go up
        dfs(grid, i, j + 1); // go right
        dfs(grid, i, j - 1); // go left
    }
};

int main() {
    std::vector<std::vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution sol;
    int numIslands = sol.numIslands(grid);
    std::cout << "Number of islands: " << numIslands << std::endl;

    return 0;
}
