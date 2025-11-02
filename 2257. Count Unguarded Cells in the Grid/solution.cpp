#include <vector>

class Solution
{
public:
    int countUnguarded(int m, int n, std::vector<std::vector<int>> &guards, std::vector<std::vector<int>> &walls)
    {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n));

        for (const auto &guard : guards)
        {
            grid[guard[0]][guard[1]] = 1;
        }

        for (const auto &wall : walls)
        {
            grid[wall[0]][wall[1]] = 1;
        }

        for (const auto &guard : guards)
        {
            for (int i = guard[1] - 1; i > -1; i--)
            {
                if (grid[guard[0]][i] == 1)
                {
                    break;
                }

                grid[guard[0]][i] = 2;
            }

            for (int i = guard[1] + 1; i < n; i++)
            {
                if (grid[guard[0]][i] == 1)
                {
                    break;
                }

                grid[guard[0]][i] = 2;
            }

            for (int i = guard[0] - 1; i > -1; i--)
            {
                if (grid[i][guard[1]] == 1)
                {
                    break;
                }

                grid[i][guard[1]] = 2;
            }

            for (int i = guard[0] + 1; i < m; i++)
            {
                if (grid[i][guard[1]] == 1)
                {
                    break;
                }

                grid[i][guard[1]] = 2;
            }
        }

        int res = 0;

        for (const auto &row : grid)
        {
            for (const auto &col : row)
            {
                if (col == 0)
                {
                    res = res + 1;
                }
            }
        }

        return res;
    }
};