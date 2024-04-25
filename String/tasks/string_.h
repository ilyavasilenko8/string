#ifndef STRING_STRING__H
#define STRING_STRING__H

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

#include <stdio.h>
#include <stdbool.h>

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

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

int getWord(char *beginSearch, WordDescriptor *word);

void digitToStart(WordDescriptor word);

void digitToEnd(WordDescriptor word);

void digits_to_end(char *string);

void test_WordDescriptor();

void replace_digits_with_spaces(char *string);

void test_replace_digits_with_spaces();

bool are_two_words_equal(WordDescriptor a, WordDescriptor b);

bool are_words_in_string_ordered(char *string);

void test_are_words_in_string_ordered();

void replace(char *source, char *w1, char *w2);

void test_replace();
#endif //STRING_STRING__H
