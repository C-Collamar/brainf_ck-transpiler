/**
 * Syntax-directed translation scheme
 * start := expr { print('[...]char array[LARGE_BUFFER] = { 0 }, *ptr = array;') }
 * expr  := op expr'
 *       | op
 * expr' := op expr' | ε
 * op    := + { print('++*ptr') }
 *       |  - { print('--*ptr') }
 *       |  . { print('putchar(*ptr)') }
 *       |  , { print('*ptr = getchar()') }
 *       |  > { print('++ptr') }
 *       |  < { print('--ptr') }
 * loop  := [ { print('while(*ptr) {') } expr ] { print('}') }
 */

#define INDENTATION 4
#define PTR_ID "ptr"

char* expand(TreeNode *currNode) {
    if(currNode == NULL)
        return NULL;

    char *code = NULL;
    int index;

    switch(currNode->type) {
        //for non-terminals, expand each child nodes
        case NODE_START:
        case NODE_OP:
        case NODE_EXPR:
        case NODE_EXPR_CONT:
        case NODE_LOOP:;
            char *fragment;
            size_t codeLen;
            NodeList *child = currNode->children;

            while(child != NULL) {
                if((fragment = expand(child->node))) {
                    if(code == NULL) {
                        code = fragment;
                    }
                    else {
                        codeLen = strlen(code) + strlen(fragment);
                        code = realloc(code, sizeof(char) * (codeLen + 1));
                        code[codeLen] = '\0';
                        if(currNode->type == NODE_EXPR) {
                        }
                        strcat(code, fragment);
                        free(fragment);
                    }
                }
                child = child->next;
            }
            break;
        //handle terminals according to the syntax-directed translation
        case NODE_MOVE_LEFT:
            code = malloc(sizeof(char) * (currNode->depth * INDENTATION) + 8);
            for(index = 0; index < currNode->depth * INDENTATION; ++index) {
                code[index] = ' ';
            }
            code[index] = '\0';
            strcat(code, "--"PTR_ID";\n");
            break;
        case NODE_MOVE_RIGHT:
            code = malloc(sizeof(char) * (currNode->depth * INDENTATION) + 8);
            for(index = 0; index < currNode->depth * INDENTATION; ++index) {
                code[index] = ' ';
            }
            code[index] = '\0';
            strcat(code, "++"PTR_ID";\n");
            break;
        case NODE_INCREMENT:
            code = malloc(sizeof(char) * (currNode->depth * INDENTATION) + 9);
            for(index = 0; index < currNode->depth * INDENTATION; ++index) {
                code[index] = ' ';
            }
            code[index] = '\0';
            strcat(code, "++*"PTR_ID";\n");
            break;
        case NODE_DECREMENT:
            code = malloc(sizeof(char) * (currNode->depth * INDENTATION) + 9);
            for(index = 0; index < currNode->depth * INDENTATION; ++index) {
                code[index] = ' ';
            }
            code[index] = '\0';
            strcat(code, "--*"PTR_ID";\n");
            break;
        case NODE_OUTPUT:
            code = malloc(sizeof(char) * (currNode->depth * INDENTATION) + 16);
            for(index = 0; index < currNode->depth * INDENTATION; ++index) {
                code[index] = ' ';
            }
            code[index] = '\0';
            strcat(code, "putchar(*"PTR_ID");\n");
            break;
        case NODE_INPUT:
            code = malloc(sizeof(char) * (currNode->depth * INDENTATION) + 19);
            for(index = 0; index < currNode->depth * INDENTATION; ++index) {
                code[index] = ' ';
            }
            code[index] = '\0';
            strcat(code, "*"PTR_ID" = getchar();\n");
            break;
        case NODE_JUMP_FORWARD:
            code = malloc(sizeof(char) * (currNode->depth * INDENTATION) + 15);
            for(index = 0; index < currNode->depth * INDENTATION; ++index) {
                code[index] = ' ';
            }
            code[index] = '\0';
            strcat(code, "while(*"PTR_ID") {\n");
            break;
        case NODE_JUMP_BACKWARD:
            code = malloc(sizeof(char) * (currNode->depth * INDENTATION) + 3);
            for(index = 0; index < currNode->depth * INDENTATION; ++index) {
                code[index] = ' ';
            }
            code[index] = '\0';
            strcat(code, "}\n");
            break;
    }

    return code;
}

/**
 * Performs syntax-directed translation given the generated
 * syntax tree.
 */
char* translate() {
    char *precode =
        "/**\n"
        " * This code is generated by our Brainf*** compiler.\n"
        " * You can edit this file however you like, perhaps\n"
        " * modify the BUFFER_SIZE to your needs in case you\n"
        " * need to for some reason.\n"
        " */\n\n"
        "#include<stdio.h>\n\n"
        "#define BUFFER_SIZE 1024\n\n"
        "void main(void) {\n"
        "    char array[BUFFER_SIZE] = { 0 };\n"
        "    char *ptr = array;\n\n"
    ;
    char *fragment = expand(syntaxTree);

    char *code = malloc(sizeof(char) * (strlen(precode) + strlen(fragment) + 2));
    strcpy(code, precode);
    strcat(code, fragment);
    strcat(code, "}");
    free(fragment);

    return code;
}
