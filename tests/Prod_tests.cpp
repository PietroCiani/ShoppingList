//
// Created by delta on 09/08/24.
//

#include <gtest/gtest.h>

#include "List.h"

TEST(ProdTest, DefaultConstructor) {
Prod prod("Pane");
EXPECT_EQ(prod.getName(), "Pane");
EXPECT_EQ(prod.getAmount(), 1);
}

TEST(ProdTest, SetAmount) {
    Prod prod("Latte");
    prod.setAmount(3, false);
    EXPECT_EQ(prod.getAmount(), 3);
}
