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

#ifndef MYUNIT_H_
#define MYUNIT_H_

#ifdef _DEBUG
#include <iostream>
#include <vector>

class Cunittest {
public:
  virtual void run(void)const =0;
};
typedef std::vector<Cunittest*> VecUnitTest;
typedef VecUnitTest::iterator IterUnitTest;

class CunittestReport {
  CunittestReport();
  VecUnitTest _tests;
public:
  static CunittestReport* Instance(void);
  void AddTest(Cunittest* test);
  void RunTests(void);
};

#define UNITTEST(A) namespace unittests {                     \
                      class Cunittest_##A : public Cunittest{ \
                        public:                               \
                        Cunittest_##A();                      \
                        virtual void run(void)const;          \
                    };                                        \
  }                                                           \
  unittests::Cunittest_##A::Cunittest_##A(){                  \
    CunittestReport::Instance()->AddTest(this);               \
  }                                                           \
  unittests::Cunittest_##A unittest_instance_##A;             \
  void unittests::Cunittest_##A::run(void) const

#define ASSERT_EQUAL(A,B) if(!(A==B))std::cout<< __FILE__ << "(" << __LINE__ << ") : error: expected: " << A << " received: " << B << std::endl;
#define ASSERT_NOT_EQUAL(A,B) if(A==B)std::cout<< __FILE__ << "(" << __LINE__ << ") : error: expected something different than: " << A << std::endl;
#define ASSERT_TRUE(A) if(!(A))std::cout<< __FILE__ << "(" << __LINE__ << ") : error: assert error" << std::endl;
#define ASSERT_FALSE(A) if((A))std::cout<< __FILE__ << "(" << __LINE__ << ") : error: assert error" << std::endl;
#define ASSERT_CLOSE(A,B,C)if((((A)-(B)) > (C))||(((B)-(A))>(C)))std::cout<< __FILE__ << "(" << __LINE__ << ") : error: expected: " << A << " received: " << B << std::endl;

#define UNITTEST_RUN_ALL_TESTS() {                      \
    CunittestReport *rat = CunittestReport::Instance(); \
    if (NULL != rat) {                                  \
      rat->RunTests();                                  \
      delete rat;                                       \
    }                                                   \
  }

#endif // _DEBUG

#endif /* MYUNIT_H_ */
