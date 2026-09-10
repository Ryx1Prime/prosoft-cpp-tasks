cmake_minimum_required(VERSION 3.15)
project(ProsoftLeetCode CXX)

set(CMAKE_CXX_STANDARD 17)

# Исполняемый файл для первой задачи
add_executable(run_task_1 task_1_easy/solution.cpp "task_3_medium/solution.cpp")
add_executable(run_task_2 task_2_medium/solution.cpp "task_3_medium/solution.cpp")