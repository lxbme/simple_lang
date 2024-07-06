set(TEST_LEXER
        test_lexer.c
)
set(TEST_PARSER
        test_parser.c
)


add_executable(test_lexer ${TEST_LEXER})
target_link_libraries(test_lexer simple_lang_lib)

add_executable(test_parser ${TEST_PARSER})
target_link_libraries(test_parser simple_lang_lib)
