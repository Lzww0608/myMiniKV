cmake_minimum_required(VERSION 3.0.12)
project(myMiniKV)

# 配置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 配置最终的可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 配置头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/bPlusTree)
include_directories(${PROJECT_SOURCE_DIR}/include/redBlackTree)
include_directories(${PROJECT_SOURCE_DIR}/include/skipList)


# 加载子目录
add_subdirectory(src)