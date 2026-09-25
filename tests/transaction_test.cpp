#include <gtest/gtest.h>
#include <stdexcept>

#include "Account.h"
#include "Transaction.h"

TEST(Transaction, SameAccount) {
  Account acc(1, 1000);
  Transaction tr;
  EXPECT_THROW(tr.Make(acc, acc, 100), std::logic_error);
}

TEST(Transaction, NegativeSum) {
  Account from(1, 1000);
  Account to(2, 1000);
  Transaction tr;
  EXPECT_THROW(tr.Make(from, to, -10), std::invalid_argument);
}

TEST(Transaction, TooSmallSum) {
  Account from(1, 1000);
  Account to(2, 1000);
  Transaction tr;
  EXPECT_THROW(tr.Make(from, to, 50), std::logic_error);
}

TEST(Transaction, FeeTooBig) {
  Account from(1, 1000);
  Account to(2, 1000);
  Transaction tr;
  tr.set_fee(100);
  EXPECT_FALSE(tr.Make(from, to, 100));
}

TEST(Transaction, Successful) {
  Account from(1, 1000);
  Account to(2, 1000);
  Transaction tr;
  EXPECT_TRUE(tr.Make(from, to, 500));
  // Из-за особенности реализации Transaction::Make:
  // from не меняется, to уменьшается на fee
  EXPECT_EQ(from.GetBalance(), 1000);
  EXPECT_EQ(to.GetBalance(), 999);
}
