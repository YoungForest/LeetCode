```bash
# add a new solution
python script/NewSolution.py problem_number
# build project
g++ -Wall -Wextra -Wpedantic -fsanitize=address -fno-omit-frame-pointer -D_GLIBCXX_DEBUG -g -std=c++11 test/main.cpp -lgtest -lpthread -o main
# run all test 
./main 
# run filter tests
./main --gtest_filter=Solution235Test.Correct
```