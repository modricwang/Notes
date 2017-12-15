# CPP

## filesystem

之前写正经的C++工程代码比较少，没怎么遇到过遍历目录下的文件这种需求。后来问了下身边的人，提供的都是很古老的做法。了解到C++17标准中提供了filesystem库，决定试一下。使用上感觉体验还不错。

使用的编译器及版本为g++ 7.2.0
CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.9)
project(test_Cpp17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
add_library(stdc++fs UNKNOWN IMPORTED)
set_property(TARGET stdc++fs PROPERTY IMPORTED_LOCATION "/usr/lib/gcc/x86_64-linux-gnu/7/libstdc++fs.a")

add_executable(test_Cpp17 main.cpp)
target_link_libraries(${PROJECT_NAME} stdc++fs)
```

头文件为experimental/filesystem

main.cpp
```c++
#include<iostream>
#include<experimental/filesystem>

using namespace std;
namespace fs = std::experimental::filesystem;

int main() {
    fs::path path(".");
    for (auto &it : fs::directory_iterator(path)) {
        const auto &info = it.path();
        cout << info << "\n";
    }
    return 0;
}
```
这就完成了对当前文件夹内文件的遍历
