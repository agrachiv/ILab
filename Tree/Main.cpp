#include "Node.cpp"

int main() {
    node tree("^");
    tree.addl("+");
    tree.left->addr("0");
    tree.left->addl("6");
    tree.addr("exp");
    tree.right->addl("1");
    tree.calculate();
    tree.print();

    return 0;
}
