#include <iostream>
using namespace std;
int main()
{
    int row, col;
    cout << "Enter No. of Rows: ";
    cin >> row;
    int **arr = new int *[row];
    int *colsize = new int[row];
    for (int i = 0; i < row; i++)
    {
        cout << "Enter No. of Col for " << i << " row: ";
        cin >> colsize[i];
        arr[i] = new int[colsize[i]];
    }
    cout << "Enter Elements: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Array is: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colsize[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] colsize;
    return 0;
}