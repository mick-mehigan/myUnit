/*
 * myUnit.h
 *
 *  Created on: 02-Sep-2008
 *      Author: Mick
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
