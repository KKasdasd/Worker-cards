cmake_minimum_required(VERSION 3.14)
project(workers-cards)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE
  src/Worker.cpp
  src/Card.cpp
  src/System.cpp
  src/Manager.cpp)
add_executable(${PROJECT_NAME} 
  src/Main.cpp
  ${SOURCE}
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  )
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME}-ut
    tests/Tests.cpp
    ${SOURCE}
)
target_link_libraries(${PROJECT_NAME}-ut
gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)