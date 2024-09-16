//
// Created by delta on 09/08/24.
//

#include <gtest/gtest.h>

#include "src/List.h"

TEST(ProdTest, DefaultConstructor) {
Prod prod("Pane");
EXPECT_EQ(prod.getName(), "Pane");
EXPECT_EQ(prod.getNumber(), 1);
}

TEST(ProdTest, SetAmount) {
    Prod prod("Latte");
    prod.setNumber(3);
    EXPECT_EQ(prod.getNumber(), 3);
}
