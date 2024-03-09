#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

vector<double> temp;

void merge(vector<double>& arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void sortFile(const string& filename) {
    ifstream inFile(filename);
    vector<double> numbers;
    double num;

    while (inFile >> num) {
        numbers.push_back(num);
    }

    temp.resize(numbers.size());
    auto start = high_resolution_clock::now();
    mergeSort(numbers, 0, numbers.size() - 1);
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
