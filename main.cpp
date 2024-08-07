#include "Prod.h"
#include "List.h"

int main(){
    List list1("Casa");
    List list2("Grigliata");

    list1.addProd(Prod("Pane", 2));
    list1.addProd(Prod("Latte"));
    list1.addProd(Prod("Uova", 6));

    list2.addProd(Prod("Salsicce", 10));
    list2.addProd(Prod("Hamburger", 5));
    list2.addProd(Prod("Carbonella"));

    //list1.setAmount("Uova", 4);
    //list2.removeProd("Hamburger");

    list1.printList();
    list2.printList();

    return 0;
};