//
// Created by delta on 08/08/24.
//

#include <gtest/gtest.h>

#include "List.h"

class ListTest : public ::testing::Test {
protected:
    List list1, list2;

    ListTest() : list1("Casa"), list2("Grigliata") {}

    void SetUp() override {
        list1.addProd("Latte");
        list1.addProd("Uova", 6);

        list2.addProd("Carbonella");
        list2.addProd("Hamburger", 5);
        list2.addProd("Salsicce", 10);
    }
};

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

