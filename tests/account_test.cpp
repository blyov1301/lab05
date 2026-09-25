#include <gtest/gtest.h>
#include <stdexcept>

#include "Account.h"

TEST(Account, Init) {
  Account acc(1, 100);
  EXPECT_EQ(acc.id(), 1);
  EXPECT_EQ(acc.GetBalance(), 100);
}

TEST(Account, ChangeBalanceWithoutLock) {
  Account acc(1, 100);
  EXPECT_THROW(acc.ChangeBalance(50), std::runtime_error);
}

TEST(Account, ChangeBalanceAfterLock) {
  Account acc(1, 100);
  acc.Lock();
  acc.ChangeBalance(50);
  EXPECT_EQ(acc.GetBalance(), 150);
  acc.Unlock();
}

TEST(Account, DoubleLock) {
  Account acc(1, 100);
  acc.Lock();
  EXPECT_THROW(acc.Lock(), std::runtime_error);
}

TEST(Account, Unlock) {
  Account acc(1, 100);
  acc.Lock();
  acc.Unlock();
  EXPECT_THROW(acc.ChangeBalance(10), std::runtime_error);
}
