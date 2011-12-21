/*
 * test_app.cpp
 *
 *  Created on: 12-Dec-2011
 *      Author: Mick
 */

#ifdef _DEBUG
#include "../core/myUnit.h"
#endif // _DEBUG

// Application Code

int main(int argc, char *argv[]) {
#ifdef _DEBUG
  UNITTEST_RUN_ALL_TESTS();
#endif // _DEBUG
  return 0;
}

int string_len(char *str) {
  char *str_ = str;
  while((0 != str_) && ('\0' != *str_)) {
    str_++;
  }
  return(str_ - str);
}


#ifdef _DEBUG
// Unit Test Code

UNITTEST(string_len_null) {
  ASSERT_EQUAL(0, string_len(0));
}

UNITTEST(string_len_12345) {
  ASSERT_EQUAL(5, string_len("12345"));
}

UNITTEST(string_len_) {
  ASSERT_EQUAL(0, string_len(""));
}

UNITTEST(string_len_deliberate_failure) {
  ASSERT_EQUAL(0, string_len("1"));
}

#endif // _DEBUG
