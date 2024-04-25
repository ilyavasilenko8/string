#ifndef STRING_STRING__H
#define STRING_STRING__H

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

char* copy(const char *beginSource, const char *endSource, char *beginDestination);

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

void test_copy();

void test_copyIf();

void test_copyIfReverse();

void test_string_();

void removeNonLetters(char *s);

void assertSrting(const char *expected, char *got, char const *fileName, char const *funcName, int line);

void test_removeNonLetters();

char* copy_if_not_extra_spaces(char *beginSource, const char *endSource, char *beginDestination);

void removeExtraSpaces(char *s);

void test_removeExtraSpaces_1();

void test_removeExtraSpaces_2();

void test_removeExtraSpaces_3();

void removeAdjacentEqualLetters(char *s);

void test_removeAdjacentEqualLetters();
#endif //STRING_STRING__H
