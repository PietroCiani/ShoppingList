//
// Created by delta on 08/08/24.
//

#include <gtest/gtest.h>

#include "List.h"

TEST(ListTest, RemoveProd) {
    List list("Casa");
    list.addProd(Prod("Pane", 2));
    list.addProd(Prod("Latte", 1));
    list.removeProd(Prod("Latte"));

    EXPECT_EQ(list.searchProdIndex("Latte"), -1);
}

TEST(ListTest, SetAmount) {
    List list("Casa");
    list.addProd(Prod("Uova", 6));
    list.setAmount("Uova", 12);

    EXPECT_EQ(list.searchProd("Uova").getAmount(), 12);
}

