# Лабораторная работа №5: Изучение фреймворков для тестирования на примере GTest

**Студент:** Литошенко Григорий

**GitHub Username:** blyov1301

Данная лабораторная работа посвещена изучению фреймворков для тестирования на примере **GTest**

## CI/CD Status
*Travis CI:* сборка и тесты проходят успешно на gcc и clang

*Coveralls:* отчёт о покрытии кода генерируется автоматически

## Building

Проект собирается с помощью CMake. Для сборки тестов используется флаг **BUILD_TESTS**.

```bash
cmake -H. -B_build -DBUILD_TESTS=ON
cmake --build _build
```
*Вывод:*

```bash
[  7%] Building CXX object third-party/gtest/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 14%] Linking CXX static library ../../../lib/libgtest.a
[ 14%] Built target gtest
[ 21%] Building CXX object third-party/gtest/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 28%] Linking CXX static library ../../../lib/libgtest_main.a
[ 28%] Built target gtest_main
[ 35%] Building CXX object banking/CMakeFiles/banking.dir/Account.cpp.o
[ 42%] Building CXX object banking/CMakeFiles/banking.dir/Transaction.cpp.o
[ 50%] Linking CXX static library libbanking.a
[ 50%] Built target banking
[ 57%] Building CXX object CMakeFiles/check.dir/tests/account_test.cpp.o
[ 64%] Building CXX object CMakeFiles/check.dir/tests/transaction_test.cpp.o
[ 71%] Linking CXX executable check
[ 71%] Built target check
[ 78%] Building CXX object third-party/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 85%] Linking CXX static library ../../../lib/libgmock.a
[ 85%] Built target gmock
[ 92%] Building CXX object third-party/gtest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[100%] Linking CXX static library ../../../lib/libgmock_main.a
[100%] Built target gmock_main
```
## Running Tests

```bash
ctest --test-dir _build --output-on-failure
```
*Вывод:*

```bash
Internal ctest changing into directory: /home/vboxuser/workspace/lab05/_build
Test project /home/vboxuser/workspace/lab05/_build
    Start 1: check
1/1 Test #1: check ............................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.02 sec
```
## Code coverage

| File | Coverage |
|-------|---------|
| `Account.cpp` | 100% ✅ |
| `Transaction.cpp` |	100% ✅ |
| **Total** | **100% ✅** |


