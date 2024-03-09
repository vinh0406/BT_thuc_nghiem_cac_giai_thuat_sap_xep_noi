#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

int partition(vector<double>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[high]) swap(arr[low], arr[high]);
    if (arr[mid] > arr[high]) swap(arr[mid], arr[high]);
    if (arr[mid] > arr[low]) swap(arr[mid], arr[low]);

    double pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

void quickSort(vector<double>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sortFile(const string& filename) {
    ifstream inFile(filename);
    vector<double> numbers;
    double num;

    while (inFile >> num) {
        numbers.push_back(num);
    }

    auto start = high_resolution_clock::now();
    quickSort(numbers, 0, numbers.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Thoi gian sap xep day trong tep " << filename << ": "
         << duration.count() << " milliseconds" << endl;

    ofstream outFile("sorted_" + filename);
    outFile << setprecision(12);
    for (const auto& n : numbers) {
        outFile << n << ' ';
    }
}

int main() {
    for (int i = 1; i <= 10; i++) {
        string filename = "file" + to_string(i) + ".txt";
        sortFile(filename);
    }

    return 0;
}
