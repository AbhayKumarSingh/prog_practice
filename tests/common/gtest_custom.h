#ifndef GTEST_CUSTOM_H
#define GTEST_CUSTOM_H
#include "gtest\gtest.h"

#define CREATE_FIXTURE_CLASS(fixture, func_pointer_type, func_common_name) \
	class fixture : public ::testing::TestWithParam<func_pointer_type> { \
	protected: \
		virtual void SetUp() { func_common_name = GetParam(); } \
		func_pointer_type func_common_name; \
		}


#endif // !GTEST_CUSTOM_H