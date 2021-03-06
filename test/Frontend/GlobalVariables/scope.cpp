// RUN: %tapi-frontend -target i386-apple-macos10.12 %s 2>&1 | FileCheck %s
// RUN: %tapi-frontend -target x86_64-apple-macos10.12 %s 2>&1 | FileCheck %s

// CHECK: global variables:

namespace test {
int t;
// CHECK:      - name: __ZN4test1tE
};

int g;
// CHECK:      - name: _g

extern int g1;
// CHECK:      - name: _g1

// CHECK-NOT:  - name: _k
// CHECK-NOT:  - name: _l
inline void foo(int k) {
  int l;
}

// check decl with empty name.
void bar(int) {}
