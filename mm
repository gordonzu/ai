#!/bin/bash

clear
rm -rf build/src/ai_run &&
rm -rf build/tests/unit_tests/unit_tests_run
mkdir -p build && 
cd build && 
cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" && 
make all &&
 
#./tests/unit_tests/unit_tests_run
#./tests/unit_tests/unit_tests_run --gtest_filter=*TestPercept*-*TestXYEnvironment*

#valgrind --tool=memcheck --leak-check=yes ./tests/unit_tests/unit_tests_run
valgrind --tool=memcheck --track-origins=yes --leak-check=full --show-leak-kinds=all ./tests/unit_tests/unit_tests_run
