#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define spec "%d\n" // тут нормальный принт сложно реализовать, так как тип передается в виде спецификаторов
template <typename type>
class Stack {



    private:
        struct node {
            type value;
            node* next;
        };

        node* tail;

    public:

        Stack() {
            tail = NULL;

        }


        int emp() {

            if (tail == NULL) return 1;
            else return 0;

        }

        bool push (type input) {
            node* topNode = new node;

            if (!topNode) return 0;

            topNode->value = input;
            topNode->next = tail;
            tail = topNode;

            return 1;
        }

        type pop() {

            assert (tail);

            type output = tail->value;
            tail = tail->next;
            return output;
        }



        void print() { //-||-

            if (emp() == 0) printf (spec, tail->value);

        }
};

int main() {


    Stack<int> Stack1;
    Stack1.push(3);
    Stack1.print();
    Stack1.push(4);
    int a = Stack1.pop();
    Stack1.print();
    printf("%d",a);
    return 0;
}
