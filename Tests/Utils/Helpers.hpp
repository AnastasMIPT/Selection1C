#pragma once

#include <iostream>
#include <cassert>

#define TEST_INIT(number) std::cout << number << " Started test" << __func__ << "\n"

#define FAIL(expr, result) do {							\
	std::cerr << "Test failed: " << expr << " is " << result << " at " <<	\
	__FILE__ << ":" << __LINE__ << " in test " << __func__ << std::endl;	\
        assert(false);								\
	exit(-1);								\
} while (0)

#define FAIL_IF(expr) if (expr) FAIL(#expr, "true")