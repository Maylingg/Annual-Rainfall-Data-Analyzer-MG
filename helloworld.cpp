#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubble_sort(vector<double> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int binary_search(const vector<double> &arr, double x)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    vector<double> rainfall(12);
    double total_rainfall = 0.0;

    for (int i = 0; i < 12; ++i)
    {
        while (true)
        {
            cout << "Enter the rainfall for month " << i + 1 << ": ";
            cin >> rainfall[i];
            if (rainfall[i] >= 0)
                break;
            else
                cout << "Rainfall cannot be negative. Please enter again." << endl;
        }
        total_rainfall += rainfall[i];
    }

    double average_rainfall = total_rainfall / 12;
    cout << "\nTotal rainfall for the year: " << total_rainfall << endl;
    cout << "Average monthly rainfall: " << average_rainfall << endl;

    bubble_sort(rainfall);
    cout << "\nRainfall sorted from lowest to highest: ";
    for (double rain : rainfall)
    {
        cout << rain << " ";
    }
    cout << endl;

    double search_value;
    cout << "\nEnter the rainfall amount to search for: ";
    cin >> search_value;

    int result = binary_search(rainfall, search_value);
    if (result != -1)
    {
        cout << "The rain amount " << search_value << " was found at index " << result << "." << endl;
    }
    else
    {
        cout << "The rain amount " << search_value << " was not found." << endl;
    }

    return 0;
}
