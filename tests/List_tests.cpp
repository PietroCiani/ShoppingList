//
// Created by delta on 08/08/24.
//

#include <gtest/gtest.h>

#include "src/List.h"

class ListTest : public ::testing::Test {
protected:
    List casa;

    ListTest() : casa("Casa") {}

    void SetUp() override {
        casa.addProd("Latte");
        casa.addProd("Uova");
        casa.addProd("Carbonella");
        casa.addProd("Hamburger", 5);
        casa.addProd("Salsicce", 10);
    }
};

TEST_F(ListTest, Search) {
    EXPECT_EQ(casa.searchProdIndex("latte").front(), 0);
    EXPECT_EQ(casa.getItems(casa.searchProdIndex("Latte").front()).getNumber(), 0);

    EXPECT_EQ(casa.searchProdIndex("dfsdfdfs").empty(), true);
}

TEST_F(ListTest, Add) {
    casa.addProd("Pane");

    EXPECT_EQ(casa.searchProdIndex("Pane").front(), 5);
    EXPECT_EQ(casa.getItems(casa.searchProdIndex("Pane").front()).getNumber(), 0);
}

TEST_F(ListTest, Remove) {
    int oldSize = casa.getItemsSize();
    casa.removeProd(casa.searchProdIndex("Latte").front());

    EXPECT_EQ(casa.getItems(casa.searchProdIndex("Latte").empty()), true);
    EXPECT_EQ(casa.getItemsSize(), oldSize);
}

TEST_F(ListTest, editNumber) {
    EXPECT_EQ(casa.getItems(casa.searchProdIndex("Uova").front()).getNumber(), 0);

    casa.setNumber(casa.searchProdIndex("Uova").front(),12);
    EXPECT_EQ(casa.getItems(casa.searchProdIndex("Uova").front()).getNumber(), 12);
}

