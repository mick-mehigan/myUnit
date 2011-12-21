/*
 * myUnit.cpp
 *
 *  Created on: 02-Sep-2008
 *      Author: Mick
 */

#ifdef _DEBUG
#include "myUnit.h"

using namespace std;

CunittestReport::CunittestReport() {
}
//
//      VecUnitTest _tests;
CunittestReport* CunittestReport::Instance(void) {
  static CunittestReport* report = NULL;
  if (NULL == report) {
    report = new CunittestReport();
  }
  return report;
}
//
void CunittestReport::AddTest(Cunittest* test) {
  _tests.push_back(test);
}
//
void CunittestReport::RunTests(void) {
  cout << "Running unit tests..." << endl;
  for (IterUnitTest itTest = _tests.begin(); itTest != _tests.end(); ++itTest) {
    (*itTest)->run();
  }
  cout << "Ran " << (unsigned int)_tests.size() << " tests." << endl;
}

#endif // _DEBUG
