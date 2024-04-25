#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <memory.h>
#include "string.h"
#include "string_.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0') {
        end++;
    }
    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch) {
        begin++;
    }
    return begin;
}

char *findNonSpace(char *begin) {
    while (isspace(*begin) && *begin != '\0') {
        begin++;
    }
    return begin;
}

char *findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0') {
        begin++;
    }
    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin >= rend && isspace(*rbegin)) {
        rbegin--;
    }
    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin >= rend && !isspace(*rbegin)) {
        rbegin--;
    }
    return rbegin;
}

void test_find_1() {
    char string[] = "hello";

    assert(find(string, string + 5, 'e') == string + 1);
}

void test_find_2() {
    char string[] = "hello";

    assert(find(string, string + 5, 'h') == string);
}

void test_find_3() {
    char string[] = "hello";

    assert(find(string, string + 5, 'o') == string + 4);
}

void test_find_4() {
    char string[] = "hello";

    assert(find(string, string + 5, 'g') == string + 5);
}

void test_find_non_space_1() {
    char string[] = "hello";

    assert(findNonSpace(string) == string);
}

void test_find_non_space_2() {
    char string[] = "  llo";

    assert(findNonSpace(string) == string + 2);
}

void test_find_non_space_3() {
    char string[] = "    o";

    assert(findNonSpace(string) == string + 4);
}

void test_find_non_space_4() {
    char string[] = "     ";

    assert(findNonSpace(string) == string + 5);
}

void test_find_space_1() {
    char string[] = " ello";

    assert(findSpace(string) == string);
}

void test_find_space_2() {
    char string[] = "he lo";

    assert(findSpace(string) == string + 2);
}

void test_find_space_3() {
    char string[] = "hello";

    assert(findSpace(string) == string + 5);
}

void test_find_space_4() {
    char string[] = "hell ";

    assert(findSpace(string) == string + 4);
}

void test_find_non_space_reverse_1() {
    char string[] = "hello";

    assert(findNonSpaceReverse(string + 4, string) == string + 4);
}

void test_find_non_space_reverse_2() {
    char string[] = "hel  ";

    assert(findNonSpaceReverse(string + 4, string) == string + 2);
}

void test_find_non_space_reverse_3() {
    char string[] = "h    ";

    assert(findNonSpaceReverse(string + 4, string) == string);
}

void test_find_non_space_reverse_4() {
    char string[] = "     ";

    assert(findNonSpaceReverse(string + 4, string) == string - 1);
}

void test_find_space_reverse_1() {
    char string[] = "hello";

    assert(findSpaceReverse(string + 4, string) == string - 1);
}

void test_find_space_reverse_2() {
    char string[] = "hel  ";

    assert(findSpaceReverse(string + 4, string) == string + 4);
}

void test_find_space_reverse_3() {
    char string[] = "h   o";

    assert(findSpaceReverse(string + 4, string) == string + 3);
}

void test_find_space_reverse_4() {
    char string[] = " ello";

    assert(findSpaceReverse(string + 4, string) == string);
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs == *rhs && *lhs != '\0' && *rhs != '\0') {
        lhs++;
        rhs++;
    }
    return *lhs - *rhs;
}

void test_is_strings_equal_1() {
    char string1[] = "Hello";
    char string2[] = "Hello";

    assert(strcmp_(string1, string2) == 0);
}

void test_is_strings_equal_2() {
    char string1[] = "Hello";
    char string2[] = "Hallo";

    assert(strcmp_(string1, string2) > 0);
}

void test_is_strings_equal_3() {
    char string1[] = "Hello";
    char string2[] = "Hellower";

    assert(strcmp_(string1, string2) < 0);
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    size_t size = endSource - beginSource;
    memcpy(beginDestination, beginSource, size);
    *(beginDestination + size) = '\0';

    return beginDestination + size;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }
    *beginDestination = '\0';

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    char *beginDestination_ = beginDestination;
    while (rbeginSource >= rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination_ = *rbeginSource;
            beginDestination_++;
        }
        rbeginSource--;
    }
    *beginDestination_ = '\0';
    return beginDestination_;
}

int is_h(char s) {
    return s == 'h' || s == 'w';
}

void test_copy() {
    char string[] = "hahh";
    char new_string[4];
    copy(string, string + 3, new_string);
    char result[] = "hah";

    assert(strcmp_(new_string, result) == 0);
}

void test_copyIf() {
    char string[] = "hahh";
    char new_string[4];
    copyIf(string, string + 3, new_string, (int (*)(int)) is_h);
    char result[] = "hh";

    assert(strcmp_(new_string, result) == 0);
}

void test_copyIfReverse() {
    char string[] = "haw";
    char new_string[3];
    copyIfReverse(string + 3, string, new_string, (int (*)(int)) is_h);
    char result[] = "wh";

    assert(strcmp_(new_string, result) == 0);
}

void removeNonLetters(char *s) {
    char *endSource = s + strlen_(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void test_removeNonLetters() {
    char s1[] = "hel lo";
    char s2[] = "hello";

    removeNonLetters(s1);

    ASSERT_STRING(s1, s2);
}

char *copy_if_not_extra_spaces(char *beginSource, const char *endSource, char *beginDestination) {
    *beginDestination = *beginSource;
    beginDestination++;
    beginSource++;

    while (beginSource != endSource) {
        if (!isspace(*beginSource) || (isspace(*beginSource) && !isspace(*(beginSource - 1)))) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }

    *beginDestination = '\0';

    return beginDestination;
}

void removeExtraSpaces(char *s) {
    if (strlen_(s) > 0) {
        char *endSource = s + strlen_(s);
        char *destination = copy_if_not_extra_spaces(s, endSource, s);
        *destination = '\0';
    }
}

void test_removeExtraSpaces_1() {
    char s1[] = "";
    char s2[] = "";

    removeExtraSpaces(s1);

    ASSERT_STRING(s1, s2);
}

void removeAdjacentEqualLetters(char *s) {
    if (*s != '\0') {
        s++;
    }

    char *read_buffer = s;

    while (*read_buffer != '\0') {
        if (*read_buffer != *(--s)) {
            *(++s) = *read_buffer;
        }
        s++;
        read_buffer++;
    }
    *s = '\0';
}

void test_removeAdjacentEqualLetters() {
    char s1[] = "";
    removeAdjacentEqualLetters(s1);
    ASSERT_STRING(s1, "");

    char s2[] = "zero";
    removeAdjacentEqualLetters(s2);
    ASSERT_STRING(s2, "zero");

    char s3[] = "zzeeeeroooo";
    removeAdjacentEqualLetters(s3);
    ASSERT_STRING(s3, "zero");
}

void test_removeExtraSpaces_2() {
    char s1[] = " ";
    char s2[] = " ";

    removeExtraSpaces(s1);

    ASSERT_STRING(s1, s2);
}

void test_removeExtraSpaces_3() {
    char s1[] = "  hell    o ";
    char s2[] = " hell o ";
    removeExtraSpaces(s1);

    ASSERT_STRING(s1, s2);
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0') {
        return 0;
    }
    word->end = findSpace(word->begin);
    return 1;
}

void digitToStart(WordDescriptor word){
    char _strinBuffer[MAX_STRING_SIZE+1];
    char *endStringBuffer=copy(word.begin, word.end, _strinBuffer);
    char *recPosition = copyIf(_strinBuffer, endStringBuffer, word.begin, isdigit);

    copyIf(_strinBuffer, endStringBuffer, recPosition, isalpha);

}

void digitToEnd(WordDescriptor word) {
    char _stringBuffer[MAX_STRING_SIZE + 1];
    char *endStringBuffer = copy(word.begin, word.end,_stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isalpha);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
}

void digitToEndAndReverse(WordDescriptor word) {
    char _stringBuffer[MAX_STRING_SIZE + 1];
    char *endStringBuffer = copy(word.begin, word.end,_stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isalpha);
    copyIfReverse(endStringBuffer, _stringBuffer, recPosition, isdigit);
}

void digits_to_end(char *string) {
    WordDescriptor word;
    char *beginSearch = string;
    while (getWord(beginSearch, &word)) {
        digitToEnd(word);
        beginSearch = word.end;
    }
}

void digits_to_end_and_reverse(char *string) {
    WordDescriptor word;
    char *beginSearch = string;
    while (getWord(beginSearch, &word)) {
        digitToEndAndReverse(word);
        beginSearch = word.end;
    }
}

void letters_to_end(char *string) {
    WordDescriptor word;
    char *beginSearch = string;
    while (getWord(beginSearch, &word)) {
        digitToStart(word);
        beginSearch = word.end;
    }
}

void test_WordDescriptor() {
    char string[] = "he13l3lo8";
    digits_to_end(string);
    ASSERT_STRING("hello1338", string);
}

void replace_digits_with_spaces(char *string) {
    char _stringBuffer[MAX_STRING_SIZE + 1];
    char *end = string + strlen_(string);
    char *readBuffer = _stringBuffer;
    copy(string, end, readBuffer);

    while (*readBuffer != '\0') {
        if (isalpha(*readBuffer)) {
            *string++ = *readBuffer;
        } else {
            while (isdigit(*readBuffer) && *readBuffer != '0') {
                *string++ = ' ';
                (*readBuffer)--;
            }
        }

        readBuffer++;
    }

    *string = '\0';
}

void test_replace_digits_with_spaces() {
    char string_1[] = "";
    replace_digits_with_spaces(string_1);
    ASSERT_STRING("", string_1);

    char string_2[] = "hl";
    replace_digits_with_spaces(string_2);
    ASSERT_STRING("hl", string_2);

    char string_3[] = "h12l";
    replace_digits_with_spaces(string_3);
    ASSERT_STRING("h l", string_3);
}
void test_string_() {
    test_find_1();
    test_find_2();
    test_find_3();
    test_find_4();
    test_find_non_space_1();
    test_find_non_space_2();
    test_find_non_space_3();
    test_find_non_space_4();
    test_find_space_1();
    test_find_space_2();
    test_find_space_3();
    test_find_space_4();
    test_find_non_space_reverse_1();
    test_find_non_space_reverse_2();
    test_find_non_space_reverse_3();
    test_find_non_space_reverse_4();
    test_find_space_reverse_1();
    test_find_space_reverse_2();
    test_find_space_reverse_3();
    test_find_space_reverse_4();
    test_is_strings_equal_1();
    test_is_strings_equal_2();
    test_is_strings_equal_3();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
    test_removeNonLetters();
    test_removeExtraSpaces_1();
    test_removeExtraSpaces_2();
    test_removeExtraSpaces_3();
    test_WordDescriptor();
    test_replace_digits_with_spaces();
}