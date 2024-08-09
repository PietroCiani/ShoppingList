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

TEST_F(ListTest, AddProd) {
    list1.addProd("Pane", 3);

    EXPECT_EQ(list1.searchProdIndex("Pane"), 2);
    EXPECT_EQ(list1.searchProd("Pane").getAmount(), 3);
}

TEST_F(ListTest, RemoveProd) {
    list1.removeProd(Prod("Latte"));

    EXPECT_EQ(list1.searchProdIndex("Latte"), -1);
}

TEST_F(ListTest, SetAmount) {
    list1.setAmount("Uova", 12);

    EXPECT_EQ(list1.searchProd("Uova").getAmount(), 12);
}

