#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void sortFile(const string& filename) {
    ifstream inFile(filename);
    vector<double> numbers;
    double num;

    while (inFile >> num) {
        numbers.push_back(num);
    }

    auto start = high_resolution_clock::now();
    sort (numbers.begin(),numbers.end());
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
