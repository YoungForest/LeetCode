```bash
# build project
g++ -std=c++11 test/main.cpp -lgtest -lpthread -o main
# run all test 
./main 
# run filter tests
./main --gtest_filter=Solution235Test.Correct
```