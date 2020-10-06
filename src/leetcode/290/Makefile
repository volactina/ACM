# This Makefile is used for Windows, and is specific for src/leetcode/
CXXTEST_OUT = cxxrunner
CXXTEST_SRC = myCxxTest
SOLUTION_SRC = Solution
CXXTEST_PATH = .\..\..\..\tools\cxxtest-4.4
CXXTEST_BIN_PATH = $(CXXTEST_PATH)\bin
COMPILE_OPTIONS = -Wall -Wsign-compare -Wwrite-strings -Wtype-limits -Werror
$(CXXTEST_OUT): $(CXXTEST_SRC).cpp $(SOLUTION_SRC).c
	g++ -o $(CXXTEST_OUT) -I$(CXXTEST_PATH) $(COMPILE_OPTIONS) $(CXXTEST_SRC).cpp $(SOLUTION_SRC).c
$(CXXTEST_SRC).cpp: $(CXXTEST_SRC).h
	$(CXXTEST_BIN_PATH)\cxxtestgen --error-printer -o $(CXXTEST_SRC).cpp $(CXXTEST_SRC).h
clean: $(CXXTEST_OUT) $(CXXTEST_SRC).cpp
	del $(CXXTEST_OUT).exe $(CXXTEST_SRC).cpp
$(SOLUTION_SRC).c: $(SOLUTION_SRC).h