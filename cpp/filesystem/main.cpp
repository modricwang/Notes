#include<iostream>
#include<experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

int main() {
    fs::path path(".");
    for (auto &it : fs::directory_iterator(path)) {
        const auto &info = it.path();
        cout << info << endl;
    }
    return 0;
}