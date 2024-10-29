#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int main()
{
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    int rows = arr.size();
    int cols = arr[0].size();
    vector<int> ans(rows * cols);

    for (int i = 0; i < rows; i++)
    {
        // CHECK for an element every row element is 0 &
        //  every col element must be 1 except DIAGONAL
        bool knows = false, known = true;
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == 1)
            {
                knows = true;
                break;
            }
        }
        for (int j = 0; j < cols; j++)
        {
            if (i != j && arr[j][i] == 0)
            {
                known = false;
                break;
            }
        }
        if (known == true && knows == false)
        {
            cout << "CELEBRITY: " << i << endl;
        }
    }
}