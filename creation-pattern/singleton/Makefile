CC = g++
GTEST_DIR = /Users/ows/workspace/dev-tool/googletest
GTEST_INCLUDE = -I${GTEST_DIR}/googletest/include
GTEST_LIB = ${GTEST_DIR}/googletest/make/libgtest.a

CFLAGS = -std=c++17 ${GTEST_INCLUDE}
INCLUDES= ${GTEST_LIB}
OUT_DIR = ./out
TEST_DIR = ./test

.PHONY: build-test run-test test print

build-test:
	${CC} ${CFLAGS} ${INCLUDES} test_singleton.cpp -o ${TEST_DIR}/test_singleton

run-test:
	${TEST_DIR}/test_singleton

test: build-test run-test

clean-test:
	rm -rf ${TEST_DIR}/*