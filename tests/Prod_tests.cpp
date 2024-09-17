//
// Created by delta on 09/08/24.
//

#include <gtest/gtest.h>

#include "src/Prod.h"

TEST(ProdTest, DefaultConstructor) {
    Prod prod("Pane");

    EXPECT_EQ(prod.getName(), "Pane");
    EXPECT_EQ(prod.getNumber(), 0);
    EXPECT_EQ(prod.isCount(), false);
}

TEST(ProdTest, editNumber) {
    Prod prod("Latte");

    ASSERT_THROW(prod.setNumber(3), std::logic_error);

    /*
    EXPECT_THROW(prod.setNumber(3), std::logic_error);
    // oppure
    prod.setNumber(3);
    EXPECT_EQ(prod.isCount(), false);
    EXPECT_EQ(prod.getNumber(), 0);
    */

    prod.setCount(true);
    prod.setNumber(3);
    EXPECT_EQ(prod.isCount(), true);
    EXPECT_EQ(prod.getNumber(), 3);
}
