#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> dis(0, 100);

    for (int i = 0; i < 10; ++i) {
        vector<double> numbers(1000000);
        for (auto& num : numbers) {
            num = dis(gen);
        }

        if (i == 0) {
            sort(numbers.begin(), numbers.end());
        } else if (i == 1) {
            sort(numbers.rbegin(), numbers.rend());
        } else {
            shuffle(numbers.begin(), numbers.end(), gen);
        }

        ofstream file("file" + to_string(i + 1) + ".txt");
        for (const auto& num : numbers) {
            file << num << " ";
        }
    }

    return 0;
}
