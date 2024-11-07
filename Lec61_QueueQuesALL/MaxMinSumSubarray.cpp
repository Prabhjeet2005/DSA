#include <iostream>
#include <deque>
using namespace std;

int sum(int *arr, int k, int n)
{
    deque<int> maxq;
    deque<int> minq;

    for (int i = 0; i < k; i++)
    {
        while (!maxq.empty() && arr[maxq.front()] <= arr[i])
        {
            maxq.pop_front();
        }
        while (!minq.empty() && arr[minq.front()] >= arr[i])
        {
            minq.pop_front();
        }
        minq.push_back(i);
        maxq.push_back(i);
    }

    int sum = 0;
    sum += arr[maxq.front()] + arr[minq.front()];
    cout << arr[maxq.front()] << " " << arr[minq.front()] << " " << sum << endl;

    for (int i = k; i < n; i++)
    {
        if (!maxq.empty() && i - maxq.front() >= k)
        {
            maxq.pop_front();
        }
        if (!minq.empty() && i - minq.front() >= k)
        {
            minq.pop_front();
        }

        while (!maxq.empty() && arr[maxq.front()] <= arr[i])
        {
            maxq.pop_front();
        }
        while (!minq.empty() && arr[minq.front()] >= arr[i])
        {
            minq.pop_front();
        }

        minq.push_back(i);
        maxq.push_back(i);

        sum += arr[minq.front()] + arr[maxq.front()];
        cout << arr[maxq.front()] << " " << arr[minq.front()] << " " << sum << endl;
    }
    return sum;
}

int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    int n = 7;
    cout << sum(arr, k, n) << endl;
}

// BRUTE FORCE TC => O(n*k)  SC=>O(1)

// int main()
// {
//     int arr[7] = {2, 5, -1, 7, -3, -1, -2};
//     int k = 4;
//     int sum = 0;

//     for (int i = 0; i <= 7 - k; i++)
//     {
//         int mini = INT_MAX;
//         int maxi = INT_MIN;
//         for (int j = i; j < i + k; j++)
//         {
//             maxi = max(arr[j], maxi);
//             mini = min(arr[j], mini);
//         }
//         sum += maxi + mini;
//         cout << "MAX: " << maxi << ", MIN: " << mini << "SUM: " << sum << endl;
//     }
//     cout << "SUM: " << sum << endl;
// }