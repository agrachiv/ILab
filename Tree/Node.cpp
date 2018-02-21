
#include "Node.h"

//flags
#define Number 0;
#define Function 1;
#define Variable 2;

int funcVal(char* input){
                if (strcmp (input, "sin") == 0)  return 1;
                if (strcmp (input, "cos") == 0)  return 2;
                if (strcmp (input, "tg") == 0)   return 3;
                if (strcmp (input, "ctg") == 0)  return 4;
                if (strcmp (input, "asin") == 0) return 5;
                if (strcmp (input, "acos") == 0) return 6;
                if (strcmp (input, "atg") == 0)  return 7;
                if (strcmp (input, "actg") == 0) return 8;
                if (strcmp (input, "+") == 0)    return 9;
                if (strcmp (input, "-") == 0)    return 10;
                if (strcmp (input, "*") == 0)    return 11;
                if (strcmp (input, "/") == 0)    return 12;
                if (strcmp (input, "^") == 0)    return 13;
                if (strcmp (input, "exp") == 0)  return 14;
                if (strcmp (input, "ln") == 0)   return 15;
                assert(false);
}

node::node(char* input) {

            root = NULL;
            left = NULL;
            right = NULL;

            if (
                (strcmp (input, "sin") == 0)  ||
                (strcmp (input, "cos") == 0)  ||
                (strcmp (input, "tg") == 0)   ||
                (strcmp (input, "ctg") == 0)  ||
                (strcmp (input, "asin") == 0) ||
                (strcmp (input, "acos") == 0) ||
                (strcmp (input, "atg") == 0)  ||
                (strcmp (input, "actg") == 0) ||
                (strcmp (input, "+") == 0)    ||
                (strcmp (input, "-") == 0)    ||
                (strcmp (input, "*") == 0)    ||
                (strcmp (input, "/") == 0)    ||
                (strcmp (input, "^") == 0)    ||
                (strcmp (input, "exp") == 0)  ||
                (strcmp (input, "ln") == 0)) {



                flag = Function;
                value = funcVal (input); \

            } else {

                for (int i = 1; i < strlen (input); i++) {
                    assert (input[i] >= 48 && input[i] <= 57); //input is not a variable, number or function
                }

                if (*input < 48 || *input > 57) {

                    for (int i = 1; i < strlen (input); i++) {
                        assert (strlen (input) == 1); //input is not a variable, number or function
                    }

                    flag = Variable;
                    value = *input;
                } else {

                    flag = Number;
                    assert (atoi (input) != 0); //integer not found
                    value = atoi (input);

                }

            }
        }

void node::print() {
            if (left != NULL) {
                left->print();
            }

            printf ("\n flag = %d\n", flag);
            printf ("\n value = %d\n", value);

            if (right != NULL) {
                right->print();
            }
        }

bool node::isleaf () {
            if (left == NULL && right == NULL) {
                return 1;
            } else {
                return 0;
            }
        }

void node::addl (char* newdef) {
            assert (left == NULL);
            left = new node (newdef);
            left->root = this;
        }

void node::addr (char* newdef) {
            assert (right == NULL);
            right = new node (newdef);
            right->root = this;
        }

void node::remover() {

            if (left != NULL) {
                left->remover();
            }

            if (right != NULL) {
                left->remover();
            }

            delete left;
            delete right;

            left = NULL;
            right = NULL;
        }
