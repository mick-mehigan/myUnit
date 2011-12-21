/*
 Copyright (c) 2008, Mick Mehigan
 All rights reserved.

 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:

 Redistributions of source code must retain the above copyright notice, this list
 of conditions and the following disclaimer.
 Redistributions in binary form must reproduce the above copyright notice, this
 list of conditions and the following disclaimer in the documentation and/or other
 materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
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
