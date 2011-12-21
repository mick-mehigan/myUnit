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
