#ifndef STRING_STRING_H
#define STRING_STRING_H

#include <stdio.h>
#include <stdbool.h>

size_t strlen_(const char *begin);

char* find(char *begin, char *end, int ch);

char* findNonSpace(char *begin);

char* findSpace(char *begin);

char* findNonSpaceReverse(char *rbegin, const char *rend);

char* findSpaceReverse(char *rbegin, const char *rend);

void test_find_1();

void test_find_2();

void test_find_3();

void test_find_4();

void test_find_non_space_1();

void test_find_non_space_2();

void test_find_non_space_3();

void test_find_non_space_4();

void test_find_space_1();

void test_find_space_2();

void test_find_space_3();

void test_find_space_4();

void test_find_non_space_reverse_1();

void test_find_non_space_reverse_2();

void test_find_non_space_reverse_3();

void test_find_non_space_reverse_4();

void test_find_space_reverse_1();

void test_find_space_reverse_2();

void test_find_space_reverse_3();

void test_find_space_reverse_4();

int strcmp_(const char *lhs, const char *rhs);

void test_is_strings_equal_1();

void test_is_strings_equal_2();

void test_is_strings_equal_3();

void test_string_();

#endif //STRING_STRING_H
