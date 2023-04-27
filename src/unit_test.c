/*do not edit this file*/

#include <stdio.h>

#ifdef TEST
#define TESTCODE
#endif
int g_unit_test_error_count = 0;
int g_unit_test_success_count = 0;
#ifdef TESTCODE

/*forward declarations*/

/* tests from tokenizer.c*/
void test_lexeme_cmp(void);
void token_list_pop_front_test(void);
void token_list_pop_back_test(void);
int token_list_append_list_test(void);
void test_collect(void);
void test_va_opt_0(void);
void test_va_opt_1(void);
void test_va_opt(void);
void test_empty_va_args(void);
void test_va_args_single(void);
void test_va_args_extra_args(void);
void test_empty_va_args_empty(void);
void test_defined(void);
void testline(void);
void ifelse(void);
void T1(void);
int EXAMPLE5(void);
void recursivetest1(void);
void rectest(void);
void emptycall(void);
void semiempty(void);
void calling_one_arg_with_empty_arg(void);
void test_argument_with_parentesis(void);
void two_empty_arguments(void);
void simple_object_macro(void);
void test_one_file(void);
void test2(void);
void test3(void);
void tetris(void);
void recursive_macro_expansion(void);
void empty_and_no_args(void);
void test4(void);
void test_string(void);
void test6(void);
void testerror(void);
int test_expression(void);
int test_concatenation_o(void);
int test_concatenation(void);
void bad_test(void);
int test_spaces(void);
int test_stringfy(void);
int test_tokens(void);
int test_predefined_macros(void);
int test_utf8(void);
int test_line_continuation(void);

/* tests from parser.c*/
void parser_specifier_test(void);
void array_item_type_test(void);
void take_address_type_test(void);
void parser_scope_test(void);
void parser_tag_test(void);
void string_concatenation_test(void);
void test_digit_separator(void);
void test_lit(void);
void type_test2(void);
void type_test3(void);
void crazy_decl(void);
void crazy_decl2(void);
void crazy_decl4(void);
void sizeof_array_test(void);
void sizeof_test(void);
void alignof_test(void);
void indirection_struct_size(void);
void traits_test(void);
void comp_error1(void);
void array_size(void);
void expr_type(void);
void expand_test(void);
void expand_test2(void);
void expand_test3(void);
void bigtest(void);
void literal_string_type(void);
void digit_separator_test(void);
void numbers_test(void);
void binary_digits_test(void);
void type_suffix_test(void);
void type_test(void);
void is_pointer_test(void);
void params_test(void);
void test_compiler_constant_expression(void);
void zerodiv(void);
void auto_test(void);
void function_result_test(void);

/*end of forward declarations*/

int test_main(void)
{
g_unit_test_error_count = 0;
g_unit_test_success_count = 0;
    test_lexeme_cmp();
    token_list_pop_front_test();
    token_list_pop_back_test();
    token_list_append_list_test();
    test_collect();
    test_va_opt_0();
    test_va_opt_1();
    test_va_opt();
    test_empty_va_args();
    test_va_args_single();
    test_va_args_extra_args();
    test_empty_va_args_empty();
    test_defined();
    testline();
    ifelse();
    T1();
    EXAMPLE5();
    recursivetest1();
    rectest();
    emptycall();
    semiempty();
    calling_one_arg_with_empty_arg();
    test_argument_with_parentesis();
    two_empty_arguments();
    simple_object_macro();
    test_one_file();
    test2();
    test3();
    tetris();
    recursive_macro_expansion();
    empty_and_no_args();
    test4();
    test_string();
    test6();
    testerror();
    test_expression();
    test_concatenation_o();
    test_concatenation();
    bad_test();
    test_spaces();
    test_stringfy();
    test_tokens();
    test_predefined_macros();
    test_utf8();
    test_line_continuation();
    parser_specifier_test();
    array_item_type_test();
    take_address_type_test();
    parser_scope_test();
    parser_tag_test();
    string_concatenation_test();
    test_digit_separator();
    test_lit();
    type_test2();
    type_test3();
    crazy_decl();
    crazy_decl2();
    crazy_decl4();
    sizeof_array_test();
    sizeof_test();
    alignof_test();
    indirection_struct_size();
    traits_test();
    comp_error1();
    array_size();
    expr_type();
    expand_test();
    expand_test2();
    expand_test3();
    bigtest();
    literal_string_type();
    digit_separator_test();
    numbers_test();
    binary_digits_test();
    type_suffix_test();
    type_test();
    is_pointer_test();
    params_test();
    test_compiler_constant_expression();
    zerodiv();
    auto_test();
    function_result_test();
return g_unit_test_error_count;

}
#undef TESTCODE
#endif /*TEST*/
