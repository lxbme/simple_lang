#include "lexer.h"
#include "parser.h"
#include "compiler.h"
#include "misc.h"
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[]) {
    //const char *source_path = "./test.sl";
    if (argc != 2) {
        fprintf(stderr, "Take one argument: Path of source code.");
        exit(-1);
    }
    const char *source_path = argv[1];

    char * source = read_file(source_path);
    //const char* source = "let x = 1; let y = 2; let z = x + y;";
    Token* token = tokenize(source);
    ASTNode ** asts = parse(token);
    int number = 0;
    Instruction * instr = compile_asts(asts, &number);

    if (DEBUG) {
        printf("File: %s\n", source_path);
        printf("SourceCode: \n %s \n", source);
        show_tokens(token);
        print_asts(asts);
        show_opcode(instr, number);
    }

//    int number = 0;
//    Instruction * instr = compile(source, &number);
//    show_opcode(instr, number);
//    printf("%d", number);

    Frame * frame = init_frame();
    eval(frame, instr, number);
    free_frame(frame);
    free(source);
}
