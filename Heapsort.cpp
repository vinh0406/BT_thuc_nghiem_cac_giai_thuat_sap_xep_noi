#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

void heapify(double arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(double arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    heapSort(numbers.data(), numbers.size());
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
