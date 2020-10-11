# This Makefile is used for Windows, and is specific for src/leetcode/
CXXTEST_OUT = cxxrunner
CXXTEST_SRC = myCxxTest
SOLUTION_SRC = Solution
ROOT_PATH = .\..\..\..
LIB_PATH = $(ROOT_PATH)\lib
UT_PATH = $(LIB_PATH)\uthash-master\src
CXXTEST_PATH = $(ROOT_PATH)\tools\cxxtest-4.4
CXXTEST_BIN_PATH = $(CXXTEST_PATH)\bin
INCLUDE_PATHS = -I$(CXXTEST_PATH) -I$(UT_PATH)
COMPILE_OPTIONS = -Wall -Wsign-compare -Wwrite-strings -Wtype-limits -Werror
#compile all(test and generate main)
all: main test debug
clean-all:
	del *.exe $(CXXTEST_SRC).cpp
#compile debugging version
debug: main-debug test-debug
# compile test(include cxxtest)
test: $(CXXTEST_OUT)
$(CXXTEST_OUT): $(CXXTEST_SRC).cpp $(SOLUTION_SRC).c
	g++ -o $(CXXTEST_OUT) $(INCLUDE_PATHS) $(COMPILE_OPTIONS) $(CXXTEST_SRC).cpp $(SOLUTION_SRC).c
	$(CXXTEST_OUT)
$(CXXTEST_SRC).cpp: $(CXXTEST_SRC).h
	$(CXXTEST_BIN_PATH)\cxxtestgen --error-printer -o $(CXXTEST_SRC).cpp $(CXXTEST_SRC).h
test-debug: $(CXXTEST_SRC).cpp $(SOLUTION_SRC).c
	g++ -o $(CXXTEST_OUT)-debug $(INCLUDE_PATHS) $(COMPILE_OPTIONS) $(CXXTEST_SRC).cpp $(SOLUTION_SRC).c -g
# compile main
main: main.c $(SOLUTION_SRC).c
	gcc -o main $(INCLUDE_PATHS) main.c $(SOLUTION_SRC).c
main-debug: main.c $(SOLUTION_SRC).c
	gcc -o main-debug $(INCLUDE_PATHS) main.c $(SOLUTION_SRC).c -g
main.c: $(SOLUTION_SRC).c $(SOLUTION_SRC).h
$(SOLUTION_SRC).c: $(SOLUTION_SRC).h
