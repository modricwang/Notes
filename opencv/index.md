# OpenCV
学习如何使用OpenCV库

## 调用方法
如果是C++ API:

CMakeLists.txt:
```cmake
cmake_minimum_required(VERSION 3.9)
project(opencv_app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

set(SOURCE_FILES main.cpp)

find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
```

如果是Python Lib：
```python
import cv2
```
