include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../../src/week2)

add_executable(week2Tests NaiveStringMatcherTests.cpp benchmarks.cpp Rabin-KarpTests.cpp)

target_link_libraries(week2Tests week2)
target_link_libraries(week2Tests gtest gtest_main)