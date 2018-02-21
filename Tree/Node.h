#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int funcVal(char* input);

class node {
    private:

        char flag;
        int value;
        node* root;
        node* left;
        node* right;

    public:

        node(char* input); //constructor automatically interprets string into a value, variable or function
        void print(); //test function just prints into a console
        bool isleaf(); //checks whenever current node leaf or not
        void addl (char* newdef); //adds node with 'newdef' value
        void addr (char* newdef);
        void remover(); //removes current node and all daughter nodes
};
