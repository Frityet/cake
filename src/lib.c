




#ifndef __OWNERSHIP_H__
#define __OWNERSHIP_H__

#ifdef __STDC_OWNERSHIP__
 /*
   ownership is suported
 */
#define out _Out
#define opt _Opt
#define owner _Owner
#define obj_owner  _Obj_owner
#define view _View
#define unchecked "unchecked"


void* owner calloc(int nmemb, int size);
void free(void* owner opt ptr);
void* owner malloc(int size);
void* owner realloc(void*  ptr, int size);
char * owner strdup( const char *src );

typedef struct _iobuf FILE;
FILE* owner fopen(char const* _FileName, char const* _Mode);
int fclose(FILE* owner _Stream);

#else
#define out
#define opt
#define owner
#define obj_owner
#define view
#define static_debug(x)
#define static_set(x, s)
#define unchecked
#endif

#endif




#include <stdlib.h>


#include <assert.h>


#include <stdio.h>


#include <string.h>


//#pragma once



#include <stdbool.h>

#ifdef _WIN32


#include <conio.h>
#else
//#include <curses.h>
#endif



bool enable_vt_mode(void);

//#define DISABLE_COLORS 1

#ifdef DISABLE_COLORS

#define ESC ""
#define CSI ""

#define BLACK      ""
#define BLUE      ""
#define GREEN     ""
#define CYAN     ""
#define RED ""
#define MAGENTA      ""
#define BROWN     ""
#define LIGHTGRAY  ""
#define DARKGRAY ""
#define LIGHTBLUE ""
#define  LIGHTGREEN ""
#define LIGHTCYAN  ""
#define LIGHTRED ""
#define LIGHTMAGENTA  ""
#define YELLOW ""
#define WHITE ""

//https//en.wikipedia.org/wiki/ANSI_escape_code


#define BK_BLACK "" 
#define BK_BLUE ""
#define BK_GREEN  ""
#define BK_CYAN ""
#define BK_RED ""
#define BK_MAGENTA ""
#define BK_BROWN ""
#define BK_LIGHTGRAY ""
#define BK_DARKGRAY ""
#define BK_LIGHTBLUE ""
#define BK_LIGHTGREEN ""
#define BK_LIGHTCYAN ""
#define BK_LIGHTRED ""
#define BK_LIGHTMAGENTA ""
#define BK_YELLOW       ""
#define BK_WHITE        ""
#define BK_BLINK ""
#define RESET ESC ""
#else
/*change foreground color*/

#define ESC "\x1b"
#define CSI "\x1b["

#define BLACK     "\x1b[30m"
#define BLUE     "\x1b[34m"
#define GREEN     "\x1b[32m"
#define CYAN     "\x1b[36m"
#define RED "\x1b[31;1m"
#define MAGENTA     "\x1b[35m"
#define BROWN     "\x1b[31m"
#define LIGHTGRAY "\x1b[37m"
#define DARKGRAY "\x1b[90m"
#define LIGHTBLUE    "\x1b[34;1m"
#define  LIGHTGREEN "\x1b[92m"
#define LIGHTCYAN "\x1b[36;1m"
#define LIGHTRED "\x1b[91m"
#define LIGHTMAGENTA "\x1b[95m"
#define YELLOW "\x1b[93m"
#define WHITE "\x1b[97m"

    //https//en.wikipedia.org/wiki/ANSI_escape_code


#define BK_BLACK "\x1b[40m"
#define BK_BLUE "\x1b[44m"
#define BK_GREEN  "\x1b[42m"
#define BK_CYAN "\x1b[46m"
#define BK_RED "\x1b[41;1m"
#define BK_MAGENTA "\x1b[45m"
#define BK_BROWN "\x1b[41m"
#define BK_LIGHTGRAY "\x1b[40;1m"
#define BK_DARKGRAY "\x1b[40m"
#define BK_LIGHTBLUE "\x1b[44;1m"
#define BK_LIGHTGREEN "\x1b[42,1m"
#define BK_LIGHTCYAN "\x1b[46;1m"
#define BK_LIGHTRED "\x1b[41;1m"
#define BK_LIGHTMAGENTA "\x1b[45;1m"
#define BK_YELLOW             "\x1b[43;1m"
#define BK_WHITE             "\x1b[47;1m"
#define BK_BLINK "\x1b[40m"
            
#define RESET ESC "[0m"

#endif


int c_kbhit(void);
int c_getch(void);

void c_clrscr();



//#pragma once



#include <stdarg.h>

struct osstream
{
    char* owner c_str;
    int size;
    int capacity;
};


void ss_close( struct osstream * obj_owner stream);

int ss_vafprintf(struct osstream* stream, const char* fmt, va_list args);
int ss_fprintf(struct osstream* stream, const char* fmt, ...);
int ss_putc(char ch, struct osstream* stream);
void ss_clear(struct osstream* stream);
void ss_swap(struct osstream* a, struct osstream* b);



//#pragma once


//#pragma once
/*
* tag allow more than one type of object be inserted at the same map
*/
enum tag
{
    TAG_TYPE_NONE,
    
    TAG_TYPE_ENUN_SPECIFIER,
    TAG_TYPE_STRUCT_OR_UNION_SPECIFIER,

    TAG_TYPE_ENUMERATOR,
    TAG_TYPE_ONLY_DECLARATOR,
    TAG_TYPE_INIT_DECLARATOR,
};


struct map_entry {
    struct map_entry* owner next;
    unsigned int hash;
    char* owner key;
    void* p;
    enum tag type; /*type of the object pointed by p*/
};

struct hash_map {
    struct map_entry *owner * owner table;
    int capacity;
    int  size;
};

void hashmap_remove_all(struct hash_map* map);
void hashmap_destroy( struct hash_map* obj_owner map);
struct map_entry* hashmap_find(struct hash_map* map, const char* key);
void* hashmap_remove(struct hash_map* map, const char* key, enum tag* p_type_opt);
int hashmap_set(struct hash_map* map, const char* key, const void* p, enum tag type);


struct owner_map_entry {
    struct owner_map_entry* owner next;
    unsigned int hash;
    char* owner key;
    void* owner p;
    enum tag type; /*type of the object pointed by p*/
};

struct owner_hash_map {
    struct owner_map_entry *owner * owner table;
    int capacity;
    int  size;
};

void owner_hashmap_remove_all(struct owner_hash_map* map, void (*pf)(void* owner ));
void owner_hashmap_destroy( struct owner_hash_map* obj_owner map, void (*pf)(void*));
struct owner_map_entry* owner_hashmap_find(struct owner_hash_map* map, const char* key);
void*  owner owner_hashmap_remove(struct owner_hash_map* map, const char* key, enum tag* p_type_opt);
void* owner owner_hashmap_set(struct owner_hash_map* map, const char* key, const void* owner p, enum tag type);




//#pragma once

enum token_type
{
    TK_NONE = 0,
    TK_NEWLINE = '\n',
    TK_WHITE_SPACE = ' ',
    TK_EXCLAMATION_MARK = '!',
    TK_QUOTATION_MARK = '"',
    TK_NUMBER_SIGN = '#',
    TK_DOLLAR_SIGN = '$',
    TK_PERCENT_SIGN = '%',
    TK_AMPERSAND = '&',
    TK_APOSTROPHE = '\'',
    TK_LEFT_PARENTHESIS = '(',
    TK_RIGHT_PARENTHESIS = ')',
    TK_ASTERISK = '*',
    TK_PLUS_SIGN = '+',
    TK_COMMA = ',',
    TK_HYPHEN_MINUS = '-',
    TK_FULL_STOP = '.',
    TK_SOLIDUS = '/',
    TK_COLON = ':',
    TK_SEMICOLON = ';',
    TK_LESS_THAN_SIGN = '<',
    TK_EQUALS_SIGN = '=',
    TK_GREATER_THAN_SIGN = '>',
    TK_QUESTION_MARK = '?',
    TK_COMMERCIAL_AT = '@',
    TK_LEFT_SQUARE_BRACKET = '[',
    TK_REVERSE_SOLIDUS = '//',
    TK_RIGHT_SQUARE_BRACKET = ']',
    TK_CIRCUMFLEX_ACCENT = '^',
    TK_FLOW_LINE = '_',
    TK_GRAVE_ACCENT = '`',
    TK_LEFT_CURLY_BRACKET = '{',
    TK_VERTICAL_LINE = '|',
    TK_RIGHT_CURLY_BRACKET = '}',
    TK_TILDE = '~',
    TK_PREPROCESSOR_LINE,
    TK_PRAGMA,
    TK_STRING_LITERAL,
    TK_CHAR_CONSTANT,    
    TK_LINE_COMMENT,
    TK_COMMENT,
    TK_PPNUMBER,

    ANY_OTHER_PP_TOKEN, //@ por ex

    /*PPNUMBER sao convertidos para constantes antes do parse*/
    TK_COMPILER_DECIMAL_CONSTANT,
    TK_COMPILER_OCTAL_CONSTANT,
    TK_COMPILER_HEXADECIMAL_CONSTANT,
    TK_COMPILER_BINARY_CONSTANT,
    TK_COMPILER_DECIMAL_FLOATING_CONSTANT,
    TK_COMPILER_HEXADECIMAL_FLOATING_CONSTANT,


    TK_PLACEMARKER,

    TK_BLANKS,
    TK_PLUSPLUS = '++',
    TK_MINUSMINUS = '--',
    TK_ARROW = '->',
    TK_SHIFTLEFT = '<<',
    TK_SHIFTRIGHT = '>>',
    TK_LOGICAL_OPERATOR_OR = '||',
    TK_LOGICAL_OPERATOR_AND = '&&',

    TK_MACRO_CONCATENATE_OPERATOR = '##',

    TK_IDENTIFIER,
    TK_IDENTIFIER_RECURSIVE_MACRO, /*usado para evitar recursao expansao macro*/

    TK_BEGIN_OF_FILE,

    //C23 keywords
    TK_KEYWORD_AUTO,
    TK_KEYWORD_BREAK,
    TK_KEYWORD_CASE,
    TK_KEYWORD_CONSTEXPR,
    TK_KEYWORD_CHAR,
    TK_KEYWORD_CONST,
    TK_KEYWORD_CONTINUE,
    TK_KEYWORD_CATCH, /*extension*/
    TK_KEYWORD_DEFAULT,
    TK_KEYWORD_DO,
    TK_KEYWORD_DEFER, /*extension*/
    TK_KEYWORD_DOUBLE,
    TK_KEYWORD_ELSE,
    TK_KEYWORD_ENUM,
    TK_KEYWORD_EXTERN,
    TK_KEYWORD_FLOAT,
    TK_KEYWORD_FOR,
    TK_KEYWORD_GOTO,
    TK_KEYWORD_IF,
    TK_KEYWORD_INLINE,
    TK_KEYWORD_INT,
    TK_KEYWORD_LONG,
    TK_KEYWORD__INT8,
    TK_KEYWORD__INT16,
    TK_KEYWORD__INT32,
    TK_KEYWORD__INT64,

    TK_KEYWORD_REGISTER,
    TK_KEYWORD_RESTRICT,
    TK_KEYWORD_RETURN,
    TK_KEYWORD_SHORT,
    TK_KEYWORD_SIGNED,
    TK_KEYWORD_SIZEOF,
    
    TK_KEYWORD_STATIC,
    TK_KEYWORD_STRUCT,
    TK_KEYWORD_SWITCH,
    TK_KEYWORD_TYPEDEF,
    TK_KEYWORD_TRY, /*extension*/
    TK_KEYWORD_THROW, /*extension*/
    TK_KEYWORD_UNION,
    TK_KEYWORD_UNSIGNED,
    TK_KEYWORD_VOID,
    TK_KEYWORD_VOLATILE,
    TK_KEYWORD_WHILE,
    
    TK_KEYWORD__ALIGNAS,
    TK_KEYWORD__ALIGNOF,
    TK_KEYWORD__ATOMIC,
    //microsoft
    //KEYWORD__FASTCALL,
    //KEYWORD__STDCALL
    // 
    TK_KEYWORD__ASM,
    //end microsoft
    TK_KEYWORD__BOOL,
    TK_KEYWORD__COMPLEX,
    TK_KEYWORD__DECIMAL128,
    TK_KEYWORD__DECIMAL32,
    TK_KEYWORD__DECIMAL64,
    TK_KEYWORD__GENERIC,
    TK_KEYWORD__IMAGINARY,
    TK_KEYWORD__NORETURN,
    TK_KEYWORD__STATIC_ASSERT,    
    TK_KEYWORD_ASSERT, /*extension*/
    TK_KEYWORD__THREAD_LOCAL,

    TK_KEYWORD_TYPEOF, /*C23*/
    
    TK_KEYWORD_TRUE,  /*C23*/
    TK_KEYWORD_FALSE,  /*C23*/
    TK_KEYWORD_NULLPTR,  /*C23*/
    TK_KEYWORD_TYPEOF_UNQUAL, /*C23*/
    TK_KEYWORD__BITINT /*C23*/,

    

    /*cake extension*/
    TK_KEYWORD__OWNER,
    TK_KEYWORD__OUT,
    TK_KEYWORD__OBJ_OWNER, 
    TK_KEYWORD__VIEW,    
    TK_KEYWORD__OPT, 

    /*extension compile time functions*/
    TK_KEYWORD_STATIC_DEBUG, /*extension*/
    TK_KEYWORD_STATIC_STATE, /*extension*/
    TK_KEYWORD_STATIC_SET, /*extension*/
    TK_KEYWORD_ATTR_ADD, /*extension*/
    TK_KEYWORD_ATTR_REMOVE, /*extension*/
    TK_KEYWORD_ATTR_HAS, /*extension*/
    
    /*https://en.cppreference.com/w/cpp/header/type_traits*/
    
    TK_KEYWORD_IS_POINTER,
    TK_KEYWORD_IS_LVALUE,
    TK_KEYWORD_IS_CONST,
    TK_KEYWORD_IS_OWNER,
    TK_KEYWORD_IS_ARRAY,
    TK_KEYWORD_IS_FUNCTION,
    TK_KEYWORD_IS_SCALAR,
    TK_KEYWORD_IS_ARITHMETIC,
    TK_KEYWORD_IS_FLOATING_POINT,
    TK_KEYWORD_IS_INTEGRAL,
    

};

enum token_flags
{
    TK_FLAG_NONE = 0,
    TK_FLAG_FINAL = 1 << 0,
    TK_FLAG_MACRO_EXPANDED = 1 << 1,    /*tokens expandidos pela macro*/
    TK_FLAG_HAS_SPACE_BEFORE = 1 << 2,
    TK_FLAG_HAS_NEWLINE_BEFORE = 1 << 3,
    TK_FLAG_IDENTIFIER_IS_TYPEDEF = 1 << 4, /*indica que eh identificador typedef*/
    TK_FLAG_IDENTIFIER_IS_NOT_TYPEDEF = 1 << 5,
    TK_FLAG_HIDE = 1 << 6, /*alguem pediu p esconder*/
    TK_FLAG_IDENTIFIER_IS_ENUMERATOR = 1 << 7, /*indica que eh identificador enumerator separar?*/
    TK_FLAG_IDENTIFIER_IS_NOT_ENUMERATOR = 1 << 8, /*indica que eh identificador enumerator separar?*/    
    TK_FLAG_SLICED = 1 << 9, /*line-slicing in the middle*/
    TK_FLAG_LINE_CONTINUATION = 1 << 10 /*token has one or more line-slicing*/
};

struct token
{
    enum token_type type;
    char* owner lexeme;
    char* original;

    int line;
    int col;

    /*nivel de includes, 0 primeiro arquivo*/
    int level;

    enum token_flags flags;

    /*points to the token with file name or macro*/
    struct token* token_origin;

    struct token* owner next;
    struct token* prev;
};

void token_delete( struct token* owner p);

struct token_list
{
    struct token* owner head;
    struct token* tail;
};
void token_list_set_file(struct token_list* list, struct token* filetoken, int line, int col);
bool token_list_is_empty(struct token_list* p);
void token_list_swap(struct token_list* a, struct token_list* b);

struct token* owner clone_token(struct token* p);
struct token* token_list_add(struct token_list* list, struct token* owner pnew);
void token_list_remove(struct token_list* list, struct token* first, struct token* last);
struct token_list token_list_remove_get(struct token_list* list, struct token* first, struct token* last);
void token_list_append_list(struct token_list* dest, struct token_list* source);
void token_list_append_list_at_beginning(struct token_list* dest, struct token_list* source);
struct token* token_list_clone_and_add(struct token_list* list, struct token* pnew);
char* owner token_list_join_tokens(struct token_list* list, bool bliteral);
void token_list_clear(struct token_list* list);
bool token_is_blank(struct token* p);
void token_range_add_flag(struct token* first, struct token* last, enum token_flags flag);
void token_range_remove_flag(struct token* first, struct token* last, enum token_flags flag);
void token_range_add_show(struct token* first, struct token* last);

void print_tokens_html(struct token* p_token);
void print_line_and_token(const struct token* p_token, bool visual_studio_ouput_format);
void print_position(const char* path, int line, int col, bool msvc_format);
struct stream
{
    const char* source;
    const char* current;
    int line;
    int col;
    int line_continuation_count;
    const char* path; /*non owner*/
};

int is_digit(struct stream* p);
int is_nondigit(struct stream* p);
void stream_match(struct stream* stream);

#define LIST_ADD(list, pnew)\
do {\
    void* owner pitem = (void* owner) (pnew);\
    if ((list)->head == NULL)\
    {\
        (list)->head = pitem;\
        (list)->tail = pitem;\
    } else \
    {\
        (list)->tail->next = pitem;\
        (list)->tail = pitem;\
    }\
} while(0)

bool style_has_space(const struct token* token);
bool style_has_one_space(const struct token* token);


//#pragma once

#ifndef __CAKE__

#define try  
#define catch if (0) catch_label:
#define throw goto catch_label

#endif

const char* get_posix_error_message(int error);
int windows_error_to_posix(int i);




//#pragma once

/*
* Compiler options shared with compiler and preprocessor
*/

enum language_version
{
    LANGUAGE_C89 = -1,
    LANGUAGE_C99 = 0, /*default*/
    LANGUAGE_C11 = 1,
    LANGUAGE_C2X = 2, //C23
    LANGUAGE_CXX = 3, //experimental
};

enum warning {    
    W_NONE = 0,  /*not a real warning, used in especial cases*/
    W_UNUSED_VARIABLE = 1 << 1, //-Wunused-variable
    W_DEPRECATED = 1 << 2,
    W_ENUN_CONVERSION = 1 << 3 ,//-Wenum-conversion
    W_NON_NULL = 1 << 4, //-Wnonnull
    W_ADDRESS = 1 << 5, //-Waddress (always true)
    W_UNUSED_PARAMETER = 1 << 6, //-Wno-unused-parameter
    W_DECLARATOR_HIDE = 1 << 7, // gcc no
    W_TYPEOF_ARRAY_PARAMETER = 1 << 8,//
    W_ATTRIBUTES = 1 << 9, //-Wattributes
    W_UNUSED_VALUE = 1 << 10, //-Wunused-value
    W_STYLE = 1 << 11, //-Wstyle
    W_COMMENT = 1 << 12,
    W_LINE_SLICING = 1 << 13,
    W_STRING_SLICED = 1 << 14,
    W_DISCARDED_QUALIFIERS = 1 << 15,
    W_DECLARATOR_STATE = 1 << 16,
    W_UNINITIALZED  = 1 << 17,
    
    W_RETURN_LOCAL_ADDR = 1 << 20,
    
};

enum error
{ 
    C_SUCCESS = 0,
    C_UNEXPECTED,    
    C_TOO_MANY_ARGUMENTS,
    C_TOO_FEW_ARGUMENTS,
    C_NOT_FOUND,
    C_NO_MATCH_FOR_GENERIC,
    C_SUBSCRIPTED_VALUE_IS_NEITHER_ARRAY_NOR_POINTER,
    C_CALLED_OBJECT_IS_NOT_FUNCTION_OR_FUNCTION_POINTER,
    C_STRUCT_MEMBER_NOT_FOUND,
    C_STRUCTURE_OR_UNION_REQUIRED,
    C_STRUCT_IS_INCOMPLETE,
    C_DECLARATOR_NOT_FOUND,
    C_EXPECTED_DECLARATOR_NAME,
    C_UNKNOWN_ATTRIBUTE_NAME,
    C_INDIRECTION_REQUIRES_POINTER_OPERAND,
    C_INVALID_TOKEN,
    C_EXPECTED_STRUCT_TYPE,
    C_EXPECTED_TYPE_NAME,
    C_LEFT_IS_NOT_ARITHMETIC,
    C_RIGHT_IS_NOT_ARITHMETIC,
    C_DIVIZION_BY_ZERO,
    C_LEFT_IS_NOT_INTEGER,
    C_RIGHT_IS_NOT_INTEGER,
    C_INVALID_TYPE,
    C_LEFT_IS_NOT_SCALAR,
    C_RIGHT_IS_NOT_SCALAR,
    C_INCOMPATIBLE_POINTER_TYPES,
    C_ASSIGNMENT_OF_FUNCTION,
    C_ASSIGNMENT_TO_EXPRESSION_WITH_ARRAY_TYPE,
    C_ASSIGNMENT_OF_READ_ONLY_OBJECT,
    C_LVALUE_ASSIGNMENT,
    C_CONDITION_MUST_HAVE_SCALAR_TYPE,
    C_INCOMPATIBLE_TYPES,
    C_EXPECTED_CONSTANT_EXPRESSION,
    C_UNEXPECTED_TOKEN,
    C_CANNOT_COMBINE_WITH_PREVIOUS_LONG_LONG,
    C_EXPECTED_DECLARATION,
    C_STATIC_OR_TYPE_QUALIFIERS_NOT_ALLOWED_IN_NON_PARAMETER,
    C_OBJ_OWNER_CAN_BE_USED_ONLY_IN_POINTER,
    C_REDECLARATION,
    C_TAG_TYPE_DOES_NOT_MATCH_PREVIOUS_DECLARATION,
    C_MISSING_ENUM_TAG_NAME,
    C_MULTIPLE_DEFINITION_ENUM,
    C_STATIC_ASSERT_FAILED,
    C_ATTR_UNBALANCED,    
    C_UNEXPECTED_END_OF_FILE,
    C_THROW_STATEMENT_NOT_WITHIN_TRY_BLOCK,
    C_VOID_FUNCTION_SHOULD_NOT_RETURN_VALUE,
    C_ARGUMENT_SIZE_SMALLER_THAN_PARAMETER_SIZE,
    C_PASSING_NULL_AS_ARRAY,
    C_DISCARDING_CONST_AT_ARGUMENT,
    C_INCOMPATIBLE_ENUN_TYPES,
    C_TOKEN_NOT_VALID_IN_PREPROCESSOR_EXPRESSIONS,
    C_FILE_NOT_FOUND,
    C_MISSING_CLOSE_PARENTHESIS,
    C_EXPRESSION_ERROR,
    C_PREPROCESSOR_ERROR_DIRECTIVE,
    C_TOO_FEW_ARGUMENTS_TO_FUNCTION_LIKE_MACRO,
    C_MACRO_INVALID_ARG,
    C_MISSING_MACRO_ARGUMENT,
    C_ADDRESS_OF_REGISTER,
    C_OPERATOR_NEEDS_LVALUE, //C2105
    C_MULTICHAR_ERROR,
    C_CHARACTER_TOO_LARGE,
    C_OWNERSHIP_NON_OWNER_MOVE,
    C_PRAGMA_ERROR,
    /*ownership type system errors*/
    C_OWNERSHIP_MISSING_OWNER_QUALIFIER,
    C_OWNERSHIP_NOT_OWNER,
    C_OWNERSHIP_USING_TEMPORARY_OWNER,
    C_OWNERSHIP_MOVE_ASSIGNMENT_OF_NON_OWNER,
    
    C_OWNERSHIP_NON_OWNER_TO_OWNER_ASSIGN,
    C_DISCARDING_OWNER,
    
    /*flow analysis errors*/
    C_OWNERSHIP_FLOW_MISSING_DTOR,    
};

bool is_ownership_error(enum error e);

enum style
{
    STYLE_CAKE,

    // https://llvm.org/docs/CodingStandards.html
    STYLE_LLVM,// A style complying with the LLVM coding standards
    
    //https://google.github.io/styleguide/cppguide.html
    STYLE_GOOGLE,// A style complying with Google’s C++ style guide

    //https://chromium.googlesource.com/chromium/src/+/refs/heads/main/styleguide/styleguide.md
    //https://www.kernel.org/doc/html/latest/process/coding-style.html
    STYLE_CHROMIUM,// A style complying with Chromium’s style guide
    
    //https://firefox-source-docs.mozilla.org/code-quality/coding-style/index.html
    STYLE_MOZILLA,// A style complying with Mozilla’s style guide
    
    //https://www.webkit.org/code-style-guidelines/
    STYLE_WEBKIT,// A style complying with WebKit’s style guide
    
    STYLE_MICROSOFT,// A style complying with Microsoft’s style guide
    
    STYLE_GNU,// A style complying with the GNU coding standards
    
};
const char* get_warning_name(enum warning w);
enum warning  get_warning_flag(const char* wname);

struct options
{
    /*
       -std=c99
    */
    enum language_version input;

    /*
       -target=c99
    */
    enum language_version target;
    
    /*
      #pragma CAKE diagnostic push
      #pragma CAKE diagnostic pop
    */
    int enabled_warnings_stack_top_index;
    enum warning enabled_warnings_stack[10];

    enum style style;

    /*
       Causes the compiler to output a list of the include files.
       The option also displays nested include files, that is, 
       the files included by the files that you include.
    */
    bool show_includes;

    /*
       -remove-comments  
    */
    bool remove_comments;    

    /*
       -flow-analysis
    */
    bool flow_analysis;

    /*
      -E 
    */
    bool preprocess_only;

    bool disable_ownership_errors;
    /*
      -rm
      -direct-compilation
    */
    bool direct_compilation;

    /*
      -sarif
    */
    bool sarif_output;

    bool format_input;
    bool format_ouput;
    
    
    /*
      -no-output
      if true cake does not generate ouput
    */
    bool no_output;
    
    /* 
    -nullchecks
     
    */
    bool null_checks;

    /*
      -msvc-output
    */
    bool visual_studio_ouput_format;

    /*
      -o filename
      defines the ouputfile when 1 file is used
    */
    char output[200];
};

int fill_options(struct options* options,
                 int argc,
                 const char** argv);

void print_help();


struct include_dir
{
    const char* owner path;
    struct include_dir* owner next;
};

struct include_dir_list
{
    struct include_dir* owner head;
    struct include_dir* tail;
};


enum preprocessor_ctx_flags
{
    PREPROCESSOR_CTX_FLAGS_NONE = 0,
    PREPROCESSOR_CTX_FLAGS_ONLY_FINAL = 1 << 0
};

struct preprocessor_ctx
{
    struct options options;
    enum preprocessor_ctx_flags flags;
    struct owner_hash_map macros;
    struct include_dir_list include_dir;

    /*map of pragma once already included files*/
    struct hash_map pragma_once_map;
    
    struct token* current;
    struct token_list input_list;

    bool conditional_inclusion;
    int n_warnings;
    int n_errors;    
};
void preprocessor_ctx_destroy( struct preprocessor_ctx* obj_owner p);

void preprocessor_set_info_with_token(struct preprocessor_ctx* ctx, const struct token* p_token, const char* fmt, ...);
void preprocessor_set_warning_with_token(enum warning w, struct preprocessor_ctx* ctx, const struct token* p_token, const char* fmt, ...);
void preprocessor_set_error_with_token(enum error error, struct preprocessor_ctx* ctx, const struct token* p_token, const char* fmt, ...);


struct tokenizer_ctx
{
    struct options options;
    int n_warnings;
    int n_errors;    
};

struct token_list tokenizer(struct tokenizer_ctx* ctx, const char* text, const char* filename_opt, int level, enum token_flags addflags);
void add_standard_macros(struct preprocessor_ctx* ctx);
struct include_dir* include_dir_add(struct include_dir_list* list, const char* path);

struct token_list preprocessor(struct preprocessor_ctx* ctx, struct token_list* input_list, int level);
struct token_list  copy_replacement_list(struct token_list* list);

void token_list_append_list(struct token_list* dest, struct token_list* obj_owner source);
void print_list(struct token_list* list);
void token_list_destroy( struct token_list* obj_owner list);
bool token_is_blank(struct token* p);
void token_list_pop_back(struct token_list* list);
void token_list_pop_front(struct token_list* list);
struct token* owner token_list_pop_front_get(struct token_list* list);
void remove_line_continuation(char* s);
struct token* token_list_clone_and_add(struct token_list* list, struct token* pnew);

void token_list_insert_after(struct token_list* list, struct token* after, struct token_list* append);
struct token_list tokenizer(struct tokenizer_ctx* p, const char* text, const char* filename_opt, int level, enum token_flags addflags);

const char* owner get_code_as_we_see(struct token_list* list, bool remove_comments);
const char* owner get_code_as_compiler_see(struct token_list* list);

const char* owner get_code_as_we_see_plus_macros(struct token_list* list);
const char* owner get_code_as_we_see(struct token_list* list, bool remove_comments);

void print_tokens(struct token* p_token);
void print_preprocessed(struct token* p_token);
const char* owner print_preprocessed_to_string(struct token* p_token);
const char* owner print_preprocessed_to_string2(struct token* p_token);
void check_unused_macros(struct owner_hash_map* map);

char* owner read_file(const char* path);
const char* get_token_name(enum token_type tk);
void print_all_macros(struct preprocessor_ctx* prectx);

int string_literal_byte_size(const char* s);
int get_char_type(const char* s);
void include_config_header(struct preprocessor_ctx* ctx);

#ifdef _WIN32


#include <Windows.h>
#endif

#if defined _MSC_VER && !defined __POCC__


#include <crtdbg.h>
#endif

#if defined _MSC_VER && !defined __POCC__


#include <debugapi.h>
#endif

bool style_has_space(const struct token* token)
{
    return token_is_blank(token->prev);
}

bool style_has_one_space(const struct token* token)
{
    return token->prev &&
        token->prev->type == TK_BLANKS;
}

void print_literal2(const char* s);

void token_list_clear(struct token_list* list)
{
    struct token* owner p = list->head;
    while (p)
    {
        struct token* owner next = p->next;
        p->next = NULL;
        token_delete(p);
        p = next;
    }

    list->head = NULL;
    list->tail = NULL;
}


void token_range_add_show(struct token* first, struct token* last)
{
    for (struct token* current = first;
        current != last->next;
        current = current->next)
    {
        current->flags = current->flags & ~TK_FLAG_HIDE;
    }
}

void token_range_remove_flag(struct token* first, struct token* last, enum token_flags flag)
{
    for (struct token* current = first;
        current != last->next;
        current = current->next)
    {
        current->flags = current->flags & ~flag;
    }
}

void token_range_add_flag(struct token* first, struct token* last, enum token_flags flag)
{
    for (struct token* current = first;
        current != last->next;
        current = current->next)
    {
        current->flags |= flag;
    }
}

void token_list_pop_back(struct token_list* list) unchecked
{
    if (list->head == NULL)
        return ;

    struct token* p = list->tail;
    if (list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        if (list->tail == list->head)
        {
            list->tail->prev = NULL;
        }
    }
    p->next = NULL;
    p->prev = NULL;
    p->next = NULL;
    token_delete(p);    
}

void token_list_pop_front(struct token_list* list) unchecked
{
    if (list->head == NULL)
        return;

    struct token* owner p = list->head;

    if (list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->head = list->head->next;
    }
    p->next = NULL;
    p->prev = NULL;    
    token_delete(p);
}

struct token* owner token_list_pop_front_get(struct token_list* list)  unchecked
{
    if (list->head == NULL)
        return NULL;

    struct token* p = list->head;

    if (list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->head = list->head->next;
    }
    p->next = NULL;
    p->prev = NULL;

    return p;
}

void token_list_swap(struct token_list*  a, struct token_list* b)
{
    struct token_list temp = *a;
    *a = *b;
    *b = temp;
}

void token_delete(struct token* owner p)
{
    if (p)
    {
        /*
         * ownership warning here is about the p->next
         * we need a way to remove only this especific warning
        */
        assert(p->next == NULL);
        free(p->lexeme);
        free(p);
    }
}

void token_list_set_file(struct token_list* list, struct token* filetoken, int line, int col)
{
    //assert(filetoken != NULL);
    struct token* p = list->head;
    while (p)
    {
        p->token_origin = filetoken;
        p->line = line;
        p->col = col;
        p = p->next;
    }
}

void token_list_destroy(struct token_list* obj_owner list)
{
    struct token* owner p = list->head;
    while (p)
    {
        struct token* owner next = p->next;
        p->next = NULL;
        token_delete(p);
        p = next;
    }
}

char* owner token_list_join_tokens(struct token_list* list, bool bliteral)
{
    struct osstream ss = {0};
    if (bliteral)
        ss_fprintf(&ss, "\"");
    bool has_space = false;
    struct token* current = list->head;

    while (current)
    {
        if (token_is_blank(current))
        {
            has_space = true;
            current = current->next;
            continue;
        }

        if (has_space)
            ss_fprintf(&ss, " ");

        const char* p = current->lexeme;
        while (*p)
        {
            if (*p == '"')
                ss_fprintf(&ss, "\\\"");
            else
                ss_fprintf(&ss, "%c", *p);
            p++;
        }


        current = current->next;
        if (current)
            has_space = current->flags & TK_FLAG_HAS_SPACE_BEFORE;
    }

    if (bliteral)
        ss_fprintf(&ss, "\"");

    char* owner cstr = ss.c_str;
    ss.c_str = NULL; /*MOVED*/

    ss_close(&ss);

    return cstr;
}

void token_list_insert_after(struct token_list* token_list, struct token* after, struct token_list* append_list) 
{
    if (append_list->head == NULL)
        return;

    if (after == NULL)
    {
        assert(append_list->tail->next == NULL);
        append_list->tail->next = token_list->head;
        token_list->head->prev = append_list->tail;

        token_list->head = append_list->head;
        append_list->head->prev = NULL;
    }
    else
    {
        struct token* owner follow = after->next;
        if (token_list->tail == after)
        {
            token_list->tail = append_list->tail;
        }
        else if (token_list->head == after)
        {
        }
        assert(append_list->tail->next == NULL);
        append_list->tail->next = follow;
        follow->prev = append_list->tail;
        after->next = append_list->head;
        append_list->head->prev = after;

    }

    append_list->head = NULL;
    append_list->tail = NULL;

}

struct token* token_list_add(struct token_list* list, struct token* owner pnew) unchecked
{
    /*evitar que sem querer esteja em 2 listas diferentes*/
    assert(pnew->next == NULL);
    assert(pnew->prev == NULL);
    //assert(pnew->token_origin);

    if (list->head == NULL)
    {
        pnew->prev = NULL;
        pnew->next = NULL;
        list->head = pnew;
        list->tail = pnew;
        //pnew->prev = list->tail;
    }
    else
    {
        pnew->prev = list->tail;
        list->tail->next = pnew;
        list->tail = pnew;
    }
    assert(list->tail->next == NULL);
    return list->tail;

}

int is_digit(struct stream* p)
{
    /*
     digit : one of
     0 1 2 3 4 5 6 7 8 9
    */
    return (p->current[0] >= '0' && p->current[0] <= '9');
}

bool token_is_blank(struct token* p)
{
    return p->type == TK_BEGIN_OF_FILE ||
        p->type == TK_BLANKS ||
        p->type == TK_LINE_COMMENT ||
        p->type == TK_COMMENT;
}

struct token* token_list_clone_and_add(struct token_list* list, struct token* pnew)
{
    struct token* owner clone = clone_token(pnew);
    return token_list_add(list, clone);
}

void token_list_append_list_at_beginning(struct token_list* dest, struct token_list* source)
{
    if (source->head == NULL)
    {
        return;
    }
    if (dest->head == NULL)
    {
        dest->head = source->head;
        dest->tail = source->tail;
    }
    else
    {
        assert(source->tail->next == NULL);
        source->tail->next = dest->head;
        dest->head = source->head;
    }

    source->head = NULL;
    source->tail = NULL;
}

void token_list_append_list(struct token_list* dest, struct token_list* source) 
{
    if (source->head == NULL)
    {
        return;
    }
    if (dest->head == NULL)
    {
        dest->head = source->head;
        dest->tail = source->tail;
    }
    else
    {
        assert(dest->tail->next == NULL);
        dest->tail->next = source->head;
        source->head->prev = dest->tail;
        dest->tail = source->tail;
    }
    source->head = NULL;
    source->tail = NULL;
}


struct token* owner clone_token(struct token* p) unchecked
{
    struct token* owner token = calloc(1, sizeof * token);
    if (token)
    {
        *token = *p;        
        token->lexeme = strdup(p->lexeme);
        token->next = NULL;
        token->prev = NULL;
    }
    return token;
}

struct token_list token_list_remove_get(struct token_list* list, struct token* first, struct token* last) unchecked
{

    struct token_list r = {0};

    struct token* before_first = first->prev;
    struct token* owner after_last = last->next;

    before_first->next = after_last;
    after_last->prev = before_first;

    r.head = (struct token* owner)first;
    first->prev = NULL;
    r.tail = last;
    last->next = NULL;


    return r;
}


void token_list_remove(struct token_list* list, struct token* first, struct token* last)
{
    struct token_list r = token_list_remove_get(list, first, last);
    token_list_destroy(&r);
}


bool token_list_is_empty(struct token_list* p)
{
    assert((p->head == NULL && p->tail == NULL) ||
        (p->head != NULL && p->tail != NULL));

    return p->head == NULL;
}



void print_list(struct token_list* list)
{
    struct token* current = list->head;
    while (current)
    {
        if (current != list->head)
        {
            printf(u8"˰");
            //printf("`");
        }
        print_literal2(current->lexeme);
        printf(RESET);
        if (current == list->tail)
        {
            //printf("`");
        }
        current = current->next;
    }
    printf(u8"\n");
}

void print_literal2(const char* s)
{
    if (s == NULL)
    {
        //printf("`");
        //printf("`");
        return;
    }
    //printf("`");
    while (*s)
    {
        switch (*s)
        {
            case '\n':
                printf("\\n");
                break;
            default:
                printf("%c", *s);
        }
        s++;
    }
    //printf("`");
}


void print_token(struct token* p_token)
{
    for (int i = 0; i < p_token->level; i++)
    {
        printf("  ");
    }
    if (p_token->flags & TK_FLAG_FINAL)
        printf(LIGHTGREEN);
    else
        printf(LIGHTGRAY);
    char buffer0[50] = {0};
    snprintf(buffer0, sizeof buffer0, "%d:%d", p_token->line, p_token->col);
    printf("%-6s ", buffer0);
    printf("%-20s ", get_token_name(p_token->type));
    if (p_token->flags & TK_FLAG_MACRO_EXPANDED)
    {
        printf(LIGHTCYAN);
    }
    char buffer[50] = {0};
    strcat(buffer, "[");
    if (p_token->flags & TK_FLAG_FINAL)
    {
        strcat(buffer, "final ");
    }
    if (p_token->flags & TK_FLAG_HIDE)
    {
        strcat(buffer, "hide ");
    }
    if (p_token->flags & TK_FLAG_MACRO_EXPANDED)
    {
        strcat(buffer, "expanded ");
    }
    if (p_token->flags & TK_FLAG_HAS_SPACE_BEFORE)
    {
        strcat(buffer, "space ");
    }
    if (p_token->flags & TK_FLAG_HAS_NEWLINE_BEFORE)
    {
        strcat(buffer, "newline ");
    }
    strcat(buffer, "]");
    printf("%-20s ", buffer);
    print_literal2(p_token->lexeme);
    printf("\n");
    printf(RESET);
}

void print_tokens(struct token* p_token)
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" RESET);
    struct token* current = p_token;
    while (current)
    {
        print_token(current);
        current = current->next;
    }
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" RESET);
    printf(RESET);
}


void print_token_html(struct token* p_token)
{
    printf("<span class=\"");


    if (!(p_token->flags & TK_FLAG_FINAL))
    {
        printf("notfinal ");
    }

    if (p_token->flags & TK_FLAG_FINAL)
    {
        printf("final ");
    }
    if (p_token->flags & TK_FLAG_HIDE)
    {
        printf("hide ");
    }
    if (p_token->flags & TK_FLAG_MACRO_EXPANDED)
    {
        printf("expanded ");
    }
    if (p_token->flags & TK_FLAG_HAS_SPACE_BEFORE)
    {
        printf("space ");
    }
    if (p_token->flags & TK_FLAG_HAS_NEWLINE_BEFORE)
    {
        printf("newline ");
    }

    printf("\">");

    print_literal2(p_token->lexeme);

    printf("</span>");

    if (p_token->type == TK_NEWLINE || p_token->type == TK_BEGIN_OF_FILE)
    {
        printf("<br>\n");
    }
}

/*
 CSS for html ouput

 <style>
        .final {
          color:blue;
        }

        .notfinal {
          color:gray;
        }

        .hide {
          text-decoration: line-through;
          color:red;
        }

        .expanded {
           background-color:yellow;
        }

        span {
            border-style: solid;
            border-color: gray;
            border-width: 1px 1px;
            padding:1px;
            margin:2px;
        }

</style>

*/
void print_tokens_html(struct token* p_token)
{
    printf("<pre>\n");
    struct token* current = p_token;
    while (current)
    {
        print_token_html(current);
        current = current->next;
    }
    printf("\n</pre>");
}

void print_position(const char* path, int line, int col, bool visual_studio_ouput_format)
{

    if (visual_studio_ouput_format)
    {
        //MSVC format
        printf("%s(%d,%d): ", path ? path : "<>", line, col);
    }
    else
    {
        //GCC format
        printf(WHITE "%s:%d:%d: ", path ? path : "<>", line, col);
    }
}

void print_line_and_token(const struct token* p_token, bool visual_studio_ouput_format)
{
    if (p_token == NULL)
        return;

    int line = p_token->line;

    if (!visual_studio_ouput_format)
        printf(LIGHTGRAY);

    char nbuffer[20] = {0};
    int n = snprintf(nbuffer, sizeof nbuffer, "%d", line);
    printf(" %s |", nbuffer);

    int offset = 0;
    bool stop_offset = false;

    const struct token* prev = p_token;
    while (prev && prev->prev && (prev->prev->type != TK_NEWLINE && prev->prev->type != TK_BEGIN_OF_FILE))
    {
        prev = prev->prev;
    }
    const struct token* next = prev;
    while (next && (next->type != TK_NEWLINE && next->type != TK_BEGIN_OF_FILE))
    {
        if (p_token == next)
            stop_offset = true;

        if (next->flags & TK_FLAG_MACRO_EXPANDED)
        {
            if (next->flags & TK_FLAG_HAS_SPACE_BEFORE)
            {
                if (!stop_offset) offset++;
                printf(" ");
            }
        }
        if (next->flags & TK_FLAG_MACRO_EXPANDED)
        {
            if (!stop_offset)
                offset += strlen(next->lexeme);

            if (!visual_studio_ouput_format)
                printf(DARKGRAY "%s" RESET, next->lexeme);
            else
                printf("%s", next->lexeme);

        }
        else
            printf("%s", next->lexeme);

        next = next->next;
    }
    printf("\n");

    if (!visual_studio_ouput_format)
        printf(LIGHTGRAY);

    printf(" %*s |", n, " ");
    if (p_token)
    {
        for (int i = 1; i <= (p_token->col - 1) + offset; i++)
        {
            printf(" ");
        }
    }

    if (!visual_studio_ouput_format)
        printf(LIGHTGREEN);

    printf("^");

    char* p = p_token->lexeme + 1;
    while (p && *p)
    {
        printf("~");
        p++;
    }

    if (!visual_studio_ouput_format)
        printf(RESET);

    printf("\n");
}





//#pragma once

unsigned int string_hash(const char* key);


unsigned int string_hash(const char* key)
{
    // hash key to unsigned int value by pseudorandomizing transform
    // (algorithm copied from STL char hash in xfunctional)
    unsigned int hash_val = 2166136261U;
    unsigned int first = 0;
    unsigned int last = (unsigned int)strlen(key);
    unsigned int stride = 1 + last / 10;

    for (; first < last; first += stride)
    {
        hash_val = 16777619U * hash_val ^ (unsigned int)key[first];
    }

    return (hash_val);
}


#ifdef _WIN32
#endif

#if defined _MSC_VER
#endif


void hashmap_remove_all(struct hash_map* map)
{
 
    if (map->table != NULL)
    {
        for (int i = 0; i < map->capacity; i++)
        {
            struct map_entry* owner pentry = map->table[i];

            while (pentry != NULL)
            {
                struct map_entry* owner next = pentry->next;                
                free(pentry->key);
                free(pentry);
                pentry = next;
            }
        }
 
        free(map->table);
        map->table = NULL;
        map->size = 0;
    }
}

void hashmap_destroy( struct hash_map* obj_owner map)
{
    hashmap_remove_all(map);
    assert(map->table == NULL);
}

struct map_entry* hashmap_find(struct hash_map* map, const char* key)
{
    if (map->table == NULL)
      return NULL;

    const unsigned int hash = string_hash(key);
    const int index = hash % map->capacity;

    struct map_entry* pentry = map->table[index];

    for (; pentry != NULL; pentry = pentry->next)
    {
        if (pentry->hash == hash && strcmp(pentry->key, key) == 0)
        {
            return pentry;
        }
    }

    return NULL;
}


void * view hashmap_remove(struct hash_map* map, const char* key, enum tag * p_type_opt)
{
    if (map->table != NULL)
    {
        const unsigned int hash = string_hash(key);
        struct map_entry* * pp_entry = &map->table[hash % map->capacity];
        struct map_entry* p_entry = *pp_entry;

        for (; p_entry != NULL; p_entry = p_entry->next)
        {
            if ((p_entry->hash == hash) && (strcmp(p_entry->key, key) == 0))
            {
                *pp_entry = p_entry->next;

                if (p_type_opt)
                    *p_type_opt = p_entry->type;

                void* view p = p_entry->p;
                free((void* owner)p_entry->key);
                free((void* owner)p_entry);
                
                return p;
            }
            pp_entry = &p_entry->next;
        }
    }

    return NULL;
}


int hashmap_set(struct hash_map* map, const char* key, const void* view p, enum tag type)
{
    int result = 0;

    if (map->table == NULL)
    {
        if (map->capacity < 1)
        {
            map->capacity = 1000;
        }

        map->table = calloc(map->capacity, sizeof(map->table[0]));
    }

    if (map->table != NULL)
    {
        unsigned int hash = string_hash(key);
        int index = hash % map->capacity;

        struct map_entry* pentry = map->table[index];

        for (; pentry != NULL; pentry = pentry->next)
        {
            if (pentry->hash == hash && strcmp(pentry->key, key) == 0)
            {
                break;
            }
        }

        if (pentry == NULL)
        {
            struct map_entry* owner p_new_entry = calloc(1, sizeof(*pentry));
            p_new_entry->hash = hash;
            p_new_entry->p = (void*) p;
            p_new_entry->type = type;
            p_new_entry->key = strdup(key);
            p_new_entry->next = map->table[index];
            map->table[index] = p_new_entry;
            map->size++;
            result = 0;
        }
        else
        {
            result = 1;            
            pentry->p = (void*) p;
            pentry->type = type;
        }
    }

    return result;
}


/////////////



void owner_hashmap_remove_all(struct owner_hash_map* map, void (*pf)(void* owner))
{
    if (map->table != NULL)
    {
        for (int i = 0; i < map->capacity; i++)
        {
            struct owner_map_entry* owner pentry = map->table[i];

            while (pentry != NULL)
            {
                struct owner_map_entry* owner next = pentry->next;                
                
                pf(pentry->p); //TODO

                free(pentry->key);
                free(pentry);

                pentry = next;
            }
        }

        free(map->table);
        map->table = NULL;
        map->size = 0;
    }
}

void owner_hashmap_destroy( struct owner_hash_map* obj_owner map, void (*pf)(void* owner))
{
    owner_hashmap_remove_all(map, pf );
    assert(map->table == NULL);
}

struct owner_map_entry* owner_hashmap_find(struct owner_hash_map* map, const char* key)
{
    if (map->table == NULL)
      return NULL;

    const unsigned int hash = string_hash(key);
    const int index = hash % map->capacity;

    struct owner_map_entry* pentry = map->table[index];

    for (; pentry != NULL; pentry = pentry->next)
    {
        if (pentry->hash == hash && strcmp(pentry->key, key) == 0)
        {
            return pentry;
        }
    }

    return NULL;
}


void * owner owner_hashmap_remove(struct owner_hash_map* map, const char* key, enum tag * p_type_opt)
{
    if (map->table != NULL)
    {
        const unsigned int hash = string_hash(key);
        struct owner_map_entry* * pp_entry = &map->table[hash % map->capacity];
        struct owner_map_entry* p_entry = *pp_entry;

        for (; p_entry != NULL; p_entry = p_entry->next)
        {
            if ((p_entry->hash == hash) && (strcmp(p_entry->key, key) == 0))
            {
                *pp_entry = p_entry->next;

                if (p_type_opt)
                    *p_type_opt = p_entry->type;

                void* owner p = p_entry->p;
                free(p_entry->key);
                free((void  * owner)p_entry);
                
                return p;
            }
            pp_entry = &p_entry->next;
        }
    }

    return NULL;
}


void* owner owner_hashmap_set(struct owner_hash_map* map, const char* key, const void* owner p, enum tag type)
{
    void* owner previous = NULL;

    if (map->table == NULL)
    {
        if (map->capacity < 1)
        {
            map->capacity = 1000;
        }

        map->table = calloc(map->capacity, sizeof(map->table[0]));
    }

    if (map->table != NULL)
    {
        unsigned int hash = string_hash(key);
        int index = hash % map->capacity;

        struct owner_map_entry* pentry = map->table[index];

        for (; pentry != NULL; pentry = pentry->next)
        {
            if (pentry->hash == hash && strcmp(pentry->key, key) == 0)
            {
                break;
            }
        }

        if (pentry == NULL)
        {
            struct owner_map_entry* owner p_new_entry = calloc(1, sizeof(*pentry));
            p_new_entry->hash = hash;
            p_new_entry->p = (void * owner)p;
            p_new_entry->type = type;
            p_new_entry->key = strdup(key);
            p_new_entry->next = map->table[index];
            map->table[index] = p_new_entry;
            map->size++;            
        }
        else
        {            
            previous = pentry->p;
            pentry->p = (void * owner) p;
            pentry->type = type;
        }
    }
    else
    {
        static_set(p, "moved"); //this is a leak actually
    }
    return previous;
}




#ifdef _WIN32
#else


#include <termios.h>


#include <unistd.h>


#include <fcntl.h>


#include <sys/ioctl.h>
#endif

#ifndef WIN32

bool enable_vt_mode(void)
{
    return true;
}

int c_kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

/* Read 1 character without echo */
int c_getch(void)
{
    struct termios old, new;
    int ch;

    tcgetattr(0, &old);

    new = old;
    new.c_lflag &= ~ICANON;
    new.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &new);

    ch = getchar();

    tcsetattr(0, TCSANOW, &old);

    return ch;
}

#else

bool enable_vt_mode(void)
{
//missing in mingw (installed with codeblocs)
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING  
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
#endif

    DWORD mode = 0;
    HANDLE h_out = GetStdHandle(STD_OUTPUT_HANDLE);
    if ((h_out = GetStdHandle(STD_OUTPUT_HANDLE)) != INVALID_HANDLE_VALUE &&
            GetConsoleMode(h_out, &mode) != 0 &&
            SetConsoleMode(h_out, mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING) != 0 &&
            SetConsoleOutputCP(CP_UTF8) != 0)
    {
        return true;//ok
    }
    return false;//error
}

int c_kbhit(void)
{
    return _kbhit();
}
int c_getch(void)
{
    return _getch();
}

#endif

void c_clrscr()
{
    puts("\x1b[2J\x1b[1;1H");
    fflush(stdout);
}



/*

   1 - The initial input is a string.
   2 - This string is transformed into a linked list of tokens

   ┌───┐   ┌───┐   ┌───┐   ┌───┐
   │   ├──►│   ├──►│   ├──►│   │──► NULL
   └───┘   └───┘   └───┘   └───┘

   The list is then expanded using includes and macros through a preprocessor.


   ┌───┐                  ┌───┐   ┌───┐   ┌───┐
   │   ├──────┐           │   ├──►│x  ├──►│x  │ ──► NULL   Level 0
   └───┘      │           └───┘   └───┘   └───┘
			┌─▼─┐   ┌───┐   ▲
			│   ├───┤   ├───┘  (includes)                  Level 1
			└───┘   └───┘


	Each item in the list has additional properties:

	level         :  An integer indicating the level of inclusion.

	bmacroexpanded: A boolean indicating whether the token was generated
					from macro expansion.

	bfinal        : A boolean indicating whether the token is the
					final, the one seen by the parser.

*/



#include <ctype.h>


#include <sys/stat.h>


#include <errno.h>


#include <stddef.h>


#include <time.h>


//#pragma once


#ifdef _WIN32 


#include <direct.h>


#include <sys/types.h>

#ifdef __CAKE__
#pragma CAKE diagnostic push
#pragma CAKE diagnostic ignore "-Wstyle"
#endif


//https://docs.microsoft.com/pt-br/cpp/c-runtime-library/reference/mkdir-wmkdir?view=msvc-160
#define mkdir(a, b) _mkdir(a)
#define rmdir _rmdir
#define chdir _chdir


#ifdef __CAKE__
#pragma CAKE diagnostic pop
#endif


/*
 opendir,  readdir closedir for windows.
 include dirent.h on linux
*/



enum
{
    DT_UNKNOWN = 0,
    DT_FIFO = 1,
    DT_CHR = 2,
    DT_DIR = 4,
    DT_BLK = 6,
    DT_REG = 8,
    DT_LNK = 10,
    DT_SOCK = 12,
    DT_WHT = 14
};

struct dirent
{
    ino_t d_ino;             /* Inode number */
    off_t d_off;             /* Not an offset; see below */
    unsigned short d_reclen; /* Length of this record */
    unsigned char d_type;    /* Type of file; not supported
                                     by all filesystem types*/
    char d_name[256];        /* Null-terminated filename */
};

#ifdef __CAKE__
#pragma CAKE diagnostic push
#pragma CAKE diagnostic ignore "-Wstyle"
#endif
struct TAGDIR;
typedef struct TAGDIR DIR;

#ifdef __CAKE__
#pragma CAKE diagnostic pop
#endif

DIR* owner opendir(const char* name);
int closedir(DIR* owner dirp);
struct dirent* readdir(DIR* dirp);


#else

typedef struct __dirstream DIR;
DIR * owner opendir (const char *__name);


#define MAX_PATH 500

//https://man7.org/linux/man-pages/man2/mkdir.2.html


#include <dirent.h>
#endif



char* realpath(const char* restrict path, char* restrict resolved_path);

int get_self_path(char* buffer, int maxsize);

char* owner read_file(const char* path);
char* dirname(char* path);

const char* get_posix_error_message(int error);


bool path_is_relative(const char* path);
bool path_is_absolute(const char* path);



//#pragma once

struct preprocessor_ctx;

int pre_constant_expression(struct preprocessor_ctx* ctx, long long* pvalue);



#ifdef _WIN32
#endif

#if defined _MSC_VER && !defined __POCC__
#endif

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

/*
 Se for 1 inclui todos os ignorados de dentro dos includes
 se for 0 ele faz so resumido e desctart oq nao eh usado.
*/
#define INCLUDE_ALL 1

///////////////////////////////////////////////////////////////////////////////
void naming_convention_macro(struct preprocessor_ctx* ctx, struct token* token);
///////////////////////////////////////////////////////////////////////////////

static bool preprocessor_is_warning_enabled(const struct preprocessor_ctx* ctx, enum warning w)
{
	return
		(ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index] & w) != 0;
}

struct macro_parameter
{
	const char* owner name;
	struct macro_parameter* owner next;
};



struct macro
{
	const char* owner name;
	struct token_list replacement_list; /*copia*/
	struct macro_parameter* owner parameters;
	bool is_function;
	int usage;

	bool expand;
};


void delete_macro(struct macro* owner macro);

static void delete_macro_void(void* owner p)
{
	struct macro* owner p_macro = p;
	delete_macro(p_macro);
}

void include_dir_list_destroy(struct include_dir_list* obj_owner list)
{
	struct include_dir* owner p = list->head;
	while (p)
	{
		struct include_dir* owner next = p->next;
		free((void* owner)p->path);
		free(p);
		p = next;
	}
}

void preprocessor_ctx_destroy(struct preprocessor_ctx* obj_owner p)
{
	owner_hashmap_destroy(&p->macros, delete_macro_void);
	include_dir_list_destroy(&p->include_dir);
	hashmap_destroy(&p->pragma_once_map);
	token_list_destroy(&p->input_list);
}

struct token_list preprocessor(struct preprocessor_ctx* ctx, struct token_list* input_list, int level);

static void tokenizer_set_error(struct tokenizer_ctx* ctx, struct stream* stream, const char* fmt, ...)
{
	ctx->n_errors++;
#ifndef TEST
	char buffer[200] = { 0 };
	va_list args;
	va_start(args, fmt);
	/*int n =*/ vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	print_position(stream->path, stream->line, stream->col, ctx->options.visual_studio_ouput_format);
	if (ctx->options.visual_studio_ouput_format)
	{
		printf("error: "  "%s\n", buffer);
	}
	else
	{
		printf(LIGHTRED "error: " WHITE "%s\n", buffer);
	}
#endif
}


static void tokenizer_set_warning(struct tokenizer_ctx* ctx, struct stream* stream, const char* fmt, ...)
{
	ctx->n_warnings++;

#ifndef TEST
	char buffer[200] = { 0 };
	va_list args;
	va_start(args, fmt);
	/*int n =*/ vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);
	print_position(stream->path, stream->line, stream->col, ctx->options.visual_studio_ouput_format);
	if (ctx->options.visual_studio_ouput_format)
	{
		printf("warning: " "%s\n", buffer);
	}
	else
	{
		printf(LIGHTMAGENTA "warning: " WHITE "%s\n", buffer);
	}
#endif
}

void preprocessor_set_info_with_token(struct preprocessor_ctx* ctx, const struct token* p_token, const char* fmt, ...)
{
#ifndef TEST
	if (p_token)
		print_position(p_token->token_origin->lexeme, p_token->line, p_token->col, ctx->options.visual_studio_ouput_format);

	char buffer[200] = { 0 };
	va_list args;
	va_start(args, fmt);
	/*int n =*/ vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	if (ctx->options.visual_studio_ouput_format)
	{
		printf("note: " "%s\n", buffer);
	}
	else 
	{
		printf(LIGHTCYAN "note: " WHITE "%s\n", buffer);
	}
	print_line_and_token(p_token, ctx->options.visual_studio_ouput_format);
#endif

}

void preprocessor_set_warning_with_token(enum warning w, struct preprocessor_ctx* ctx, const struct token* p_token, const char* fmt, ...)
{
	if (w != W_NONE)
	{
		/*
		 we dont warn ing code inside includes, except #warning (w == 0)
		*/
		if (p_token->level != 0)
			return;

		if (!preprocessor_is_warning_enabled(ctx, w))
		{
			return;
		}
	}

	ctx->n_warnings++;
#ifndef TEST

	if (p_token)
		print_position(p_token->token_origin->lexeme, p_token->line, p_token->col, ctx->options.visual_studio_ouput_format);

	char buffer[200] = { 0 };
	va_list args;
	va_start(args, fmt);
	/*int n =*/ vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	if (ctx->options.visual_studio_ouput_format)
	{
		printf("warning: " "%s\n", buffer);
		print_line_and_token(p_token, ctx->options.visual_studio_ouput_format);
	}
	else
	{
		printf(LIGHTMAGENTA "warning: " WHITE "%s\n", buffer);
		print_line_and_token(p_token, ctx->options.visual_studio_ouput_format);

	}
#endif

}

void preprocessor_set_error_with_token(enum error error, struct preprocessor_ctx* ctx, const struct token* p_token, const char* fmt, ...)
{
	ctx->n_errors++;

#ifndef TEST

	if (p_token)
		print_position(p_token->token_origin->lexeme, p_token->line, p_token->col, ctx->options.visual_studio_ouput_format);

	char buffer[200] = { 0 };
	va_list args;
	va_start(args, fmt);
	/*int n =*/ vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	if (ctx->options.visual_studio_ouput_format)
	{
		printf("error: " "%s\n", buffer);
	}
	else
	{
		printf(LIGHTRED"error: " WHITE "%s\n", buffer);
	}

	print_line_and_token(p_token, ctx->options.visual_studio_ouput_format);
#endif
}




struct include_dir* include_dir_add(struct include_dir_list* list, const char* path)
{
	struct include_dir* owner p_new_include_dir = calloc(1, sizeof * p_new_include_dir);
	p_new_include_dir->path = strdup(path);
	if (list->head == NULL)
	{
		list->head = p_new_include_dir;
		list->tail = p_new_include_dir;
	}
	else
	{
		assert(list->tail->next == NULL);
		list->tail->next = p_new_include_dir;
		list->tail = p_new_include_dir;
	}
	return list->tail;
}


const char* owner find_and_read_include_file(struct preprocessor_ctx* ctx,
	const char* path, /*as in include*/
	const char* current_file_dir, /*this is the dir of the file that includes*/
	bool* p_already_included, /*out file alread included pragma once*/
	char full_path_out[], /*this is the final full path of the file*/
	int full_path_out_size)
{

	full_path_out[0] = '\0';

	if (path_is_absolute(path))
	{
		//todo realpath
		if (hashmap_find(&ctx->pragma_once_map, path) != NULL)
		{
			*p_already_included = true;
			return NULL;
		}

		char* owner content = read_file(path);
		if (content != NULL)
		{
			snprintf(full_path_out, full_path_out_size, "%s", path);
			return content;
		}
		return NULL;
	}



	char newpath[200] = { 0 };
	snprintf(newpath, sizeof newpath, "%s/%s", current_file_dir, path);

#ifdef __EMSCRIPTEN__
	/*realpath returns empty on emscriptem*/
	snprintf(full_path_out, full_path_out_size, "%s", newpath);
#else
	realpath(newpath, full_path_out);
#endif


	if (hashmap_find(&ctx->pragma_once_map, full_path_out) != NULL)
	{
		*p_already_included = true;
		return NULL;
	}

	char* owner content = read_file(full_path_out);
	if (content != NULL)
		return content;


	struct include_dir* current = ctx->include_dir.head;
	while (current)
	{
		int len = strlen(current->path);
		if (current->path[len - 1] == '/')
		{
			snprintf(full_path_out, full_path_out_size, "%s%s", current->path, path);
		}
		else
		{
			snprintf(full_path_out, full_path_out_size, "%s/%s", current->path, path);
		}

		if (hashmap_find(&ctx->pragma_once_map, full_path_out) != NULL)
		{
			*p_already_included = true;
			return NULL;
		}

		content = read_file(full_path_out);
		if (content != NULL)
		{
			return content;
		}
		current = current->next;
	}
	full_path_out[0] = '\0';
	return NULL;
}





/*usado para verificar recursividade*/
struct macro_expanded
{
	const char* name;
	struct macro_expanded* p_previous;
};


void add_macro(struct preprocessor_ctx* ctx, const char* name)
{
	struct macro* owner macro = calloc(1, sizeof * macro);
	if (macro != NULL)
	{
		macro->name = strdup(name);
		struct macro* owner previous = (struct macro* owner)owner_hashmap_set(&ctx->macros, name, (void* owner) macro, 0);
		if (previous)
		{
			delete_macro(previous);
			previous = NULL;
		}
	}
}

struct macro_argument
{
	const char* owner name;
	struct token_list tokens;
	struct macro_argument* owner next; /*linked list*/
};
void macro_argument_delete(struct macro_argument* owner p);


struct token_list copy_replacement_list(struct token_list* list);

struct token_list copy_argument_list_tokens(struct token_list* list)
{
	//Faz uma copia dos tokens fazendo um trim no iniico e fim
	//qualquer espaco coments etcc vira um unico  espaco
	struct token_list r = { 0 };
	struct token* current = list->head;
	//sai de cima de todos brancos iniciais
	while (current &&
		(token_is_blank(current) ||
			current->type == TK_NEWLINE))
	{
		current = current->next;
	}
	//remover flag de espaco antes se tiver
	bool is_first = true;

	for (; current;)
	{
		if (current && (token_is_blank(current) ||
			current->type == TK_NEWLINE))
		{
			if (current == list->tail)
				break;

			current = current->next;
			continue;
		}
		struct token* token = token_list_clone_and_add(&r, current);
		if (token->flags & TK_FLAG_HAS_NEWLINE_BEFORE)
		{
			token->flags = token->flags & ~TK_FLAG_HAS_NEWLINE_BEFORE;
			token->flags |= TK_FLAG_HAS_SPACE_BEFORE;
		}
		if (is_first)
		{
			token->flags = token->flags & ~TK_FLAG_HAS_SPACE_BEFORE;
			token->flags = token->flags & ~TK_FLAG_HAS_NEWLINE_BEFORE;
			is_first = false;
		}
		remove_line_continuation(token->lexeme);

		if (current == list->tail)
			break;
		current = current->next;
	}

	return r;
}

void macro_argument_delete(struct macro_argument* owner p)
{
	if (p)
	{
		assert(p->next == NULL);
		token_list_destroy(&p->tokens);
		free((void* owner) p->name);
		free(p);
	}
}

struct token_list copy_argument_list(struct macro_argument* p_macro_argument)
{
	struct token_list list = copy_argument_list_tokens(&p_macro_argument->tokens);
	if (list.head == NULL)
	{
		/*nunca eh vazio..se for ele colocar um TK_PLACEMARKER*/
		struct token* owner p_new_token = calloc(1, sizeof * p_new_token);
		p_new_token->lexeme = strdup("");
		p_new_token->type = TK_PLACEMARKER;
		token_list_add(&list, p_new_token);
	}
	//print_list(&list);
	return list;
}


struct macro_argument_list
{
	struct token_list tokens;
	struct macro_argument* owner head;
	struct macro_argument* tail;
};

void macro_argument_list_destroy(struct macro_argument_list* obj_owner list)
{
	token_list_destroy(&list->tokens);
	struct macro_argument* owner p = list->head;
	while (p)
	{
		struct macro_argument* owner next = p->next;
		p->next = NULL;
		macro_argument_delete(p);
		p = next;
	}
}

void print_macro_arguments(struct macro_argument_list* arguments)
{
	struct macro_argument* p_argument = arguments->head;
	while (p_argument)
	{
		printf("%s:", p_argument->name);
		print_list(&p_argument->tokens);
		p_argument = p_argument->next;
	}
}

struct macro_argument* find_macro_argument_by_name(struct macro_argument_list* parameters, const char* name)
{
	/*
	* Os argumentos são coletados na expansão da macro e cada um (exceto ...)
	* é associado a um dos parametros da macro.
	*/
	struct macro_argument* p = parameters->head;
	while (p)
	{
		if (strcmp(p->name, name) == 0)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}


void argument_list_add(struct macro_argument_list* list, struct macro_argument* owner pnew)
{
	assert(pnew->next == NULL);
	if (list->head == NULL)
	{
		list->head = pnew;
		assert(list->tail == NULL);
		list->tail = pnew;
	}
	else
	{
		assert(list->tail->next == NULL);
		list->tail->next = pnew;
		list->tail = pnew;
	}
}


void print_macro(struct macro* macro)
{
	printf("%s", macro->name);
	if (macro->is_function)
		printf("(");
	struct macro_parameter* parameter = macro->parameters;
	while (parameter)
	{
		if (macro->parameters != parameter)
			printf(",");
		printf("%s", parameter->name);
		parameter = parameter->next;
	}
	if (macro->is_function)
		printf(") ");
	print_list(&macro->replacement_list);
}

void macro_parameters_delete(struct macro_parameter* owner parameters)
{
	struct macro_parameter* owner p = parameters;
	while (p)
	{
		struct macro_parameter* owner p_next = p->next;
		free((void* owner)p->name);
		free(p);
		p = p_next;
	}
}

void delete_macro(struct macro* owner macro)
{
	if (macro)
	{
		token_list_destroy(&macro->replacement_list);

		struct macro_parameter* owner p_macro_parameter = macro->parameters;
		while (p_macro_parameter)
		{
			struct macro_parameter* owner p_next = p_macro_parameter->next;
			free((void* owner)p_macro_parameter->name);
			free(p_macro_parameter);
			p_macro_parameter = p_next;
		}

		free((void* owner) macro->name);
		free(macro);
	}
}

struct macro* find_macro(struct preprocessor_ctx* ctx, const char* name)
{
	struct owner_map_entry* p_entry = owner_hashmap_find(&ctx->macros, name);
	if (p_entry == NULL)
		return NULL;

	return p_entry->p;
}

void stream_print_line(struct stream* stream)
{
	const char* p = stream->current;
	while ((p - 1) >= stream->source &&
		*(p - 1) != '\n')
	{
		p--;
	}
	while (*p && *(p + 1) != '\n')
	{
		printf("%c", *p);
		p++;
	}
	printf("\n");
	for (int i = 0; i < stream->col - 1; i++)
		printf(" ");
	printf("^\n");
}

void stream_match(struct stream* stream)
{
	if (stream->current[0] == '\n')
	{
		stream->line++;
		stream->col = 1;
	}
	else
	{
		stream->col++;
	}

	if (stream->current[0] == '\0')
		return;
	stream->current++;

	while (stream->current[0] == '\\' && stream->current[1] == '\n')
	{
		/*
			2. Each instance of a backslash character (\) immediately followed by a new-line character is
			deleted, splicing physical source lines to form logical source lines. Only the last backslash on
			any physical source line shall be eligible for being part of such a splice. A source file that is
			not empty shall end in a new-line character, which shall not be immediately preceded by a
			backslash character before any such splicing takes place.
		*/
		stream->current++;
		stream->current++;
		stream->line++;
		stream->col = 1;

		stream->line_continuation_count++;
	}

}

void print_line(struct token* p)
{
	printf("%s\n", p->token_origin->lexeme);
	struct token* prev = p;
	while (prev->prev && prev->prev->type != TK_NEWLINE)
	{
		prev = prev->prev;
	}
	struct token* next = prev;
	while (next && next->type != TK_NEWLINE)
	{
		printf("%s", next->lexeme);
		next = next->next;
	}
	printf("\n");
}

int is_nondigit(struct stream* p)
{
	/*
	nondigit: one of
	 _ a b c d e f g h i j k l m
	 n o p q r s t u v w x y z
	 A B C D E F G H I J K L M
	 N O P Q R S T U V W X Y Z
	*/
	return (p->current[0] >= 'a' && p->current[0] <= 'z') ||
		(p->current[0] >= 'A' && p->current[0] <= 'Z') ||
		(p->current[0] == '_');
}


enum token_type is_punctuator(struct stream* stream)
{
	enum token_type type = TK_NONE;
	/*
	 punctuator: one of
	  [ ] ( ) { } . ->
	  ++ -- & * + - ~ !
	  / % << >> < > <= >= == != ^ | && ||
	  ? : :: ; ...
	  = *= /= %= += -= <<= >>= &= ^= |=
	  , # ##
	  <: :> <% %> %: %:%:
	*/
	switch (stream->current[0])
	{
	case '[':
		type = '[';
		stream_match(stream);
		break;
	case ']':
		type = ']';
		stream_match(stream);
		break;
	case '(':
		type = '(';
		stream_match(stream);
		break;
	case ')':
		type = ')';
		stream_match(stream);
		break;
	case '{':
		type = '{';
		stream_match(stream);
		break;
	case '}':
		type = '}';
		stream_match(stream);
		break;
	case ';':
		type = ';';
		stream_match(stream);
		break;
	case ',':
		type = ',';
		stream_match(stream);
		break;
	case '!':
		type = '!';
		stream_match(stream);
		if (stream->current[0] == '=')
		{
			type = '!=';
			stream_match(stream);
		}
		break;
	case ':':
		type = ':';
		stream_match(stream);
		if (stream->current[0] == ':')
		{
			type = '::';
			stream_match(stream);
		}
		break;
	case '~':
		type = '~';
		stream_match(stream);
		break;
	case '?':
		type = '?';
		stream_match(stream);
		break;
	case '/':
		type = '/';
		stream_match(stream);
		if (stream->current[0] == '=')
		{
			type = '/=';
			stream_match(stream);
		}
		break;
	case '*':
		type = '*';
		stream_match(stream);
		if (stream->current[0] == '=')
		{
			type = '*=';
			stream_match(stream);
		}
		break;
	case '%':
		type = '%';
		stream_match(stream);
		if (stream->current[0] == '=')
		{
			type = '%=';
			stream_match(stream);
		}
		break;
	case '-':
		type = '-';
		stream_match(stream);
		if (stream->current[0] == '>')
		{
			type = '->';
			stream_match(stream);
		}
		else if (stream->current[0] == '-')
		{
			type = '--';
			stream_match(stream);
		}
		else if (stream->current[0] == '=')
		{
			type = '-=';
			stream_match(stream);
		}
		break;
	case '|':
		type = '|';
		stream_match(stream);
		if (stream->current[0] == '|')
		{
			type = '||';
			stream_match(stream);
		}
		else if (stream->current[0] == '=')
		{
			type = '|=';
			stream_match(stream);
		}
		break;
	case '+':
		type = '+';
		stream_match(stream);
		if (stream->current[0] == '+')
		{
			type = '++';
			stream_match(stream);
		}
		else if (stream->current[0] == '=')
		{
			type = '+=';
			stream_match(stream);
		}
		break;
	case '=':
		type = '=';
		stream_match(stream);
		if (stream->current[0] == '=')
		{
			type = '==';
			stream_match(stream);
		}
		break;
	case '^':
		type = '^';
		stream_match(stream);
		if (stream->current[0] == '=')
		{
			type = '^=';
			stream_match(stream);
		}
		break;
	case '&':
		type = '&';
		stream_match(stream);
		if (stream->current[0] == '&')
		{
			type = '&&';
			stream_match(stream);
		}
		else if (stream->current[0] == '=')
		{
			type = '&=';
			stream_match(stream);
		}
		break;
	case '>':
		type = '>';
		stream_match(stream);
		if (stream->current[0] == '>')
		{
			type = '>>';
			stream_match(stream);
			if (stream->current[0] == '=')
			{
				type = '>>=';
				stream_match(stream);
			}
		}
		else if (stream->current[0] == '=')
		{
			type = '>=';
			stream_match(stream);
		}

		break;
	case '<':
		type = '<';
		stream_match(stream);
		if (stream->current[0] == '<')
		{
			type = '<<';
			stream_match(stream);
			if (stream->current[0] == '=')
			{
				type = '<<=';
				stream_match(stream);
			}
		}
		else if (stream->current[0] == '=')
		{
			type = '<=';
			stream_match(stream);
		}
		break;
	case '#':
		type = '#';
		stream_match(stream);
		if (stream->current[0] == '#')
		{
			type = '##';
			stream_match(stream);
		}
		break;
	case '.':
		type = '.';
		stream_match(stream);
		if (stream->current[0] == '.' && stream->current[1] == '.')
		{
			type = '...';
			stream_match(stream);
			stream_match(stream);
		}
		break;
	}
	return type;
}


struct token* owner new_token(const char* lexeme_head, const char* lexeme_tail, enum token_type type)
{
	struct token* owner p_new_token = calloc(1, sizeof * p_new_token);
	size_t sz = lexeme_tail - lexeme_head;
	p_new_token->lexeme = calloc(sz + 1, sizeof(char));
	p_new_token->type = type;
	strncpy(p_new_token->lexeme, lexeme_head, sz);
	return p_new_token;
}

struct token* owner identifier(struct stream* stream)
{
	const char* start = stream->current;
	stream_match(stream);
	/*
	identifier:
	  identifier-nondigit
	  identifier identifier-nondigit
	  identifier digit

	identifier-nondigit:
	  nondigit
	  universal-character-name
	  other implementation-defined characters
	*/
	while (is_nondigit(stream) || is_digit(stream))
	{
		stream_match(stream);
	}

	struct token* owner p_new_token = new_token(start, stream->current, TK_IDENTIFIER);


	return p_new_token;
}




bool first_of_character_constant(struct stream* stream)
{
	return stream->current[0] == '\'' ||
		(stream->current[0] == 'u' && stream->current[1] == '8' && stream->current[2] == '\'') ||
		(stream->current[0] == 'u' && stream->current[1] == '\'') ||
		(stream->current[0] == 'U' && stream->current[1] == '\'') ||
		(stream->current[0] == 'L' && stream->current[1] == '\'');
}

struct token* owner character_constant(struct tokenizer_ctx* ctx, struct stream* stream)
{
	const char* start = stream->current;

	/*
	  encoding-prefix: one of
	   u8 u U L
	*/
	if (stream->current[0] == 'u')
	{
		stream_match(stream);
		if (stream->current[0] == '8')
			stream_match(stream);
	}
	else if (stream->current[0] == 'U' ||
		stream->current[0] == 'L')
	{
		stream_match(stream);
	}


	stream_match(stream); //"


	while (stream->current[0] != '\'')
	{
		if (stream->current[0] == '\\')
		{
			stream_match(stream);
			stream_match(stream);
		}
		else
			stream_match(stream);

		if (stream->current[0] == '\0' ||
			stream->current[0] == '\n')
		{
			tokenizer_set_warning(ctx, stream, "missing terminating ' character");
			break;
		}
	}
	stream_match(stream);
	struct token* owner p_new_token = new_token(start, stream->current, TK_CHAR_CONSTANT);
	return p_new_token;
}

bool first_of_string_literal(struct stream* stream)
{
	/*
	string-literal:
	encoding_prefix_opt " s-char-sequenceopt "

	encoding_prefix:
	u8
	u
	U
	L
	*/

	return stream->current[0] == '"' ||
		(stream->current[0] == 'u' && stream->current[1] == '8' && stream->current[2] == '"') ||
		(stream->current[0] == 'u' && stream->current[1] == '"') ||
		(stream->current[0] == 'U' && stream->current[1] == '"') ||
		(stream->current[0] == 'L' && stream->current[1] == '"');
}

struct token* owner string_literal(struct tokenizer_ctx* ctx, struct stream* stream)
{
	struct token* owner p_new_token = NULL;
	const char* start = stream->current;

	try
	{
		/*encoding_prefix_opt*/
		if (stream->current[0] == 'u')
		{
			stream_match(stream);
			if (stream->current[0] == '8')
				stream_match(stream);
		}
		else if (stream->current[0] == 'U' ||
			stream->current[0] == 'L')
		{
			stream_match(stream);
		}


		stream_match(stream); //"


		while (stream->current[0] != '"')
		{
			if (stream->current[0] == '\0' ||
				stream->current[0] == '\n')
			{
				tokenizer_set_error(ctx, stream, "missing terminating \" character");
				throw;
			}

			if (stream->current[0] == '\\')
			{
				stream_match(stream);
				stream_match(stream);
			}
			else
				stream_match(stream);
		}
		stream_match(stream);
		p_new_token = new_token(start, stream->current, TK_STRING_LITERAL);
	}
	catch
	{
	}

	return p_new_token;
}

int get_char_type(const char* s)
{
	if (s[0] == 'L')
		return 2; /*wchar*/

	return 1;
}

int string_literal_byte_size(const char* s)
{

	struct stream stream = { .source = s,
		.current = s,
		.line = 1,
		.col = 1 };

	int size = 0;
	int charsize = sizeof(char);

	try
	{
		/*encoding_prefix_opt*/
		if (stream.current[0] == 'u')
		{
			stream_match(&stream);
			if (stream.current[0] == '8')
				stream_match(&stream);
		}
		else if (stream.current[0] == 'U' ||
			stream.current[0] == 'L')
		{
			charsize = sizeof(wchar_t);
			stream_match(&stream);
		}


		stream_match(&stream); //"


		while (stream.current[0] != '"')
		{
			if (stream.current[0] == '\0' ||
				stream.current[0] == '\n')
			{
				throw;
			}

			if (stream.current[0] == '\\')
			{
				stream_match(&stream);
				stream_match(&stream);
				size++;
			}
			else
			{
				stream_match(&stream);
				size++;
			}
		}
		stream_match(&stream);
	}
	catch
	{
	}

	size++; /* /0 included */

	return size * charsize;
}

struct token* owner ppnumber(struct stream* stream)
{
	/*
	 pp-number:
	  digit
	  . digit
	  pp-number identifier-continue
	  pp-number ’ digit
	  pp-number ’ nondigit
	  pp-number e sign
	  pp-number E sign
	  pp-number p sign
	  pp-number P sign
	  pp-number .
	*/

	/*
	 identifier-continue:
	   digit
	   nondigit
	   XID_Continue character
	   universal-character-name of class XID_Continue
	*/

	const char* start = stream->current;
	if (is_digit(stream))
	{
		stream_match(stream);//digit
	}
	else if (stream->current[0] == '.')
	{
		stream_match(stream); //.
		stream_match(stream); //digit
	}
	else
	{
		assert(false);
	}

	for (;;)
	{
		if (stream->current[0] == '\'')
		{
			//digit separators c23
			stream_match(stream);
			if (is_digit(stream))
			{
				stream_match(stream);
			}
			else if (is_nondigit(stream))
			{
				stream_match(stream);
			}
			else
			{
				assert(false);
				break;
			}
		}
		else if ((stream->current[0] == 'e' ||
			stream->current[0] == 'E' ||
			stream->current[0] == 'p' ||
			stream->current[0] == 'P') &&
			(stream->current[1] == '+' || stream->current[1] == '-'))
		{
			stream_match(stream);//e E  p P
			stream_match(stream);//sign            
		}
		else if (stream->current[0] == '.')
		{
			stream_match(stream);//.            
		}
		else if (is_digit(stream) || is_nondigit(stream))
		{
			////identifier-continue
			/*
			* OBS test for is_nondigit must be AFTER
			* test for e E p P
			*/
			stream_match(stream);//nondigit
		}
		else
		{
			break;
		}
	}
	struct token* owner p_new_token = new_token(start, stream->current, TK_PPNUMBER);
	return p_new_token;
}

struct token_list embed_tokenizer(struct preprocessor_ctx* ctx, const char* filename_opt, int level, enum token_flags addflags)
{
	struct token_list list = { 0 };

	FILE* owner file = NULL;

	bool b_first = true;
	int line = 1;
	int col = 1;
	int count = 0;
	try
	{
#ifndef MOCKFILES
		file = (FILE * owner)fopen(filename_opt, "rb");
		if (file == NULL)
		{
			preprocessor_set_error_with_token(C_FILE_NOT_FOUND, ctx, ctx->current, "file '%s' not found", filename_opt);
			throw;
		}
#else
		/*web versions only text files that are included*/
		const char* textfile = read_file(filename_opt);
		if (textfile == NULL)
		{
			preprocessor_set_error_with_token(C_FILE_NOT_FOUND, ctx, ctx->current, "file '%s' not found", filename_opt);
			throw;
		}

		const char* pch = textfile;
#endif

		unsigned char ch = 0;
#ifndef MOCKFILES
		while (fread(&ch, 1, 1, file))
		{
#else
		while (*pch)
		{
			ch = *pch;
			pch++;
#endif                    
			if (b_first)
			{
				b_first = false;
			}
			else
			{
				char b[] = ",";
				struct token* owner p_new_token = new_token(b, &b[1], TK_COMMA);
				p_new_token->flags |= addflags;
				p_new_token->level = level;
				p_new_token->token_origin = NULL;
				p_new_token->line = line;
				p_new_token->col = col;
				token_list_add(&list, p_new_token);

				if (count > 0 && count % 25 == 0)
				{
					/*new line*/
					char newline[] = "\n";
					struct token* owner p_new3 = new_token(newline, &newline[1], TK_NEWLINE);
					p_new3->level = level;
					p_new3->token_origin = NULL;
					p_new3->line = line;
					p_new3->col = col;
					token_list_add(&list, p_new3);
				}
			}

			char buffer[30] = { 0 };
			int c = snprintf(buffer, sizeof buffer, "%d", (int)ch);

			struct token* owner p_new_token = new_token(buffer, &buffer[c], TK_PPNUMBER);
			p_new_token->flags |= addflags;
			p_new_token->level = level;
			p_new_token->token_origin = NULL;
			p_new_token->line = line;
			p_new_token->col = col;
			token_list_add(&list, p_new_token);


			count++;
		}
#ifdef MOCKFILES   
		free(textfile);
#endif
	}
	catch
	{
	}

	/*new line*/
	char newline[] = "\n";
	struct token* owner p_new_token = new_token(newline, &newline[1], TK_NEWLINE);
	p_new_token->level = level;
	p_new_token->token_origin = NULL;
	p_new_token->line = line;
	p_new_token->col = col;
	token_list_add(&list, p_new_token);

	if (file) fclose(file);



	assert(list.head != NULL);
	return list;
}

static bool set_sliced_flag(struct stream* stream, struct token* p_new_token)
{
	if (stream->line_continuation_count > 0)
	{
		p_new_token->flags |= TK_FLAG_LINE_CONTINUATION;
		if (stream->line_continuation_count == 1)
		{
			int l = strlen(p_new_token->lexeme);
			if (p_new_token->lexeme[l - 1] == '\n')
			{
				/*not sliced, line continuation is at end of token*/
			}
			else
			{
				p_new_token->flags |= TK_FLAG_SLICED;
			}
		}
		else
		{
			p_new_token->flags |= TK_FLAG_SLICED;
		}
	}

	return p_new_token->flags & TK_FLAG_SLICED;
}

struct token_list tokenizer(struct tokenizer_ctx* ctx, const char* text, const char* filename_opt, int level, enum token_flags addflags)
{
	struct token_list list = { 0 };
	if (text == NULL)
	{
		return list;
	}

	struct stream stream =
	{
		.col = 1,
		.line = 1,
		.source = text,
		.current = text,
		.path = filename_opt ? filename_opt : ""
	};

	try
	{
		struct token* p_first = NULL;
		if (filename_opt != NULL)
		{
			const char* begin = filename_opt;
			const char* end = filename_opt + strlen(filename_opt);
			struct token* owner p_new = new_token(begin, end, TK_BEGIN_OF_FILE);
#ifdef _WINDOWS_
			//windows have case insensive paths
			for (char* p = p_new->lexeme; *p; p++)
			{
				*p = tolower(*p);
			}
#endif
			p_new->level = level;
			p_first = token_list_add(&list, p_new);
		}


		//struct token* current = pFirst;
		bool new_line = true;
		bool has_space = false;
		while (1)
		{
			const int line = stream.line;
			const int col = stream.col;
			stream.line_continuation_count = 0;

			if (stream.current[0] == '\0')
			{
				stream_match(&stream);
				break;
			}
			if (is_digit(&stream) ||
				(stream.current[0] == '.' && isdigit(stream.current[0])))
			{
				struct token* owner p_new_token = ppnumber(&stream);
				p_new_token->flags |= has_space ? TK_FLAG_HAS_SPACE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= new_line ? TK_FLAG_HAS_NEWLINE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= addflags;

				p_new_token->flags |= addflags;

				p_new_token->level = level;
				p_new_token->token_origin = p_first;
				p_new_token->line = line;
				p_new_token->col = col;
				set_sliced_flag(&stream, p_new_token);
				token_list_add(&list, p_new_token);
				new_line = false;
				has_space = false;
				continue;
			}

			/*
			 Tem que vir antes identifier
			*/
			if (first_of_string_literal(&stream))
			{
				struct token* owner p_new_token = string_literal(ctx, &stream);
				if (p_new_token == NULL) throw;

				p_new_token->flags |= has_space ? TK_FLAG_HAS_SPACE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= new_line ? TK_FLAG_HAS_NEWLINE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= addflags;

				p_new_token->flags |= addflags;

				p_new_token->level = level;
				p_new_token->token_origin = p_first;
				p_new_token->line = line;
				p_new_token->col = col;
				set_sliced_flag(&stream, p_new_token);
				token_list_add(&list, p_new_token);
				new_line = false;
				has_space = false;

				continue;
			}

			if (first_of_character_constant(&stream))
			{
				//TODO if we have ' in the middle then it is not character constant
				struct token* owner p_new_token = character_constant(ctx, &stream);
				p_new_token->flags |= has_space ? TK_FLAG_HAS_SPACE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= new_line ? TK_FLAG_HAS_NEWLINE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= addflags;

				p_new_token->level = level;
				p_new_token->token_origin = p_first;
				p_new_token->line = line;
				p_new_token->col = col;
				set_sliced_flag(&stream, p_new_token);
				token_list_add(&list, p_new_token);
				new_line = false;
				has_space = false;

				continue;
			}

			if (is_nondigit(&stream))
			{
				struct token* owner p_new_token = identifier(&stream);
				p_new_token->flags |= has_space ? TK_FLAG_HAS_SPACE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= new_line ? TK_FLAG_HAS_NEWLINE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= addflags;

				p_new_token->level = level;
				p_new_token->token_origin = p_first;
				p_new_token->line = line;
				p_new_token->col = col;

				new_line = false;
				has_space = false;
				if (set_sliced_flag(&stream, p_new_token))
				{
					tokenizer_set_warning(ctx, &stream, "token sliced");
				}
				token_list_add(&list, p_new_token);
				continue;
			}

			if (stream.current[0] == ' ' ||
				stream.current[0] == '\t' ||
				stream.current[0] == '\f')
			{
				const char* start = stream.current;
				while (stream.current[0] == ' ' ||
					stream.current[0] == '\t' ||
					stream.current[0] == '\f'
					)
				{
					stream_match(&stream);
				}
				struct token* owner p_new_token = new_token(start, stream.current, TK_BLANKS);
				p_new_token->flags |= has_space ? TK_FLAG_HAS_SPACE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= new_line ? TK_FLAG_HAS_NEWLINE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= addflags;

				p_new_token->level = level;
				p_new_token->token_origin = p_first;
				p_new_token->line = line;
				p_new_token->col = col;
				set_sliced_flag(&stream, p_new_token);
				token_list_add(&list, p_new_token);
				/*bNewLine = false;*/ //deixa assim
				has_space = true;

				continue;
			}
			if (stream.current[0] == '/' &&
				stream.current[1] == '/')
			{
				const char* start = stream.current;
				stream_match(&stream);
				stream_match(&stream);
				//line comment
				while (stream.current[0] != '\n')
				{
					stream_match(&stream);

					if (stream.current[0] == '\0')
						break;
				}
				struct token* owner p_new_token = new_token(start, stream.current, TK_LINE_COMMENT);
				p_new_token->flags |= has_space ? TK_FLAG_HAS_SPACE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= new_line ? TK_FLAG_HAS_NEWLINE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= addflags;

				p_new_token->level = level;
				p_new_token->token_origin = p_first;
				p_new_token->line = line;
				p_new_token->col = col;
				set_sliced_flag(&stream, p_new_token);
				token_list_add(&list, p_new_token);
				new_line = true;
				has_space = false;


				if (stream.current[0] == '\0')
					break;

				continue;
			}
			if (stream.current[0] == '/' &&
				stream.current[1] == '*')
			{
				const char* start = stream.current;
				stream_match(&stream);
				stream_match(&stream);
				//line comment
				for (;;)
				{
					if (stream.current[0] == '*' && stream.current[1] == '/')
					{
						stream_match(&stream);
						stream_match(&stream);
						break;
					}
					else if (stream.current[0] == '\0')
					{
						tokenizer_set_error(ctx, &stream, "missing end of comment");
						break;
					}
					else
					{
						stream_match(&stream);
					}
				}
				struct token* owner p_new_token = new_token(start, stream.current, TK_COMMENT);
				p_new_token->flags |= has_space ? TK_FLAG_HAS_SPACE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= new_line ? TK_FLAG_HAS_NEWLINE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= addflags;

				p_new_token->level = level;
				p_new_token->token_origin = p_first;
				p_new_token->line = line;
				p_new_token->col = col;
				token_list_add(&list, p_new_token);
				new_line = false;
				has_space = false;

				/*
				* Ignore line splicing inside comments.
				* if you are curious to see when it happens just add
				* set_sliced_flag
				*/

				continue;
			}
			if (new_line && stream.current[0] == '#')
			{
				const char* start = stream.current;
				stream_match(&stream);
				struct token* owner p_new_token = new_token(start, stream.current, '#');
				p_new_token->flags |= has_space ? TK_FLAG_HAS_SPACE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= new_line ? TK_FLAG_HAS_NEWLINE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= addflags;

				p_new_token->level = level;
				p_new_token->token_origin = p_first;
				p_new_token->line = line;
				p_new_token->col = col;
				p_new_token->type = TK_PREPROCESSOR_LINE;
				set_sliced_flag(&stream, p_new_token);
				token_list_add(&list, p_new_token);
				new_line = false;
				has_space = false;

				continue;
			}


			if (stream.current[0] == '\n' || stream.current[0] == '\r')
			{
				if (stream.current[0] == '\r' && stream.current[1] == '\n')
				{
					stream_match(&stream);
					stream_match(&stream);
				}
				else
				{
					stream_match(&stream);
				}
				char  newline[] = "\n";
				struct token* owner p_new_token = new_token(newline, newline + 1, TK_NEWLINE);
				p_new_token->flags |= has_space ? TK_FLAG_HAS_SPACE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= new_line ? TK_FLAG_HAS_NEWLINE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= addflags;

				p_new_token->level = level;
				p_new_token->token_origin = p_first;
				p_new_token->line = line;
				p_new_token->col = col;
				set_sliced_flag(&stream, p_new_token);
				token_list_add(&list, p_new_token);
				new_line = true;
				has_space = false;

				continue;
			}
			const char* start = stream.current;
			enum token_type t = is_punctuator(&stream);
			if (t != TK_NONE)
			{

				struct token* owner p_new_token = new_token(start, stream.current, t);
				p_new_token->flags |= has_space ? TK_FLAG_HAS_SPACE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= new_line ? TK_FLAG_HAS_NEWLINE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= addflags;

				p_new_token->level = level;
				p_new_token->token_origin = p_first;
				p_new_token->line = line;
				p_new_token->col = col;
				set_sliced_flag(&stream, p_new_token);
				token_list_add(&list, p_new_token);
				new_line = false;
				has_space = false;

				continue;
			}
			else
			{
				stream_match(&stream);
				struct token* owner p_new_token = new_token(start, stream.current, ANY_OTHER_PP_TOKEN);
				p_new_token->flags |= has_space ? TK_FLAG_HAS_SPACE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= new_line ? TK_FLAG_HAS_NEWLINE_BEFORE : TK_FLAG_NONE;
				p_new_token->flags |= addflags;

				p_new_token->level = level;
				p_new_token->token_origin = p_first;
				p_new_token->line = line;
				p_new_token->col = col;
				set_sliced_flag(&stream, p_new_token);
				token_list_add(&list, p_new_token);
				new_line = false;
				has_space = false;



				continue;
			}


			break;
		}
	}
	catch
	{
	}

	assert(list.head != NULL);
	return list;
}


bool fread2(void* buffer, size_t size, size_t count, FILE * stream, size_t * sz)
{
	*sz = 0;//out
	bool result = false;
	size_t n = fread(buffer, size, count, stream);
	if (n == count)
	{
		*sz = n;
		result = true;
	}
	else if (n < count)
	{
		if (feof(stream))
		{
			*sz = n;
			result = true;
		}
	}
	return result;
}


bool preprocessor_token_ahead_is_identifier(struct token* p, const char* lexeme);
struct token_list group_part(struct preprocessor_ctx* ctx, struct token_list* input_list, bool is_active, int level);
struct token_list group_opt(struct preprocessor_ctx* ctx, struct token_list* input_list, bool is_active, int level)
{
	/*
	  group:
	   group-part
	   group group-part
	*/
	struct token_list r = { 0 };
	try
	{

		if (token_list_is_empty(input_list))
		{
			return r;
		}
		while (!token_list_is_empty(input_list))
		{

			if (input_list->head->type == TK_PREPROCESSOR_LINE &&
				(preprocessor_token_ahead_is_identifier(input_list->head, "endif") ||
					preprocessor_token_ahead_is_identifier(input_list->head, "else") ||
					preprocessor_token_ahead_is_identifier(input_list->head, "elif") ||
					preprocessor_token_ahead_is_identifier(input_list->head, "elifdef") ||
					preprocessor_token_ahead_is_identifier(input_list->head, "elifndef")))
			{
				/*follow of group-part*/
				break;
			}
			else
			{
				struct token_list r2 = group_part(ctx, input_list, is_active, level);
				token_list_append_list(&r, &r2);
				token_list_destroy(&r2);
				if (ctx->n_errors > 0) throw;
			}
		}
	}
	catch
	{
	}

	return r;
}

bool is_parser_token(struct token* p)
{
	return p->type != TK_COMMENT &&
		p->type != TK_BLANKS &&
		p->type != TK_LINE_COMMENT &&
		p->type != TK_NEWLINE;
}

bool is_never_final(enum token_type type)
{
	return type == TK_BEGIN_OF_FILE ||
		type == TK_BLANKS ||
		type == TK_LINE_COMMENT ||
		type == TK_COMMENT ||
		type == TK_PLACEMARKER ||
		type == TK_NEWLINE;
}



enum token_type is_keyword(const char* text);






struct token* preprocessor_look_ahead_core(struct token* p)
{
	if (p->next == NULL)
	{
		return NULL;
	}
	struct token* current = p->next;
	if (current == NULL)
		return NULL;
	while (current &&
		(current->type == TK_BLANKS ||
			current->type == TK_PLACEMARKER ||
			current->type == TK_LINE_COMMENT ||
			current->type == TK_COMMENT))
	{
		current = current->next;
	}
	return current;
}

bool preprocessor_token_ahead_is(struct token* p, enum token_type t)
{
	struct token* p_token = preprocessor_look_ahead_core(p);
	if (p_token != NULL && p_token->type == t)
		return true;
	return false;
}

bool preprocessor_token_previous_is(struct token* p, enum token_type t)
{
	if (p == NULL)
	{
		return false;
	}
	struct token* current = p->prev;
	if (current == NULL)
		return false;
	while (current &&
		(current->type == TK_BLANKS ||
			current->type == TK_LINE_COMMENT ||
			current->type == TK_PLACEMARKER ||
			current->type == TK_COMMENT))
	{
		current = current->prev;
	}
	return (current && current->type == t);
}

bool preprocessor_token_ahead_is_identifier(struct token* p, const char* lexeme)
{
	assert(p != NULL);
	struct token* p_token = preprocessor_look_ahead_core(p);
	if (p_token != NULL && p_token->type == TK_IDENTIFIER)
	{
		return strcmp(p_token->lexeme, lexeme) == 0;
	}
	return false;
}


static void skip_blanks_level(struct preprocessor_ctx* ctx, struct token_list* dest, struct token_list* input_list, int level)
{
	while (input_list->head)
	{
		if (!token_is_blank(input_list->head))
			break;

		if (INCLUDE_ALL || level == 0)
			token_list_add(dest, token_list_pop_front_get(input_list));
		else
			token_list_pop_front(input_list); //deletar
	}
}

static void skip_blanks(struct preprocessor_ctx* ctx, struct token_list* dest, struct token_list* input_list)
{
	while (input_list->head)
	{
		if (!token_is_blank(input_list->head))
			break;
		token_list_add(dest, token_list_pop_front_get(input_list));
	}
}

void prematch_level(struct token_list* dest, struct token_list* input_list, int level)
{
	if (INCLUDE_ALL || level == 0)
		token_list_add(dest, token_list_pop_front_get(input_list));
	else
		token_list_pop_front(input_list);
}

void prematch(struct token_list* dest, struct token_list* input_list)
{
	token_list_add(dest, token_list_pop_front_get(input_list));
}

struct token_list pp_tokens_opt(struct preprocessor_ctx* ctx, struct token_list* input_list, int level);

struct token_list process_defined(struct preprocessor_ctx* ctx, struct token_list* obj_owner input_list)
{
	struct token_list r = { 0 };

	try
	{
		while (input_list->head != NULL)
		{
			if (input_list->head->type == TK_IDENTIFIER &&
				strcmp(input_list->head->lexeme, "defined") == 0)
			{
				token_list_pop_front(input_list);
				skip_blanks(ctx, &r, input_list);

				bool has_parentesis = false;
				if (input_list->head->type == '(')
				{
					token_list_pop_front(input_list);
					has_parentesis = true;
				}

				skip_blanks(ctx, &r, input_list);



				struct macro* macro = find_macro(ctx, input_list->head->lexeme);
				struct token* owner p_new_token = token_list_pop_front_get(input_list);
				p_new_token->type = TK_PPNUMBER;
				free(p_new_token->lexeme);
				if (macro)
				{
					p_new_token->lexeme = strdup("1");
				}
				else
				{
					p_new_token->lexeme = strdup("0");
				}

				token_list_add(&r, p_new_token);

				if (has_parentesis)
				{
					if (input_list->head->type != ')')
					{
						preprocessor_set_error_with_token(C_MISSING_CLOSE_PARENTHESIS, ctx, input_list->head, "missing )");
						throw;
					}
					token_list_pop_front(input_list);
				}


			}
			else if (input_list->head->type == TK_IDENTIFIER &&
				(strcmp(input_list->head->lexeme, "__has_include") == 0 ||
					strcmp(input_list->head->lexeme, "__has_embed") == 0)
				)
			{
				token_list_pop_front(input_list); //pop __has_include
				skip_blanks(ctx, &r, input_list);
				token_list_pop_front(input_list); //pop (
				skip_blanks(ctx, &r, input_list);


				char path[100] = { 0 };

				if (input_list->head->type == TK_STRING_LITERAL)
				{
					strcat(path, input_list->head->lexeme);
					token_list_pop_front(input_list); //pop "file"
				}
				else
				{
					token_list_pop_front(input_list); //pop <

					while (input_list->head->type != '>')
					{
						strcat(path, input_list->head->lexeme);
						token_list_pop_front(input_list); //pop (
					}
					token_list_pop_front(input_list); //pop >					
				}

				char fullpath[300] = { 0 };



				char full_path_result[200] = { 0 };
				bool already_included = false;
				const char* owner s = find_and_read_include_file(ctx,
					path,
					fullpath,
					&already_included,
					full_path_result,
					sizeof full_path_result);

				bool has_include = s != NULL;
				free((void* owner)s);

				struct token* owner p_new_token = calloc(1, sizeof * p_new_token);
				p_new_token->type = TK_PPNUMBER;
				p_new_token->lexeme = strdup(has_include ? "1" : "0");
				p_new_token->flags |= TK_FLAG_FINAL;

				token_list_add(&r, p_new_token);
				token_list_pop_front(input_list); //pop )
			}
			else if (input_list->head->type == TK_IDENTIFIER &&
				strcmp(input_list->head->lexeme, "__has_c_attribute") == 0)
			{
				token_list_pop_front(input_list); //pop __has_include
				skip_blanks(ctx, &r, input_list);
				token_list_pop_front(input_list); //pop (
				skip_blanks(ctx, &r, input_list);


				char path[100] = { 0 };
				while (input_list->head->type != ')')
				{
					strcat(path, input_list->head->lexeme);
					token_list_pop_front(input_list); //pop (
				}
				token_list_pop_front(input_list); //pop >					

				/*nodiscard
				* The __has_c_attribute conditional inclusion expression (6.10.1) shall
				* return the value 202003L
				* when given nodiscard as the pp-tokens operand.
				*/

				/*maybe_unused
				* The __has_c_attribute conditional inclusion expression (6.10.1) shall return
				* the value 202106L when given maybe_unused as the pp-tokens operand.
				*/

				/*deprecated
				* The __has_c_attribute conditional inclusion expression (6.10.1) shall return the value 201904L
				* when given deprecated as the pp-tokens operand
				*/

				/*noreturn
				* The __has_c_attribute conditional inclusion expression (6.10.1) shall return the value 202202L
				* when given noreturn as the pp-tokens operand.
				*/

				/*reproducible
				 * The __has_c_attribute conditional inclusion expression (6.10.1) shall return the value 202207L
				 * when given reproducible as the pp-tokens operand.
				*/

				/*
				* The __has_c_attribute conditional inclusion expression (6.10.1) shall return the value 202207L
				* when given unsequenced as the pp-tokens operand.
				*/
				bool has_c_attribute = false;

				struct token* owner p_new_token = calloc(1, sizeof * p_new_token);
				p_new_token->type = TK_PPNUMBER;
				p_new_token->lexeme = strdup(has_c_attribute ? "1" : "0");
				p_new_token->flags |= TK_FLAG_FINAL;

				token_list_add(&r, p_new_token);
				token_list_pop_front(input_list); //pop )
			}
			else
			{
				token_list_add(&r, token_list_pop_front_get(input_list));
			}
		}
	}
	catch
	{
	}

	return r;
}

struct token_list process_identifiers(struct preprocessor_ctx* ctx, struct token_list* obj_owner list)
{
	assert(!token_list_is_empty(list));

	struct token_list list2 = { 0 };


	while (list->head != NULL)
	{
		if (list->head->type == TK_IDENTIFIER)
		{

			struct macro* macro = find_macro(ctx, list->head->lexeme);
			struct token* owner p_new_token = token_list_pop_front_get(list);
			p_new_token->type = TK_PPNUMBER;

			if (macro)
			{
				free(p_new_token->lexeme);
				p_new_token->lexeme = strdup("1");
			}
			else
			{
				/*
				* after all replacements due to macro expansion and
				  evaluations of defined macro expressions, has_include expressions, and has_c_attribute expressions
				  have been performed, all remaining identifiers other than true (including those lexically identical
				  to keywords such as false) are replaced with the pp-number 0, true is replaced with pp-number
				  1, and then each preprocessing token is converted into a token.
				*/
				if (strcmp(p_new_token->lexeme, "true") == 0)
				{
					p_new_token->lexeme[0] = '1';
					p_new_token->lexeme[1] = '\0';
				}
				else if (strcmp(p_new_token->lexeme, "false") == 0)
				{
					p_new_token->lexeme[0] = '0';
					p_new_token->lexeme[1] = '\0';
				}
				else
				{
					free(p_new_token->lexeme);
					p_new_token->lexeme = strdup("0");
				}
			}
			token_list_add(&list2, p_new_token);
		}
		else
		{
			token_list_add(&list2, token_list_pop_front_get(list));
		}
	}
	assert(!token_list_is_empty(&list2));
	return list2;
}

struct token_list ignore_preprocessor_line(struct token_list* input_list)
{
	struct token_list r = { 0 };
	while (input_list->head->type != TK_NEWLINE)
	{
		token_list_add(&r, token_list_pop_front_get(input_list));
	}
	return r;
}

//todo passar lista para reotnro
long long preprocessor_constant_expression(struct preprocessor_ctx* ctx,
	struct token_list* output_list,
	struct token_list* input_list,
	int level
)
{
	struct token* first = input_list->head;

	ctx->conditional_inclusion = true;

	struct token_list r = { 0 };
	while (input_list->head && input_list->head->type != TK_NEWLINE)
	{
		token_list_add(&r, token_list_pop_front_get(input_list));

		/*
		  We call preprocessor that emmit warnings if line continuation
		  is used outside macro directives.
		  Let's remove TK_FLAG_LINE_CONTINUATION from the original token
		  to avoid warning inside constant expressions
		*/
		r.tail->flags &= ~TK_FLAG_LINE_CONTINUATION;
	}

	struct token_list list1 = copy_replacement_list(&r);
	token_list_swap(output_list, &r);


	//printf("\n");
	//print_list(&list1);
	//printf("\n");



	int flags = ctx->flags;
	ctx->flags |= PREPROCESSOR_CTX_FLAGS_ONLY_FINAL;

	/*defined X  por exemplo é mantido sem ser expandido*/

	struct token_list list2 = preprocessor(ctx, &list1, 1);
	ctx->flags = flags;
	//printf("apos preprocess\n");
	//print_list(&list2);
	//printf("\n");

	/*aonde defined has_c_aatribute sao transformados em constantes*/
	struct token_list list3 = process_defined(ctx, &list2);

	//printf("apos remove defined\n");
	//print_list(&list3);
	//printf("\n");

	struct token_list list4 = process_identifiers(ctx, &list3);

	//printf("apos remover identificadores restantes\n");
	//print_list(&list4);
	//printf("\n");

	assert(list4.head != NULL);

	struct preprocessor_ctx pre_ctx = { 0 };

	//struct parser_ctx parser_ctx = { 0 };
	pre_ctx.input_list = list4;
	pre_ctx.current = pre_ctx.input_list.head;
	//pre_skip_blanks(&parser_ctx);

	long long value = 0;
	if (pre_constant_expression(&pre_ctx, &value) != 0)
	{
		preprocessor_set_error_with_token(C_EXPRESSION_ERROR, ctx, first, "expression error");
	}

	ctx->conditional_inclusion = false;

	preprocessor_ctx_destroy(&pre_ctx);
	token_list_destroy(&list1);

	token_list_destroy(&r);

	return value;
}

void match_level(struct token_list* dest, struct token_list* input_list, int level)
{
	if (INCLUDE_ALL || level == 0)
		token_list_add(dest, token_list_pop_front_get(input_list));
	else
		token_list_pop_front(input_list); //deletar
}


int match_token_level(struct token_list* dest, struct token_list* input_list, enum token_type type, int level,
	struct preprocessor_ctx* ctx)
{
	try
	{
		if (input_list->head == NULL ||
			input_list->head->type != type)
		{
			if (type == TK_NEWLINE && input_list->head == NULL)
			{
				//vou aceitar final de arquivo como substituro do endline
				//exemplo #endif sem quebra de linha
			}
			else
			{
				if (input_list->head)
					preprocessor_set_error_with_token(C_UNEXPECTED_TOKEN, ctx, input_list->head, "expected token %s got %s\n", get_token_name(type), get_token_name(input_list->head->type));
				else
					preprocessor_set_error_with_token(C_UNEXPECTED_TOKEN, ctx, dest->tail, "expected EOF \n");

				throw;
			}
		}
		if (input_list->head != NULL)
		{
			if (INCLUDE_ALL || level == 0)
				token_list_add(dest, token_list_pop_front_get(input_list));
			else
				token_list_pop_front(input_list); //deletar
		}
	}
	catch
	{
	}
	return ctx->n_errors > 0;
}


struct token_list if_group(struct preprocessor_ctx* ctx, struct token_list* input_list, bool is_active, int level, bool* p_result)
{
	*p_result = 0; //out

	struct token_list r = { 0 };
	try
	{
		/*
		 if-group:
		   # if constant-expression new-line group_opt
		   # ifdef identifier new-line group_opt
		   # ifndef identifier new-line group_opt
		*/
		match_token_level(&r, input_list, TK_PREPROCESSOR_LINE, level, ctx);
		skip_blanks_level(ctx, &r, input_list, level);
		assert(input_list->head->type == TK_IDENTIFIER);
		if (strcmp(input_list->head->lexeme, "ifdef") == 0)
		{
			match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx); //ifdef
			skip_blanks_level(ctx, &r, input_list, level);
			if (is_active)
			{
				struct macro* macro = find_macro(ctx, input_list->head->lexeme);
				*p_result = (macro != NULL) ? 1 : 0;
				//printf("#ifdef %s (%s)\n", input_list->head->lexeme, *p_result ? "true" : "false");
			}
			match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);
			skip_blanks_level(ctx, &r, input_list, level);
			match_token_level(&r, input_list, TK_NEWLINE, level, ctx);
		}
		else if (strcmp(input_list->head->lexeme, "ifndef") == 0)
		{
			match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx); //ifndef
			skip_blanks_level(ctx, &r, input_list, level);
			if (is_active)
			{
				struct macro* macro = find_macro(ctx, input_list->head->lexeme);
				*p_result = (macro == NULL) ? 1 : 0;
			}
			match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);
			skip_blanks_level(ctx, &r, input_list, level);
			match_token_level(&r, input_list, TK_NEWLINE, level, ctx);
		}
		else if (strcmp(input_list->head->lexeme, "if") == 0)
		{
			match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx); //if
			skip_blanks_level(ctx, &r, input_list, level);
			if (is_active)
			{
				struct token_list r0 = { 0 };
				*p_result = preprocessor_constant_expression(ctx, &r0, input_list, level);
				token_list_append_list(&r, &r0);
				token_list_destroy(&r0);
			}
			else
			{
				struct token_list r0 = ignore_preprocessor_line(input_list);
				token_list_append_list(&r, &r0);
				token_list_destroy(&r0);
			}
			match_token_level(&r, input_list, TK_NEWLINE, level, ctx);
		}
		else
		{

			preprocessor_set_error_with_token(C_UNEXPECTED, ctx, input_list->head, "unexpected");
			throw;
		}
		struct token_list r2 = group_opt(ctx, input_list, is_active && *p_result, level);
		token_list_append_list(&r, &r2);
		assert(r2.head == NULL);
		assert(r2.tail == NULL);
	}
	catch
	{
	}

	return r;
}

struct token_list elif_group(struct preprocessor_ctx* ctx, struct token_list* input_list, bool is_active, int level, bool* p_elif_result)
{
	*p_elif_result = 0; //out

	struct token_list r = { 0 };
	/*
	 elif-group:
	  # elif constant-expression new-line group_opt

	  C23
	  # elifdef identifier new-line group_opt
	  # elifndef identifier new-line group_opt
	*/
	match_token_level(&r, input_list, TK_PREPROCESSOR_LINE, level, ctx);
	skip_blanks(ctx, &r, input_list);
	unsigned long long result = 0;
	if (strcmp(input_list->head->lexeme, "elif") == 0)
	{
		match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);
		skip_blanks(ctx, &r, input_list);

		if (is_active)
		{
			struct token_list r0 = { 0 };
			result = preprocessor_constant_expression(ctx, &r0, input_list, level);
			token_list_append_list(&r, &r0);
			token_list_destroy(&r0);
		}
		else
		{
			struct token_list r0 = ignore_preprocessor_line(input_list);
			token_list_append_list(&r, &r0);
			token_list_destroy(&r0);
		}
	}
	else if (strcmp(input_list->head->lexeme, "elifdef") == 0)
	{
		match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);
		skip_blanks(ctx, &r, input_list);

		if (is_active)
		{
			result = (owner_hashmap_find(&ctx->macros, input_list->head->lexeme) != NULL) ? 1 : 0;
		}
		match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);
	}
	else if (strcmp(input_list->head->lexeme, "elifndef") == 0)
	{
		match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);
		skip_blanks(ctx, &r, input_list);

		if (is_active)
		{
			result = (owner_hashmap_find(&ctx->macros, input_list->head->lexeme) == NULL) ? 1 : 0;
		}
		match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);
	}
	*p_elif_result = (result != 0);
	skip_blanks(ctx, &r, input_list);
	match_token_level(&r, input_list, TK_NEWLINE, level, ctx);
	struct token_list r2 = group_opt(ctx, input_list, is_active && *p_elif_result, level);
	token_list_append_list(&r, &r2);
	token_list_destroy(&r2);
	return r;
}

struct token_list elif_groups(struct preprocessor_ctx* ctx, struct token_list* input_list, bool is_active, int level, bool* pelif_result)
{
	struct token_list r = { 0 };
	/*
	elif-groups:
	  elif-group
	  elif-groups elif-group
	*/
	bool already_found_elif_true = false;
	bool elif_result = false;
	struct token_list r2 = elif_group(ctx, input_list, is_active, level, &elif_result);
	token_list_append_list(&r, &r2);
	if (elif_result)
		already_found_elif_true = true;
	if (input_list->head->type == TK_PREPROCESSOR_LINE &&
		(
			preprocessor_token_ahead_is_identifier(input_list->head, "elif") ||
			preprocessor_token_ahead_is_identifier(input_list->head, "elifdef") ||
			preprocessor_token_ahead_is_identifier(input_list->head, "elifndef")
			)
		)
	{
		/*
		  Depois que acha 1 true already_found_elif_true os outros sao false.
		*/
		struct token_list r3 = elif_groups(ctx, input_list, is_active && !already_found_elif_true, level, &elif_result);
		token_list_append_list(&r, &r3);
		if (elif_result)
			already_found_elif_true = true;
		token_list_destroy(&r3);
	}
	/*
	   Se algum dos elifs foi true retorna true
	*/
	*pelif_result = already_found_elif_true;
	token_list_destroy(&r2);
	return r;
}

struct token_list else_group(struct preprocessor_ctx* ctx, struct token_list* input_list, bool is_active, int level)
{
	/*
	  else-group:
	   # else new-line group_opt
	*/

	struct token_list r = { 0 };
	match_token_level(&r, input_list, TK_PREPROCESSOR_LINE, level, ctx);
	skip_blanks_level(ctx, &r, input_list, level);

	match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx); //else
	skip_blanks_level(ctx, &r, input_list, level);
	match_token_level(&r, input_list, TK_NEWLINE, level, ctx);

	struct token_list r2 = group_opt(ctx, input_list, is_active, level);
	token_list_append_list(&r, &r2);

	token_list_destroy(&r2);

	return r;
}

struct token_list endif_line(struct preprocessor_ctx* ctx, struct token_list* input_list, int level)
{
	/*
	 endif-line:
	   # endif new-line
	*/

	struct token_list r = { 0 };

	match_token_level(&r, input_list, TK_PREPROCESSOR_LINE, level, ctx); //#
	skip_blanks_level(ctx, &r, input_list, level);
	match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx); //endif
	skip_blanks_level(ctx, &r, input_list, level);
	match_token_level(&r, input_list, TK_NEWLINE, level, ctx);

	return r;
}

struct token_list if_section(struct preprocessor_ctx* ctx, struct token_list* input_list, bool is_active, int level)
{
	/*
	 if-section:
	   if-group elif-groups_opt else-group_opt endif-line
	*/

	struct token_list r = { 0 };

	try
	{
		bool if_result = false;
		struct token_list r2 = if_group(ctx, input_list, is_active, level, &if_result);
		if (ctx->n_errors > 0)
		{
			token_list_destroy(&r2);
			throw;
		}

		token_list_append_list(&r, &r2);
		bool elif_result = false;
		if (input_list->head->type == TK_PREPROCESSOR_LINE && (
			preprocessor_token_ahead_is_identifier(input_list->head, "elif") ||
			preprocessor_token_ahead_is_identifier(input_list->head, "elifdef") ||
			preprocessor_token_ahead_is_identifier(input_list->head, "elifndef")))
		{
			struct token_list r3 = elif_groups(ctx, input_list, is_active && !if_result, level, &elif_result);
			token_list_append_list(&r, &r3);
			token_list_destroy(&r3);
		}
		if (input_list->head->type == TK_PREPROCESSOR_LINE &&
			preprocessor_token_ahead_is_identifier(input_list->head, "else"))
		{
			struct token_list r4 = else_group(ctx, input_list, is_active && !if_result && !elif_result, level);
			token_list_append_list(&r, &r4);
			token_list_destroy(&r4);
		}

		if (ctx->n_errors > 0)
		{
			token_list_destroy(&r2);
			throw;
		}

		struct token_list r5 = endif_line(ctx, input_list, level);
		token_list_append_list(&r, &r5);
		token_list_destroy(&r5);
		token_list_destroy(&r2);
	}
	catch
	{
	}

	return r;
}

struct token_list identifier_list(struct preprocessor_ctx* ctx, struct macro* macro, struct token_list* input_list, int level)
{
	struct token_list r = { 0 };
	/*
	  identifier-list:
	  identifier
	  identifier-list , identifier
	*/
	skip_blanks(ctx, &r, input_list);

	struct macro_parameter* owner p_macro_parameter = calloc(1, sizeof * p_macro_parameter);
	p_macro_parameter->name = strdup(input_list->head->lexeme);

	assert(macro->parameters == NULL);
	macro->parameters = p_macro_parameter;

	struct macro_parameter* p_last_parameter = macro->parameters;

	match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);
	skip_blanks(ctx, &r, input_list);

	while (input_list->head->type == ',')
	{
		match_token_level(&r, input_list, ',', level, ctx);
		skip_blanks(ctx, &r, input_list);
		if (input_list->head->type == '...')
		{
			break;
		}

		struct macro_parameter* owner p_new_macro_parameter = calloc(1, sizeof * p_new_macro_parameter);
		p_new_macro_parameter->name = strdup(input_list->head->lexeme);

		assert(p_last_parameter->next == NULL);
		p_last_parameter->next = p_new_macro_parameter;
		p_last_parameter = p_last_parameter->next;

		match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);
		skip_blanks(ctx, &r, input_list);
	}
	return r;
}


struct token_list replacement_list(struct preprocessor_ctx* ctx, struct macro* macro, struct token_list* input_list, int level)
{
	struct token_list r = { 0 };

	while (input_list->head->type != TK_NEWLINE)
	{
		match_level(&r, input_list, level);
		if (input_list->head == NULL)
		{
			//terminou define sem quebra de linha
		}
	}

	assert(macro->replacement_list.head == NULL);
	struct token_list copy = copy_replacement_list(&r);
	token_list_append_list(&macro->replacement_list, &copy);
	token_list_destroy(&copy);
	return r;
}

struct token_list pp_tokens_opt(struct preprocessor_ctx* ctx, struct token_list* input_list, int level)
{
	struct token_list r = { 0 };
	while (input_list->head->type != TK_NEWLINE)
	{
		prematch_level(&r, input_list, level);
	}
	return r;
}

static bool is_empty_assert(struct token_list* replacement_list)
{
	struct token* token = replacement_list->head;

	if (token == NULL) return false;
	if (strcmp(token->lexeme, "(")) return false;
	token = token->next;

	if (token == NULL) return false;
	if (strcmp(token->lexeme, "(")) return false;
	token = token->next;

	if (token == NULL) return false;
	if (strcmp(token->lexeme, "void")) return false;
	token = token->next;

	if (token == NULL) return false;
	if (strcmp(token->lexeme, ")")) return false;
	token = token->next;

	if (token == NULL) return false;
	if (strcmp(token->lexeme, "0")) return false;
	token = token->next;

	if (token == NULL) return false;
	if (strcmp(token->lexeme, ")")) return false;
	token = token->next;

	if (token != NULL) return false;

	return true;
}

struct token_list control_line(struct preprocessor_ctx* ctx, struct token_list* input_list, bool is_active, int level)
{
	/*
		control-line:
			# "include" pp-tokens new-line
			# "embed" pp-tokens new-line
			# "define" identifier replacement-list new-line
			# "define" identifier ( identifier-list opt ) replacement-list new-line
			# "define" identifier ( ... ) replacement-list new-line
			# "define" identifier ( identifier-list , ... ) replacement-list new-line
			# "undef" identifier new-line
			# "line" pp-tokens new-line
			# "error" pp-tokens opt new-line
			# "warning" pp-tokens opt new-line
			# "pragma" pp-tokens opt new-line
			# new-line
	*/

	struct token_list r = { 0 };

	try
	{

		if (!is_active)
		{
			//se nao esta ativo eh ignorado
			struct token_list r7 = pp_tokens_opt(ctx, input_list, level);
			token_list_append_list(&r, &r7);
			match_token_level(&r, input_list, TK_NEWLINE, level, ctx);
			token_list_destroy(&r7);
			return r;
		}

#ifdef _WIN32
		//char line[1000] = { 0 };
		//snprintf(line, sizeof line, "%s(%d,%d):\n", input_list->head->token_origin->lexeme, input_list->head->line, input_list->head->col);
		//OutputDebugStringA(line);
#endif
		struct token* const ptoken = input_list->head;
		match_token_level(&r, input_list, TK_PREPROCESSOR_LINE, level, ctx);
		skip_blanks_level(ctx, &r, input_list, level);
		if (strcmp(input_list->head->lexeme, "include") == 0)
		{
			/*
			  # include pp-tokens new-line
			*/
			match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx); //include
			skip_blanks_level(ctx, &r, input_list, level);
			char path[100] = { 0 };

			if (input_list->head->type == TK_STRING_LITERAL)
			{
				strcat(path, input_list->head->lexeme);
				prematch_level(&r, input_list, level);
			}
			else
			{
				while (input_list->head->type != '>')
				{
					strcat(path, input_list->head->lexeme);
					prematch_level(&r, input_list, level);
				}
				strcat(path, input_list->head->lexeme);
				prematch_level(&r, input_list, level);
			}

			if (input_list->head)
			{
				while (input_list->head->type != TK_NEWLINE)
				{
					prematch_level(&r, input_list, level);
				}
			}
			match_token_level(&r, input_list, TK_NEWLINE, level, ctx);

			path[strlen(path) - 1] = '\0';

			/*this is the dir of the current file*/
			char current_file_dir[300] = { 0 };
			snprintf(current_file_dir, sizeof current_file_dir, "%s", r.tail->token_origin->lexeme);
			dirname(current_file_dir);


			char full_path_result[200] = { 0 };
			bool already_included = false;
			const char* owner content = find_and_read_include_file(ctx,
				path + 1,
				current_file_dir,
				&already_included,
				full_path_result,
				sizeof full_path_result);

			if (content != NULL)
			{
				if (ctx->options.show_includes)
				{
					printf("Note: including file:");
					printf("%*c", level + 1, ' ');
					printf("%s\n", full_path_result);
				}

				struct tokenizer_ctx tctx = { 0 };
				struct token_list list = tokenizer(&tctx, content, full_path_result, level + 1, TK_FLAG_NONE);
				free((void* owner)content);

				struct token_list list2 = preprocessor(ctx, &list, level + 1);
				token_list_append_list(&r, &list2);

				token_list_destroy(&list2);
				token_list_destroy(&list);
			}
			else
			{
				if (!already_included)
				{
					preprocessor_set_error_with_token(C_FILE_NOT_FOUND, ctx, r.tail, "file %s not found", path + 1);

					for (struct include_dir* p = ctx->include_dir.head; p; p = p->next)
					{
						/*let's print the include path*/
						preprocessor_set_info_with_token(ctx, r.tail, "dir = '%s'", p->path);
					}
				}
				else
				{
					//pragma once..
				}
			}

		}
		else if (strcmp(input_list->head->lexeme, "embed") == 0)
		{
			struct token_list discard0 = { 0 };
			struct token_list* p_list = &r;
			if (ctx->options.target < LANGUAGE_C2X)
			{
				p_list = &discard0;

				free(ptoken->lexeme);
				ptoken->lexeme = strdup(" ");

			}

			/*
			  C23
			  # embed pp-tokens new-line
			*/
			match_token_level(p_list, input_list, TK_IDENTIFIER, level, ctx); //embed
			skip_blanks_level(ctx, p_list, input_list, level);
			char path[100] = { 0 };

			if (input_list->head->type == TK_STRING_LITERAL)
			{
				strcat(path, input_list->head->lexeme);
				prematch_level(p_list, input_list, level);
			}
			else
			{
				while (input_list->head->type != '>')
				{
					strcat(path, input_list->head->lexeme);
					prematch_level(p_list, input_list, level);
				}
				strcat(path, input_list->head->lexeme);
				prematch_level(p_list, input_list, level);
			}

			if (input_list->head)
			{
				while (input_list->head->type != TK_NEWLINE)
				{
					prematch_level(p_list, input_list, level);
				}
			}
			match_token_level(p_list, input_list, TK_NEWLINE, level, ctx);



			char fullpath[300] = { 0 };
			path[strlen(path) - 1] = '\0';

			snprintf(fullpath, sizeof(fullpath), "%s", path + 1);


			int nlevel = level;

			enum token_flags f = 0;
			if (ctx->options.target < LANGUAGE_C2X)
			{
				//we can see it
				f = TK_FLAG_FINAL;
			}
			else
			{
				f = TK_FLAG_FINAL;
				//we cannot see it just like include
				nlevel = nlevel + 1;
			}

			struct token_list list = embed_tokenizer(ctx, fullpath, nlevel, f);


			token_list_append_list(&r, &list);
			token_list_destroy(&list);
			token_list_destroy(&discard0);
		}
		else if (strcmp(input_list->head->lexeme, "define") == 0)
		{
			//TODO strcmp nao pode ser usado temos que criar uma funcao especial

			/*
			 #de\
			 fine A 1

			A
			*/

			struct macro* owner macro = calloc(1, sizeof * macro);
			if (macro == NULL)
			{
				preprocessor_set_error_with_token(C_UNEXPECTED, ctx, ctx->current, "out of mem");
				throw;
			}

			/*
				# define identifier                           replacement-list new-line
				# define identifier ( identifier-list_opt )    replacement-list new-line
				# define identifier ( ... )                   replacement-list new-line
				# define identifier ( identifier-list , ... ) replacement-list new-line
			*/
			//p = preprocessor_match_identifier(p, is_active, level, false, "define");

			match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx); //define
			skip_blanks_level(ctx, &r, input_list, level);

			// printf("define %s\n%s : %d\n", input_list->head->lexeme, input_list->head->token_origin->lexeme, input_list->head->line);

			struct token* macro_name_token = input_list->head;


			if (owner_hashmap_find(&ctx->macros, input_list->head->lexeme) != NULL)
			{
				//printf("warning: '%s' macro redefined at %s %d\n",
				  //     input_list->head->lexeme,
					///   input_list->head->token_origin->lexeme,
					  // input_list->head->line);
			}

			assert(macro->name == NULL);
			macro->name = strdup(input_list->head->lexeme);
			struct macro* owner previous =
				owner_hashmap_set(&ctx->macros, input_list->head->lexeme, (void* owner)macro, 0);
			if (previous)
			{
				delete_macro(previous);
				previous = NULL;
			}


			match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx); //nome da macro


			/*sem skip*/
			//p = preprocessor_match_token(p, is_active, level, false, IDENTIFIER); /*name*/
			if (input_list->head->type == '(')
			{

				macro->is_function = true;


				match_token_level(&r, input_list, '(', level, ctx);
				skip_blanks_level(ctx, &r, input_list, level);
				if (input_list->head->type == '...')
				{
					struct macro_parameter* owner p_macro_parameter = calloc(1, sizeof * p_macro_parameter);
					p_macro_parameter->name = strdup("__VA_ARGS__");
					macro->parameters = p_macro_parameter;

					// assert(false);
					match_token_level(&r, input_list, '...', level, ctx); //nome da macro
					skip_blanks_level(ctx, &r, input_list, level);
					match_token_level(&r, input_list, ')', level, ctx); //nome da macro
				}
				else if (input_list->head->type == ')')
				{
					match_token_level(&r, input_list, ')', level, ctx);
					skip_blanks_level(ctx, &r, input_list, level);
				}
				else
				{
					struct token_list r3 = identifier_list(ctx, macro, input_list, level);
					token_list_append_list(&r, &r3);
					token_list_destroy(&r3);

					skip_blanks_level(ctx, &r, input_list, level);
					if (input_list->head->type == '...')
					{
						struct macro_parameter* owner p_macro_parameter = calloc(1, sizeof * p_macro_parameter);
						p_macro_parameter->name = strdup("__VA_ARGS__");
						struct macro_parameter* p_last = macro->parameters;
						assert(p_last != NULL);
						while (p_last->next)
						{
							p_last = p_last->next;
						}
						p_last->next = p_macro_parameter;

						match_token_level(&r, input_list, '...', level, ctx);
					}
					skip_blanks_level(ctx, &r, input_list, level);
					match_token_level(&r, input_list, ')', level, ctx);
				}
			}
			else
			{
				macro->is_function = false;
			}
			skip_blanks_level(ctx, &r, input_list, level);
			struct token_list r4 = replacement_list(ctx, macro, input_list, level);
			token_list_append_list(&r, &r4);
			token_list_destroy(&r4);

			match_token_level(&r, input_list, TK_NEWLINE, level, ctx);

			if (strcmp(macro->name, "assert") == 0)
			{
				// TODO create option for this?
				// Cake overrides the definition of macro to be 
				// #define assert(...) assert(__VA_ARGS__)
				// and assert is a keyword. The reason is the send
				// information to the static analyzer


				if (!is_empty_assert(&macro->replacement_list))
				{
					macro_parameters_delete(macro->parameters);

					struct macro_parameter* owner p_macro_parameter = calloc(1, sizeof * p_macro_parameter);
					p_macro_parameter->name = strdup("__VA_ARGS__");
					macro->parameters = p_macro_parameter;

					token_list_destroy(&macro->replacement_list);
					struct tokenizer_ctx tctx = { 0 };
					macro->replacement_list = tokenizer(&tctx, "assert(__VA_ARGS__)", NULL, level, TK_FLAG_NONE);
				}
			}

			if (macro_name_token)
				naming_convention_macro(ctx, macro_name_token);
		}
		else if (strcmp(input_list->head->lexeme, "undef") == 0)
		{
			/*
			 # undef identifier new-line
			*/
			match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//undef
			skip_blanks_level(ctx, &r, input_list, level);

			struct macro* owner macro = (struct macro* owner) owner_hashmap_remove(&ctx->macros, input_list->head->lexeme, NULL);
			assert(find_macro(ctx, input_list->head->lexeme) == NULL);
			if (macro)
			{
				delete_macro(macro);
				match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//undef
			}
			else
			{
				match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//undef
				/*no warnings*/
			}
			skip_blanks_level(ctx, &r, input_list, level);
			match_token_level(&r, input_list, TK_NEWLINE, level, ctx);
		}
		else if (strcmp(input_list->head->lexeme, "line") == 0)
		{
			/*
			   # line pp-tokens new-line
			*/
			match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//line
			struct token_list r5 = pp_tokens_opt(ctx, input_list, level);
			token_list_append_list(&r, &r5);
			token_list_destroy(&r5);
			match_token_level(&r, input_list, TK_NEWLINE, level, ctx);
		}
		else if (strcmp(input_list->head->lexeme, "error") == 0)
		{
			/*
			  # error pp-tokensopt new-line
			*/
			ctx->n_warnings++;
			match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//error
			struct token_list r6 = pp_tokens_opt(ctx, input_list, level);
			preprocessor_set_error_with_token(C_PREPROCESSOR_ERROR_DIRECTIVE, ctx, input_list->head, "#error");
			token_list_append_list(&r, &r6);
			token_list_destroy(&r6);
			match_token_level(&r, input_list, TK_NEWLINE, level, ctx);


		}
		else if (strcmp(input_list->head->lexeme, "warning") == 0)
		{
			/*
			  # warning pp-tokensopt new-line
			*/
			ctx->n_warnings++;
			if (ctx->options.target < LANGUAGE_C2X)
			{
				/*insert comment before #*/
				free(ptoken->lexeme);
				ptoken->lexeme = strdup("//#");
			}
			match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//warning

			struct token_list r6 = pp_tokens_opt(ctx, input_list, level);
			preprocessor_set_warning_with_token(W_NONE, ctx, input_list->head, "#warning");
			token_list_append_list(&r, &r6);
			match_token_level(&r, input_list, TK_NEWLINE, level, ctx);
			token_list_destroy(&r6);
		}
		else if (strcmp(input_list->head->lexeme, "pragma") == 0)
		{
			/*
			  # pragma pp-tokensopt new-line
			*/
			match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//pragma
			r.tail->type = TK_PRAGMA;
			skip_blanks_level(ctx, &r, input_list, level);

			if (input_list->head->type == TK_IDENTIFIER)
			{
				if (strcmp(input_list->head->lexeme, "CAKE") == 0)
				{
					match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);
					skip_blanks_level(ctx, &r, input_list, level);
				}

				if (input_list->head && strcmp(input_list->head->lexeme, "once") == 0)
				{
					hashmap_set(&ctx->pragma_once_map, input_list->head->token_origin->lexeme, (void*)1, 0);
					match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//pragma
				}
				else if (input_list->head && strcmp(input_list->head->lexeme, "dir") == 0)
				{
					match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//pragma
					skip_blanks_level(ctx, &r, input_list, level);
					char path[200] = { 0 };
					strncpy(path, input_list->head->lexeme + 1, strlen(input_list->head->lexeme) - 2);
					include_dir_add(&ctx->include_dir, path);
					match_token_level(&r, input_list, TK_STRING_LITERAL, level, ctx);//pragma
				}
				else if (input_list->head && strcmp(input_list->head->lexeme, "expand") == 0)
				{
					match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//pragma
					skip_blanks_level(ctx, &r, input_list, level);

					struct macro* macro = find_macro(ctx, input_list->head->lexeme);
					if (macro)
					{
						macro->expand = true;
					}

					match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//pragma
				}
				else if (input_list->head && strcmp(input_list->head->lexeme, "nullchecks") == 0)
				{
					match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//nullchecks
					skip_blanks_level(ctx, &r, input_list, level);
					ctx->options.null_checks = true;
				}

				if (input_list->head && strcmp(input_list->head->lexeme, "diagnostic") == 0)
				{
					match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//diagnostic
					skip_blanks_level(ctx, &r, input_list, level);

					if (input_list->head && strcmp(input_list->head->lexeme, "push") == 0)
					{
						match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//diagnostic
						//#pragma GCC diagnostic push
						if (ctx->options.enabled_warnings_stack_top_index <
							sizeof(ctx->options.enabled_warnings_stack) / sizeof(ctx->options.enabled_warnings_stack[0]))
						{
							ctx->options.enabled_warnings_stack_top_index++;
							ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index] =
								ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index - 1];
						}
					}
					else if (input_list->head && strcmp(input_list->head->lexeme, "pop") == 0)
					{
						//#pragma GCC diagnostic pop
						match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//pop
						if (ctx->options.enabled_warnings_stack_top_index > 0)
						{
							ctx->options.enabled_warnings_stack_top_index--;
						}
					}
					else if (input_list->head && strcmp(input_list->head->lexeme, "warning") == 0)
					{
						//#pragma CAKE diagnostic warning "-Wenum-compare"

						match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//warning
						skip_blanks_level(ctx, &r, input_list, level);

						if (input_list->head && input_list->head->type == TK_STRING_LITERAL)
						{
							match_token_level(&r, input_list, TK_STRING_LITERAL, level, ctx);//""

							enum warning  w = get_warning_flag(input_list->head->lexeme + 1 + 2);
							ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index] |= w;
						}
					}
					else if (input_list->head && strcmp(input_list->head->lexeme, "ignore") == 0)
					{
						//#pragma CAKE diagnostic ignore "-Wenum-compare"

						match_token_level(&r, input_list, TK_IDENTIFIER, level, ctx);//ignore
						skip_blanks_level(ctx, &r, input_list, level);

						if (input_list->head && input_list->head->type == TK_STRING_LITERAL)
						{
							enum warning  w = get_warning_flag(input_list->head->lexeme + 1 + 2);
							ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index] &= ~w;
						}
					}
				}
			}

			struct token_list r7 = pp_tokens_opt(ctx, input_list, level);
			token_list_append_list(&r, &r7);
			match_token_level(&r, input_list, TK_NEWLINE, level, ctx);
			token_list_destroy(&r7);
		}
	}
	catch
	{
	}

	return r;
}


static struct token_list non_directive(struct preprocessor_ctx* ctx, struct token_list* input_list, int level)
{
	/*
	  non-directive:
	  pp-tokens new-line
	 */
	struct token_list r = pp_tokens_opt(ctx, input_list, level);
	skip_blanks_level(ctx, &r, input_list, level);
	match_token_level(&r, input_list, TK_NEWLINE, level, ctx);
	return r;
}

static struct macro_argument_list collect_macro_arguments(struct preprocessor_ctx* ctx,
	struct macro* macro,
	struct token_list* input_list, int level)
{
	struct macro_argument_list macro_argument_list = { 0 };
	try
	{
		assert(input_list->head->type == TK_IDENTIFIER); //nome da macro
		const struct token* const macro_name_token = input_list->head;

		match_token_level(&macro_argument_list.tokens, input_list, TK_IDENTIFIER, level, ctx); //NOME DA MACRO
		if (!macro->is_function)
		{
			//se nao eh funcao so faz isso e retorna o nome da macro
			return macro_argument_list;
		}

		struct macro_parameter* p_current_parameter = macro->parameters;
		int count = 1;
		skip_blanks(ctx, &macro_argument_list.tokens, input_list);
		match_token_level(&macro_argument_list.tokens, input_list, '(', level, ctx);
		skip_blanks(ctx, &macro_argument_list.tokens, input_list);
		if (input_list->head->type == ')')
		{
			if (macro->parameters != NULL)
			{
				struct macro_argument* owner p_argument = calloc(1, sizeof(struct macro_argument));
				p_argument->name = strdup(p_current_parameter->name);
				argument_list_add(&macro_argument_list, p_argument);
			}
			match_token_level(&macro_argument_list.tokens, input_list, ')', level, ctx);
			return macro_argument_list;
		}
		struct macro_argument* owner p_argument = calloc(1, sizeof(struct macro_argument));
		p_argument->name = strdup(p_current_parameter->name);
		while (input_list->head != NULL)
		{
			if (input_list->head->type == '(')
			{
				count++;
				token_list_clone_and_add(&p_argument->tokens, input_list->head);
				match_token_level(&macro_argument_list.tokens, input_list, '(', level, ctx);
			}
			else if (input_list->head->type == ')')
			{
				count--;
				if (count == 0)
				{
					match_token_level(&macro_argument_list.tokens, input_list, ')', level, ctx);
					argument_list_add(&macro_argument_list, p_argument);
					p_argument = NULL; //MOVED

					p_current_parameter = p_current_parameter->next;

					if (p_current_parameter != NULL)
					{
						if (strcmp(p_current_parameter->name, "__VA_ARGS__") == 0)
						{
							//adicionamos este argumento como sendo vazio
							p_argument = calloc(1, sizeof(struct macro_argument));
							p_argument->name = strdup(p_current_parameter->name);
							argument_list_add(&macro_argument_list, p_argument);
							p_argument = NULL; //MOVED
						}
						else
						{
							preprocessor_set_error_with_token(C_TOO_FEW_ARGUMENTS_TO_FUNCTION_LIKE_MACRO, ctx, macro_name_token, "too few arguments provided to function-like macro invocation\n");
							throw;
						}
					}


					break;
				}
				else
				{
					token_list_clone_and_add(&p_argument->tokens, input_list->head);
					match_token_level(&macro_argument_list.tokens, input_list, ')', level, ctx);
				}
			}
			else if (count == 1 && input_list->head->type == ',')
			{
				if (strcmp(p_current_parameter->name, "__VA_ARGS__") == 0)
				{
					token_list_clone_and_add(&p_argument->tokens, input_list->head);
					match_token_level(&macro_argument_list.tokens, input_list, ',', level, ctx);
				}
				else //if (count == 1)
				{
					match_token_level(&macro_argument_list.tokens, input_list, ',', level, ctx);
					argument_list_add(&macro_argument_list, p_argument);
					p_argument = NULL; /*MOVED*/

					p_argument = calloc(1, sizeof(struct macro_argument));
					p_current_parameter = p_current_parameter->next;
					if (p_current_parameter == NULL)
					{
						preprocessor_set_error_with_token(C_MACRO_INVALID_ARG, ctx, macro_name_token, "invalid args");
						macro_argument_delete(p_argument);
						p_argument = NULL; //DELETED
						throw;
					}
					p_argument->name = strdup(p_current_parameter->name);
				}
			}
			else
			{
				token_list_clone_and_add(&p_argument->tokens, input_list->head);
				prematch_level(&macro_argument_list.tokens, input_list, level);
				//token_list_add(&list, token_list_pop_front(input_list));
			}
		}

		assert(p_argument == NULL);
	}
	catch
	{
	}

	return macro_argument_list;
}

struct token_list expand_macro(struct preprocessor_ctx* ctx, struct macro_expanded* p_list, struct macro* macro, struct macro_argument_list* arguments, int level);
struct token_list replacement_list_reexamination(struct preprocessor_ctx* ctx, struct macro_expanded* p_list, struct token_list* oldlist, int level);


struct token_list macro_copy_replacement_list(struct preprocessor_ctx* ctx, struct macro* macro);

/*#define hash_hash # ## #
#define mkstr(a) # a
#define in_between(a) mkstr(a)
#define join(c, d) in_between(c hash_hash d)

hash_hash

join(x, y)
*/
static struct token_list concatenate(struct preprocessor_ctx* ctx, struct token_list* input_list)
{
	//printf("input="); print_list(input_list);

	struct token_list  r = { 0 };
	//todo juntar tokens mesmo objet macro
	//struct token* p_previousNonBlank = 0;
	while (input_list->head)
	{
		//printf("r="); print_list(&r);
		//printf("input="); print_list(input_list);

		assert(!(input_list->head->flags & TK_FLAG_HAS_NEWLINE_BEFORE));
		if (input_list->head->type == '##')
		{
			if (r.tail == NULL)
			{
				preprocessor_set_error_with_token(C_MISSING_MACRO_ARGUMENT, ctx, input_list->head, "missing macro argument (should be checked before)");
				break;
			}
			/*
			* arranca ## do input (sem adicionar)
			*/
			token_list_pop_front(input_list);

			struct osstream ss = { 0 };

			/*
			*  Faz uma string com o fim r + começo do input (## ja foi removido)
			*/
			if (r.tail->lexeme[0] != '\0')
				ss_fprintf(&ss, "%s", r.tail->lexeme);

			if (input_list->head && input_list->head->lexeme[0] != '\0')
				ss_fprintf(&ss, "%s", input_list->head->lexeme);

			//copiar o level para gerar um novo igual
			int level = input_list->head ? input_list->head->level : 0;

			/*
			* Já paga do input o token usado na concatenacao
			*/
			token_list_pop_front(input_list);

			/*
			* Faz um novo token com a string montada
			*/
			struct tokenizer_ctx tctx = { 0 };
			struct token_list newlist = tokenizer(&tctx, ss.c_str, NULL, level, TK_FLAG_NONE);

			if (newlist.head)
			{
				newlist.head->flags = r.tail->flags;
			}
			else
			{
				struct token* owner p_new_token = calloc(1, sizeof * p_new_token);
				p_new_token->lexeme = strdup("");
				p_new_token->type = TK_PLACEMARKER;
				token_list_add(&newlist, p_new_token);
				newlist.head->flags = r.tail->flags;
			}
			/*
			* Arranca o anterior do r que foi usado para formar string
			*/
			token_list_pop_back(&r);

			/*adiciona novo token no fim do r*/
			token_list_append_list(&r, &newlist);

			ss_close(&ss);

			token_list_destroy(&newlist);

			if (input_list->head == NULL)
				break;
		}
		else
		{
			prematch(&r, input_list);
		}
	}
	return r;
}

/*
  check if the argument list that corresponds to a trailing ...
  of the parameter list is present and has a non-empty substitution.
*/
static bool has_argument_list_empty_substitution(struct preprocessor_ctx* ctx,
	struct macro_expanded* p_list,
	struct macro_argument_list* p_macro_argument_list)
{
	if (p_macro_argument_list->head == NULL)
		return true;

	struct macro_argument* p_va_args_argument =
		find_macro_argument_by_name(p_macro_argument_list, "__VA_ARGS__");

	if (p_va_args_argument)
	{
		if (p_va_args_argument->tokens.head == NULL)
			return true;

		struct token_list argumentlist = copy_argument_list(p_va_args_argument);

		struct token_list r4 = replacement_list_reexamination(ctx, p_list, &argumentlist, 0);
		const bool results_in_empty_substituition = (r4.head == NULL || r4.head->type == TK_PLACEMARKER);
		token_list_destroy(&r4);

		token_list_destroy(&argumentlist);

		return results_in_empty_substituition;
	}

	return false;
}

static struct token_list replace_macro_arguments(struct preprocessor_ctx* ctx, struct macro_expanded* p_list, struct token_list* input_list, struct macro_argument_list* arguments)
{
	struct token_list r = { 0 };

	try
	{
		while (input_list->head)
		{
			assert(!(input_list->head->flags & TK_FLAG_HAS_NEWLINE_BEFORE));
			assert(!token_is_blank(input_list->head));
			assert(r.tail == NULL || !token_is_blank(r.tail));
			struct macro_argument* p_argument = NULL;
			if (input_list->head->type == TK_IDENTIFIER)
			{
				if (strcmp(input_list->head->lexeme, "__VA_OPT__") == 0)
				{
					token_list_pop_front(input_list); //pop __VA_OPT__
					token_list_pop_front(input_list); //pop (
					int parenteses_count = 1;         //we already have one

					const bool discard_va_opt =
						has_argument_list_empty_substitution(ctx, p_list, arguments);

					if (discard_va_opt)
					{
						//discard all tokens __VA_OPT__(...)
						while (input_list->head)
						{
							if (input_list->head->type == '(') parenteses_count++;
							else if (input_list->head->type == ')') parenteses_count--;
							token_list_pop_front(input_list);
							if (parenteses_count == 0)
								break;
						}
					}
					else
					{
						// Search and remove the last balanced ')'
						struct token* p_token = input_list->head;
						for (; p_token; p_token = p_token->next)
						{
							if (p_token->type == '(') parenteses_count++;
							else if (p_token->type == ')') parenteses_count--;

							if (parenteses_count == 0)
								break;
						}
						token_list_remove(input_list, p_token, p_token);
					}
					continue;
				}

				p_argument = find_macro_argument_by_name(arguments, input_list->head->lexeme);
			}

			if (p_argument)
			{
				if (r.tail != NULL && r.tail->type == '#')
				{

					/*
					  deleta nome parametro da lista
					  antes copia flags dele
					*/

					const enum token_flags flags = input_list->head->flags;
					token_list_pop_front(input_list);

					//deleta tambem # do fim
					while (token_is_blank(r.tail))
					{
						token_list_pop_back(&r);
					}
					token_list_pop_back(&r);

					///----------------------------
					//transforma tudo em string e coloca no resultado
					struct token_list argumentlist = copy_argument_list(p_argument);
					char* owner s = token_list_join_tokens(&argumentlist, true);
					if (s == NULL)
					{
						token_list_destroy(&argumentlist);
						preprocessor_set_error_with_token(C_UNEXPECTED, ctx, input_list->head, "unexpected");
						throw;
					}
					struct token* owner p_new_token = calloc(1, sizeof * p_new_token);
					p_new_token->lexeme = s;
					p_new_token->type = TK_STRING_LITERAL;
					p_new_token->flags = flags;
					token_list_add(&r, p_new_token);
					token_list_destroy(&argumentlist);
					continue;
				}
				else if (r.tail != NULL && r.tail->type == '##')
				{
					//estou parametro e anterior era ##
					token_list_pop_front(input_list);
					struct token_list argumentlist = copy_argument_list(p_argument);
					token_list_append_list(&r, &argumentlist);
					token_list_destroy(&argumentlist);
				}
				else if (input_list->head->next && input_list->head->next->type == '##')
				{
					//estou no parametro e o da frente eh ##
					int flags = input_list->head->flags;
					//tira nome parametro a lista
					token_list_pop_front(input_list);
					//passa tudo p resultado
					struct token_list argumentlist = copy_argument_list(p_argument);
					if (argumentlist.head != NULL)
					{
						argumentlist.head->flags = flags;
					}
					token_list_append_list(&r, &argumentlist);
					// ja passa o ## tambem
					prematch(&r, input_list);
					token_list_destroy(&argumentlist);
				}
				else
				{
					int flags = input_list->head->flags;
					//remove nome parametro do input
					token_list_pop_front(input_list);
					//coloca a expansao no resultado
					struct token_list argumentlist = copy_argument_list(p_argument);
					if (argumentlist.head)
					{
						//copia os flags do identificador
						argumentlist.head->flags = flags;
					}
					/*depois reescan vai corrigir level*/
					struct token_list r4 = replacement_list_reexamination(ctx, p_list, &argumentlist, 0);
					token_list_append_list(&r, &r4);
					token_list_destroy(&r4);
					if (ctx->n_errors > 0)
					{
						token_list_destroy(&argumentlist);
						throw;
					}
					token_list_destroy(&argumentlist);
				}
			}
			else
			{
				prematch(&r, input_list);
			}
		}
	}
	catch
	{
	}


	return r;
}

struct token_list concatenate(struct preprocessor_ctx* ctx, struct token_list* input_list);

static bool macro_already_expanded(struct macro_expanded* p_list, const char* name)
{
	struct macro_expanded* p_item = p_list;
	while (p_item)
	{
		if (strcmp(name, p_item->name) == 0)
		{
			return true;
		}
		p_item = p_item->p_previous;
	}
	return false;
}

struct token_list replacement_list_reexamination(struct preprocessor_ctx* ctx, struct macro_expanded* p_list, struct token_list* oldlist, int level)
{
	struct token_list r = { 0 };
	try
	{
		//replacement_list_reexamination
		/*
		For both object-like and function-like macro invocations, before the replacement list is reexamined
		for more macro names to replace, each instance of a ## preprocessing token in the replacement list
		(not from an argument) is deleted and the preceding preprocessing token is concatenated with the
		following preprocessing token.
		*/
		struct token_list new_list = concatenate(ctx, oldlist);
		while (new_list.head != NULL)
		{
			assert(!(new_list.head->flags & TK_FLAG_HAS_NEWLINE_BEFORE));
			assert(!token_is_blank(new_list.head));
			struct macro* macro = NULL;
			if (new_list.head->type == TK_IDENTIFIER)
			{
				macro = find_macro(ctx, new_list.head->lexeme);
				if (macro &&
					macro->is_function &&
					!preprocessor_token_ahead_is(new_list.head, '('))
				{
					macro = NULL;
				}

				if (macro && macro_already_expanded(p_list, new_list.head->lexeme))
				{
					new_list.head->type = TK_IDENTIFIER_RECURSIVE_MACRO;
					macro = NULL;
				}


				if (ctx->conditional_inclusion)
				{
					/*
					 Quando estamos expandindo em condinonal inclusion o defined macro ou defined (macro)
					 não é expandido e é considerado depois
					*/
					if (r.tail &&
						r.tail->type == TK_IDENTIFIER &&
						strcmp(r.tail->lexeme, "defined") == 0)
					{
						macro = NULL;
					}
					else if (r.tail &&
						r.tail->type == '(')
					{
						struct token* previous = r.tail->prev;
						if (previous != NULL &&
							previous->type == TK_IDENTIFIER &&
							strcmp(previous->lexeme, "defined") == 0)
						{
							macro = NULL;
						}
					}
				}

			}
			if (macro)
			{
				int flags = new_list.head->flags;
				struct macro_argument_list arguments = collect_macro_arguments(ctx, macro, &new_list, level);
				if (ctx->n_errors > 0)
				{
					macro_argument_list_destroy(&arguments);
					token_list_destroy(&new_list);
					throw;
				}


				struct token_list r3 = expand_macro(ctx, p_list, macro, &arguments, level);
				if (ctx->n_errors > 0)
				{
					token_list_destroy(&new_list);
					token_list_destroy(&r3);
					macro_argument_list_destroy(&arguments);
					throw;
				}

				if (r3.head)
				{
					r3.head->flags = flags;
				}
				token_list_append_list_at_beginning(&new_list, &r3);
				macro_argument_list_destroy(&arguments);
				token_list_destroy(&r3);
			}
			else
			{
				/*
				aqui eh um bom lugar para setar o level e macro flags
				poq sempre tem a re scann da macro no fim
				*/
				new_list.head->level = level;
				new_list.head->flags |= TK_FLAG_MACRO_EXPANDED;
				assert(!(new_list.head->flags & TK_FLAG_HAS_NEWLINE_BEFORE));
				prematch(&r, &new_list); //nao era macro
			}
		}
	}
	catch
	{
	}

	return r;
}

/*
  Faz a comparação ignorando a continuacao da linha
  TODO fazer uma revisão geral aonde se usa strcmp em lexeme
  e trocar por esta.
*/
int lexeme_cmp(const char* s1, const char* s2)
{
	while (*s1 && *s2)
	{

		while ((s1[0] == '\\' && s1[1] == '\n'))
		{
			s1++;
			s1++;
		}


		while (s2[0] == '\\' && s2[1] == '\n')
		{
			s2++;
			s2++;
		}

		if (*s1 != *s2)
			break;

		s1++;
		s2++;
	}

	while ((s1[0] == '\\' && s1[1] == '\n'))
	{
		s1++;
		s1++;
	}


	while (s2[0] == '\\' && s2[1] == '\n')
	{
		s2++;
		s2++;
	}

	return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

void remove_line_continuation(char* s)
{
	char* pread = s;
	char* pwrite = s;
	while (*pread)
	{
		if (pread[0] == '\\' && pread[1] == '\n')
		{
			pread++;
			pread++;
		}
		else
		{
			*pwrite = *pread;
			pread++;
			pwrite++;
		}
	}
	*pwrite = *pread;
}

struct token_list  copy_replacement_list(struct token_list* list)
{
	//Faz uma copia dos tokens fazendo um trim no iniico e fim
	//qualquer espaco coments etcc vira um unico  espaco
	struct token_list r = { 0 };
	struct token* current = list->head;
	//sai de cima de todos brancos iniciais
	while (current && token_is_blank(current))
	{
		current = current->next;
	}
	//remover flag de espaco antes se tiver
	bool is_first = true;

	for (; current;)
	{
		if (current && token_is_blank(current))
		{
			if (current == list->tail)
				break;

			current = current->next;
			continue;
		}
		struct token* token_added = token_list_clone_and_add(&r, current);
		if (token_added->flags & TK_FLAG_HAS_NEWLINE_BEFORE)
		{
			token_added->flags = token_added->flags & ~TK_FLAG_HAS_NEWLINE_BEFORE;
			token_added->flags |= TK_FLAG_HAS_SPACE_BEFORE;
		}
		if (is_first)
		{
			token_added->flags = token_added->flags & ~TK_FLAG_HAS_SPACE_BEFORE;
			token_added->flags = token_added->flags & ~TK_FLAG_HAS_NEWLINE_BEFORE;
			is_first = false;
		}
		remove_line_continuation(token_added->lexeme);

		if (current == list->tail)
			break;
		current = current->next;

	}
	return r;
}



struct token_list macro_copy_replacement_list(struct preprocessor_ctx* ctx, struct macro* macro)
{
	/*macros de conteudo dinamico*/
	if (strcmp(macro->name, "__LINE__") == 0)
	{
		struct tokenizer_ctx tctx = { 0 };

		struct token_list r = tokenizer(&tctx, "1", "", 0, TK_FLAG_NONE);
		token_list_pop_front(&r);
		r.head->flags = 0;
		return r;
	}
	else if (strcmp(macro->name, "__FILE__") == 0)
	{
		struct tokenizer_ctx tctx = { 0 };


		struct token_list r = tokenizer(&tctx, "\"file\"", "", 0, TK_FLAG_NONE);
		token_list_pop_front(&r);
		r.head->flags = 0;
		return r;
	}
	else if (strcmp(macro->name, "__COUNT__") == 0)
	{
		assert(false);//TODO
		struct tokenizer_ctx tctx = { 0 };
		struct token_list r = tokenizer(&tctx, "1", "", 0, TK_FLAG_NONE);
		token_list_pop_front(&r);
		r.head->flags = 0;
		return r;
	}

	return copy_replacement_list(&macro->replacement_list);
}

void print_literal2(const char* s);



/*
	Se p for macro expande completamente e retorna o ponteiro
	para o primeiro item da expansao
	caso contrario, se p nao for macro, retorna null.
*/
struct token_list expand_macro(struct preprocessor_ctx* ctx, struct macro_expanded* list, struct macro* macro, struct macro_argument_list* arguments, int level)
{
	macro->usage++;

	//printf("\nexpanding ");
	//print_macro(macro);
	//print_macro_arguments(arguments);
	//printf("\n");
	struct token_list r = { 0 };
	try
	{
		assert(!macro_already_expanded(list, macro->name));
		struct macro_expanded macro_expanded = { 0 };
		macro_expanded.name = macro->name;
		macro_expanded.p_previous = list;
		if (macro->is_function)
		{
			struct token_list copy = macro_copy_replacement_list(ctx, macro);
			struct token_list copy2 = replace_macro_arguments(ctx, &macro_expanded, &copy, arguments);
			struct token_list r2 = replacement_list_reexamination(ctx, &macro_expanded, &copy2, level);

			token_list_append_list(&r, &r2);

			token_list_destroy(&copy);
			token_list_destroy(&copy2);
			token_list_destroy(&r2);

			if (ctx->n_errors > 0) throw;
		}
		else
		{
			struct token_list copy = macro_copy_replacement_list(ctx, macro);
			struct token_list r3 = replacement_list_reexamination(ctx, &macro_expanded, &copy, level);
			if (ctx->n_errors > 0)
			{
				token_list_destroy(&copy);
				token_list_destroy(&r3);
				throw;
			}

			token_list_append_list(&r, &r3);
			token_list_destroy(&copy);
			token_list_destroy(&r3);
		}
	}
	catch
	{
	}

	//printf("result=");
	//print_list(&r);
	return r;
}
void print_token(struct token* p_token);

static struct token_list text_line(struct preprocessor_ctx* ctx, struct token_list* input_list, bool is_active, int level)
{
	/*
		  text-line:
		  pp-tokens_opt new-line
	*/
	struct token_list r = { 0 };

	try
	{
		while (input_list->head &&
			input_list->head->type != TK_PREPROCESSOR_LINE)
		{
			struct macro* macro = NULL;
			struct token* start_token = input_list->head;

			if (is_active && input_list->head->type == TK_IDENTIFIER)
			{
				macro = find_macro(ctx, input_list->head->lexeme);
				if (macro &&
					macro->is_function &&
					!preprocessor_token_ahead_is(input_list->head, '('))
				{
					macro = NULL;
				}

				if (ctx->conditional_inclusion)
				{
					/*
					 Quando estamos expandindo em condinonal inclusion o defined macro ou defined (macro)
					 não é expandido e é considerado depois
					*/

					if (r.tail &&
						r.tail->type == TK_IDENTIFIER &&
						strcmp(r.tail->lexeme, "defined") == 0)
					{
						macro = NULL;
					}
					else if (r.tail &&
						r.tail->type == '(')
					{
						struct token* previous = r.tail->prev;
						if (previous != NULL &&
							previous->type == TK_IDENTIFIER &&
							strcmp(previous->lexeme, "defined") == 0)
						{
							macro = NULL;
						}
					}
				}
			}
			if (macro)
			{
#ifdef _WIN32
				if (input_list->head->token_origin)
				{
					//char line[1000] = { 0 };
					//snprintf(line, sizeof line, "%s(%d,%d):\n", input_list->head->token_origin->lexeme, input_list->head->line, input_list->head->col);
					//OutputDebugStringA(line);
				}
#endif

				//efeito tetris
				//#define f(a) a
				//#define F g
				//F(1)
				//quero deixar F(g) na saida.
				//e toda parte de dentro escondida no caso  1
				//F(1)`a` acho que vou imprimir desta forma ou so fundo diferente
				//
				enum token_flags flags = input_list->head->flags;
				struct macro_argument_list arguments = collect_macro_arguments(ctx, macro, input_list, level);
				if (ctx->n_errors > 0)
				{
					macro_argument_list_destroy(&arguments);
					throw;
				}


				struct token_list start_macro = expand_macro(ctx, NULL, macro, &arguments, level);
				if (start_macro.head)
				{
					start_macro.head->flags |= flags;
				}

				if (macro->expand)
				{
					//Esconde a macro e os argumentos
					for (struct token* current = arguments.tokens.head;
						current != arguments.tokens.tail->next;
						current = current->next)
					{
						current->flags |= TK_FLAG_HIDE;
					}

					//mostra a expansao da macro
					/*teste de expandir so algumas macros*/
					for (struct token* current = start_macro.head;
						current != start_macro.tail->next;
						current = current->next)
					{
						current->flags &= ~(TK_FLAG_MACRO_EXPANDED | TK_FLAG_SLICED | TK_FLAG_LINE_CONTINUATION);
					}
				}

				//seta nos tokens expandidos da onde eles vieram
				token_list_set_file(&start_macro, start_token->token_origin, start_token->line, start_token->col);

				token_list_append_list_at_beginning(input_list, &start_macro);

				if (ctx->flags & PREPROCESSOR_CTX_FLAGS_ONLY_FINAL)
				{
				}
				else
				{
					if (level == 0 || INCLUDE_ALL)
						token_list_append_list(&r, &arguments.tokens);
				}

				//print_tokens(r.head);
				while (macro)
				{
					macro = NULL;
					if (input_list->head->type == TK_IDENTIFIER)
					{
						macro = find_macro(ctx, input_list->head->lexeme);
						if (macro && macro->is_function &&
							!preprocessor_token_ahead_is(input_list->head, '('))
						{
							macro = NULL;
						}
						if (macro)
						{
							// printf("tetris\n");
							int flags2 = input_list->head->flags;
							struct macro_argument_list arguments2 = collect_macro_arguments(ctx, macro, input_list, level);
							if (ctx->n_errors > 0)
							{
								macro_argument_list_destroy(&arguments2);
								macro_argument_list_destroy(&arguments);
								token_list_destroy(&start_macro);
								throw;
							}

							if (ctx->flags & PREPROCESSOR_CTX_FLAGS_ONLY_FINAL)
							{
							}
							else
							{
								if (level == 0 || INCLUDE_ALL)
								{
									token_list_append_list(&r, &arguments2.tokens);
								}
							}


							struct token_list r3 = expand_macro(ctx, NULL, macro, &arguments2, level);
							if (ctx->n_errors > 0)
							{
								macro_argument_list_destroy(&arguments2);
								token_list_destroy(&r3);
								macro_argument_list_destroy(&arguments);
								token_list_destroy(&start_macro);
								throw;
							}

							//seta nos tokens expandidos da onde eles vieram
							token_list_set_file(&r3, start_token->token_origin, start_token->line, start_token->col);

							if (r3.head)
							{
								r3.head->flags = flags2;
							}
							token_list_append_list_at_beginning(input_list, &r3);
							macro_argument_list_destroy(&arguments2);
							token_list_destroy(&r3);
						}
					}
				}

				macro_argument_list_destroy(&arguments);
				token_list_destroy(&start_macro);

				continue;
				//saiu tetris...
				//entao tudo foi expandido desde a primeiroa
			}
			else
			{
				if (input_list->head->flags & TK_FLAG_LINE_CONTINUATION &&
					!(input_list->head->flags & TK_FLAG_MACRO_EXPANDED)
					)
				{
					/*
					   The only place were line-continuation are really necessary is
					   inside preprocessor directives.
					   Here we are inside text-line so we can send a info that
					   here is optional.
					*/
					if (input_list->head->type == TK_STRING_LITERAL)
					{
						if (preprocessor_is_warning_enabled(ctx, W_STRING_SLICED))
							preprocessor_set_info_with_token(ctx, input_list->head, "you can use \"adjacent\" \"strings\"");
					}
					else if (input_list->head->type == TK_LINE_COMMENT)
						preprocessor_set_warning_with_token(W_COMMENT, ctx, input_list->head, "multi-line //comment");
					else
						preprocessor_set_warning_with_token(W_LINE_SLICING, ctx, input_list->head, "unnecessary line-slicing");
				}

				bool blanks = token_is_blank(input_list->head) || input_list->head->type == TK_NEWLINE;
				bool is_final = is_active && !is_never_final(input_list->head->type);

				if (ctx->flags & PREPROCESSOR_CTX_FLAGS_ONLY_FINAL)
				{
					if (is_final)
					{
						prematch(&r, input_list);
						r.tail->flags |= TK_FLAG_FINAL;
						//token_promote(r.tail);
					}
					else
					{
						token_list_pop_front(input_list);//todo deletar
					}
				}
				else
				{
					if (blanks)
					{
						if (level == 0 || INCLUDE_ALL)
						{
							prematch(&r, input_list);
						}
						else
							token_list_pop_front(input_list);//todo deletar
					}
					else
					{
						if (level == 0 || INCLUDE_ALL)
						{
							prematch(&r, input_list);
							if (is_final)
							{
								// if (strcmp(r.tail->lexeme, "_CRT_STDIO_INLINE") == 0)
								 //{
								   //  printf("");
								 //}

								r.tail->flags |= TK_FLAG_FINAL;
								//token_promote(r.tail);

							}
						}
						else
						{
							if (is_final)
							{
								//if (strcmp(r.tail->lexeme, "_CRT_STDIO_INLINE") == 0)
								//{
								 //   printf("");
								//}

								prematch(&r, input_list);
								r.tail->flags |= TK_FLAG_FINAL;
								//token_promote(r.tail);
							}
							else
							{
								token_list_pop_front(input_list);//todo deletar
							}
						}
					}
				}


			}
		}
	}
	catch
	{
	}

	return r;
}

struct token_list group_part(struct preprocessor_ctx* ctx, struct token_list* input_list, bool is_active, int level)
{
	/*
	group-part:
	 if-section
	 control-line
	 text-line
	 # non-directive
	*/

	if (input_list->head->type == TK_PREPROCESSOR_LINE)
	{
		if (preprocessor_token_ahead_is_identifier(input_list->head, "if") ||
			preprocessor_token_ahead_is_identifier(input_list->head, "ifdef") ||
			preprocessor_token_ahead_is_identifier(input_list->head, "ifndef"))
		{
			return if_section(ctx, input_list, is_active, level);
		}
		else if (preprocessor_token_ahead_is_identifier(input_list->head, "include") ||
			preprocessor_token_ahead_is_identifier(input_list->head, "embed") ||
			preprocessor_token_ahead_is_identifier(input_list->head, "define") ||
			preprocessor_token_ahead_is_identifier(input_list->head, "undef") ||
			preprocessor_token_ahead_is_identifier(input_list->head, "warning") ||
			preprocessor_token_ahead_is_identifier(input_list->head, "line") ||
			preprocessor_token_ahead_is_identifier(input_list->head, "error") ||
			preprocessor_token_ahead_is_identifier(input_list->head, "pragma"))
		{
			return control_line(ctx, input_list, is_active, level);
		}
		else
		{
			//aqui vou consumir o # dentro para ficar simetrico
			return non_directive(ctx, input_list, level);
		}
	}
	return text_line(ctx, input_list, is_active, level);
}


struct token_list preprocessor(struct preprocessor_ctx* ctx, struct token_list* input_list, int level)
{
	struct token_list r = { 0 };
	if (input_list->head == NULL)
	{
		return r;
	}

	if (input_list->head->type == TK_BEGIN_OF_FILE)
	{
		prematch_level(&r, input_list, 1); //sempre coloca
	}

	struct token_list g = group_opt(ctx, input_list, true /*active*/, level);
	token_list_append_list(&r, &g);
	token_list_destroy(&g);
	return r;
}


static void mark_macros_as_used(struct owner_hash_map* map)
{
	/*
	 *  Objetivo era alertar macros nao usadas...
	 */

	if (map->table != NULL)
	{
		for (int i = 0; i < map->capacity; i++)
		{
			struct owner_map_entry* pentry = map->table[i];

			while (pentry != NULL)
			{
				struct macro* macro = pentry->p;
				macro->usage = 1;
				pentry = pentry->next;
			}
		}
	}
}

void check_unused_macros(struct owner_hash_map* map)
{
	/*
	 *  Objetivo era alertar macros nao usadas...
	 */

	if (map->table != NULL)
	{
		for (int i = 0; i < map->capacity; i++)
		{
			struct owner_map_entry* pentry = map->table[i];

			while (pentry != NULL)
			{
				struct macro* macro = pentry->p;
				if (macro->usage == 0)
				{
					//TODO adicionar conceito meu codigo , codigo de outros nao vou colocar erro
					printf("%s not used\n", macro->name);
				}
				pentry = pentry->next;
			}
		}
	}
}

void include_config_header(struct preprocessor_ctx* ctx)
{
	char executable_path[MAX_PATH] = { 0 };
	get_self_path(executable_path, sizeof(executable_path));
	dirname(executable_path);
	char path[MAX_PATH] = { 0 };
	snprintf(path, sizeof path, "%s/cakeconfig.h", executable_path);
	/*
	* windows
	 echo %INCLUDE%
	 Linux
	 echo | gcc -E -Wp,-v -
	*/

	char* owner str = read_file(path);


	const enum warning w =
		ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index];



	struct tokenizer_ctx tctx = { 0 };
	struct token_list l = tokenizer(&tctx, str, "standard macros inclusion", 0, TK_FLAG_NONE);
	struct token_list l10 = preprocessor(ctx, &l, 0);
	mark_macros_as_used(&ctx->macros);
	token_list_destroy(&l);
	free(str);
	token_list_destroy(&l10);

	/*restore*/
	ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index] = w;
}

void add_standard_macros(struct preprocessor_ctx* ctx)
{
	/*
	  This command prints all macros used by gcc
	  echo | gcc -dM -E -
	*/
	const enum warning w =
		ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index];

	/*we dont want warnings here*/
	ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index] = W_NONE;

	static char mon[][4] = {
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
	};

	time_t now = time(NULL);
	struct tm* tm = localtime(&now);

	struct tokenizer_ctx tctx = { 0 };


	char datastr[100] = { 0 };
	snprintf(datastr, sizeof datastr, "#define __DATE__ \"%s %2d %d\"\n", mon[tm->tm_mon], tm->tm_mday, tm->tm_year + 1900);
	struct token_list l1 = tokenizer(&tctx, datastr, "__DATE__ macro inclusion", 0, TK_FLAG_NONE);
	struct token_list tl1 = preprocessor(ctx, &l1, 0);

	token_list_destroy(&tl1);
	token_list_destroy(&l1);

	char timestr[100] = { 0 };
	snprintf(timestr, sizeof timestr, "#define __TIME__ \"%02d:%02d:%02d\"\n", tm->tm_hour, tm->tm_min, tm->tm_sec);
	struct token_list l2 = tokenizer(&tctx, timestr, "__TIME__ macro inclusion", 0, TK_FLAG_NONE);
	struct token_list tl2 = preprocessor(ctx, &l2, 0);

	token_list_destroy(&tl2);
	token_list_destroy(&l2);


	/*
	  Some macros are dynamic like __LINE__ they are replaced  at
	  macro_copy_replacement_list but they need to be registered here.
	*/

	const char* pre_defined_macros_text =
		"#define __CAKE__ 202311L\n"
		"#define __STDC_VERSION__ 202311L\n"
		"#define __FILE__ \"__FILE__\"\n"
		"#define __LINE__ 0\n"
		"#define __COUNT__ 0\n"
		"#define _CONSOLE\n"
		"#define __STDC_OWNERSHIP__\n"

#ifdef WIN32

		//see
		//https://learn.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=msvc-170

#ifdef _WIN32
		"#define _WIN32 " TOSTRING(_WIN32) "\n"
#endif

#ifdef _WIN64 
		"#define _WIN64 " TOSTRING(_WIN64) "\n"
#endif

		"#define _INTEGRAL_MAX_BITS " TOSTRING(_INTEGRAL_MAX_BITS) "\n" /*Use of __int64 should be conditional on the predefined macro _INTEGRAL_MAX_BITS*/
		"#define _MSC_EXTENSIONS\n"
		"#define _MSC_VER " TOSTRING(_MSC_VER) "\n"
		"#define _M_IX86 "  TOSTRING(_M_IX86) "\n"
		"#define __fastcall\n"
		"#define __stdcall\n"
		"#define __cdecl\n"
		"#define __pragma(a)\n"
		"#define __declspec(a)\n"
		"#define __crt_va_start(X) \n"
		"#define __builtin_offsetof(type, member) 0\n"; //como nao defini msver ele pensa que eh gcc aqui

#endif

#ifdef __linux__

	//https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html
		/*some gcc stuff need to parse linux headers*/
	"#define __linux__\n"
		"#define __builtin_va_list\n"
		"#define __builtin_va_start(a, b)\n"
		"#define __builtin_va_end(a)\n"
		"#define __builtin_va_arg(a, b)\n"
		"#define __builtin_va_copy(a, b)\n"

		"#define __CHAR_BIT__ " TOSTRING(__CHAR_BIT__) "\n"
		"#define __SIZE_TYPE__ " TOSTRING(__SIZE_TYPE__) "\n"
		"#define __PTRDIFF_TYPE__ " TOSTRING(__PTRDIFF_TYPE__) "\n"
		"#define __WCHAR_TYPE__ " TOSTRING(__WCHAR_TYPE__) "\n"
		"#define __WINT_TYPE__ " TOSTRING(__WINT_TYPE__) "\n"
		"#define __INTMAX_TYPE__ " TOSTRING(__INTMAX_TYPE__) "\n"
		"#define __UINTMAX_TYPE__ " TOSTRING(__UINTMAX_TYPE__) "\n"
		"#define __SIG_ATOMIC_TYPE__ " TOSTRING(__SIG_ATOMIC_TYPE__) "\n"
		"#define __INT8_TYPE__ " TOSTRING(__INT8_TYPE__) "\n"
		"#define __INT16_TYPE__ " TOSTRING(__INT16_TYPE__) "\n"
		"#define __INT32_TYPE__ " TOSTRING(__INT32_TYPE__) "\n"
		"#define __INT64_TYPE__ " TOSTRING(__INT64_TYPE__) "\n"
		"#define __UINT8_TYPE__ " TOSTRING(__UINT8_TYPE__) "\n"
		"#define __UINT16_TYPE__ " TOSTRING(__UINT16_TYPE__) "\n"
		"#define __UINT32_TYPE__ " TOSTRING(__UINT32_TYPE__) "\n"
		"#define __UINT64_TYPE__ " TOSTRING(__UINT64_TYPE__) "\n"
		"#define __INT_LEAST8_TYPE__ " TOSTRING(__INT_LEAST8_TYPE__) "\n"
		"#define __INT_LEAST16_TYPE__ " TOSTRING(__INT_LEAST16_TYPE__) "\n"
		"#define __INT_LEAST32_TYPE__ " TOSTRING(__INT_LEAST32_TYPE__) "\n"
		"#define __INT_LEAST64_TYPE__ " TOSTRING(__INT_LEAST64_TYPE__) "\n"
		"#define __UINT_LEAST8_TYPE__ " TOSTRING(__UINT_LEAST8_TYPE__) "\n"
		"#define __UINT_LEAST16_TYPE__ " TOSTRING(__UINT_LEAST16_TYPE__) "\n"
		"#define __UINT_LEAST32_TYPE__ " TOSTRING(__UINT_LEAST32_TYPE__) "\n"
		"#define __UINT_LEAST64_TYPE__ " TOSTRING(__UINT_LEAST64_TYPE__) "\n"
		"#define __INT_FAST8_TYPE__ " TOSTRING(__INT_FAST8_TYPE__) "\n"
		"#define __INT_FAST16_TYPE__ " TOSTRING(__INT_FAST16_TYPE__) "\n"
		"#define __INT_FAST32_TYPE__ " TOSTRING(__INT_FAST32_TYPE__) "\n"
		"#define __INT_FAST64_TYPE__ " TOSTRING(__INT_FAST64_TYPE__) "\n"
		"#define __UINT_FAST8_TYPE__ " TOSTRING(__UINT_FAST8_TYPE__) "\n"
		"#define __UINT_FAST16_TYPE__ " TOSTRING(__UINT_FAST16_TYPE__) "\n"
		"#define __UINT_FAST32_TYPE__ " TOSTRING(__UINT_FAST32_TYPE__) "\n"
		"#define __UINT_FAST64_TYPE__ " TOSTRING(__UINT_FAST64_TYPE__) "\n"
		"#define __INTPTR_TYPE__ " TOSTRING(__INTPTR_TYPE__) "\n"
		"#define __UINTPTR_TYPE__ " TOSTRING(__UINTPTR_TYPE__) "\n"

		"#define __SCHAR_MAX__ " TOSTRING(__SCHAR_MAX__) "\n"
		"#define __WCHAR_MAX__ " TOSTRING(__WCHAR_MAX__) "\n"
		"#define __SHRT_MAX__ " TOSTRING(__SHRT_MAX__) "\n"
		"#define __INT_MAX__ " TOSTRING(__INT_MAX__) "\n"
		"#define __LONG_MAX__ " TOSTRING(__LONG_MAX__) "\n"
		"#define __LONG_LONG_MAX__ " TOSTRING(__LONG_LONG_MAX__) "\n"
		"#define __WINT_MAX__ " TOSTRING(__WINT_MAX__) "\n"
		"#define __SIZE_MAX__ " TOSTRING(__SIZE_MAX__) "\n"
		"#define __PTRDIFF_MAX__ " TOSTRING(__PTRDIFF_MAX__) "\n"
		"#define __INTMAX_MAX__ " TOSTRING(__INTMAX_MAX__) "\n"
		"#define __UINTMAX_MAX__ " TOSTRING(__UINTMAX_MAX__) "\n"
		"#define __SIG_ATOMIC_MAX__ " TOSTRING(__SIG_ATOMIC_MAX__) "\n"
		"#define __INT8_MAX__ " TOSTRING(__INT8_MAX__) "\n"
		"#define __INT16_MAX__ " TOSTRING(__INT16_MAX__) "\n"
		"#define __INT32_MAX__ " TOSTRING(__INT32_MAX__) "\n"
		"#define __INT64_MAX__ " TOSTRING(__INT64_MAX__) "\n"
		"#define __UINT8_MAX__ " TOSTRING(__UINT8_MAX__) "\n"
		"#define __UINT16_MAX__ " TOSTRING(__UINT16_MAX__) "\n"
		"#define __UINT32_MAX__ " TOSTRING(__UINT32_MAX__) "\n"
		"#define __UINT64_MAX__ " TOSTRING(__UINT64_MAX__) "\n"
		"#define __INT_LEAST8_MAX__ " TOSTRING(__INT_LEAST8_MAX__) "\n"
		"#define __INT_LEAST16_MAX__ " TOSTRING(__INT_LEAST16_MAX__) "\n"
		"#define __INT_LEAST32_MAX__ " TOSTRING(__INT_LEAST32_MAX__) "\n"
		"#define __INT_LEAST64_MAX__ " TOSTRING(__INT_LEAST64_MAX__) "\n"
		"#define __UINT_LEAST8_MAX__ " TOSTRING(__UINT_LEAST8_MAX__) "\n"
		"#define __UINT_LEAST16_MAX__ " TOSTRING(__UINT_LEAST16_MAX__) "\n"
		"#define __UINT_LEAST32_MAX__ " TOSTRING(__UINT_LEAST32_MAX__) "\n"
		"#define __UINT_LEAST64_MAX__ " TOSTRING(__UINT_LEAST64_MAX__) "\n"
		"#define __INT_FAST8_MAX__ " TOSTRING(__INT_FAST8_MAX__) "\n"
		"#define __INT_FAST16_MAX__ " TOSTRING(__INT_FAST16_MAX__) "\n"
		"#define __INT_FAST32_MAX__ " TOSTRING(__INT_FAST32_MAX__) "\n"
		"#define __INT_FAST64_MAX__ " TOSTRING(__INT_FAST64_MAX__) "\n"
		"#define __UINT_FAST8_MAX__ " TOSTRING(__UINT_FAST8_MAX__) "\n"
		"#define __UINT_FAST16_MAX__ " TOSTRING(__UINT_FAST16_MAX__) "\n"
		"#define __UINT_FAST32_MAX__ " TOSTRING(__UINT_FAST32_MAX__) "\n"
		"#define __UINT_FAST64_MAX__ " TOSTRING(__UINT_FAST64_MAX__) "\n"
		"#define __INTPTR_MAX__ " TOSTRING(__INTPTR_MAX__) "\n"
		"#define __UINTPTR_MAX__ " TOSTRING(__UINTPTR_MAX__) "\n"
		"#define __WCHAR_MIN__ " TOSTRING(__WCHAR_MIN__) "\n"
		"#define __WINT_MIN__ " TOSTRING(__WINT_MIN__) "\n"
		"#define __SIG_ATOMIC_MIN__ " TOSTRING(__SIG_ATOMIC_MIN__) "\n"

		"#define __INT8_C " TOSTRING(__SIG_ATOMIC_MIN__) "\n"
		"#define __INT16_C " TOSTRING(__INT16_C) "\n"
		"#define __INT32_C " TOSTRING(__INT32_C) "\n"
		"#define __INT64_C " TOSTRING(__INT64_C) "\n"
		"#define __UINT8_C " TOSTRING(__UINT8_C) "\n"
		"#define __UINT16_C " TOSTRING(__UINT16_C) "\n"
		"#define __UINT32_C " TOSTRING(__UINT32_C) "\n"
		"#define __UINT64_C " TOSTRING(__UINT64_C) "\n"
		"#define __INTMAX_C " TOSTRING(__INTMAX_C) "\n"
		"#define __UINTMAX_C " TOSTRING(__UINTMAX_C) "\n"

		"#define __SCHAR_WIDTH__ " TOSTRING(__SCHAR_WIDTH__) "\n"
		"#define __SHRT_WIDTH__ " TOSTRING(__SHRT_WIDTH__) "\n"
		"#define __INT_WIDTH__ " TOSTRING(__INT_WIDTH__) "\n"
		"#define __LONG_WIDTH__ " TOSTRING(__LONG_WIDTH__) "\n"
		"#define __LONG_LONG_WIDTH__ " TOSTRING(__LONG_LONG_WIDTH__) "\n"
		"#define __PTRDIFF_WIDTH__ " TOSTRING(__PTRDIFF_WIDTH__) "\n"
		"#define __SIG_ATOMIC_WIDTH__ " TOSTRING(__SIG_ATOMIC_WIDTH__) "\n"
		"#define __SIZE_WIDTH__ " TOSTRING(__SIZE_WIDTH__) "\n"
		"#define __WCHAR_WIDTH__ " TOSTRING(__WCHAR_WIDTH__) "\n"
		"#define __WINT_WIDTH__ " TOSTRING(__WINT_WIDTH__) "\n"
		"#define __INT_LEAST8_WIDTH__ " TOSTRING(__INT_LEAST8_WIDTH__) "\n"
		"#define __INT_LEAST16_WIDTH__ " TOSTRING(__INT_LEAST16_WIDTH__) "\n"
		"#define __INT_LEAST32_WIDTH__ " TOSTRING(__INT_LEAST32_WIDTH__) "\n"
		"#define __INT_LEAST64_WIDTH__ " TOSTRING(__INT_LEAST64_WIDTH__) "\n"
		"#define __INT_FAST8_WIDTH__ " TOSTRING(__INT_FAST8_WIDTH__) "\n"
		"#define __INT_FAST16_WIDTH__ " TOSTRING(__INT_FAST16_WIDTH__) "\n"
		"#define __INT_FAST32_WIDTH__ " TOSTRING(__INT_FAST32_WIDTH__) "\n"
		"#define __INT_FAST64_WIDTH__ " TOSTRING(__INT_FAST64_WIDTH__) "\n"
		"#define __INTPTR_WIDTH__ " TOSTRING(__INTPTR_WIDTH__) "\n"
		"#define __INTMAX_WIDTH__ " TOSTRING(__INTMAX_WIDTH__) "\n"


		"#define __SIZEOF_INT__ " TOSTRING(__SIZEOF_INT__) "\n"
		"#define __SIZEOF_LONG__ " TOSTRING(__SIZEOF_LONG__) "\n"
		"#define __SIZEOF_LONG_LONG__ " TOSTRING(__SIZEOF_LONG_LONG__) "\n"
		"#define __SIZEOF_SHORT__ " TOSTRING(__SIZEOF_SHORT__) "\n"
		"#define __SIZEOF_POINTER__ " TOSTRING(__SIZEOF_POINTER__) "\n"
		"#define __SIZEOF_FLOAT__ " TOSTRING(__SIZEOF_FLOAT__) "\n"
		"#define __SIZEOF_DOUBLE__ " TOSTRING(__SIZEOF_DOUBLE__) "\n"
		"#define __SIZEOF_LONG_DOUBLE__ " TOSTRING(__SIZEOF_LONG_DOUBLE__) "\n"
		"#define __SIZEOF_SIZE_T__ " TOSTRING(__SIZEOF_SIZE_T__) "\n"
		"#define __SIZEOF_WCHAR_T__ " TOSTRING(__SIZEOF_WCHAR_T__) "\n"
		"#define __SIZEOF_WINT_T__ " TOSTRING(__SIZEOF_WINT_T__) "\n"
		"#define __SIZEOF_PTRDIFF_T__ " TOSTRING(__SIZEOF_PTRDIFF_T__) "\n"
#endif
		"\n";

	struct token_list l = tokenizer(&tctx, pre_defined_macros_text, "standard macros inclusion", 0, TK_FLAG_NONE);
	struct token_list l10 = preprocessor(ctx, &l, 0);

	//nao quer ver warning de nao usado nestas macros padrao
	mark_macros_as_used(&ctx->macros);
	token_list_destroy(&l);
	token_list_destroy(&l10);

	/*restore*/
	ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index] = w;
}




const char* get_token_name(enum token_type tk)
{
	switch (tk)
	{
	case TK_NONE: return "NONE";
	case TK_NEWLINE: return "NEWLINE";
	case TK_WHITE_SPACE: return "SPACE";
	case TK_EXCLAMATION_MARK: return "TK_EXCLAMATION_MARK";
	case TK_QUOTATION_MARK: return "TK_QUOTATION_MARK";
	case TK_NUMBER_SIGN: return "TK_NUMBER_SIGN";
	case TK_DOLLAR_SIGN: return "TK_DOLLAR_SIGN";
	case TK_PERCENT_SIGN: return "TK_PERCENT_SIGN";
	case TK_AMPERSAND: return "TK_AMPERSAND";
	case TK_APOSTROPHE: return "TK_APOSTROPHE";
	case TK_LEFT_PARENTHESIS: return "TK_LEFT_PARENTHESIS";
	case TK_RIGHT_PARENTHESIS: return "TK_RIGHT_PARENTHESIS";
	case TK_ASTERISK: return "TK_ASTERISK";
	case TK_PLUS_SIGN: return "TK_PLUS_SIGN";
	case TK_COMMA: return "TK_COMMA";
	case TK_HYPHEN_MINUS: return "TK_HYPHEN_MINUS";
	case TK_FULL_STOP: return "TK_FULL_STOP";
	case TK_SOLIDUS: return "TK_SOLIDUS";
	case TK_COLON: return "TK_COLON";
	case TK_SEMICOLON: return "TK_SEMICOLON";
	case TK_LESS_THAN_SIGN: return "TK_LESS_THAN_SIGN";
	case TK_EQUALS_SIGN: return "TK_EQUALS_SIGN";
	case TK_GREATER_THAN_SIGN: return "TK_GREATER_THAN_SIGN";
	case TK_QUESTION_MARK: return "TK_QUESTION_MARK";
	case TK_COMMERCIAL_AT: return "TK_COMMERCIAL_AT";
	case TK_LEFT_SQUARE_BRACKET: return "TK_LEFT_SQUARE_BRACKET";
	case TK_REVERSE_SOLIDUS: return "TK_REVERSE_SOLIDUS";
	case TK_RIGHT_SQUARE_BRACKET: return "TK_RIGHT_SQUARE_BRACKET";
	case TK_CIRCUMFLEX_ACCENT: return "TK_CIRCUMFLEX_ACCENT";
	case TK_FLOW_LINE: return "TK_FLOW_LINE";
	case TK_GRAVE_ACCENT: return "TK_GRAVE_ACCENT";
	case TK_LEFT_CURLY_BRACKET: return "TK_LEFT_CURLY_BRACKET";
	case TK_VERTICAL_LINE: return "TK_VERTICAL_LINE";
	case TK_RIGHT_CURLY_BRACKET: return "TK_RIGHT_CURLY_BRACKET";
	case TK_TILDE: return "TK_TILDE";
	case TK_PREPROCESSOR_LINE: return "TK_PREPROCESSOR_LINE";
	case TK_STRING_LITERAL: return "TK_STRING_LITERAL";
	case TK_LINE_COMMENT: return "TK_LINE_COMMENT";
	case TK_COMMENT: return "TK_COMENT";
	case TK_PPNUMBER: return "TK_PPNUMBER";
	case ANY_OTHER_PP_TOKEN: return "ANY_OTHER_PP_TOKEN";
	case TK_COMPILER_DECIMAL_CONSTANT: return "TK_COMPILER_DECIMAL_CONSTANT";
	case TK_COMPILER_OCTAL_CONSTANT: return "TK_COMPILER_OCTAL_CONSTANT";
	case TK_COMPILER_HEXADECIMAL_CONSTANT: return "TK_COMPILER_HEXADECIMAL_CONSTANT";
	case TK_COMPILER_BINARY_CONSTANT: return "TK_COMPILER_BINARY_CONSTANT";
	case TK_COMPILER_DECIMAL_FLOATING_CONSTANT: return "TK_COMPILER_DECIMAL_FLOATING_CONSTANT";
	case TK_COMPILER_HEXADECIMAL_FLOATING_CONSTANT: return "TK_COMPILER_HEXADECIMAL_FLOATING_CONSTANT";

	case TK_PLACEMARKER: return "TK_PLACEMARKER";
	case TK_BLANKS: return "TK_BLANKS";
	case TK_PLUSPLUS: return "TK_PLUSPLUS";
	case TK_MINUSMINUS: return "TK_MINUSMINUS";
	case TK_ARROW: return "TK_ARROW";
	case TK_SHIFTLEFT: return "TK_SHIFTLEFT";
	case TK_SHIFTRIGHT: return "TK_SHIFTRIGHT";
	case TK_LOGICAL_OPERATOR_OR: return "TK_LOGICAL_OPERATOR_OR";
	case TK_LOGICAL_OPERATOR_AND: return "TK_LOGICAL_OPERATOR_AND";
	case TK_MACRO_CONCATENATE_OPERATOR: return "TK_MACRO_CONCATENATE_OPERATOR";
	case TK_IDENTIFIER: return "TK_IDENTIFIER";
	case TK_IDENTIFIER_RECURSIVE_MACRO: return "TK_IDENTIFIER_RECURSIVE_MACRO";
	case TK_BEGIN_OF_FILE: return "TK_BEGIN_OF_FILE";
	case TK_KEYWORD_AUTO: return "TK_KEYWORD_AUTO";
	case TK_KEYWORD_BREAK: return "TK_KEYWORD_BREAK";
	case TK_KEYWORD_CASE: return "TK_KEYWORD_CASE";
	case TK_KEYWORD_CONSTEXPR: return "TK_KEYWORD_CONSTEXPR";
	case TK_KEYWORD_CHAR: return "TK_KEYWORD_CHAR";
	case TK_KEYWORD_CONST: return "TK_KEYWORD_CONST";
	case TK_KEYWORD_CONTINUE: return "TK_KEYWORD_CONTINUE";
	case TK_KEYWORD_DEFAULT: return "TK_KEYWORD_DEFAULT";
	case TK_KEYWORD_DO: return "TK_KEYWORD_DO";
	case TK_KEYWORD_DOUBLE: return "TK_KEYWORD_DOUBLE";
	case TK_KEYWORD_ELSE: return "TK_KEYWORD_ELSE";
	case TK_KEYWORD_ENUM: return "TK_KEYWORD_ENUM";
	case TK_KEYWORD_EXTERN: return "TK_KEYWORD_EXTERN";
	case TK_KEYWORD_FLOAT: return "TK_KEYWORD_FLOAT";
	case TK_KEYWORD_FOR: return "TK_KEYWORD_FOR";
	case TK_KEYWORD_GOTO: return "TK_KEYWORD_GOTO";
	case TK_KEYWORD_IF: return "TK_KEYWORD_IF";
	case TK_KEYWORD_INLINE: return "TK_KEYWORD_INLINE";
	case TK_KEYWORD_INT: return "TK_KEYWORD_INT";
	case TK_KEYWORD_LONG: return "TK_KEYWORD_LONG";
	case TK_KEYWORD__INT8: return "TK_KEYWORD__INT8";
	case TK_KEYWORD__INT16: return "TK_KEYWORD__INT16";
	case TK_KEYWORD__INT32: return "TK_KEYWORD__INT32";
	case TK_KEYWORD__INT64: return "TK_KEYWORD__INT64";
	case TK_KEYWORD_REGISTER: return "TK_KEYWORD_REGISTER";
	case TK_KEYWORD_RESTRICT: return "TK_KEYWORD_RESTRICT";
	case TK_KEYWORD_RETURN: return "TK_KEYWORD_RETURN";
	case TK_KEYWORD_SHORT: return "TK_KEYWORD_SHORT";
	case TK_KEYWORD_SIGNED: return "TK_KEYWORD_SIGNED";
	case TK_KEYWORD_SIZEOF: return "TK_KEYWORD_SIZEOF";
	case TK_KEYWORD_STATIC_DEBUG: return "TK_KEYWORD_STATIC_DEBUG";
	case TK_KEYWORD_STATIC_STATE: return "TK_KEYWORD_STATIC_STATE";
	case TK_KEYWORD_STATIC_SET: return "TK_KEYWORD_STATIC_SET";
	case TK_KEYWORD_STATIC: return "TK_KEYWORD_STATIC";
	case TK_KEYWORD_STRUCT: return "TK_KEYWORD_STRUCT";
	case TK_KEYWORD_SWITCH: return "TK_KEYWORD_SWITCH";
	case TK_KEYWORD_TYPEDEF: return "TK_KEYWORD_TYPEDEF";
	case TK_KEYWORD_UNION: return "TK_KEYWORD_UNION";
	case TK_KEYWORD_UNSIGNED: return "TK_KEYWORD_UNSIGNED";
	case TK_KEYWORD_VOID: return "TK_KEYWORD_VOID";
	case TK_KEYWORD_VOLATILE: return "TK_KEYWORD_VOLATILE";
	case TK_KEYWORD_WHILE: return "TK_KEYWORD_WHILE";
	case TK_KEYWORD__ALIGNAS: return "TK_KEYWORD__ALIGNAS";
	case TK_KEYWORD__ALIGNOF: return "TK_KEYWORD__ALIGNOF";
	case TK_KEYWORD__ATOMIC: return "TK_KEYWORD__ATOMIC";
	case TK_KEYWORD__BOOL: return "TK_KEYWORD__BOOL";
	case TK_KEYWORD__COMPLEX: return "TK_KEYWORD__COMPLEX";
	case TK_KEYWORD__DECIMAL128: return "TK_KEYWORD__DECIMAL128";
	case TK_KEYWORD__DECIMAL32: return "TK_KEYWORD__DECIMAL32";
	case TK_KEYWORD__DECIMAL64: return "TK_KEYWORD__DECIMAL64";
	case TK_KEYWORD__GENERIC: return "TK_KEYWORD__GENERIC";
	case TK_KEYWORD__IMAGINARY: return "TK_KEYWORD__IMAGINARY";
	case TK_KEYWORD__NORETURN: return "TK_KEYWORD__NORETURN";
	case TK_KEYWORD__STATIC_ASSERT: return "TK_KEYWORD__STATIC_ASSERT";
	case TK_KEYWORD__THREAD_LOCAL: return "TK_KEYWORD__THREAD_LOCAL";
	case TK_KEYWORD_TYPEOF: return "TK_KEYWORD_TYPEOF";


	case TK_KEYWORD_TRUE: return "TK_KEYWORD_TRUE";
	case TK_KEYWORD_FALSE: return "TK_KEYWORD_FALSE";
	case TK_KEYWORD_NULLPTR: return "TK_KEYWORD_NULLPTR";
	case TK_KEYWORD_DEFER: return "TK_KEYWORD_DEFER";
	case TK_KEYWORD__BITINT: return "TK_KEYWORD__BITINT";
	case TK_KEYWORD__ASM: return "TK_KEYWORD__ASM";
	case TK_KEYWORD_CATCH: return "TK_KEYWORD_CATCH";
	case TK_KEYWORD_TRY: return "TK_KEYWORD_TRY";
	case TK_KEYWORD_THROW: return "TK_KEYWORD_THROW";

	case TK_KEYWORD_TYPEOF_UNQUAL: return "TK_KEYWORD_TYPEOF_UNQUAL";
	}
	assert(false);
	return "";
};


void print_literal(const char* s)
{
	if (s == NULL)
	{
		printf("\"");
		printf("\"");
		return;
	}
	printf("\"");
	while (*s)
	{
		switch (*s)
		{
		case '\n':
			printf("\\n");
			break;
		default:
			printf("%c", *s);
		}
		s++;
	}
	printf("\"");
}





const char* owner get_code_as_we_see_plus_macros(struct token_list* list)
{
	struct osstream ss = { 0 };
	struct token* current = list->head;
	while (current)
	{
		if (current->level == 0 &&
			current->type != TK_BEGIN_OF_FILE)
		{
			if (current->flags & TK_FLAG_MACRO_EXPANDED)
				ss_fprintf(&ss, LIGHTCYAN);
			else
				ss_fprintf(&ss, WHITE);
			ss_fprintf(&ss, "%s", current->lexeme);
			ss_fprintf(&ss, RESET);
		}
		current = current->next;
	}

	const char* owner cstr = ss.c_str;
	ss.c_str = NULL; /*MOVED*/

	ss_close(&ss);

	return cstr;
}

const char* owner get_code_as_we_see(struct token_list* list, bool remove_comments)
{
	struct osstream ss = { 0 };
	struct token* current = list->head;
	while (current != list->tail->next)
	{
		if (current->level == 0 &&
			!(current->flags & TK_FLAG_MACRO_EXPANDED) &&
			!(current->flags & TK_FLAG_HIDE) &&
			current->type != TK_BEGIN_OF_FILE)
		{
			if ((current->flags & TK_FLAG_HAS_SPACE_BEFORE) &&
				(current->prev != NULL && current->prev->type != TK_BLANKS))
			{
				//se uma macro expandida for mostrada ele nao tem espacos entao inserimos
				ss_fprintf(&ss, " ");
			}

			if (remove_comments)
			{
				if (current->type == TK_LINE_COMMENT)
					ss_fprintf(&ss, "\n");
				else if (current->type == TK_COMMENT)
					ss_fprintf(&ss, " ");
				else
					ss_fprintf(&ss, "%s", current->lexeme);
			}
			else
			{
				ss_fprintf(&ss, "%s", current->lexeme);
			}
		}
		current = current->next;
	}

	const char* owner cstr = ss.c_str;
	ss.c_str = NULL; /*MOVED*/

	ss_close(&ss);

	return cstr;
}


const char* owner get_code_as_compiler_see(struct token_list* list)
{
	struct osstream ss = { 0 };


	struct token* current = list->head;
	while (current != list->tail->next)
	{
		if (!(current->flags & TK_FLAG_HIDE) &&
			current->type != TK_BEGIN_OF_FILE &&
			(current->flags & TK_FLAG_FINAL))
		{
			if (current->flags & TK_FLAG_HAS_SPACE_BEFORE)
				ss_fprintf(&ss, " ");

			if (current->flags & TK_FLAG_HAS_NEWLINE_BEFORE)
				ss_fprintf(&ss, "\n");

			if (current->type == TK_LINE_COMMENT)
				ss_fprintf(&ss, "\n");
			else if (current->type == TK_COMMENT)
				ss_fprintf(&ss, " ");
			else
				ss_fprintf(&ss, "%s", current->lexeme);
		}
		current = current->next;
	}

	return ss.c_str;
}

const char* owner print_preprocessed_to_string2(struct token* p_token)
{
	/*
	* No nivel > 0 (ou seja dentro dos includes)
	* Esta funcao imprime os tokens como o compilador ve
	* e insere um espaco ou quebra de linha para poder representar
	* a separacao entre os tokens.

	* Ja no nivel 0 (arquivo principal) ele imprime espacos comentarios
	* etc.. e insere espacos na expancao da macro.
	*/

	if (p_token == NULL)
		return strdup("(null)");

	struct osstream ss = { 0 };
	struct token* current = p_token;
	while (current)
	{

		//Nós ignorados a line continuation e ela pode aparecer em qualquer parte
		//dos lexemes.
		//inves de remover poderia so pular ao imprimir
		remove_line_continuation(current->lexeme);

		if (current->flags & TK_FLAG_FINAL)
		{
			if (current->level > 0)
			{
				//nos niveis de include nos podemos estar ignorando todos
				//os espacos. neste caso eh preciso incluilos para nao juntar os tokens

				if ((current->flags & TK_FLAG_HAS_NEWLINE_BEFORE))
					ss_fprintf(&ss, "\n");
				else if ((current->flags & TK_FLAG_HAS_SPACE_BEFORE))
					ss_fprintf(&ss, " ");
			}
			else
			{
				/*
				  no nivel 0 nos imprimimos os espacos.. porem no caso das macros
				  eh preciso colocar um espaco pq ele nao existe.
				*/
				if (current->flags & TK_FLAG_MACRO_EXPANDED)
				{
					if ((current->flags & TK_FLAG_HAS_SPACE_BEFORE))
						ss_fprintf(&ss, " ");
				}
			}

			//}

			if (current->lexeme[0] != '\0')
			{
				ss_fprintf(&ss, "%s", current->lexeme);
			}

			current = current->next;
		}
		else
		{
			if (current->level == 0)
			{
				if (current->type == TK_BLANKS ||
					current->type == TK_NEWLINE)
				{
					ss_fprintf(&ss, "%s", current->lexeme);
				}
			}

			current = current->next;
		}
	}

	return ss.c_str;
}

const char* owner print_preprocessed_to_string(struct token* p_token)
{
	/*
	* Esta funcao imprime os tokens como o compilador ve
	* e insere um espaco ou quebra de linha para poder representar
	* a separacao entre os tokens.
	*/

	struct osstream ss = { 0 };
	struct token* current = p_token;

	/*
	* Ignora tudo o que é espaço no início
	*/
	while (!(current->flags & TK_FLAG_FINAL) ||
		current->type == TK_BLANKS ||
		current->type == TK_COMMENT ||
		current->type == TK_LINE_COMMENT ||
		current->type == TK_NEWLINE ||
		current->type == TK_PREPROCESSOR_LINE)
	{
		current = current->next;
		if (current == NULL)
			return ss.c_str; /*MOVED*/
	}

	bool first = true;
	while (current)
	{
		assert(current->token_origin != NULL);
		if (current->flags & TK_FLAG_FINAL)
		{
			if (!first && current->flags & TK_FLAG_HAS_NEWLINE_BEFORE)
				ss_fprintf(&ss, "\n");
			else if (!first && current->flags & TK_FLAG_HAS_SPACE_BEFORE)
				ss_fprintf(&ss, " ");
			if (current->lexeme[0] != '\0')
				ss_fprintf(&ss, "%s", current->lexeme);
			first = false;
			current = current->next;
		}
		else
		{
			current = current->next;
		}
	}

	return ss.c_str; /*MOVED*/
}

void print_preprocessed(struct token* p_token)
{
	const char* owner s = print_preprocessed_to_string(p_token);
	if (s)
	{
		printf("%s", s);
		free((void* owner)s);
	}
}

static bool is_screaming_case(const char* text)
{
	if (text == NULL)
		return true;

	if (!(text[0] >= 'A' && text[0] <= 'Z'))
	{
		/*first letter lower case*/
		return false;
	}

	while (*text)
	{
		if ((*text >= 'A' && *text <= 'Z') ||
			(*text >= '0' && *text <= '9') ||
			(*text == '_'))
		{
			//ok
		}
		else
			return false;
		text++;
	}

	return true;

}

void print_all_macros(struct preprocessor_ctx* prectx)
{
	for (int i = 0; i < prectx->macros.capacity; i++)
	{
		struct owner_map_entry* entry = prectx->macros.table[i];
		if (entry == NULL) continue;
		struct macro* macro = entry->p;
		printf("#define %s", macro->name);
		if (macro->is_function)
		{
			printf("(");

			struct macro_parameter* parameter = macro->parameters;
			while (parameter)
			{
				printf("%s", parameter->name);
				if (parameter->next)
					printf(",");
				parameter = parameter->next;
			}
			printf(")");
		}
		printf(" ");

		struct token* token = macro->replacement_list.head;
		while (token)
		{
			printf("%s", token->lexeme);

			if (token == macro->replacement_list.tail)
				break;

			token = token->next;
		}
		printf("\n");
	}
}
void naming_convention_macro(struct preprocessor_ctx* ctx, struct token* token)
{
	if (!preprocessor_is_warning_enabled(ctx, W_STYLE) || token->level != 0)
	{
		return;
	}

	if (!is_screaming_case(token->lexeme))
	{
		preprocessor_set_info_with_token(ctx, token, "use SCREAMING_CASE for macros");
	}

}


#ifdef TEST


//#pragma once

extern int g_unit_test_error_count;
extern int g_unit_test_success_count;
static void assert_func(int condition, const char* func, const char* file, int line, const char* message)
{
    if (!condition)
    {
        const char* pos = file;
        const char* p = file;
        while (*p)
        {
            if (*p == '/' || *p == '\\')
                pos = p;
            p++;
        }
        
        if (*pos == '/' || *pos == '\\')
            pos++;

        g_unit_test_error_count++;
        printf("\x1b[97m" "%s:%d:0:" "\x1b[91m" " test failed:" "\x1b[0m" " function '%s'\n", pos, line, func);
        
        char buffer[20] = { 0 };
        int n = snprintf(buffer, sizeof buffer, "%d", line);        
        printf(" %s |", buffer);
        printf("    assert(%s);\n", message);
        printf(" %*s |\n", n, " ");
    }
    else
    {
        g_unit_test_success_count++;
        //printf("\x1b[97m" "%s:%d:0" "\x1b[92m" " OK" "\x1b[0m" " at '%s'\n", file, line, func);        
    }
}

#undef assert
#define assert(expression) assert_func(expression, __func__, __FILE__, __LINE__, #expression)




void print_asserts(struct token* p_token)
{
	struct token* current = p_token;
	printf("struct { const char* lexeme; enum token_type token; int is_active; int is_final; } result[] = { \n");
	while (current)
	{
		printf("{ %-20s, %d, ", get_token_name(current->type), (current->flags & TK_FLAG_FINAL));
		print_literal(current->lexeme);
		printf("},\n");
		current = current->next;
	}
	printf("}\n");
}

void show_all(struct token* p_token)
{
	struct token* current = p_token;
	while (current)
	{
		if (current->flags & TK_FLAG_FINAL)
		{
			if (current->level == 0)
				printf(WHITE);
			else
				printf(BROWN);
		}
		else
		{
			if (current->level == 0)
				printf(LIGHTGRAY);
			else
				printf(BLACK);
		}
		printf("%s", current->lexeme);
		printf(RESET);
		current = current->next;
	}
}





void print_preprocessed_to_file(struct token* p_token, const char* filename)
{
	FILE* f = fopen(filename, "r");
	if (f)
	{
		const char* s = print_preprocessed_to_string(p_token);
		if (s)
		{
			fprintf(f, "%s", s);
			free((void* owner)s);
		}
		fclose(f);
	}
}

void show_visible(struct token* p_token)
{
	printf(WHITE "visible used   / " LIGHTGRAY "visible ignored\n" RESET);
	struct token* current = p_token;
	while (current)
	{
		if (current->level == 0)
		{
			if (current->flags & TK_FLAG_FINAL)
				printf(WHITE);
			else
				printf(LIGHTGRAY);
		}
		else
		{
			if (current->level == 0)
				printf(BLACK);
			else
				printf(BLACK);
		}
		printf("%s", current->lexeme);
		printf(RESET);
		current = current->next;
	}
}

void show_visible_and_invisible(struct token* p_token)
{
	printf(LIGHTGREEN "visible used   / " LIGHTGRAY "visible ignored\n" RESET);
	printf(LIGHTBLUE  "invisible used / " BROWN     "invisible ignored\n" RESET);
	struct token* current = p_token;
	while (current)
	{
		if (current->level == 0)
		{
			if (current->flags & TK_FLAG_FINAL)
				printf(LIGHTGREEN);
			else
				printf(LIGHTGRAY);
		}
		else
		{
			if (current->flags & TK_FLAG_FINAL)
				printf(LIGHTBLUE);
			else
				printf(BROWN);
		}
		printf("%s", current->lexeme);
		printf(RESET);
		current = current->next;
	}
}

int test_preprossessor_input_output(const char* input, const char* output)
{
	struct tokenizer_ctx tctx = { 0 };
	struct token_list list = tokenizer(&tctx, input, "source", 0, TK_FLAG_NONE);

	struct preprocessor_ctx ctx = { 0 };

	struct token_list r = preprocessor(&ctx, &list, 0);
	const char* s = print_preprocessed_to_string(r.head);
	if (strcmp(s, output) != 0)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("expected\n%s", output);
		printf("HAS\n%s", s);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		print_tokens(r.head);
		printf("TEST 0 FAILED\n");
		return 1;
	}
	free((void* owner)s);
	return 0;
}

char* normalize_line_end(char* input)
{
	if (input == NULL)
		return NULL;
	char* pWrite = input;
	const char* p = input;
	while (*p)
	{
		if (p[0] == '\r' && p[1] == '\n')
		{
			*pWrite = '\n';
			p++;
			p++;
			pWrite++;
		}
		else
		{
			*pWrite = *p;
			p++;
			pWrite++;
		}
	}
	*pWrite = 0;
	return input;
}


int test_preprocessor_in_out(const char* input, const char* output)
{
	int res = 0;

	struct tokenizer_ctx tctx = { 0 };
	struct token_list list = tokenizer(&tctx, input, "source", 0, TK_FLAG_NONE);

	struct preprocessor_ctx ctx = { 0 };

	struct token_list r = preprocessor(&ctx, &list, 0);
	const char* result = print_preprocessed_to_string(r.head);
	if (result == NULL)
	{
		result = strdup("");
	}

	if (strcmp(result, output) != 0)
	{
		/*
		printf("FAILED\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("assert\n");
		printf("%s`", output);
		printf("\nGOT\n");
		printf("%s`", result);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		print_tokens(r.head);

		*/
		res = 1;
	}



	return res;
}

int test_preprocessor_in_out_using_file(const char* fileName)
{
	int res = 0;
	const char* input = normalize_line_end(read_file(fileName));
	char* output = 0;
	if (input)
	{
		char* pos = strstr(input, "\n---");
		if (pos)
		{
			*pos = 0;
			//anda ate sair ---
			pos++;
			while (*pos != '\n')
			{
				pos++;
			}
			pos++; //skip \n
			output = pos;
			/*optional*/
			pos = strstr(output, "\n---");
			if (pos)
				*pos = 0;
		}
		res = test_preprocessor_in_out(input, output);
		free((void* owner)input);
	}
	return res;
}

void test_lexeme_cmp()
{
	assert(lexeme_cmp("a", "\\\na") == 0);
	assert(lexeme_cmp("a", "a\\\n") == 0);
	assert(lexeme_cmp("\\\na", "a") == 0);
	assert(lexeme_cmp("a\\\n", "a") == 0);
	assert(lexeme_cmp("a\\\nb", "ab") == 0);
	assert(lexeme_cmp("define", "define") == 0);
	assert(lexeme_cmp("de\\\nfine", "define") == 0);
}

void token_list_pop_front_test()
{

	struct token_list list = { 0 };
	token_list_pop_front(&list);
	struct tokenizer_ctx tctx = { 0 };
	list = tokenizer(&tctx, "a", NULL, 0, TK_FLAG_NONE);
	token_list_pop_front(&list);

	list = tokenizer(&tctx, "a,", NULL, 0, TK_FLAG_NONE);
	token_list_pop_front(&list);

	list = tokenizer(&tctx, "a,b", NULL, 0, TK_FLAG_NONE);
	token_list_pop_front(&list);
}

void token_list_pop_back_test()
{

	struct token_list list = { 0 };
	token_list_pop_back(&list);

	/*pop back quando so tem 1*/
	token_list_clear(&list);
	struct tokenizer_ctx tctx = { 0 };
	list = tokenizer(&tctx, "a", NULL, 0, TK_FLAG_NONE);
	token_list_pop_back(&list);
	assert(list.head == NULL && list.tail == NULL);


	/*
	* pop bacl com 2
	*/

	token_list_clear(&list);
	list = tokenizer(&tctx, "a,", NULL, 0, TK_FLAG_NONE);
	token_list_pop_back(&list);

	assert(strcmp(list.head->lexeme, "a") == 0);

	assert(list.head != NULL &&
		list.head->prev == NULL &&
		list.head->next == NULL &&
		list.tail->prev == NULL &&
		list.tail->next == NULL &&
		list.tail == list.head);

	/*
	* pop back com 3
	*/

	list = tokenizer(&tctx, "a,b", NULL, 0, TK_FLAG_NONE);
	token_list_pop_back(&list);
	assert(strcmp(list.head->lexeme, "a") == 0);
	assert(strcmp(list.head->next->lexeme, ",") == 0);
	assert(strcmp(list.tail->lexeme, ",") == 0);
	assert(strcmp(list.tail->prev->lexeme, "a") == 0);
	assert(list.head->prev == NULL);
	assert(list.tail->next == NULL);
}

int token_list_append_list_test()
{

	struct tokenizer_ctx tctx = { 0 };
	struct token_list source = { 0 };
	struct token_list dest = tokenizer(&tctx, "a", NULL, 0, TK_FLAG_NONE);
	token_list_append_list(&dest, &source);
	assert(strcmp(dest.head->lexeme, "a") == 0);


	token_list_clear(&source);
	token_list_clear(&dest);


	dest = tokenizer(&tctx, "a", NULL, 0, TK_FLAG_NONE);
	token_list_append_list(&dest, &source);

	assert(strcmp(dest.head->lexeme, "a") == 0);

	token_list_clear(&source);
	token_list_clear(&dest);
	source = tokenizer(&tctx, "a,", NULL, 0, TK_FLAG_NONE);
	dest = tokenizer(&tctx, "1", NULL, 0, TK_FLAG_NONE);
	token_list_append_list(&dest, &source);
	assert(strcmp(dest.head->lexeme, "1") == 0);
	assert(strcmp(dest.tail->lexeme, ",") == 0);
	assert(dest.tail->next == NULL);
	assert(dest.head->next->next == dest.tail);
	assert(dest.tail->prev->prev == dest.head);

	return 0;
}

void test_collect()
{
	const char* input =
		"#define F(A, B) A ## B\n"
		"F(a \n, b)";

	const char* output =
		"ab"
		;


	assert(test_preprocessor_in_out(input, output) == 0);

}


void test_va_opt_0()
{
	const char* input =
		"#define F(...)  f(0 __VA_OPT__(,) __VA_ARGS__)\n"
		"F(a, b, c)";
	const char* output =
		"f(0, a, b, c)";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void test_va_opt_1()
{
	const char* input =
		"#define F(...)  f(0 __VA_OPT__(,) __VA_ARGS__)\n"
		"F()";
	const char* output =
		"f(0)";
	assert(test_preprocessor_in_out(input, output) == 0);
}


void test_va_opt_2()
{
	const char* input =
		"#define empty(...) (__VA_OPT__(!)1)\n"
		"empty()";
	const char* output =
		"(1)";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void test_va_opt_3()
{
	const char* input =
		"#define empty(...) (__VA_OPT__(!)1)\n"
		"empty(1)";
	const char* output =
		"(!1)";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void test_va_opt_4()
{
	const char* input =
		"#define LPAREN() (\n"
		"#define G(Q) 42\n"
		"#define F(R, X, ...) __VA_OPT__(G R X) )\n"
		"int x = F(LPAREN(), 0, <:-);\n"
		;
	const char* output =
		"int x = 42;";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void test_va_opt_5()
{
	const char* input =
		"#define F(...) f(0 __VA_OPT__(,) __VA_ARGS__)\n"
		"#define EMPTY\n"
		"F(EMPTY)"
		;
	const char* output =
		"f(0)";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void test_va_opt_6()
{
	const char* input =
		"#define G(X, ...) f(0, X __VA_OPT__(,) __VA_ARGS__)\n"
		"G(a)"
		;

	const char* output =
		"f(0, a)";

	assert(test_preprocessor_in_out(input, output) == 0);
}
void test_va_opt_7()
{
	const char* input =
		"#define H4(X, ...) __VA_OPT__(a X ## X) ## b\n"
		"H4(, 1)"
		;

	const char* output =
		"a b";

	assert(test_preprocessor_in_out(input, output) == 0);
}

void concatenation_problem()
{
	const char* input =
		"#define H4(X, ...) a X ## X ## b\n"
		"H4()"
		;

	const char* output =
		"a b";

	assert(test_preprocessor_in_out(input, output) == 0);
}


void test_va_opt_G2()
{
	const char* input =
		"#define G(X, ...) f(0, X __VA_OPT__(,) __VA_ARGS__)\n"
		"G(a, )"
		;

	const char* output =
		"f(0, a)";

	assert(test_preprocessor_in_out(input, output) == 0);
}


void test_va_opt()
{
	const char* input =
		"#define F(...)  f(0 __VA_OPT__(,) __VA_ARGS__)\n"
		"#define EMPTY\n"
		"F(EMPTY)";
	const char* output =
		"f(0)";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void test_empty_va_args()
{
	const char* input = "#define M(a, ...) a, __VA_ARGS__\n"
		"M(1)\n";
	const char* output =
		"1,";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void test_va_args_single()
{
	const char* input =
		"#define F(...) __VA_ARGS__\n"
		"F(1, 2)";
	const char* output =
		"1, 2";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void test_va_args_extra_args()
{
	const char* input =
		"#define F(a, ...) a __VA_ARGS__\n"
		"F(0, 1, 2)";
	const char* output =
		"0 1, 2";
	assert(test_preprocessor_in_out(input, output) == 0);
}


void test_empty_va_args_empty()
{
	const char* input =
		"#define F(...) a __VA_ARGS__\n"
		"F()";
	const char* output =
		"a";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void test_defined()
{
	const char* input =
		"#if defined X || defined (X)\n"
		"A\n"
		"#else\n"
		"B\n"
		"#endif\n";
	const char* output =
		"B";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void testline()
{
	const char* input =
		"#define M \\\n"
		"        a\\\n"
		"        b\n"
		"M";
	const char* output =
		"a b";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void ifelse()
{
	const char* input =
		"#if 1\n"
		"A\n"
		"#else\n"
		"B\n"
		"#endif\n";
	const char* output =
		"A";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void T1()
{
	const char* input =
		"#define f(a) f(x * (a))\n"
		"f(2 * (0, 1))";
	const char* output =
		"f(x * (2 * (0, 1)))";
	//se f tivesse 2 parametros
	//error: too few arguments provided to function-like macro invocation
	//se f nao tivesse nenhum ou menus
	//too many arguments provided to function-like macro invocation
	assert(test_preprocessor_in_out(input, output) == 0);
}

int EXAMPLE5()
{
	/*
	//EXAMPLE 5 To illustrate the rules for placemarker preprocessing tokens, the sequence

	//const char* input =
	//"#define t(x,y,z) x ## y ## z\n"
	//"int j[] = {t(+1,2,3), t(,4,5), t(6,,7), t(8,9,),t(10,,), t(,11,), t(,,12), t(,,) };";

	//const char* output =
	  //  "int j[] = {+123, 45, 67, 89,10, 11, 12, };";

	const char* input =
		"#define t(x,y,z) x ## y ## z\n"
		"t(+1,2,3)";

	const char* output =
		"int j[] = {+123, 45, 67, 89,10, 11, 12, };";

	//se f tivesse 2 parametros
	//error: too few arguments provided to function-like macro invocation

	//se f nao tivesse nenhum ou menus
	//too many arguments provided to function-like macro invocation
	//test_preprocessor_in_out(input, output);
	*/
	return 0;
}

void recursivetest1()
{
	//acho que este vai sero caso que precisa do hidden set.
	const char* input =
		"#define x 2\n"
		"#define f(a) f(x * (a))\n"
		"#define z z[0]\n"
		"f(f(z))";
	//resultado gcc da
	//const char* output =
	//  "f(2 * (f(2 * (z[0]))))";
	const char* output =
		"f(2 * (f(z[0])))";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void rectest()
{
	const char* input =
		"#define x 2\n"
		"#define f(a) f(x * (a))\n"
		"#define g f\n"
		"#define z z[0]\n"
		"f(y + 1) + f(f(z)) % t(t(g)(0) + t)(1);";
	//GCC
	//const char* output =
	//  "f(2 * (y + 1)) + f(2 * (f(2 * (z[0])))) % t(t(f)(0) + t)(1);";
	const char* output =
		"f(2 * (y + 1)) + f(2 * (f(z[0]))) % t(t(f)(0) + t)(1);";
	assert(test_preprocessor_in_out(input, output) == 0);
}

void emptycall()
{
	const char* input =
		"#define F(x) x\n"
		"F()"
		;
	const char* output =
		""
		;
	assert(test_preprocessor_in_out(input, output) == 0);
}

void semiempty()
{
	const char* input =
		"#define F(x,y) x ## y\n"
		"F(1,)"
		;
	const char* output =
		"1"
		;
	assert(test_preprocessor_in_out(input, output) == 0);
}

void calling_one_arg_with_empty_arg()
{
	const char* input =
		"#define F(a) # a\n"
		"F()"
		;
	const char* output =
		"\"\""
		;
	assert(test_preprocessor_in_out(input, output) == 0);
}


void test_argument_with_parentesis()
{
	const char* input =
		"#define F(a, b) a ## b\n"
		"F((1, 2, 3),4)"
		;
	const char* output =
		"(1, 2, 3)4"
		;
	assert(test_preprocessor_in_out(input, output) == 0);
}

void two_empty_arguments()
{
	const char* input =
		"#define F(a, b) a ## b\n"
		"F(,)\n"
		;
	const char* output =
		""
		;
	assert(test_preprocessor_in_out(input, output) == 0);
}

void simple_object_macro()
{
	const char* input = "#define B b\n"
		"#define M a B\n"
		"M\n"
		"c\n";
	const char* output =
		"a b\n"
		"c";
	assert(test_preprocessor_in_out(input, output) == 0);
}


void test_one_file()
{
	assert(test_preprocessor_in_out_using_file("tests/pre_debug.c") == 0);
}

void test2()
{
	const char* input =
		"#define F(a, b) 1 a ## b 4\n"
		"F(  2  ,  3 )"
		;
	const char* output =
		"1 23 4"
		;

	assert(test_preprocessor_in_out(input, output) == 0);
}


void test3()
{
#if 0
	const char* input =
		"#define F(a, b) 1 a ## 3 4\n"
		"F(  2   )"
		;
	const char* output =
		"1 23 4"
		;
#endif
	//este erro falta parametro b
	//too few arguments provided to function - like macro invocation
	//test_preprocessor_in_out(input, output);
}


void tetris()
{
	const char* input =
		"#define D(a) a\n"
		"#define C(a) a\n"
		"#define F(a) a\n"
		"#define M F\n"
		"M(F)(C)(D)e"
		;
	const char* output =
		"De"
		;
	struct tokenizer_ctx tctx = { 0 };
	struct token_list list = tokenizer(&tctx, input, "source", 0, TK_FLAG_NONE);

	struct preprocessor_ctx ctx = { 0 };

	struct token_list r = preprocessor(&ctx, &list, 0);

	assert(test_preprocessor_in_out(input, output) == 0);
}

void recursive_macro_expansion()
{
	const char* input =
		"#define A 3 4 B\n"
		"#define B 1 2 A\n"
		"B";
	const char* output =
		"1 2 3 4 B"
		;
	assert(test_preprocessor_in_out(input, output) == 0);
}

void empty_and_no_args()
{
	const char* input =
		"#define F() 1\n"
		"F()";
	const char* output =
		"1"
		;
	assert(test_preprocessor_in_out(input, output) == 0);
}

void test4()
{
	const char* input =
		"#define F(a, b) 1 2 ## a 4\n"
		"F(  3   )"
		;
	const char* output =
		"1 23 4"
		;


	int code = test_preprocessor_in_out(input, output);

	//esperado um erro (falta mensagem)
	//too few arguments provided to function-like macro invocation F (3)
	//engracado msc eh warning  warning C4003: not enough actual parameters for macro 'F'
	assert(code != 0);
}

void test_string()
{
	const char* input =
		"#define M(a, b) a # b\n"
		"M(A, \"B\")"
		;
	const char* output =
		"A \"\\\"B\\\"\""
		;


	test_preprocessor_in_out(input, output);
}

void test6()
{
	/*

	#define Y
	#define X defined (Y)

	#if X
	#warning !
	#endif
	*/
}

void testerror()
{
	/*
	const char* input =
		"#define F(a) #b\n"
		"F(1)\n"
		;
	const char* output =
		""
		;
	//tem que dar error
	test_preprocessor_in_out(input, output);
	*/
}

int test_preprocessor_expression(const char* expr, long long expected)
{

	struct preprocessor_ctx ctx = { 0 };

	struct token_list r = { 0 };
	struct tokenizer_ctx tctx = { 0 };
	struct token_list input = tokenizer(&tctx, expr, "", 0, TK_FLAG_NONE);

	long long result = preprocessor_constant_expression(&ctx, &r, &input, 0);
	return result == expected ? 0 : 1;
}

int test_expression()
{

	//TODO preprocessador eh sempre long long.. signed passadno maior
	//deve dar erro

	if (test_preprocessor_expression("true", true) != 0)
		return __LINE__;

	if (test_preprocessor_expression("false", false) != 0)
		return __LINE__;


	if (test_preprocessor_expression("'A'", 'A') != 0)
		return __LINE__;

	if (test_preprocessor_expression("'ab'", 'ab') != 0)
		return __LINE__;

	if (test_preprocessor_expression("1+2", 1 + 2) != 0)
		return __LINE__;

	if (test_preprocessor_expression("1 + 2 * 3 / 2 ^ 2 & 4 | 3 % 6 >> 2 << 5 - 4 + !7",
		1 + 2 * 3 / 2 ^ 2 & 4 | 3 % 6 >> 2 << 5 - 4 + !7) != 0)
		return __LINE__;

	if (test_preprocessor_expression("1ull + 2l * 3ll",
		1ull + 2l * 3ll) != 0)
		return __LINE__;


	return 0;
}

int test_concatenation_o()
{
	const char* input =
		"# define F(t1, t2, t3) *i_##t1##_j k\n"
		"F(A, B, C)\n";

	const char* output =
		"*i_A_j k"
		;


	return test_preprocessor_in_out(input, output);
}

int test_concatenation()
{
	const char* input =
		"#define F(t1, t2, t3) i##j##k\n"
		"F(A, B, C)\n";

	const char* output =
		"ijk"
		;


	return test_preprocessor_in_out(input, output);


}

void bad_test()
{
	struct tokenizer_ctx tctx = { 0 };
	struct token_list list = tokenizer(&tctx, "0xfe-BAD(3)", "source", 0, TK_FLAG_NONE);

	const char* input = "#define BAD(x) ((x) & 0xff)\n"
		"0xfe-BAD(3);";
	const char* output =
		"0xfe-BAD(3);"
		;

	test_preprocessor_in_out(input, output);
}
/*
#define A0
#define B0
#define A1(x) x B##x(
#define B1(x) x A##x(
A1(1)1)1)1)1)0))
*/
int test_spaces()
{
	const char* input =
		"#define throw A B\n"
		"throw\n"
		;
	const char* output =
		"A B"
		;


	return test_preprocessor_in_out(input, output);
}

int test_stringfy()
{
	const char* input =
		"#define M(T) #T\n"
		"M(unsigned   int)\n"
		;
	const char* output =
		"\"unsigned int\""
		;


	return test_preprocessor_in_out(input, output);

}


int test_tokens()
{
	const char* input =
		"L\"s1\" u8\"s2\""
		;

	struct tokenizer_ctx tctx = { 0 };
	struct token_list list = tokenizer(&tctx, input, "", 0, TK_FLAG_NONE);

	if (list.head->next->type != TK_STRING_LITERAL)
	{
		return __LINE__;
	}

	if (list.head->next->next->next->type != TK_STRING_LITERAL)
	{
		return __LINE__;
	}

	return tctx.n_errors;
}

int test_predefined_macros()
{
	const char* input =
		"__LINE__ __FILE__"
		;
	const char* output =
		"1 \"source\""
		;

	struct tokenizer_ctx tctx = { 0 };
	struct token_list list = tokenizer(&tctx, input, "", 0, TK_FLAG_NONE);

	struct preprocessor_ctx prectx = { 0 };
	prectx.macros.capacity = 5000;
	add_standard_macros(&prectx);
	struct token_list list2 = preprocessor(&prectx, &list, 0);


	const char* result = print_preprocessed_to_string(list2.head);
	if (result == NULL)
	{
		result = strdup("");
	}
	if (strcmp(result, output) != 0)
	{
	}


	return 0;
}

int test_utf8()
{

	const char* input =
		"u8\"maçã\"";

	struct tokenizer_ctx tctx = { 0 };
	struct token_list list = tokenizer(&tctx, input, "source", 0, TK_FLAG_NONE);
	if (strcmp(list.head->next->lexeme, u8"u8\"maçã\"") != 0)
		return __LINE__;
	token_list_destroy(&list);
	return 0;
}


int test_line_continuation()
{


	const char* input =
		"#define A B \\\n"
		"C\n"
		"A";

	const char* output =
		"1 \"source\""
		;


	struct tokenizer_ctx tctx = { 0 };
	struct token_list list = tokenizer(&tctx, input, "", 0, TK_FLAG_NONE);

	struct preprocessor_ctx prectx = { 0 };
	prectx.macros.capacity = 5000;

	struct token_list list2 = preprocessor(&prectx, &list, 0);

	const char* result = print_preprocessed_to_string(list2.head);
	if (result == NULL)
	{
		result = strdup("");
	}
	if (strcmp(result, output) != 0)
	{
	}


	return 0;
}

#endif



void ss_swap(view struct osstream* a, view struct osstream* b)
{
    view struct osstream r = *a;
    *a = *b;
    *b = r;    
}

void ss_clear(struct osstream* stream)
{
    stream->size = 0;
}


void ss_close( struct osstream * obj_owner stream)
{
    free(stream->c_str);    
}

static int reserve(struct osstream* stream, int size)
{
    int errorcode = 0;
    if (size > stream->capacity)
    {
        void* owner pnew = realloc( stream->c_str, (size + 1) * sizeof(char));
        if (pnew)
        {
            static_set(stream->c_str, "moved");
            stream->c_str = pnew;
            stream->capacity = size;
            stream->c_str[size] = 0;
        }
        else
        {
            errno = ENOMEM;
            errorcode = 1;
        }
    }
    return errorcode;
}

int ss_vafprintf(struct osstream* stream, const char* fmt, va_list args)
{
    assert(fmt != 0);
    int size = 0;
    va_list tmpa;

    va_copy(tmpa, args);

    size = vsnprintf(stream->c_str + stream->size, stream->capacity - stream->size, fmt, tmpa);

    va_end(tmpa);

    if (size < 0)
    {
        return -1;
    }

    if (reserve(stream, stream->size + size) != 0)
    {
        return -1;
    }

    size = vsprintf(stream->c_str + stream->size, fmt, args);
    if (size > 0)
    {
        stream->size += size;
    }
    return size;
}

/*
* Returns the character written. For fputc, a return value of EOF indicates an error
*/
int ss_putc(char ch, struct osstream* stream)
{
    if (reserve(stream, stream->size + 1) != 0)
    {
        return EOF;
    }
    stream->c_str[stream->size] = ch;
    stream->size++;

    return ch;
}

int ss_fprintf(struct osstream* stream, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int size = ss_vafprintf(stream, fmt, args);
    va_end(args);
    return size;
}







#ifdef _WIN32
#endif


#if defined _MSC_VER && !defined __POCC__
#endif


#ifdef __POCC__
#define stat _stat
#endif

#ifdef _WIN32
#pragma comment (lib, "Rpcrt4.lib")

#else


#include <uuid/uuid.h>
/*
caso nao tenha este arquivos apt-get install uuid-dev
*/
#endif




bool path_is_absolute(const char* path)
{
#ifdef _WINDOWS_
    const char ch = tolower(path[0]);
    if (ch >= 'a' && ch <= 'z')
    {
        /*  c:/ or c:\ */
        if (path[1] == ':' && (path[2] == '\\' || path[2] == '/'))
            return true;
    }

    if (path[0] == '\\' && path[1] == '\\')
    {
        // //server
        return true;
    }
#else
    return path[0] == '/';
#endif

    return false;    
}

bool path_is_relative(const char* path)
{
    return !path_is_absolute(path);
}


#ifdef _WIN32

#ifdef __CAKE__
#pragma CAKE diagnostic push
#pragma CAKE diagnostic ignore "-Wstyle"
#endif

struct TAGDIR
{
    void* handle;
    struct dirent dirent;
};

#ifdef __CAKE__
#pragma CAKE diagnostic pop
#endif

DIR* owner opendir(const char* name)
{
    assert(name != 0);
    WIN32_FIND_DATAA fdfile = {0};

    char path[MAX_PATH] = {0};
    strcat(path, name);
    strcat(path, "\\*.*");

    HANDLE handle = FindFirstFileA(path, &fdfile);

    if (handle != INVALID_HANDLE_VALUE)
    {
        DIR* owner p = calloc(1, sizeof * p);
        if (p)
        {
            p->handle = handle;
            return p;
        }
        else
        {
            /*calloc sets errno to ENOMEM if a memory allocation fails */
            FindClose(handle);
        }
    }
    else
    {
        errno = windows_error_to_posix(GetLastError());
    }

    return NULL;
}

int closedir(DIR* owner dirp)
{
    FindClose(dirp->handle);
    free(dirp);
    return 0;
}

struct dirent* readdir(DIR* dirp)
{
    WIN32_FIND_DATAA fdfile = {0};
    BOOL b = FindNextFileA(dirp->handle, &fdfile);
    if (b)
    {
        /*clear*/
        memset(&dirp->dirent, 0, sizeof(dirp->dirent));

        if (fdfile.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            dirp->dirent.d_type |= DT_DIR;
        }

        /*worst case trunks the string*/
        strncpy(dirp->dirent.d_name,
            fdfile.cFileName,
            sizeof(dirp->dirent.d_name) - 1);

        return &dirp->dirent;
    }
    else
    {
        errno = windows_error_to_posix(GetLastError());
    }
    return NULL;
}

/*
* realpath
   If there is no error, realpath() returns a pointer to the
       resolved_path.

       Otherwise, it returns NULL, the contents of the array
       resolved_path are undefined, and errno is set to indicate the
       error.
*/
char* realpath(const char* restrict path, char* restrict resolved_path)
{
    /*
    * _fullpath
    * Each of these functions returns a pointer to a buffer
      containing the absolute path name (absPath). If there's an
      error (for example, if the value passed in relPath includes a drive
      letter that isn't valid or can't be found, or if the length of the
      created absolute path name (absPath) is greater than maxLength), the function returns NULL.
    */
    char* p = _fullpath(resolved_path, path, MAX_PATH);
    char* p2 = resolved_path;
    while (*p2)
    {
        if (*p2 == '\\')
            *p2 = '/';
        p2++;
    }
    return p;
}

#endif //_WINDOWS_

int copy_file(const char* pathfrom, const char* pathto)
{

    FILE* owner fd_from = fopen(pathfrom, "rb");
    if (fd_from == NULL)
        return -1;

    FILE* owner fd_to = fopen(pathto, "wb");
    if (fd_to == NULL)
    {
        fclose(fd_from);
        return -1;
    }

    char buf[4096] = {0};
    size_t nread;
    while (nread = fread(buf, sizeof(char), sizeof buf, fd_from), nread > 0) //lint !e668  (warning -- possibly passing null pointer to function 'fread(void *, size_t, size_t, FILE *)', arg. no. 4)
    {
        char* out_ptr = buf;
        size_t nwritten;

        do
        {
            nwritten = fwrite(out_ptr, sizeof(char), nread, fd_to);//lint !e668

            nread -= nwritten;
            out_ptr += nwritten;
        } while (nread > 0);
    }

    if (nread == 0)
    {
        fclose(fd_to);
        fclose(fd_from);

        /* Success! */
        return 0;
    }

    fclose(fd_to);
    fclose(fd_from);

    return -1;
}

int copy_folder(const char* from, const char* to)
{
    int errcode = mkdir(to, 0700);
    if (errcode != 0)
    {
        return errcode;
    }

    DIR* owner dir = opendir(from);

    if (dir == NULL)
    {
        return errno;
    }

    struct dirent* dp;
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
        {
            /* skip self and parent */
            continue;
        }

        char fromlocal[MAX_PATH] = {0};
        snprintf(fromlocal, MAX_PATH, "%s/%s", from, dp->d_name);

        char tolocal[MAX_PATH] = {0};
        snprintf(tolocal, MAX_PATH, "%s/%s", to, dp->d_name);

        if (dp->d_type & DT_DIR)
        {
            errcode = copy_folder(fromlocal, tolocal);
        }
        else
        {
            errcode = copy_file(fromlocal, tolocal);
        }

        if (errcode != 0)
            break;
    }

    closedir(dir);
    return errcode;
}

#ifdef _WIN32
int get_self_path(char* buffer, int maxsize)
{
    DWORD r = GetModuleFileNameA(NULL, buffer, maxsize);
    return r;
}

#else

int get_self_path(char* buffer, int maxsize)
{

    memset(buffer, 0, maxsize); // readlink does not null terminate!
    if (readlink("/proc/self/exe", buffer, maxsize) == -1)
    {
        //perror("readlink");
        return 1;
    }
    else
    {
        //printf("%s\n", dest);
    }
    return 0;

}

#endif




#if !defined __EMSCRIPTEN__
char* dirname(char* path)
{
    int last = -1;
    for (int i = 0; path[i]; i++)
    {
        if (path[i] == '\\' || path[i] == '/')
            last = i;
    }

    if (last != -1)
    {
        path[last] = 0;
    }
    else
    {
        path[0] = 0;
    }
    return path;
}
#endif

#ifndef MOCKFILES

char* owner read_file(const char* const path)
{
    char* owner data = NULL;
    FILE* owner file = NULL;
    struct stat info = {0};

    if (stat(path, &info) != 0)
        return NULL;

    const int mem_size_bytes = sizeof(char) * info.st_size + 3 /*BOM*/ + 1 /* \0 */;

    data = malloc(mem_size_bytes);
    if (data == NULL)
        return NULL;

    file = fopen(path, "r");
    if (file == NULL)
    {
        free(data);
        return NULL;
    }

    /* first we read 3 bytes */
    size_t bytes_read = fread(data, 1, 3, file);

    if (bytes_read < 3)
    {
        /* we have less than 3 bytes - no BOM */

        data[bytes_read] = '\0';
        if (feof(file))
        {
            fclose(file);
            return data;
        }

        free(data);
        fclose(file);

        return NULL;
    }

    /* check byte order mark (BOM) */
    if ((unsigned char) data[0] == (unsigned char) 0xEF &&
        (unsigned char) data[1] == (unsigned char) 0xBB &&
        (unsigned char) data[2] == (unsigned char) 0xBF)
    {
        /* in this case we skip this BOM */
        size_t bytes_read_part2 = fread(&data[0], 1, info.st_size - 3, file);
        data[bytes_read_part2] = 0;

        fclose(file);
        return data;
    }

    size_t bytes_read_part2 = fread(&data[3], 1, info.st_size - 3, file);
    data[bytes_read_part2 + 3] = 0;

    fclose(file);
    return data;
}

#else

static const char* file_assert_h =
"\n"
"#ifdef NDEBUG\n"
"#define assert(...) ((void)0)"
"#else"
"#define assert(...) assert(__VA_ARGS__)\n"
"#endif\n"
"\n"
"";


static const char* file_stdio_h =
"#pragma once\n"
"#define _IOFBF 0x0000\n"
"#define _IOLBF 0x0040\n"
"#define _IONBF 0x0004\n"
"\n"
"#define BUFSIZ  512\n"
"\n"
"#define EOF    (-1)\n"
"\n"
"#define FILENAME_MAX    260\n"
"#define FOPEN_MAX       20\n"
"\n"
"#define L_tmpnam   260 // _MAX_PATH\n"
"\n"
"/* Seek method constants */\n"
"\n"
"#define SEEK_CUR    1\n"
"#define SEEK_END    2\n"
"#define SEEK_SET    0\n"
"\n"
"\n"
"#define TMP_MAX         2147483647\n"
"\n"
"\n"
"#define stdin  ((FILE*)0)\n"
"#define stdout ((FILE*)1)\n"
"#define stderr ((FILE*)2)\n"
"\n"
"typedef long long fpos_t;\n"
"typedef int FILE;\n"
"\n"
"extern FILE* stdin;\n"
"extern FILE* stdout;\n"
"extern FILE* stderr;\n"
"\n"
"typedef int size_t;\n"
"typedef void* va_list;\n"
"int remove(const char* filename);\n"
"int rename(const char* old, const char* news);\n"
"FILE* tmpfile(void);\n"
"char* tmpnam(char* s);\n"
"#if defined(__STDC_OWNERSHIP__) && defined(__OWNERSHIP_H__)\n"
"int fclose(FILE* _Owner stream);\n"
"#else\n"
"int fclose(FILE* stream);\n"
"#endif\n"
"int fflush(FILE* stream);\n"
"#if defined(__STDC_OWNERSHIP__) && defined(__OWNERSHIP_H__)\n"
"FILE* _Owner fopen(const char* restrict filename, const char* restrict mode);\n"
"FILE* _Owner freopen(const char* restrict filename, const char* restrict mode, FILE* restrict stream);\n"
"#else\n"
"FILE* fopen(const char* restrict filename, const char* restrict mode);\n"
"FILE* freopen(const char* restrict filename, const char* restrict mode, FILE* restrict stream);\n"
"#endif\n"
"void setbuf(FILE* restrict stream, char* restrict buf);\n"
"int setvbuf(FILE* restrict stream, char* restrict buf, int mode, size_t size);\n"
"int fprintf(FILE* restrict stream, const char* restrict format, ...);\n"
"int fscanf(FILE* restrict stream, const char* restrict format, ...);\n"
"int printf(const char* restrict format, ...);\n"
"int scanf(const char* restrict format, ...);\n"
"int snprintf(char* restrict s, size_t n, const char* restrict format, ...);\n"
"int sprintf(char* restrict s, const char* restrict format, ...);\n"
"int sscanf(const char* restrict s, const char* restrict format, ...);\n"
"int vfprintf(FILE* restrict stream, const char* restrict format, va_list arg);\n"
"int vfscanf(FILE* restrict stream, const char* restrict format, va_list arg);\n"
"int vprintf(const char* restrict format, va_list arg);\n"
"int vscanf(const char* restrict format, va_list arg);\n"
"int puts(const char* str);\n"
"int fputs(const char* restrict s, FILE* restrict stream);\n"
"int getc(FILE* stream);\n"
"int getchar(void);\n"
"int putc(int c, FILE* stream);\n"
"int putchar(int c);\n"
"int puts(const char* s);\n"
"int ungetc(int c, FILE* stream);\n"
"int fgetc(FILE* stream);\n"
"size_t fread(void* restrict ptr, size_t size, size_t nmemb, FILE* restrict stream);\n"
"size_t fwrite(const void* restrict ptr, size_t size, size_t nmemb, FILE* restrict stream);\n"
"int fgetpos(FILE* restrict stream, fpos_t* restrict pos);\n"
"int fseek(FILE* stream, long int offset, int whence);\n"
"int fsetpos(FILE* stream, const fpos_t* pos);\n"
"long int ftell(FILE* stream);\n"
"void rewind(FILE* stream);\n"
"void clearerr(FILE* stream);\n"
"int feof(FILE* stream);\n"
"int ferror(FILE* stream);\n"
"void perror(const char* s);\n"
"\n"
"\n"
"\n"
"#ifndef NULL\n"
"#define NULL ((void*)0)\n"
"#endif\n"
"";

static const char* file_errno_h =
"#pragma once\n"
"\n"
"int* _errno(void);\n"
"#define errno (*_errno())\n"
"\n"
"\n"
"#define EPERM           1\n"
"#define ENOENT          2\n"
"#define ESRCH           3\n"
"#define EINTR           4\n"
"#define EIO             5\n"
"#define ENXIO           6\n"
"#define E2BIG           7\n"
"#define ENOEXEC         8\n"
"#define EBADF           9\n"
"#define ECHILD          10\n"
"#define EAGAIN          11\n"
"#define ENOMEM          12\n"
"#define EACCES          13\n"
"#define EFAULT          14\n"
"#define EBUSY           16\n"
"#define EEXIST          17\n"
"#define EXDEV           18\n"
"#define ENODEV          19\n"
"#define ENOTDIR         20\n"
"#define EISDIR          21\n"
"#define ENFILE          23\n"
"#define EMFILE          24\n"
"#define ENOTTY          25\n"
"#define EFBIG           27\n"
"#define ENOSPC          28\n"
"#define ESPIPE          29\n"
"#define EROFS           30\n"
"#define EMLINK          31\n"
"#define EPIPE           32\n"
"#define EDOM            33\n"
"#define EDEADLK         36\n"
"#define ENAMETOOLONG    38\n"
"#define ENOLCK          39\n"
"#define ENOSYS          40\n"
"#define ENOTEMPTY       41\n"
"\n"
"\n"
"// Support EDEADLOCK for compatibility with older Microsoft C versions\n"
"#define EDEADLOCK       EDEADLK\n"
"\n"
"#define EADDRINUSE      100\n"
"#define EADDRNOTAVAIL   101\n"
"#define EAFNOSUPPORT    102\n"
"#define EALREADY        103\n"
"#define EBADMSG         104\n"
"#define ECANCELED       105\n"
"#define ECONNABORTED    106\n"
"#define ECONNREFUSED    107\n"
"#define ECONNRESET      108\n"
"#define EDESTADDRREQ    109\n"
"#define EHOSTUNREACH    110\n"
"#define EIDRM           111\n"
"#define EINPROGRESS     112\n"
"#define EISCONN         113\n"
"#define ELOOP           114\n"
"#define EMSGSIZE        115\n"
"#define ENETDOWN        116\n"
"#define ENETRESET       117\n"
"#define ENETUNREACH     118\n"
"#define ENOBUFS         119\n"
"#define ENODATA         120\n"
"#define ENOLINK         121\n"
"#define ENOMSG          122\n"
"#define ENOPROTOOPT     123\n"
"#define ENOSR           124\n"
"#define ENOSTR          125\n"
"#define ENOTCONN        126\n"
"#define ENOTRECOVERABLE 127\n"
"#define ENOTSOCK        128\n"
"#define ENOTSUP         129\n"
"#define EOPNOTSUPP      130\n"
"#define EOTHER          131\n"
"#define EOVERFLOW       132\n"
"#define EOWNERDEAD      133\n"
"#define EPROTO          134\n"
"#define EPROTONOSUPPORT 135\n"
"#define EPROTOTYPE      136\n"
"#define ETIME           137\n"
"#define ETIMEDOUT       138\n"
"#define ETXTBSY         139\n"
"#define EWOULDBLOCK     140\n"
"\n"
"";



static const char* file_string_h =
" \n"
"typedef int errno_t;\n"
"typedef unsigned long long size_t;\n"
"typedef unsigned long long rsize_t;\n"
"typedef unsigned short wchar_t;\n"
"void* memchr(void const* _Buf, int _Val, size_t _MaxCount);\n"
"int memcmp(void const* _Buf1, void const* _Buf2, size_t _Size);\n"
"void* memcpy(void* _Dst, void const* _Src, size_t _Size);\n"
"void* memmove(void* _Dst, void const* _Src, size_t _Size);\n"
"void* memset(void* _Dst, int _Val, size_t _Size);\n"
"char* strchr(char const* _Str, int _Val);\n"
"char* strrchr(char const* _Str, int _Ch);\n"
"char* strstr(char const* _Str, char const* _SubStr);\n"
"wchar_t* wcschr(wchar_t const* _Str, wchar_t _Ch);\n"
"wchar_t* wcsrchr(wchar_t const* _Str, wchar_t _Ch);\n"
"wchar_t* wcsstr(wchar_t const* _Str, wchar_t const* _SubStr);\n"
"static __inline errno_t memcpy_s(void* const _Destination, rsize_t const _DestinationSize, void const* const _Source, rsize_t const _SourceSize);\n"
"static __inline errno_t memmove_s(void* const _Destination, rsize_t const _DestinationSize, void const* const _Source, rsize_t const _SourceSize);\n"
"int _memicmp(void const* _Buf1, void const* _Buf2, size_t _Size);\n"
"void* memccpy(void* _Dst, void const* _Src, int _Val, size_t _Size);\n"
"int memicmp(void const* _Buf1, void const* _Buf2, size_t _Size);\n"
"errno_t wcscat_s(wchar_t* _Destination, rsize_t _SizeInWords, wchar_t const* _Source);\n"
"errno_t wcscpy_s(wchar_t* _Destination, rsize_t _SizeInWords, wchar_t const* _Source);\n"
"errno_t wcsncat_s(wchar_t* _Destination, rsize_t _SizeInWords, wchar_t const* _Source, rsize_t _MaxCount);\n"
"errno_t wcsncpy_s(wchar_t* _Destination, rsize_t _SizeInWords, wchar_t const* _Source, rsize_t _MaxCount);\n"
"wchar_t* wcstok_s(wchar_t* _String, wchar_t const* _Delimiter, wchar_t** _Context);\n"
"wchar_t* _wcsdup(wchar_t const* _String);\n"
"wchar_t* wcscat(wchar_t* _Destination, wchar_t const* _Source); int wcscmp(wchar_t const* _String1, wchar_t const* _String2);\n"
"wchar_t* wcscpy(wchar_t* _Destination, wchar_t const* _Source); size_t wcscspn(wchar_t const* _String, wchar_t const* _Control);\n"
"size_t wcslen(wchar_t const* _String);\n"
"size_t wcsnlen(wchar_t const* _Source, size_t _MaxCount);\n"
"static __inline size_t wcsnlen_s(wchar_t const* _Source, size_t _MaxCount);\n"
"wchar_t* wcsncat(wchar_t* _Destination, wchar_t const* _Source, size_t _Count);\n"
"int wcsncmp(wchar_t const* _String1, wchar_t const* _String2, size_t _MaxCount);\n"
"wchar_t* wcsncpy(wchar_t* _Destination, wchar_t const* _Source, size_t _Count);\n"
"wchar_t* wcspbrk(wchar_t const* _String, wchar_t const* _Control);\n"
"size_t wcsspn(wchar_t const* _String, wchar_t const* _Control);\n"
"wchar_t* wcstok(wchar_t* _String, wchar_t const* _Delimiter, wchar_t** _Context);\n"
"size_t wcsxfrm(wchar_t* _Destination, wchar_t const* _Source, size_t _MaxCount);\n"
"int wcscoll(wchar_t const* _String1, wchar_t const* _String2);\n"
"wchar_t* wcsdup(wchar_t const* _String);\n"
"int wcsicmp(wchar_t const* _String1, wchar_t const* _String2);\n"
"int wcsnicmp(wchar_t const* _String1, wchar_t const* _String2, size_t _MaxCount);\n"
"wchar_t* wcsnset(wchar_t* _String, wchar_t _Value, size_t _MaxCount);\n"
"wchar_t* wcsrev(wchar_t* _String);\n"
"wchar_t* wcsset(wchar_t* _String, wchar_t _Value);\n"
"wchar_t* wcslwr(wchar_t* _String); wchar_t* wcsupr(wchar_t* _String);\n"
"int wcsicoll(wchar_t const* _String1, wchar_t const* _String2);\n"
"char* strtok_s(char* _String, char const* _Delimiter, char** _Context);\n"
"void* _memccpy(void* _Dst, void const* _Src, int _Val, size_t _MaxCount);\n"
"char* strcat(char* _Destination, char const* _Source);\n"
"int strcmp(char const* _Str1, char const* _Str2);\n"
"int strcoll(char const* _String1, char const* _String2);\n"
"char* strerror(int _ErrorMessage);\n"
"size_t strlen(char const* _Str);\n"
"char* strncat(char* _Destination, char const* _Source, size_t _Count);\n"
"int strncmp(char const* _Str1, char const* _Str2, size_t _MaxCount);\n"
"char* strncpy(char* _Destination, char const* _Source, size_t _Count);\n"
"size_t strnlen(char const* _String, size_t _MaxCount);\n"
"static __inline size_t strnlen_s(char const* _String, size_t _MaxCount);\n"
"char* strpbrk(char const* _Str, char const* _Control);\n"
"size_t strspn(char const* _Str, char const* _Control);\n"
"char* strtok(char* _String, char const* _Delimiter);\n"
"#if defined(__STDC_OWNERSHIP__) && defined(__OWNERSHIP_H__)\n"
"char* _Owner strdup(char const* _String);\n"
"#else\n"
"char* strdup(char const* _String);\n"
"#endif\n"
"int strcmpi(char const* _String1, char const* _String2);\n"
"int stricmp(char const* _String1, char const* _String2);\n"
"char* strlwr(char* _String);\n"
"int strnicmp(char const* _String1, char const* _String2, size_t _MaxCount);\n"
"char* strnset(char* _String, int _Value, size_t _MaxCount);\n"
"char* strrev(char* _String);\n"
"char* strset(char* _String, int _Value); char* strupr(char* _String);";


static const char* file_math_h
=
"#pragma once\n"
"\n"
"double acos(double __x);\n"
"double asin(double __x);\n"
"double atan(double __x);\n"
"double atan2(double __y, double __x);\n"
"double cos(double __x);\n"
"double sin(double __x);\n"
"double tan(double __x);\n"
"double cosh(double __x);\n"
"double sinh(double __x);\n"
"double tanh(double __x);\n"
"double acosh(double __x);\n"
"double asinh(double __x);\n"
"double atanh(double __x);\n"
"double exp(double __x);\n"
"double frexp(double __x, int* __exponent);\n"
"double ldexp(double __x, int __exponent);\n"
"double log(double __x);\n"
"double log10(double __x);\n"
"double modf(double __x, double* __iptr);\n"
"double expm1(double __x);\n"
"double log1p(double __x);\n"
"double logb(double __x);\n"
"double exp2(double __x);\n"
"double log2(double __x);\n"
"double pow(double __x, double __y);\n"
"double sqrt(double __x);\n"
"double hypot(double __x, double __y);\n"
"double cbrt(double __x);\n"
"double ceil(double __x);\n"
"double fabs(double __x);\n"
"double floor(double __x);\n"
"double fmod(double __x, double __y);\n"
"int isinf(double __value);\n"
"int finite(double __value);\n"
"double drem(double __x, double __y);\n"
"double significand(double __x);\n"
"double copysign(double __x, double __y);\n"
"double nan(const char* __tagb);\n"
"int isnan(double __value);\n"
"double j0(double);\n"
"double j1(double);\n"
"double jn(int, double);\n"
"double y0(double);\n"
"double y1(double);\n"
"double yn(int, double);\n"
"double erf(double);\n"
"double erfc(double);\n"
"double lgamma(double);\n"
"double tgamma(double);\n"
"double gamma(double);\n"
"double lgamma_r(double, int* __signgamp);\n"
"double rint(double __x);\n"
"double nextafter(double __x, double __y);\n"
"double nexttoward(double __x, long double __y);\n"
"double remainder(double __x, double __y);\n"
"double scalbn(double __x, int __n);\n"
"int ilogb(double __x);\n"
"double scalbln(double __x, long int __n);\n"
"double nearbyint(double __x);\n"
"double round(double __x);\n"
"double trunc(double __x);\n"
"double remquo(double __x, double __y, int* __quo);\n"
"long int lrint(double __x);\n"
"long long int llround(double __x);\n"
"double fdim(double __x, double __y);\n"
"double fmax(double __x, double __y);\n"
"double fmin(double __x, double __y);\n"
"double fma(double __x, double __y, double __z);\n"
"double scalb(double __x, double __n);\n"
"float acosf(float __x);\n"
"float asinf(float __x);\n"
"float atanf(float __x);\n"
"float atan2f(float __y, float __x);\n"
"float cosf(float __x);\n"
"float sinf(float __x);\n"
"float tanf(float __x);\n"
"float coshf(float __x);\n"
"float sinhf(float __x);\n"
"float tanhf(float __x);\n"
"float acoshf(float __x);\n"
"float asinhf(float __x);\n"
"float atanhf(float __x);\n"
"float expf(float __x);\n"
"float frexpf(float __x, int* __exponent);\n"
"float ldexpf(float __x, int __exponent);\n"
"float logf(float __x);\n"
"float log10f(float __x); float __log10f(float __x);\n"
"float modff(float __x, float* __iptr);\n"
"float expm1f(float __x);\n"
"float log1pf(float __x);\n"
"float logbf(float __x);\n"
"float exp2f(float __x);\n"
"float log2f(float __x);\n"
"float powf(float __x, float __y);\n"
"float sqrtf(float __x);\n"
"float hypotf(float __x, float __y);\n"
"float cbrtf(float __x);\n"
"float ceilf(float __x);\n"
"float fabsf(float __x);\n"
"float floorf(float __x);\n"
"float fmodf(float __x, float __y); \n"
"int isinff(float __value);\n"
"int finitef(float __value);\n"
"float dremf(float __x, float __y);\n"
"float significandf(float __x); \n"
"float copysignf(float __x, float __y); \n"
"float nanf(const char* __tagb); \n"
"int isnanf(float __value);\n"
"float j0f(float); \n"
"float j1f(float); \n"
"float jnf(int, float); \n"
"float y0f(float); \n"
"float y1f(float); \n"
"float ynf(int, float); \n"
"float erff(float); \n"
"float erfcf(float);\n"
"float lgammaf(float);\n"
"float tgammaf(float);\n"
"float gammaf(float); \n"
"float lgammaf_r(float, int* __signgamp); \n"
"float rintf(float __x); \n"
"float nextafterf(float __x, float __y); \n"
"float nexttowardf(float __x, long double __y); \n"
"float remainderf(float __x, float __y); \n"
"float scalbnf(float __x, int __n); \n"
"int ilogbf(float __x); \n"
"float scalblnf(float __x, long int __n); \n"
"float nearbyintf(float __x); \n"
"float roundf(float __x); \n"
"float truncf(float __x); \n"
"float remquof(float __x, float __y, int* __quo); \n"
"long int lrintf(float __x); \n"
"long long int llroundf(float __x); \n"
"float fdimf(float __x, float __y);\n"
"float fmaxf(float __x, float __y); \n"
"float fminf(float __x, float __y);\n"
"float fmaf(float __x, float __y, float __z); \n"
"float scalbf(float __x, float __n); \n"
"long double acosl(long double __x); \n"
"long double asinl(long double __x); \n"
"long double atanl(long double __x); \n"
"long double atan2l(long double __y, long double __x); \n"
"long double cosl(long double __x); \n"
"long double sinl(long double __x); \n"
"long double tanl(long double __x); \n"
"long double coshl(long double __x);\n"
"long double sinhl(long double __x);\n"
"long double tanhl(long double __x);\n"
"long double acoshl(long double __x); \n"
"long double asinhl(long double __x); \n"
"long double atanhl(long double __x); \n"
"long double expl(long double __x); \n"
"long double frexpl(long double __x, int* __exponent); \n"
"long double ldexpl(long double __x, int __exponent); \n"
"long double logl(long double __x); \n"
"long double log10l(long double __x); \n"
"long double modfl(long double __x, long double* __iptr); \n"
"long double expm1l(long double __x); \n"
"long double log1pl(long double __x); \n"
"long double logbl(long double __x); \n"
"long double exp2l(long double __x); \n"
"long double log2l(long double __x); \n"
"long double powl(long double __x, long double __y); \n"
"long double sqrtl(long double __x); \n"
"long double hypotl(long double __x, long double __y); \n"
"long double cbrtl(long double __x); \n"
"long double ceill(long double __x); \n"
"long double fabsl(long double __x); \n"
"long double floorl(long double __x);\n"
"long double fmodl(long double __x, long double __y); \n"
"int isinfl(long double __value);\n"
"int finitel(long double __value);\n"
"long double dreml(long double __x, long double __y); \n"
"long double significandl(long double __x); \n"
"long double copysignl(long double __x, long double __y); \n"
"long double nanl(const char* __tagb); \n"
"int isnanl(long double __value);\n"
"long double j0l(long double); \n"
"long double j1l(long double); \n"
"long double jnl(int, long double);\n"
"long double y0l(long double); \n"
"long double y1l(long double); \n"
"long double ynl(int, long double);\n"
"long double erfl(long double); \n"
"long double erfcl(long double);\n"
"long double lgammal(long double); \n"
"long double tgammal(long double); \n"
"long double gammal(long double); \n"
"long double lgammal_r(long double, int* __signgamp); \n"
"long double rintl(long double __x); \n"
"long double nextafterl(long double __x, long double __y); \n"
"long double nexttowardl(long double __x, long double __y);\n"
"long double remainderl(long double __x, long double __y); \n"
"long double scalbnl(long double __x, int __n); \n"
"int ilogbl(long double __x); \n"
"long double scalblnl(long double __x, long int __n); \n"
"long double nearbyintl(long double __x);\n"
"long double roundl(long double __x);\n"
"long double truncl(long double __x);\n"
"long double remquol(long double __x, long double __y, int* __quo);\n"
"long int lrintl(long double __x);\n"
"long long int llroundl(long double __x);\n"
"long double fdiml(long double __x, long double __y);\n"
"long double fmaxl(long double __x, long double __y);\n"
"long double fminl(long double __x, long double __y);\n"
"long double fmal(long double __x, long double __y, long double __z);\n"
"long double scalbl(long double __x, long double __n);\n"
"";

static const char* file_stdlib_h =
"typedef long long fpos_t;\n"
"typedef unsigned size_t;\n"
"\n"
"#define NULL ((void*)0)\n"
"typedef int wchar_t;\n"
"[[nodiscard]] double atof(const char* nptr);\n"
"[[nodiscard]] int atoi(const char* nptr);\n"
"[[nodiscard]] long int atol(const char* nptr);\n"
"[[nodiscard]] long long int atoll(const char* nptr);\n"
"double strtod(const char* restrict nptr, char** restrict endptr);\n"
"float strtof(const char* restrict nptr, char** restrict endptr);\n"
"long double strtold(const char* restrict nptr, char** restrict endptr);\n"
"long int strtol(const char* restrict nptr, char** restrict endptr, int base);\n"
"long long int strtoll(const char* restrict nptr, char** restrict endptr, int base);\n"
"unsigned long int strtoul(const char* restrict nptr, char** restrict endptr, int base);\n"
"unsigned long long int strtoull(const char* restrict nptr, char** restrict endptr, int base);\n"
"int rand(void);\n"
"void srand(unsigned int seed);\n"
"void* aligned_alloc(size_t alignment, size_t size);\n"
"#if defined(__STDC_OWNERSHIP__) && defined(__OWNERSHIP_H__)\n"
"[[nodiscard]] void* _Owner calloc(size_t nmemb, size_t size);\n"
"void free(void* _Owner ptr);\n"
"[[nodiscard]] void* _Owner malloc(size_t size);\n"
"[[nodiscard]] void* _Owner realloc(void* ptr, size_t size);\n"
"#else\n"
"[[nodiscard]] void* calloc(size_t nmemb, size_t size);\n"
"void free(void* ptr);\n"
"[[nodiscard]] void* malloc(size_t size);\n"
"[[nodiscard]] void* realloc(void* ptr, size_t size);\n"
"#endif\n"
"[[noreturn]] void abort(void);\n"
"int atexit(void (*func)(void));\n"
"int at_quick_exit(void (*func)(void));\n"
"[[noreturn]] void exit(int status);\n"
"[[noreturn]] void _Exit(int status);\n"
"char* getenv(const char* name);\n"
"[[noreturn]] void quick_exit(int status);\n"
"int system(const char* string);";

static const char* file_stddef_h =
"\n"
"typedef long int ptrdiff_t;\n"
"typedef long unsigned int size_t;\n"
"typedef int wchar_t;\n"
"typedef struct {\n"
"  long long __max_align_ll;\n"
"  long double __max_align_ld;\n"
"} max_align_t;\n"
"\n"
"typedef typeof(nullptr) nullptr_t;\n"
"\n";

const char* file_ownership_h = 
 "#ifndef __OWNERSHIP_H__\n"
 "#define __OWNERSHIP_H__\n"
 "\n"
 "#ifdef __STDC_OWNERSHIP__\n"
 "#define out _Out\n"
 "#define opt _Opt\n"
 "#define owner _Owner\n"
 "#define obj_owner  _Obj_owner\n"
 "#define view _View\n"
 "#define unchecked \"unchecked\"\n"
 "\n"
 "#else\n"
 "#define out \n"
 "#define opt \n"
 "#define owner\n"
 "#define obj_owner\n"
 "#define view\n"
 "#define static_debug(x)\n"
 "#define static_set(x, s)\n"
 "#define unchecked\n"
 "#endif\n"
 "\n"
 "#endif\n"
 "\n"
 "";



char* owner read_file(const char* path)
{
    if (strcmp(path, "c:/stdio.h") == 0)
        return strdup(file_stdio_h);
    else if (strcmp(path, "c:/stdlib.h") == 0)
        return strdup(file_stdlib_h);
    else if (strcmp(path, "c:/stddef.h") == 0)
        return strdup(file_stddef_h);
    else if (strcmp(path, "c:/math.h") == 0)
        return strdup(file_math_h);
    else if (strcmp(path, "c:/errno.h") == 0)
        return strdup(file_errno_h);
    else if (strcmp(path, "c:/string.h") == 0)
        return strdup(file_string_h);
    else if (strcmp(path, "c:/assert.h") == 0)
        return strdup(file_assert_h);
    else if (strcmp(path, "c:/ownership.h") == 0)
        return strdup(file_ownership_h);
    printf("read %s\n", path);
    return NULL;
}
#endif





bool is_ownership_error(enum error e)
{
    switch (e)
    {
        case C_OWNERSHIP_MISSING_OWNER_QUALIFIER:
        case C_OWNERSHIP_NOT_OWNER:
        case C_OWNERSHIP_USING_TEMPORARY_OWNER:
        case C_OWNERSHIP_MOVE_ASSIGNMENT_OF_NON_OWNER:        
        case C_OWNERSHIP_NON_OWNER_TO_OWNER_ASSIGN:
        case C_OWNERSHIP_FLOW_MISSING_DTOR:
            return true;
    }
    return false;
}

static struct w {
    enum warning w;
    const char* name;
}
s_warnings[] = {
    {W_UNUSED_VARIABLE, "unused-variable"},
    {W_DEPRECATED, "deprecated"},
    {W_ENUN_CONVERSION,"enum-conversion"},
    {W_NON_NULL, "nonnull"},
    {W_ADDRESS, "address"},
    {W_UNUSED_PARAMETER, "unused-parameter"},
    {W_DECLARATOR_HIDE, "hide-declarator"},
    {W_TYPEOF_ARRAY_PARAMETER, "typeof-parameter"},
    {W_ATTRIBUTES, "attributes"},
    {W_UNUSED_VALUE, "unused-value"},
    {W_STYLE, "style"},
    {W_DISCARDED_QUALIFIERS, "discarded-qualifiers"},
    {W_UNINITIALZED, "uninitialized"},
    {W_RETURN_LOCAL_ADDR, "return-local-addr"}
};

enum warning  get_warning_flag(const char* wname)
{

    for (int j = 0; j < sizeof(s_warnings) / sizeof(s_warnings[0]); j++)
    {
        if (strncmp(s_warnings[j].name, wname, strlen(s_warnings[j].name)) == 0)
        {
            return s_warnings[j].w;
        }
    }
    return 0;
}

const char* get_warning_name(enum warning w)
{
    int lower_index = 0;
    int upper_index = sizeof(s_warnings) / sizeof(s_warnings[0]) - 1;

    while (lower_index <= upper_index)
    {
        const int mid = (lower_index + upper_index) / 2;
        const int cmp = w - s_warnings[mid].w;

        if (cmp == 0)
        {
            return s_warnings[mid].name;
        }
        else if (cmp < 0)
        {
            upper_index = mid - 1;
        }
        else
        {
            lower_index = mid + 1;
        }
    }

    assert(false);
    return "";
}

int fill_options(struct options* options,
    int argc,
    const char** argv)
{

    /*
       default at this moment is same as -Wall
    */
    options->enabled_warnings_stack[0] = ~0;
    options->enabled_warnings_stack[0] &= ~(W_STYLE | W_UNUSED_PARAMETER | W_UNUSED_VARIABLE); //default is OFF
    
    
    

#ifdef __EMSCRIPTEN__
    options->flow_analysis = true;
#endif

    /*first loop used to collect options*/
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] != '-')
            continue;

        if (argv[i][1] == 'I' ||
            argv[i][1] == 'D')
        {
            /*
              Valid, but handled with preprocessor
            */
            continue;
        }

        if (strcmp(argv[i], "-no-output") == 0)
        {
            options->no_output = true;
            continue;
        }

        if (strcmp(argv[i], "-o") == 0)
        {
            if (i + 1 < argc)
            {
                strcpy(options->output, argv[i + 1]);
                i++;
            }
            else
            {
                //ops
            }
            continue;
        }
        
        if (strcmp(argv[i], "-showIncludes") == 0)
        {
            options->show_includes = true;
            continue;
        }
        if (strcmp(argv[i], "-E") == 0)
        {
            options->preprocess_only = true;
            continue;
        }

        if (strcmp(argv[i], "-sarif") == 0)
        {
            options->sarif_output = true;
            continue;
        }

        if (strcmp(argv[i], "-analyze") == 0)
        {
            options->flow_analysis = true;
            continue;
        }

        if (strcmp(argv[i], "-remove-comments") == 0)
        {
            options->remove_comments = true;
            continue;
        }

        if (strcmp(argv[i], "-direct-compilation") == 0 ||
            strcmp(argv[i], "-rm") == 0)
        {
            options->direct_compilation = true;
            continue;
        }

        if (strcmp(argv[i], "-fi") == 0)
        {
            options->format_input = true;
            continue;
        }

        if (strcmp(argv[i], "-fo") == 0)
        {
            options->format_ouput = true;
            continue;
        }

        if (strcmp(argv[i], "-nullchecks") == 0)
        {
            options->null_checks = true;
            continue;
        }

        if (strcmp(argv[i], "-msvc-output") == 0)
        {
            options->visual_studio_ouput_format = true;
            continue;
        }


        //
        if (strcmp(argv[i], "-style=cake") == 0)
        {
            options->style = STYLE_CAKE;
            continue;
        }

        if (strcmp(argv[i], "-style=gnu") == 0)
        {
            options->style = STYLE_GNU;
            continue;
        }

        if (strcmp(argv[i], "-style=microsoft") == 0)
        {
            options->style = STYLE_GNU;
            continue;
        }

        //
        if (strcmp(argv[i], "-target=c89") == 0)
        {
            options->target = LANGUAGE_C89;
            continue;
        }

        if (strcmp(argv[i], "-target=c99") == 0)
        {
            options->target = LANGUAGE_C99;
            continue;
        }
        if (strcmp(argv[i], "-target=c11") == 0)
        {
            options->target = LANGUAGE_C11;
            continue;
        }
        if (strcmp(argv[i], "-target=c2x") == 0)
        {
            options->target = LANGUAGE_C2X;
            continue;
        }
        if (strcmp(argv[i], "-target=cxx") == 0)
        {
            options->target = LANGUAGE_CXX;
            continue;
        }



        //
        if (strcmp(argv[i], "-std=c99") == 0)
        {
            options->input = LANGUAGE_C99;
            continue;
        }
        if (strcmp(argv[i], "-std=c11") == 0)
        {
            options->input = LANGUAGE_C11;
            continue;
        }
        if (strcmp(argv[i], "-std=c2x") == 0)
        {
            options->input = LANGUAGE_C2X;
            continue;
        }
        if (strcmp(argv[i], "-std=cxx") == 0)
        {
            options->input = LANGUAGE_CXX;
            continue;
        }

        //warnings
        if (argv[i][1] == 'W')
        {
            if (strcmp(argv[i], "-Wall") == 0)
            {
                options->enabled_warnings_stack[0] = ~0;
                continue;
            }
            const bool disable_warning = (argv[i][2] == 'n' && argv[i][3] == 'o');

            enum warning  w = 0;

            if (disable_warning)
                w = get_warning_flag(argv[i] + 5);
            else
                w = get_warning_flag(argv[i] + 2);

            if (w == 0)
            {
                printf("unknown warning '%s'", argv[i]);
                return 1;
            }


            if (disable_warning)
            {
                options->enabled_warnings_stack[0] &= ~w;
            }
            else
            {
                options->enabled_warnings_stack[0] |= w;
            }
            continue;
        }

        printf("unknown option '%s'", argv[i]);
        return 1;
    }
    return 0;
}


void print_help()
{
    const char* options =
        "cake [options] source1.c source2.c ...\n"
        "\n"
        WHITE "SAMPLES\n" RESET
        "\n"
        WHITE "    cake source.c\n" RESET
        "    Compiles source.c and outputs /out/source.c\n"
        "\n"
        WHITE "    cake -target=C11 source.c\n" RESET
        "    Compiles source.c and outputs C11 code at /out/source.c\n"
        "\n"
        WHITE "cake file.c -o file.cc && cl file.cc\n" RESET
        "    Compiles file.c and outputs file.cc then use cl to compile file.cc\n"
        "\n"
        WHITE "cake file.c -direct-compilation -o file.cc && cl file.cc\n" RESET
        "    Compiles file.c and outputs file.cc for direct compilation then use cl to compile file.cc\n"
        "\n"
        WHITE "OPTIONS\n" RESET
        "\n"
        WHITE "  -I                   " RESET " Adds a directory to the list of directories searched for include files \n"
        "                        (On windows, if you run cake at the visual studio command prompt cake \n"
        "                        uses the same include files used by msvc )\n"
        "\n"
        WHITE "  -no-output            " RESET "Cake will not generate ouput\n"
        "\n"
        WHITE "  -D                    " RESET "Defines a preprocessing symbol for a source file \n"
        "\n"
        WHITE "  -E                    " RESET "Copies preprocessor output to standard output \n"
        "\n"
        WHITE "  -o name.c             " RESET "Defines the ouput name. used when we compile one file\n"
        "\n"
        WHITE "  -remove-comments      " RESET "Remove all comments from the ouput file \n"
        "\n"
        WHITE "  -direct-compilation   " RESET "output without macros/preprocessor parts\n"
        "\n"
        WHITE "  -target=standard      " RESET "Output target C standard (c89, c99, c11, c2x, cxx) \n"
        "                        C99 is the default and C89 (ANSI C) is the minimum target \n"
        "\n"
        WHITE "  -std=standard         " RESET "Assume that the input sources are for standard (c89, c99, c11, c2x, cxx) \n"
        "                        (not implemented yet, input is considered C23)                    \n"
        "\n"
        WHITE "  -fi                   " RESET "Format input (format before language convertion)\n"
        "\n"
        WHITE "  -fo                   " RESET "Format output (format after language convertion, result parsed again)\n"
        "\n"
        WHITE "  -no-discard           " RESET "Makes [[nodiscard]] default implicitly \n"
        "\n"
        WHITE "  -Wname -Wno-name      " RESET "Enables or disable warning\n"
        "\n"
        WHITE "  -sarif                " RESET "Generates sarif files\n"
        "\n"
        WHITE "  -msvc-output          " RESET "Ouput is compatible with visual studio\n"
        "\n"
        "More details at http://thradams.com/cake/manual.html\n"
        ;

    printf("%s", options);
}





#include <limits.h>


//#pragma once


//#pragma once


struct parser_ctx;


enum type_category
{
    TYPE_CATEGORY_ITSELF,
    TYPE_CATEGORY_FUNCTION,
    TYPE_CATEGORY_ARRAY,
    TYPE_CATEGORY_POINTER,    
};


enum attribute_flags
{
    STD_ATTRIBUTE_NONE = 0,
    STD_ATTRIBUTE_DEPRECATED = 1 << 0,
    STD_ATTRIBUTE_FALLTHROUGH = 1 << 1,
    STD_ATTRIBUTE_MAYBE_UNUSED = 1 << 2,
    STD_ATTRIBUTE_NODISCARD = 1 << 3,
    STD_ATTRIBUTE_NORETURN = 1 << 4,
    STD_ATTRIBUTE_UNSEQUENCED = 1 << 5,
    STD_ATTRIBUTE_REPRODUCIBLE = 1 << 6,
    CAKE_ATTRIBUTE_IMPLICT= 1 << 7,
    /*
     1 == 2 results in int in C
     lets add extra flag here
     not sure what is the best place to put in
     type specifier my generate some error
    */
    CAKE_HIDDEN_ATTRIBUTE_LIKE_BOOL = 1 << 25,
    // 'a'
    CAKE_HIDDEN_ATTRIBUTE_LIKE_CHAR = 1 << 26
};

enum type_specifier_flags
{
    TYPE_SPECIFIER_NONE = 0,
    TYPE_SPECIFIER_VOID = 1 << 0,
    TYPE_SPECIFIER_CHAR = 1 << 1,
    TYPE_SPECIFIER_SHORT = 1 << 2,
    TYPE_SPECIFIER_INT = 1 << 3,
    TYPE_SPECIFIER_LONG = 1 << 4,

    TYPE_SPECIFIER_FLOAT = 1 << 5,
    TYPE_SPECIFIER_DOUBLE = 1 << 6,
    TYPE_SPECIFIER_SIGNED = 1 << 7,
    TYPE_SPECIFIER_UNSIGNED = 1 << 8,
    TYPE_SPECIFIER_BOOL = 1 << 9,
    TYPE_SPECIFIER_COMPLEX = 1 << 10,
    TYPE_SPECIFIER_DECIMAL32 = 1 << 11,
    TYPE_SPECIFIER_DECIMAL64 = 1 << 12,
    TYPE_SPECIFIER_DECIMAL128 = 1 << 13,
    TYPE_SPECIFIER_ATOMIC = 1 << 14,
    TYPE_SPECIFIER_STRUCT_OR_UNION = 1 << 15,
    TYPE_SPECIFIER_ENUM = 1 << 16,
    TYPE_SPECIFIER_TYPEDEF = 1 << 17,

    //MICROSOFT
    TYPE_SPECIFIER_INT8 = 1 << 18,
    TYPE_SPECIFIER_INT16 = 1 << 19,
    TYPE_SPECIFIER_INT32 = 1 << 20,
    TYPE_SPECIFIER_INT64 = 1 << 21,

    TYPE_SPECIFIER_LONG_LONG = 1 << 22,

    TYPE_SPECIFIER_TYPEOF = 1 << 23,

    TYPE_SPECIFIER_NULLPTR_T = 1 << 24,


};

enum type_qualifier_flags
{
    TYPE_QUALIFIER_NONE,
    TYPE_QUALIFIER_CONST = 1 << 0,
    TYPE_QUALIFIER_RESTRICT = 1 << 1,
    TYPE_QUALIFIER_VOLATILE = 1 << 2,
    TYPE_QUALIFIER__ATOMIC = 1 << 3 , 
    
    /*ownership extensions*/
    TYPE_QUALIFIER_OWNER = 1 << 4,    
    TYPE_QUALIFIER_OBJ_OWNER = 1 << 5,   
    TYPE_QUALIFIER_VIEW = 1 << 6,
    TYPE_QUALIFIER_OPT = 1 << 7,
    TYPE_QUALIFIER_NOT_NULL = 1 << 8,
    TYPE_QUALIFIER_OUT = 1 << 9,
};

enum storage_class_specifier_flags
{
    STORAGE_SPECIFIER_NONE = 0,
    STORAGE_SPECIFIER_TYPEDEF = 1 << 0,
    STORAGE_SPECIFIER_EXTERN = 1 << 1,
    STORAGE_SPECIFIER_STATIC = 1 << 2,
    STORAGE_SPECIFIER_THREAD_LOCAL = 1 << 3,
    STORAGE_SPECIFIER_AUTO = 1 << 4,
    STORAGE_SPECIFIER_REGISTER = 1 << 5,
    STORAGE_SPECIFIER_CONSTEXPR = 1 << 6,
    
    /*extra flag just to annotate this*/
    STORAGE_SPECIFIER_CONSTEXPR_STATIC = 1 << 7,

    STORAGE_SPECIFIER_PARAMETER = 1 << 11,
    STORAGE_SPECIFIER_AUTOMATIC_STORAGE = 1 << 12,
    STORAGE_SPECIFIER_FUNCTION_RETURN = 1 << 13,
    STORAGE_SPECIFIER_FUNCTION_RETURN_NODISCARD = 1 << 14,
};


struct declarator;
struct type;


struct type_list {
    struct type* owner head;
    struct type* tail;
};

void type_list_push_back(struct type_list* books, struct type* owner new_book);
void type_list_push_front(struct type_list* books, struct type* owner new_book);


struct param;

struct param_list {
    bool is_var_args;
    bool is_void;
    struct param* owner head;
    struct param* tail;
};

void param_list_destroy(struct param_list* obj_owner p);

struct type 
{
    enum type_category category;

    enum attribute_flags  attributes_flags;
    enum type_specifier_flags type_specifier_flags;
    enum type_qualifier_flags type_qualifier_flags;
    enum storage_class_specifier_flags storage_class_specifier_flags;

    const char* owner name_opt;

    struct struct_or_union_specifier* struct_or_union_specifier;
    const struct enum_specifier* enum_specifier;

    int array_size;
    bool static_array;
    
    /*
      address_of is true when the type is created by address of operator.
      This is used to create obj_owner pointer.
    */
    bool address_of;
    
    struct param_list params;
    struct type* owner next;
};

const struct param_list* type_get_func_or_func_ptr_params(const struct type* p_type);

struct param {
    struct type type;
    struct param* owner next;
};

struct expression;

void check_assigment(struct parser_ctx* ctx,
    struct type* left_type,
    struct expression* right,    
    bool return_assignment);

void print_type(struct osstream* ss, const  struct type* type);
void print_item(struct osstream* ss, bool* first, const char* item);
struct type type_dup(const struct type* p_type);
void type_set(struct type* a, const struct type* b);

void type_destroy( struct type* obj_owner p_type);




int type_common(struct type* p_type1, struct type* p_type2, struct type* out);
struct type get_array_item_type(const struct type* p_type);
struct type type_remove_pointer(const struct type* p_type);
int type_get_array_size(const struct type* p_type);
int type_set_array_size(struct type* p_type, int size);

bool type_is_enum(const struct type* p_type);
bool type_is_array(const struct type* p_type);

bool type_is_out(const struct type* p_type);
bool type_is_const(const struct type* p_type);
bool type_is_owner(const struct type* p_type);
bool type_is_obj_owner(const struct type* p_type);
bool type_is_any_owner(const struct type* p_type);
bool type_is_lvalue(const struct type* p_type);
bool type_is_pointer_to_const(const struct type* p_type);
bool type_is_pointer(const struct type* p_type);
bool type_is_nullptr_t(const struct type* p_type);
bool type_is_void_ptr(const struct type* p_type);
bool type_is_integer(const struct type* p_type);
bool type_is_unsigned_integer(const struct type* p_type);
bool type_is_floating_point(const struct type* p_type);

bool type_is_arithmetic(const struct type* p_type);

bool type_is_struct_or_union(const struct type* p_type);
bool type_is_void(const struct type* p_type);
bool type_is_function_or_function_pointer(const struct type* p_type);
bool type_is_function(const struct type* p_type);
bool type_is_nodiscard(const struct type* p_type);

bool type_is_deprecated(const struct type* p_type);
bool type_is_maybe_unused(const struct type* p_type);
bool type_is_pointer_or_array(const struct type* p_type);
bool type_is_same(const struct type* a, const struct type* b, bool compare_qualifiers);
bool type_is_scalar(const struct type* p_type);
bool type_has_attribute(const struct type* p_type, enum attribute_flags attributes);
bool type_is_bool(const struct type* p_type);

struct type type_get_enum_type(const struct type* p_type);

struct argument_expression;
void check_argument_and_parameter(struct parser_ctx* ctx,
    struct argument_expression* current_argument,
    struct type* paramer_type,
    int param_num);

struct type type_convert_to(const struct type* p_type, enum language_version target);
struct type type_lvalue_conversion(struct type* p_type);
void type_remove_qualifiers(struct type* p_type);
void type_add_const(struct type* p_type);
void type_swap(struct type* a, struct type* b);


struct type type_remove_pointer(const struct type* p_type);
struct type get_array_item_type(const struct type* p_type);

struct type type_param_array_to_pointer(const struct type* p_type);

struct type type_make_literal_string(int size, enum type_specifier_flags chartype);
struct type type_make_int();
struct type type_make_int_bool_like();
struct type type_make_size_t();
struct type type_make_enumerator(const struct enum_specifier* enum_specifier);
struct type make_void_type();
struct type make_void_ptr_type();

struct type get_function_return_type(const struct type* p_type);

int type_get_sizeof(const struct type* p_type);
int type_get_num_members(const struct type* type);

int type_get_alignof(const struct type* p_type);
unsigned int type_get_hashof(struct parser_ctx* ctx, struct type* p_type);

struct type type_add_pointer(const struct type* p_type);
void type_print(const struct type* a);
enum type_category type_get_category(const struct type* p_type);
void print_type_qualifier_specifiers(struct osstream* ss, const struct type* type);


void type_visit_to_mark_anonymous(struct type* p_type);

void type_set_qualifiers_using_declarator(struct type* p_type, struct declarator* pdeclarator);
void type_merge_qualifiers_using_declarator(struct type* p_type, struct declarator* pdeclarator);


void print_type_declarator(struct osstream* ss, const struct type* p_type);
void type_remove_names(struct type* p_type);
const struct type* type_get_specifer_part(const struct type* p_type);


struct parser_ctx;

enum expression_type
{
    PRIMARY_IDENTIFIER,
    

    PRIMARY_EXPRESSION_ENUMERATOR,
    PRIMARY_EXPRESSION_DECLARATOR,
    PRIMARY_EXPRESSION_STRING_LITERAL,
    PRIMARY_EXPRESSION__FUNC__, /*predefined identifier __func__ */
    PRIMARY_EXPRESSION_CHAR_LITERAL,
    PRIMARY_EXPRESSION_PREDEFINED_CONSTANT, /*true false*/
    PRIMARY_EXPRESSION_GENERIC,
    PRIMARY_EXPRESSION_NUMBER,
    PRIMARY_EXPRESSION_PARENTESIS,

    POSTFIX_EXPRESSION_FUNCTION_LITERAL,
    POSTFIX_EXPRESSION_COMPOUND_LITERAL,

    POSTFIX_FUNCTION_CALL, // ( ) 
    POSTFIX_ARRAY, // [ ]
    POSTFIX_DOT, // .
    POSTFIX_ARROW, // .
    POSTFIX_INCREMENT,
    POSTFIX_DECREMENT,


    UNARY_EXPRESSION_SIZEOF_EXPRESSION,
    UNARY_EXPRESSION_SIZEOF_TYPE,    
    
    UNARY_EXPRESSION_TRAITS,
    UNARY_EXPRESSION_IS_SAME,
    UNARY_DECLARATOR_ATTRIBUTE_EXPR,
    UNARY_EXPRESSION_ALIGNOF,
    UNARY_EXPRESSION_ASSERT,

    UNARY_EXPRESSION_INCREMENT,
    UNARY_EXPRESSION_DECREMENT,

    UNARY_EXPRESSION_NOT,
    UNARY_EXPRESSION_BITNOT,
    UNARY_EXPRESSION_NEG,
    UNARY_EXPRESSION_PLUS,
    UNARY_EXPRESSION_CONTENT,
    UNARY_EXPRESSION_ADDRESSOF,

    CAST_EXPRESSION,

    MULTIPLICATIVE_EXPRESSION_MULT,
    MULTIPLICATIVE_EXPRESSION_DIV,
    MULTIPLICATIVE_EXPRESSION_MOD,

    ADDITIVE_EXPRESSION_PLUS,
    ADDITIVE_EXPRESSION_MINUS,

    SHIFT_EXPRESSION_RIGHT,
    SHIFT_EXPRESSION_LEFT,

    RELATIONAL_EXPRESSION_BIGGER_THAN,
    RELATIONAL_EXPRESSION_LESS_THAN,
    RELATIONAL_EXPRESSION_BIGGER_OR_EQUAL_THAN,
    RELATIONAL_EXPRESSION_LESS_OR_EQUAL_THAN,

    EQUALITY_EXPRESSION_EQUAL,
    EQUALITY_EXPRESSION_NOT_EQUAL,

    AND_EXPRESSION,
    EXCLUSIVE_OR_EXPRESSION,
    INCLUSIVE_OR_EXPRESSION,
    INCLUSIVE_AND_EXPRESSION,
    LOGICAL_OR_EXPRESSION,
    ASSIGNMENT_EXPRESSION,

    CONDITIONAL_EXPRESSION,
};

struct argument_expression_list
{
    /*
     argument-expression-list:
        assignment-expression
        argument-expression-list , assignment-expression
    */
    struct argument_expression* owner head;
    struct argument_expression* tail;
};

void argument_expression_list_destroy(struct argument_expression_list * obj_owner p);

struct generic_association
{
    /*
     generic-association:
       type-name : assignment-expression
       "default" : assignment-expression
    */

    struct type type;
    struct type_name* owner p_type_name;
    struct expression* owner expression;

    struct token* first_token;
    struct token* last_token;

    struct generic_association* owner next;
};

struct generic_assoc_list
{
    struct generic_association* owner head;
    struct generic_association* tail;
};

void generic_assoc_list_add(struct generic_assoc_list * p, struct generic_association* owner item);
void generic_assoc_list_destroy(struct generic_assoc_list * obj_owner p);

struct generic_selection
{
    /*
      generic-selection:
        "_Generic" ( assignment-expression , generic-assoc-list )
    */


    /*
      Extension
      generic-selection:
        "_Generic" ( generic-argument, generic-assoc-list )

        generic-argument:
          assignment-expression
          type-name
    */


    struct expression* owner expression;
    struct type_name* owner type_name;
    /*
    * Points to the matching expression
    */
    struct expression* p_view_selected_expression;

    struct generic_assoc_list generic_assoc_list;
    struct token* first_token;
    struct token* last_token;
};

void generic_selection_delete(struct generic_selection * owner p);

enum constant_value_type {
    TYPE_NOT_CONSTANT,
    TYPE_EMPTY,
    TYPE_LONG_LONG,
    TYPE_DOUBLE,
    TYPE_UNSIGNED_LONG_LONG
};

struct constant_value {       
    enum constant_value_type type;
    union {
        unsigned long long ullvalue;
        long long llvalue;
        double dvalue;
    };
};

struct constant_value make_constant_value_double(double d, bool disabled);
struct constant_value make_constant_value_ull(unsigned long long d, bool disabled);
struct constant_value make_constant_value_ll(long long d, bool disabled);

struct constant_value constant_value_op(const struct constant_value* a, const  struct constant_value* b, int op);
unsigned long long constant_value_to_ull(const struct constant_value* a);
long long constant_value_to_ll(const struct constant_value* a);
long long constant_value_to_ll(const struct constant_value* a);
bool constant_value_to_bool(const struct constant_value* a);
bool constant_value_is_valid(const struct constant_value* a);
void constant_value_to_string(const struct constant_value* a, char buffer[], int sz);

struct expression
{
    enum expression_type expression_type;
    struct type type;
    //bool lvalue;

    struct constant_value constant_value;

    struct type_name* owner type_name; 
    struct type_name* owner type_name2; /*is_same*/
    struct braced_initializer* owner braced_initializer;
    struct compound_statement* owner compound_statement; //function literal (lambda)
    struct generic_selection* owner generic_selection; //_Generic

    struct token* first_token;
    struct token* last_token;

    /*token used in _add_attr, _has_attr, _del_attr, return*/
    struct token* contract_arg_token;


    /*se expressão for um identificador ele aponta para declaração dele*/
    struct declarator* declarator;
    int member_index; //used in post_fix .

    /*se for POSTFIX_FUNCTION_CALL post*/
    struct argument_expression_list argument_expression_list; //este node eh uma  chamada de funcao

    struct expression* owner condition_expr;
    struct expression* owner left;
    struct expression* owner right;
};

void expression_delete(struct expression* owner p);

struct expression* owner assignment_expression(struct parser_ctx* ctx);
struct expression* owner expression(struct parser_ctx* ctx);
struct expression* owner constant_expression(struct parser_ctx* ctx, bool show_error_if_not_constant);
bool expression_is_subjected_to_lvalue_conversion(struct expression*);
bool expression_is_zero(struct expression*);
bool expression_is_lvalue(const struct expression* expr);

struct object* expression_get_object(struct expression* p_expression, struct type* p_type);
bool expression_is_null_pointer_constant(const struct expression* expression);
void expression_evaluate_equal_not_equal(const struct expression* left,
    const struct expression* right,
    struct expression* result,
    int op,
    bool disabled);



//#pragma once



/*
   Object represents "memory" and state. Used by flow analysis
*/

//#pragma once

enum object_state
{
    /*
       Not applicable. The state cannot be used.
    */
    OBJECT_STATE_NOT_APPLICABLE = 0,

    OBJECT_STATE_UNINITIALIZED = 1 << 0,
    /*
      non-pointer can be NULL and not ZERO.
      For pointer ZERO is set as NULL
    */
    OBJECT_STATE_NULL = 1 << 1,

    /*
       We have a reference
    */
    OBJECT_STATE_NOT_NULL = 1 << 2,

    /*
       object was moved
    */
    OBJECT_STATE_MOVED = 1 << 3,

    /*
       non-pointer with 0
    */
    OBJECT_STATE_ZERO = 1 << 4,

    /*
       non-pointer with != 0
    */
    OBJECT_STATE_NOT_ZERO = 1 << 5
};

void object_state_to_string(enum object_state e);

struct object_state_stack
{
    enum object_state* owner data;
    int size;
    int capacity;
};
void object_state_stack_destroy(struct object_state_stack* obj_owner p);

struct objects {
    struct object* owner data;
    int size;
    int capacity;
};

void objects_destroy(struct objects* obj_owner p);
/*
  Used in flow analysis to represent the object instance
*/
struct object
{
    /*
       state should not be used for struct, unless
       members_size is zero.
    */
    enum object_state state;
    struct object* owner pointed;

    /*declarator is used only to print the error message*/
    const struct declarator* declarator;

    struct objects members;
    struct object_state_stack object_state_stack;
};
void object_destroy(struct object* obj_owner p);
void object_delete(struct object* owner p);
void object_swap(struct object* a, struct object* b);

struct declarator;
struct object make_object(struct type* p_type, const struct declarator* declarator);

void object_push_copy_current_state(struct object* object);

void object_pop_states(struct object* object, int n);

struct parser_ctx;
struct token;

void visit_object(struct parser_ctx* ctx,
    struct type* p_type,
    struct object* p_object,
    const struct token* position_token,
    const char* previous_names,
    bool is_assigment);

void object_restore_state(struct object* object, int state_to_restore);

void print_object_core(int ident, struct type* p_type, struct object* p_object, const char* previous_names, bool is_pointer, bool short_version);

void print_object(struct type* p_type, struct object* p_object, bool short_version);
void set_direct_state(
    struct type* p_type,
    struct object* p_object,
    enum object_state flags);
void set_object(
    struct type* p_type,
    struct object* p_object,
    enum object_state flags);

void object_assignment(struct parser_ctx* ctx,
    struct object* p_source_obj_opt,
    struct type* p_source_obj_type,

    struct object* p_dest_obj_opt,
    struct type* p_dest_obj_type,

    const struct token* error_position,
    bool bool_source_zero_value,
    enum object_state source_state_after);

void object_set_unknown(struct type* p_type, struct object* p_object);


void checked_read_object(struct parser_ctx* ctx,
    struct type* p_type,
    struct object* p_object,
    const struct token* position_token,
    bool check_pointed_object);


#define CAKE_VERSION "0.7.4"


struct scope
{
    int scope_level;
    struct hash_map tags;
    struct hash_map variables;
        
    struct scope* next;
    struct scope* previous;        
};

void scope_destroy( struct scope* obj_owner p);

struct scope_list
{
    struct scope* head;
    struct scope* tail;
};
void scope_list_push(struct scope_list* list, struct scope* s);
void scope_list_pop(struct scope_list* list);

struct report
{
    int no_files;
    double cpu_time_used_sec;
    int error_count;
    int warnings_count;
    int info_count;
    enum error last_error;
    enum warning last_warning;
};




struct parser_ctx
{
    struct options options;
    
    /*
      file scope -> function params -> function -> inner scope
    */
    struct scope_list scopes;
    
    /*
    * Points to the function we're in. Or null in file scope.
    */
    struct declaration* p_current_function_opt;

    /*
    * Points to the try-block we're in. Or null.
    */
    const struct try_statement* p_current_try_statement_opt;

    FILE* owner sarif_file;

    view struct token_list input_list;
    struct token* current;
    struct token* previous;
    int try_catch_block_index;

    /*
       Expression inside sizeof etc.. are not evaluated
    */
    bool evaluation_is_disabled;

    struct report* p_report;
    
};

///////////////////////////////////////////////////////

void parser_ctx_destroy( struct parser_ctx* obj_owner ctx);


struct token* parser_look_ahead(struct parser_ctx* ctx);

struct token* parser_match(struct parser_ctx* ctx);
int parser_match_tk(struct parser_ctx* ctx, enum token_type type);
struct token* parser_look_ahead(struct parser_ctx* ctx);
struct token* previous_parser_token(struct token* token);
struct declarator* find_declarator(struct parser_ctx* ctx, const char* lexeme, struct scope** ppscope_opt);
struct enumerator* find_enumerator(struct parser_ctx* ctx, const char* lexeme, struct scope** ppscope_opt);
struct map_entry* find_variables(struct parser_ctx* ctx, const char* lexeme, struct scope** ppscope_opt);

struct struct_or_union_specifier* find_struct_or_union_specifier(struct parser_ctx* ctx, const char* lexeme);
bool first_is(struct parser_ctx* ctx, enum token_type type);
void print_scope(struct scope_list* e);

char* CompileText(const char* options, const char* content);

void compiler_set_error_with_token(enum error error, struct parser_ctx* ctx, const struct token* p_token, const char* fmt, ...);
_Bool compiler_set_warning_with_token(enum warning w, struct parser_ctx* ctx, const struct token* p_token, const char* fmt, ...);
void compiler_set_info_with_token(enum warning w, struct parser_ctx* ctx, const struct token* p_token, const char* fmt, ...);

int compile(int argc, const char** argv, struct report* error);


void print_type_qualifier_flags(struct osstream* ss, bool* first, enum type_qualifier_flags e_type_qualifier_flags);

enum token_type parse_number(const char* lexeme, enum type_specifier_flags* flags_opt);
bool print_type_specifier_flags(struct osstream* ss, bool* first, enum type_specifier_flags e_type_specifier_flags);


struct expression_ctx;

struct declaration_specifier
{
    /*
       declaration-specifier:
         storage-class-specifier
         type-specifier-qualifier
         function-specifier
    */
    struct storage_class_specifier* owner storage_class_specifier;

    struct type_specifier_qualifier* owner  type_specifier_qualifier;
    
    struct function_specifier* owner function_specifier;

    struct declaration_specifier* owner next;
};

struct declaration_specifier* owner declaration_specifier(struct parser_ctx* ctx);
void declaration_specifier_delete(struct declaration_specifier* owner p);

struct declaration_specifiers
{
    /*
     declaration-specifiers:
       declaration-specifier attribute-specifier-sequence opt
       declaration-specifier declaration-specifiers
    */

    /*cumulative flags*/
    enum attribute_flags  attributes_flags;
    enum type_specifier_flags type_specifier_flags;
    enum type_qualifier_flags type_qualifier_flags;
    enum storage_class_specifier_flags storage_class_specifier_flags;

    /*shortcuts*/
    struct struct_or_union_specifier* struct_or_union_specifier;
    struct enum_specifier* enum_specifier;
    struct declarator* typedef_declarator;
    struct typeof_specifier* typeof_specifier;

    struct token* first_token; /*not owner*/
    struct token* last_token; /*not owner*/

    struct declaration_specifier* owner head;
    struct declaration_specifier* tail;
};

void print_declaration_specifiers(struct osstream* ss, struct declaration_specifiers* p);
struct declaration_specifiers* owner declaration_specifiers(struct parser_ctx* ctx, enum storage_class_specifier_flags default_storage_flag);
void declaration_specifiers_delete(struct declaration_specifiers* owner p);

struct static_assert_declaration
{
    /*
     static_assert-declaration:
       "static_assert" ( constant-expression , string-literal ) ;
       "static_assert" ( constant-expression ) ;
    */

    /*
      I am keeping the name static_assert_declaration but better is
      
      static_declaration:
       static_assert_declaration
       static_debug_declaration

      extension:
      "static_debug" ( constant-expression ) ;      
      "static_debug" ( constant-expression , string-literal) ;      
    */
    
    struct token*  first_token;
    struct token*  last_token;
    struct expression* owner constant_expression;
    struct token*  string_literal_opt;
};
struct static_assert_declaration* owner static_assert_declaration(struct parser_ctx* ctx);
void static_assert_declaration_delete(struct static_assert_declaration* owner p);


struct attribute_specifier_sequence
{
    /*
     attribute-specifier-sequence:
       attribute-specifier-sequence opt attribute-specifier
    */

    struct token* first_token;
    struct token* last_token;
    enum attribute_flags  attributes_flags;
    struct attribute_specifier* owner head;
    struct attribute_specifier* tail;
};
struct attribute_specifier_sequence* owner attribute_specifier_sequence_opt(struct parser_ctx* ctx);
void attribute_specifier_sequence_delete( struct attribute_specifier_sequence* owner p);

struct attribute_specifier
{
    /*
     attribute-specifier:
        [ [ attribute-list ] ]
    */
    struct token* first_token;
    struct token* last_token;
    struct attribute_list* owner attribute_list;
    struct attribute_specifier* owner next;
};

struct attribute_specifier*  owner attribute_specifier(struct parser_ctx* ctx);
void attribute_specifier_delete( struct attribute_specifier*  owner p);

struct attribute* owner attribute(struct parser_ctx* ctx);


struct storage_class_specifier
{
    /*
     storage-class-specifier:
      "auto"
      "constexpr"
      "extern"
      "register"
      "static"
      "thread_local"
      "typedef"
    */
    enum storage_class_specifier_flags flags;
    struct token* token;
};

struct storage_class_specifier* owner storage_class_specifier(struct parser_ctx* ctx);
void storage_class_specifier_delete(struct storage_class_specifier* owner p);

struct function_specifier
{
    /*
     function-specifier:
       inline
       _Noreturn
    */
    struct token* token;
};
struct function_specifier*  owner function_specifier(struct parser_ctx* ctx);
void function_specifier_delete(struct function_specifier*  owner p);

struct typeof_specifier_argument
{
    /*
     typeof-specifier-argument:
       expression
       type-name
    */
    struct expression* owner expression;
    struct type_name* owner type_name;
};

void typeof_specifier_argument_delete(struct typeof_specifier_argument* owner p);

struct typeof_specifier
{
    /*
     typeof-specifier:
       "typeof" ( typeof-specifier-argument )
    */
    struct token* first_token;
    struct token* last_token;
    struct typeof_specifier_argument*  owner typeof_specifier_argument;
    struct type type;    
};
void typeof_specifier_delete(struct typeof_specifier * owner p);

struct type_specifier
{
    /*
     type-specifier:
        "void"
        "char"
        "short"
        "int"
        "long"
        "float"
        "double"
        "signed"
        "unsigned"
        "_BitInt" ( constant-expression )
        "bool"
        "_Complex"
        "_Decimal32"
        "_Decimal64"
        "_Decimal128"
        atomic-type-specifier
        struct-or-union-specifier
        enum-specifier
        typedef-name
        typeof-specifier
    */
    enum type_specifier_flags flags;
    struct token* token;
    struct struct_or_union_specifier* owner struct_or_union_specifier;
    struct typeof_specifier*  owner  typeof_specifier;
    struct enum_specifier*  owner enum_specifier;
    struct declarator*  view typedef_declarator;
    struct atomic_type_specifier* owner atomic_type_specifier;
};

struct type_specifier*  owner type_specifier(struct parser_ctx* ctx);
void type_specifier_delete(struct type_specifier*  owner p);

struct init_declarator_list
{
    /*
     init-declarator-list:
       init-declarator
       init-declarator-list , init-declarator
    */
    struct init_declarator* owner head;
    struct init_declarator* tail;    
};

struct init_declarator_list init_declarator_list(struct parser_ctx* ctx,
    struct declaration_specifiers* p_declaration_specifiers);

void init_declarator_list_destroy(struct init_declarator_list * obj_owner p);

struct declaration
{
    /*
      declaration:
        declaration-specifiers init-declarator-list opt ;
        attribute-specifier-sequence declaration-specifiers init-declarator-list ;
        static_assert-declaration
        attribute-declaration
    */
    struct attribute_specifier_sequence* owner p_attribute_specifier_sequence_opt;
    
    struct static_assert_declaration* owner static_assert_declaration;
    

    struct declaration_specifiers* owner declaration_specifiers;
    struct init_declarator_list init_declarator_list;

    struct compound_statement* owner function_body;
    struct declarator*  contract_declarator;

    struct token* first_token;
    struct token* last_token;

    struct declaration* owner next;
};
void declaration_delete( struct declaration* owner p);
struct declaration*  owner external_declaration(struct parser_ctx* ctx);

struct atomic_type_specifier
{
    /*
      atomic-type-specifier:
        "_Atomic" ( type-name )
    */
    struct token* token;
    struct type_name* owner type_name;
};

struct atomic_type_specifier*  owner atomic_type_specifier(struct parser_ctx* ctx);
void atomic_type_specifier_delete(struct atomic_type_specifier*  owner p);

struct enumerator_list
{
    /*
     enumerator-list:
       enumerator
       enumerator-list , enumerator
    */
    struct enumerator* owner head;
    struct enumerator* tail;
};

struct enumerator_list enumerator_list(struct parser_ctx* ctx,
    const struct enum_specifier*  p_enum_specifier
    );

void enumerator_list_destroy(struct enumerator_list*  obj_owner p_enum_specifier);
    
struct enum_specifier
{
    /*
     enum-type-specifier:
       : specifier-qualifier-lis
    
     enum-specifier:
       "enum" attribute-specifier-sequence opt identifier opt enum-type-specifier opt  { enumerator-list }
       "enum" attribute-specifier-sequence opt identifier opt enum-type-specifier opt  { enumerator-list , }
       "enum" identifier enum-type-specifier opt
    */
    struct attribute_specifier_sequence*  owner attribute_specifier_sequence_opt;
    struct specifier_qualifier_list*  owner specifier_qualifier_list;
    

    struct enumerator_list enumerator_list;
    
    struct token* tag_token;
    struct token* first_token;
    /*points to the complete enum (can be self pointed)*/
    struct enum_specifier* complete_enum_specifier;
};

struct enum_specifier*  owner enum_specifier(struct parser_ctx*);
void enum_specifier_delete(struct enum_specifier*  owner p);

struct member_declaration_list
{
    /*
     member-declaration-list:
       member-declaration
       member-declaration-list member-declaration
    */

    struct token* first_token; /*TODO ? necessary*/
    struct token* last_token;
    struct member_declaration* owner head;
    struct member_declaration* tail;
};

struct member_declaration_list member_declaration_list(struct parser_ctx* ctx, const struct struct_or_union_specifier*);
void member_declaration_list_destroy(struct member_declaration_list * obj_owner p );

struct member_declarator* find_member_declarator(struct member_declaration_list* list, const char* name, int* p_member_index);

struct struct_or_union_specifier
{
    /*
     struct-or-union-specifier:
       struct-or-union attribute-specifier-sequence opt identifier opt { member-declaration-list }
       struct-or-union attribute-specifier-sequence opt identifier
    */
    struct attribute_specifier_sequence* owner attribute_specifier_sequence_opt;
    struct member_declaration_list member_declaration_list;
    
    struct token* first_token;
    struct token* last_token;
        
    bool is_owner;

    /*
    * Token que possui tag da struct
    */
    struct token* tagtoken;

    char tag_name[200];
    /*geramos um tag name para anomimas, mas colocamos banonymousTag para true*/
    bool has_anonymous_tag;
    /*it was asked to show struct tag created for anonymous*/
    bool show_anonymous_tag;

    int scope_level; /*nivel escopo 0 global*/
    int visit_moved; /*nivel escopo 0 global*/
        
    /*
    * This points to the first struct_or_union_specifier that will have it´s
    * complete_struct_or_union_specifier_indirection pointing to the complete
    * struct_or_union_specifier.
    */
    struct struct_or_union_specifier* complete_struct_or_union_specifier_indirection;
};

struct struct_or_union_specifier* owner struct_or_union_specifier(struct parser_ctx* ctx);
void struct_or_union_specifier_delete(struct struct_or_union_specifier* owner p);

bool struct_or_union_specifier_is_complete(struct struct_or_union_specifier* p_struct_or_union_specifier);
struct struct_or_union_specifier* view get_complete_struct_or_union_specifier(struct struct_or_union_specifier* p_struct_or_union_specifier);

struct init_declarator
{
    /*
     init-declarator:
        declarator
        declarator = initializer
    */

    struct declarator* owner p_declarator;
    struct initializer* owner initializer;
    struct init_declarator* owner next;    
};

void init_declarator_delete(struct init_declarator*  owner p);
struct init_declarator*  owner init_declarator(struct parser_ctx* ctx,
    struct declaration_specifiers* p_declaration_specifiers
    );

struct initializer
{
    /*
     initializer:
       assignment-expression
       braced-initializer
    */
    struct token* first_token;
    struct designation*  owner designation; /*auxiliar para list??*/
    struct braced_initializer*  owner braced_initializer;
    struct expression*  owner assignment_expression;
    struct initializer* owner next;
    
    /*
       cake extension
       int * p = [[cake::move]] p2;
    */
    struct attribute_specifier_sequence* owner p_attribute_specifier_sequence_opt;
};

struct initializer* owner initializer(struct parser_ctx* ctx);
void initializer_delete(struct initializer* owner p);



struct declarator
{
    /*
      declarator:
        pointer opt direct-declarator
    */

    struct token* first_token;
    struct token* last_token;


    struct pointer*  owner pointer;
    struct direct_declarator*  owner direct_declarator;

    
    struct declaration_specifiers* view declaration_specifiers;
    const struct specifier_qualifier_list* view specifier_qualifier_list;

    struct token* name; //shortcut

    struct compound_statement* view function_body;
           
    int num_uses; /*used to show not used warnings*/
    
    /*user by flow analysis*/
    struct object object;

    /*final declarator type (after auto, typeof etc)*/
    struct type type;    
};

enum type_specifier_flags declarator_get_type_specifier_flags(const struct declarator* p);

struct declarator;
void print_declarator(struct osstream* ss, struct declarator* declarator, bool is_abstract);

struct declarator* owner declarator(struct parser_ctx* ctx,
    const struct specifier_qualifier_list* specifier_qualifier_list,
    struct declaration_specifiers* declaration_specifiers,
    bool abstract_acceptable,
    struct token** pptokenname);

void declarator_delete(struct declarator* owner p);
struct array_declarator
{
    /*
     array-declarator:
        direct-declarator [ type-qualifier-list opt assignment-expression opt ]
        direct-declarator [ "static" type-qualifier-list opt assignment-expression ]
        direct-declarator [ type-qualifier-list "static" assignment-expression ]
        direct-declarator [ type-qualifier-listopt * ]
    */
    struct direct_declarator* owner direct_declarator;
    struct expression* owner assignment_expression;
    struct expression* owner expression;
    struct type_qualifier_list* owner type_qualifier_list_opt;
    
    struct token* token;
    struct token* static_token_opt;
};
void array_declarator_delete(struct array_declarator* owner p);
/*
  Return a value > 0 if it has constant size
*/
unsigned long long  array_declarator_get_size(struct array_declarator* p_array_declarator);

struct function_declarator
{
    /*
     function-declarator:
       direct-declarator ( parameter-type-list opt )
    */
    struct direct_declarator* owner direct_declarator;
    struct scope parameters_scope; //usado para escopo parametros
    struct parameter_type_list* owner parameter_type_list_opt;
};
void function_declarator_delete(struct function_declarator * owner p);

struct direct_declarator
{
    /*
     direct-declarator:
        identifier attribute-specifier-sequence opt
        ( declarator )
        array-declarator attribute-specifier-sequence opt
        function-declarator attribute-specifier-sequence opt
    */
    struct token* name_opt;
    struct declarator* owner declarator;
    struct array_declarator* owner array_declarator;
    struct function_declarator* owner function_declarator;
    struct attribute_specifier_sequence * owner p_attribute_specifier_sequence_opt;
};

void direct_declarator_delete(struct direct_declarator* owner p);

struct direct_declarator*  owner  direct_declarator(struct parser_ctx* ctx,
    const struct specifier_qualifier_list* specifier_qualifier_list,
    struct declaration_specifiers* declaration_specifiers,
    bool abstract_acceptable,
    struct token** pptoken_name
    );

struct parameter_type_list
{
    /*
    parameter-type-list:
        parameter-list
        parameter-list , ...
        ...
    */
    bool is_var_args; /*(...)*/
    bool is_void;/*(void)*/
    struct parameter_list* owner parameter_list;
};

struct parameter_type_list*  owner parameter_type_list(struct parser_ctx* ctx);
void parameter_type_list_delete(struct parameter_type_list*  owner p);

struct pointer
{
    /*
     pointer:
        * attribute-specifier-sequence opt type-qualifier-list opt
        * attribute-specifier-sequence opt type-qualifier-list opt pointer    
    */
    struct attribute_specifier_sequence* owner attribute_specifier_sequence_opt;
    struct type_qualifier_list* owner type_qualifier_list_opt;

    struct pointer* owner pointer;
};

struct pointer*  owner pointer_opt(struct parser_ctx* ctx);
void pointer_delete(struct pointer*  owner p);
struct parameter_list
{
    /*
     parameter-list:
        parameter-declaration
        parameter-list , parameter-declaration
    */
    struct parameter_declaration* owner head;
    struct parameter_declaration* tail;
};
struct parameter_list*  owner  parameter_list(struct parser_ctx* ctx);
void parameter_list_delete(struct parameter_list*  owner  p);

struct parameter_declaration
{
    /*
     parameter-declaration:
      attribute-specifier-sequence opt declaration-specifiers declarator
      attribute-specifier-sequence opt declaration-specifiers abstract-declarator opt
    */
    struct attribute_specifier_sequence* owner attribute_specifier_sequence_opt;
    
    struct declaration_specifiers* owner declaration_specifiers;
    struct declarator* owner declarator;
    struct token * implicit_token;
    struct parameter_declaration* owner next;
};
struct parameter_declaration*  owner parameter_declaration(struct parser_ctx* ctx);
void parameter_declaration_delete(struct parameter_declaration*  owner p);


struct type_name
{
    /*
     type-name:
       specifier-qualifier-list abstract-declarator opt
    */

    struct token* first_token;
    struct token* last_token;
    struct specifier_qualifier_list* owner specifier_qualifier_list;
    struct declarator* owner declarator;
    struct type type;
};

struct type_name*  owner type_name(struct parser_ctx* ctx);
void type_name_delete(struct type_name*  owner p);
void print_type_name(struct osstream* ss, struct type_name* p);

struct argument_expression
{    
    struct expression* owner expression;
    struct argument_expression* owner next;
};

void argument_expression_delete(struct argument_expression* owner p);

struct braced_initializer
{    
    /*
      { }
      { initializer-list }
      { initializer-list , }
    */

    struct token* first_token;
    struct initializer_list* owner initializer_list;
};
struct braced_initializer*  owner braced_initializer(struct parser_ctx* ctx);
void braced_initializer_delete(struct braced_initializer*  owner p);

struct type_specifier_qualifier
{
    /*
     type-specifier-qualifier:
       type-specifier
       type-qualifier
       alignment-specifier
    */

    struct type_specifier* owner type_specifier;
    struct type_qualifier* owner type_qualifier;
    struct alignment_specifier* owner alignment_specifier;

    struct type_specifier_qualifier* owner next;
};
struct type_specifier_qualifier*  owner type_specifier_qualifier(struct parser_ctx* ctx);
void type_specifier_qualifier_delete(struct type_specifier_qualifier*  owner p);


struct specifier_qualifier_list
{
    /*
      specifier-qualifier-list:
        type-specifier-qualifier attribute-specifier-sequence opt
        type-specifier-qualifier specifier-qualifier-list
    */

    /*cumulative flags*/
    enum type_specifier_flags type_specifier_flags;
    enum type_qualifier_flags type_qualifier_flags;

    /*shortcuts*/
    struct struct_or_union_specifier* view struct_or_union_specifier;
    struct enum_specifier* view enum_specifier;
    struct typeof_specifier* view typeof_specifier;
    struct declarator* view typedef_declarator;
    
    struct type_specifier_qualifier* owner head;
    struct type_specifier_qualifier* tail;
    struct token* first_token;
    struct token* last_token;

    struct attribute_specifier_sequence * owner p_attribute_specifier_sequence;

};

struct specifier_qualifier_list* owner specifier_qualifier_list(struct parser_ctx* ctx);
void specifier_qualifier_list_delete(struct specifier_qualifier_list* owner p);

void print_specifier_qualifier_list(struct osstream* ss, bool* first, struct specifier_qualifier_list* p_specifier_qualifier_list);


struct alignment_specifier
{
    /*
     alignment-specifier:
       "alignas" ( type-name )
       "alignas" ( constant-expression )
    */
    struct type_name * owner type_name;
    struct expression * owner constant_expression;
    struct token* token;
};
struct alignment_specifier*  owner alignment_specifier(struct parser_ctx* ctx);
void alignment_specifier_delete(struct alignment_specifier*  owner p);


struct type_qualifier
{
    /*
     type-qualifier:
       "const"
       "restrict"
       "volatile"
       "_Atomic"
    */
    enum type_qualifier_flags flags;
    struct token* token;

    /*
      Next is used when inside struct type_qualifier_list
      Not used when inside struct type_specifier_qualifier    
    */
    struct type_qualifier* owner next;
};

struct type_qualifier*  owner type_qualifier(struct parser_ctx* ctx);

struct member_declaration
{
    /*
     member-declaration:
       attribute-specifier-sequence opt specifier-qualifier-list member-declarator-list opt ;
       static_assert-declaration
    */
    struct specifier_qualifier_list* owner specifier_qualifier_list;
    struct member_declarator_list* owner member_declarator_list_opt;

    struct static_assert_declaration* owner static_assert_declaration;
    struct attribute_specifier_sequence* owner p_attribute_specifier_sequence_opt;
    struct member_declaration* owner next;
    
};

struct member_declaration*  owner member_declaration(struct parser_ctx* ctx,  struct struct_or_union_specifier*);
void member_declaration_delete(struct member_declaration*  owner p);

struct member_declarator
{
    /*    
     member-declarator:
       declarator
       declarator opt : constant-expression
    */
    
    struct declarator* owner declarator;
    struct expression* owner constant_expression;
    struct member_declarator* owner next;
};
void member_declarator_delete(struct member_declarator * owner p);

struct member_declarator_list
{
    /*    
     member-declarator-list:
        member-declarator
        member-declarator-list , member-declarator
    */

    struct member_declarator* owner head;
    struct member_declarator* tail;
};

struct member_declarator_list*  owner member_declarator_list(struct parser_ctx* ctx,
     struct struct_or_union_specifier* ,
    const struct specifier_qualifier_list* specifier_qualifier_list
    );
void member_declarator_list_delete(struct member_declarator_list*  owner p);

struct block_item_list
{
    /*
     block-item-list:
       block-item
       block-item-list block-item
    */
    struct block_item* owner head;
    struct block_item* tail;
};

struct block_item_list block_item_list(struct parser_ctx* ctx);
void block_item_list_destroy( struct block_item_list * obj_owner p);

struct compound_statement
{
    /*
     compound-statement:
       { block-item-list opt }
    */
    struct token* first_token; /*{*/
    struct token* last_token; /*}*/

    struct block_item_list block_item_list;
};
struct compound_statement*  owner compound_statement(struct parser_ctx* ctx);
void compound_statement_delete( struct compound_statement*  owner p);

struct defer_statement
{
    /*
     defer-statement: (extension)
       "defer" secondary-block     
    */
    struct token* first_token;
    struct token* last_token;
    struct secondary_block* owner secondary_block;
};

void defer_statement_delete(struct defer_statement * owner opt p);

struct try_statement
{   
   /*
     try-statement: (extension)
      "try" secondary-block
      "try" secondary-block "catch" secondary-block
   */
    struct secondary_block* owner secondary_block;
    struct secondary_block* owner catch_secondary_block_opt;
    struct token* first_token; /*try*/
    struct token* last_token;
    struct token*  catch_token_opt; /*catch*/
    /*Used to generate label names*/
    int try_catch_block_index;
};

struct try_statement*  owner try_statement(struct parser_ctx* ctx);
void try_statement_delete(struct try_statement*  owner p);

struct selection_statement
{
    /*
      selection-statement:
        "if" ( expression ) secondary-block
        "if" ( expression ) secondary-block "else" secondary-block
        "switch" ( expression ) secondary-block
    */

    /*C++ 17 if with initialization extension*/
    struct init_declarator* owner init_declarator;
    struct declaration_specifiers* owner declaration_specifiers;

    struct expression* owner expression;
    struct secondary_block* owner secondary_block;
    struct secondary_block* owner else_secondary_block_opt;

    struct token* first_token;
    struct token* last_token;
    struct token* else_token_opt;    
};

struct selection_statement*  owner selection_statement(struct parser_ctx* ctx);
void selection_statement_delete(struct selection_statement* owner p);
struct iteration_statement
{
    /*
      iteration-statement:
        "while" ( expression ) secondary-block
        "do" secondary-block "while" ( expression ) ;
        "for" ( expression opt ; expression opt ; expression opt ) secondary-block
        "for" ( declaration expression opt ; expression opt ) secondary-block
        "repeat" secondary-block  (extension)
    */
    
    struct token* first_token;
    struct token* second_token; /*do {} while*/

    struct secondary_block* owner secondary_block;
    struct expression* owner expression1;
    struct expression* owner expression2;
    struct expression* owner expression0;
    struct declaration * owner declaration;
};

struct iteration_statement*  owner iteration_statement(struct parser_ctx* ctx);
void iteration_statement_delete(struct iteration_statement*owner p);

struct jump_statement
{
    /*
     jump-statement:
       "goto" identifier ;
       "continue" ;
       "break" ;
       "return" expression opt ;
    */
    
    struct token* label;
    struct token* first_token;
    struct token* last_token;
    struct expression* owner expression_opt;
    
    int try_catch_block_index;
};

struct jump_statement*  owner jump_statement(struct parser_ctx* ctx);
void jump_statement_delete(struct jump_statement*  owner p);

struct expression_statement
{
    /*
     expression-statement:
       expression opt;
       attribute-specifier-sequence expression ;
    */
    
    struct attribute_specifier_sequence* owner p_attribute_specifier_sequence_opt;
    struct expression* owner expression_opt;
};

struct expression_statement*  owner expression_statement(struct parser_ctx* ctx);
void expression_statement_delete(struct expression_statement*  owner p);

struct block_item
{
    /*
     block-item:
      declaration
      unlabeled-statement
      label
    */
    struct token* first_token; //?necessary
    struct declaration* owner declaration;    
    struct unlabeled_statement* owner unlabeled_statement;
    struct label* owner label;

    struct block_item* owner next;
};

struct block_item*  owner block_item(struct parser_ctx* ctx);
void block_item_delete( struct block_item*  owner p);

struct compound_statement*  owner function_body(struct parser_ctx* ctx);

struct designator
{
    /*
     designator:
       [ constant-expression ]
       . identifier
    */
    struct expression* owner constant_expression_opt;
    struct token* token;
    struct designator* owner next;
};
struct designator*  owner designator(struct parser_ctx* ctx);
void designator_delete(struct designator*  owner p);
struct initializer_list
{
    /*
      initializer-list:
        designation opt initializer
        initializer-list , designation opt initializer
    */
    struct token* first_token;
    struct initializer* owner head;
    struct initializer* tail;
    int size;
};
struct initializer_list*  owner initializer_list(struct parser_ctx* ctx);
void initializer_list_delete(struct initializer_list*  owner p);

struct primary_block
{
    /*
       primary-block:
         compound-statement
         selection-statement
         iteration-statement
         defer-statement (extension)
         try-statement (extension)
    */
    
    struct compound_statement* owner compound_statement;
    struct selection_statement* owner selection_statement;
    struct iteration_statement* owner iteration_statement;
    struct defer_statement* owner defer_statement;
    struct try_statement* owner try_statement;
};

void primary_block_delete(struct primary_block * owner p);

struct secondary_block
{
    /*
     secondary-block:
       statement
    */
    struct token* view first_token;
    struct token* view last_token;
    struct statement* owner statement;
};

void secondary_block_delete(struct secondary_block * owner opt p);

struct unlabeled_statement
{
    /*
      unlabeled-statement:
        expression-statement
        attribute-specifier-sequence opt primary-block
        attribute-specifier-sequence opt jump-statement
     */

    struct expression_statement*  owner expression_statement;
    struct primary_block*  owner primary_block;
    struct jump_statement*  owner jump_statement;
};

struct unlabeled_statement* owner unlabeled_statement(struct parser_ctx* ctx);
void unlabeled_statement_delete( struct unlabeled_statement* owner p);

struct labeled_statement
{
    /*
     label statement:
       label statement
    */
    struct label* owner label;
    struct statement* owner statement;
};
struct labeled_statement* owner labeled_statement(struct parser_ctx* ctx);
void labeled_statement_delete(struct labeled_statement * owner p);

struct statement
{    
    /*
     statement:
       labeled-statement
       unlabeled-statemen
    */
    struct labeled_statement* owner labeled_statement;
    struct unlabeled_statement* owner unlabeled_statement;
};
struct statement* owner statement(struct parser_ctx* ctx);
void statement_delete(struct statement* owner p);

struct designator_list
{
    /*
     designator-list:
       designator
       designator-list designator
    */
    struct designator* owner head;
    struct designator* tail;
};

struct designator_list* owner designator_list(struct parser_ctx* ctx);
void designator_list_delete(struct designator_list* owner p);

struct designation
{
    /*
     designation:
       designator-list =
    */
    struct designator_list * owner designator_list;
    struct token* token;
};
struct designation* owner designation(struct parser_ctx* ctx);
void designation_delete(struct designation* owner p);

struct type_qualifier_list
{
    /*
     type-qualifier-list:
       type-qualifier
       type-qualifier-list type-qualifier
    */
    enum type_qualifier_flags flags;
    struct type_qualifier* owner head;
    struct type_qualifier* tail;
};

struct type_qualifier_list* owner type_qualifier_list(struct parser_ctx* ctx);
void type_qualifier_list_delete(struct type_qualifier_list* owner p);

struct attribute_token
{
    enum attribute_flags attributes_flags;
    struct token* token;
};
struct attribute_token* owner attribute_token(struct parser_ctx* ctx);
void attribute_token_delete(struct attribute_token* owner p);
struct attribute
{
    enum attribute_flags  attributes_flags;
    struct attribute_token* owner attribute_token;
    struct attribute_argument_clause* owner attribute_argument_clause;
    struct attribute* owner next;
};
void attribute_delete(struct attribute * owner p);

struct attribute_list
{
    enum attribute_flags  attributes_flags;
    struct attribute* owner head;
    struct attribute* tail;
};
struct attribute_list* owner attribute_list(struct parser_ctx* ctx);
void attribute_list_destroy( struct attribute_list* obj_owner p);

struct enumerator
{
    /*
      enumeration-constant:
        identifier
   
      enumerator:
        enumeration-constant attribute-specifier-sequence opt
        enumeration-constant attribute-specifier-sequence opt = constant-expression
    */
    
    struct token* token;
    struct attribute_specifier_sequence* owner attribute_specifier_sequence_opt;

    struct expression* owner constant_expression_opt;
    
    /*
      having the enum specifier we have better information about the type
    */
    const struct enum_specifier* view enum_specifier;

    struct enumerator* owner next;
    long long value;    
};

struct enumerator* owner enumerator(struct parser_ctx* ctx, const struct enum_specifier* p_enum_specifier, long long *p_enumerator_value);
void enumerator_delete(struct enumerator* owner p);

struct attribute_argument_clause
{
    /*
     attribute-argument-clause:
       ( balanced-token-sequence opt )
    */
    struct balanced_token_sequence * owner p_balanced_token_sequence;
    struct token* token;
};

struct attribute_argument_clause* owner attribute_argument_clause(struct parser_ctx* ctx);
void attribute_argument_clause_delete(struct attribute_argument_clause* owner p);

bool first_of_attribute(struct parser_ctx* ctx);

struct balanced_token
{
    struct token * token;
    struct balanced_token* owner next;
};

struct balanced_token_sequence
{
    struct balanced_token* owner head;
    struct balanced_token* tail;
};
struct balanced_token_sequence* owner balanced_token_sequence_opt(struct parser_ctx* ctx);
void balanced_token_sequence_delete(struct balanced_token_sequence* owner p);

bool is_first_of_conditional_expression(struct parser_ctx* ctx);
bool first_of_type_name(struct parser_ctx* ctx);
bool first_of_type_name_ahead(struct parser_ctx* ctx);

struct argument_expression_list argument_expression_list(struct parser_ctx* ctx);

struct declaration_list
{
    struct declaration* owner head;
    struct declaration* tail;
};

struct declaration_list translation_unit(struct parser_ctx* ctx);
void declaration_list_destroy( struct declaration_list* obj_owner list);

struct label
{
    /*
     label:
       attribute-specifier-sequence opt identifier :
       attribute-specifier-sequence opt "case" constant-expression :
       attribute-specifier-sequence opt "default" :
    */
    struct expression* owner constant_expression;
    struct token* name;
};

struct label* owner label(struct parser_ctx* ctx);
void label_delete( struct label* owner p);

struct ast
{
    struct token_list token_list;
    struct declaration_list declaration_list;
};


struct ast get_ast(struct options* options, const char* filename, const char* source, struct report* report);
void ast_destroy( struct ast* obj_owner ast);
struct type make_type_using_declarator(struct parser_ctx* ctx, struct declarator* pdeclarator);


struct declaration_list parse(struct parser_ctx* ctx, struct token_list* list);
const char* owner compile_source(const char* pszoptions, const char* content, struct report* report);


#ifdef _WIN32
#endif

#if defined _MSC_VER && !defined __POCC__
#endif


struct constant_value make_constant_value_double(double d, bool disabled)
{
    struct constant_value r = {0};
    if (disabled)
        return r;
    r.dvalue = d;
    r.type = TYPE_DOUBLE;
    return r;
}

struct constant_value make_constant_value_ull(unsigned long long d, bool disabled)
{
    struct constant_value r= {0};
    if (disabled)
        return r;

    r.ullvalue = d;
    r.type = TYPE_UNSIGNED_LONG_LONG;
    return r;
}

struct constant_value make_constant_value_ll(long long d, bool disabled)
{
    struct constant_value r= {0};
    if (disabled)
        return r;

    r.llvalue = d;
    r.type = TYPE_LONG_LONG;
    return r;
}

double constant_value_to_double(const struct constant_value* a)
{
    switch (a->type)
    {
        case TYPE_LONG_LONG: return (double) a->llvalue;
        case TYPE_DOUBLE: return  a->dvalue;
        case TYPE_UNSIGNED_LONG_LONG: return (double) a->ullvalue;
    }

    return 0;
}

bool constant_value_is_valid(const struct constant_value* a)
{
    return a->type != TYPE_NOT_CONSTANT &&
        a->type != TYPE_EMPTY;
}

void constant_value_to_string(const struct constant_value* a, char buffer[], int sz)
{
    buffer[0] = 0;
    switch (a->type)
    {
        case TYPE_LONG_LONG:
            snprintf(buffer, sz, "%lld", a->llvalue);
            break;
        case TYPE_DOUBLE:
            snprintf(buffer, sz, "%f", a->dvalue);
            break;

        case TYPE_UNSIGNED_LONG_LONG:
            snprintf(buffer, sz, "%llu", a->ullvalue);
            break;
    }
}

unsigned long long constant_value_to_ull(const struct constant_value* a)
{
    switch (a->type)
    {
        case TYPE_LONG_LONG: return (unsigned long long)a->llvalue;
        case TYPE_DOUBLE: return  (unsigned long long)a->dvalue;
        case TYPE_UNSIGNED_LONG_LONG: return (unsigned long long) a->ullvalue;
    }

    return 0;
}
long long constant_value_to_ll(const struct constant_value* a)
{
    switch (a->type)
    {
        case TYPE_LONG_LONG: return (long long) a->llvalue;
        case TYPE_DOUBLE: return  (long long) a->dvalue;
        case TYPE_UNSIGNED_LONG_LONG: return (long long) a->ullvalue;
    }

    return 0;
}
bool constant_value_to_bool(const struct constant_value* a)
{
    switch (a->type)
    {
        case TYPE_LONG_LONG: return a->llvalue != 0;
        case TYPE_DOUBLE: return  a->dvalue != 0;
        case TYPE_UNSIGNED_LONG_LONG: return a->ullvalue != 0;
    }

    return 0;
}

struct constant_value constant_value_cast(const struct constant_value* a, enum constant_value_type type)
{
    struct constant_value r = *a;

    if (a->type == TYPE_EMPTY || a->type == TYPE_NOT_CONSTANT)
    {
        return r;
    }

    switch (type)
    {
        case TYPE_NOT_CONSTANT:
        case TYPE_EMPTY:
            assert(false);
            break;

        case TYPE_LONG_LONG:
            r.type = TYPE_LONG_LONG;
            r.llvalue = constant_value_to_ll(a);
            break;
        case TYPE_DOUBLE:
            r.type = TYPE_DOUBLE;
            r.dvalue = constant_value_to_double(a);
            break;
        case TYPE_UNSIGNED_LONG_LONG:
            r.type = TYPE_UNSIGNED_LONG_LONG;
            r.ullvalue = constant_value_to_ull(a);
            break;
    }
    return r;
}

struct constant_value constant_value_unary_op(const struct constant_value* a, int op)
{
    struct constant_value r = {0};
    if (!constant_value_is_valid(a))
    {
        return r;
    }

    if (a->type == TYPE_DOUBLE)
    {
        r.type = TYPE_DOUBLE;
        switch (op)
        {
            case '!':r.dvalue = !a->dvalue;  break;
                //case '~':r.dvalue = ~ a->dvalue;  break;
            case '+':r.dvalue = +a->dvalue;  break;
            case '-':r.dvalue = -a->dvalue;  break;
            default:
                assert(false);
                break;
        }
        return r;
    }
    else if (a->type == TYPE_UNSIGNED_LONG_LONG)
    {
        r.type = TYPE_UNSIGNED_LONG_LONG;
        switch (op)
        {
            case '!':r.ullvalue = !a->ullvalue;  break;
            case '~':r.ullvalue = ~a->ullvalue;  break;
            case '+':r.ullvalue = a->ullvalue;  break;
                //case '-':r.dvalue = -a->ullvalue;  break;
            case '-':
                r.dvalue = 0;// -a->ullvalue;
                break;
            default:
                assert(false);
                break;
        }
        return r;
    }
    else if (a->type == TYPE_LONG_LONG)
    {
        r.type = TYPE_UNSIGNED_LONG_LONG;
        switch (op)
        {
            case '!':r.llvalue = !((long long) a->llvalue);  break;
            case '~':r.llvalue = ~((long long) a->llvalue);  break;
            case '+':r.llvalue = +((long long) a->llvalue);  break;
            case '-':r.llvalue = -((long long) a->llvalue);  break;
            default:
                assert(false);
                break;
        }
        return r;
    }

    return r;
}


struct constant_value constant_value_op(const struct constant_value* a, const struct constant_value* b, int op)
{
    //TODO https://github.com/thradams/checkedints
    struct constant_value r = {0};
    if (!constant_value_is_valid(a) || !constant_value_is_valid(b))
    {
        return r;
    }

    if (a->type == TYPE_DOUBLE || b->type == TYPE_DOUBLE)
    {
        double va = constant_value_to_double(a);
        double vb = constant_value_to_double(b);
        r.type = TYPE_DOUBLE;

        switch (op)
        {
            //Arithmetic Operators
            case '+':r.dvalue = va + vb;  break;
            case '-':r.dvalue = va - vb;  break;
            case '*':r.dvalue = va * vb;  break;
            case '/':
                if (vb != 0)
                    r.dvalue = va / vb;
                else
                    r.type = TYPE_NOT_CONSTANT;
                break;

                //case '%':r.dvalue = va % vb;  break;

                    //Relational Operators
            case '==':r.dvalue = va == vb;  break;
            case '!=':r.dvalue = va != vb;  break;
            case '>':r.dvalue = va > vb;  break;
            case '<':r.dvalue = va < vb;  break;
            case '<=':r.dvalue = va <= vb;  break;
            case '>=':r.dvalue = va >= vb;  break;

                //Logical Operators
            case '&&':r.dvalue = va && vb;  break;
            case '||':r.dvalue = va || vb;  break;

                //Bitwise Operators
            //case '|':r.dvalue = va | vb;  break;
            //case '&':r.dvalue = va & vb;  break;
            //case '^':r.dvalue = va ^ vb;  break;
            //case '>>':r.dvalue = va >> vb;  break;
            //case '<<':r.dvalue = va << vb;  break;

            default:
                assert(false);
                break;
        }

        return r;
    }

    if (a->type == TYPE_UNSIGNED_LONG_LONG || b->type == TYPE_UNSIGNED_LONG_LONG)
    {
        unsigned long long va = constant_value_to_ull(a);
        unsigned long long vb = constant_value_to_ull(b);
        r.type = TYPE_UNSIGNED_LONG_LONG;

        switch (op)
        {
            //Arithmetic Operators
            case '+':r.ullvalue = va + vb;  break;
            case '-':r.ullvalue = va - vb;  break;
            case '*':r.ullvalue = va * vb;  break;
            case '/':
                if (vb != 0)
                    r.ullvalue = va / vb;
                else
                    r.type = TYPE_NOT_CONSTANT;
                break;

            case '%':
                if (vb != 0)
                    r.ullvalue = va % vb;
                else
                    r.type = TYPE_NOT_CONSTANT;
                break;

                //Relational Operators
            case '==':r.ullvalue = va == vb;  break;
            case '!=':r.ullvalue = va != vb;  break;
            case '>':r.ullvalue = va > vb;  break;
            case '<':r.ullvalue = va < vb;  break;
            case '<=':r.ullvalue = va <= vb;  break;
            case '>=':r.ullvalue = va >= vb;  break;

                //Logical Operators
            case '&&':r.ullvalue = va && vb;  break;
            case '||':r.ullvalue = va || vb;  break;

                //Bitwise Operators
            case '|':r.ullvalue = va | vb;  break;
            case '&':r.ullvalue = va & vb;  break;
            case '^':r.ullvalue = va ^ vb;  break;
            case '>>':r.ullvalue = va >> vb;  break;
            case '<<':r.ullvalue = va << vb;  break;

            default:
                assert(false);
                break;
        }

        return r;
    }

    unsigned long long va = a->llvalue;
    unsigned long long vb = b->llvalue;
    r.type = TYPE_LONG_LONG;
    switch (op)
    {
        //Arithmetic Operators
        case '+':r.llvalue = va + vb;  break;
        case '-':r.llvalue = va - vb;  break;
        case '*':r.llvalue = va * vb;  break;

        case '/':
            if (vb != 0)
                r.llvalue = va / vb;
            else
                r.type = TYPE_NOT_CONSTANT;
            break;

        case '%':
            if (vb != 0)
                r.llvalue = va % vb;
            else
                r.type = TYPE_NOT_CONSTANT;
            break;

            //Relational Operators
        case '==':r.llvalue = va == vb;  break;
        case '!=':r.llvalue = va != vb;  break;
        case '>':r.llvalue = va > vb;  break;
        case '<':r.llvalue = va < vb;  break;
        case '<=':r.llvalue = va <= vb;  break;
        case '>=':r.llvalue = va >= vb;  break;

            //Logical Operators
        case '&&':r.llvalue = va && vb;  break;
        case '||':r.llvalue = va || vb;  break;

            //Bitwise Operators
        case '|':r.llvalue = va | vb;  break;
        case '&':r.llvalue = va & vb;  break;
        case '^':r.llvalue = va ^ vb;  break;
        case '>>':r.llvalue = va >> vb;  break;
        case '<<':r.llvalue = va << vb;  break;

        default:
            assert(false);
            break;
    }


    return r;
}

struct expression* owner postfix_expression(struct parser_ctx* ctx);
struct expression* owner cast_expression(struct parser_ctx* ctx);
struct expression* owner multiplicative_expression(struct parser_ctx* ctx);
struct expression* owner unary_expression(struct parser_ctx* ctx);
struct expression* owner additive_expression(struct parser_ctx* ctx);
struct expression* owner shift_expression(struct parser_ctx* ctx);
struct expression* owner relational_expression(struct parser_ctx* ctx);
struct expression* owner equality_expression(struct parser_ctx* ctx);
struct expression* owner and_expression(struct parser_ctx* ctx);
struct expression* owner exclusive_or_expression(struct parser_ctx* ctx);
struct expression* owner inclusive_or_expression(struct parser_ctx* ctx);
struct expression* owner logical_and_expression(struct parser_ctx* ctx);
struct expression* owner logical_or_expression(struct parser_ctx* ctx);
struct expression* owner conditional_expression(struct parser_ctx* ctx);
struct expression* owner expression(struct parser_ctx* ctx);
struct expression* owner conditional_expression(struct parser_ctx* ctx);



static int compare_function_arguments(struct parser_ctx* ctx,
    struct type* p_type,
    struct argument_expression_list* p_argument_expression_list)
{
    try
    {
        struct param* p_current_parameter_type = NULL;

        const struct param_list* p_param_list = type_get_func_or_func_ptr_params(p_type);

        if (p_param_list)
        {
            p_current_parameter_type = p_param_list->head;
        }

        int param_num = 1;
        struct argument_expression* p_current_argument = p_argument_expression_list->head;

        while (p_current_argument && p_current_parameter_type)
        {
            check_argument_and_parameter(ctx, p_current_argument, &p_current_parameter_type->type, param_num);




            p_current_argument = p_current_argument->next;
            p_current_parameter_type = p_current_parameter_type->next;
            param_num++;
        }

        if (p_current_argument != NULL && !p_param_list->is_var_args)
        {
            compiler_set_error_with_token(C_TOO_MANY_ARGUMENTS, ctx,
                p_argument_expression_list->tail->expression->first_token,
                "too many arguments");
            throw;
        }

        if (p_current_parameter_type != NULL && !p_param_list->is_void)
        {
            if (p_argument_expression_list->tail)
            {
                compiler_set_error_with_token(C_TOO_FEW_ARGUMENTS, ctx,
                    p_argument_expression_list->tail->expression->first_token,
                    "too few arguments");
            }
            else
            {
                compiler_set_error_with_token(C_TOO_FEW_ARGUMENTS, ctx, ctx->current, "too few arguments");
            }
            throw;
        }
    }
    catch
    {
        return 1; /*error*/
    }

    return 0;
}


bool is_enumeration_constant(struct parser_ctx* ctx)
{
    if (ctx->current->type != TK_IDENTIFIER)
    {
        return false;
    }

    if (ctx->current->flags & TK_FLAG_IDENTIFIER_IS_ENUMERATOR)
        return true;

    if (ctx->current->flags & TK_FLAG_IDENTIFIER_IS_NOT_ENUMERATOR)
        return false;

    const bool is_enumerator = find_enumerator(ctx, ctx->current->lexeme, NULL) != NULL;

    if (is_enumerator)
    {
        ctx->current->flags |= TK_FLAG_IDENTIFIER_IS_ENUMERATOR;
    }
    else
    {
        ctx->current->flags |= TK_FLAG_IDENTIFIER_IS_NOT_ENUMERATOR;
    }

    return is_enumerator;
}

bool is_first_of_floating_constant(struct parser_ctx* ctx)
{
    /*
     floating-constant:
      decimal-floating-constant
      hexadecimal-floating-constan
    */
    return ctx->current->type == TK_COMPILER_DECIMAL_FLOATING_CONSTANT ||
        ctx->current->type == TK_COMPILER_HEXADECIMAL_FLOATING_CONSTANT;
}

bool is_first_of_integer_constant(struct parser_ctx* ctx)
{
    /*
     integer-constant:
      decimal-constant integer-suffixopt
      octal-constant integer-suffixopt
      hexadecimal-constant integer-suffixopt
      binary-constant integer-suffixop
    */

    return ctx->current->type == TK_COMPILER_DECIMAL_CONSTANT ||
        ctx->current->type == TK_COMPILER_OCTAL_CONSTANT ||
        ctx->current->type == TK_COMPILER_HEXADECIMAL_CONSTANT ||
        ctx->current->type == TK_COMPILER_BINARY_CONSTANT;
}

bool is_predefined_constant(struct parser_ctx* ctx)
{
    return ctx->current->type == TK_KEYWORD_TRUE ||
        ctx->current->type == TK_KEYWORD_FALSE ||
        ctx->current->type == TK_KEYWORD_NULLPTR;
}

bool is_first_of_constant(struct parser_ctx* ctx)
{
    /*
     constant:
      integer-constant
      floating-constant
      enumeration-constant
      character-constant
      predefined-constant
    */
    return is_first_of_integer_constant(ctx) ||
        is_first_of_floating_constant(ctx) ||
        is_enumeration_constant(ctx) ||
        (ctx->current->type == TK_CHAR_CONSTANT) ||
        is_predefined_constant(ctx);
}

bool is_first_of_primary_expression(struct parser_ctx* ctx)
{
    /*
     primary-expression:
      identifier
      constant
      string-literal
      ( expression )
      generic-selection
      typeid (expression )
    */
    if (ctx->current == NULL)
        return false;

    return ctx->current->type == TK_IDENTIFIER ||
        is_first_of_constant(ctx) ||
        ctx->current->type == TK_STRING_LITERAL ||
        ctx->current->type == '(' ||
        ctx->current->type == TK_KEYWORD__GENERIC;
}

struct generic_association* owner generic_association(struct parser_ctx* ctx)
{
    struct generic_association* owner p_generic_association = NULL;
    try
    {
        p_generic_association = calloc(1, sizeof * p_generic_association);
        if (p_generic_association == NULL)
            throw;

        static_set(*p_generic_association, "zero");
        p_generic_association->first_token = ctx->current;
        /*generic - association:
            type-name : assignment-expression
            default : assignment-expression
            */
        if (ctx->current && ctx->current->type == TK_KEYWORD_DEFAULT)
        {
            parser_match(ctx);
        }
        else if (first_of_type_name(ctx))
        {
            p_generic_association->p_type_name = type_name(ctx);
            p_generic_association->type = make_type_using_declarator(ctx, p_generic_association->p_type_name->declarator);
        }
        else
        {
            compiler_set_error_with_token(C_UNEXPECTED, ctx, ctx->current, "unexpected");
        }
        parser_match_tk(ctx, ':');
        p_generic_association->expression = assignment_expression(ctx);
    }
    catch
    {
    }

    return p_generic_association;
}

struct generic_assoc_list generic_association_list(struct parser_ctx* ctx)
{
    struct generic_assoc_list list = {0};
    try
    {
        struct generic_association* owner p_generic_association =
            generic_association(ctx);

        if (p_generic_association == NULL) throw;

        generic_assoc_list_add(&list, p_generic_association);

        while (ctx->current->type == ',')
        {
            parser_match(ctx);

            struct generic_association* owner p_generic_association2 = generic_association(ctx);
            if (p_generic_association2 == NULL) throw;

            generic_assoc_list_add(&list, p_generic_association2);
        }
    }
    catch
    {
    }
    return list;
}
void generic_association_delete(struct generic_association* owner p)
{
    if (p)
    {
        assert(p->next == NULL);
        type_name_delete(p->p_type_name);
        expression_delete(p->expression);
        type_destroy(&p->type);
        free(p);
    }
}

void generic_assoc_list_add(struct generic_assoc_list* list, struct generic_association* owner pitem)
{
    if (list->head == NULL)
    {
        list->head = pitem;
    }
    else
    {
        assert(list->tail->next == NULL);
        list->tail->next = pitem;
    }
    list->tail = pitem;
}

void generic_assoc_list_destroy(struct generic_assoc_list* obj_owner p)
{
    struct generic_association* owner item = p->head;
    while (item)
    {
        struct generic_association* owner next = item->next;
        item->next = NULL;
        generic_association_delete(item);
        item = next;
    }
}
void generic_selection_delete(struct generic_selection* owner p)
{
    if (p)
    {
        expression_delete(p->expression);
        type_name_delete(p->type_name);
        generic_assoc_list_destroy(&p->generic_assoc_list);
        free(p);
    }
}
struct generic_selection* owner generic_selection(struct parser_ctx* ctx)
{
    /*C23
      generic-selection:
        _Generic ( assignment-expression , generic-assoc-ctx )
    */

    /*
      Extension
      generic-selection:
        "_Generic" ( generic-argument, generic-assoc-list )

        generic-argument:
          assignment-expression
          type-name
    */

    struct generic_selection* owner p_generic_selection = NULL;
    try
    {
        p_generic_selection = calloc(1, sizeof * p_generic_selection);
        if (p_generic_selection == NULL)
            throw;

        p_generic_selection->first_token = ctx->current;



        parser_match_tk(ctx, TK_KEYWORD__GENERIC);
        parser_match_tk(ctx, '(');

        if (first_of_type_name(ctx))
        {
            /*extension*/
            p_generic_selection->type_name = type_name(ctx);
        }
        else
        {
            p_generic_selection->expression = assignment_expression(ctx);
        }

        parser_match_tk(ctx, ',');

        p_generic_selection->generic_assoc_list = generic_association_list(ctx);


        struct type lvalue_type = {0};

        struct type* p_type = NULL;

        if (p_generic_selection->expression)
        {
            p_type = &p_generic_selection->expression->type;


            if (expression_is_subjected_to_lvalue_conversion(p_generic_selection->expression))
            {
                lvalue_type = type_lvalue_conversion(&p_generic_selection->expression->type);
                p_type = &lvalue_type;
            }

        }
        else
        {
            p_type = &p_generic_selection->type_name->declarator->type;
        }


        struct generic_association* current = p_generic_selection->generic_assoc_list.head;
        while (current)
        {
            if (current->p_type_name)
            {
                if (type_is_same(p_type, &current->type, true))
                {
                    p_generic_selection->p_view_selected_expression = current->expression;
                    break;
                }
            }
            else
            {
                /*default*/
                p_generic_selection->p_view_selected_expression = current->expression;
            }
            current = current->next;
        }

        p_generic_selection->last_token = ctx->current;
        parser_match_tk(ctx, ')');
        type_destroy(&lvalue_type);
    }
    catch
    {
    }
    return p_generic_selection;
}


/*
    https://en.wikipedia.org/wiki/UTF-8
    Since the restriction of the Unicode code-space to 21-bit values in 2003,
    UTF-8 is defined to encode code points in one to four bytes, depending on the number
    of significant bits in the numerical value of the code point. The following table shows
    the structure of the encoding. The x characters are replaced by the bits of the code point.

    Code point <->UTF - 8 conversion
    First         | Last           | Byte 1   | Byte 2   | Byte 3   | Byte 4
    --------------| -------------- |----------|----------|----------| ----------
    U+0000      0 | U+007F     127 | 0xxxxxxx |          |          |
    U+0080    128 | U+07FF    2047 | 110xxxxx | 10xxxxxx |          |
    U+0800   2048 | U+FFFF   65535 | 1110xxxx | 10xxxxxx | 10xxxxxx |
    U+10000 65536 | U+10FFFF 69631 | 11110xxx | 10xxxxxx | 10xxxxxx | 10xxxxxx
*/

const unsigned char* utf8_decode(const unsigned char* s, int* c)
{
    if (s[0] == '\0')
    {
        *c = 0;
        return 0;
    }

    const unsigned char* next = 0;
    if (s[0] < 0x80)
    {
        *c = s[0];
        assert(*c >= 0x0000 && *c <= 0x007F);
        next = s + 1;
    }
    else if ((s[0] & 0xe0) == 0xc0)
    {
        *c = ((int) (s[0] & 0x1f) << 6) |
            ((int) (s[1] & 0x3f) << 0);
        assert(*c >= 0x0080 && *c <= 0x07FF);
        next = s + 2;
    }
    else if ((s[0] & 0xf0) == 0xe0)
    {
        *c = ((int) (s[0] & 0x0f) << 12) |
            ((int) (s[1] & 0x3f) << 6) |
            ((int) (s[2] & 0x3f) << 0);
        assert(*c >= 0x0800 && *c <= 0xFFFF);
        next = s + 3;
    }
    else if ((s[0] & 0xf8) == 0xf0 && (s[0] <= 0xf4))
    {
        *c = ((int) (s[0] & 0x07) << 18) |
            ((int) (s[1] & 0x3f) << 12) |
            ((int) (s[2] & 0x3f) << 6) |
            ((int) (s[3] & 0x3f) << 0);
        assert(*c >= 0x100000 && *c <= 0x10FFFF);
        next = s + 4;
    }
    else
    {
        *c = -1; // invalid
        next = s + 1; // skip this byte
    }

    if (*c >= 0xd800 && *c <= 0xdfff)
    {
        *c = -1; // surrogate half
    }

    return next;
}

struct expression* owner character_constant_expression(struct parser_ctx* ctx)
{
    struct expression* owner p_expression_node = calloc(1, sizeof * p_expression_node);
    if (p_expression_node == NULL) return NULL;

    p_expression_node->expression_type = PRIMARY_EXPRESSION_CHAR_LITERAL;
    p_expression_node->first_token = ctx->current;
    p_expression_node->last_token = p_expression_node->first_token;
    p_expression_node->type.attributes_flags |= CAKE_HIDDEN_ATTRIBUTE_LIKE_CHAR;
    p_expression_node->type.category = TYPE_CATEGORY_ITSELF;

    const unsigned char* p = (const unsigned char* ) ctx->current->lexeme;

    if (p[0] == 'u' && p[1] == '8')
    {
        p++;
        p++;
        p++;

        //A UTF-8 character constant has type char8_t.
        p_expression_node->type.type_specifier_flags = TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_CHAR;

        int c = 0;
        p = utf8_decode(p, &c);

        if (p && *p != '\'')
        {
            compiler_set_error_with_token(C_MULTICHAR_ERROR, ctx, ctx->current, "Unicode character literals may not contain multiple characters.");
        }

        if (c > 0x80)
        {
            compiler_set_error_with_token(C_MULTICHAR_ERROR, ctx, ctx->current, "Character too large for enclosing character literal type.");
        }


        p_expression_node->constant_value = make_constant_value_ll(c, ctx->evaluation_is_disabled);
    }
    else if (p[0] == 'u')
    {
        p++;
        p++;

        //A UTF-16 character constant has type char16_t which is an unsigned integer types defined in the <uchar.h> header
        p_expression_node->type.type_specifier_flags = TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_SHORT;

        int c = 0;
        p = utf8_decode(p, &c);

        if (p && *p != '\'')
        {
            compiler_set_error_with_token(C_MULTICHAR_ERROR, ctx, ctx->current, "Unicode character literals may not contain multiple characters.");
        }

        if (c > USHRT_MAX)
        {
            compiler_set_error_with_token(C_MULTICHAR_ERROR, ctx, ctx->current, "Character too large for enclosing character literal type.");
        }

        p_expression_node->constant_value = make_constant_value_ll(c, ctx->evaluation_is_disabled);
    }
    else if (p[0] == 'U')
    {
        p++;
        p++;

        //A UTF-16 character constant has type char16_t which is an unsigned integer types defined in the <uchar.h> header
        p_expression_node->type.type_specifier_flags = TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_INT;

        int c = 0;
        p = utf8_decode(p, &c);

        if (p && *p != '\'')
        {
            compiler_set_error_with_token(C_MULTICHAR_ERROR, ctx, ctx->current, "Unicode character literals may not contain multiple characters.");
        }


        p_expression_node->constant_value = make_constant_value_ll(c, ctx->evaluation_is_disabled);
    }
    else if (p[0] == 'L')
    {
        //A wchar_t character constant is prefixed by the letter L
        p++;
        p++;

        if (sizeof(wchar_t) > sizeof(short))
        {
            p_expression_node->type.type_specifier_flags = TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_INT;
        }
        else
        {
            p_expression_node->type.type_specifier_flags = TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_SHORT;
        }
        /*
         wchar_t character constant prefixed by the letter L has type wchar_t, an integer type defined in
         the <stddef.h> header. The value of a wchar_t character constant containing a single multibyte
         character that maps to a single member of the extended execution character set is the wide character
         corresponding to that multibyte character in the implementation-defined wide literal encoding
         (6.2.9). The value of a wchar_t character constant containing more than one multibyte character or a
         single multibyte character that maps to multiple members of the extended execution character set,
         or containing a multibyte character or escape sequence not represented in the extended execution
         character set, is implementation-defined.
        */
        long long value = 0;
        while (*p != '\'')
        {
            int c = 0;
            p = utf8_decode(p, &c);
            if (p == 0)
                break;
            value = value * 256 + c;
        }

        p_expression_node->constant_value = make_constant_value_ll(value, ctx->evaluation_is_disabled);
    }
    else
    {
        p++;
        p_expression_node->type.type_specifier_flags = TYPE_SPECIFIER_INT;

        /*
          An integer character constant has type int. The value of an integer character constant containing
          a single character that maps to a single value in the literal encoding (6.2.9) is the numerical value
          of the representation of the mapped character in the literal encoding interpreted as an integer.
          The value of an integer character constant containing more than one character (e.g., ’ab’), or
          containing a character or escape sequence that does not map to a single value in the literal encoding,
          is implementation-defined. If an integer character constant contains a single character or escape
          sequence, its value is the one that results when an object with type char whose value is that of the
          single character or escape sequence is converted to type int.
        */
        long long value = 0;
        while (*p != '\'')
        {
            int c = 0;
            p = utf8_decode(p, &c);
            if (p == 0)
                break;
            value = value * 256 + c;
        }
        p_expression_node->constant_value = make_constant_value_ll(value, ctx->evaluation_is_disabled);
    }

    parser_match(ctx);



    //warning: character constant too long for its type
    return p_expression_node;
}


int convert_to_number(struct token* token, struct expression* p_expression_node, bool disabled)
{

    /*copia removendo os separadores*/
    //um dos maiores buffer necessarios seria 128 bits binario...
    //0xb1'1'1.... 
    int c = 0;
    char buffer[128 * 2 + 4] = {0};
    const char* s = token->lexeme;
    while (*s)
    {
        if (*s != '\'')
        {
            buffer[c] = *s;
            c++;
        }
        s++;
    }
    enum type_specifier_flags  flags = 0;
    parse_number(buffer, &flags);
    p_expression_node->type.type_specifier_flags = flags;

    switch (token->type)
    {
        case TK_COMPILER_DECIMAL_CONSTANT:

            if (flags & TYPE_SPECIFIER_UNSIGNED)
            {
                p_expression_node->constant_value = make_constant_value_ull(strtoull(buffer, 0, 10), disabled);
            }
            else
            {
                p_expression_node->constant_value = make_constant_value_ll(strtoll(buffer, 0, 10), disabled);
            }

            break;
        case TK_COMPILER_OCTAL_CONSTANT:
            p_expression_node->constant_value = make_constant_value_ll(strtoll(buffer, 0, 8), disabled);

            break;
        case TK_COMPILER_HEXADECIMAL_CONSTANT:
            p_expression_node->constant_value = make_constant_value_ll(strtoll(buffer + 2, 0, 16), disabled);

            break;
        case TK_COMPILER_BINARY_CONSTANT:
            p_expression_node->constant_value = make_constant_value_ll(strtoll(buffer + 2, 0, 2), disabled);
            break;
        case TK_COMPILER_DECIMAL_FLOATING_CONSTANT:
            p_expression_node->constant_value = make_constant_value_double(strtod(buffer, 0), disabled);
            break;
        case TK_COMPILER_HEXADECIMAL_FLOATING_CONSTANT:
            p_expression_node->constant_value = make_constant_value_double(strtod(buffer + 2, 0), disabled);
            break;
        default:
            assert(false);
    }

    return 0;
}

static bool is_integer_or_floating_constant(enum token_type type)
{
    return type == TK_COMPILER_DECIMAL_CONSTANT ||
        type == TK_COMPILER_OCTAL_CONSTANT ||
        type == TK_COMPILER_HEXADECIMAL_CONSTANT ||
        type == TK_COMPILER_BINARY_CONSTANT ||
        type == TK_COMPILER_DECIMAL_FLOATING_CONSTANT ||
        type == TK_COMPILER_HEXADECIMAL_FLOATING_CONSTANT;
}

struct object* expression_get_object(struct expression* p_expression, struct type* p_type)
{
    if (p_expression->expression_type == PRIMARY_EXPRESSION_DECLARATOR)
    {
        if (p_type)
            type_set(p_type, &p_expression->declarator->type);


        return &p_expression->declarator->object;
    }
    else if (p_expression->expression_type == UNARY_EXPRESSION_CONTENT)
    {
        if (p_type)
            type_set(p_type, &p_expression->type);

        struct object* p_obj = expression_get_object(p_expression->right, NULL);
        if (p_obj)
        {
            return p_obj->pointed;
        }
        return p_obj;
    }
    else if (p_expression->expression_type == UNARY_EXPRESSION_ADDRESSOF)
    {
        return expression_get_object(p_expression->right, p_type);
    }
    else if (p_expression->expression_type == PRIMARY_EXPRESSION_PARENTESIS)
    {
        return expression_get_object(p_expression->right, p_type);
    }
    else if (p_expression->expression_type == CAST_EXPRESSION)
    {
        if (p_type)
            type_set(p_type, &p_expression->type);

        return expression_get_object(p_expression->left, NULL);
    }
    else if (p_expression->expression_type == POSTFIX_DOT)
    {
        struct object* p_obj = expression_get_object(p_expression->left, NULL);
        if (p_obj)
        {
            if (p_type)
                type_set(p_type, &p_expression->type);
            if (p_expression->member_index < p_obj->members.size)
                return &p_obj->members.data[p_expression->member_index];
            else
            {
                // assert(false);
            }
        }
    }
    else if (p_expression->expression_type == POSTFIX_ARROW)
    {
        struct object* p_obj = expression_get_object(p_expression->left, NULL);
        if (p_obj &&
            p_obj->pointed)
        {
            if (p_type)
                type_set(p_type, &p_expression->type);
            if (p_expression->member_index < p_obj->pointed->members.size)
                return &p_obj->pointed->members.data[p_expression->member_index];
            else
            {
                assert(false);
            }
        }
    }
    else if (p_expression->expression_type == POSTFIX_FUNCTION_CALL)
    {
        if (p_type)
            type_set(p_type, &p_expression->type);
        return NULL;

    }
    else if (p_expression->expression_type == POSTFIX_EXPRESSION_COMPOUND_LITERAL)
    {
        if (p_type)
            type_set(p_type, &p_expression->type);

        return &p_expression->type_name->declarator->object;
    }


    if (p_type)
        type_set(p_type, &p_expression->type);
    return NULL;
}


struct expression* owner primary_expression(struct parser_ctx* ctx)
{
    /*
     primary-expression:
      identifier
      constant
      string-literal
      ( expression )
      generic-selection
    */
    struct expression* owner p_expression_node = NULL;
    try
    {
        if (ctx->current->type == TK_IDENTIFIER)
        {
            p_expression_node = calloc(1, sizeof * p_expression_node);

            if (p_expression_node == NULL) throw;

            p_expression_node->first_token = ctx->current;
            p_expression_node->last_token = ctx->current;

            struct map_entry* p_entry = find_variables(ctx, ctx->current->lexeme, NULL);

            if (p_entry && p_entry->type == TAG_TYPE_ENUMERATOR)
            {
                struct enumerator* p_enumerator = p_entry->p;
                p_expression_node->expression_type = PRIMARY_EXPRESSION_ENUMERATOR;
                p_expression_node->constant_value = make_constant_value_ll(p_enumerator->value, ctx->evaluation_is_disabled);

                p_expression_node->type = type_make_enumerator(p_enumerator->enum_specifier);

            }
            else if (p_entry &&
                (p_entry->type == TAG_TYPE_ONLY_DECLARATOR || p_entry->type == TAG_TYPE_INIT_DECLARATOR))
            {
                struct declarator* p_declarator = NULL;
                struct init_declarator* p_init_declarator = NULL;
                if (p_entry->type == TAG_TYPE_INIT_DECLARATOR)
                {
                    p_init_declarator = p_entry->p;
                    p_declarator = p_init_declarator->p_declarator;
                }
                else
                {
                    p_declarator = p_entry->p;
                }

                if (type_is_deprecated(&p_declarator->type))
                {
                    compiler_set_warning_with_token(W_DEPRECATED, ctx, ctx->current, "'%s' is deprecated", ctx->current->lexeme);
                }

                p_declarator->num_uses++;
                p_expression_node->declarator = p_declarator;
                p_expression_node->expression_type = PRIMARY_EXPRESSION_DECLARATOR;
                

                p_expression_node->type = type_dup(&p_declarator->type);
                if (p_init_declarator)
                {
                    if (p_init_declarator->p_declarator &&
                        p_init_declarator->p_declarator->declaration_specifiers &&
                        p_init_declarator->p_declarator->declaration_specifiers->storage_class_specifier_flags & STORAGE_SPECIFIER_CONSTEXPR)
                    {
                        if (p_init_declarator->initializer &&
                            p_init_declarator->initializer->assignment_expression)
                        {
                            p_expression_node->constant_value =
                                p_init_declarator->initializer->assignment_expression->constant_value;
                        }
                    }
                }
            }
            else if (ctx->p_current_function_opt &&
                strcmp(ctx->current->lexeme, "__func__") == 0)
            {
                /*
                   not sure if this is the best way to implement but
                   works for now
                */
                const char* funcname =
                    ctx->p_current_function_opt->init_declarator_list.head->p_declarator->name->lexeme;

                p_expression_node->expression_type = PRIMARY_EXPRESSION__FUNC__;
                p_expression_node->first_token = ctx->current;
                p_expression_node->last_token = ctx->current;

                p_expression_node->type = type_make_literal_string(strlen(funcname) + 1, TYPE_SPECIFIER_CHAR);
                
            }
            else
            {
                compiler_set_error_with_token(C_NOT_FOUND, ctx, ctx->current, "not found '%s'", ctx->current->lexeme);
                throw;
            }
            parser_match(ctx);
        }
        else if (ctx->current->type == TK_STRING_LITERAL)
        {
            p_expression_node = calloc(1, sizeof * p_expression_node);
            if (p_expression_node == NULL) throw;

            p_expression_node->expression_type = PRIMARY_EXPRESSION_STRING_LITERAL;
            p_expression_node->first_token = ctx->current;
            p_expression_node->last_token = ctx->current;
            

            enum type_specifier_flags char_type = TYPE_SPECIFIER_CHAR;

            if (get_char_type(ctx->current->lexeme) == 2)
            {
                if (sizeof(wchar_t) == 2)
                    char_type = TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_SHORT;
                else if (sizeof(wchar_t) == 4)
                    char_type = TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_INT;
            }

            p_expression_node->type = type_make_literal_string(string_literal_byte_size(ctx->current->lexeme), char_type);

            parser_match(ctx);

            /*
            string concatenation deveria ser em uma phase anterior
            mas como mantemos as forma do fonte aqui foi uma alternativa
            */
            while (ctx->current &&
                ctx->current->type == TK_STRING_LITERAL)
            {
                parser_match(ctx);
            }
        }
        else if (ctx->current->type == TK_CHAR_CONSTANT)
        {
            p_expression_node = character_constant_expression(ctx);
        }

        else if (ctx->current->type == TK_KEYWORD_TRUE ||
            ctx->current->type == TK_KEYWORD_FALSE)
        {
            p_expression_node = calloc(1, sizeof * p_expression_node);
            if (p_expression_node == NULL) throw;

            p_expression_node->expression_type = PRIMARY_EXPRESSION_PREDEFINED_CONSTANT;
            p_expression_node->first_token = ctx->current;
            p_expression_node->last_token = ctx->current;

            p_expression_node->constant_value =
                make_constant_value_ll(ctx->current->type == TK_KEYWORD_TRUE ? 1 : 0, ctx->evaluation_is_disabled);

            p_expression_node->type.type_specifier_flags = TYPE_SPECIFIER_BOOL;
            p_expression_node->type.type_qualifier_flags = 0;



            parser_match(ctx);
        }
        else if (ctx->current->type == TK_KEYWORD_NULLPTR)
        {
            p_expression_node = calloc(1, sizeof * p_expression_node);
            if (p_expression_node == NULL) throw;

            p_expression_node->expression_type = PRIMARY_EXPRESSION_PREDEFINED_CONSTANT;
            p_expression_node->first_token = ctx->current;
            p_expression_node->last_token = ctx->current;


            p_expression_node->constant_value = make_constant_value_ll(0, ctx->evaluation_is_disabled);

            /*TODO nullptr type*/
            p_expression_node->type.type_specifier_flags = TYPE_SPECIFIER_NULLPTR_T;
            p_expression_node->type.type_qualifier_flags = 0;



            parser_match(ctx);
        }
        else if (is_integer_or_floating_constant(ctx->current->type))
        {
            p_expression_node = calloc(1, sizeof * p_expression_node);
            if (p_expression_node == NULL) throw;

            p_expression_node->first_token = ctx->current;
            p_expression_node->last_token = ctx->current;
            p_expression_node->expression_type = PRIMARY_EXPRESSION_NUMBER;

            convert_to_number(ctx->current, p_expression_node, ctx->evaluation_is_disabled);

            parser_match(ctx);
        }
        else if (ctx->current->type == TK_KEYWORD__GENERIC)
        {
            p_expression_node = calloc(1, sizeof * p_expression_node);
            if (p_expression_node == NULL) throw;
            p_expression_node->first_token = ctx->current;

            p_expression_node->expression_type = PRIMARY_EXPRESSION_GENERIC;

            p_expression_node->generic_selection = generic_selection(ctx);

            p_expression_node->last_token = p_expression_node->generic_selection->last_token;

            if (p_expression_node->generic_selection->p_view_selected_expression)
            {
                p_expression_node->type = type_dup(&p_expression_node->generic_selection->p_view_selected_expression->type);

                p_expression_node->constant_value = p_expression_node->generic_selection->p_view_selected_expression->constant_value;
            }
            else
            {
                compiler_set_error_with_token(C_NO_MATCH_FOR_GENERIC, ctx, ctx->current, "no match for generic");
            }
        }
        else if (ctx->current->type == '(')
        {
            p_expression_node = calloc(1, sizeof * p_expression_node);
            p_expression_node->expression_type = PRIMARY_EXPRESSION_PARENTESIS;
            p_expression_node->first_token = ctx->current;
            parser_match(ctx);
            p_expression_node->right = expression(ctx);
            
            

            p_expression_node->type = type_dup(&p_expression_node->right->type);
            p_expression_node->constant_value = p_expression_node->right->constant_value;
            if (p_expression_node->right == NULL) throw;
            p_expression_node->last_token = ctx->current;
            parser_match_tk(ctx, ')');

        }
        else
        {
            compiler_set_error_with_token(C_UNEXPECTED, ctx, ctx->current, "unexpected");
        }
    }
    catch
    {
    }


    assert(p_expression_node == NULL || (p_expression_node->first_token && p_expression_node->last_token));


    return p_expression_node;
}


void argument_expression_delete(struct argument_expression* owner p)
{
    if (p)
    {
        expression_delete(p->expression);
        assert(p->next == NULL);
        free(p);
    }
}

struct argument_expression_list argument_expression_list(struct parser_ctx* ctx)
{
    /*
     argument-expression-list:
      assignment-expression
      argument-expression-ctx , assignment-expression
    */

    /*
     argument-expression-list: (extended)
      assignment-expression
      move assignment-expression
      argument-expression-ctx , assignment-expression
      argument-expression-ctx , assignment-expression
    */

    struct argument_expression_list list = {0};
    struct argument_expression* owner p_argument_expression = NULL;

    try
    {
        p_argument_expression = calloc(1, sizeof(struct argument_expression));
        if (p_argument_expression == NULL) throw;


        p_argument_expression->expression = assignment_expression(ctx);
        LIST_ADD(&list, p_argument_expression);

        while (ctx->current->type == ',')
        {
            parser_match(ctx);


            struct argument_expression* owner p_argument_expression_2 = calloc(1, sizeof * p_argument_expression_2);
            if (p_argument_expression_2 == NULL) throw;

            p_argument_expression_2->expression = assignment_expression(ctx);
            if (p_argument_expression_2->expression == NULL)
            {
                argument_expression_delete(p_argument_expression_2);
                throw;
            }

            LIST_ADD(&list, p_argument_expression_2);
        }
    }
    catch
    {
    }
    return list;
}



bool first_of_postfix_expression(struct parser_ctx* ctx)
{
    //( type-name )  postfix confunde com (expression) primary
    if (first_of_type_name_ahead(ctx))
        return true; //acho q  nao precisa pq primary tb serve p postif
    return is_first_of_primary_expression(ctx);
}

static void fix_member_type(struct type* p_type, const struct type* struct_type, const struct type* member_type)
{
    if (struct_type->type_qualifier_flags & TYPE_QUALIFIER_CONST)
    {
        /*
          struct X { int i; };
          const struct X x;
          x.i ;//x.i is const
        */
        p_type->type_qualifier_flags |= TYPE_QUALIFIER_CONST;
    }

    /*
          struct X { int i; };
          const struct X x;
          x.i ;//x.i is also local, or parameter etc.
    */
    p_type->storage_class_specifier_flags = struct_type->storage_class_specifier_flags;


    if (struct_type->type_qualifier_flags & TYPE_QUALIFIER_VIEW)
    {
        /*
          struct X { owner int i; };
          view struct X x;
          x.i ;//is is not owner
        */
        p_type->type_qualifier_flags &= ~TYPE_QUALIFIER_OWNER;
    }

}


static void fix_arrow_member_type(struct type* p_type, const struct type* left, const struct type* member_type)
{
    struct type t = type_remove_pointer(left);

    if (t.type_qualifier_flags & TYPE_QUALIFIER_CONST)
    {
        /*
           const struct X * p;
        */

        p_type->type_qualifier_flags |= TYPE_QUALIFIER_CONST;
    }


    if (t.type_qualifier_flags & TYPE_QUALIFIER_VIEW)
    {
        /*
          view struct X * p;
        */
        p_type->type_qualifier_flags &= ~TYPE_QUALIFIER_OWNER;
    }

    type_destroy(&t);
}

struct expression* owner postfix_expression_tail(struct parser_ctx* ctx, struct expression* owner p_expression_node)
{
    try
    {
        while (ctx->current != NULL)
        {
            if (ctx->current->type == '[')
            {
                struct expression* owner p_expression_node_new = calloc(1, sizeof * p_expression_node_new);

                static_set(*p_expression_node_new, "zero");

                p_expression_node_new->first_token = ctx->current;
                p_expression_node_new->expression_type = POSTFIX_ARRAY;
                //the result of the subscription operator ([])
                

                if (!type_is_pointer_or_array(&p_expression_node->type))
                {
                    compiler_set_error_with_token(C_SUBSCRIPTED_VALUE_IS_NEITHER_ARRAY_NOR_POINTER,
                        ctx,
                        ctx->current,
                        "subscripted value is neither array nor pointer");
                }


                if (type_is_pointer(&p_expression_node->type))
                {
                    p_expression_node_new->type = type_remove_pointer(&p_expression_node->type);
                }
                else if (type_is_array(&p_expression_node->type))
                {
                    p_expression_node_new->type = get_array_item_type(&p_expression_node->type);
                }

                parser_match(ctx);
                /*contem a expresao de dentro do  [ ] */
                p_expression_node_new->right = expression(ctx);
                if (p_expression_node_new->right == NULL)
                {
                    expression_delete(p_expression_node_new);
                    throw;
                }

                if (constant_value_is_valid(&p_expression_node_new->right->constant_value))
                {
                    unsigned long long index =
                        constant_value_to_ull(&p_expression_node_new->right->constant_value);
                    if (type_is_array(&p_expression_node->type))
                    {
                        if (p_expression_node->type.array_size > 0)
                        {
                            if (index >= (unsigned long long) p_expression_node->type.array_size)
                            {
                                compiler_set_error_with_token(C_SUBSCRIPTED_VALUE_IS_NEITHER_ARRAY_NOR_POINTER,
                                    ctx,
                                    ctx->current,
                                    "index %d is past the end of the array", index);
                            }
                        }
                    }
                }
                parser_match_tk(ctx, ']');

                p_expression_node_new->left = p_expression_node;
                p_expression_node = p_expression_node_new;
            }
            else if (ctx->current->type == '(')
            {
                struct expression* owner p_expression_node_new = calloc(1, sizeof * p_expression_node_new);

                static_set(*p_expression_node_new, "zero");
                p_expression_node_new->first_token = p_expression_node->first_token;
                p_expression_node_new->expression_type = POSTFIX_FUNCTION_CALL;



                if (!type_is_function_or_function_pointer(&p_expression_node->type))
                {
                    compiler_set_error_with_token(C_CALLED_OBJECT_IS_NOT_FUNCTION_OR_FUNCTION_POINTER,
                        ctx,
                        ctx->current,
                        "called object is not attr function or function pointer");

                    expression_delete(p_expression_node_new);
                    throw;
                }

                p_expression_node_new->type = get_function_return_type(&p_expression_node->type);

                parser_match(ctx);
                if (ctx->current->type != ')')
                {
                    p_expression_node_new->argument_expression_list = argument_expression_list(ctx);
                }
                parser_match_tk(ctx, ')');
                compare_function_arguments(ctx, &p_expression_node->type, &p_expression_node_new->argument_expression_list);
                p_expression_node_new->last_token = ctx->previous;

                p_expression_node_new->left = p_expression_node;
                p_expression_node = p_expression_node_new;
            }
            else if (ctx->current->type == '.')
            {
                struct expression* owner p_expression_node_new = calloc(1, sizeof * p_expression_node_new);
                static_set(*p_expression_node_new, "zero");
                p_expression_node_new->first_token = ctx->current;
                p_expression_node_new->expression_type = POSTFIX_DOT;
                p_expression_node_new->left = p_expression_node;
                
                p_expression_node_new->declarator = p_expression_node_new->left->declarator;

                parser_match(ctx);
                if (p_expression_node->type.type_specifier_flags & TYPE_SPECIFIER_STRUCT_OR_UNION)
                {
                    struct struct_or_union_specifier* p =
                        find_struct_or_union_specifier(ctx, p_expression_node->type.struct_or_union_specifier->tag_name);
                    p = get_complete_struct_or_union_specifier(p);
                    if (p)
                    {
                        int member_index = 0;
                        struct member_declarator* p_member_declarator =
                            find_member_declarator(&p->member_declaration_list, ctx->current->lexeme, &member_index);
                        if (p_member_declarator)
                        {
                            p_expression_node_new->member_index = member_index;

                            p_expression_node_new->type = make_type_using_declarator(ctx, p_member_declarator->declarator);

                            fix_member_type(&p_expression_node_new->type,
                                &p_expression_node_new->left->type,
                                &p_member_declarator->declarator->type);
                        }
                        else
                        {
                            compiler_set_error_with_token(C_STRUCT_MEMBER_NOT_FOUND,
                                ctx,
                                ctx->current,
                                "struct member '%s' not found in '%s'",
                                ctx->current->lexeme,
                                p_expression_node->type.struct_or_union_specifier->tag_name);
                        }
                    }
                    else
                    {
                        print_scope(&ctx->scopes);
                    }
                    parser_match_tk(ctx, TK_IDENTIFIER);
                }
                else
                {
                    compiler_set_error_with_token(C_STRUCTURE_OR_UNION_REQUIRED,
                        ctx,
                        ctx->current,
                        "structure or union required");
                }
                //todo apontar pro nome?
                p_expression_node = p_expression_node_new;
            }
            else if (ctx->current->type == '->')
            {
                struct expression* owner p_expression_node_new = calloc(1, sizeof * p_expression_node_new);
                static_set(*p_expression_node_new, "zero");
                p_expression_node_new->first_token = ctx->current;
                p_expression_node_new->expression_type = POSTFIX_ARROW;
                
                //the result of a member access through pointer -> operator is lvalue
                


                parser_match(ctx);

                if (type_is_pointer_or_array(&p_expression_node->type))
                {
                    struct type item_type = {0};
                    if (type_is_array(&p_expression_node->type))
                    {
                        compiler_set_info_with_token(W_STYLE, ctx, ctx->current, "using '->' in array as pointer to struct");
                        item_type = get_array_item_type(&p_expression_node->type);
                    }
                    else
                    {
                        item_type = type_remove_pointer(&p_expression_node->type);
                    }

                    if (type_is_struct_or_union(&item_type))
                    {
                        struct struct_or_union_specifier* p_complete =
                            get_complete_struct_or_union_specifier(p_expression_node->type.next->struct_or_union_specifier);

                        if (p_complete)
                        {
                            int member_index = 0;
                            struct member_declarator* p_member_declarator =
                                find_member_declarator(&p_complete->member_declaration_list, ctx->current->lexeme, &member_index);

                            if (p_member_declarator)
                            {
                                p_expression_node_new->member_index = member_index;
                                p_expression_node_new->type = make_type_using_declarator(ctx, p_member_declarator->declarator);
                                fix_arrow_member_type(&p_expression_node_new->type, &p_expression_node->type, &p_expression_node_new->type);
                            }
                            else
                            {
                                compiler_set_error_with_token(C_STRUCT_MEMBER_NOT_FOUND,
                                    ctx,
                                    ctx->current,
                                    "member '%s' not found in struct '%s'",
                                    ctx->current->lexeme,
                                    p_expression_node->type.next->struct_or_union_specifier->tag_name);

                            }
                        }
                        else
                        {
                            compiler_set_error_with_token(C_STRUCT_IS_INCOMPLETE,
                                ctx,
                                ctx->current,
                                "struct '%s' is incomplete.",
                                ctx->current->lexeme);
                        }
                        parser_match_tk(ctx, TK_IDENTIFIER);
                    }
                    else
                    {
                        compiler_set_error_with_token(C_STRUCTURE_OR_UNION_REQUIRED,
                            ctx,
                            ctx->current,
                            "structure or union required");
                    }
                    type_destroy(&item_type);
                }
                else
                {
                    compiler_set_error_with_token(C_STRUCTURE_OR_UNION_REQUIRED,
                        ctx,
                        ctx->current,
                        "structure or union required");
                }

                p_expression_node_new->left = p_expression_node;
                p_expression_node = p_expression_node_new;
            }
            else if (ctx->current->type == '++')
            {
                if (!expression_is_lvalue(p_expression_node))
                {
                    compiler_set_error_with_token(C_OPERATOR_NEEDS_LVALUE,
                        ctx,
                        p_expression_node->first_token,
                        "lvalue required as increment operand");
                }

                struct expression* owner p_expression_node_new = calloc(1, sizeof * p_expression_node_new);

                static_set(*p_expression_node_new, "zero");
                p_expression_node_new->first_token = ctx->current;
                p_expression_node_new->expression_type = POSTFIX_INCREMENT;

                p_expression_node_new->type = type_dup(&p_expression_node->type);
                parser_match(ctx);
                p_expression_node_new->left = p_expression_node;
                p_expression_node = p_expression_node_new;
            }
            else if (ctx->current->type == '--')
            {
                if (!expression_is_lvalue(p_expression_node))
                {
                    compiler_set_error_with_token(C_OPERATOR_NEEDS_LVALUE,
                        ctx,
                        p_expression_node->first_token,
                        "lvalue required as decrement operand");
                }

                struct expression* owner p_expression_node_new = calloc(1, sizeof * p_expression_node_new);

                static_set(*p_expression_node_new, "zero");
                p_expression_node_new->first_token = ctx->current;
                p_expression_node_new->expression_type = POSTFIX_DECREMENT;

                p_expression_node_new->type = type_dup(&p_expression_node->type);
                parser_match(ctx);
                p_expression_node_new->left = p_expression_node;
                p_expression_node = p_expression_node_new;
            }
            else
            {
                break;
            }
        }
    }
    catch
    {
    }

    return p_expression_node;
}

struct expression* owner postfix_expression_type_name(struct parser_ctx* ctx, struct type_name* owner p_type_name)
{
    /*
        ( type-name ) { initializer-ctx }
        ( type-name ) { initializer-ctx , }

        //My extension : if type-name is function then follow is compound-statement
        ( type-name ) compound-statement

    */

    struct expression* owner p_expression_node = NULL;

    try
    {
        p_expression_node = calloc(1, sizeof * p_expression_node);
        if (p_expression_node == NULL) throw;

        static_set(*p_expression_node, "zero");
        assert(p_expression_node->type_name == NULL);

        p_expression_node->first_token = previous_parser_token(p_type_name->first_token);
        assert(p_expression_node->first_token->type == '(');

        p_expression_node->type_name = p_type_name;
        p_expression_node->type = make_type_using_declarator(ctx, p_expression_node->type_name->declarator);


        if (type_is_function(&p_type_name->declarator->type))
        {
            p_expression_node->expression_type = POSTFIX_EXPRESSION_FUNCTION_LITERAL;

            struct scope* parameters_scope =
                &p_expression_node->type_name->declarator->direct_declarator->function_declarator->parameters_scope;

            scope_list_push(&ctx->scopes, parameters_scope);
            p_expression_node->compound_statement = function_body(ctx);
            scope_list_pop(&ctx->scopes);

        }
        else
        {
            p_expression_node->expression_type = POSTFIX_EXPRESSION_COMPOUND_LITERAL;
            p_expression_node->braced_initializer = braced_initializer(ctx);
            
        }

        p_expression_node->last_token = ctx->previous;

        p_expression_node = postfix_expression_tail(ctx, p_expression_node);
        if (p_expression_node == NULL) throw;

    }
    catch
    {
    }

    return p_expression_node;
}

struct expression* owner postfix_expression(struct parser_ctx* ctx)
{
    /*
      postfix-expression:
        primary-expression
        postfix-expression [ expression ]
        postfix-expression ( argument-expression-list_opt)
        postfix-expression . identifier
        postfix-expression -> identifier
        postfix-expression ++
        postfix-expression --
        ( type-name ) { initializer-ctx }
        ( type-name ) { initializer-ctx , }

        //My extension : if type-name is function then follow is compound-statement
        ( type-name ) compound-statement

        */
    struct expression* owner p_expression_node = NULL;
    try
    {
        if (first_of_type_name_ahead(ctx)) //aqui preciso ver se nao eh primary
        {
            assert(false); //este caso esta pegando lá dentro deo cast expression.
            p_expression_node = calloc(1, sizeof * p_expression_node);
            if (p_expression_node == NULL) throw;

            static_set(*p_expression_node, "zero");

            p_expression_node->first_token = ctx->current;
            parser_match_tk(ctx, '(');
            p_expression_node->type_name = type_name(ctx);
            if (p_expression_node->type_name == NULL) throw;

            p_expression_node->type = make_type_using_declarator(ctx, p_expression_node->type_name->declarator);

            parser_match_tk(ctx, ')');
            //printf("\n");
            //print_type(&p_expression_node->type);
            bool is_function_type = type_is_function(&p_expression_node->type);

            if (is_function_type)
            {
                p_expression_node->expression_type = POSTFIX_EXPRESSION_FUNCTION_LITERAL;
                p_expression_node->compound_statement = compound_statement(ctx);
                if (p_expression_node->compound_statement == NULL) throw;

                p_expression_node->last_token = p_expression_node->compound_statement->last_token;
            }
            else
            {
                p_expression_node->expression_type = POSTFIX_EXPRESSION_COMPOUND_LITERAL;
                p_expression_node->braced_initializer = braced_initializer(ctx);
                p_expression_node->last_token = ctx->current;
            }
        }
        else
        {
            p_expression_node = primary_expression(ctx);
            if (p_expression_node == NULL) throw;
        }

        p_expression_node = postfix_expression_tail(ctx, p_expression_node);
        if (p_expression_node == NULL) throw;
    }
    catch
    {
    }
    return p_expression_node;
}

bool is_first_of_compiler_function(struct parser_ctx* ctx)
{
    if (ctx->current == NULL)
        return false;

    return
        //traits
        ctx->current->type == TK_KEYWORD_IS_LVALUE ||
        ctx->current->type == TK_KEYWORD_IS_OWNER ||
        ctx->current->type == TK_KEYWORD_IS_CONST ||
        ctx->current->type == TK_KEYWORD_IS_POINTER ||
        ctx->current->type == TK_KEYWORD_IS_ARRAY ||
        ctx->current->type == TK_KEYWORD_IS_FUNCTION ||

        ctx->current->type == TK_KEYWORD_ASSERT ||

        ctx->current->type == TK_KEYWORD_IS_SCALAR ||
        ctx->current->type == TK_KEYWORD_IS_ARITHMETIC ||
        ctx->current->type == TK_KEYWORD_IS_FLOATING_POINT ||
        ctx->current->type == TK_KEYWORD_IS_INTEGRAL ||
        //

        ctx->current->type == TK_KEYWORD_ATTR_ADD ||
        ctx->current->type == TK_KEYWORD_ATTR_REMOVE ||
        ctx->current->type == TK_KEYWORD_ATTR_HAS;
}

bool is_first_of_unary_expression(struct parser_ctx* ctx)
{
    if (ctx->current == NULL)
        return false;
    return  first_of_postfix_expression(ctx) ||
        ctx->current->type == '++' ||
        ctx->current->type == '--' ||
        ctx->current->type == '&' ||
        ctx->current->type == '*' ||
        ctx->current->type == '+' ||
        ctx->current->type == '-' ||
        ctx->current->type == '~' ||
        ctx->current->type == '!' ||
        ctx->current->type == TK_KEYWORD_SIZEOF ||
        ctx->current->type == TK_KEYWORD__ALIGNOF ||
        is_first_of_compiler_function(ctx);
}


struct expression* owner unary_expression(struct parser_ctx* ctx)
{
    /*
    unary-expression:
      postfix-expression
      ++ unary-expression
      -- unary-expression

      one of (& * + - ~ !) cast-expression

      sizeof unary-expression
      sizeof ( type-name )
      _Alignof ( type-name )



      */
    struct expression* owner p_expression_node = NULL;
    try
    {
        if (ctx->current->type == '++' || ctx->current->type == '--')
        {
            struct expression* owner new_expression = calloc(1, sizeof * new_expression);
            new_expression->first_token = ctx->current;

            static_set(*new_expression, "zero");
            if (ctx->current->type == '++')
                new_expression->expression_type = UNARY_EXPRESSION_INCREMENT;
            else
                new_expression->expression_type = UNARY_EXPRESSION_DECREMENT;
            parser_match(ctx);
            new_expression->right = unary_expression(ctx);
            if (new_expression->right == NULL)
            {
                expression_delete(new_expression);
                throw;
            }

            new_expression->type = type_dup(&new_expression->right->type);
            p_expression_node = new_expression;
        }
        else if (ctx->current != NULL &&
            (ctx->current->type == '&'
                || ctx->current->type == '*'
                || ctx->current->type == '+'
                || ctx->current->type == '-'
                || ctx->current->type == '~'
                || ctx->current->type == '!'))
        {

            struct expression* owner new_expression = calloc(1, sizeof * new_expression);
            static_set(*new_expression, "zero");
            new_expression->first_token = ctx->current;

            struct token* op_position = ctx->current; //marcar posicao
            enum token_type op = ctx->current->type;
            parser_match(ctx);
#if 0
            //visual studio formater is adding spaces..
            if (style_has_space(ctx->current))
            {
                compiler_set_info_with_token(W_STYLE, ctx, ctx->current, "don't use spaces");
            }
#endif

            new_expression->right = cast_expression(ctx);
            if (new_expression->right == NULL)
            {
                expression_delete(new_expression);
                throw;
            }

            new_expression->last_token = new_expression->right->last_token;
            if (op == '!')
            {
                new_expression->expression_type = UNARY_EXPRESSION_NOT;
                new_expression->constant_value = constant_value_unary_op(&new_expression->right->constant_value, op);

                //same as v == 0

                new_expression->type = type_make_int_bool_like();
            }
            else if (op == '~')
            {
                new_expression->expression_type = UNARY_EXPRESSION_BITNOT;
                new_expression->constant_value = constant_value_unary_op(&new_expression->right->constant_value, op);

                new_expression->type = type_dup(&new_expression->right->type);
            }
            else if (op == '-')
            {
                new_expression->expression_type = UNARY_EXPRESSION_NEG;

                new_expression->constant_value = constant_value_unary_op(&new_expression->right->constant_value, op);

                new_expression->type = type_dup(&new_expression->right->type);
                
            }
            else if (op == '+')
            {
                new_expression->expression_type = UNARY_EXPRESSION_PLUS;

                new_expression->constant_value = constant_value_unary_op(&new_expression->right->constant_value, op);

                new_expression->type = type_dup(&new_expression->right->type);
                
            }
            else if (op == '*')
            {
                new_expression->expression_type = UNARY_EXPRESSION_CONTENT;
                //the result of the indirection(unary*) operator applied to a pointer to object
                

                if (!type_is_pointer(&new_expression->right->type))
                {
                    compiler_set_error_with_token(C_INDIRECTION_REQUIRES_POINTER_OPERAND,
                        ctx,
                        op_position,
                        "indirection requires pointer operand");
                }
                new_expression->type = type_remove_pointer(&new_expression->right->type);
            }
            else if (op == '&')
            {
                /*
                  The result of the unary & operator is a pointer to the object referred to by the lvalue-expression.
                  If the type of the lvalue-expression is " . . . ", the type of the result is
                  "pointer to . . ."
                */
                new_expression->expression_type = UNARY_EXPRESSION_ADDRESSOF;

                if (!expression_is_lvalue(new_expression->right))
                {
                    compiler_set_error_with_token(C_ADDRESS_OF_REGISTER,
                        ctx,
                        new_expression->right->first_token,
                        "lvalue required as unary '&' operand");
                }

                if (new_expression->right->type.storage_class_specifier_flags & STORAGE_SPECIFIER_REGISTER)
                {
                    if (new_expression->right->declarator)
                    {
                        compiler_set_error_with_token(C_ADDRESS_OF_REGISTER,
                            ctx,
                            new_expression->right->first_token,
                            "address of register variable 'x' requested",
                            new_expression->right->declarator->name->lexeme);
                    }
                    else
                    {
                        compiler_set_error_with_token(C_ADDRESS_OF_REGISTER,
                            ctx,
                            new_expression->right->first_token,
                            "address of register variable requested - declarator?");
                    }

                }

                new_expression->type = type_add_pointer(&new_expression->right->type);
                new_expression->type.address_of = true;
            }
            else
            {
                expression_delete(new_expression);
                compiler_set_error_with_token(C_INVALID_TOKEN,
                    ctx,
                    ctx->current,
                    "invalid token");
                throw;
            }
            p_expression_node = new_expression;
        }
        else if (ctx->current->type == TK_KEYWORD_SIZEOF)
        {
            const bool disable_evaluation_copy = ctx->evaluation_is_disabled;
            ctx->evaluation_is_disabled = true;
            //defer would be nice here...

            parser_match(ctx);
            struct expression* owner new_expression = calloc(1, sizeof * new_expression);

            static_set(*new_expression, "zero");
            new_expression->first_token = ctx->current;

            if (first_of_type_name_ahead(ctx))
            {
                new_expression->expression_type = UNARY_EXPRESSION_SIZEOF_TYPE;
                parser_match_tk(ctx, '(');
                new_expression->type_name = type_name(ctx);

                new_expression->type = type_make_int();

                parser_match_tk(ctx, ')');

                new_expression->constant_value = make_constant_value_ll(type_get_sizeof(&new_expression->type_name->declarator->type), false);
            }
            else
            {
                new_expression->right = unary_expression(ctx);
                if (new_expression->right == NULL)
                {
                    /*restore*/
                    ctx->evaluation_is_disabled = disable_evaluation_copy;
                    expression_delete(new_expression);
                    throw;
                }


                new_expression->expression_type = UNARY_EXPRESSION_SIZEOF_EXPRESSION;

                new_expression->constant_value = make_constant_value_ll(type_get_sizeof(&new_expression->right->type), false);
            }

            type_destroy(&new_expression->type);
            new_expression->type = type_make_size_t();
            p_expression_node = new_expression;

            /*restore*/
            ctx->evaluation_is_disabled = disable_evaluation_copy;
        }
        else if (
            ctx->current->type == TK_KEYWORD_IS_LVALUE ||
            ctx->current->type == TK_KEYWORD_IS_OWNER ||
            ctx->current->type == TK_KEYWORD_IS_CONST ||
            ctx->current->type == TK_KEYWORD_IS_POINTER ||
            ctx->current->type == TK_KEYWORD_IS_ARRAY ||
            ctx->current->type == TK_KEYWORD_IS_FUNCTION ||
            ctx->current->type == TK_KEYWORD_IS_ARITHMETIC ||
            ctx->current->type == TK_KEYWORD_IS_SCALAR ||
            ctx->current->type == TK_KEYWORD_IS_FLOATING_POINT ||
            ctx->current->type == TK_KEYWORD_IS_INTEGRAL)
        {
            const bool disable_evaluation_copy = ctx->evaluation_is_disabled;
            ctx->evaluation_is_disabled = true;

            struct token* traits_token = ctx->current;

            struct expression* owner new_expression = calloc(1, sizeof * new_expression);

            static_set(*new_expression, "zero");
            new_expression->first_token = ctx->current;
            new_expression->expression_type = UNARY_EXPRESSION_TRAITS;

            parser_match(ctx);

            struct type* p_type = NULL;
            if (first_of_type_name_ahead(ctx))
            {
                parser_match_tk(ctx, '(');
                new_expression->type_name = type_name(ctx);
                new_expression->last_token = ctx->current;
                parser_match_tk(ctx, ')');
                p_type = &new_expression->type_name->declarator->type;
            }
            else
            {


                new_expression->right = unary_expression(ctx);
                if (new_expression->right == NULL)
                {
                    /*restore*/
                    ctx->evaluation_is_disabled = disable_evaluation_copy;
                    expression_delete(new_expression);
                    throw;
                }

                p_type = &new_expression->right->type;
                new_expression->last_token = ctx->previous;
            }

            switch (traits_token->type)
            {
                case TK_KEYWORD_IS_LVALUE:
                    new_expression->constant_value = make_constant_value_ll(expression_is_lvalue(new_expression->right), false);
                    break;

                case TK_KEYWORD_IS_CONST:
                    new_expression->constant_value = make_constant_value_ll(type_is_const(p_type), false);
                    break;
                case TK_KEYWORD_IS_OWNER:
                    new_expression->constant_value = make_constant_value_ll(type_is_owner(p_type), false);
                    break;

                case TK_KEYWORD_IS_POINTER:
                    new_expression->constant_value = make_constant_value_ll(type_is_pointer(p_type), false);

                    break;
                case TK_KEYWORD_IS_FUNCTION:
                    new_expression->constant_value = make_constant_value_ll(type_is_function(p_type), false);

                    break;
                case TK_KEYWORD_IS_ARRAY:
                    new_expression->constant_value = make_constant_value_ll(type_is_array(p_type), false);

                    break;
                case TK_KEYWORD_IS_ARITHMETIC:
                    new_expression->constant_value = make_constant_value_ll(type_is_arithmetic(p_type), false);

                    break;
                case TK_KEYWORD_IS_SCALAR:
                    new_expression->constant_value = make_constant_value_ll(type_is_scalar(p_type), false);

                    break;
                case TK_KEYWORD_IS_FLOATING_POINT:
                    new_expression->constant_value = make_constant_value_ll(type_is_floating_point(p_type), false);

                    break;
                case TK_KEYWORD_IS_INTEGRAL:
                    new_expression->constant_value = make_constant_value_ll(type_is_integer(p_type), false);

                    break;

                default:
                    assert(false);

            }


            new_expression->type = type_make_int_bool_like();
            p_expression_node = new_expression;
            /*restore*/
            ctx->evaluation_is_disabled = disable_evaluation_copy;
        }
        else if (ctx->current->type == TK_KEYWORD_ASSERT)
        {
            struct expression* owner new_expression = calloc(1, sizeof * new_expression);

            static_set(*new_expression, "zero");
            new_expression->expression_type = UNARY_EXPRESSION_ASSERT;
            new_expression->first_token = ctx->current;

            parser_match(ctx);
            parser_match_tk(ctx, '(');
            new_expression->right = expression(ctx);
            
            /*if (constant_value_is_valid(&new_expression->right->constant_value) &&
                !constant_value_to_bool(&new_expression->right->constant_value))
            {
                compiler_set_error_with_token(C_STATIC_ASSERT_FAILED, ctx, 
                    new_expression->right->first_token, "assert failed");
            }*/

            parser_match_tk(ctx, ')');
            return new_expression;
        }
        else if (ctx->current->type == TK_KEYWORD__ALIGNOF)
        {
            struct expression* owner new_expression = calloc(1, sizeof * new_expression);

            static_set(*new_expression, "zero");
            new_expression->expression_type = UNARY_EXPRESSION_ALIGNOF;
            new_expression->first_token = ctx->current;
            parser_match(ctx);
            parser_match_tk(ctx, '(');
            new_expression->type_name = type_name(ctx);
            parser_match_tk(ctx, ')');
            if (!ctx->evaluation_is_disabled)
            {
                new_expression->constant_value = make_constant_value_ll(type_get_alignof(&new_expression->type_name->type), ctx->evaluation_is_disabled);
            }
            new_expression->type = type_make_int();
            new_expression->last_token = ctx->previous;

            p_expression_node = new_expression;
        }
        else if (ctx->current->type == TK_KEYWORD__ALIGNAS)
        {
        }
        else //if (is_first_of_primary_expression(ctx))
        {
            p_expression_node = postfix_expression(ctx);
            if (p_expression_node == NULL) throw;
        }
    }
    catch
    {
    }

    return p_expression_node;
}

struct expression* owner cast_expression(struct parser_ctx* ctx)
{
    /*
     cast-expression:
      unary-expression
      ( type-name ) cast-expression


      ( type-name ) //<- extension void value
    */
    struct expression* owner p_expression_node = NULL;
    try
    {
        if (first_of_type_name_ahead(ctx))
        {
            p_expression_node = calloc(1, sizeof * p_expression_node);
            if (p_expression_node == NULL) throw;

            static_set(*p_expression_node, "zero");
            p_expression_node->first_token = ctx->current;
            p_expression_node->expression_type = CAST_EXPRESSION;
            parser_match_tk(ctx, '(');
            p_expression_node->type_name = type_name(ctx);
            if (p_expression_node->type_name == NULL)
            {
                expression_delete(p_expression_node);
                p_expression_node = NULL;
                throw;
            }


            p_expression_node->type = type_dup(&p_expression_node->type_name->type);

            //type_set_int(&ctx->result_type);
            //print_type_name(p_cast_expression->type_name);
            parser_match_tk(ctx, ')');
            //struct token_list r = copy_replacement_list(&l);
            //pop_f
            if (ctx->current->type == '{')
            {
                // Achar que era um cast_expression foi um engano...
                // porque apareceu o { então é compound literal que eh postfix.
                struct expression* owner new_expression = postfix_expression_type_name(ctx, p_expression_node->type_name);
                p_expression_node->type_name = NULL; //MOVED

                expression_delete(p_expression_node);
                p_expression_node = new_expression;
            }
            else if (is_first_of_unary_expression(ctx))
            {
                p_expression_node->left = cast_expression(ctx);
                if (p_expression_node->left == NULL)
                {
                    expression_delete(p_expression_node);
                    p_expression_node = NULL;
                    throw;
                }


                if (p_expression_node->left->type.storage_class_specifier_flags & STORAGE_SPECIFIER_FUNCTION_RETURN &&
                    type_is_owner(&p_expression_node->left->type))
                {
                    if (!type_is_owner(&p_expression_node->type))
                    {
                        if (type_is_pointer(&p_expression_node->left->type))
                        {
                            //(int*) malloc(1)
                            compiler_set_error_with_token(C_DISCARDING_OWNER, ctx, p_expression_node->first_token, "discarding owner pointer");
                        }
                        else
                        {
                            compiler_set_error_with_token(C_DISCARDING_OWNER, ctx, p_expression_node->first_token, "discarding owner");
                        }
                    }
                }

                p_expression_node->constant_value = p_expression_node->left->constant_value;

                type_destroy(&p_expression_node->type);
                p_expression_node->type = make_type_using_declarator(ctx, p_expression_node->type_name->declarator);
                if (type_is_floating_point(&p_expression_node->type))
                {
                    p_expression_node->constant_value =
                        constant_value_cast(&p_expression_node->constant_value, TYPE_DOUBLE);
                }
                else if (type_is_integer(&p_expression_node->type))
                {
                    if (type_is_unsigned_integer(&p_expression_node->type))
                    {
                        p_expression_node->constant_value =
                            constant_value_cast(&p_expression_node->constant_value, TYPE_UNSIGNED_LONG_LONG);
                    }
                    else
                    {
                        p_expression_node->constant_value =
                            constant_value_cast(&p_expression_node->constant_value, TYPE_LONG_LONG);
                    }
                }

                p_expression_node->type.storage_class_specifier_flags =
                    p_expression_node->left->type.storage_class_specifier_flags;

            }
            else
            {
                type_destroy(&p_expression_node->type);
                p_expression_node->type = make_type_using_declarator(ctx, p_expression_node->type_name->declarator);
                p_expression_node->constant_value.type = TYPE_EMPTY;
            }
        }
        else if (is_first_of_unary_expression(ctx))
        {

            p_expression_node = unary_expression(ctx);
            if (p_expression_node == NULL)
            {
                throw;
            }
        }
        else
        {
            compiler_set_error_with_token(C_UNEXPECTED, ctx, ctx->current, "unexpected");
        }
    }
    catch
    {
    }
    if (p_expression_node && ctx->current)
    {
        p_expression_node->last_token = ctx->previous;
    }
    return p_expression_node;
}

struct expression* owner multiplicative_expression(struct parser_ctx* ctx)
{


    /*
     multiplicative-expression:
    cast-expression
    multiplicative-expression * cast-expression
    multiplicative-expression / cast-expression
    multiplicative-expression % cast-expression
    */
    struct expression* owner p_expression_node = NULL;
    try
    {
        p_expression_node = cast_expression(ctx);
        if (p_expression_node == NULL)
        {
            throw;
        }

        while (ctx->current != NULL &&
            (ctx->current->type == '*' ||
                ctx->current->type == '/' ||
                ctx->current->type == '%'))
        {
            struct expression* owner new_expression = calloc(1, sizeof * new_expression);
            if (new_expression == NULL)
            {
                expression_delete(p_expression_node);
                p_expression_node = NULL;
                throw;
            }
            static_set(*new_expression, "zero");
            new_expression->first_token = ctx->current;
            enum token_type op = ctx->current->type;
            parser_match(ctx);
            new_expression->left = p_expression_node;
            new_expression->right = cast_expression(ctx);

            if (new_expression->left == NULL ||
                new_expression->right == NULL)
            {
                expression_delete(new_expression);
                throw;
            }

            new_expression->last_token = new_expression->right->last_token;

            if (op == '*')
            {
                new_expression->expression_type = MULTIPLICATIVE_EXPRESSION_MULT;


                if (!type_is_arithmetic(&new_expression->left->type))
                {
                    compiler_set_error_with_token(C_LEFT_IS_NOT_ARITHMETIC, ctx, ctx->current, "left * is not arithmetic");

                }
                if (!type_is_arithmetic(&new_expression->right->type))
                {
                    compiler_set_error_with_token(C_RIGHT_IS_NOT_ARITHMETIC, ctx, ctx->current, "right * is not arithmetic");
                }

            }
            else if (op == '/')
            {

                new_expression->expression_type = MULTIPLICATIVE_EXPRESSION_DIV;

                new_expression->constant_value =
                    constant_value_op(&new_expression->left->constant_value, &new_expression->right->constant_value, '/');

                if (constant_value_is_valid(&new_expression->right->constant_value) &&
                    constant_value_to_ll(&new_expression->right->constant_value) == 0)
                {
                    compiler_set_error_with_token(C_DIVIZION_BY_ZERO, ctx, ctx->current, "division by zero");
                }

                if (!type_is_arithmetic(&new_expression->left->type))
                {
                    compiler_set_error_with_token(C_LEFT_IS_NOT_ARITHMETIC, ctx, ctx->current, "left / is not arithmetic");

                }
                if (!type_is_arithmetic(&new_expression->right->type))
                {
                    compiler_set_error_with_token(C_RIGHT_IS_NOT_ARITHMETIC, ctx, ctx->current, "right / is not arithmetic");
                }
            }
            else if (op == '%')
            {
                new_expression->expression_type = MULTIPLICATIVE_EXPRESSION_MOD;


                if (!type_is_integer(&new_expression->left->type))
                {
                    compiler_set_error_with_token(C_LEFT_IS_NOT_INTEGER, ctx, ctx->current, "left is not integer");

                }
                if (!type_is_integer(&new_expression->right->type))
                {
                    compiler_set_error_with_token(C_RIGHT_IS_NOT_INTEGER, ctx, ctx->current, "right is not integer");
                }

                if (constant_value_is_valid(&new_expression->right->constant_value) &&
                    constant_value_to_ll(&new_expression->right->constant_value) == 0)
                {
                    compiler_set_error_with_token(C_DIVIZION_BY_ZERO, ctx, ctx->current, "divizion by zero");
                }
            }

            new_expression->constant_value =
                constant_value_op(&new_expression->left->constant_value, &new_expression->right->constant_value, op);


            int code = type_common(&new_expression->left->type, &new_expression->right->type, &new_expression->type);
            if (code != 0)
            {
                expression_delete(new_expression);
                compiler_set_error_with_token(C_INVALID_TYPE, ctx, ctx->current, "invalid type multiplicative expression");
                throw;
            }

            p_expression_node = new_expression;
        }
    }
    catch
    {
    }
    return p_expression_node;
}

struct expression* owner additive_expression(struct parser_ctx* ctx)
{
    /*
     additive-expression:
    multiplicative-expression
    additive-expression + multiplicative-expression
    additive-expression - multiplicative-expression
    */

    struct expression* owner p_expression_node = NULL;
    struct expression* owner new_expression = NULL;

    try
    {
        p_expression_node = multiplicative_expression(ctx);
        if (p_expression_node == NULL) throw;


        while (ctx->current != NULL &&
            (ctx->current->type == '+' ||
                ctx->current->type == '-'))
        {
            struct token* operator_position = ctx->current;

            assert(new_expression == NULL);
            new_expression = calloc(1, sizeof * new_expression);
            new_expression->first_token = ctx->current;

            static_set(*new_expression, "zero");
            enum token_type op = ctx->current->type;
            parser_match(ctx);
            new_expression->left = p_expression_node;

            static int count = 0;
            count++;
            new_expression->right = multiplicative_expression(ctx);
            if (new_expression->right == NULL)
            {
                expression_delete(new_expression);
                new_expression = NULL;
                throw;
            }

            new_expression->last_token = new_expression->right->last_token;

            if (!type_is_scalar(&new_expression->left->type))
            {
                compiler_set_error_with_token(C_LEFT_IS_NOT_SCALAR, ctx, operator_position, "left operator is not scalar");
            }
            if (!type_is_scalar(&new_expression->right->type))
            {
                compiler_set_error_with_token(C_RIGHT_IS_NOT_SCALAR, ctx, operator_position, "right operator is not scalar");
            }


            const bool b_left_is_arithmetic = type_is_arithmetic(&new_expression->left->type);
            const bool b_right_is_arithmetic = type_is_arithmetic(&new_expression->right->type);

            const enum type_category left_category = type_get_category(&new_expression->left->type);
            const enum type_category right_category = type_get_category(&new_expression->right->type);

            if (op == '+')
            {
                new_expression->expression_type = ADDITIVE_EXPRESSION_PLUS;


                /*
                 For addition, either both operands shall have arithmetic type,
                 or one operand shall be a pointer to a complete object type and
                 the other shall have integer type. (Incrementing is equivalent to adding 1.)
                */
                if (b_left_is_arithmetic && b_right_is_arithmetic)
                {
                    int code = type_common(&new_expression->left->type, &new_expression->right->type, &new_expression->type);
                    if (code != 0)
                    {
                        compiler_set_error_with_token(C_UNEXPECTED, ctx, ctx->current, "internal error");
                        throw;
                    }
                }
                else
                {
                    if (left_category == TYPE_CATEGORY_POINTER || left_category == TYPE_CATEGORY_ARRAY  /* || left_category == TYPE_CATEGORY_FUNCTION*/)
                    {
                        if (type_is_integer(&new_expression->right->type))
                        {
                            if (left_category == TYPE_CATEGORY_ARRAY)
                            {
                                struct type t = get_array_item_type(&new_expression->left->type);
                                new_expression->type = type_add_pointer(&t);
                                type_destroy(&t);
                            }
                            else
                            {
                                new_expression->type = type_dup(&new_expression->left->type);
                            }
                        }
                        else
                        {
                            compiler_set_error_with_token(C_RIGHT_IS_NOT_INTEGER, ctx, ctx->current, "expected integer type on right");
                        }
                    }
                    else if (right_category == TYPE_CATEGORY_POINTER || right_category == TYPE_CATEGORY_ARRAY /*|| right_category == TYPE_CATEGORY_FUNCTION*/)
                    {
                        if (type_is_integer(&new_expression->left->type))
                        {
                            if (right_category == TYPE_CATEGORY_ARRAY)
                            {
                                new_expression->type = get_array_item_type(&new_expression->right->type);
                            }
                            else
                            {
                                new_expression->type = type_dup(&new_expression->right->type);
                            }
                        }
                        else
                        {
                            compiler_set_error_with_token(C_LEFT_IS_NOT_INTEGER, ctx, ctx->current, "expected integer type on left");
                        }
                    }
                    else
                    {
                        compiler_set_error_with_token(C_INVALID_TYPE, ctx, ctx->current, "invalid types additive expression");
                    }
                }
            }
            else if (op == '-')
            {
                new_expression->expression_type = ADDITIVE_EXPRESSION_MINUS;


                /*
                 For subtraction, one of the following shall hold:
                    — both operands have arithmetic type;
                    — both operands are pointers to qualified or unqualified versions of compatible complete object
                    types; or
                    — the left operand is a pointer to a complete object type and the right operand has integer type.
                    (Decrementing is equivalent to subtracting 1.)
                */
                if (b_left_is_arithmetic && b_right_is_arithmetic)
                {
                    //— both operands have arithmetic type;
                    int code = type_common(&new_expression->left->type, &new_expression->right->type, &new_expression->type);
                    if (code != 0)
                    {
                        compiler_set_error_with_token(C_INVALID_TYPE, ctx, ctx->current, "internal error type_common");
                        throw;
                    }
                }
                else
                {
                    if (left_category == TYPE_CATEGORY_POINTER || left_category == TYPE_CATEGORY_ARRAY)
                    {
                        if (right_category == TYPE_CATEGORY_POINTER || right_category == TYPE_CATEGORY_ARRAY)
                        {
                            //— both operands are pointers to qualified or unqualified versions of compatible complete object
                            // types;
                            struct type t1 = type_lvalue_conversion(&new_expression->left->type);
                            struct type t2 = type_lvalue_conversion(&new_expression->right->type);

                            if (!type_is_same(&t1, &t2, false))
                            {
                                compiler_set_error_with_token(C_INCOMPATIBLE_POINTER_TYPES, ctx, ctx->current, "incompatible pointer types");
                            }

                            new_expression->type = type_make_int();
                            type_destroy(&t1);
                            type_destroy(&t2);
                        }
                        else
                        {
                            if (type_is_integer(&new_expression->right->type))
                            {
                                //- the left operand is a pointer to a complete object typeand the right operand has integer type.
                                new_expression->type = type_dup(&new_expression->left->type);
                            }
                            else
                            {
                                compiler_set_error_with_token(C_RIGHT_IS_NOT_INTEGER, ctx, ctx->current, "right must be integer type");
                            }
                        }
                    }
                    else
                    {
                        compiler_set_error_with_token(C_INVALID_TYPE, ctx, ctx->current, "invalid types for operator -");
                    }
                }
            }

            new_expression->constant_value =
                constant_value_op(&new_expression->left->constant_value, &new_expression->right->constant_value, op);


            p_expression_node = new_expression;
            new_expression = NULL; /*MOVED*/
        }
    }
    catch
    {
        if (p_expression_node)
        {
            //expression_node_delete(p_expression_node);
        }
        if (new_expression)
        {
            //expression_node_delete(p_expression_node);
        }
    }



    return p_expression_node;
}

struct expression* owner shift_expression(struct parser_ctx* ctx)
{
    /*
     shift-expression:
       additive-expression
       shift-expression << additive-expression
       shift-expression >> additive-expression
    */
    struct expression* owner p_expression_node = NULL;
    try
    {
        p_expression_node = additive_expression(ctx);
        if (p_expression_node == NULL) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '>>' ||
                ctx->current->type == '<<'))
        {
            struct expression* owner new_expression = calloc(1, sizeof * new_expression);

            new_expression->first_token = ctx->current;
            static_set(*new_expression, "zero");

            enum token_type op = ctx->current->type;
            parser_match(ctx);
            new_expression->left = p_expression_node;
            new_expression->right = multiplicative_expression(ctx);
            if (new_expression->left == NULL || new_expression->right == NULL)
            {
                expression_delete(new_expression);
                throw;
            }

            new_expression->last_token = new_expression->right->last_token;

            if (op == '>>')
            {
                new_expression->expression_type = SHIFT_EXPRESSION_RIGHT;
            }
            else if (op == '<<')
            {
                new_expression->expression_type = SHIFT_EXPRESSION_LEFT;

            }

            new_expression->constant_value =
                constant_value_op(&new_expression->left->constant_value, &new_expression->right->constant_value, op);


            int code = type_common(&new_expression->left->type, &new_expression->right->type, &new_expression->type);
            if (code != 0)
            {
                expression_delete(new_expression);
                compiler_set_error_with_token(C_INVALID_TYPE, ctx, ctx->current, "invalid type shift expression");
                throw;
            }

            p_expression_node = new_expression;
        }
    }
    catch
    {
    }

    return p_expression_node;
}

struct expression* owner relational_expression(struct parser_ctx* ctx)
{
    /*
    relational-expression:
        shift-expression
        relational-expression < shift-expression
        relational-expression > shift-expression
        relational-expression <= shift-expression
        relational-expression >= shift-expression
    */

    struct expression* owner p_expression_node = NULL;
    struct expression* owner new_expression = NULL;
    try
    {
        p_expression_node = shift_expression(ctx);
        if (p_expression_node == NULL) throw;


        while (ctx->current != NULL &&
            (ctx->current->type == '>' ||
                ctx->current->type == '<' ||
                ctx->current->type == '>=' ||
                ctx->current->type == '<='))
        {
            assert(new_expression == NULL);
            new_expression = calloc(1, sizeof * new_expression);
            if (new_expression == NULL)
            {
                throw;
            }
            static_set(*new_expression, "zero");

            new_expression->first_token = ctx->current;
            enum token_type op = ctx->current->type;
            parser_match(ctx);
            new_expression->left = p_expression_node;

            new_expression->right = shift_expression(ctx);
            if (new_expression->right == NULL)
            {
                expression_delete(new_expression);
                new_expression = NULL;
                throw;
            }

            new_expression->last_token = new_expression->right->last_token;

            if (op == '>')
            {
                new_expression->expression_type = RELATIONAL_EXPRESSION_BIGGER_THAN;

            }
            else if (op == '<')
            {
                new_expression->expression_type = RELATIONAL_EXPRESSION_LESS_THAN;
            }
            else if (op == '>=')
            {
                new_expression->expression_type = RELATIONAL_EXPRESSION_BIGGER_OR_EQUAL_THAN;
            }
            else if (op == '<=')
            {
                new_expression->expression_type = RELATIONAL_EXPRESSION_LESS_OR_EQUAL_THAN;
            }

            new_expression->constant_value =
                constant_value_op(&new_expression->left->constant_value, &new_expression->right->constant_value, op);

            new_expression->type = type_make_int_bool_like();

            p_expression_node = new_expression;
            new_expression = NULL;/*MOVED*/
        }
    }
    catch
    {
    }

    return p_expression_node;
}

static void check_diferent_enuns(struct parser_ctx* ctx,
    const struct token* operator_token,
    struct expression* left,
    struct expression* right)
{
    if (left->type.type_specifier_flags & TYPE_SPECIFIER_ENUM &&
        right->type.type_specifier_flags & TYPE_SPECIFIER_ENUM)
    {
        if (left->type.enum_specifier->complete_enum_specifier !=
            right->type.enum_specifier->complete_enum_specifier)
        {
            const char* lefttag = "";
            if (left->type.enum_specifier->tag_token)
                lefttag = left->type.enum_specifier->tag_token->lexeme;

            const char* righttag = "";
            if (right->type.enum_specifier->tag_token)
                righttag = right->type.enum_specifier->tag_token->lexeme;

            compiler_set_warning_with_token(W_ENUN_CONVERSION,
                ctx,
                operator_token,
                "implicit conversion from 'enum %s' to 'enum %s'",
                lefttag,
                righttag);
        }
    }

}
void expression_evaluate_equal_not_equal(const struct expression* left,
    const struct expression* right,
    struct expression* result,
    int op,
    bool disabled)
{
    assert(op == '==' || op == '!=');
    result->constant_value =
        constant_value_op(&left->constant_value, &right->constant_value, op);


    if (left->constant_value.type == TYPE_EMPTY ||
        right->constant_value.type == TYPE_EMPTY)
    {
        if (op == '==')
        {
            result->constant_value =
                make_constant_value_ll(type_is_same(&left->type, &right->type, true), disabled);
        }
        else
        {
            result->constant_value =
                make_constant_value_ll(!type_is_same(&left->type, &right->type, true), disabled);
        }
    }
}

struct expression* owner equality_expression(struct parser_ctx* ctx)
{
    /*
      equality-expression:
       relational-expression
       equality-expression == relational-expression
       equality-expression != relational-expression
    */
    /*
    * Equality operators
    One of the following shall hold:
    — both operands have arithmetic type;
    — both operands are pointers to qualified or unqualified versions of compatible types;
    — one operand is a pointer to an object type and the other is a pointer to a qualified or unqualified
    version of void; or
    — one operand is a pointer and the other is a null pointer constant.
    */
    struct expression* owner p_expression_node = NULL;
    struct expression* owner new_expression = NULL;

    try
    {
        p_expression_node = relational_expression(ctx);
        if (p_expression_node == NULL) throw;


        while (ctx->current != NULL &&
            (ctx->current->type == '==' ||
                ctx->current->type == '!='))
        {
            assert(new_expression == NULL);
            new_expression = calloc(1, sizeof * new_expression);
            if (new_expression == NULL) throw;

            new_expression->first_token = ctx->current;
            static_set(*new_expression, "zero");
            struct  token* operator_token = ctx->current;
            parser_match(ctx);
            new_expression->left = p_expression_node;
            new_expression->right = relational_expression(ctx);
            if (new_expression->right == NULL) throw;

            new_expression->last_token = new_expression->right->last_token;
            check_diferent_enuns(ctx, operator_token, new_expression->left, new_expression->right);

            new_expression->first_token = operator_token;

            if (operator_token->type == '==')
            {
                new_expression->expression_type = EQUALITY_EXPRESSION_EQUAL;
                expression_evaluate_equal_not_equal(new_expression->left,
                    new_expression->right,
                    new_expression,
                    '==',
                    ctx->evaluation_is_disabled);
            }
            else if (operator_token->type == '!=')
            {
                new_expression->expression_type = EQUALITY_EXPRESSION_NOT_EQUAL;
                expression_evaluate_equal_not_equal(new_expression->left,
                    new_expression->right,
                    new_expression,
                    '!=',
                    ctx->evaluation_is_disabled);
            }
            else
            {
                assert(false);
            }

            type_destroy(&new_expression->type);
            new_expression->type = type_make_int_bool_like();
            p_expression_node = new_expression;
            new_expression = NULL; /*MOVED*/
        }
    }
    catch
    {
    }

    return p_expression_node;
}

struct expression* owner and_expression(struct parser_ctx* ctx)
{
    /*
     AND-expression:
      equality-expression
      AND-expression & equality-expression
    */
    struct expression* owner p_expression_node = NULL;
    struct expression* owner new_expression = NULL;

    try
    {
        p_expression_node = equality_expression(ctx);
        if (p_expression_node == NULL)
            throw;

        while (ctx->current != NULL && ctx->current->type == '&')
        {
            parser_match(ctx);

            assert(new_expression == NULL);
            new_expression = calloc(1, sizeof * new_expression);
            if (new_expression == NULL) throw;
            static_set(*new_expression, "zero");

            new_expression->first_token = ctx->current;
            new_expression->expression_type = AND_EXPRESSION;
            new_expression->left = p_expression_node;
            new_expression->right = equality_expression(ctx);
            if (new_expression->right == NULL) throw;

            new_expression->last_token = new_expression->right->last_token;
            new_expression->constant_value =
                constant_value_op(&new_expression->left->constant_value, &new_expression->right->constant_value, '&');


            int code = type_common(&new_expression->left->type, &new_expression->right->type, &new_expression->type);
            if (code != 0)
            {
                compiler_set_error_with_token(C_INVALID_TYPE, ctx, ctx->current, "invalid types and expression");
                throw;
            }

            p_expression_node = new_expression;
            new_expression = NULL; /*MOVED*/
        }
    }
    catch
    {
    }

    return p_expression_node;
}

struct expression* owner exclusive_or_expression(struct parser_ctx* ctx)
{
    /*
     exclusive-OR-expression:
      AND-expression
      exclusive-OR-expression ^ AND-expression
    */
    struct expression* owner p_expression_node = NULL;
    struct expression* owner new_expression = NULL;

    try
    {
        p_expression_node = and_expression(ctx);
        if (p_expression_node == NULL) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '^'))
        {
            parser_match(ctx);

            assert(new_expression == NULL);
            new_expression = calloc(1, sizeof * new_expression);
            if (new_expression == NULL) throw;

            static_set(*new_expression, "zero");
            new_expression->first_token = ctx->current;
            new_expression->expression_type = EXCLUSIVE_OR_EXPRESSION;
            new_expression->left = p_expression_node;
            new_expression->right = and_expression(ctx);
            if (new_expression->right == NULL) throw;

            new_expression->last_token = new_expression->right->last_token;
            new_expression->constant_value =
                constant_value_op(&new_expression->left->constant_value, &new_expression->right->constant_value, '^');


            int code = type_common(&new_expression->left->type, &new_expression->right->type, &new_expression->type);
            if (code != 0)
            {
                compiler_set_error_with_token(C_INVALID_TYPE, ctx, ctx->current, "invalid types or expression");
                throw;
            }

            p_expression_node = new_expression;
            new_expression = NULL;
        }
    }
    catch
    {
    }

    return p_expression_node;
}

struct expression* owner inclusive_or_expression(struct parser_ctx* ctx)
{

    /*
    inclusive-OR-expression:
    exclusive-OR-expression
    inclusive-OR-expression | exclusive-OR-expression
    */
    struct expression* owner p_expression_node = NULL;
    try
    {
        p_expression_node = exclusive_or_expression(ctx);
        if (p_expression_node == NULL) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '|'))
        {
            parser_match(ctx);
            struct expression* owner new_expression = calloc(1, sizeof * new_expression);
            if (new_expression == NULL) throw;

            static_set(*new_expression, "zero");
            new_expression->first_token = ctx->current;
            new_expression->expression_type = INCLUSIVE_OR_EXPRESSION;
            new_expression->left = p_expression_node;
            new_expression->right = exclusive_or_expression(ctx);
            if (new_expression->right == NULL)
            {
                expression_delete(new_expression);
                throw;
            }
            new_expression->last_token = new_expression->right->last_token;
            new_expression->constant_value =
                constant_value_op(&new_expression->left->constant_value, &new_expression->right->constant_value, '|');



            int code = type_common(&new_expression->left->type, &new_expression->right->type, &new_expression->type);
            if (code != 0)
            {
                expression_delete(new_expression);
                compiler_set_error_with_token(C_INVALID_TYPE, ctx, ctx->current, "invalid types inclusive or expression");
                throw;
            }

            p_expression_node = new_expression;
        }
    }
    catch
    {
    }

    return p_expression_node;
}

struct expression* owner logical_and_expression(struct parser_ctx* ctx)
{
    /*
    logical-AND-expression:
     inclusive-OR-expression
     logical-AND-expression && inclusive-OR-expression
    */
    struct expression* owner p_expression_node = NULL;
    try
    {
        p_expression_node = inclusive_or_expression(ctx);
        if (p_expression_node == NULL) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '&&'))
        {
            parser_match(ctx);
            struct expression* owner new_expression = calloc(1, sizeof * new_expression);
            if (new_expression == NULL) throw;

            static_set(*new_expression, "zero");
            new_expression->first_token = ctx->current;
            new_expression->expression_type = INCLUSIVE_AND_EXPRESSION;
            new_expression->left = p_expression_node;
            new_expression->right = inclusive_or_expression(ctx);
            if (new_expression->right == NULL)
            {
                expression_delete(new_expression);
                throw;
            }
            new_expression->last_token = new_expression->right->last_token;
            new_expression->constant_value =
                constant_value_op(&new_expression->left->constant_value, &new_expression->right->constant_value, '&&');


            int code = type_common(&new_expression->left->type, &new_expression->right->type, &new_expression->type);
            if (code != 0)
            {
                expression_delete(new_expression);
                type_print(&new_expression->left->type);
                type_print(&new_expression->right->type);
                compiler_set_error_with_token(C_INVALID_TYPE, ctx, ctx->current, "invalid types logicl and expression");
                throw;
            }
            p_expression_node = new_expression;
        }
    }
    catch
    {
    }

    return p_expression_node;
}

struct expression* owner logical_or_expression(struct parser_ctx* ctx)
{
    /*
      logical-OR-expression:
       logical-AND-expression
       logical-OR-expression || logical-AND-expression
    */
    struct expression* owner p_expression_node = NULL;
    try
    {
        p_expression_node = logical_and_expression(ctx);
        if (p_expression_node == NULL) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '||'))
        {
            parser_match(ctx);
            struct expression* owner new_expression = calloc(1, sizeof * new_expression);
            if (new_expression == NULL) throw;

            static_set(*new_expression, "zero");
            new_expression->first_token = ctx->current;
            new_expression->expression_type = LOGICAL_OR_EXPRESSION;
            new_expression->left = p_expression_node;
            new_expression->right = logical_and_expression(ctx);
            if (new_expression->right == NULL)
            {
                expression_delete(new_expression);
                throw;
            }

            new_expression->last_token = new_expression->right->last_token;
            new_expression->constant_value =
                constant_value_op(&new_expression->left->constant_value, &new_expression->right->constant_value, '||');


            if (!type_is_scalar(&new_expression->left->type))
            {
                expression_delete(new_expression);
                compiler_set_error_with_token(C_LEFT_IS_NOT_SCALAR, ctx, ctx->current, "left type is not scalar for or expression");
                throw;
            }

            if (!type_is_scalar(&new_expression->right->type))
            {
                expression_delete(new_expression);
                compiler_set_error_with_token(C_RIGHT_IS_NOT_SCALAR, ctx, ctx->current, "right type is not scalar for or expression");
                throw;
            }

            new_expression->type = type_make_int_bool_like();

            p_expression_node = new_expression;
        }
    }
    catch
    {
    }

    return p_expression_node;
}



struct expression* owner assignment_expression(struct parser_ctx* ctx)
{
    /*
    assignment-expression:
       conditional-expression
       unary-expression assignment-operator assignment-expression
       */
       /*
          assignment-operator: one of
          = *= /= %= += -= <<= >>= &= ^= |=
       */
       //aqui eh duvidoso mas conditional faz a unary tb.
       //a diferenca q nao eh qualquer expressao
       //que pode ser de atribuicao
    struct expression* owner p_expression_node = NULL;
    try
    {
        p_expression_node = conditional_expression(ctx);
        if (p_expression_node == NULL) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '=' ||
                ctx->current->type == '*=' ||
                ctx->current->type == '/=' ||
                ctx->current->type == '%=' ||
                ctx->current->type == '+=' ||
                ctx->current->type == '-=' ||
                ctx->current->type == '<<=' ||
                ctx->current->type == '>>=' ||
                ctx->current->type == '&=' ||
                ctx->current->type == '^=' ||
                ctx->current->type == '|='))
        {
            const struct token* const op_token = ctx->current;
            parser_match(ctx);


            struct expression* owner new_expression = calloc(1, sizeof * new_expression);
            if (new_expression == NULL) throw;

            static_set(*new_expression, "zero");
            new_expression->first_token = ctx->current;
            new_expression->expression_type = ASSIGNMENT_EXPRESSION;
            new_expression->left = p_expression_node;

            enum type_category category =
                type_get_category(&new_expression->left->type);

            if (category == TYPE_CATEGORY_FUNCTION)
            {
                compiler_set_error_with_token(C_ASSIGNMENT_OF_FUNCTION, ctx, ctx->current, "assignment of function");
            }
            else if (category == TYPE_CATEGORY_ARRAY)
            {
                compiler_set_error_with_token(C_ASSIGNMENT_TO_EXPRESSION_WITH_ARRAY_TYPE, ctx, ctx->current, "assignment to expression with array type");
            }
            else
            {
                if (type_is_const(&new_expression->left->type))
                {
                    compiler_set_error_with_token(C_ASSIGNMENT_OF_READ_ONLY_OBJECT, ctx, ctx->current, "assignment of read-only object");
                }
            }

            if (!expression_is_lvalue(new_expression->left))
            {
                compiler_set_error_with_token(C_OPERATOR_NEEDS_LVALUE,
                    ctx,
                    op_token,
                    "lvalue required as left operand of assignment");
            }

            new_expression->right = assignment_expression(ctx);
            if (new_expression->right == NULL)
            {
                expression_delete(new_expression);
                throw;
            }


            if (op_token->type == '=')
            {
                check_assigment(ctx, &new_expression->left->type, new_expression->right, false);
            }


            new_expression->last_token = new_expression->right->last_token;

            new_expression->type = type_dup(&new_expression->right->type);
            

            new_expression->type.storage_class_specifier_flags &= ~STORAGE_SPECIFIER_FUNCTION_RETURN;
            new_expression->type.storage_class_specifier_flags &= ~STORAGE_SPECIFIER_FUNCTION_RETURN_NODISCARD;


            check_diferent_enuns(ctx, op_token, new_expression->left, new_expression->right);

            p_expression_node = new_expression;
        }
    }
    catch
    {
    }
    return p_expression_node;
}

void argument_expression_list_destroy(struct argument_expression_list* obj_owner p)
{
    struct argument_expression* owner item = p->head;
    while (item)
    {
        struct argument_expression* owner next = item->next;
        item->next = NULL;
        argument_expression_delete(item);
        item = next;
    }
}

void expression_delete(struct expression* owner p)
{
    if (p)
    {
        expression_delete(p->condition_expr);
        compound_statement_delete(p->compound_statement);
        type_name_delete(p->type_name);
        type_name_delete(p->type_name2);
        expression_delete(p->right);
        expression_delete(p->left);
        braced_initializer_delete(p->braced_initializer);
        generic_selection_delete(p->generic_selection);
        type_destroy(&p->type);
        argument_expression_list_destroy(&p->argument_expression_list);
        free(p);
    }
}
struct expression* owner expression(struct parser_ctx* ctx)
{
    /*expression:
      assignment-expression
      expression, assignment-expression
    */
    struct expression* owner p_expression_node = NULL;
    try
    {
        p_expression_node = assignment_expression(ctx);
        if (p_expression_node == NULL) throw;

        if (ctx->current->type == ',')
        {
            while (ctx->current->type == ',')
            {
                parser_match(ctx);
                struct expression* owner p_expression_node_new = calloc(1, sizeof * p_expression_node_new);
                if (p_expression_node_new == NULL) throw;

                static_set(*p_expression_node_new, "zero");
                p_expression_node_new->first_token = ctx->current;
                p_expression_node_new->expression_type = ASSIGNMENT_EXPRESSION;
                p_expression_node_new->left = p_expression_node;

                p_expression_node_new->right = expression(ctx);
                if (p_expression_node_new->right == NULL)
                {
                    expression_delete(p_expression_node_new);
                    throw;
                }
                p_expression_node->last_token = p_expression_node_new->right->last_token;

                p_expression_node = p_expression_node_new;
            }

            if (p_expression_node->right == NULL)
            {
                throw;
            }

            /*same type of the last expression*/
            type_destroy(&p_expression_node->type);
            p_expression_node->type = type_dup(&p_expression_node->right->type);
        }
    }
    catch
    {
    }
    return p_expression_node;
}

bool is_first_of_conditional_expression(struct parser_ctx* ctx)
{
    return is_first_of_unary_expression(ctx) ||
        is_first_of_primary_expression(ctx);
}

bool expression_is_null_pointer_constant(const struct expression* expression)
{
    if (expression)
    {
        if (type_is_nullptr_t(&expression->type) ||
            (constant_value_is_valid(&expression->constant_value) &&
                constant_value_to_ull(&expression->constant_value) == 0))
        {
            return true;
        }
    }
    return false;
}

struct expression* owner conditional_expression(struct parser_ctx* ctx)
{
    /*
      conditional-expression:
      logical-OR-expression
      logical-OR-expression ? expression : conditional-expression
    */
    struct expression* owner p_expression_node = NULL;
    struct type left_type = {0};
    struct type right_type = {0};
    try
    {
        p_expression_node = logical_or_expression(ctx);
        if (p_expression_node == NULL) throw;


        if (ctx->current && ctx->current->type == '?')
        {
            struct expression* owner p_conditional_expression = calloc(1, sizeof * p_conditional_expression);

            static_set(*p_conditional_expression, "zero");
            p_conditional_expression->first_token = ctx->current;
            p_conditional_expression->expression_type = CONDITIONAL_EXPRESSION;
            p_conditional_expression->condition_expr = p_expression_node;


            parser_match(ctx); //?

            p_conditional_expression->left = expression(ctx);
            if (p_conditional_expression->left == NULL)
            {
                expression_delete(p_conditional_expression);
                throw;
            }

            parser_match(ctx); //:
            p_conditional_expression->right = conditional_expression(ctx);
            if (p_conditional_expression->right == NULL)
            {
                expression_delete(p_conditional_expression);
                throw;
            }



            if (constant_value_is_valid(&p_conditional_expression->condition_expr->constant_value))
            {
                if (constant_value_to_bool(&p_conditional_expression->condition_expr->constant_value))
                {
                    /*this is an extensions.. in constant expression we can mix types!*/
                    p_conditional_expression->type = type_dup(&p_conditional_expression->left->type);
                    p_conditional_expression->constant_value = p_conditional_expression->left->constant_value;

                }
                else
                {
                    /*this is an extensions.. in constant expression we can mix types!*/
                    p_conditional_expression->type = type_dup(&p_conditional_expression->right->type);
                    p_conditional_expression->constant_value = p_conditional_expression->right->constant_value;

                }
            }

            if (expression_is_subjected_to_lvalue_conversion(p_conditional_expression->left))
            {
                left_type = type_lvalue_conversion(&p_conditional_expression->left->type);
            }
            else
            {
                left_type = type_dup(&p_conditional_expression->left->type);
            }

            if (expression_is_subjected_to_lvalue_conversion(p_conditional_expression->right))
            {
                right_type = type_lvalue_conversion(&p_conditional_expression->right->type);
            }
            else
            {
                right_type = type_dup(&p_conditional_expression->right->type);
            }

            /*The first operand shall have scalar type*/
            if (!type_is_scalar(&p_conditional_expression->condition_expr->type))
            {
                compiler_set_error_with_token(C_CONDITION_MUST_HAVE_SCALAR_TYPE, ctx, ctx->current, "condition must have scalar type");
            }
            else if (type_is_arithmetic(&left_type) &&
                type_is_arithmetic(&right_type))
            {
                /*
            *  both operands have arithmetic type;
            */
                type_common(&left_type, &right_type, &p_conditional_expression->type);

            }
            else if (type_is_struct_or_union(&left_type) && type_is_struct_or_union(&right_type))
            {
                /*
        *  both operands have compatible structure or union type;
        */
                if (!type_is_same(&left_type, &right_type, true))
                {
                    compiler_set_error_with_token(C_INCOMPATIBLE_TYPES, ctx, p_conditional_expression->condition_expr->first_token, "incompatible types");
                }
                type_swap(&p_conditional_expression->type, &right_type);

            }
            else if (type_is_void(&left_type) && type_is_void(&right_type))
            {
                /*
         *  both operands have void type;
        */
                type_swap(&p_conditional_expression->type, &right_type);

            }
            else if (type_is_nullptr_t(&left_type) && type_is_nullptr_t(&right_type))
            {
                /* both operands have nullptr_t type;*/
                type_swap(&p_conditional_expression->type, &right_type);

            }
            else if (type_is_pointer(&left_type))
            {
                /*
                — one operand is a pointer and the other is a null pointer constant or has type nullptr_t; or
                    — one operand is a pointer to an object type and the other is a pointer to a qualified or unqualified
                    version of void
            */
                if (expression_is_null_pointer_constant(p_conditional_expression->right) ||
                    type_is_nullptr_t(&right_type) ||
                    type_is_void_ptr(&right_type))
                {
                    type_swap(&p_conditional_expression->type, &left_type);

                }
                else if (type_is_pointer(&right_type))
                {
                    if (type_is_nullptr_t(&left_type) || type_is_void_ptr(&left_type))
                    {
                        type_swap(&p_conditional_expression->type, &left_type);

                    }
                    else if (!type_is_same(&left_type, &right_type, false))
                    {
                        //type_print(&left_type);
                        //type_print(&right_type);
                        compiler_set_error_with_token(C_INCOMPATIBLE_TYPES, ctx, ctx->current, "incompatible types");
                    }
                    else
                    {
                        type_swap(&p_conditional_expression->type, &right_type);
                    }
                }
                else
                {
                    compiler_set_error_with_token(C_INCOMPATIBLE_TYPES, ctx, p_conditional_expression->condition_expr->first_token, "incompatible types");
                }

            }
            else if (type_is_pointer(&right_type))
            {
                if (expression_is_null_pointer_constant(p_conditional_expression->left) ||
                    type_is_nullptr_t(&left_type) ||
                    type_is_void_ptr(&left_type))
                {
                    type_swap(&p_conditional_expression->type, &right_type);

                }
                else if (type_is_pointer(&left_type))
                {
                    if (type_is_nullptr_t(&left_type) || type_is_void_ptr(&left_type))
                    {
                        type_swap(&p_conditional_expression->type, &right_type);

                    }
                    else if (!type_is_same(&left_type, &right_type, false))
                    {
                        compiler_set_error_with_token(C_INCOMPATIBLE_TYPES, ctx, p_conditional_expression->condition_expr->first_token, "incompatible types");

                    }
                    else
                    {
                        type_swap(&p_conditional_expression->type, &right_type);
                    }
                }
                else
                {
                    compiler_set_error_with_token(C_INCOMPATIBLE_TYPES, ctx, p_conditional_expression->condition_expr->first_token, "incompatible types");
                }
            }
            else
            {
                compiler_set_error_with_token(C_INCOMPATIBLE_TYPES, ctx, p_conditional_expression->condition_expr->first_token, "incompatible types??");
                assert(false);
            }
            p_expression_node = p_conditional_expression;
        }
    }
    catch
    {
    }

    type_destroy(&left_type);
    type_destroy(&right_type);

    return p_expression_node;
}

struct expression* owner constant_expression(struct parser_ctx* ctx, bool show_error_if_not_constant)
{
    struct expression* owner p_expression = conditional_expression(ctx);


    if (show_error_if_not_constant &&
        p_expression &&
        !constant_value_is_valid(&p_expression->constant_value))
    {
        compiler_set_error_with_token(C_EXPECTED_CONSTANT_EXPRESSION, ctx, ctx->current, "expected constant expression");
    }

    return p_expression;
}

bool expression_is_lvalue(const struct expression* expr)
{
    //https://en.cppreference.com/w/c/language/value_category

    switch (expr->expression_type)
    {
     case PRIMARY_EXPRESSION_DECLARATOR:
     case PRIMARY_EXPRESSION__FUNC__:
     case PRIMARY_EXPRESSION_STRING_LITERAL:
     case POSTFIX_ARRAY:
     case POSTFIX_ARROW:
     case POSTFIX_EXPRESSION_COMPOUND_LITERAL:
     case UNARY_EXPRESSION_CONTENT:
        return true;
     default:
         break;
    }

    if (expr->expression_type == PRIMARY_EXPRESSION_PARENTESIS)
    {
        return expression_is_lvalue(expr->right);
    }
    else if (expr->expression_type == POSTFIX_DOT)
    {
      return expression_is_lvalue(expr->left);
    }

    return false;
}

bool expression_is_zero(struct expression* p_expression)
{
    bool is_zero = false;

    if (type_is_nullptr_t(&p_expression->type) ||
        (constant_value_is_valid(&p_expression->constant_value) &&
            constant_value_to_ull(&p_expression->constant_value) == 0))
    {
        is_zero = true;
    }
    return is_zero;
}

/*
* Returns true if the type of expression is subjected to type_lvalue_conversion
*/
bool expression_is_subjected_to_lvalue_conversion(struct expression* expression)
{

    switch (expression->expression_type)
    {
        case UNARY_EXPRESSION_ADDRESSOF:
        case UNARY_EXPRESSION_INCREMENT:
        case UNARY_EXPRESSION_DECREMENT:
        case POSTFIX_INCREMENT:
        case POSTFIX_DECREMENT:
            return false;
    }

    if (expression->type.storage_class_specifier_flags & STORAGE_SPECIFIER_PARAMETER)
        return true;

    return true;
}


/*
  For performance reasons we will separate expression from preprocessor from compiler.
*/

#ifdef _WIN32
#endif

#if defined _MSC_VER && !defined __POCC__
#endif


/*contexto expressoes preprocessador*/
struct pre_expression_ctx
{
    /*todas expressões do preprocessador sao calculadas com long long*/
    long long value;
};


static void pre_postfix_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_cast_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_multiplicative_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_unary_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_additive_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_shift_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_relational_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_equality_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_and_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_exclusive_or_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_inclusive_or_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_logical_and_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_logical_or_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_conditional_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);
static void pre_conditional_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx);



/*
* preprocessor uses long long
*/
static int ppnumber_to_longlong(struct token* token, long long* result)
{

    /*copia removendo os separadores*/
    //um dos maiores buffer necessarios seria 128 bits binario...
    //0xb1'1'1.... 
    int c = 0;
    char buffer[128 * 2 + 4] = { 0 };
    const char* s = token->lexeme;
    while (*s)
    {
        if (*s != '\'')
        {
            buffer[c] = *s;
            c++;
        }
        s++;
    }

    if (buffer[0] == '0' &&
        buffer[1] == 'x')
    {
        //hex
        *result = strtoll(buffer + 2, 0, 16);
    }
    else if (buffer[0] == '0' &&
        buffer[1] == 'b')
    {
        //binario
        *result = strtoll(buffer + 2, 0, 2);
    }
    else if (buffer[0] == '0')
    {
        //octal
        *result = strtoll(buffer, 0, 8);
    }
    else
    {
        //decimal
        *result = strtoll(buffer, 0, 10);
    }

    
    return 0;
}

/*
  ctx->current and pre_match are used only in preprocessor constant expressions
  (the preprocessor itself uses concept of removing from one list and adding
  into another so the head of the input list is the current.
  We could use the same concept here removing current.
*/
static struct token* pre_match(struct preprocessor_ctx* ctx)
{
    ctx->current = ctx->current->next;

    while (ctx->current && token_is_blank(ctx->current))
    {
        ctx->current = ctx->current->next;
    }

    return ctx->current;
}

static void pre_primary_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
     primary-expression:
      identifier
      constant
      string-literal
      ( expression )
      generic-selection
    */
    try
    {
        if (ctx->current->type == TK_CHAR_CONSTANT)
        {
            const char* p = ctx->current->lexeme + 1;
            ectx->value = 0;
            int count = 0;
            while (*p != '\'')
            {
                ectx->value = ectx->value * 256 + *p;
                p++;
                count++;
                if (count > 4)
                {
                    preprocessor_set_warning_with_token(W_NONE, ctx, ctx->current, "character constant too long for its type");
                }
            }

            pre_match(ctx);
        }
        else if (ctx->current->type == TK_PPNUMBER)
        {
            ppnumber_to_longlong(ctx->current, &ectx->value);
            pre_match(ctx);
        }
        else if (ctx->current->type == '(')
        {
            pre_match(ctx);
            pre_expression(ctx,  ectx);
            if (ctx->n_errors > 0) throw;
            if (ctx->current && ctx->current->type != ')')
            {
                preprocessor_set_error_with_token(C_UNEXPECTED, ctx, ctx->current, "expected )");
                throw;
            }
            pre_match(ctx);
        }
        else
        {
            preprocessor_set_error_with_token(C_TOKEN_NOT_VALID_IN_PREPROCESSOR_EXPRESSIONS,
                ctx, 
                ctx->current, 
                "token '%s' is not valid in preprocessor expressions", 
                ctx->current->lexeme);
            throw;

        }
    }
    catch
    {
    }
}




static void pre_postfix_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
      postfix-expression:
        primary-expression
        postfix-expression [ expression ]
        postfix-expression ( argument-expression-list_opt)
        postfix-expression . identifier
        postfix-expression -> identifier
        postfix-expression ++
        postfix-expression --
        ( type-name ) { initializer-ctx }
        ( type-name ) { initializer-ctx , }

        //My extension : if type-name is function then follow is compound-statement
        ( type-name ) compound-statement

        */
    try
    {
        pre_primary_expression(ctx,  ectx);
        if (ctx->n_errors > 0) throw;
    }
    catch
    {
    }
}


static void pre_unary_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
    unary-expression:
      postfix-expression
      ++ unary-expression
      -- unary-expression

      one of (& * + - ~ !) cast-expression

      sizeof unary-expression
      sizeof ( type-name )
      _Alignof ( type-name )
      */
    try
    {
        if (ctx->current->type == '++' || ctx->current->type == '--')
        {
            preprocessor_set_error_with_token(C_TOKEN_NOT_VALID_IN_PREPROCESSOR_EXPRESSIONS,
                ctx, 
                ctx->current, 
                "token '%s' is not valid in preprocessor expressions",
                ctx->current->lexeme);
            throw;
        }
        else if (ctx->current != NULL &&
            (ctx->current->type == '&'
                || ctx->current->type == '*'
                || ctx->current->type == '+'
                || ctx->current->type == '-'
                || ctx->current->type == '~'
                || ctx->current->type == '!'))
        {
            enum token_type op = ctx->current->type;
            pre_match(ctx);
            pre_cast_expression(ctx,  ectx);
            if (ctx->n_errors > 0) throw;

            if (op == '!')
                ectx->value = !ectx->value;
            else if (op == '~')
                ectx->value = ~ectx->value;
            else if (op == '-')
                ectx->value = -ectx->value;
            else if (op == '+')
                ectx->value = +ectx->value;
            else if (op == '*')
            {
                preprocessor_set_error_with_token(C_TOKEN_NOT_VALID_IN_PREPROCESSOR_EXPRESSIONS, ctx, ctx->current, "token '%s' is not valid in preprocessor expressions", ctx->current->lexeme);
            }
            else if (op == '&')
            {
                preprocessor_set_error_with_token(C_TOKEN_NOT_VALID_IN_PREPROCESSOR_EXPRESSIONS, ctx, ctx->current, "token '%s' is not valid in preprocessor expressions", ctx->current->lexeme);
            }
            else
            {
                preprocessor_set_error_with_token(C_TOKEN_NOT_VALID_IN_PREPROCESSOR_EXPRESSIONS, ctx, ctx->current, "token '%s' is not valid in preprocessor expressions", ctx->current->lexeme);
            }
        }
        else 
        {
            pre_postfix_expression(ctx,  ectx);
        }
    }
    catch
    {
    }
}

static void pre_cast_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
     cast-expression:
      unary-expression
      ( type-name ) cast-expression
    */
    pre_unary_expression(ctx,  ectx);    
}

static void pre_multiplicative_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
     multiplicative-expression:
    cast-expression
    multiplicative-expression * cast-expression
    multiplicative-expression / cast-expression
    multiplicative-expression % cast-expression
    */
    try
    {
        pre_cast_expression(ctx,  ectx);
        if (ctx->n_errors > 0) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '*' ||
                ctx->current->type == '/' ||
                ctx->current->type == '%'))
        {
            enum token_type op = ctx->current->type;
            pre_match(ctx);
            long long left_value = ectx->value;
            pre_cast_expression(ctx,  ectx);
            if (ctx->n_errors > 0) throw;

            if (op == '*')
            {
                ectx->value = (left_value * ectx->value);
            }
            else if (op == '/')
            {
                ectx->value = (left_value / ectx->value);
            }
            else if (op == '%')
            {
                ectx->value = (left_value % ectx->value);
            }
        }
    }
    catch
    {
    }
}

static void pre_additive_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
     additive-expression:
       multiplicative-expression
       additive-expression + multiplicative-expression
       additive-expression - multiplicative-expression
    */
    try
    {
        pre_multiplicative_expression(ctx,  ectx);
        if (ctx->n_errors > 0) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '+' ||
                ctx->current->type == '-'))
        {
            enum token_type op = ctx->current->type;
            pre_match(ctx);
            if (ctx->current == NULL)
            {
                preprocessor_set_error_with_token(C_UNEXPECTED_END_OF_FILE, ctx, ctx->current, "unexpected end of file");
                throw;
            }
            long long left_value = ectx->value;
            pre_multiplicative_expression(ctx,  ectx);
            if (ctx->n_errors > 0) throw;

            if (op == '+')
            {
                ectx->value = left_value + ectx->value;
            }
            else if (op == '-')
            {
                ectx->value = left_value - ectx->value;
            }
        }
    }
    catch
    {
    }
}

static void pre_shift_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
     shift-expression:
       additive-expression
       shift-expression << additive-expression
       shift-expression >> additive-expression
    */
    try
    {
        pre_additive_expression(ctx,  ectx);
        if (ctx->n_errors > 0) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '>>' ||
                ctx->current->type == '<<'))
        {
            enum token_type op = ctx->current->type;
            pre_match(ctx);
            long long left_value = ectx->value;
            pre_multiplicative_expression(ctx,  ectx);
            if (ctx->n_errors > 0) throw;

            if (op == '>>')
            {
                ectx->value = left_value >> ectx->value;
            }
            else if (op == '<<')
            {
                ectx->value = left_value << ectx->value;
            }
        }
    }
    catch
    {
    }
}

static void pre_relational_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
    relational-expression:
      shift-expression
      relational-expression < shift-expression
      relational-expression > shift-expression
      relational-expression <= shift-expression
      relational-expression >= shift-expression
    */
    try
    {
        pre_shift_expression(ctx,  ectx);
        if (ctx->n_errors > 0) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '>' ||
                ctx->current->type == '<' ||
                ctx->current->type == '>=' ||
                ctx->current->type == '<='))
        {
            enum token_type op = ctx->current->type;
            pre_match(ctx);
            long long left_value = ectx->value;
            pre_shift_expression(ctx,  ectx);
            if (ctx->n_errors > 0) throw;

            if (op == '>')
            {
                ectx->value = left_value > ectx->value;
            }
            else if (op == '<')
            {
                ectx->value = left_value < ectx->value;
            }
            else if (op == '>=')
            {
                ectx->value = left_value >= ectx->value;
            }
            else if (op == '<=')
            {
                ectx->value = left_value <= ectx->value;
            }
        }
    }
    catch
    {
    }
}

static void pre_equality_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
      equality-expression:
        relational-expression
        equality-expression == relational-expression
        equality-expression != relational-expression
    */

    /*
    * Equality operators
    One of the following shall hold:
    — both operands have arithmetic type;
    — both operands are pointers to qualified or unqualified versions of compatible types;
    — one operand is a pointer to an object type and the other is a pointer to a qualified or unqualified
    version of void; or
    — one operand is a pointer and the other is a null pointer constant.
    */
    try
    {
        pre_relational_expression(ctx,  ectx);
        if (ctx->n_errors > 0) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '==' ||
                ctx->current->type == '!='))
        {
            enum token_type op = ctx->current->type;
            pre_match(ctx);
            long long left_value = ectx->value;
            pre_multiplicative_expression(ctx,  ectx);
            if (ctx->n_errors > 0) throw;

            if (op == '==')
            {
                ectx->value = left_value == ectx->value;
            }
            else if (op == '!=')
            {
                ectx->value = left_value != ectx->value;
            }            
        }
    }
    catch
    {
    }
}

static void pre_and_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
     AND-expression:
      equality-expression
      AND-expression & equality-expression
    */
    try
    {
        pre_equality_expression(ctx,  ectx);
        if (ctx->n_errors > 0) throw;
        while (ctx->current != NULL &&
            (ctx->current->type == '&'))
        {
            pre_match(ctx);
            long long left_value = ectx->value;
            pre_equality_expression(ctx,  ectx);
            if (ctx->n_errors > 0) throw;
            ectx->value = left_value & ectx->value;
        }
    }
    catch
    {
    }
}

static void pre_exclusive_or_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
     exclusive-OR-expression:
      AND-expression
     exclusive-OR-expression ^ AND-expression
    */
    try
    {
        pre_and_expression(ctx, ectx);
        if (ctx->n_errors > 0) throw;

        
        while (ctx->current != NULL &&
            (ctx->current->type == '^'))
        {
            pre_match(ctx);
            long long left_value = ectx->value;
            pre_and_expression(ctx,  ectx);
            if (ctx->n_errors > 0) throw;
            ectx->value = left_value ^ ectx->value;
        }
    }
    catch
    {
    }
}

static void pre_inclusive_or_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
    inclusive-OR-expression:
    exclusive-OR-expression
    inclusive-OR-expression | exclusive-OR-expression
    */
    try
    {
        pre_exclusive_or_expression(ctx, ectx);
        if (ctx->n_errors > 0) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '|'))
        {
            pre_match(ctx);
            long long left_value = ectx->value;
            pre_exclusive_or_expression(ctx, ectx);
            if (ctx->n_errors > 0) throw;

            ectx->value = left_value | ectx->value;
        }
    }
    catch
    {
    }
}

static void pre_logical_and_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
    logical-AND-expression:
     inclusive-OR-expression
     logical-AND-expression && inclusive-OR-expression
    */
    try
    {
        pre_inclusive_or_expression(ctx, ectx);
        if (ctx->n_errors > 0) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '&&'))
        {
            pre_match(ctx);
            long long left_value = ectx->value;
            pre_inclusive_or_expression(ctx,  ectx);
            if (ctx->n_errors > 0) throw;

            ectx->value = left_value && ectx->value;
        }
    }
    catch
    {
    }
}

static void pre_logical_or_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
      logical-OR-expression:
       logical-AND-expression
       logical-OR-expression || logical-AND-expression
    */
    try
    {
        pre_logical_and_expression(ctx,  ectx);
        if (ctx->n_errors > 0) throw;

        while (ctx->current != NULL &&
            (ctx->current->type == '||'))
        {
            pre_match(ctx);
            long long left_value = ectx->value;
            pre_logical_and_expression(ctx,  ectx);
            if (ctx->n_errors > 0) throw;

            ectx->value = left_value || ectx->value;

        }
    }
    catch
    {
    }
}



static void pre_assignment_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
    assignment-expression:
       conditional-expression
       unary-expression assignment-operator assignment-expression
       */
       /*
          assignment-operator: one of
          = *= /= %= += -= <<= >>= &= ^= |=
       */
       //aqui eh duvidoso mas conditional faz a unary tb.
       //a diferenca q nao eh qualquer expressao
       //que pode ser de atribuicao
    try
    {
        pre_conditional_expression(ctx, ectx);
        if (ctx->n_errors > 0) throw;

        
        while (ctx->current != NULL &&
            (ctx->current->type == '=' ||
                ctx->current->type == '*=' ||
                ctx->current->type == '/=' ||
                ctx->current->type == '+=' ||
                ctx->current->type == '-=' ||
                ctx->current->type == '<<=' ||
                ctx->current->type == '>>=' ||
                ctx->current->type == '&=' ||
                ctx->current->type == '^=' ||
                ctx->current->type == '|='))
        {
            preprocessor_set_error_with_token(C_TOKEN_NOT_VALID_IN_PREPROCESSOR_EXPRESSIONS, ctx, ctx->current, "token '%s' is not valid in preprocessor expressions", ctx->current->lexeme);
            throw;
        }
    }
    catch
    {
    }
}

static void pre_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*expression:
      assignment-expression
      expression, assignment-expression
    */
    try
    {
        pre_assignment_expression(ctx, ectx);
        if (ctx->n_errors > 0) throw;
        
        while (ctx->current->type == ',')
        {
            pre_match(ctx);
            pre_expression(ctx, ectx);
            if (ctx->n_errors > 0) throw;            
        }
    }
    catch
    {
    }
}



static void pre_conditional_expression(struct preprocessor_ctx* ctx,struct pre_expression_ctx* ectx)
{
    /*
      conditional-expression:
      logical-OR-expression
      logical-OR-expression ? expression : conditional-expression
    */
    try
    {
        pre_logical_or_expression(ctx, ectx);
        if (ctx->n_errors > 0) throw;

        if (ctx->current && ctx->current->type == '?')
        {
            pre_match(ctx);
            if (ectx->value)
            {
                pre_expression(ctx, ectx);
                if (ctx->n_errors > 0) throw;

                pre_match(ctx); //:
                struct pre_expression_ctx temp = {0};
                pre_conditional_expression(ctx, &temp);                
                if (ctx->n_errors > 0) throw;
            }
            else
            {
                struct pre_expression_ctx temp = {0};
                pre_expression(ctx, &temp);
                if (ctx->n_errors > 0) throw;

                pre_match(ctx); //:
                pre_conditional_expression(ctx, ectx);
                if (ctx->n_errors > 0) throw;
            }
        }
    }
    catch
    {
    }
}

int pre_constant_expression(struct preprocessor_ctx* ctx,long long* pvalue)
{
    struct pre_expression_ctx ectx = { 0 };
    pre_conditional_expression(ctx, &ectx);
    *pvalue = ectx.value;
    return ctx->n_errors > 0;
}




void print_item(struct osstream* ss, bool* first, const char* item)
{
	if (!(*first))
		ss_fprintf(ss, " ");
	ss_fprintf(ss, "%s", item);
	*first = false;

}

bool print_type_specifier_flags(struct osstream* ss, bool* first, enum type_specifier_flags e_type_specifier_flags)
{
	if (e_type_specifier_flags & TYPE_SPECIFIER_VOID)
		print_item(ss, first, "void");

	if (e_type_specifier_flags & TYPE_SPECIFIER_SIGNED)
		print_item(ss, first, "signed");

	if (e_type_specifier_flags & TYPE_SPECIFIER_UNSIGNED)
		print_item(ss, first, "unsigned");

	if (e_type_specifier_flags & TYPE_SPECIFIER_INT)
		print_item(ss, first, "int");

	if (e_type_specifier_flags & TYPE_SPECIFIER_SHORT)
		print_item(ss, first, "short");

	if (e_type_specifier_flags & TYPE_SPECIFIER_LONG)
		print_item(ss, first, "long");

	if (e_type_specifier_flags & TYPE_SPECIFIER_LONG_LONG)
		print_item(ss, first, "long long");

	if (e_type_specifier_flags & TYPE_SPECIFIER_INT16)
		print_item(ss, first, "__int16");

	if (e_type_specifier_flags & TYPE_SPECIFIER_INT32)
		print_item(ss, first, "__int32");

	if (e_type_specifier_flags & TYPE_SPECIFIER_INT64)
		print_item(ss, first, "__int64");

	if (e_type_specifier_flags & TYPE_SPECIFIER_CHAR)
		print_item(ss, first, "char");

	if (e_type_specifier_flags & TYPE_SPECIFIER_DOUBLE)
		print_item(ss, first, "double");

	if (e_type_specifier_flags & TYPE_SPECIFIER_FLOAT)
		print_item(ss, first, "float");

	if (e_type_specifier_flags & TYPE_SPECIFIER_BOOL)
		print_item(ss, first, "_Bool");

	if (e_type_specifier_flags & TYPE_SPECIFIER_COMPLEX)
		print_item(ss, first, "_Complex");

	if (e_type_specifier_flags & TYPE_SPECIFIER_DECIMAL32)
		print_item(ss, first, "_Decimal32");

	if (e_type_specifier_flags & TYPE_SPECIFIER_DECIMAL64)
		print_item(ss, first, "_Decimal64");

	if (e_type_specifier_flags & TYPE_SPECIFIER_DECIMAL128)
		print_item(ss, first, "_Decimal128");

	if (e_type_specifier_flags & TYPE_SPECIFIER_NULLPTR_T)
		print_item(ss, first, "nullptr_t");

	return *first;
}



void print_type_qualifier_flags(struct osstream* ss, bool* first, enum type_qualifier_flags e_type_qualifier_flags)
{

	if (e_type_qualifier_flags & TYPE_QUALIFIER_CONST)
		print_item(ss, first, "const");

	if (e_type_qualifier_flags & TYPE_QUALIFIER_RESTRICT)
		print_item(ss, first, "restrict");

	if (e_type_qualifier_flags & TYPE_QUALIFIER_VOLATILE)
		print_item(ss, first, "volatile");

}

void print_type_qualifier_specifiers(struct osstream* ss, const struct type* type)
{
	bool first = true;
	print_type_qualifier_flags(ss, &first, type->type_qualifier_flags);

	if (type->type_specifier_flags & TYPE_SPECIFIER_STRUCT_OR_UNION)
	{
		print_item(ss, &first, "struct ");
		ss_fprintf(ss, "%s", type->struct_or_union_specifier->tag_name);
	}
	else if (type->type_specifier_flags & TYPE_SPECIFIER_ENUM)
	{
		print_item(ss, &first, "enum ");
		if (type->enum_specifier->tag_token)
			ss_fprintf(ss, "%s", type->enum_specifier->tag_token->lexeme);

	}
	else if (type->type_specifier_flags & TYPE_SPECIFIER_TYPEDEF)
	{
		assert(false);
	}
	else
	{
		print_type_specifier_flags(ss, &first, type->type_specifier_flags);
	}
}

void type_add_const(struct type* p_type)
{
	p_type->type_qualifier_flags |= TYPE_QUALIFIER_CONST;
}

void type_remove_qualifiers(struct type* p_type)
{
	p_type->type_qualifier_flags = 0;
}

struct type type_lvalue_conversion(struct type* p_type)
{

	enum type_category category = type_get_category(p_type);
	switch (category)
	{
	case TYPE_CATEGORY_FUNCTION:
	{
		/*
		   "function returning type" is converted to an expression that has type
		   "pointer to function returning type".
		*/
		struct type t = type_add_pointer(p_type);
		t.storage_class_specifier_flags &= ~STORAGE_SPECIFIER_PARAMETER;
		t.category = t.category;
		return t;
	}
	break;
	case TYPE_CATEGORY_ARRAY:
	{
		/*
		  An expression that has type "array of type" is converted
		  to an expression with type "pointer to type" that points to the initial element
		  of the array object and s not an lvalue.
		  If the array object has register storage class, the behavior is undefined.
		*/
		struct type t = get_array_item_type(p_type);
		struct type t2 = type_add_pointer(&t);

		type_remove_qualifiers(&t2);
		/*
		int g(const int a[const 20]) {
			// in this function, a has type const int* const (const pointer to const int)
			}
		*/
		type_destroy(&t);
		t2.storage_class_specifier_flags &= ~STORAGE_SPECIFIER_PARAMETER;
		return t2;
	}
	break;
	case TYPE_CATEGORY_POINTER:
		break;
	case TYPE_CATEGORY_ITSELF:
	default:
		break;
	}

	struct type t = type_dup(p_type);
	type_remove_qualifiers(&t);
	t.storage_class_specifier_flags &= ~STORAGE_SPECIFIER_PARAMETER;

	t.category = type_get_category(&t);

	return t;
}

struct type type_convert_to(const struct type* p_type, enum language_version target)
{
	/*
	* Convert types to previous standard format
	*/

	if (type_is_nullptr_t(p_type))
	{
		if (target < LANGUAGE_C2X)
		{
			struct type t = make_void_ptr_type();
			assert(t.name_opt == NULL);
			if (p_type->name_opt)
			{
				t.name_opt = strdup(p_type->name_opt);
			}
			return t;
		}
	}
	else if (type_is_bool(p_type))
	{
		if (target < LANGUAGE_C99)
		{
			struct type t = type_dup(p_type);
			t.type_specifier_flags &= ~TYPE_SPECIFIER_BOOL;
			t.type_specifier_flags |= TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_CHAR;
			return t;
		}
	}

	return type_dup(p_type);
}

void print_type_core(struct osstream* ss, const struct type* p_type, bool onlydeclarator)
{
	const struct type* p = p_type;

	while (p)
	{
		if (onlydeclarator && p->next == NULL)
			break;

		switch (p->category)
		{
		case TYPE_CATEGORY_ITSELF:
		{
			struct osstream local = { 0 };
			bool first = true;

			print_type_qualifier_flags(&local, &first, p->type_qualifier_flags);

			if (p->struct_or_union_specifier)
			{
				ss_fprintf(&local, "struct %s", p->struct_or_union_specifier->tag_name);
			}
			else if (p->enum_specifier)
			{
				if (p->enum_specifier->tag_token->lexeme)
					ss_fprintf(&local, "enum %s", p->enum_specifier->tag_token->lexeme);
			}
			else
			{
				print_type_specifier_flags(&local, &first, p->type_specifier_flags);
			}



			if (p->name_opt)
			{
				if (first)
				{
					ss_fprintf(ss, " ");
					first = false;
				}
				ss_fprintf(ss, "%s", p->name_opt);
			}

			struct osstream local2 = { 0 };
			if (ss->c_str)
				ss_fprintf(&local2, "%s %s", local.c_str, ss->c_str);
			else
				ss_fprintf(&local2, "%s", local.c_str);

			ss_swap(ss, &local2);
			ss_close(&local);
			ss_close(&local2);
		}
		break;
		case TYPE_CATEGORY_ARRAY:


			if (p->name_opt)
			{
				//if (first)
				//{
				  //  ss_fprintf(ss, " ");
					//first = false;
				//}
				ss_fprintf(ss, "%s", p->name_opt);
			}

			ss_fprintf(ss, "[");

			bool b = true;
			if (p->static_array)
			{
				ss_fprintf(ss, "static");
				b = false;
			}

			print_type_qualifier_flags(ss, &b, p->type_qualifier_flags);

			if (p->array_size > 0)
			{
				if (!b)
					ss_fprintf(ss, " ");

				ss_fprintf(ss, "%d", p->array_size);
			}
			ss_fprintf(ss, "]");

			break;
		case TYPE_CATEGORY_FUNCTION:

			if (p->name_opt)
			{
				//if (first)
				//{
				  //  ss_fprintf(ss, " ");
					//first = false;
				//}
				ss_fprintf(ss, "%s", p->name_opt);
			}
			ss_fprintf(ss, "(");




			struct param* pa = p->params.head;

			while (pa)
			{
				struct osstream sslocal = { 0 };
				print_type(&sslocal, &pa->type);
				ss_fprintf(ss, "%s", sslocal.c_str);
				if (pa->next)
					ss_fprintf(ss, ",");
				ss_close(&sslocal);
				pa = pa->next;
			}
			ss_fprintf(ss, ")");
			break;

		case TYPE_CATEGORY_POINTER:
		{
			struct osstream local = { 0 };
			if (p->next && (
				(p->next->category == TYPE_CATEGORY_FUNCTION ||
					p->next->category == TYPE_CATEGORY_ARRAY)))
			{
				ss_fprintf(&local, "(");
			}

			ss_fprintf(&local, "*");
			bool first = false;
			print_type_qualifier_flags(&local, &first, p->type_qualifier_flags);

			if (p->name_opt)
			{
				if (!first)
				{
					ss_fprintf(ss, " ");
				}
				ss_fprintf(ss, "%s", p->name_opt);
				first = false;
			}

			if (ss->c_str)
				ss_fprintf(&local, "%s", ss->c_str);

			if (p->next &&
				(p->next->category == TYPE_CATEGORY_FUNCTION ||
					p->next->category == TYPE_CATEGORY_ARRAY))
			{
				ss_fprintf(&local, ")", ss->c_str);
			}

			ss_swap(ss, &local);
			ss_close(&local);
		}
		break;
		}

		p = p->next;

	}
}

void print_type(struct osstream* ss, const struct type* p_type)
{
	print_type_core(ss, p_type, false);
}

void print_type_declarator(struct osstream* ss, const struct type* p_type)
{
	print_type_core(ss, p_type, true);
}

void type_print(const struct type* a)
{
	struct osstream ss = { 0 };
	print_type(&ss, a);
	puts(ss.c_str);
	puts("\n");
	ss_close(&ss);
}

enum type_category type_get_category(const struct type* p_type)
{
	return p_type->category;
}

void param_list_destroy(struct param_list* obj_owner p)
{
	struct param* owner item = p->head;
	while (item)
	{
		struct param* owner next = item->next;
		type_destroy(&item->type);
		free(item);
		item = next;
	}
}

void type_destroy_one(struct type* obj_owner p_type)
{
	free((void* owner)p_type->name_opt);
	param_list_destroy(&p_type->params);
	assert(p_type->next == NULL);
}

void type_destroy(struct type* obj_owner p_type)
{
	free((void* owner)p_type->name_opt);
	param_list_destroy(&p_type->params);

	struct type* owner item = p_type->next;
	while (item)
	{
		struct type* owner next = item->next;
		item->next = NULL;
		type_destroy_one(item);
		free(item);
		item = next;
	}

}

bool type_has_attribute(const struct type* p_type, enum attribute_flags attributes)
{
	if (p_type->attributes_flags & attributes)
	{
		/*like
		  [[maybe_unused]] int i;
		*/
		return true;
	}

	struct attribute_specifier_sequence* p_attribute_specifier_sequence_opt = NULL;


	if (p_type->struct_or_union_specifier)
	{
		/*like
		  struct [[maybe_unused]] X { }
		  struct X x;
		*/
		p_attribute_specifier_sequence_opt = p_type->struct_or_union_specifier->attribute_specifier_sequence_opt;

		struct struct_or_union_specifier* p_complete =
			get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

		if (p_attribute_specifier_sequence_opt == NULL && p_complete)
		{
			p_attribute_specifier_sequence_opt = p_complete->attribute_specifier_sequence_opt;
		}
	}
	else if (p_type->enum_specifier)
	{
		p_attribute_specifier_sequence_opt = p_type->enum_specifier->attribute_specifier_sequence_opt;
		if (p_attribute_specifier_sequence_opt == NULL &&
			p_type->enum_specifier->complete_enum_specifier)
		{
			p_attribute_specifier_sequence_opt = p_type->enum_specifier->complete_enum_specifier->attribute_specifier_sequence_opt;
		}
	}

	if (p_attribute_specifier_sequence_opt &&
		p_attribute_specifier_sequence_opt->attributes_flags & attributes)
	{
		return true;
	}

	return false;
}

bool type_is_maybe_unused(const struct type* p_type)
{
	return type_has_attribute(p_type, STD_ATTRIBUTE_MAYBE_UNUSED);
}

bool type_is_deprecated(const struct type* p_type)
{
	return type_has_attribute(p_type, STD_ATTRIBUTE_DEPRECATED);
}

bool type_is_nodiscard(const struct type* p_type)
{
	return type_has_attribute(p_type, STD_ATTRIBUTE_NODISCARD);
}

bool type_is_array(const struct type* p_type)
{
	return type_get_category(p_type) == TYPE_CATEGORY_ARRAY;
}



bool type_is_any_owner(const struct type* p_type)
{
	if (type_is_owner(p_type))
	{
		return true;
	}
	return p_type->type_qualifier_flags & TYPE_QUALIFIER_OBJ_OWNER;
}

bool type_is_pointer_to_owner(const struct type* p_type)
{
	return type_is_owner(p_type->next);
}

bool type_is_obj_owner(const struct type* p_type)
{
	return p_type->type_qualifier_flags & TYPE_QUALIFIER_OBJ_OWNER;
}

bool type_is_owner(const struct type* p_type)
{

	if (p_type->struct_or_union_specifier)
	{
		if (p_type->type_qualifier_flags & TYPE_QUALIFIER_VIEW)
			return false;

		struct struct_or_union_specifier* p_complete =
			get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

		if (p_complete && p_complete->is_owner)
		{
			//The objective here is fix a type later.
			/*
			 struct X;
			 struct X f(); //X is owner?
			 struct X { char * owner p; };
			 int main()
			 {
			   struct X x = 1 ? f() : f();
			 }
			*/

			return true;
		}
	}

	return p_type->type_qualifier_flags & TYPE_QUALIFIER_OWNER;
}

bool type_is_out(const struct type* p_type)
{
	return p_type->type_qualifier_flags & TYPE_QUALIFIER_OUT;
}

bool type_is_const(const struct type* p_type)
{
	return p_type->type_qualifier_flags & TYPE_QUALIFIER_CONST;
}

bool type_is_pointer_to_const(const struct type* p_type)
{
	if (p_type->category == TYPE_CATEGORY_POINTER)
	{
		if (p_type->next)
		{
			return p_type->next->type_qualifier_flags & TYPE_QUALIFIER_CONST;
		}
	}
	return false;
}

bool type_is_void_ptr(const struct type* p_type)
{
	if (p_type->category == TYPE_CATEGORY_POINTER)
	{
		if (p_type->next)
		{
			return p_type->next->type_specifier_flags & TYPE_SPECIFIER_VOID;
		}
	}
	return false;
}

bool type_is_void(const struct type* p_type)
{
	if (p_type->category == TYPE_CATEGORY_ITSELF)
	{
		return p_type->type_specifier_flags & TYPE_SPECIFIER_VOID;
	}

	return false;
}

bool type_is_nullptr_t(const struct type* p_type)
{
	if (p_type->category == TYPE_CATEGORY_ITSELF)
	{
		return p_type->type_specifier_flags & TYPE_SPECIFIER_NULLPTR_T;
	}

	return false;
}

bool type_is_pointer(const struct type* p_type)
{
	return p_type->category == TYPE_CATEGORY_POINTER;
}

bool type_is_enum(const struct type* p_type)
{
	return type_get_category(p_type) == TYPE_CATEGORY_ITSELF &&
		p_type->type_specifier_flags & TYPE_SPECIFIER_ENUM;
}

bool type_is_struct_or_union(const struct type* p_type)
{
	return type_get_category(p_type) == TYPE_CATEGORY_ITSELF &&
		p_type->type_specifier_flags & TYPE_SPECIFIER_STRUCT_OR_UNION;
}

/*
  The three types
  char, signed char, and unsigned char
  are collectively called the character types.
*/
bool type_is_character(const struct type* p_type)
{
	return type_get_category(p_type) == TYPE_CATEGORY_ITSELF &&
		p_type->type_specifier_flags & TYPE_SPECIFIER_CHAR;
}

bool type_is_bool(const struct type* p_type)
{
	return type_get_category(p_type) == TYPE_CATEGORY_ITSELF &&
		p_type->type_specifier_flags & TYPE_SPECIFIER_BOOL;
}

/*
 There are three standard floating types, designated as
 float, double, and long double.

 There are three decimal floating types, designated as _Decimal32, _Decimal64, and _Decimal128.
*/
bool type_is_floating_point(const struct type* p_type)
{
	if (type_get_category(p_type) != TYPE_CATEGORY_ITSELF)
		return false;

	return p_type->type_specifier_flags &
		(TYPE_SPECIFIER_DOUBLE |
			TYPE_SPECIFIER_FLOAT);
}

bool type_is_unsigned_integer(const struct type* p_type)
{
	if (type_is_integer(p_type) &&
		(p_type->type_specifier_flags & TYPE_SPECIFIER_UNSIGNED))
	{
		return true;
	}

	return false;
}
/*
  The type char, the signed and unsigned integer types,
  and the enumerated types
  are collectively  called integer types.
*/
bool type_is_integer(const struct type* p_type)
{
	if (type_get_category(p_type) != TYPE_CATEGORY_ITSELF)
		return false;

	if (p_type->type_specifier_flags & TYPE_SPECIFIER_DOUBLE)
	{
		/*we cannot check long without check double*/
		//long double
		return false;
	}

	if (p_type->type_specifier_flags & TYPE_SPECIFIER_ENUM)
	{
		return true;
	}

	return p_type->type_specifier_flags &
		(TYPE_SPECIFIER_CHAR |
			TYPE_SPECIFIER_SHORT |
			TYPE_SPECIFIER_INT |

			TYPE_SPECIFIER_INT16 |
			TYPE_SPECIFIER_INT32 |
			TYPE_SPECIFIER_INT64 |

			TYPE_SPECIFIER_INT |
			TYPE_SPECIFIER_LONG |
			TYPE_SPECIFIER_SIGNED |
			TYPE_SPECIFIER_UNSIGNED |
			TYPE_SPECIFIER_INT8 |
			TYPE_SPECIFIER_INT16 |
			TYPE_SPECIFIER_INT64 |
			TYPE_SPECIFIER_LONG_LONG |
			TYPE_SPECIFIER_BOOL);
}

/*
* Integer and floating types are collectively called arithmetic types.
*/
bool type_is_arithmetic(const struct type* p_type)
{
	return type_is_integer(p_type) || type_is_floating_point(p_type);
}

/*
 Arithmetic types, pointer types, and the nullptr_t type are collectively
 called scalar types.
*/
bool type_is_scalar(const struct type* p_type)
{
	//TODO we need two concepts...is_scalar on real type or is_scalar after lvalue converison

	if (type_is_arithmetic(p_type))
		return true;

	if (type_is_pointer_or_array(p_type))
		return true;

	if (type_get_category(p_type) != TYPE_CATEGORY_ITSELF)
		return false;


	if (p_type->type_specifier_flags & TYPE_SPECIFIER_ENUM)
		return true;
	if (p_type->type_specifier_flags & TYPE_SPECIFIER_NULLPTR_T)
		return true;

	if (p_type->type_specifier_flags & TYPE_SPECIFIER_BOOL)
		return true;

	return false;
}


const struct param_list* type_get_func_or_func_ptr_params(const struct type* p_type)
{
	if (p_type->category == TYPE_CATEGORY_FUNCTION)
	{
		return &p_type->params;
	}
	else if (p_type->category == TYPE_CATEGORY_POINTER)
	{
		if (p_type->next &&
			p_type->next->category == TYPE_CATEGORY_FUNCTION)
		{
			return &p_type->next->params;
		}
	}
	return NULL;
}

void check_ownership_qualifiers_of_argument_and_parameter(struct parser_ctx* ctx,
	struct argument_expression* current_argument,
	struct type* paramer_type,
	int param_num)
{
	//            owner     obj_owner  view parameter
	// owner      OK                   OK
	// obj_owner  X         OK         OK
	// view       X (NULL)  X          OK

	const bool paramer_is_obj_owner = type_is_obj_owner(paramer_type);
	const bool paramer_is_owner = type_is_owner(paramer_type);
	const bool paramer_is_view = !paramer_is_obj_owner && !paramer_is_owner;

	const struct type* const argument_type = &current_argument->expression->type;
	const bool argument_is_owner = type_is_owner(&current_argument->expression->type);
	const bool argument_is_obj_owner = type_is_obj_owner(&current_argument->expression->type);
	const bool argument_is_view = !argument_is_owner && !argument_is_obj_owner;

	if (argument_is_owner && paramer_is_owner)
	{
		//ok
	}
	else if (argument_is_owner && paramer_is_obj_owner)
	{
		//ok
	}
	else if (argument_is_owner && paramer_is_view)
	{
		//ok
		if (current_argument->expression->type.storage_class_specifier_flags & STORAGE_SPECIFIER_FUNCTION_RETURN)
		{
			compiler_set_error_with_token(C_OWNERSHIP_USING_TEMPORARY_OWNER,
				ctx,
				current_argument->expression->first_token,
				"passing a temporary owner to a view");
		}

	}////////////////////////////////////////////////////////////
	else if (argument_is_obj_owner && paramer_is_owner)
	{
		compiler_set_error_with_token(C_OWNERSHIP_MOVE_ASSIGNMENT_OF_NON_OWNER,
			ctx,
			current_argument->expression->first_token,
			"cannot move obj_owner to owner");
	}
	else if (argument_is_obj_owner && paramer_is_obj_owner)
	{
		//ok
	}
	else if (argument_is_obj_owner && paramer_is_view)
	{
		//ok
		//ok
		if (current_argument->expression->type.storage_class_specifier_flags & STORAGE_SPECIFIER_FUNCTION_RETURN)
		{
			compiler_set_error_with_token(C_OWNERSHIP_USING_TEMPORARY_OWNER,
				ctx,
				current_argument->expression->first_token,
				"passing a temporary owner to a view");
		}


	}///////////////////////////////////////////////////////////////
	else if (argument_is_view && paramer_is_owner)
	{
		if (!expression_is_zero(current_argument->expression))
		{
			compiler_set_error_with_token(C_OWNERSHIP_MOVE_ASSIGNMENT_OF_NON_OWNER,
				ctx,
				current_argument->expression->first_token,
				"passing a view argument to a owner parameter");
		}
	}
	else if (argument_is_view && paramer_is_obj_owner)
	{
		//check if the contented of pointer is owner.
		if (type_is_pointer(argument_type))
		{
			struct type t2 = type_remove_pointer(argument_type);
			if (!type_is_owner(&t2))
			{

				compiler_set_error_with_token(C_OWNERSHIP_MOVE_ASSIGNMENT_OF_NON_OWNER,
					ctx,
					current_argument->expression->first_token,
					"pointed object is not owner");

			}
			else
			{
				//pointer object is owner 
				if (!argument_type->address_of)
				{
					//we need something created with address of.
					compiler_set_error_with_token(C_OWNERSHIP_MOVE_ASSIGNMENT_OF_NON_OWNER,
						ctx,
						current_argument->expression->first_token,
						"obj_owner pointer must be created using address of operator &");
				}
			}

			type_destroy(&t2);
		}
		else
		{
			if (!expression_is_zero(current_argument->expression))
			{
				compiler_set_error_with_token(C_OWNERSHIP_MOVE_ASSIGNMENT_OF_NON_OWNER,
					ctx,
					current_argument->expression->first_token,
					"passing a view argument to a obj_owner parameter");
			}
		}

	}
	else if (argument_is_view && paramer_is_view)
	{
		//ok
	}///////////////////////////////////////////////////////////////
}

void check_argument_and_parameter(struct parser_ctx* ctx,
	struct argument_expression* current_argument,
	struct type* paramer_type,
	int param_num)
{

	if (type_is_any_owner(paramer_type))
	{
		if (type_is_obj_owner(paramer_type))
		{
			if (current_argument->expression->type.category == TYPE_CATEGORY_POINTER)
			{
				if (type_is_pointer(&current_argument->expression->type) &&
					!type_is_pointer_to_owner(&current_argument->expression->type))
				{
					compiler_set_error_with_token(C_OWNERSHIP_NOT_OWNER, ctx,
						current_argument->expression->first_token,
						"parameter %d requires a pointer to owner object",
						param_num);
				}
			}
			else
			{
				compiler_set_error_with_token(C_OWNERSHIP_NOT_OWNER, ctx,
					current_argument->expression->first_token,
					"parameter %d requires a pointer to owner type",
					param_num);
			}
		}
	}
	struct type* argument_type = &current_argument->expression->type;
	bool is_null_pointer_constant = false;

	if (current_argument)
	{
		is_null_pointer_constant = expression_is_null_pointer_constant(current_argument->expression);
	}

	struct type parameter_type_converted = (type_is_array(paramer_type)) ?
		type_lvalue_conversion(paramer_type) :
		type_dup(paramer_type);


	struct type argument_type_converted =
		expression_is_subjected_to_lvalue_conversion(current_argument->expression) ?
		type_lvalue_conversion(argument_type) :
		type_dup(argument_type);


	/*
	   less generic tests are first
	*/
	if (type_is_enum(argument_type) && type_is_enum(paramer_type))
	{
		if (!type_is_same(argument_type, paramer_type, false))
		{
			compiler_set_error_with_token(C_INCOMPATIBLE_TYPES, ctx,
				current_argument->expression->first_token,
				" incompatible types at argument %d", param_num);
		}

		check_ownership_qualifiers_of_argument_and_parameter(ctx,
			current_argument,
			paramer_type,
			param_num);

		type_destroy(&parameter_type_converted);
		type_destroy(&argument_type_converted);

		return;
	}

	if (type_is_arithmetic(argument_type) && type_is_arithmetic(paramer_type))
	{
		check_ownership_qualifiers_of_argument_and_parameter(ctx,
			current_argument,
			paramer_type,
			param_num);

		type_destroy(&parameter_type_converted);
		type_destroy(&argument_type_converted);

		return;
	}

	if (is_null_pointer_constant && type_is_pointer(paramer_type))
	{
		//TODO void F(int * [[opt]] p)
		// F(0) when passing null we will check if the parameter 
		//have the anotation [[opt]]

		/*can be converted to any type*/
		check_ownership_qualifiers_of_argument_and_parameter(ctx,
			current_argument,
			paramer_type,
			param_num);

		type_destroy(&parameter_type_converted);
		type_destroy(&argument_type_converted);

		return;
	}

	if (is_null_pointer_constant && type_is_array(paramer_type))
	{
		compiler_set_warning_with_token(W_NON_NULL,
			ctx,
			current_argument->expression->first_token,
			" passing null as array");

		check_ownership_qualifiers_of_argument_and_parameter(ctx,
			current_argument,
			paramer_type,
			param_num);

		type_destroy(&parameter_type_converted);
		type_destroy(&argument_type_converted);

		return;
	}

	/*
	   We have two pointers or pointer/array combination
	*/
	if (type_is_pointer_or_array(argument_type) && type_is_pointer_or_array(paramer_type))
	{
		if (type_is_void_ptr(argument_type))
		{
			/*void pointer can be converted to any type*/
			check_ownership_qualifiers_of_argument_and_parameter(ctx,
				current_argument,
				paramer_type,
				param_num);

			type_destroy(&parameter_type_converted);
			type_destroy(&argument_type_converted);

			return;
		}

		if (type_is_void_ptr(paramer_type))
		{
			/*any pointer can be converted to void* */
			check_ownership_qualifiers_of_argument_and_parameter(ctx,
				current_argument,
				paramer_type,
				param_num);

			type_destroy(&parameter_type_converted);
			type_destroy(&argument_type_converted);

			return;
		}


		//TODO  lvalue

		if (type_is_array(paramer_type))
		{
			int parameter_array_size = type_get_array_size(paramer_type);
			if (type_is_array(argument_type))
			{
				int argument_array_size = type_get_array_size(argument_type);
				if (parameter_array_size != 0 &&
					argument_array_size < parameter_array_size)
				{
					compiler_set_error_with_token(C_ARGUMENT_SIZE_SMALLER_THAN_PARAMETER_SIZE,
						ctx,
						current_argument->expression->first_token,
						" argument of size [%d] is smaller than parameter of size [%d]", argument_array_size, parameter_array_size);
				}
			}
			else if (is_null_pointer_constant || type_is_nullptr_t(argument_type))
			{
				compiler_set_error_with_token(C_PASSING_NULL_AS_ARRAY,
					ctx,
					current_argument->expression->first_token,
					" passing null as array");
			}
		}



		if (!type_is_same(&argument_type_converted, &parameter_type_converted, false))
		{
			type_print(&argument_type_converted);
			type_print(&parameter_type_converted);

			compiler_set_error_with_token(C_INCOMPATIBLE_TYPES, ctx,
				current_argument->expression->first_token,
				" incompatible types at argument %d", param_num);
			//disabled for now util it works correctly
			//return false;
		}

		if (type_is_pointer(&argument_type_converted) && type_is_pointer(&parameter_type_converted))
		{
			//parameter pointer do non const
			//argument const.
			struct type argument_pointer_to = type_remove_pointer(&argument_type_converted);
			struct type parameter_pointer_to = type_remove_pointer(&parameter_type_converted);
			if (type_is_const(&argument_pointer_to) &&
				!type_is_const(&parameter_pointer_to) &&
				!type_is_any_owner(&parameter_pointer_to))
			{
				compiler_set_error_with_token(C_DISCARDING_CONST_AT_ARGUMENT, ctx,
					current_argument->expression->first_token,
					" discarding const at argument %d", param_num);
			}
			type_destroy(&argument_pointer_to);
			type_destroy(&parameter_pointer_to);
		}
		//return true;
	}

	//TODO
	//if (!type_is_same(paramer_type, &current_argument->expression->type, false))
	//{
	//    compiler_set_error_with_token(C1, ctx,
	//        current_argument->expression->first_token,
	//        " incompatible types at argument %d ", param_num);
	//}



	check_ownership_qualifiers_of_argument_and_parameter(ctx,
		current_argument,
		paramer_type,
		param_num);



	type_destroy(&argument_type_converted);
	type_destroy(&parameter_type_converted);
}

void check_owner_rules_assigment(struct parser_ctx* ctx,
	struct type* left_type,
	struct expression* right,
	bool return_assignment)
{

	struct type* p_right_type = &right->type;
	bool is_null_pointer_constant = false;

	if (type_is_nullptr_t(&right->type) ||
		(constant_value_is_valid(&right->constant_value) &&
			constant_value_to_ull(&right->constant_value) == 0))
	{
		is_null_pointer_constant = true;
	}

	struct type lvalue_right_type = { 0 };
	struct type t2 = { 0 };

	if (expression_is_subjected_to_lvalue_conversion(right))
	{
		lvalue_right_type = type_lvalue_conversion(p_right_type);
	}
	else
	{
		lvalue_right_type = type_dup(p_right_type);
	}

	if (return_assignment)
	{
		if (type_is_pointer(&right->type) &&
			right->type.next &&
			right->type.next->storage_class_specifier_flags & STORAGE_SPECIFIER_AUTOMATIC_STORAGE)
		{
			compiler_set_warning_with_token(W_RETURN_LOCAL_ADDR,
				ctx,
				right->first_token,
				"function returns address of local variable");
		}
		if (type_is_array(&right->type) &&			
			right->type.storage_class_specifier_flags & STORAGE_SPECIFIER_AUTOMATIC_STORAGE)
		{
			compiler_set_warning_with_token(W_RETURN_LOCAL_ADDR,
				ctx,
				right->first_token,
				"function returns address of local variable");
		}
		/*              return | non owner  | owner
			non owner          | OK         | if external, or param
			owner          |   | ERROR      | explicit if local, non explicit if external or param
		*/

		if (type_is_owner(&right->type))
		{
			if (type_is_owner(left_type))
			{
				//returning a owning variable to a owner result                                
				// * explicit if local variable                
				// * non explicit if param or external
				// ok if external



			}
			else
			{
				//returning a owning variable to a non owner result
				// * ok if external or param
				if (right->type.storage_class_specifier_flags & STORAGE_SPECIFIER_AUTOMATIC_STORAGE)
				{
					compiler_set_error_with_token(C_OWNERSHIP_MOVE_ASSIGNMENT_OF_NON_OWNER,
						ctx,
						right->first_token,
						"returning a owner variable to a non owner result");
				}
			}
		}
		else
		{
			if (type_is_owner(left_type))
			{
				if (type_is_pointer(left_type) &&
					constant_value_is_valid(&right->constant_value) &&
					constant_value_to_bool(&right->constant_value) == false)
				{
					//ok
				}
				else
				{
					//returning a non owning variable to owner
					compiler_set_error_with_token(C_OWNERSHIP_MOVE_ASSIGNMENT_OF_NON_OWNER,
						ctx,
						right->first_token,
						"returning a non owner variable to a owner");
				}
			}
			else
			{
				//returning a non owning variable to non owner
				//ok
			}
		}
	}
	else
	{
		if (type_is_owner(left_type))
		{
			if (type_is_owner(&right->type))
			{
				//owner = owner

			}
			else
			{
				//owner = non-owner
				if (!is_null_pointer_constant)
				{
					compiler_set_error_with_token(C_OWNERSHIP_MOVE_ASSIGNMENT_OF_NON_OWNER,
						ctx,
						right->first_token,
						"move assignment needs a owner type on right side");
				}
			}
		}
		else
		{
			if (type_is_owner(&right->type))
			{
				//non owner = owner

				if (right->type.storage_class_specifier_flags & STORAGE_SPECIFIER_FUNCTION_RETURN)
				{
					//non owner = (owner) f()
					compiler_set_error_with_token(C_OWNERSHIP_NON_OWNER_MOVE,
						ctx,
						right->first_token,
						"cannot move a temporary owner to non-owner");
				}



			}
			else
			{
				//non owner = non owner


			}
		}
	}
	if (right->type.type_qualifier_flags & TYPE_QUALIFIER_OWNER)
	{
		if (right->expression_type == POSTFIX_FUNCTION_CALL)
		{
			//p = f();
			if (!type_is_owner(left_type))
			{
				compiler_set_error_with_token(C_OWNERSHIP_MISSING_OWNER_QUALIFIER, ctx, right->first_token, "left type must be owner qualified ");
			}
		}
	}



	type_destroy(&lvalue_right_type);
	type_destroy(&t2);

}

void check_assigment(struct parser_ctx* ctx,
	struct type* left_type,
	struct expression* right,
	bool return_assignment)
{

	struct type* p_right_type = &right->type;
	bool is_null_pointer_constant = false;

	if (type_is_nullptr_t(&right->type) ||
		(constant_value_is_valid(&right->constant_value) &&
			constant_value_to_ull(&right->constant_value) == 0))
	{
		is_null_pointer_constant = true;
	}

	struct type lvalue_right_type = { 0 };
	struct type t2 = { 0 };

	if (expression_is_subjected_to_lvalue_conversion(right))
	{
		lvalue_right_type = type_lvalue_conversion(p_right_type);
	}
	else
	{
		lvalue_right_type = type_dup(p_right_type);
	}


	if (!(type_is_owner(&right->type)) && type_is_owner(left_type))
	{
		if (!is_null_pointer_constant)
		{
			compiler_set_error_with_token(C_OWNERSHIP_NON_OWNER_TO_OWNER_ASSIGN, ctx, right->first_token, "cannot assign a non owner to owner");

			check_owner_rules_assigment(ctx,
				left_type,
				right,
				return_assignment);

			type_destroy(&lvalue_right_type);
			type_destroy(&t2);

			return;
		}
	}


	/*
	   less generic tests are first
	*/
	if (type_is_enum(p_right_type) && type_is_enum(left_type))
	{
		if (!type_is_same(p_right_type, left_type, false))
		{
			compiler_set_error_with_token(C_INCOMPATIBLE_ENUN_TYPES, ctx,
				right->first_token,
				" incompatible types ");
		}
		check_owner_rules_assigment(ctx,
			left_type,
			right,
			return_assignment);

		type_destroy(&lvalue_right_type);
		type_destroy(&t2);
		return;
	}

	if (type_is_arithmetic(p_right_type) && type_is_arithmetic(left_type))
	{
		check_owner_rules_assigment(ctx,
			left_type,
			right,
			return_assignment);
		type_destroy(&lvalue_right_type);
		type_destroy(&t2);
		return;
	}

	if (is_null_pointer_constant && type_is_pointer(left_type))
	{
		//TODO void F(int * [[opt]] p)
		// F(0) when passing null we will check if the parameter 
		//have the anotation [[opt]]

		/*can be converted to any type*/
		check_owner_rules_assigment(ctx,
			left_type,
			right,
			return_assignment);
		type_destroy(&lvalue_right_type);
		type_destroy(&t2);
		return;
	}

	if (is_null_pointer_constant && type_is_array(left_type))
	{
		compiler_set_warning_with_token(W_NON_NULL,
			ctx,
			right->first_token,
			" passing null as array");

		check_owner_rules_assigment(ctx,
			left_type,
			right,
			return_assignment);
		type_destroy(&lvalue_right_type);
		type_destroy(&t2);
		return;
	}

	/*
	   We have two pointers or pointer/array combination
	*/
	if (type_is_pointer_or_array(p_right_type) && type_is_pointer_or_array(left_type))
	{
		if (type_is_void_ptr(p_right_type))
		{
			/*void pointer can be converted to any type*/
			check_owner_rules_assigment(ctx,
				left_type,
				right,
				return_assignment);
			type_destroy(&lvalue_right_type);
			type_destroy(&t2);
			return;
		}

		if (type_is_void_ptr(left_type))
		{
			/*any pointer can be converted to void* */
			check_owner_rules_assigment(ctx,
				left_type,
				right,
				return_assignment);
			type_destroy(&lvalue_right_type);
			type_destroy(&t2);
			return;
		}


		//TODO  lvalue

		if (type_is_array(left_type))
		{
			int parameter_array_size = type_get_array_size(left_type);
			if (type_is_array(p_right_type))
			{
				int argument_array_size = type_get_array_size(p_right_type);
				if (parameter_array_size != 0 &&
					argument_array_size < parameter_array_size)
				{
					compiler_set_error_with_token(C_ARGUMENT_SIZE_SMALLER_THAN_PARAMETER_SIZE, ctx,
						right->first_token,
						" argument of size [%d] is smaller than parameter of size [%d]", argument_array_size, parameter_array_size);
				}
			}
			else if (is_null_pointer_constant || type_is_nullptr_t(p_right_type))
			{
				compiler_set_error_with_token(C_PASSING_NULL_AS_ARRAY, ctx,
					right->first_token,
					" passing null as array");
			}
			t2 = type_lvalue_conversion(left_type);
		}
		else
		{
			t2 = type_dup(left_type);
		}



		if (!type_is_same(&lvalue_right_type, &t2, false))
		{
			type_print(&lvalue_right_type);
			type_print(&t2);

			compiler_set_error_with_token(C_INCOMPATIBLE_TYPES, ctx,
				right->first_token,
				" incompatible types at argument ");
			//disabled for now util it works correctly
			//return false;
		}

		if (type_is_pointer(&lvalue_right_type) && type_is_pointer(&t2))
		{
			//parameter pointer do non const
			//argument const.
			struct type argument_pointer_to = type_remove_pointer(&lvalue_right_type);
			struct type parameter_pointer_to = type_remove_pointer(&t2);
			if (type_is_const(&argument_pointer_to) && !type_is_const(&parameter_pointer_to))
			{
				compiler_set_error_with_token(C_DISCARDING_CONST_AT_ARGUMENT, ctx,
					right->first_token,
					" discarding const at argument ");
			}
			type_destroy(&argument_pointer_to);
			type_destroy(&parameter_pointer_to);
		}
		//return true;
	}

	if (!type_is_same(left_type, &lvalue_right_type, false))
	{
		//TODO more rules..but it is good to check worst case!
		// 
		//  compiler_set_error_with_token(C1, ctx,
		//      right->first_token,
		//      " incompatible types ");
	}

	check_owner_rules_assigment(ctx,
		left_type,
		right,
		return_assignment);



	type_destroy(&lvalue_right_type);
	type_destroy(&t2);

}

bool type_is_function(const struct type* p_type)
{
	return type_get_category(p_type) == TYPE_CATEGORY_FUNCTION;
}

bool type_is_function_or_function_pointer(const struct type* p_type)
{
	if (type_is_function(p_type))
		return true;

	if (type_is_pointer(p_type))
	{
		//TODO not optimized
		struct type t = type_remove_pointer(p_type);
		bool r = type_is_function(&t);
		type_destroy(&t);
		return r;
	}

	return false;
}

struct type type_add_pointer(const struct type* p_type)
{
	struct type r = type_dup(p_type);

	struct type* owner p = calloc(1, sizeof(struct type));
	*p = r;
	r = (struct type){ 0 };
	r.next = p;
	r.category = TYPE_CATEGORY_POINTER;

	r.storage_class_specifier_flags = p_type->storage_class_specifier_flags;

	return r;
}

struct type type_remove_pointer(const struct type* p_type)
{
	assert(type_is_pointer(p_type));

	struct type r = type_dup(p_type);

	assert(r.next);
	if (r.next)
	{
		struct type next = *r.next;
		/*
		  we have moved the contents of r.next, but we also need to delete it's memory
		*/
		free(r.next);
		r.next = NULL;
		type_destroy_one(&r);
		r = next;
	}

	r.storage_class_specifier_flags = p_type->next->storage_class_specifier_flags;
	r.type_qualifier_flags = p_type->next->type_qualifier_flags;

	return r;
}


struct type get_array_item_type(const struct type* p_type)
{
	struct type r = type_dup(p_type);

	struct type r2 = *r.next;

	free(r.next);
	free((void* owner) r.name_opt);
	param_list_destroy(&r.params);

	return r2;
}

struct type type_param_array_to_pointer(const struct type* p_type)
{
	assert(type_is_array(p_type));
	struct type t = get_array_item_type(p_type);
	struct type t2 = type_add_pointer(&t);

	if (p_type->type_qualifier_flags & TYPE_QUALIFIER_CONST)
	{
		/*
		 void F(int a[static const 5]) {
		  static_assert((typeof(a)) == (int* const));
		}
		*/
		t2.type_qualifier_flags |= TYPE_QUALIFIER_CONST;
	}

	type_destroy(&t);
	t2.storage_class_specifier_flags &= ~STORAGE_SPECIFIER_PARAMETER;

	return t2;
}

bool type_is_pointer_or_array(const struct type* p_type)
{
	const enum type_category category = type_get_category(p_type);

	if (category == TYPE_CATEGORY_POINTER ||
		category == TYPE_CATEGORY_ARRAY)
		return true;

	if (category == TYPE_CATEGORY_ITSELF &&
		p_type->type_specifier_flags == TYPE_SPECIFIER_NULLPTR_T)
	{
		return true;
	}

	return false;
}


//See 6.3.1.1
int type_get_rank(struct type* p_type1)
{
	if (type_is_pointer_or_array(p_type1))
	{
		return 40;
	}

	int rank = 0;
	if ((p_type1->type_specifier_flags & TYPE_SPECIFIER_BOOL))
	{
		rank = 10;
	}
	else if ((p_type1->type_specifier_flags & TYPE_SPECIFIER_CHAR) ||
		(p_type1->type_specifier_flags & TYPE_SPECIFIER_INT8))
	{
		rank = 20;
	}
	else if ((p_type1->type_specifier_flags & TYPE_SPECIFIER_SHORT) ||
		(p_type1->type_specifier_flags & TYPE_SPECIFIER_INT16))
	{
		rank = 30;
	}
	else if ((p_type1->type_specifier_flags & TYPE_SPECIFIER_INT) ||
		(p_type1->type_specifier_flags & TYPE_SPECIFIER_ENUM))
	{
		rank = 40;
	}
	else if ((p_type1->type_specifier_flags & TYPE_SPECIFIER_LONG) ||
		(p_type1->type_specifier_flags & TYPE_SPECIFIER_INT32))
	{
		rank = 50;
	}
	else if ((p_type1->type_specifier_flags & TYPE_SPECIFIER_NULLPTR_T))
	{
		rank = 50; //?
	}
	else if ((p_type1->type_specifier_flags & TYPE_SPECIFIER_FLOAT))
	{
		rank = 60;
	}
	else if ((p_type1->type_specifier_flags & TYPE_SPECIFIER_DOUBLE))
	{
		rank = 70;
	}
	else if ((p_type1->type_specifier_flags & TYPE_SPECIFIER_LONG_LONG) ||
		(p_type1->type_specifier_flags & TYPE_SPECIFIER_INT64))
	{
		rank = 80;
	}
	else if ((p_type1->type_specifier_flags & TYPE_SPECIFIER_STRUCT_OR_UNION))
	{
		return -1;
		//seterror(error, "internal error - struct is not valid for rank");
	}
	else
	{
		return -2;
		//seterror(error, "unexpected type for rank");
	}
	return rank;
}

int type_common(struct type* p_type1, struct type* p_type2, struct type* out_type)
{
	struct type t0 = { 0 };
	try
	{
		int rank_left = type_get_rank(p_type1);
		if (rank_left < 0) throw;

		int rank_right = type_get_rank(p_type2);
		if (rank_right < 0) throw;

		if (rank_left >= rank_right)
			t0 = type_dup(p_type1);
		else
			t0 = type_dup(p_type2);

		/*
		   The result of expression +,- * / etc are not lvalue
		*/

	}
	catch
	{
		return 1;
	}

	type_swap(out_type, &t0);
	type_destroy(&t0);

	return 0;
}

void type_set(struct type* a, const struct type* b)
{
	struct type t = type_dup(b);
	type_swap(&t, a);
	type_destroy(&t);
}

struct type type_dup(const struct type* p_type)
{
	struct type_list l = { 0 };
	const struct type* p = p_type;
	while (p)
	{
		struct type* owner p_new = calloc(1, sizeof(struct type));
		*p_new = *p;

		//actually I was not the owner of p_new->next
		static_set(p_new->next, "uninitialized");
		p_new->next = NULL;

		if (p->name_opt)
		{
			//actually p_new->name_opt was not mine..
			static_set(p_new->name_opt, "uninitialized");
			p_new->name_opt = strdup(p->name_opt);
		}

		if (p->category == TYPE_CATEGORY_FUNCTION)
		{
			//actually p_new->params.head  p_new->params.tail and was not mine..
			static_set(p_new->params.head, "uninitialized");
			p_new->params.head = NULL;
			static_set(p_new->params.tail, "uninitialized");
			p_new->params.tail = NULL;

			struct param* p_param = p->params.head;
			while (p_param)
			{
				struct param* owner p_new_param = calloc(1, sizeof * p_new_param);
				p_new_param->type = type_dup(&p_param->type);

				LIST_ADD(&p_new->params, p_new_param);
				p_param = p_param->next;
			}
		}

		type_list_push_back(&l, p_new);
		p = p->next;
	}

	struct type r = *l.head;
	/*
	   we have moved the content of l.head
	   but we also need to delete the memory
	*/
	free(l.head);

	return r;
}


int type_get_array_size(const struct type* p_type)
{
	return p_type->array_size;
}


int type_set_array_size(struct type* p_type, int size)
{
	p_type->array_size = size;
	return 0;
}
int type_get_num_members(const struct type* type);
int type_get_struct_num_members(struct struct_or_union_specifier* complete_struct_or_union_specifier)
{
	int count = 0;
	struct member_declaration* d = complete_struct_or_union_specifier->member_declaration_list.head;
	while (d)
	{
		if (d->member_declarator_list_opt)
		{
			struct member_declarator* md = d->member_declarator_list_opt->head;
			while (md)
			{
				count += 1;
				md = md->next;
			}
		}
		d = d->next;
	}

	return count;
}

int type_get_sizeof(const struct type* p_type);
int get_sizeof_struct(struct struct_or_union_specifier* complete_struct_or_union_specifier)
{
	int maxalign = 0;
	int size = 0;
	struct member_declaration* d = complete_struct_or_union_specifier->member_declaration_list.head;
	while (d)
	{
		if (d->member_declarator_list_opt)
		{
			struct member_declarator* md = d->member_declarator_list_opt->head;
			while (md)
			{
				int align = type_get_alignof(&md->declarator->type);

				if (align > maxalign)
				{
					maxalign = align;
				}
				if (size % align != 0)
				{
					size += align - (size % align);
				}

				size += type_get_sizeof(&md->declarator->type);
				md = md->next;
			}
		}
		else
		{
			if (d->specifier_qualifier_list->struct_or_union_specifier)
			{
				struct type t = { 0 };
				t.category = TYPE_CATEGORY_ITSELF;
				t.struct_or_union_specifier = d->specifier_qualifier_list->struct_or_union_specifier;
				t.type_specifier_flags = TYPE_SPECIFIER_STRUCT_OR_UNION;

				int align = type_get_alignof(&t);

				if (align > maxalign)
				{
					maxalign = align;
				}
				if (size % align != 0)
				{
					size += align - (size % align);
				}
				size += type_get_sizeof(&t);
				type_destroy(&t);
			}
		}
		d = d->next;
	}
	if (maxalign != 0)
	{
		if (size % maxalign != 0)
		{
			size += maxalign - (size % maxalign);
		}
	}
	else
	{
		assert(false);
	}

	return size;
}
int type_get_alignof(const struct type* p_type);
int get_alignof_struct(struct struct_or_union_specifier* complete_struct_or_union_specifier)
{
	int align = 0;
	struct member_declaration* d = complete_struct_or_union_specifier->member_declaration_list.head;
	while (d)
	{
		if (d->member_declarator_list_opt)
		{
			struct member_declarator* md = d->member_declarator_list_opt->head;
			while (md)
			{
				//TODO padding
				int temp_align = type_get_alignof(&md->declarator->type);
				if (temp_align > align)
				{
					align = temp_align;
				}
				md = md->next;
			}
		}
		else
		{
			/*We don't have the declarator like in */
			/*
			  struct X {
				union {
					struct {
						int Zone;
					};
					int Value;
				};
			};
			static_assert(alignof(struct X) == 1);
			*/

			/*so we create a type using only specifiers*/

			struct type type = { 0 };
			if (d->specifier_qualifier_list)
			{
				type.type_specifier_flags =
					d->specifier_qualifier_list->type_specifier_flags;

				type.enum_specifier = d->specifier_qualifier_list->enum_specifier;
				type.struct_or_union_specifier = d->specifier_qualifier_list->struct_or_union_specifier;

			}

			int temp_align = type_get_alignof(&type);
			if (temp_align > align)
			{
				align = temp_align;
			}

			type_destroy(&type);
		}
		d = d->next;
	}
	assert(align != 0);
	return align;
}

int type_get_alignof(const struct type* p_type)
{
	int align = 0;

	enum type_category category = type_get_category(p_type);

	if (category == TYPE_CATEGORY_POINTER)
	{
		align = _Alignof(void*);
	}
	else if (category == TYPE_CATEGORY_FUNCTION)
	{
		align = -1;
		//seterror(error, "sizeof function");
	}
	else if (category == TYPE_CATEGORY_ITSELF)
	{
		if (p_type->type_specifier_flags & TYPE_SPECIFIER_CHAR)
		{
			align = _Alignof(char);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_BOOL)
		{
			align = _Alignof(_Bool);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_SHORT)
		{
			align = _Alignof(short);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_INT)
		{
			align = _Alignof(int);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_ENUM)
		{
			//TODO enum type
			align = _Alignof(int);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_LONG)
		{
			align = _Alignof(long);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_LONG_LONG)
		{
			align = _Alignof(long long);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_INT64)
		{
			align = _Alignof(long long);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_INT32)
		{
			align = _Alignof(long);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_INT16)
		{
			align = _Alignof(short);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_INT8)
		{
			align = _Alignof(char);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_FLOAT)
		{
			align = _Alignof(float);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_DOUBLE)
		{
			align = _Alignof(double);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_STRUCT_OR_UNION)
		{
			struct struct_or_union_specifier* p_complete =
				get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

			align = 1;
			if (p_complete)
			{
				align = get_alignof_struct(p_complete);
			}
			else
			{
				align = -2;
				//seterror(error, "invalid application of 'sizeof' to incomplete type 'struct %s'", p_type->struct_or_union_specifier->tag_name);
			}
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_ENUM)
		{
			align = _Alignof(int);
		}
		else if (p_type->type_specifier_flags == TYPE_SPECIFIER_NONE)
		{
			align = -3;
			//seterror(error, "type information is missing");
		}
		else if (p_type->type_specifier_flags == TYPE_SPECIFIER_VOID)
		{
			align = 1;
		}
		else
		{
			assert(false);
		}
	}
	else if (category == TYPE_CATEGORY_ARRAY)
	{

		struct type type = get_array_item_type(p_type);
		align = type_get_alignof(&type);
		type_destroy(&type);
	}
	assert(align > 0);
	return align;
}

int type_get_num_members(const struct type* p_type)
{
	enum type_category category = type_get_category(p_type);

	if (category == TYPE_CATEGORY_POINTER)
	{
		return 0;
	}
	else if (category == TYPE_CATEGORY_FUNCTION)
	{
		return 0;
	}
	else if (category == TYPE_CATEGORY_ITSELF)
	{
		if (p_type->type_specifier_flags & TYPE_SPECIFIER_STRUCT_OR_UNION)
		{
			struct struct_or_union_specifier* p_complete =
				get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);


			if (p_complete)
			{
				return type_get_struct_num_members(p_complete);
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else if (category == TYPE_CATEGORY_ARRAY)
	{
		//int arraysize = type_get_array_size(p_type);
		//struct type type = get_array_item_type(p_type);
		//int sz = type_get_sizeof(&type);
		//size = sz * arraysize;
		//type_destroy(&type);
		//assert(false);
		return 1;
	}
	return 0;
}

int type_get_sizeof(const struct type* p_type)
{
	int size = 0;

	enum type_category category = type_get_category(p_type);

	if (category == TYPE_CATEGORY_POINTER)
	{
		size = (int)sizeof(void*);
	}
	else if (category == TYPE_CATEGORY_FUNCTION)
	{
		size = -1;
		//seterror(error, "sizeof function");
	}
	else if (category == TYPE_CATEGORY_ITSELF)
	{
		if (p_type->type_specifier_flags & TYPE_SPECIFIER_CHAR)
		{
			size = (int)sizeof(char);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_BOOL)
		{
			size = (int)sizeof(_Bool);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_SHORT)
		{
			size = (int)sizeof(int);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_INT)
		{
			size = (int)sizeof(int);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_ENUM)
		{
			//TODO enum type
			size = (int)sizeof(int);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_LONG)
		{
			size = (int)sizeof(long);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_LONG_LONG)
		{
			size = (int)sizeof(long long);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_INT64)
		{
			size = (int)sizeof(long long);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_INT32)
		{
			size = 4;
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_INT16)
		{
			size = 2;
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_INT8)
		{
			size = 1;
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_FLOAT)
		{
			size = (int)sizeof(float);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_DOUBLE)
		{
			size = (int)sizeof(double);
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_STRUCT_OR_UNION)
		{
			struct struct_or_union_specifier* p_complete =
				get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

			size = 1;
			if (p_complete)
			{
				size = get_sizeof_struct(p_complete);
			}
			else
			{
				size = -2;
				//seterror(error, "invalid application of 'sizeof' to incomplete type 'struct %s'", p_type->struct_or_union_specifier->tag_name);
			}
		}
		else if (p_type->type_specifier_flags & TYPE_SPECIFIER_ENUM)
		{
			size = (int)sizeof(int);
		}
		else if (p_type->type_specifier_flags == TYPE_SPECIFIER_NONE)
		{
			size = -3;
			//seterror(error, "type information is missing");
		}
		else if (p_type->type_specifier_flags == TYPE_SPECIFIER_VOID)
		{
			size = 1;
		}
		else
		{
			assert(false);
		}
	}
	else if (category == TYPE_CATEGORY_ARRAY)
	{
		int arraysize = type_get_array_size(p_type);
		struct type type = get_array_item_type(p_type);
		int sz = type_get_sizeof(&type);
		size = sz * arraysize;
		type_destroy(&type);
	}

	return size;
}

unsigned int type_get_hashof(struct parser_ctx* ctx, struct type* p_type)
{
	unsigned int hash = 0;
	if (type_is_struct_or_union(p_type))
	{
		struct osstream ss = { 0 };
		struct struct_or_union_specifier* p_complete =
			p_type->struct_or_union_specifier->complete_struct_or_union_specifier_indirection;
		if (p_complete)
		{
			struct token* current = p_complete->first_token;
			for (;
				current != p_complete->last_token->next;
				current = current->next)
			{
				if (current->flags & TK_FLAG_FINAL)
				{
					ss_fprintf(&ss, "%s", current->lexeme);

				}
			}
		}

		hash = string_hash(ss.c_str);
		ss_close(&ss);
	}
	else if (type_is_enum(p_type))
	{
		struct osstream ss = { 0 };

		struct enum_specifier* p_complete =
			p_type->enum_specifier->complete_enum_specifier;


		if (p_complete)
		{
			//struct token* current = p_complete->first_token;
		   // for (;
			 //   current != p_complete->last_token->next;
			   // current = current->next)
			//{
			  //  if (current->flags & TK_FLAG_FINAL)
				//{
				  //  ss_fprintf(&ss, "%s", current->lexeme);
//
  //              }
	//        }
		}

		hash = string_hash(ss.c_str);
		ss_close(&ss);
	}

	return hash;
}


void type_set_attributes(struct type* p_type, struct declarator* pdeclarator)
{
	if (pdeclarator->declaration_specifiers)
	{
		p_type->attributes_flags =
			pdeclarator->declaration_specifiers->attributes_flags;
	}
	else if (pdeclarator->specifier_qualifier_list)
	{
		//p_type->type_qualifier_flags =
		  //  pdeclarator->specifier_qualifier_list->ATR;
	}
}







struct type make_type_using_declarator(struct parser_ctx* ctx, struct declarator* pdeclarator);


#if 0    
/*this sample is useful to try in compiler explorer*/


#include <typeinfo>


#include <cxxabi.h>

int status;
#define TYPE(EXPR) \
 printf("%s=", #EXPR); \
 printf("%s\n", abi::__cxa_demangle(typeid(typeof(EXPR)).name(),0,0,&status))


typedef char* T1;
typedef const T1 CONST_T1;
typedef CONST_T1 T2[5];
typedef T2 T3[2];

int main()
{
	TYPE(T1);
}
#endif
/*

typedef char *T;
T a[2]; //char * [2]

typedef char *T[1];
T a[2]; // char* [2][1]

typedef char (*PF)(void);
PF a[2]; //char (* [2])()

typedef char *T;
T (*a)(void); //char* (*)()

typedef char const *T;
T (*a)(void); //char const* (*)()

typedef char (*PF)(void);
	PF (*a)(void); //char (*(*)())()

typedef char (*PF)(double);
	PF (*a)(int); //char (*(*)(int))(double)

 typedef char (*PF)(double);
 const PF (*a)(int); //char (* const (*)(int))(double)

*/




struct type get_function_return_type(const struct type* p_type)
{

	if (type_is_pointer(p_type))
	{
		/*pointer to function returning ... */
		struct type r = type_dup(p_type->next->next);
		return r;
	}


	/*function returning ... */
	struct type r = type_dup(p_type->next);
	return r;
}


void type_set_int(struct type* p_type)
{
	p_type->type_specifier_flags = TYPE_SPECIFIER_INT;
	p_type->type_qualifier_flags = 0;
	p_type->category = TYPE_CATEGORY_ITSELF;
}

struct type type_make_enumerator(const struct enum_specifier* enum_specifier)
{
	struct type t = { 0 };
	t.type_specifier_flags = TYPE_SPECIFIER_ENUM;
	t.enum_specifier = enum_specifier;
	t.category = TYPE_CATEGORY_ITSELF;
	return t;
}
struct type type_get_enum_type(const struct type* p_type)
{
	assert(p_type->enum_specifier != NULL);

	if (p_type->enum_specifier->complete_enum_specifier &&
		p_type->enum_specifier->complete_enum_specifier->specifier_qualifier_list)
	{
		struct type t = { 0 };
		t.type_qualifier_flags = p_type->enum_specifier->complete_enum_specifier->specifier_qualifier_list->type_qualifier_flags;
		t.type_specifier_flags = p_type->enum_specifier->complete_enum_specifier->specifier_qualifier_list->type_specifier_flags;
		return t;
	}

	struct type t = { 0 };
	t.type_specifier_flags = TYPE_SPECIFIER_INT;
	return t;
}

struct type type_make_size_t()
{
	struct type t = { 0 };

#ifdef _WIN64
	t.type_specifier_flags = TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_INT64;
#else
	t.type_specifier_flags = TYPE_SPECIFIER_UNSIGNED | TYPE_SPECIFIER_INT;
#endif

	t.category = TYPE_CATEGORY_ITSELF;
	return t;
}

struct type make_void_ptr_type()
{
	struct type t = { 0 };
	t.category = TYPE_CATEGORY_POINTER;

	struct type* owner p = calloc(1, sizeof * p);
	p->category = TYPE_CATEGORY_ITSELF;
	p->type_specifier_flags = TYPE_SPECIFIER_VOID;
	t.next = p;

	return t;
}

struct type make_void_type()
{
	struct type t = { 0 };
	t.type_specifier_flags = TYPE_SPECIFIER_VOID;
	t.category = TYPE_CATEGORY_ITSELF;
	return t;
}

struct type type_make_int_bool_like()
{
	struct type t = { 0 };
	t.type_specifier_flags = TYPE_SPECIFIER_INT;
	t.attributes_flags = CAKE_HIDDEN_ATTRIBUTE_LIKE_BOOL;
	t.category = TYPE_CATEGORY_ITSELF;
	return t;
}

struct type type_make_int()
{
	struct type t = { 0 };
	t.type_specifier_flags = TYPE_SPECIFIER_INT;
	t.category = TYPE_CATEGORY_ITSELF;
	return t;
}

struct type type_make_literal_string(int size, enum type_specifier_flags chartype)
{
	struct type t = { 0 };
	t.category = TYPE_CATEGORY_ARRAY;
	t.array_size = size;

	struct type* owner p2 = calloc(1, sizeof(struct type));
	p2->category = TYPE_CATEGORY_ITSELF;
	p2->type_specifier_flags = chartype;
	t.next = p2;
	return t;
}

bool struct_or_union_specifier_is_same(struct struct_or_union_specifier* a, struct struct_or_union_specifier* b)
{
	if (a && b)
	{
		struct struct_or_union_specifier* p_complete_a = get_complete_struct_or_union_specifier(a);
		struct struct_or_union_specifier* p_complete_b = get_complete_struct_or_union_specifier(b);

		if (p_complete_a != NULL && p_complete_b != NULL)
		{
			if (p_complete_a != p_complete_b)
			{
				return false;
			}
			return true;
		}
		else
		{
			/*both incomplete then we compare tag names*/
			if (a->tagtoken != NULL && b->tagtoken != NULL)
			{
				if (strcmp(a->tagtoken->lexeme, b->tagtoken->lexeme) == 0)
					return true;
			}
		}
		return p_complete_a == NULL && p_complete_b == NULL;
	}
	return a == NULL && b == NULL;
}

bool enum_specifier_is_same(struct enum_specifier* a, struct enum_specifier* b)
{
	if (a && b)
	{
		if (a->complete_enum_specifier && b->complete_enum_specifier)
		{
			if (a->complete_enum_specifier != b->complete_enum_specifier)
				return false;
			return true;
		}
		return a->complete_enum_specifier == NULL &&
			b->complete_enum_specifier == NULL;
	}
	return a == NULL && b == NULL;
}




bool type_is_same(const struct type* a, const struct type* b, bool compare_qualifiers)
{
	const struct type* pa = a;
	const struct type* pb = b;


	while (pa && pb)
	{


		if (pa->array_size != pb->array_size) return false;

		if (pa->category != pb->category) return false;

		if (pa->enum_specifier &&
			pb->enum_specifier &&
			pa->enum_specifier->complete_enum_specifier !=
			pb->enum_specifier->complete_enum_specifier)
		{
			return false;
		}


		if (pa->enum_specifier && !pb->enum_specifier)
		{
			//TODO enum with types
			//enum  x int
		   //return false;
		}

		if (!pa->enum_specifier && pb->enum_specifier)
		{
			//TODO enum with types
			//int x enum
			//return false;
		}

		//if (pa->name_opt != pb->name_opt) return false;
		if (pa->static_array != pb->static_array) return false;

		if (pa->category == TYPE_CATEGORY_FUNCTION)
		{

			if (pa->params.is_var_args != pb->params.is_var_args)
			{
				return false;
			}

			if (pa->params.is_void != pb->params.is_void)
			{
				return false;
			}

			struct param* p_param_a = pa->params.head;
			struct param* p_param_b = pb->params.head;
			while (p_param_a && p_param_b)
			{
				if (!type_is_same(&p_param_a->type, &p_param_b->type, true))
				{
					return false;
				}
				p_param_a = p_param_a->next;
				p_param_b = p_param_b->next;
			}
			return p_param_a == NULL && p_param_b == NULL;
		}

		if (pa->struct_or_union_specifier &&
			pb->struct_or_union_specifier)
		{

			if (pa->struct_or_union_specifier->complete_struct_or_union_specifier_indirection !=
				pb->struct_or_union_specifier->complete_struct_or_union_specifier_indirection)
			{
				//this should work but it is not... 
			}

			if (strcmp(pa->struct_or_union_specifier->tag_name, pb->struct_or_union_specifier->tag_name) != 0)
			{
				return false;
			}
		}

		if (compare_qualifiers && pa->type_qualifier_flags != pb->type_qualifier_flags)
		{
			return false;
		}

		if (pa->type_specifier_flags != pb->type_specifier_flags)
		{
			return false;
		}


		pa = pa->next;
		pb = pb->next;
	}
	return pa == NULL && pb == NULL;
}


void type_swap(view struct type* a, view struct type* b)
{
	view struct type temp = *a;
	*a = *b;
	*b = temp;
}


void type_visit_to_mark_anonymous(struct type* p_type)
{
	//TODO better visit?
	if (p_type->struct_or_union_specifier != NULL &&
		p_type->struct_or_union_specifier->has_anonymous_tag)
	{
		if (p_type->struct_or_union_specifier->complete_struct_or_union_specifier_indirection)
		{
			p_type->struct_or_union_specifier->complete_struct_or_union_specifier_indirection->show_anonymous_tag = true;
		}
		p_type->struct_or_union_specifier->show_anonymous_tag = true;
	}

}


void type_merge_qualifiers_using_declarator(struct type* p_type, struct declarator* pdeclarator)
{

	enum type_qualifier_flags type_qualifier_flags = 0;
	if (pdeclarator->declaration_specifiers)
	{
		type_qualifier_flags = pdeclarator->declaration_specifiers->type_qualifier_flags;

	}
	else if (pdeclarator->specifier_qualifier_list)
	{
		type_qualifier_flags = pdeclarator->specifier_qualifier_list->type_qualifier_flags;

	}

	p_type->type_qualifier_flags |= type_qualifier_flags;




}


void type_set_qualifiers_using_declarator(struct type* p_type, struct declarator* pdeclarator)
{

	enum type_qualifier_flags type_qualifier_flags = 0;
	if (pdeclarator->declaration_specifiers)
	{
		type_qualifier_flags = pdeclarator->declaration_specifiers->type_qualifier_flags;

	}
	else if (pdeclarator->specifier_qualifier_list)
	{
		type_qualifier_flags = pdeclarator->specifier_qualifier_list->type_qualifier_flags;

	}

	p_type->type_qualifier_flags = type_qualifier_flags;



}

void type_set_storage_specifiers_using_declarator(struct type* p_type, struct declarator* pdeclarator)
{
	if (pdeclarator->declaration_specifiers)
	{
		p_type->storage_class_specifier_flags |=
			pdeclarator->declaration_specifiers->storage_class_specifier_flags;
	}
	else
	{
		//struct member
		//assert(false);
		/*
		   where we don't have specifiers?
		*/
		//p_type->storage_class_specifier_flags |= STORAGE_SPECIFIER_AUTO;
	}
}


void type_set_specifiers_using_declarator(struct type* p_type, struct declarator* pdeclarator)
{
	if (pdeclarator->declaration_specifiers)
	{
		p_type->type_specifier_flags =
			pdeclarator->declaration_specifiers->type_specifier_flags;

		p_type->enum_specifier = pdeclarator->declaration_specifiers->enum_specifier;
		p_type->struct_or_union_specifier = pdeclarator->declaration_specifiers->struct_or_union_specifier;

	}
	else if (pdeclarator->specifier_qualifier_list)
	{
		p_type->type_specifier_flags =
			pdeclarator->specifier_qualifier_list->type_specifier_flags;
		p_type->enum_specifier = pdeclarator->specifier_qualifier_list->enum_specifier;
		p_type->struct_or_union_specifier = pdeclarator->specifier_qualifier_list->struct_or_union_specifier;

	}


}

void type_set_attributes_using_declarator(struct type* p_type, struct declarator* pdeclarator)
{
	if (pdeclarator->declaration_specifiers)
	{
		if (pdeclarator->declaration_specifiers->attributes_flags & STD_ATTRIBUTE_NODISCARD)
		{
			p_type->storage_class_specifier_flags |= STORAGE_SPECIFIER_FUNCTION_RETURN_NODISCARD;
		}
		p_type->attributes_flags =
			pdeclarator->declaration_specifiers->attributes_flags;
	}
	else if (pdeclarator->specifier_qualifier_list)
	{
		//p_type->attributes_flags =
		  //  pdeclarator->specifier_qualifier_list->attributes_flags;
	}
}


void type_list_push_front(struct type_list* books, struct type* owner new_book)
{
	assert(books != NULL);
	assert(new_book != NULL);
	assert(new_book->next == NULL);

	if (books->head == NULL)
	{
		books->head = new_book;
		books->tail = new_book;
	}
	else
	{
		new_book->next = books->head;
		books->head = new_book;
	}
}


void type_list_push_back(struct type_list* type_list, struct type* owner new_book)
{
	assert(type_list != NULL);
	assert(new_book != NULL);

	if (type_list->tail == NULL)
	{
		assert(type_list->head == NULL);
		type_list->head = new_book;
	}
	else
	{
		assert(type_list->tail->next == NULL);
		type_list->tail->next = new_book;
	}

	type_list->tail = new_book;
}

void make_type_using_declarator_core(struct parser_ctx* ctx, struct declarator* pdeclarator, char** ppname, struct type_list* list);

void  make_type_using_direct_declarator(struct parser_ctx* ctx,
	struct direct_declarator* pdirectdeclarator,
	char** ppname,
	struct type_list* list)
{
	if (pdirectdeclarator->declarator)
	{
		make_type_using_declarator_core(ctx, pdirectdeclarator->declarator, ppname, list);
	}

	else if (pdirectdeclarator->function_declarator)
	{
		if (pdirectdeclarator->function_declarator->direct_declarator)
		{
			make_type_using_direct_declarator(ctx,
				pdirectdeclarator->function_declarator->direct_declarator,
				ppname,
				list);
		}

		struct type* owner p_func = calloc(1, sizeof(struct type));
		p_func->category = TYPE_CATEGORY_FUNCTION;


		if (pdirectdeclarator->function_declarator->parameter_type_list_opt &&
			pdirectdeclarator->function_declarator->parameter_type_list_opt->parameter_list)
		{

			struct parameter_declaration* p =
				pdirectdeclarator->function_declarator->parameter_type_list_opt->parameter_list->head;

			p_func->params.is_var_args = pdirectdeclarator->function_declarator->parameter_type_list_opt->is_var_args;
			p_func->params.is_void = pdirectdeclarator->function_declarator->parameter_type_list_opt->is_void;

			while (p)
			{
				struct param* owner p_new_param = calloc(1, sizeof(struct param));
				p_new_param->type = type_dup(&p->declarator->type);
				LIST_ADD(&p_func->params, p_new_param);
				p = p->next;
			}
		}


		type_list_push_back(list, p_func);
	}
	else if (pdirectdeclarator->array_declarator)
	{

		if (pdirectdeclarator->array_declarator->direct_declarator)
		{
			make_type_using_direct_declarator(ctx,
				pdirectdeclarator->array_declarator->direct_declarator,
				ppname,
				list);
		}

		struct type* owner p = calloc(1, sizeof(struct type));
		p->category = TYPE_CATEGORY_ARRAY;

		p->array_size =
			(int)array_declarator_get_size(pdirectdeclarator->array_declarator);


		if (pdirectdeclarator->array_declarator->static_token_opt)
		{
			p->static_array = true;
		}

		if (pdirectdeclarator->array_declarator->type_qualifier_list_opt)
		{
			p->type_qualifier_flags = pdirectdeclarator->array_declarator->type_qualifier_list_opt->flags;
		}

		type_list_push_back(list, p);

		// if (pdirectdeclarator->name_opt)
		 //{
		   //  p->name_opt = strdup(pdirectdeclarator->name_opt->lexeme);
		 //}
	}

	if (pdirectdeclarator->name_opt)
	{
		*ppname = pdirectdeclarator->name_opt->lexeme;
	}


}

void make_type_using_declarator_core(struct parser_ctx* ctx, struct declarator* pdeclarator,
	char** ppname, struct type_list* list)
{
	struct type_list pointers = { 0 };
	struct pointer* pointer = pdeclarator->pointer;
	while (pointer)
	{
		struct type* owner p_flat = calloc(1, sizeof(struct type));

		if (pointer->type_qualifier_list_opt)
		{
			p_flat->type_qualifier_flags = pointer->type_qualifier_list_opt->flags;
		}

		if (pointer->attribute_specifier_sequence_opt)
		{
			p_flat->attributes_flags |= pointer->attribute_specifier_sequence_opt->attributes_flags;
		}
		p_flat->category = TYPE_CATEGORY_POINTER;
		type_list_push_front(&pointers, p_flat); /*invertido*/
		pointer = pointer->pointer;
	}

	if (pdeclarator->direct_declarator)
	{
		make_type_using_direct_declarator(ctx, pdeclarator->direct_declarator, ppname, list);
		if (list->head &&
			list->head->category == TYPE_CATEGORY_FUNCTION)
		{
			if (pointers.head)
			{
				pointers.head->storage_class_specifier_flags |= STORAGE_SPECIFIER_FUNCTION_RETURN;
			}
		}
	}

	while (pointers.head)
	{
		struct type* owner p = pointers.head;
		pointers.head = p->next;
		p->next = NULL;
		type_list_push_back(list, p);
	}

}

struct enum_specifier* declarator_get_enum_specifier(struct declarator* pdeclarator)
{
	if (pdeclarator->declaration_specifiers &&
		pdeclarator->declaration_specifiers->enum_specifier)
	{
		return pdeclarator->declaration_specifiers->enum_specifier;
	}
	if (pdeclarator->specifier_qualifier_list &&
		pdeclarator->specifier_qualifier_list->enum_specifier)
	{
		return pdeclarator->specifier_qualifier_list->enum_specifier;
	}
	return NULL;
}


struct struct_or_union_specifier* declarator_get_struct_or_union_specifier(struct declarator* pdeclarator)
{
	if (pdeclarator->declaration_specifiers &&
		pdeclarator->declaration_specifiers->struct_or_union_specifier)
	{
		return pdeclarator->declaration_specifiers->struct_or_union_specifier;
	}
	if (pdeclarator->specifier_qualifier_list &&
		pdeclarator->specifier_qualifier_list->struct_or_union_specifier)
	{
		return pdeclarator->specifier_qualifier_list->struct_or_union_specifier;
	}
	return NULL;
}

struct typeof_specifier* declarator_get_typeof_specifier(struct declarator* pdeclarator)
{
	if (pdeclarator->declaration_specifiers)
	{
		return pdeclarator->declaration_specifiers->typeof_specifier;
	}
	else if (pdeclarator->specifier_qualifier_list)
	{
		return pdeclarator->specifier_qualifier_list->typeof_specifier;
	}
	return NULL;
}

struct declarator* declarator_get_typedef_declarator(struct declarator* pdeclarator)
{
	if (pdeclarator->declaration_specifiers)
	{
		return pdeclarator->declaration_specifiers->typedef_declarator;
	}
	else if (pdeclarator->specifier_qualifier_list)
	{
		return pdeclarator->specifier_qualifier_list->typedef_declarator;
	}

	return NULL;
}

struct type make_type_using_declarator(struct parser_ctx* ctx, struct declarator* pdeclarator)
{
	struct type_list list = { 0 };
	char* name = 0;
	make_type_using_declarator_core(ctx, pdeclarator, &name, &list);

	//type_print(list.head);

	if (declarator_get_typeof_specifier(pdeclarator))
	{
		struct type nt =
			type_dup(&declarator_get_typeof_specifier(pdeclarator)->type);

		struct type* owner p_nt = calloc(1, sizeof(struct type));
		*p_nt = nt;

		bool head = list.head != NULL;

		if (head)
			type_set_qualifiers_using_declarator(list.head, pdeclarator);

		if (list.tail)
		{
			assert(list.tail->next == NULL);
			list.tail->next = p_nt;
		}
		else
		{
			type_list_push_back(&list, p_nt);
		}
	}
	else if (declarator_get_typedef_declarator(pdeclarator))
	{
		struct declarator* p_typedef_declarator =
			declarator_get_typedef_declarator(pdeclarator);

		struct type nt =
			type_dup(&p_typedef_declarator->type);

		struct type* owner p_nt = calloc(1, sizeof(struct type));
		*p_nt = nt;


		/*
		  maybe typedef already has const qualifier
		  so we cannot override
		*/
		type_merge_qualifiers_using_declarator(p_nt, pdeclarator);

		if (list.tail)
		{
			assert(list.tail->next == 0);
			list.tail->next = p_nt;
		}
		else
		{
			type_list_push_back(&list, p_nt);
		}
	}
	else
	{
		struct type* owner p = calloc(1, sizeof(struct type));
		p->category = TYPE_CATEGORY_ITSELF;


		type_set_specifiers_using_declarator(p, pdeclarator);
		type_set_attributes_using_declarator(p, pdeclarator);


		type_set_qualifiers_using_declarator(p, pdeclarator);

		if (list.tail &&
			list.tail->category == TYPE_CATEGORY_FUNCTION)
		{
			p->storage_class_specifier_flags |= STORAGE_SPECIFIER_FUNCTION_RETURN;
		}



		type_list_push_back(&list, p);

		type_set_storage_specifiers_using_declarator(list.head, pdeclarator);


		//if (name)
		//{
		  //  if (list.head->name_opt == NULL)
			//{
			  //  list.head->name_opt = strdup(name);
			//}
		//}
		//type_set_qualifiers_using_declarator(list.tail, pdeclarator);
	}


	//type_set_qualifiers_using_declarator(list.head, pdeclarator);


#if 0
	if (list.head->category == TYPE_CATEGORY_FUNCTION)
	{
		if (list.head->next)
		{
			if (!type_is_void(list.head->next))
			{
				list.head->next->attributes_flags |= CAKE_HIDDEN_ATTRIBUTE_FUNC_RESULT;
			}
		}
	}
#endif

	if (pdeclarator->name)
	{
		free((void* owner) list.head->name_opt);
		list.head->name_opt = strdup(pdeclarator->name->lexeme);
	}

	struct type r = *list.head;
	/*
	  we moved the contents of head
	  but we also need to delete the memory
	*/
	free(list.head);
	return r;
}

void type_remove_names(struct type* p_type)
{
	/*
	  function parameters names are preserved
	*/
	struct type* p = p_type;

	while (p)
	{
		if (p->name_opt)
		{
			free((void* owner) p->name_opt);
			p->name_opt = NULL;
		}
		p = p->next;
	}
}

const struct type* type_get_specifer_part(const struct type* p_type)
{
	/*
	 last part is the specifier
	*/
	const struct type* p = p_type;
	while (p->next) p = p->next;
	return p;
}



#include <stdint.h>


void object_swap(struct object* a, struct object* b)
{
	struct object temp = *a;
	*a = *b;
	*b = temp;
}

void object_delete(struct object* owner p)
{
	if (p)
	{
		object_destroy(p);
		free(p);
	}
}

void object_destroy(struct object* obj_owner p)
{
	object_delete(p->pointed);
	objects_destroy(&p->members);
	object_state_stack_destroy(&p->object_state_stack);
}


void object_state_stack_destroy(struct object_state_stack* obj_owner p)
{
	free(p->data);
}

int object_state_stack_reserve(struct object_state_stack* p, int n) unchecked
{
	if (n > p->capacity)
	{
		if ((size_t)n > (SIZE_MAX / (sizeof(p->data[0]))))
		{
			return EOVERFLOW;
		}

		void* owner pnew = realloc(p->data, n * sizeof(p->data[0]));
		if (pnew == NULL) return ENOMEM;

		p->data = pnew;
		p->capacity = n;
	}
	return 0;
}

int object_state_stack_push_back(struct object_state_stack* p, enum object_state e)
{
	if (p->size == INT_MAX)
	{
		return EOVERFLOW;
	}

	if (p->size + 1 > p->capacity)
	{
		int new_capacity = 0;
		if (p->capacity > (INT_MAX - p->capacity / 2))
		{
			/*overflow*/
			new_capacity = INT_MAX;
		}
		else
		{
			new_capacity = p->capacity + p->capacity / 2;
			if (new_capacity < p->size + 1)
			{
				new_capacity = p->size + 1;
			}
		}

		int error = object_state_stack_reserve(p, new_capacity);
		if (error != 0)
		{
			return error;
		}
	}

	p->data[p->size] = e;
	p->size++;

	return 0;
}

void objects_destroy(struct objects* obj_owner p) unchecked
{
	for (int i = 0; i < p->size; i++)
	{
		object_destroy(&p->data[i]);
	}
	free(p->data);
}

int objects_reserve(struct objects* p, int n) unchecked
{
	if (n > p->capacity)
	{
		if ((size_t)n > (SIZE_MAX / (sizeof(p->data[0]))))
		{
			return EOVERFLOW;
		}

		void* owner pnew = realloc(p->data, n * sizeof(p->data[0]));
		if (pnew == NULL) return ENOMEM;

		p->data = pnew;
		p->capacity = n;
	}
	return 0;
}

int objects_push_back(struct objects* p, struct object* obj_owner p_object)
{
	if (p->size == INT_MAX)
	{
		object_destroy(p_object);
		return EOVERFLOW;
	}

	if (p->size + 1 > p->capacity)
	{
		int new_capacity = 0;
		if (p->capacity > (INT_MAX - p->capacity / 2))
		{
			/*overflow*/
			new_capacity = INT_MAX;
		}
		else
		{
			new_capacity = p->capacity + p->capacity / 2;
			if (new_capacity < p->size + 1)
			{
				new_capacity = p->size + 1;
			}
		}

		int error = objects_reserve(p, new_capacity);
		if (error != 0)
		{
			object_destroy(p_object);
			return error;
		}
	}

	p->data[p->size] = *p_object; /*COPIED*/


	p->size++;

	return 0;
}
struct object_name_list
{
	const char* name;
	struct object_name_list* previous;
};

bool has_name(const char* name, struct object_name_list* list)
{
	struct object_name_list* p = list;

	while (p)
	{
		if (strcmp(p->name, name) == 0)
		{
			return true;
		}
		p = p->previous;
	}
	return false;
}

struct object make_object_core(struct type* p_type, struct object_name_list* list, int deep, const struct declarator* declarator)
{
	struct object obj = { 0 };
	obj.declarator = declarator;

	if (p_type->struct_or_union_specifier)
	{
		struct struct_or_union_specifier* p_struct_or_union_specifier =
			get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

		if (p_struct_or_union_specifier)
		{
			obj.state = OBJECT_STATE_NOT_APPLICABLE;

			struct member_declaration* p_member_declaration =
				p_struct_or_union_specifier->member_declaration_list.head;

			struct object_name_list l = { 0 };
			l.name = p_struct_or_union_specifier->tag_name;
			l.previous = list;
			//int member_index = 0;
			while (p_member_declaration)
			{
				if (p_member_declaration->member_declarator_list_opt)
				{
					struct member_declarator* p_member_declarator =
						p_member_declaration->member_declarator_list_opt->head;

					while (p_member_declarator)
					{
						if (p_member_declarator->declarator)
						{
							char* tag = NULL;
							if (p_member_declarator->declarator->type.struct_or_union_specifier)
							{
								tag = p_member_declarator->declarator->type.struct_or_union_specifier->tag_name;
							}
							else if (p_member_declarator->declarator->type.next &&
								p_member_declarator->declarator->type.next->struct_or_union_specifier)
							{
								tag = p_member_declarator->declarator->type.next->struct_or_union_specifier->tag_name;

							}

							if (tag && has_name(tag, &l))
							{
								struct object member_obj = { 0 };
								member_obj.declarator = declarator;
								member_obj.state = OBJECT_STATE_NOT_APPLICABLE;
								objects_push_back(&obj.members, &member_obj);
							}
							else
							{
								struct object member_obj = make_object_core(&p_member_declarator->declarator->type, &l, deep, declarator);
								objects_push_back(&obj.members, &member_obj);
							}

							//member_index++;
						}
						p_member_declarator = p_member_declarator->next;
					}
				}
				else
				{
					if (p_member_declaration->specifier_qualifier_list->struct_or_union_specifier)
					{
						//struct object obj = {0};
						//obj.state = OBJECT_STATE_STRUCT;
						//objects_push_back(&obj.members, &obj);


						struct type t = { 0 };
						t.category = TYPE_CATEGORY_ITSELF;
						t.struct_or_union_specifier = p_member_declaration->specifier_qualifier_list->struct_or_union_specifier;
						t.type_specifier_flags = TYPE_SPECIFIER_STRUCT_OR_UNION;
						struct object member_obj = make_object_core(&t, &l, deep, declarator);
						objects_push_back(&obj.members, &member_obj);
						type_destroy(&t);
					}
				}
				p_member_declaration = p_member_declaration->next;
			}
		}
	}


	else if (type_is_array(p_type))
	{
		//p_object->state = flags;
		//if (p_object->members_size > 0)
		//{
		//    //not sure if we instanticate all items of array
		//    p_object->members[0].state = flags;
		//}
	}
	else if (type_is_pointer(p_type))
	{
		obj.state = OBJECT_STATE_NOT_APPLICABLE;

		if (deep < 1)
		{
			struct type t2 = type_remove_pointer(p_type);
			if (type_is_struct_or_union(&t2))
			{
				struct object* owner p_object = calloc(1, sizeof(struct object));
				*p_object = make_object_core(&t2, list, deep + 1, declarator);
				obj.pointed = p_object;
			}

			type_destroy(&t2);
			//(*p_deep)++;
		}
	}
	else
	{
		//assert(p_object->members_size == 0);
		//p_object->state = flags;
		obj.state = OBJECT_STATE_NOT_APPLICABLE;
	}

	return obj;
}

struct object make_object(struct type* p_type, const struct declarator* declarator)
{
	assert(declarator);
	struct object_name_list list = { .name = "" };
	return make_object_core(p_type, &list, 0, declarator);
}

void object_push_copy_current_state(struct object* object)
{

	object_state_stack_push_back(&object->object_state_stack, object->state);

	if (object->pointed)
	{
		object_push_copy_current_state(object->pointed);
	}

	for (int i = 0; i < object->members.size; i++)
	{
		object_push_copy_current_state(&object->members.data[i]);
	}

}

void object_pop_states(struct object* object, int n)
{

	if (object->object_state_stack.size < n)
	{
		//assert(false);
		return;
	}

	object->object_state_stack.size =
		object->object_state_stack.size - n;

	if (object->pointed)
	{
		object_pop_states(object->pointed, n);
	}

	for (int i = 0; i < object->members.size; i++)
	{
		object_pop_states(&object->members.data[i], n);
	}

}

void object_restore_state(struct object* object, int state_to_restore)
{
	assert(state_to_restore > 0);

	//0 zero is top of stack
	//1 is the before top
	int index = object->object_state_stack.size - state_to_restore;
	if (index >= 0 && index < object->object_state_stack.size)
	{
	}
	else
	{
		//assert(false);
		return;
	}

	enum object_state sstate = object->object_state_stack.data[index];
	object->state = sstate;

	if (object->pointed)
	{
		object_restore_state(object->pointed, state_to_restore);
	}

	for (int i = 0; i < object->members.size; i++)
	{
		object_restore_state(&object->members.data[i], state_to_restore);
	}
}

void print_object_core(int ident, struct type* p_type, struct object* p_object, const char* previous_names, bool is_pointer, bool short_version)
{
	if (p_object == NULL)
	{
		return;
	}

	if (p_type->struct_or_union_specifier && p_object->members.size > 0)
	{
		struct struct_or_union_specifier* p_struct_or_union_specifier =
			get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

		if (p_struct_or_union_specifier)
		{
			if (p_object == NULL)
			{
				printf("%*c", ident, ' ');
				printf("%s %s\n", previous_names, "-");
				return;
			}
			//obj.state = OBJECT_STATE_STRUCT;

			struct member_declaration* p_member_declaration =
				p_struct_or_union_specifier->member_declaration_list.head;

			int member_index = 0;
			while (p_member_declaration)
			{


				if (p_member_declaration->member_declarator_list_opt)
				{
					struct member_declarator* p_member_declarator =
						p_member_declaration->member_declarator_list_opt->head;
					while (p_member_declarator)
					{
						if (p_member_declarator->declarator)
						{
							const char* name = p_member_declarator->declarator->name ? p_member_declarator->declarator->name->lexeme : "";

							char buffer[200] = { 0 };
							if (is_pointer)
								snprintf(buffer, sizeof buffer, "%s->%s", previous_names, name);
							else
								snprintf(buffer, sizeof buffer, "%s.%s", previous_names, name);


							print_object_core(ident + 1, &p_member_declarator->declarator->type,
								&p_object->members.data[member_index], buffer,
								type_is_pointer(&p_member_declarator->declarator->type), short_version);

							member_index++;
						}
						p_member_declarator = p_member_declarator->next;
					}
				}
				else
				{
					//char buffer[200] = {0};
					//if (is_pointer)
					//  snprintf(buffer, sizeof buffer, "%s", previous_names, "");
					//else
					//  snprintf(buffer, sizeof buffer, "%s", previous_names, "");

					struct type t = { 0 };
					t.category = TYPE_CATEGORY_ITSELF;
					t.struct_or_union_specifier = p_member_declaration->specifier_qualifier_list->struct_or_union_specifier;
					t.type_specifier_flags = TYPE_SPECIFIER_STRUCT_OR_UNION;

					print_object_core(ident + 1, &t, &p_object->members.data[member_index], previous_names, false, short_version);

					member_index++;
					type_destroy(&t);
				}
				p_member_declaration = p_member_declaration->next;
			}

		}
	}
	else if (type_is_array(p_type))
	{
		//p_object->state = flags;
		//if (p_object->members_size > 0)
		//{
		//    //not sure if we instanticate all items of array
		//    p_object->members[0].state = flags;
		//}
	}
	else if (type_is_pointer(p_type))
	{
		struct type t2 = type_remove_pointer(p_type);
		printf("%*c", ident, ' ');
		if (p_object)
		{
			if (short_version)
			{
				printf("%s == ", previous_names);
				object_state_to_string(p_object->state);
			}
			else
			{
				printf("%p:%s == ", p_object, previous_names);
				printf("{");
				for (int i = 0; i < p_object->object_state_stack.size; i++)
				{
					object_state_to_string(p_object->object_state_stack.data[i]);
					printf(",");
				}
				printf("*");
				object_state_to_string(p_object->state);
				printf("}");
			}
			printf("\n");


			if (p_object->pointed)
			{
				char buffer[200] = { 0 };
				if (type_is_struct_or_union(&t2))
				{
					snprintf(buffer, sizeof buffer, "%s", previous_names);
				}
				else
				{
					snprintf(buffer, sizeof buffer, "*%s", previous_names);
				}



				print_object_core(ident + 1, &t2, p_object->pointed, buffer, is_pointer, short_version);
			}
			else
			{
				//printf("%s %s\n");
			}
		}
		type_destroy(&t2);
	}
	else
	{
		printf("%*c", ident, ' ');
		if (p_object)
		{
			if (short_version)
			{
				printf("%s == ", previous_names);
				object_state_to_string(p_object->state);
			}
			else
			{
				printf("%p:%s == ", p_object, previous_names);
				printf("{");
				for (int i = 0; i < p_object->object_state_stack.size; i++)
				{
					object_state_to_string(p_object->object_state_stack.data[i]);
					printf(",");
				}
				object_state_to_string(p_object->state);
				printf("}");
			}


			printf("\n");
		}
	}


}

enum object_state state_merge(enum object_state before, enum object_state after)
{
	enum object_state e = before | after;


	return e;
}


void object_get_name(const struct type* p_type,
	const struct object* p_object,
	char* outname,
	int out_size);


void print_object(struct type* p_type, struct object* p_object, bool short_version)
{
	if (p_object == NULL)
	{
		printf("null object");
		return;
	}
	char name[100] = { 0 };
	object_get_name(p_type, p_object, name, sizeof name);



	print_object_core(0, p_type, p_object, name, type_is_pointer(p_type), short_version);
}

void set_object(
	struct type* p_type,
	struct object* p_object,
	enum object_state flags);

void set_object_state(
	struct parser_ctx* ctx,
	struct type* p_type,
	struct object* p_object,
	const struct type* p_source_type,
	const struct object* p_object_source,
	const struct token* error_position)
{
	if (p_object_source == NULL)
	{
		return;
	}
	if (p_object == NULL || p_type == NULL)
	{
		return;
	}


	if (p_type->struct_or_union_specifier && p_object->members.size > 0)
	{
		struct struct_or_union_specifier* p_struct_or_union_specifier =
			get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

		if (p_struct_or_union_specifier)
		{
			struct member_declaration* p_member_declaration =
				p_struct_or_union_specifier->member_declaration_list.head;

			int member_index = 0;
			while (p_member_declaration)
			{

				if (p_member_declaration->member_declarator_list_opt)
				{
					struct member_declarator* p_member_declarator =
						p_member_declaration->member_declarator_list_opt->head;

					while (p_member_declarator)
					{
						if (p_member_declarator->declarator)
						{
							if (member_index < p_object->members.size)
							{
								set_object_state(ctx,
									&p_member_declarator->declarator->type,
									&p_object->members.data[member_index],
									&p_object_source->members.data[member_index].declarator->type,
									&p_object_source->members.data[member_index],
									error_position);
							}
							else
							{
								//TODO BUG union?                                
							}
							member_index++;
						}
						p_member_declarator = p_member_declarator->next;
					}
				}
				p_member_declaration = p_member_declaration->next;
			}
		}
		else
		{
			assert(p_object->members.size == 0);
			p_object->state = p_object_source->state;
		}
	}
	else if (type_is_array(p_type))
	{
		p_object->state = p_object_source->state;
		if (p_object->members.size > 0)
		{
			//not sure if we instantiate all items of array
			p_object->members.data[0].state = p_object_source->members.data[0].state;
		}
	}
	else if (type_is_pointer(p_type))
	{
		if (p_object_source)
		{
			if (p_object_source->state == OBJECT_STATE_UNINITIALIZED)
			{
				char buffer[100] = { 0 };
				object_get_name(p_source_type, p_object_source, buffer, sizeof buffer);
				compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
					ctx,
					error_position,
					"source object '%s' is uninitialized", buffer);
			}
			else if (p_object_source->state & OBJECT_STATE_UNINITIALIZED)
			{
				char buffer[100] = { 0 };
				object_get_name(p_source_type, p_object_source, buffer, sizeof buffer);

				compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
					ctx,
					error_position,
					"source object '%s' may be uninitialized", buffer);
			}

			if (type_is_any_owner(p_type) &&
				type_is_any_owner(p_source_type))
			{
				if (p_object_source->state == OBJECT_STATE_MOVED)
				{
					char buffer[100] = { 0 };
					object_get_name(p_source_type, p_object_source, buffer, sizeof buffer);

					compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
						ctx,
						error_position,
						"source object '%s' have been moved", buffer);
				}
				else if (p_object_source->state & OBJECT_STATE_MOVED)
				{
					char buffer[100] = { 0 };
					object_get_name(p_source_type, p_object_source, buffer, sizeof buffer);

					compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
						ctx,
						error_position,
						"source object '%s' may have been moved", buffer);
				}
			}

		}


		if (type_is_any_owner(p_type))
		{
			p_object->state = p_object_source->state;
		}
		else
		{
			//MOVED state is not applicable to non owner objects
			p_object->state = p_object_source->state & ~OBJECT_STATE_MOVED;
		}


		if (p_object->pointed)
		{
			struct type t2 = type_remove_pointer(p_type);
			if (p_object_source->pointed)
			{
				set_object_state(ctx, &t2, p_object->pointed, p_source_type, p_object_source->pointed, error_position);
			}
			else
			{
				set_object(&t2, p_object->pointed, OBJECT_STATE_NULL | OBJECT_STATE_NOT_NULL);
			}
			type_destroy(&t2);
		}
	}
	else
	{


		//assert(p_object->members.size == 0); //enum?
		p_object->state = p_object_source->state;
	}
}


void set_direct_state(
	struct type* p_type,
	struct object* p_object,
	enum object_state flags)
{
	if (p_object == NULL || p_type == NULL)
	{
		return;
	}

	if (p_type->struct_or_union_specifier && p_object->members.size > 0)
	{
		struct struct_or_union_specifier* p_struct_or_union_specifier =
			get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

		if (p_struct_or_union_specifier)
		{
			struct member_declaration* p_member_declaration =
				p_struct_or_union_specifier->member_declaration_list.head;

			int member_index = 0;
			while (p_member_declaration)
			{

				if (p_member_declaration->member_declarator_list_opt)
				{
					struct member_declarator* p_member_declarator =
						p_member_declaration->member_declarator_list_opt->head;

					while (p_member_declarator)
					{
						if (p_member_declarator->declarator)
						{
							if (member_index < p_object->members.size)
							{
								set_direct_state(&p_member_declarator->declarator->type, &p_object->members.data[member_index], flags);
							}
							else
							{
								//TODO BUG union?                                
							}
							member_index++;
						}
						p_member_declarator = p_member_declarator->next;
					}
				}
				p_member_declaration = p_member_declaration->next;
			}
		}
		else
		{
			assert(p_object->members.size == 0);
			p_object->state = flags;
		}
	}

	if (type_is_pointer(p_type))
	{
		if (flags == OBJECT_STATE_ZERO)
		{
			/*zero for pointers is null*/
			p_object->state = OBJECT_STATE_NULL;
		}
		else
		{
			p_object->state = flags;
		}
	}
	else
	{
		p_object->state = flags;
	}
}

void set_object(
	struct type* p_type,
	struct object* p_object,
	enum object_state flags)
{
	if (p_object == NULL || p_type == NULL)
	{
		return;
	}


	if (p_type->struct_or_union_specifier && p_object->members.size > 0)
	{
		struct struct_or_union_specifier* p_struct_or_union_specifier =
			get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

		if (p_struct_or_union_specifier)
		{
			struct member_declaration* p_member_declaration =
				p_struct_or_union_specifier->member_declaration_list.head;

			int member_index = 0;
			while (p_member_declaration)
			{

				if (p_member_declaration->member_declarator_list_opt)
				{
					struct member_declarator* p_member_declarator =
						p_member_declaration->member_declarator_list_opt->head;

					while (p_member_declarator)
					{
						if (p_member_declarator->declarator)
						{
							if (member_index < p_object->members.size)
							{
								set_object(&p_member_declarator->declarator->type, &p_object->members.data[member_index], flags);
							}
							else
							{
								//TODO BUG union?                                
							}
							member_index++;
						}
						p_member_declarator = p_member_declarator->next;
					}
				}
				p_member_declaration = p_member_declaration->next;
			}
		}
		else
		{
			assert(p_object->members.size == 0);
			p_object->state = flags;
		}
	}
	else if (type_is_array(p_type))
	{
		p_object->state = flags;
		if (p_object->members.size > 0)
		{
			//not sure if we instantiate all items of array
			p_object->members.data[0].state = flags;
		}
	}
	else if (type_is_pointer(p_type))
	{
		p_object->state = flags;

		if (p_object->pointed)
		{
			struct type t2 = type_remove_pointer(p_type);
			if (type_is_out(&t2))
			{
				flags = OBJECT_STATE_UNINITIALIZED;
			}
			set_object(&t2, p_object->pointed, flags);
			type_destroy(&t2);
		}
	}
	else
	{
		//assert(p_object->members.size == 0); //enum?
		p_object->state = flags;
	}
}


void object_set_unknown(struct type* p_type, struct object* p_object)
{
	if (p_object == NULL || p_type == NULL)
	{
		return;
	}

	if (p_type->struct_or_union_specifier && p_object->members.size > 0)
	{
		struct struct_or_union_specifier* p_struct_or_union_specifier =
			get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

		if (p_struct_or_union_specifier)
		{
			struct member_declaration* p_member_declaration =
				p_struct_or_union_specifier->member_declaration_list.head;

			int member_index = 0;
			while (p_member_declaration)
			{
				if (p_member_declaration->member_declarator_list_opt)
				{
					struct member_declarator* p_member_declarator =
						p_member_declaration->member_declarator_list_opt->head;

					while (p_member_declarator)
					{
						if (p_member_declarator->declarator)
						{
							if (member_index < p_object->members.size)
							{
								object_set_unknown(&p_member_declarator->declarator->type, &p_object->members.data[member_index]);
							}
							else
							{
								//TODO BUG union?                                
							}
							member_index++;
						}
						p_member_declarator = p_member_declarator->next;
					}
				}
				p_member_declaration = p_member_declaration->next;
			}
			return;
		}
	}

	if (type_is_pointer(p_type))
	{
		p_object->state = OBJECT_STATE_NULL | OBJECT_STATE_NOT_NULL;

		if (p_object->pointed)
		{
			struct type t2 = type_remove_pointer(p_type);
			object_set_unknown(&t2, p_object->pointed);
			type_destroy(&t2);
		}
	}
	else
	{
		p_object->state = OBJECT_STATE_ZERO | OBJECT_STATE_NOT_ZERO;
	}
}

//returns true if all parts that need to be moved weren't moved.
bool object_check(struct type* p_type, struct object* p_object)
{
	if (p_object == NULL)
	{
		return false;
	}
	if (p_type->type_qualifier_flags & TYPE_QUALIFIER_VIEW)
	{
		return false;
	}

	if (!type_is_any_owner(p_type))
	{
		return false;
	}

	if (p_type->struct_or_union_specifier && p_object->members.size > 0)
	{
		struct struct_or_union_specifier* p_struct_or_union_specifier =
			get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

		struct member_declaration* p_member_declaration =
			p_struct_or_union_specifier->member_declaration_list.head;
		int possible_need_destroy_count = 0;
		int need_destroy_count = 0;
		int member_index = 0;
		while (p_member_declaration)
		{
			if (p_member_declaration->member_declarator_list_opt)
			{
				struct member_declarator* p_member_declarator =
					p_member_declaration->member_declarator_list_opt->head;
				while (p_member_declarator)
				{

					if (p_member_declarator->declarator)
					{
						if (type_is_owner(&p_member_declarator->declarator->type))
						{
							possible_need_destroy_count++;
						}

						if (object_check(&p_member_declarator->declarator->type,
							&p_object->members.data[member_index]))
						{
							need_destroy_count++;
						}
						member_index++;
					}
					p_member_declarator = p_member_declarator->next;
				}
			}
			p_member_declaration = p_member_declaration->next;
		}

		return need_destroy_count > 1 && (need_destroy_count == possible_need_destroy_count);
	}
	else
	{
		bool should_had_been_moved = false;
		if (type_is_pointer(p_type))
		{
			should_had_been_moved = (p_object->state & OBJECT_STATE_NOT_NULL);
		}
		else
		{
			if (p_object->state == OBJECT_STATE_UNINITIALIZED ||
				p_object->state == OBJECT_STATE_MOVED ||
				p_object->state == OBJECT_STATE_NOT_NULL ||
				p_object->state == (OBJECT_STATE_UNINITIALIZED | OBJECT_STATE_MOVED))
			{
			}
			else
			{
				should_had_been_moved = true;
			}
		}

		return should_had_been_moved;
	}

	return false;
}

void object_get_name_core(
	const struct type* p_type,
	const struct object* p_object,
	const struct object* p_object_target,
	const char* previous_names,
	char* outname,
	int out_size)
{
	if (p_object == NULL)
	{
		return;
	}

	if (p_object == p_object_target)
	{
		snprintf(outname, out_size, "%s", previous_names);
		return;
	}

	if (p_type->struct_or_union_specifier && p_object->members.size > 0)
	{
		struct struct_or_union_specifier* p_struct_or_union_specifier =
			get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

		struct member_declaration* p_member_declaration =
			p_struct_or_union_specifier->member_declaration_list.head;

		int member_index = 0;
		while (p_member_declaration)
		{
			if (p_member_declaration->member_declarator_list_opt)
			{
				struct member_declarator* p_member_declarator =
					p_member_declaration->member_declarator_list_opt->head;
				while (p_member_declarator)
				{

					if (p_member_declarator->declarator)
					{
						const char* name = p_member_declarator->declarator->name ? p_member_declarator->declarator->name->lexeme : "";
						char buffer[200] = { 0 };
						if (type_is_pointer(p_type))
							snprintf(buffer, sizeof buffer, "%s->%s", previous_names, name);
						else
							snprintf(buffer, sizeof buffer, "%s.%s", previous_names, name);

						object_get_name_core(
							&p_member_declarator->declarator->type,
							&p_object->members.data[member_index],
							p_object_target,
							buffer,
							outname,
							out_size);

						member_index++;
					}
					p_member_declarator = p_member_declarator->next;
				}
			}
			p_member_declaration = p_member_declaration->next;
		}

	}
	else
	{
		if (type_is_pointer(p_type))
		{
			char buffer[100] = { 0 };
			snprintf(buffer, sizeof buffer, "%s", previous_names);

			struct type t2 = type_remove_pointer(p_type);
			if (type_is_owner(&t2))
			{
				object_get_name_core(
					&t2,
					p_object->pointed,
					p_object_target,
					buffer,
					outname,
					out_size);
			}
			type_destroy(&t2);
		}
	}
}


void object_get_name(const struct type* p_type,
	const struct object* p_object,
	char* outname,
	int out_size)
{
	if (p_object->declarator == NULL)
	{
		outname[0] = '?';
		outname[1] = '\0';
		return;
	}


	const char* root_name = p_object->declarator->name ? p_object->declarator->name->lexeme : "?";
	const struct object* root = &p_object->declarator->object;

	object_get_name_core(&p_object->declarator->type, root, p_object, root_name, outname, out_size);
}

void checked_moved(struct parser_ctx* ctx,
	struct type* p_type,
	struct object* p_object,
	const struct token* position_token)
{
	if (p_object == NULL)
	{
		return;
	}
	if (p_type->struct_or_union_specifier && p_object->members.size > 0)
	{
		struct struct_or_union_specifier* p_struct_or_union_specifier =
			get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

		struct member_declaration* p_member_declaration =
			p_struct_or_union_specifier->member_declaration_list.head;

		/*
		*  Some parts of the object needs to be moved..
		*  we need to print error one by one
		*/
		int member_index = 0;
		while (p_member_declaration)
		{
			if (p_member_declaration->member_declarator_list_opt)
			{
				struct member_declarator* p_member_declarator =
					p_member_declaration->member_declarator_list_opt->head;
				while (p_member_declarator)
				{

					if (p_member_declarator->declarator)
					{
						checked_moved(ctx, &p_member_declarator->declarator->type,
							&p_object->members.data[member_index],
							position_token);

						member_index++;
					}
					p_member_declarator = p_member_declarator->next;
				}
			}
			p_member_declaration = p_member_declaration->next;
		}
	}
	else
	{
		if (type_is_pointer(p_type) && !type_is_any_owner(p_type))
		{
			struct type t2 = type_remove_pointer(p_type);
			checked_moved(ctx,
				&t2,
				p_object->pointed,
				position_token);
			type_destroy(&t2);
		}

		if (p_object->state & OBJECT_STATE_MOVED)
		{
			struct token* name_pos = p_object->declarator->name ? p_object->declarator->name : p_object->declarator->first_token;
			const char* parameter_name = p_object->declarator->name ? p_object->declarator->name->lexeme : "?";

			char name[200] = { 0 };
			object_get_name(p_type, p_object, name, sizeof name);
			compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
				ctx,
				position_token,
				"parameter '%s' is leaving scoped with a moved object '%s'",
				parameter_name,
				name);

			compiler_set_info_with_token(W_NONE, ctx, name_pos, "parameter", name);
		}

		if (p_object->state & OBJECT_STATE_UNINITIALIZED)
		{
			struct token* name_pos = p_object->declarator->name ? p_object->declarator->name : p_object->declarator->first_token;
			const char* parameter_name = p_object->declarator->name ? p_object->declarator->name->lexeme : "?";

			char name[200] = { 0 };
			object_get_name(p_type, p_object, name, sizeof name);
			compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
				ctx,
				position_token,
				"parameter '%s' is leaving scoped with a uninitialized object '%s'",
				parameter_name,
				name);

			compiler_set_info_with_token(W_NONE, ctx, name_pos, "parameter", name);
		}
	}
}


void checked_read_object(struct parser_ctx* ctx,
	struct type* p_type,
	struct object* p_object,
	const struct token* position_token,
	bool check_pointed_object)
{
	if (p_object == NULL)
	{
		return;
	}
	if (p_type->struct_or_union_specifier && p_object->members.size > 0)
	{
		struct struct_or_union_specifier* p_struct_or_union_specifier =
			get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

		struct member_declaration* p_member_declaration =
			p_struct_or_union_specifier ?
			p_struct_or_union_specifier->member_declaration_list.head :
			NULL;

		/*
		*  Some parts of the object needs to be moved..
		*  we need to print error one by one
		*/
		int member_index = 0;
		while (p_member_declaration)
		{
			if (p_member_declaration->member_declarator_list_opt)
			{
				struct member_declarator* p_member_declarator =
					p_member_declaration->member_declarator_list_opt->head;
				while (p_member_declarator)
				{

					if (p_member_declarator->declarator)
					{
						checked_read_object(ctx, &p_member_declarator->declarator->type,
							&p_object->members.data[member_index],
							position_token,
							check_pointed_object);

						member_index++;
					}
					p_member_declarator = p_member_declarator->next;
				}
			}
			p_member_declaration = p_member_declaration->next;
		}
	}
	else
	{
		if (type_is_pointer(p_type) &&
			check_pointed_object &&
			p_object->state & OBJECT_STATE_NOT_NULL /*we don't need to check pointed object*/
			)
		{
			struct type t2 = type_remove_pointer(p_type);
			checked_read_object(ctx,
				&t2,
				p_object->pointed,
				position_token,
				true);
			type_destroy(&t2);
		}

		if (p_object->state & OBJECT_STATE_MOVED)
		{
			//struct token* name_pos = p_object->declarator->name ? p_object->declarator->name : p_object->declarator->first_token;
			//const char* parameter_name = p_object->declarator->name ? p_object->declarator->name->lexeme : "?";

			char name[200] = { 0 };
			object_get_name(p_type, p_object, name, sizeof name);
			compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
				ctx,
				position_token,
				"object '%s' was moved",
				name);
		}

		if (p_object->state & OBJECT_STATE_UNINITIALIZED)
		{
			char name[200] = { 0 };
			object_get_name(p_type, p_object, name, sizeof name);
			compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
				ctx,
				position_token,
				"uninitialized object '%s'",
				name);
		}
	}
}


void visit_object(struct parser_ctx* ctx,
	struct type* p_type,
	struct object* p_object,
	const struct token* position_token,
	const char* previous_names,
	bool is_assigment)
{
	if (p_object == NULL)
	{
		return;
	}
	if (p_type->type_qualifier_flags & TYPE_QUALIFIER_VIEW)
	{
		return;
	}

	if (!type_is_any_owner(p_type))
	{
		if (p_type->storage_class_specifier_flags & STORAGE_SPECIFIER_PARAMETER)
		{
			//for view parameters we need to check if they left something moved..
			checked_moved(ctx,
				p_type,
				p_object,
				position_token);

		}
		return;
	}


	if (p_type->struct_or_union_specifier && p_object->members.size > 0)
	{
		struct struct_or_union_specifier* p_struct_or_union_specifier =
			get_complete_struct_or_union_specifier(p_type->struct_or_union_specifier);

		struct member_declaration* p_member_declaration =
			p_struct_or_union_specifier->member_declaration_list.head;

		if (object_check(p_type, p_object))
		{
			/*
			*  All parts of the object needs to be moved, so instead of
			*  describing each part we will just say that the object should
			*  have been moved.
			*/
			const struct token* const name = p_object->declarator->name ? p_object->declarator->name : p_object->declarator->first_token;
			compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
				ctx,
				name,
				"object '%s' was not moved/destroyed",
				previous_names);

			if (p_object->declarator)
				compiler_set_info_with_token(W_NONE, ctx, position_token, "end of '%s' scope", previous_names);
		}
		else
		{
			/*
			*  Some parts of the object needs to be moved..
			*  we need to print error one by one
			*/

			int member_index = 0;
			while (p_member_declaration)
			{

				if (p_member_declaration->member_declarator_list_opt)
				{
					struct member_declarator* p_member_declarator =
						p_member_declaration->member_declarator_list_opt->head;
					while (p_member_declarator)
					{

						if (p_member_declarator->declarator)
						{
							const char* name = p_member_declarator->declarator->name ? p_member_declarator->declarator->name->lexeme : "?";

							char buffer[200] = { 0 };
							if (type_is_pointer(p_type))
								snprintf(buffer, sizeof buffer, "%s->%s", previous_names, name);
							else
								snprintf(buffer, sizeof buffer, "%s.%s", previous_names, name);

							visit_object(ctx, &p_member_declarator->declarator->type,
								&p_object->members.data[member_index],
								position_token,
								buffer,
								is_assigment);

							member_index++;
						}
						p_member_declarator = p_member_declarator->next;
					}
				}
				p_member_declaration = p_member_declaration->next;
			}
		}


	}
	else
	{
		const char* name = previous_names;
		const struct token* const position =
			p_object->declarator->name ? p_object->declarator->name : p_object->declarator->first_token;

		if (name[0] == '\0')
		{
			/*function arguments without name*/
			name = "?";
		}
		bool should_had_been_moved = false;


		/*
		   Despite the name OBJECT_STATE_NOT_NULL does not means null, it means
		   the reference is not referring an object, the value could be -1 for instance.
		*/
		if (type_is_pointer(p_type))
		{
			should_had_been_moved = (p_object->state & OBJECT_STATE_NOT_NULL);
		}
		else
		{
			if (p_object->state == OBJECT_STATE_UNINITIALIZED ||
				p_object->state == OBJECT_STATE_MOVED ||
				p_object->state == OBJECT_STATE_NULL)
			{
			}
			else
			{
				should_had_been_moved = true;
			}
		}


		if (type_is_pointer(p_type))
		{
			if (should_had_been_moved)
			{
				char buffer[100] = { 0 };
				snprintf(buffer, sizeof buffer, "%s", previous_names);

				struct type t2 = type_remove_pointer(p_type);
				if (type_is_owner(&t2))
				{
					visit_object(ctx,
						&t2,
						p_object->pointed,
						position_token,
						buffer,
						is_assigment);
				}
				type_destroy(&t2);
			}

		}


		if (should_had_been_moved)
		{
			if (type_is_obj_owner(p_type))
			{

			}
			else
			{
				if (type_is_pointer(p_type))
				{
					struct type t2 = type_remove_pointer(p_type);
					bool pointed_is_out = type_is_out(&t2);
					type_destroy(&t2);

					if (!pointed_is_out)
					{
						if (is_assigment)
						{
							compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
								ctx,
								position_token,
								"memory pointed by '%s' was not released before assignment.",
								name);
						}
						else
						{
							compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
								ctx,
								position,
								"memory pointed by '%s' was not released.",
								name);
							if (p_object->declarator)
							{
								compiler_set_info_with_token(W_NONE, ctx, position_token, "end of '%s' scope", name);
							}
						}
					}
				}
				else
				{
					if (is_assigment)
					{
						compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
							ctx,
							position_token,
							"previous members of '%s' were not moved before this assignment.",
							name);
					}
					else
					{
						compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
							ctx,
							position,
							"object '%s' was not moved.",
							name);
						if (p_object->declarator)
						{
							compiler_set_info_with_token(W_NONE, ctx, position_token, "end of '%s' scope", name);
						}
					}
				}
			}
		}
	}

}


void object_assignment(struct parser_ctx* ctx,
	struct object* p_source_obj_opt,
	struct type* p_source_obj_type,

	struct object* p_dest_obj_opt,
	struct type* p_dest_obj_type,

	const struct token* error_position,
	bool bool_source_zero_value,
	enum object_state source_state_after)
{
	if (p_dest_obj_opt)
	{
		if (type_is_owner(p_dest_obj_type) && !type_is_out(p_dest_obj_type))
		{
			char buffer[100] = { 0 };
			object_get_name(p_dest_obj_type, p_dest_obj_opt, buffer, sizeof buffer);
			visit_object(ctx,
				p_dest_obj_type,
				p_dest_obj_opt,
				error_position,
				buffer,
				true);
		}
	}


	if (p_dest_obj_opt)
	{
		if (bool_source_zero_value)
		{
			set_object(p_dest_obj_type, p_dest_obj_opt, OBJECT_STATE_NULL);
		}
		else
		{
			if (p_source_obj_opt)
			{
				set_object_state(ctx, p_dest_obj_type, p_dest_obj_opt, p_source_obj_type, p_source_obj_opt, error_position);
			}
			else
			{
				object_set_unknown(p_dest_obj_type, p_dest_obj_opt);
			}
		}

	}


	if (type_is_any_owner(p_source_obj_type) &&
		!type_is_owner(p_dest_obj_type) &&
		p_source_obj_type->storage_class_specifier_flags & STORAGE_SPECIFIER_FUNCTION_RETURN)
	{
		/*
		int main()
		{
		   struct X * p = (struct X * owner) malloc(1);
		}
		*/

		compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
			ctx,
			error_position,
			"Object must be owner qualified.");
	}

	if (type_is_any_owner(p_dest_obj_type) && type_is_any_owner(p_source_obj_type) && type_is_pointer(p_source_obj_type))
	{
		if (type_is_void_ptr(p_dest_obj_type))
		{
			if (p_source_obj_opt)
			{
				struct type t2 = type_remove_pointer(p_source_obj_type);
				const char* name = p_source_obj_opt->declarator->name ?
					p_source_obj_opt->declarator->name->lexeme :
					"?";

				visit_object(ctx,
					&t2,
					p_source_obj_opt->pointed,
					error_position,
					name,
					true);
				p_source_obj_opt->state = source_state_after;
				type_destroy(&t2);
			}
		}
		else if (type_is_obj_owner(p_dest_obj_type))
		{
			if (type_is_owner(p_source_obj_type))
			{
				if (p_source_obj_opt->pointed)
				{
					struct type t = type_remove_pointer(p_source_obj_type);
					set_object(&t, p_source_obj_opt->pointed, source_state_after);
					type_destroy(&t);
				}
			}
			else if (type_is_obj_owner(p_source_obj_type))
			{
				if (p_source_obj_opt->pointed)
				{
					struct type t = type_remove_pointer(p_source_obj_type);
					set_object(&t, p_source_obj_opt->pointed, source_state_after);
					type_destroy(&t);
				}
			}
		}
		else
		{

			if (p_source_obj_opt)
			{
				set_object(p_source_obj_type, p_source_obj_opt, source_state_after);
			}
		}
	}
	else if (type_is_any_owner(p_dest_obj_type) && type_is_any_owner(p_source_obj_type))
	{
		/*everthing is moved*/
		if (p_source_obj_opt)
			set_object(p_source_obj_type, p_source_obj_opt, source_state_after);
	}
	else
	{
		/*nothing changes*/
	}

}







//#pragma once

struct format_visit_ctx
{
    view struct ast ast;
    int indentation;
};

void format_visit(struct format_visit_ctx* ctx);



//#pragma once

/*
  To be able to do static analysis with goto jump, we
  need to see full function AST because this affects for 
  instance which scopes we are leaving.
  Because static analysis may change the state we also want
  to check static_assert here.. so better to move all checks to here.
  nullchecks and imaginary flags.
*/

struct flow_visit_ctx
{
    struct parser_ctx *ctx;
    view struct ast ast;    
    struct flow_defer_scope* owner tail_block;
    struct type* view p_return_type;
    int parameter_list;
    struct jump_statement* view p_last_jump_statement;
};


void flow_visit_ctx_destroy(struct flow_visit_ctx* obj_owner p);

void flow_visit_function(struct flow_visit_ctx* ctx, struct declaration* p_declaration);

#ifdef _WIN32
#endif

#if defined _MSC_VER && !defined __POCC__
#endif




//#pragma once

struct defer_scope
{
    struct defer_statement* defer_statement; // defer 
    struct try_statement* p_try_statement; //try
    struct selection_statement* p_selection_statement2; //if swith
    struct iteration_statement* p_iteration_statement; //for do while
    struct statement* p_statement; //
    struct compound_statement* p_function_body;
    struct defer_scope* owner lastchild;

    struct defer_scope* owner previous;
};
void defer_scope_delete(struct defer_scope * owner p);
struct visit_ctx
{
    /*
    * It is necessary two passes to generate lambdas expressions
    * because some types maybe needs to be "globalized"
    * is_second_pass is true if the compiler is at second pass
    */
    bool is_second_pass;
   
    bool has_lambda;

    bool is_inside_lambda;
    bool hide_non_used_declarations;

    /*these indexes are used to generate unique names at file scope*/
    int capture_index;    
    int lambdas_index;
    
    struct token_list insert_before_declaration;
    struct token_list insert_before_block_item;
    view struct ast ast;
    enum language_version target;
    struct defer_scope* owner tail_block;
};

void visit(struct visit_ctx* ctx);
void visit_ctx_destroy( struct visit_ctx* obj_owner ctx);



void object_state_to_string(enum object_state e)
{
	bool  first = true;

	printf("\"");
	if (e & OBJECT_STATE_UNINITIALIZED)
	{
		if (first) first = false; else printf(" or ");
		printf("uninitialized");
	}


	if (e & OBJECT_STATE_NOT_NULL &&
		e & OBJECT_STATE_NULL)
	{
		if (first) first = false; else printf(" or ");
		printf("maybe-null");
	}
	else if (e & OBJECT_STATE_NOT_NULL)
	{
		if (first) first = false; else printf(" or ");
		printf("not-null");
	}
	else if (e & OBJECT_STATE_NULL)
	{
		if (first) first = false; else printf(" or ");
		printf("null");
	}

	if (e & OBJECT_STATE_NOT_ZERO &&
		e & OBJECT_STATE_ZERO)
	{
		if (first) first = false; else printf(" or ");
		printf("any");
	}
	else if (e & OBJECT_STATE_ZERO)
	{
		if (first) first = false; else printf(" or ");
		printf("zero");
	}
	else if (e & OBJECT_STATE_NOT_ZERO)
	{
		if (first) first = false; else printf(" or ");
		printf("not-zero");
	}

	if (e & OBJECT_STATE_MOVED)
	{
		if (first) first = false; else printf(" or ");
		printf("moved");
	}

	printf("\"");
}

struct defer_statement* owner defer_statement(struct parser_ctx* ctx);

void defer_statement_delete(struct defer_statement* owner opt p)
{
	if (p)
	{
		secondary_block_delete(p->secondary_block);
		free(p);
	}
}

static int s_anonymous_struct_count = 0;

///////////////////////////////////////////////////////////////////////////////
void naming_convention_struct_tag(struct parser_ctx* ctx, struct token* token);
void naming_convention_enum_tag(struct parser_ctx* ctx, struct token* token);
void naming_convention_function(struct parser_ctx* ctx, struct token* token);
void naming_convention_enumerator(struct parser_ctx* ctx, struct token* token);
void naming_convention_struct_member(struct parser_ctx* ctx, struct token* token, struct type* type);
void naming_convention_parameter(struct parser_ctx* ctx, struct token* token, struct type* type);
void naming_convention_global_var(struct parser_ctx* ctx, struct token* token, struct type* type, enum storage_class_specifier_flags storage);
void naming_convention_local_var(struct parser_ctx* ctx, struct token* token, struct type* type);

///////////////////////////////////////////////////////////////////////////////

static bool parser_is_warning_enabled(const struct parser_ctx* ctx, enum warning w)
{
	return
		(ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index] & w) != 0;

}

static void check_open_brace_style(struct parser_ctx* ctx, struct token* token)
{
	//token points to {

	if (token->level == 0 &&
		!(token->flags & TK_FLAG_MACRO_EXPANDED) &&
		token->type == '{' &&
		parser_is_warning_enabled(ctx, W_STYLE))
	{
		if (ctx->options.style == STYLE_CAKE)
		{
			if (token->prev->type == TK_BLANKS &&
				token->prev->prev->type == TK_NEWLINE)
			{
			}
			else
			{
				compiler_set_info_with_token(W_STYLE, ctx, token, "not following correct brace style {");
			}
		}
	}
}

static void check_close_brace_style(struct parser_ctx* ctx, struct token* token)
{
	//token points to {

	if (token->level == 0 &&
		!(token->flags & TK_FLAG_MACRO_EXPANDED) &&
		token->type == '}' &&
		parser_is_warning_enabled(ctx, W_STYLE))
	{
		if (ctx->options.style == STYLE_CAKE)
		{
			if (token->prev->type == TK_BLANKS &&
				token->prev->prev->type == TK_NEWLINE)
			{
			}
			else
			{
				compiler_set_info_with_token(W_STYLE, ctx, token, "not following correct close brace style }");
			}
		}
	}
}

static void check_func_open_brace_style(struct parser_ctx* ctx, struct token* token)
{
	//token points to {

	if (token->level == 0 &&
		!(token->flags & TK_FLAG_MACRO_EXPANDED) &&
		token->type == '{' &&
		parser_is_warning_enabled(ctx, W_STYLE))
	{
		if (ctx->options.style == STYLE_CAKE)
		{
			if (token->prev->type == TK_NEWLINE)
			{
			}
			else
			{
				compiler_set_info_with_token(W_STYLE, ctx, token, "not following correct brace style {");
			}
		}
	}
}

static void check_func_close_brace_style(struct parser_ctx* ctx, struct token* token)
{
	//token points to {

	if (token->level == 0 &&
		!(token->flags & TK_FLAG_MACRO_EXPANDED) &&
		token->type == '}' &&
		parser_is_warning_enabled(ctx, W_STYLE))
	{
		if (ctx->options.style == STYLE_CAKE)
		{
			if (token->prev->prev->type == TK_NEWLINE)
			{
			}
			else
			{
				compiler_set_info_with_token(W_STYLE, ctx, token, "not following correct close brace style }");
			}
		}
	}
}


#ifdef TEST
int printf_nothing(const char* fmt, ...) { return 0; }
#endif

void scope_destroy(struct scope* obj_owner p)
{
	hashmap_destroy(&p->tags);
	hashmap_destroy(&p->variables);
}

void scope_list_push(struct scope_list* list, struct scope* pnew)
{
	if (list->tail)
		pnew->scope_level = list->tail->scope_level + 1;

	if (list->head == NULL)
	{
		list->head = pnew;
		list->tail = pnew;
		//pnew->prev = list->tail;
	}
	else
	{
		pnew->previous = list->tail;
		list->tail->next = pnew;
		list->tail = pnew;
	}
}

void scope_list_pop(struct scope_list* list)
{


	if (list->head == NULL)
		return;

	struct scope* p = list->tail;
	if (list->head == list->tail)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{

		list->tail = list->tail->previous;
		if (list->tail == list->head)
		{
			list->tail->next = NULL;
			list->tail->previous = NULL;
		}
	}
	p->next = NULL;
	p->previous = NULL;
}


void parser_ctx_destroy(struct parser_ctx* obj_owner ctx)
{
	if (ctx->sarif_file)
	{
		fclose(ctx->sarif_file);
	}

}


void compiler_set_error_with_token(enum error error, struct parser_ctx* ctx, const struct token* p_token, const char* fmt, ...)
{
	if (p_token == NULL)
		return;
	if (p_token->level > 0)
		return;

	if (ctx->options.disable_ownership_errors && is_ownership_error(error))
	{
		return;
	}


	ctx->p_report->error_count++;
	ctx->p_report->last_error = error;
	char buffer[200] = { 0 };

#ifndef TEST

	if (p_token)
		print_position(p_token->token_origin->lexeme, p_token->line, p_token->col, ctx->options.visual_studio_ouput_format);


	va_list args;
	va_start(args, fmt);
	vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);
	if (ctx->options.visual_studio_ouput_format)
	{
		printf("error: " "%s\n", buffer);
	}
	else
	{
		printf(LIGHTRED "error: " WHITE "%s\n", buffer);

	}

	print_line_and_token(p_token, ctx->options.visual_studio_ouput_format);
#endif
	const char* func_name = "module";
	if (ctx->p_current_function_opt)
	{
		func_name = ctx->p_current_function_opt->init_declarator_list.head->p_declarator->name->lexeme;
	}

	if (ctx->sarif_file)
	{
		const char* file_name = "?";
		int line = 0;
		int col = 0;
		if (p_token)
		{
			file_name = p_token->token_origin->lexeme;
			line = p_token->line;
			col = p_token->col;
		}

		if (ctx->p_report->error_count + ctx->p_report->warnings_count + ctx->p_report->info_count > 1)
		{
			fprintf(ctx->sarif_file, ",\n");
		}

		fprintf(ctx->sarif_file, "   {\n");
		fprintf(ctx->sarif_file, "     \"ruleId\":\"%s\",\n", "error");
		fprintf(ctx->sarif_file, "     \"level\":\"error\",\n");
		fprintf(ctx->sarif_file, "     \"message\": {\n");
		fprintf(ctx->sarif_file, "            \"text\": \"%s\"\n", buffer);
		fprintf(ctx->sarif_file, "      },\n");
		fprintf(ctx->sarif_file, "      \"locations\": [\n");
		fprintf(ctx->sarif_file, "       {\n");

		fprintf(ctx->sarif_file, "       \"physicalLocation\": {\n");

		fprintf(ctx->sarif_file, "             \"artifactLocation\": {\n");
		fprintf(ctx->sarif_file, "                 \"uri\": \"file:///%s\"\n", file_name);
		fprintf(ctx->sarif_file, "              },\n");

		fprintf(ctx->sarif_file, "              \"region\": {\n");
		fprintf(ctx->sarif_file, "                  \"startLine\": %d,\n", line);
		fprintf(ctx->sarif_file, "                  \"startColumn\": %d,\n", col);
		fprintf(ctx->sarif_file, "                  \"endLine\": %d,\n", line);
		fprintf(ctx->sarif_file, "                  \"endColumn\": %d\n", col);
		fprintf(ctx->sarif_file, "               }\n");
		fprintf(ctx->sarif_file, "         },\n");

		fprintf(ctx->sarif_file, "         \"logicalLocations\": [\n");
		fprintf(ctx->sarif_file, "          {\n");

		fprintf(ctx->sarif_file, "              \"fullyQualifiedName\": \"%s\",\n", func_name);
		fprintf(ctx->sarif_file, "              \"decoratedName\": \"%s\",\n", func_name);

		fprintf(ctx->sarif_file, "              \"kind\": \"%s\"\n", "function");
		fprintf(ctx->sarif_file, "          }\n");

		fprintf(ctx->sarif_file, "         ]\n");

		fprintf(ctx->sarif_file, "       }\n");
		fprintf(ctx->sarif_file, "     ]\n");

		fprintf(ctx->sarif_file, "   }\n");
	}

}


_Bool compiler_set_warning_with_token(enum warning w, struct parser_ctx* ctx, const struct token* p_token, const char* fmt, ...)
{
	if (w != W_NONE)
	{
		if (p_token && p_token->level != 0)
		{
			/*we dont warning code inside includes*/
			return false;
		}

		if (!parser_is_warning_enabled(ctx, w))
		{
			return false;
		}
	}

	ctx->p_report->warnings_count++;
	ctx->p_report->last_warning |= w;

	const char* func_name = "module";
	if (ctx->p_current_function_opt)
	{
		func_name = ctx->p_current_function_opt->init_declarator_list.head->p_declarator->name->lexeme;
	}

	char buffer[200] = { 0 };

#ifndef TEST
	if (p_token)
		print_position(p_token->token_origin->lexeme, p_token->line, p_token->col, ctx->options.visual_studio_ouput_format);


	va_list args;
	va_start(args, fmt);
	/*int n =*/ vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	if (w != W_NONE)
	{
		if (ctx->options.visual_studio_ouput_format)
		{
			printf("warning: " "%s [" "-W%s" "]\n", buffer, get_warning_name(w));
		}
		else
		{
			printf(LIGHTMAGENTA "warning: " WHITE "%s [" LIGHTMAGENTA "-W%s" WHITE "]\n" RESET, buffer, get_warning_name(w));
		}

	}
	else
	{
		if (ctx->options.visual_studio_ouput_format)
		{
			printf("warning: " "%s\n", buffer);
		}
		else
		{
			printf(LIGHTMAGENTA "warning: " WHITE "%s\n" RESET, buffer);
		}
	}
	print_line_and_token(p_token, ctx->options.visual_studio_ouput_format);
#endif

	if (ctx->sarif_file)
	{
		if (ctx->p_report->error_count + ctx->p_report->warnings_count + ctx->p_report->info_count > 1)
		{
			fprintf(ctx->sarif_file, ",\n");
		}

		fprintf(ctx->sarif_file, "   {\n");
		fprintf(ctx->sarif_file, "     \"ruleId\":\"%s\",\n", get_warning_name(w));
		fprintf(ctx->sarif_file, "     \"level\":\"warning\",\n");
		fprintf(ctx->sarif_file, "     \"message\": {\n");
		fprintf(ctx->sarif_file, "            \"text\": \"%s\"\n", buffer);
		fprintf(ctx->sarif_file, "      },\n");
		fprintf(ctx->sarif_file, "      \"locations\": [\n");
		fprintf(ctx->sarif_file, "       {\n");

		fprintf(ctx->sarif_file, "       \"physicalLocation\": {\n");

		fprintf(ctx->sarif_file, "             \"artifactLocation\": {\n");
		fprintf(ctx->sarif_file, "                 \"uri\": \"file:///%s\"\n", p_token->token_origin->lexeme);
		fprintf(ctx->sarif_file, "              },\n");

		fprintf(ctx->sarif_file, "              \"region\": {\n");
		fprintf(ctx->sarif_file, "                  \"startLine\": %d,\n", p_token->line);
		fprintf(ctx->sarif_file, "                  \"startColumn\": %d,\n", p_token->col);
		fprintf(ctx->sarif_file, "                  \"endLine\": %d,\n", p_token->line);
		fprintf(ctx->sarif_file, "                  \"endColumn\": %d\n", p_token->col);
		fprintf(ctx->sarif_file, "               }\n");
		fprintf(ctx->sarif_file, "         },\n");

		fprintf(ctx->sarif_file, "         \"logicalLocations\": [\n");
		fprintf(ctx->sarif_file, "          {\n");

		fprintf(ctx->sarif_file, "              \"fullyQualifiedName\": \"%s\",\n", func_name);
		fprintf(ctx->sarif_file, "              \"decoratedName\": \"%s\",\n", func_name);

		fprintf(ctx->sarif_file, "              \"kind\": \"%s\"\n", "function");
		fprintf(ctx->sarif_file, "          }\n");

		fprintf(ctx->sarif_file, "         ]\n");

		fprintf(ctx->sarif_file, "       }\n");
		fprintf(ctx->sarif_file, "     ]\n");

		fprintf(ctx->sarif_file, "   }\n");
	}

	return 1;
}


void compiler_set_info_with_token(enum warning w, struct parser_ctx* ctx, const struct token* p_token, const char* fmt, ...)
{
	if (w != W_NONE)
	{
		if (p_token->level != 0)
		{
			/*we dont warning code inside includes*/
			return;
		}

		if (!parser_is_warning_enabled(ctx, w))
		{
			return;
		}
	}
	const char* func_name = "module";
	if (ctx->p_current_function_opt)
	{
		func_name = ctx->p_current_function_opt->init_declarator_list.head->p_declarator->name->lexeme;
	}
	ctx->p_report->info_count++;
	ctx->p_report->last_warning |= w;
	char buffer[200] = { 0 };

#ifndef TEST
	print_position(p_token->token_origin->lexeme, p_token->line, p_token->col, ctx->options.visual_studio_ouput_format);

	va_list args;
	va_start(args, fmt);
	/*int n =*/ vsnprintf(buffer, sizeof(buffer), fmt, args);
	va_end(args);

	if (ctx->options.visual_studio_ouput_format)
	{
		printf("note: " "%s\n", buffer);
	}
	else
	{
		printf(LIGHTCYAN "note: " WHITE "%s\n", buffer);
	}

	print_line_and_token(p_token, ctx->options.visual_studio_ouput_format);
#endif // !TEST


	if (ctx->sarif_file)
	{
		if (ctx->p_report->error_count + ctx->p_report->warnings_count + ctx->p_report->info_count > 1)
		{
			fprintf(ctx->sarif_file, ",\n");
		}

		fprintf(ctx->sarif_file, "   {\n");
		fprintf(ctx->sarif_file, "     \"ruleId\":\"%s\",\n", "info");
		fprintf(ctx->sarif_file, "     \"level\":\"note\",\n");
		fprintf(ctx->sarif_file, "     \"message\": {\n");
		fprintf(ctx->sarif_file, "            \"text\": \"%s\"\n", buffer);
		fprintf(ctx->sarif_file, "      },\n");
		fprintf(ctx->sarif_file, "      \"locations\": [\n");
		fprintf(ctx->sarif_file, "       {\n");

		fprintf(ctx->sarif_file, "       \"physicalLocation\": {\n");

		fprintf(ctx->sarif_file, "             \"artifactLocation\": {\n");
		fprintf(ctx->sarif_file, "                 \"uri\": \"file:///%s\"\n", p_token->token_origin->lexeme);
		fprintf(ctx->sarif_file, "              },\n");

		fprintf(ctx->sarif_file, "              \"region\": {\n");
		fprintf(ctx->sarif_file, "                  \"startLine\": %d,\n", p_token->line);
		fprintf(ctx->sarif_file, "                  \"startColumn\": %d,\n", p_token->col);
		fprintf(ctx->sarif_file, "                  \"endLine\": %d,\n", p_token->line);
		fprintf(ctx->sarif_file, "                  \"endColumn\": %d\n", p_token->col);
		fprintf(ctx->sarif_file, "               }\n");
		fprintf(ctx->sarif_file, "         },\n");

		fprintf(ctx->sarif_file, "         \"logicalLocations\": [\n");
		fprintf(ctx->sarif_file, "          {\n");

		fprintf(ctx->sarif_file, "              \"fullyQualifiedName\": \"%s\",\n", func_name);
		fprintf(ctx->sarif_file, "              \"decoratedName\": \"%s\",\n", func_name);

		fprintf(ctx->sarif_file, "              \"kind\": \"%s\"\n", "function");
		fprintf(ctx->sarif_file, "          }\n");

		fprintf(ctx->sarif_file, "         ]\n");

		fprintf(ctx->sarif_file, "       }\n");
		fprintf(ctx->sarif_file, "     ]\n");

		fprintf(ctx->sarif_file, "   }\n");
	}

}


void print_scope(struct scope_list* e)
{
	printf("--- begin of scope---\n");
	struct scope* p = e->head;
	int level = 0;
	while (p)
	{
		for (int i = 0; i < p->variables.capacity; i++)
		{
			if (p->variables.table[i])
			{
				for (int k = 0; k < level; k++)
					printf(" ");
				printf("%s\n", p->variables.table[i]->key);
			}
		}

		for (int i = 0; i < p->tags.capacity; i++)
		{
			if (p->tags.table[i])
			{
				for (int k = 0; k < level; k++)
					printf(" ");
				printf("tag %s\n", p->tags.table[i]->key);
			}
		}

		level++;
		p = p->next;
	}
	printf("--- end of scope---\n");
}


bool first_of_function_specifier_token(struct token* token)
{
	if (token == NULL)
		return false;

	return token->type == TK_KEYWORD_INLINE ||
		token->type == TK_KEYWORD__NORETURN;
}

bool first_is(struct parser_ctx* ctx, enum token_type type)
{
	return ctx->current != NULL && ctx->current->type == type;
}

bool first_of_function_specifier(struct parser_ctx* ctx)
{
	return first_of_function_specifier_token(ctx->current);
}


bool first_of_enum_specifier_token(struct token* token)
{
	if (token == NULL)
		return false;
	return token->type == TK_KEYWORD_ENUM;
}

bool first_of_enum_specifier(struct parser_ctx* ctx)
{
	return first_of_enum_specifier_token(ctx->current);
}

bool first_of_alignment_specifier(struct parser_ctx* ctx)
{
	if (ctx->current == NULL)
		return false;
	return ctx->current->type == TK_KEYWORD__ALIGNAS;
}

bool first_of_atomic_type_specifier(struct parser_ctx* ctx)
{
	if (ctx->current == NULL)
		return false;

	/*
	  If the _Atomic keyword is immediately followed by a left parenthesis, it is interpreted
	  as a type specifier (with a type name), not as a type qualifier.
	*/

	if (ctx->current->type == TK_KEYWORD__ATOMIC)
	{
		struct token* ahead = parser_look_ahead(ctx);
		if (ahead != NULL)
		{
			return ahead->type == '(';

		}
	}
	return false;
}

bool first_of_storage_class_specifier(struct parser_ctx* ctx)
{
	if (ctx->current == NULL)
		return false;

	return ctx->current->type == TK_KEYWORD_TYPEDEF ||
		ctx->current->type == TK_KEYWORD_CONSTEXPR ||
		ctx->current->type == TK_KEYWORD_EXTERN ||
		ctx->current->type == TK_KEYWORD_STATIC ||
		ctx->current->type == TK_KEYWORD__THREAD_LOCAL ||
		ctx->current->type == TK_KEYWORD_AUTO ||
		ctx->current->type == TK_KEYWORD_REGISTER;
}

bool  first_of_struct_or_union_token(struct token* token)
{
	return token->type == TK_KEYWORD_STRUCT || token->type == TK_KEYWORD_UNION;
}

bool  first_of_struct_or_union(struct parser_ctx* ctx)
{
	return first_of_struct_or_union_token(ctx->current);
}


bool first_of_type_qualifier_token(struct token* p_token)
{
	if (p_token == NULL)
		return false;

	return p_token->type == TK_KEYWORD_CONST ||
		p_token->type == TK_KEYWORD_RESTRICT ||
		p_token->type == TK_KEYWORD_VOLATILE ||
		p_token->type == TK_KEYWORD__ATOMIC ||

		/*extensions*/
		p_token->type == TK_KEYWORD__OUT ||
		p_token->type == TK_KEYWORD__OWNER ||
		p_token->type == TK_KEYWORD__OBJ_OWNER ||
		p_token->type == TK_KEYWORD__VIEW ||
		p_token->type == TK_KEYWORD__OPT;

	//__fastcall
	//__stdcall
}

bool first_of_type_qualifier(struct parser_ctx* ctx)
{
	return first_of_type_qualifier_token(ctx->current);
}




struct map_entry* find_tag(struct parser_ctx* ctx, const char* lexeme)
{
	struct scope* scope = ctx->scopes.tail;
	while (scope)
	{
		struct map_entry* p_entry = hashmap_find(&scope->tags, lexeme);
		if (p_entry)
		{
			return p_entry;
		}
		scope = scope->previous;
	}
	return NULL;
}


struct map_entry* find_variables(struct parser_ctx* ctx, const char* lexeme, struct scope** ppscope_opt)
{
	if (ppscope_opt != NULL)
		*ppscope_opt = NULL; //out

	struct scope* scope = ctx->scopes.tail;
	while (scope)
	{
		struct map_entry* p_entry = hashmap_find(&scope->variables, lexeme);
		if (p_entry)
		{
			if (ppscope_opt)
				*ppscope_opt = scope;
			return p_entry;
		}
		scope = scope->previous;
	}
	return NULL;
}



struct enum_specifier* find_enum_specifier(struct parser_ctx* ctx, const char* lexeme)
{
	struct enum_specifier* best = NULL;
	struct scope* scope = ctx->scopes.tail;
	while (scope)
	{
		struct map_entry* p_entry = hashmap_find(&scope->tags, lexeme);
		if (p_entry &&
			p_entry->type == TAG_TYPE_ENUN_SPECIFIER)
		{
			best = p_entry->p;
			if (best->enumerator_list.head != NULL)
				return best; //OK bem completo
			else
			{
				//nao eh completo vamos continuar subindo
			}

		}
		scope = scope->previous;
	}
	return best; //mesmo que nao seja tao completo vamos retornar.    
}

struct struct_or_union_specifier* find_struct_or_union_specifier(struct parser_ctx* ctx, const char* lexeme)
{
	struct struct_or_union_specifier* p = NULL;
	struct scope* scope = ctx->scopes.tail;
	while (scope)
	{
		struct map_entry* p_entry = hashmap_find(&scope->tags, lexeme);
		if (p_entry &&
			p_entry->type == TAG_TYPE_STRUCT_OR_UNION_SPECIFIER)
		{
			p = p_entry->p;
			break;
		}
		scope = scope->previous;
	}
	return p;
}


struct declarator* find_declarator(struct parser_ctx* ctx, const char* lexeme, struct scope** ppscope_opt)
{
	struct map_entry* p_entry = find_variables(ctx, lexeme, ppscope_opt);

	if (p_entry)
	{
		if (p_entry->type == TAG_TYPE_INIT_DECLARATOR)
		{
			struct init_declarator* p_init_declarator = p_entry->p;
			return (struct declarator*)p_init_declarator->p_declarator;
		}
		else if (p_entry->type == TAG_TYPE_ONLY_DECLARATOR)
		{
			return p_entry->p;
		}
	}

	return NULL;
}

struct enumerator* find_enumerator(struct parser_ctx* ctx, const char* lexeme, struct scope** ppscope_opt)
{
	struct map_entry* p_entry = find_variables(ctx, lexeme, ppscope_opt);

	if (p_entry && p_entry->type == TAG_TYPE_ENUMERATOR)
		return p_entry->p;

	return NULL;
}

bool first_of_typedef_name(struct parser_ctx* ctx, struct token* p_token)
{
	if (p_token == NULL)
		return false;

	if (p_token->type != TK_IDENTIFIER)
	{
		//nao precisa verificar
		return false;
	}
	if (p_token->flags & TK_FLAG_IDENTIFIER_IS_TYPEDEF)
	{
		//ja foi verificado que eh typedef
		return true;
	}
	if (p_token->flags & TK_FLAG_IDENTIFIER_IS_NOT_TYPEDEF)
	{
		//ja foi verificado que NAO eh typedef
		return false;
	}


	struct declarator* pdeclarator = find_declarator(ctx, p_token->lexeme, NULL);

	//pdeclarator->declaration_specifiers->
	if (pdeclarator &&
		pdeclarator->declaration_specifiers &&
		(pdeclarator->declaration_specifiers->storage_class_specifier_flags & STORAGE_SPECIFIER_TYPEDEF))
	{
		pdeclarator->num_uses++;
		p_token->flags |= TK_FLAG_IDENTIFIER_IS_TYPEDEF;
		return true;
	}
	else
	{
		p_token->flags |= TK_FLAG_IDENTIFIER_IS_NOT_TYPEDEF;
	}
	return false;
}

bool first_of_type_specifier(struct parser_ctx* ctx);
bool first_of_type_specifier_token(struct parser_ctx* ctx, struct token* token);


bool first_of_type_name_ahead(struct parser_ctx* ctx)
{

	if (ctx->current == NULL)
		return false;

	if (ctx->current->type != '(')
		return false;
	struct token* token_ahead = parser_look_ahead(ctx);
	return first_of_type_specifier_token(ctx, token_ahead) ||
		first_of_type_qualifier_token(token_ahead);
}

bool first_of_type_name(struct parser_ctx* ctx)
{
	return first_of_type_specifier(ctx) || first_of_type_qualifier(ctx);
}


bool first_of_type_specifier_token(struct parser_ctx* ctx, struct token* p_token)
{
	if (p_token == NULL)
		return false;

	//if (ctx->)
	return p_token->type == TK_KEYWORD_VOID ||
		p_token->type == TK_KEYWORD_CHAR ||
		p_token->type == TK_KEYWORD_SHORT ||
		p_token->type == TK_KEYWORD_INT ||
		p_token->type == TK_KEYWORD_LONG ||

		//microsoft extension
		p_token->type == TK_KEYWORD__INT8 ||
		p_token->type == TK_KEYWORD__INT16 ||
		p_token->type == TK_KEYWORD__INT32 ||
		p_token->type == TK_KEYWORD__INT64 ||
		//end microsoft

		p_token->type == TK_KEYWORD_FLOAT ||
		p_token->type == TK_KEYWORD_DOUBLE ||
		p_token->type == TK_KEYWORD_SIGNED ||
		p_token->type == TK_KEYWORD_UNSIGNED ||
		p_token->type == TK_KEYWORD__BOOL ||
		p_token->type == TK_KEYWORD__COMPLEX ||
		p_token->type == TK_KEYWORD__DECIMAL32 ||
		p_token->type == TK_KEYWORD__DECIMAL64 ||
		p_token->type == TK_KEYWORD__DECIMAL128 ||
		p_token->type == TK_KEYWORD_TYPEOF || //C23
		p_token->type == TK_KEYWORD_TYPEOF_UNQUAL || //C23
		first_of_atomic_type_specifier(ctx) ||
		first_of_struct_or_union_token(p_token) ||
		first_of_enum_specifier_token(p_token) ||
		first_of_typedef_name(ctx, p_token);
}

bool first_of_type_specifier(struct parser_ctx* ctx)
{
	return first_of_type_specifier_token(ctx, ctx->current);
}

bool first_of_type_specifier_qualifier(struct parser_ctx* ctx)
{
	return first_of_type_specifier(ctx) ||
		first_of_type_qualifier(ctx) ||
		first_of_alignment_specifier(ctx);
}

bool first_of_compound_statement(struct parser_ctx* ctx)
{
	return first_is(ctx, '{');
}

bool first_of_jump_statement(struct parser_ctx* ctx)
{
	if (ctx->current == NULL)
		return false;

	return ctx->current->type == TK_KEYWORD_GOTO ||
		ctx->current->type == TK_KEYWORD_CONTINUE ||
		ctx->current->type == TK_KEYWORD_BREAK ||
		ctx->current->type == TK_KEYWORD_RETURN ||
		ctx->current->type == TK_KEYWORD_THROW /*extension*/;
}

bool first_of_selection_statement(struct parser_ctx* ctx)
{
	if (ctx->current == NULL)
		return false;

	return ctx->current->type == TK_KEYWORD_IF ||
		ctx->current->type == TK_KEYWORD_SWITCH;
}

bool first_of_iteration_statement(struct parser_ctx* ctx)
{
	if (ctx->current == NULL)
		return false;

	return
		ctx->current->type == TK_KEYWORD_WHILE ||
		ctx->current->type == TK_KEYWORD_DO ||
		ctx->current->type == TK_KEYWORD_FOR;
}


bool first_of_label(struct parser_ctx* ctx)
{
	if (ctx->current == NULL)
		return false;

	if (ctx->current->type == TK_IDENTIFIER)
	{
		struct token* next = parser_look_ahead(ctx);
		return next && next->type == ':';
	}
	else if (ctx->current->type == TK_KEYWORD_CASE)
	{
		return true;
	}
	else if (ctx->current->type == TK_KEYWORD_DEFAULT)
	{
		return true;
	}

	return false;
}

bool first_of_declaration_specifier(struct parser_ctx* ctx)
{
	/*
	declaration-specifier:
	storage-class-specifier
	type-specifier-qualifier
	function-specifier
	*/
	return first_of_storage_class_specifier(ctx) ||
		first_of_function_specifier(ctx) ||
		first_of_type_specifier_qualifier(ctx);
}


bool first_of_static_assert_declaration(struct parser_ctx* ctx)
{
	if (ctx->current == NULL)
		return false;

	return ctx->current->type == TK_KEYWORD__STATIC_ASSERT ||
		ctx->current->type == TK_KEYWORD_STATIC_DEBUG ||
		ctx->current->type == TK_KEYWORD_STATIC_STATE ||
		ctx->current->type == TK_KEYWORD_STATIC_SET;
}

bool first_of_attribute_specifier(struct parser_ctx* ctx)
{
	if (ctx->current == NULL)
		return false;

	if (ctx->current->type != '[')
	{
		return false;
	}
	struct token* p_token = parser_look_ahead(ctx);
	return p_token != NULL && p_token->type == '[';
}

bool first_of_labeled_statement(struct parser_ctx* ctx)
{
	return first_of_label(ctx);
}

bool first_of_designator(struct parser_ctx* ctx)
{
	if (ctx->current == NULL)
		return false;

	return ctx->current->type == '[' || ctx->current->type == '.';
}

struct token* previous_parser_token(struct token* token)
{
	if (token == NULL)
	{
		return NULL;
	}
	struct token* r = token->prev;
	while (!(r->flags & TK_FLAG_FINAL))
	{
		r = r->prev;
	}


	return r;
}



enum token_type is_keyword(const char* text)
{
	enum token_type result = 0;
	switch (text[0])
	{
	case 'a':
		if (strcmp("alignof", text) == 0) result = TK_KEYWORD__ALIGNOF;
		else if (strcmp("auto", text) == 0) result = TK_KEYWORD_AUTO;
		else if (strcmp("alignas", text) == 0) result = TK_KEYWORD__ALIGNAS; /*C23 alternate spelling _Alignas*/
		else if (strcmp("alignof", text) == 0) result = TK_KEYWORD__ALIGNAS; /*C23 alternate spelling _Alignof*/
		else if (strcmp("assert", text) == 0) result = TK_KEYWORD_ASSERT; /*extension*/
		break;
	case 'b':
		if (strcmp("break", text) == 0) result = TK_KEYWORD_BREAK;
		else if (strcmp("bool", text) == 0) result = TK_KEYWORD__BOOL; /*C23 alternate spelling _Bool*/

		break;
	case 'c':
		if (strcmp("case", text) == 0) result = TK_KEYWORD_CASE;
		else if (strcmp("char", text) == 0) result = TK_KEYWORD_CHAR;
		else if (strcmp("const", text) == 0) result = TK_KEYWORD_CONST;
		else if (strcmp("constexpr", text) == 0) result = TK_KEYWORD_CONSTEXPR;
		else if (strcmp("continue", text) == 0) result = TK_KEYWORD_CONTINUE;
		else if (strcmp("catch", text) == 0) result = TK_KEYWORD_CATCH;
		break;
	case 'd':
		if (strcmp("default", text) == 0) result = TK_KEYWORD_DEFAULT;
		else if (strcmp("do", text) == 0) result = TK_KEYWORD_DO;
		else if (strcmp("defer", text) == 0) result = TK_KEYWORD_DEFER;
		else if (strcmp("double", text) == 0) result = TK_KEYWORD_DOUBLE;
		break;
	case 'e':
		if (strcmp("else", text) == 0) result = TK_KEYWORD_ELSE;
		else if (strcmp("enum", text) == 0) result = TK_KEYWORD_ENUM;
		else if (strcmp("extern", text) == 0) result = TK_KEYWORD_EXTERN;
		break;
	case 'f':
		if (strcmp("float", text) == 0) result = TK_KEYWORD_FLOAT;
		else if (strcmp("for", text) == 0) result = TK_KEYWORD_FOR;
		else if (strcmp("false", text) == 0) result = TK_KEYWORD_FALSE;
		break;
	case 'g':
		if (strcmp("goto", text) == 0) result = TK_KEYWORD_GOTO;
		break;
	case 'i':
		if (strcmp("if", text) == 0) result = TK_KEYWORD_IF;
		else if (strcmp("inline", text) == 0) result = TK_KEYWORD_INLINE;
		else if (strcmp("int", text) == 0) result = TK_KEYWORD_INT;
		break;
	case 'n':
		if (strcmp("nullptr", text) == 0) result = TK_KEYWORD_NULLPTR;
		break;


	case 'l':
		if (strcmp("long", text) == 0) result = TK_KEYWORD_LONG;
		break;
	case 'r':
		if (strcmp("register", text) == 0) result = TK_KEYWORD_REGISTER;
		else if (strcmp("restrict", text) == 0) result = TK_KEYWORD_RESTRICT;
		else if (strcmp("return", text) == 0) result = TK_KEYWORD_RETURN;

		break;
	case 's':
		if (strcmp("short", text) == 0) result = TK_KEYWORD_SHORT;
		else if (strcmp("signed", text) == 0) result = TK_KEYWORD_SIGNED;
		else if (strcmp("sizeof", text) == 0) result = TK_KEYWORD_SIZEOF;
		else if (strcmp("static", text) == 0) result = TK_KEYWORD_STATIC;
		else if (strcmp("struct", text) == 0) result = TK_KEYWORD_STRUCT;
		else if (strcmp("switch", text) == 0) result = TK_KEYWORD_SWITCH;
		else if (strcmp("static_assert", text) == 0) result = TK_KEYWORD__STATIC_ASSERT; /*C23 alternate spelling _Static_assert*/
		else if (strcmp("static_debug", text) == 0) result = TK_KEYWORD_STATIC_DEBUG;
		else if (strcmp("static_state", text) == 0) result = TK_KEYWORD_STATIC_STATE;
		else if (strcmp("static_set", text) == 0) result = TK_KEYWORD_STATIC_SET;

		break;
	case 't':
		if (strcmp("typedef", text) == 0) result = TK_KEYWORD_TYPEDEF;
		else if (strcmp("typeof", text) == 0) result = TK_KEYWORD_TYPEOF; /*C23*/
		else if (strcmp("typeof_unqual", text) == 0) result = TK_KEYWORD_TYPEOF_UNQUAL; /*C23*/
		else if (strcmp("true", text) == 0) result = TK_KEYWORD_TRUE; /*C23*/
		else if (strcmp("thread_local", text) == 0) result = TK_KEYWORD__THREAD_LOCAL; /*C23 alternate spelling _Thread_local*/
		else if (strcmp("try", text) == 0) result = TK_KEYWORD_TRY;
		else if (strcmp("throw", text) == 0) result = TK_KEYWORD_THROW;
		break;
	case 'u':
		if (strcmp("union", text) == 0) result = TK_KEYWORD_UNION;
		else if (strcmp("unsigned", text) == 0) result = TK_KEYWORD_UNSIGNED;
		break;
	case 'v':
		if (strcmp("void", text) == 0) result = TK_KEYWORD_VOID;
		else if (strcmp("volatile", text) == 0) result = TK_KEYWORD_VOLATILE;

		break;
	case 'w':
		if (strcmp("while", text) == 0) result = TK_KEYWORD_WHILE;
		break;
	case '_':


		//begin microsoft
		if (strcmp("__int8", text) == 0) result = TK_KEYWORD__INT8;
		else if (strcmp("__int16", text) == 0) result = TK_KEYWORD__INT16;
		else if (strcmp("__int32", text) == 0) result = TK_KEYWORD__INT32;
		else if (strcmp("__int64", text) == 0) result = TK_KEYWORD__INT64;
		else if (strcmp("__forceinline", text) == 0) result = TK_KEYWORD_INLINE;
		else if (strcmp("__inline", text) == 0) result = TK_KEYWORD_INLINE;
		else if (strcmp("_asm", text) == 0 || strcmp("__asm", text) == 0) result = TK_KEYWORD__ASM;
		else if (strcmp("__alignof", text) == 0) result = TK_KEYWORD__ALIGNOF;
		//
		//end microsoft

		/*ownership*/
		else if (strcmp("_Out", text) == 0) result = TK_KEYWORD__OUT; /*extension*/
		else if (strcmp("_Owner", text) == 0) result = TK_KEYWORD__OWNER; /*extension*/
		else if (strcmp("_Obj_owner", text) == 0) result = TK_KEYWORD__OBJ_OWNER; /*extension*/
		else if (strcmp("_Opt", text) == 0) result = TK_KEYWORD__OPT; /*extension*/
		else if (strcmp("_View", text) == 0) result = TK_KEYWORD__VIEW; /*extension*/

		/*EXPERIMENTAL EXTENSION*/
		else if (strcmp("_has_attr", text) == 0) result = TK_KEYWORD_ATTR_HAS;
		else if (strcmp("_add_attr", text) == 0) result = TK_KEYWORD_ATTR_ADD;
		else if (strcmp("_del_attr", text) == 0) result = TK_KEYWORD_ATTR_REMOVE;
		/*EXPERIMENTAL EXTENSION*/

		/*TRAITS EXTENSION*/
		else if (strcmp("_is_lvalue", text) == 0) result = TK_KEYWORD_IS_LVALUE;
		else if (strcmp("_is_const", text) == 0) result = TK_KEYWORD_IS_CONST;
		else if (strcmp("_is_owner", text) == 0) result = TK_KEYWORD_IS_OWNER;
		else if (strcmp("_is_pointer", text) == 0) result = TK_KEYWORD_IS_POINTER;
		else if (strcmp("_is_array", text) == 0) result = TK_KEYWORD_IS_ARRAY;
		else if (strcmp("_is_function", text) == 0) result = TK_KEYWORD_IS_FUNCTION;
		else if (strcmp("_is_arithmetic", text) == 0) result = TK_KEYWORD_IS_ARITHMETIC;
		else if (strcmp("_is_floating_point", text) == 0) result = TK_KEYWORD_IS_FLOATING_POINT;
		else if (strcmp("_is_integral", text) == 0) result = TK_KEYWORD_IS_INTEGRAL;
		else if (strcmp("_is_scalar", text) == 0) result = TK_KEYWORD_IS_SCALAR;
		/*TRAITS EXTENSION*/

		else if (strcmp("_Alignof", text) == 0) result = TK_KEYWORD__ALIGNOF;
		else if (strcmp("_Alignas", text) == 0) result = TK_KEYWORD__ALIGNAS;
		else if (strcmp("_Atomic", text) == 0) result = TK_KEYWORD__ATOMIC;
		else if (strcmp("_Bool", text) == 0) result = TK_KEYWORD__BOOL;
		else if (strcmp("_Complex", text) == 0) result = TK_KEYWORD__COMPLEX;
		else if (strcmp("_Decimal128", text) == 0) result = TK_KEYWORD__DECIMAL32;
		else if (strcmp("_Decimal64", text) == 0) result = TK_KEYWORD__DECIMAL64;
		else if (strcmp("_Decimal128", text) == 0) result = TK_KEYWORD__DECIMAL128;
		else if (strcmp("_Generic", text) == 0) result = TK_KEYWORD__GENERIC;
		else if (strcmp("_Imaginary", text) == 0) result = TK_KEYWORD__IMAGINARY;
		else if (strcmp("_Noreturn", text) == 0) result = TK_KEYWORD__NORETURN; /*_Noreturn deprecated C23*/
		else if (strcmp("_Static_assert", text) == 0) result = TK_KEYWORD__STATIC_ASSERT;
		else if (strcmp("_Thread_local", text) == 0) result = TK_KEYWORD__THREAD_LOCAL;
		else if (strcmp("_BitInt", text) == 0) result = TK_KEYWORD__BITINT; /*(C23)*/



		break;
	default:
		break;
	}
	return result;
}


static void token_promote(struct token* token)
{
	if (token->type == TK_IDENTIFIER_RECURSIVE_MACRO)
	{
		//talvez desse para remover antesisso..
		//assim que sai do tetris
		//virou passado
		token->type = TK_IDENTIFIER; /*nao precisamos mais disso*/
	}

	if (token->type == TK_IDENTIFIER)
	{
		enum token_type t = is_keyword(token->lexeme);
		if (t != TK_NONE)
			token->type = t;
	}
	else if (token->type == TK_PPNUMBER)
	{
		token->type = parse_number(token->lexeme, NULL);
	}
}

struct token* parser_look_ahead(struct parser_ctx* ctx)
{
	struct token* p = ctx->current->next;
	while (p && !(p->flags & TK_FLAG_FINAL))
	{
		p = p->next;
	}

	if (p)
	{

		token_promote(p);
	}

	return p;
}

bool is_binary_digit(struct stream* stream)
{
	return stream->current[0] >= '0' && stream->current[0] <= '1';
}

bool is_hexadecimal_digit(struct stream* stream)
{
	return (stream->current[0] >= '0' && stream->current[0] <= '9') ||
		(stream->current[0] >= 'a' && stream->current[0] <= 'f') ||
		(stream->current[0] >= 'A' && stream->current[0] <= 'F');
}

bool is_octal_digit(struct stream* stream)
{
	return stream->current[0] >= '0' && stream->current[0] <= '7';
}

void digit_sequence(struct stream* stream)
{
	while (is_digit(stream))
	{
		stream_match(stream);
	}
}

static void binary_exponent_part(struct stream* stream)
{
	//p signopt digit - sequence
	//P   signopt digit - sequence

	stream_match(stream); //p or P
	if (stream->current[0] == '+' || stream->current[0] == '-')
	{
		stream_match(stream); //p or P
	}
	digit_sequence(stream);
}

void hexadecimal_digit_sequence(struct stream* stream)
{
	/*
	 hexadecimal-digit-sequence:
	 hexadecimal-digit
	 hexadecimal-digit ’opt hexadecimal-digit
	*/

	stream_match(stream);
	while (stream->current[0] == '\'' ||
		is_hexadecimal_digit(stream))
	{
		if (stream->current[0] == '\'')
		{
			stream_match(stream);
			if (!is_hexadecimal_digit(stream))
			{
				//erro
			}
			stream_match(stream);
		}
		else
			stream_match(stream);
	}

}

bool first_of_unsigned_suffix(struct stream* stream)
{
	/*
	 unsigned-suffix: one of
	   u U
	 */
	return (stream->current[0] == 'u' ||
		stream->current[0] == 'U');
}

void unsigned_suffix_opt(struct stream* stream)
{
	/*
   unsigned-suffix: one of
	 u U
   */
	if (stream->current[0] == 'u' ||
		stream->current[0] == 'U')
	{
		stream_match(stream);
	}
}

void integer_suffix_opt(struct stream* stream, enum type_specifier_flags* flags_opt)
{
	/*
	 integer-suffix:
	 unsigned-suffix long-suffixopt
	 unsigned-suffix long-long-suffix
	 long-suffix unsigned-suffixopt
	 long-long-suffix unsigned-suffixopt
	*/

	if (/*unsigned-suffix*/
		stream->current[0] == 'U' || stream->current[0] == 'u')
	{
		stream_match(stream);

		if (flags_opt)
		{
			*flags_opt |= TYPE_SPECIFIER_UNSIGNED;
		}

		/*long-suffixopt*/
		if (stream->current[0] == 'l' || stream->current[0] == 'L')
		{
			if (flags_opt)
			{
				*flags_opt = *flags_opt & ~TYPE_SPECIFIER_INT;
				*flags_opt |= TYPE_SPECIFIER_LONG;
			}
			stream_match(stream);
		}

		/*long-long-suffix*/
		if (stream->current[0] == 'l' || stream->current[0] == 'L')
		{
			if (flags_opt)
			{
				*flags_opt = *flags_opt & ~TYPE_SPECIFIER_LONG;
				*flags_opt |= TYPE_SPECIFIER_LONG_LONG;
			}

			stream_match(stream);
		}
	}
	else if ((stream->current[0] == 'l' || stream->current[0] == 'L'))
	{
		if (flags_opt)
		{
			*flags_opt = *flags_opt & ~TYPE_SPECIFIER_INT;
			*flags_opt |= TYPE_SPECIFIER_LONG;
		}

		/*long-suffix*/
		stream_match(stream);

		/*long-long-suffix*/
		if ((stream->current[0] == 'l' || stream->current[0] == 'L'))
		{
			if (flags_opt)
			{
				*flags_opt = *flags_opt & ~TYPE_SPECIFIER_LONG;
				*flags_opt |= TYPE_SPECIFIER_LONG_LONG;
			}
			stream_match(stream);
		}

		if (/*unsigned-suffix*/
			stream->current[0] == 'U' || stream->current[0] == 'u')
		{
			if (flags_opt)
			{
				*flags_opt |= TYPE_SPECIFIER_UNSIGNED;
			}
			stream_match(stream);
		}
	}
}

void exponent_part_opt(struct stream* stream)
{
	/*
	exponent-part:
	e signopt digit-sequence
	E signopt digit-sequence
	*/
	if (stream->current[0] == 'e' || stream->current[0] == 'E')
	{
		stream_match(stream);

		if (stream->current[0] == '-' || stream->current[0] == '+')
		{
			stream_match(stream);
		}
		digit_sequence(stream);
	}
}

enum type_specifier_flags floating_suffix_opt(struct stream* stream)
{
	enum type_specifier_flags f = TYPE_SPECIFIER_DOUBLE;


	if (stream->current[0] == 'l' || stream->current[0] == 'L')
	{
		f = TYPE_SPECIFIER_LONG | TYPE_SPECIFIER_DOUBLE;
		stream_match(stream);
	}
	else if (stream->current[0] == 'f' || stream->current[0] == 'F')
	{
		f = TYPE_SPECIFIER_FLOAT;
		stream_match(stream);
	}

	return f;
}

bool is_nonzero_digit(struct stream* stream)
{
	return stream->current[0] >= '1' && stream->current[0] <= '9';
}



enum token_type parse_number_core(struct stream* stream, enum type_specifier_flags* flags_opt)
{
	if (flags_opt)
	{
		*flags_opt = TYPE_SPECIFIER_INT;
	}


	enum token_type type = TK_NONE;
	if (stream->current[0] == '.')
	{
		type = TK_COMPILER_DECIMAL_FLOATING_CONSTANT;
		stream_match(stream);
		digit_sequence(stream);
		exponent_part_opt(stream);
		enum type_specifier_flags f = floating_suffix_opt(stream);
		if (flags_opt)
		{
			*flags_opt = f;
		}
	}
	else if (stream->current[0] == '0' && (stream->current[1] == 'x' || stream->current[1] == 'X'))
	{
		type = TK_COMPILER_HEXADECIMAL_CONSTANT;

		stream_match(stream);
		stream_match(stream);
		while (is_hexadecimal_digit(stream))
		{
			stream_match(stream);
		}

		integer_suffix_opt(stream, flags_opt);

		if (stream->current[0] == '.')
		{
			type = TK_COMPILER_HEXADECIMAL_FLOATING_CONSTANT;
			hexadecimal_digit_sequence(stream);
		}

		if (stream->current[0] == 'p' ||
			stream->current[0] == 'P')
		{
			type = TK_COMPILER_HEXADECIMAL_FLOATING_CONSTANT;
			binary_exponent_part(stream);
		}

		if (type == TK_COMPILER_HEXADECIMAL_FLOATING_CONSTANT)
		{
			enum type_specifier_flags f = floating_suffix_opt(stream);
			if (flags_opt)
			{
				*flags_opt = f;
			}
		}
	}
	else if (stream->current[0] == '0' && (stream->current[1] == 'b' || stream->current[1] == 'B'))
	{
		type = TK_COMPILER_BINARY_CONSTANT;
		stream_match(stream);
		stream_match(stream);
		while (is_binary_digit(stream))
		{
			stream_match(stream);
		}
		integer_suffix_opt(stream, flags_opt);
	}
	else if (stream->current[0] == '0') //octal
	{
		type = TK_COMPILER_OCTAL_CONSTANT;

		stream_match(stream);
		while (is_octal_digit(stream))
		{
			stream_match(stream);
		}
		integer_suffix_opt(stream, flags_opt);

		if (stream->current[0] == '.')
		{
			hexadecimal_digit_sequence(stream);
			enum type_specifier_flags f = floating_suffix_opt(stream);
			if (flags_opt)
			{
				*flags_opt = f;
			}
		}
	}
	else if (is_nonzero_digit(stream)) //decimal
	{
		type = TK_COMPILER_DECIMAL_CONSTANT;

		stream_match(stream);
		while (is_digit(stream))
		{
			stream_match(stream);
		}
		integer_suffix_opt(stream, flags_opt);

		if (stream->current[0] == 'e' || stream->current[0] == 'E')
		{
			exponent_part_opt(stream);
			enum type_specifier_flags f = floating_suffix_opt(stream);
			if (flags_opt)
			{
				*flags_opt = f;
			}
		}
		else if (stream->current[0] == '.')
		{
			stream_match(stream);
			type = TK_COMPILER_DECIMAL_FLOATING_CONSTANT;
			digit_sequence(stream);
			exponent_part_opt(stream);
			enum type_specifier_flags f = floating_suffix_opt(stream);
			if (flags_opt)
			{
				*flags_opt = f;
			}
		}
	}




	return type;
}


enum token_type parse_number(const char* lexeme, enum type_specifier_flags* flags_opt)
{
	struct stream stream = { .source = lexeme, .current = lexeme, .line = 1, .col = 1 };
	return parse_number_core(&stream, flags_opt);
}

static void pragma_skip_blanks(struct parser_ctx* ctx)
{
	while (ctx->current && ctx->current->type == TK_BLANKS)
	{
		ctx->current = ctx->current->next;
	}
}

/*
 * Some pragmas needs to be handled by the compiler
 */
static void parse_pragma(struct parser_ctx* ctx, struct token* token)
{
	if (ctx->current->type == TK_PRAGMA)
	{
		ctx->current = ctx->current->next;
		pragma_skip_blanks(ctx);

		if (ctx->current && strcmp(ctx->current->lexeme, "CAKE") == 0)
		{
			ctx->current = ctx->current->next;
			pragma_skip_blanks(ctx);
		}

		if (ctx->current && strcmp(ctx->current->lexeme, "nullchecks") == 0)
		{
			ctx->current = ctx->current->next;
			pragma_skip_blanks(ctx);

			//Isso nao esta funcionando pois esta informao precisa estar na AST.
			//pois eh usada em um segundo passo.
			bool onoff = false;
			if (ctx->current && strcmp(ctx->current->lexeme, "ON") == 0)
			{
				onoff = true;
			}
			else if (ctx->current && strcmp(ctx->current->lexeme, "OFF") == 0)
			{
				onoff = false;
			}
			else
			{
				compiler_set_error_with_token(C_PRAGMA_ERROR, ctx, ctx->current, "nullchecks pragma needs to use ON OFF");
			}
			ctx->options.null_checks = onoff;
		}

		if (ctx->current && strcmp(ctx->current->lexeme, "diagnostic") == 0)
		{
			ctx->current = ctx->current->next;
			pragma_skip_blanks(ctx);

			if (ctx->current && strcmp(ctx->current->lexeme, "push") == 0)
			{
				//#pragma GCC diagnostic push
				if (ctx->options.enabled_warnings_stack_top_index <
					sizeof(ctx->options.enabled_warnings_stack) / sizeof(ctx->options.enabled_warnings_stack[0]))
				{
					ctx->options.enabled_warnings_stack_top_index++;
					ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index] =
						ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index - 1];
				}
				ctx->current = ctx->current->next;
				pragma_skip_blanks(ctx);
			}
			else if (ctx->current && strcmp(ctx->current->lexeme, "pop") == 0)
			{
				//#pragma CAKE diagnostic pop
				if (ctx->options.enabled_warnings_stack_top_index > 0)
				{
					ctx->options.enabled_warnings_stack_top_index--;
				}
				ctx->current = ctx->current->next;
				pragma_skip_blanks(ctx);
			}
			else if (ctx->current && strcmp(ctx->current->lexeme, "warning") == 0)
			{
				//#pragma CAKE diagnostic warning "-Wenum-compare"

				ctx->current = ctx->current->next;
				pragma_skip_blanks(ctx);

				if (ctx->current && ctx->current->type == TK_STRING_LITERAL)
				{
					enum warning  w = get_warning_flag(ctx->current->lexeme + 1 + 2);
					ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index] |= w;
				}
			}
			else if (ctx->current && strcmp(ctx->current->lexeme, "ignore") == 0)
			{
				//#pragma CAKE diagnostic ignore "-Wenum-compare"

				ctx->current = ctx->current->next;
				pragma_skip_blanks(ctx);

				if (ctx->current && ctx->current->type == TK_STRING_LITERAL)
				{
					enum warning  w = get_warning_flag(ctx->current->lexeme + 1 + 2);
					ctx->options.enabled_warnings_stack[ctx->options.enabled_warnings_stack_top_index] &= ~w;
				}
			}
		}
	}
}

static struct token* parser_skip_blanks(struct parser_ctx* ctx)
{
	while (ctx->current && !(ctx->current->flags & TK_FLAG_FINAL))
	{

		if (ctx->current->type == TK_PRAGMA)
		{
			/*only active block have TK_PRAGMA*/
			parse_pragma(ctx, ctx->current);
		}

		if (ctx->current)
			ctx->current = ctx->current->next;
	}

	if (ctx->current)
	{
		token_promote(ctx->current); //transforma para token de parser
	}

	return ctx->current;
}


struct token* parser_match(struct parser_ctx* ctx)
{
	ctx->previous = ctx->current;
	ctx->current = ctx->current->next;
	parser_skip_blanks(ctx);

	return ctx->current;
}



int parser_match_tk(struct parser_ctx* ctx, enum token_type type)
{
	int error = 0;
	if (ctx->current != NULL)
	{
		if (ctx->current->type != type)
		{
			compiler_set_error_with_token(C_UNEXPECTED_TOKEN, ctx, ctx->current, "expected %s", get_token_name(type));
			error = 1;
		}

		ctx->previous = ctx->current;
		ctx->current = ctx->current->next;
		parser_skip_blanks(ctx);
	}
	else
	{
		compiler_set_error_with_token(C_UNEXPECTED_TOKEN, ctx, ctx->input_list.tail, "unexpected end of file after");
		error = 1;
	}

	return error;
}

void print_declaration_specifiers(struct osstream* ss, struct declaration_specifiers* p_declaration_specifiers)
{
	bool first = true;
	print_type_qualifier_flags(ss, &first, p_declaration_specifiers->type_qualifier_flags);

	if (p_declaration_specifiers->enum_specifier)
	{

		if (p_declaration_specifiers->enum_specifier->tag_token)
		{
			ss_fprintf(ss, "enum %s", p_declaration_specifiers->enum_specifier->tag_token->lexeme);
		}
		else
		{
			assert(false);
		}
	}
	else if (p_declaration_specifiers->struct_or_union_specifier)
	{
		ss_fprintf(ss, "struct %s", p_declaration_specifiers->struct_or_union_specifier->tag_name);
	}
	else if (p_declaration_specifiers->typedef_declarator)
	{
		print_item(ss, &first, p_declaration_specifiers->typedef_declarator->name->lexeme);
	}
	else
	{
		print_type_specifier_flags(ss, &first, p_declaration_specifiers->type_specifier_flags);
	}
}

bool type_specifier_is_integer(enum type_specifier_flags flags)
{
	if ((flags & TYPE_SPECIFIER_CHAR) ||
		(flags & TYPE_SPECIFIER_SHORT) ||
		(flags & TYPE_SPECIFIER_INT) ||
		(flags & TYPE_SPECIFIER_LONG) ||
		(flags & TYPE_SPECIFIER_INT) ||
		(flags & TYPE_SPECIFIER_INT8) ||
		(flags & TYPE_SPECIFIER_INT16) ||
		(flags & TYPE_SPECIFIER_INT32) ||
		(flags & TYPE_SPECIFIER_INT64) ||
		(flags & TYPE_SPECIFIER_LONG_LONG))
	{
		return true;
	}
	return false;
}

int final_specifier(struct parser_ctx* ctx, enum type_specifier_flags* flags)
{
	if (((*flags) & TYPE_SPECIFIER_UNSIGNED) ||
		((*flags) & TYPE_SPECIFIER_SIGNED))
	{
		if (!type_specifier_is_integer(*flags))
		{
			//se nao especificou nada vira integer
			(*flags) |= TYPE_SPECIFIER_INT;
		}
	}

	return 0;
}

int add_specifier(struct parser_ctx* ctx,
	enum type_specifier_flags* flags,
	enum type_specifier_flags new_flag
)
{
	/*
	* Verifica as combinaçòes possíveis
	*/

	if (new_flag & TYPE_SPECIFIER_LONG) //adicionando um long
	{
		if ((*flags) & TYPE_SPECIFIER_LONG_LONG) //ja tinha long long
		{
			compiler_set_error_with_token(C_CANNOT_COMBINE_WITH_PREVIOUS_LONG_LONG, ctx, ctx->current, "cannot combine with previous 'long long' declaration specifier");
			return 1;
		}
		else if ((*flags) & TYPE_SPECIFIER_LONG) //ja tinha um long
		{
			(*flags) = (*flags) & ~TYPE_SPECIFIER_LONG;
			(*flags) |= TYPE_SPECIFIER_LONG_LONG;
		}
		else //nao tinha nenhum long
		{
			(*flags) = (*flags) & ~TYPE_SPECIFIER_INT;
			(*flags) |= TYPE_SPECIFIER_LONG;
		}
	}
	else
	{
		(*flags) |= new_flag;
	}
	return 0;
}

void declaration_specifiers_delete(struct declaration_specifiers* owner p)
{
	if (p)
	{
		struct declaration_specifier* owner item = p->head;
		while (item)
		{
			struct declaration_specifier* owner next = item->next;
			item->next = NULL;
			declaration_specifier_delete(item);
			item = next;
		}
		free(p);
	}
}

struct declaration_specifiers* owner declaration_specifiers(struct parser_ctx* ctx,
	enum storage_class_specifier_flags default_storage_flag)
{
	/*
		declaration-specifiers:
		  declaration-specifier attribute-specifier-sequence_opt
		  declaration-specifier declaration-specifiers
	*/

	/*
	 Ao fazer parser do segundo o X ja existe mas ele nao deve ser usado
	 typedef char X;
	 typedef char X;
	*/

	struct declaration_specifiers* owner p_declaration_specifiers = calloc(1, sizeof(struct declaration_specifiers));

	try
	{
		if (p_declaration_specifiers == NULL)
			throw;

		static_set(p_declaration_specifiers, "not-null");
		p_declaration_specifiers->first_token = ctx->current;

		while (first_of_declaration_specifier(ctx))
		{
			if (ctx->current->flags & TK_FLAG_IDENTIFIER_IS_TYPEDEF)
			{
				if (p_declaration_specifiers->type_specifier_flags != TYPE_SPECIFIER_NONE)
				{
					//typedef tem que aparecer sozinho
					//exemplo Socket eh nome e nao typdef
					//typedef int Socket;
					//struct X {int Socket;}; 
					break;
				}
			}

			struct declaration_specifier* owner p_declaration_specifier = declaration_specifier(ctx);

			if (p_declaration_specifier->type_specifier_qualifier)
			{
				if (p_declaration_specifier->type_specifier_qualifier)
				{
					if (p_declaration_specifier->type_specifier_qualifier->type_specifier)
					{

						if (add_specifier(ctx,
							&p_declaration_specifiers->type_specifier_flags,
							p_declaration_specifier->type_specifier_qualifier->type_specifier->flags) != 0)
						{
							declaration_specifier_delete(p_declaration_specifier);
							throw;
						}


						if (p_declaration_specifier->type_specifier_qualifier->type_specifier->struct_or_union_specifier)
						{
							p_declaration_specifiers->struct_or_union_specifier = p_declaration_specifier->type_specifier_qualifier->type_specifier->struct_or_union_specifier;
						}
						else if (p_declaration_specifier->type_specifier_qualifier->type_specifier->enum_specifier)
						{
							p_declaration_specifiers->enum_specifier = p_declaration_specifier->type_specifier_qualifier->type_specifier->enum_specifier;
						}
						else if (p_declaration_specifier->type_specifier_qualifier->type_specifier->typeof_specifier)
						{
							p_declaration_specifiers->typeof_specifier = p_declaration_specifier->type_specifier_qualifier->type_specifier->typeof_specifier;
						}
						else if (p_declaration_specifier->type_specifier_qualifier->type_specifier->token &&
							p_declaration_specifier->type_specifier_qualifier->type_specifier->token->type == TK_IDENTIFIER)
						{
							p_declaration_specifiers->typedef_declarator =
								find_declarator(ctx,
									p_declaration_specifier->type_specifier_qualifier->type_specifier->token->lexeme,
									NULL);

							//p_declaration_specifiers->typedef_declarator = p_declaration_specifier->type_specifier_qualifier->pType_specifier->token->lexeme;
						}
					}
					else if (p_declaration_specifier->type_specifier_qualifier->type_qualifier)
					{
						p_declaration_specifiers->type_qualifier_flags |= p_declaration_specifier->type_specifier_qualifier->type_qualifier->flags;

					}
				}
			}
			else if (p_declaration_specifier->storage_class_specifier)
			{
				p_declaration_specifiers->storage_class_specifier_flags |= p_declaration_specifier->storage_class_specifier->flags;
			}

			LIST_ADD(p_declaration_specifiers, p_declaration_specifier);
			//attribute_specifier_sequence_opt(ctx);

			if (ctx->current->type == TK_IDENTIFIER &&
				p_declaration_specifiers->type_specifier_flags != TYPE_SPECIFIER_NONE)
			{
				//typedef nao pode aparecer com outro especifier
				//entao ja tem tem algo e vier identifier signfica que acabou 
				//exemplo
				/*
				 typedef char X;
				 typedef char X;
				*/
				break;
			}
		}
		p_declaration_specifiers->last_token = previous_parser_token(ctx->current);
	}
	catch
	{
	}

	if (p_declaration_specifiers)
	{
		//int main() { static int i; } // i is not automatic
		final_specifier(ctx, &p_declaration_specifiers->type_specifier_flags);
	}


	p_declaration_specifiers->storage_class_specifier_flags |= default_storage_flag;

	if (p_declaration_specifiers->storage_class_specifier_flags & STORAGE_SPECIFIER_STATIC)
	{
		//
		p_declaration_specifiers->storage_class_specifier_flags &= ~STORAGE_SPECIFIER_AUTOMATIC_STORAGE;
	}

	return p_declaration_specifiers;
}

struct declaration* owner declaration_core(struct parser_ctx* ctx,
	struct attribute_specifier_sequence* owner p_attribute_specifier_sequence_opt /*SINK*/,
	bool can_be_function_definition,
	bool* is_function_definition,
	bool* flow_analysis,
	enum storage_class_specifier_flags default_storage_class_specifier_flags
)
{
	/*
								  declaration-specifiers init-declarator-list_opt ;
	 attribute-specifier-sequence declaration-specifiers init-declarator-list ;
	 static_assert-declaration
	 attribute-declaration
  */


	struct declaration* owner p_declaration = calloc(1, sizeof(struct declaration));

	p_declaration->p_attribute_specifier_sequence_opt = p_attribute_specifier_sequence_opt;

	p_declaration->first_token = ctx->current;

	if (ctx->current->type == ';')
	{
		parser_match_tk(ctx, ';');
		//declaracao vazia nao eh erro
		return p_declaration;
	}

	if (first_of_static_assert_declaration(ctx))
	{
		p_declaration->static_assert_declaration = static_assert_declaration(ctx);
	}
	else
	{

		if (first_of_declaration_specifier(ctx))
		{
			p_declaration->declaration_specifiers = declaration_specifiers(ctx, default_storage_class_specifier_flags);

			if (p_declaration->p_attribute_specifier_sequence_opt)
			{
				p_declaration->declaration_specifiers->attributes_flags =
					p_declaration->p_attribute_specifier_sequence_opt->attributes_flags;
			}

			if (ctx->current->type != ';')
			{
				p_declaration->init_declarator_list = init_declarator_list(ctx,
					p_declaration->declaration_specifiers);
			}


			p_declaration->last_token = ctx->current;

			if (ctx->current->type == '{')
			{
				if (can_be_function_definition)
					*is_function_definition = true;
			}
			else if (ctx->current->type == TK_STRING_LITERAL &&
				strcmp(ctx->current->lexeme, "\"unchecked\"") == 0)
			{
				parser_match(ctx);
				if (can_be_function_definition)
					*is_function_definition = true;
				if (flow_analysis)
					*flow_analysis = false;

			}
			else
				parser_match_tk(ctx, ';');
		}
		else
		{
			if (ctx->current->type == TK_IDENTIFIER)
			{
				compiler_set_error_with_token(C_INVALID_TYPE, ctx, ctx->current, "invalid type '%s'", ctx->current->lexeme);
			}
			else
			{
				compiler_set_error_with_token(C_EXPECTED_DECLARATION, ctx, ctx->current, "expected declaration not '%s'", ctx->current->lexeme);
			}
			parser_match(ctx); //we need to go ahead
		}
	}


	return p_declaration;
}

struct declaration* owner function_definition_or_declaration(struct parser_ctx* ctx)
{
	/*
	 function-definition:
		attribute-specifier-sequence opt declaration-specifiers declarator function-body
	*/

	/*
	  declaration:
		declaration-specifiers                              init-declarator-list opt ;
		attribute-specifier-sequence declaration-specifiers init-declarator-list ;
		static_assert-declaration
		attribute-declaration
	*/

	struct attribute_specifier_sequence* owner p_attribute_specifier_sequence_opt =
		attribute_specifier_sequence_opt(ctx);


	bool is_function_definition = false;
	bool flow_analysis = true;
	struct declaration* owner p_declaration = declaration_core(ctx, p_attribute_specifier_sequence_opt, true, &is_function_definition, &flow_analysis, STORAGE_SPECIFIER_EXTERN);
	if (is_function_definition)
	{

		ctx->p_current_function_opt = p_declaration;
		//tem que ter 1 so
		//tem 1 que ter  1 cara e ser funcao
		assert(p_declaration->init_declarator_list.head->p_declarator->direct_declarator->function_declarator);

		/*
			scope of parameters is the inner declarator

			void (*f(int i))(void) {
				i = 1;
				return 0;
			}
		*/

		struct declarator* inner = p_declaration->init_declarator_list.head->p_declarator;
		for (;;)
		{
			if (inner->direct_declarator &&
				inner->direct_declarator->function_declarator &&
				inner->direct_declarator->function_declarator->direct_declarator &&
				inner->direct_declarator->function_declarator->direct_declarator->declarator)
			{
				inner = inner->direct_declarator->function_declarator->direct_declarator->declarator;
			}
			else
				break;
		}

		struct scope* parameters_scope = &inner->direct_declarator->function_declarator->parameters_scope;
		scope_list_push(&ctx->scopes, parameters_scope);


		check_func_open_brace_style(ctx, ctx->current);

		bool disable_ownership_errors = ctx->options.disable_ownership_errors;
		if (!flow_analysis)
		{
			/*let's disable ownership type error*/
			ctx->options.disable_ownership_errors = true;
		}

		assert(p_declaration->function_body == NULL);
		p_declaration->function_body = function_body(ctx);

		ctx->options.disable_ownership_errors = disable_ownership_errors; /*restore*/

		p_declaration->init_declarator_list.head->p_declarator->function_body = p_declaration->function_body;


		if (ctx->options.flow_analysis && flow_analysis)
		{
			/*
			 Now we have the full function AST let´s visit to analise
			 jumps
			*/

			struct flow_visit_ctx ctx2 = { 0 };
			ctx2.ctx = ctx;
			flow_visit_function(&ctx2, p_declaration);
			flow_visit_ctx_destroy(&ctx2);
		}

		struct parameter_declaration* parameter = NULL;

		if (p_declaration->init_declarator_list.head->p_declarator->direct_declarator->function_declarator &&
			p_declaration->init_declarator_list.head->p_declarator->direct_declarator->function_declarator->parameter_type_list_opt &&
			p_declaration->init_declarator_list.head->p_declarator->direct_declarator->function_declarator->parameter_type_list_opt->parameter_list)
		{
			parameter = p_declaration->init_declarator_list.head->p_declarator->direct_declarator->function_declarator->parameter_type_list_opt->parameter_list->head;
		}

		/*parametros nao usados*/
		while (parameter)
		{
			if (!type_is_maybe_unused(&parameter->declarator->type) &&
				parameter->declarator->num_uses == 0)
			{
				if (parameter->declarator->name &&
					parameter->declarator->name->level == 0 /*direct source*/
					)
				{
					compiler_set_warning_with_token(W_UNUSED_PARAMETER,
						ctx,
						parameter->declarator->name,
						"'%s': unreferenced formal parameter",
						parameter->declarator->name->lexeme);
				}
			}
			parameter = parameter->next;
		}


		scope_list_pop(&ctx->scopes);
		ctx->p_current_function_opt = NULL;
	}


	return p_declaration;
}

struct declaration* owner declaration(struct parser_ctx* ctx,
	struct attribute_specifier_sequence* owner p_attribute_specifier_sequence_opt,
	enum storage_class_specifier_flags storage_specifier_flags
)
{
	bool is_function_definition = false;
	bool flow_analysis = false;
	return declaration_core(ctx, p_attribute_specifier_sequence_opt, false, &is_function_definition, &flow_analysis, storage_specifier_flags);
}


//(6.7) declaration-specifiers:
//declaration-specifier attribute-specifier-sequenceopt
//declaration-specifier declaration-specifiers


void declaration_specifier_delete(struct declaration_specifier* owner p)
{
	if (p)
	{
		free(p->function_specifier);
		type_specifier_qualifier_delete(p->type_specifier_qualifier);
		free(p->storage_class_specifier);
		assert(p->next == NULL);
		free(p);
	}
}

struct declaration_specifier* owner declaration_specifier(struct parser_ctx* ctx)
{
	//    storage-class-specifier
	//    type-specifier-qualifier
	//    function-specifier
	struct declaration_specifier* owner p_declaration_specifier = calloc(1, sizeof * p_declaration_specifier);
	if (first_of_storage_class_specifier(ctx))
	{
		p_declaration_specifier->storage_class_specifier = storage_class_specifier(ctx);
	}
	else if (first_of_type_specifier_qualifier(ctx))
	{
		p_declaration_specifier->type_specifier_qualifier = type_specifier_qualifier(ctx);
	}
	else if (first_of_function_specifier(ctx))
	{
		p_declaration_specifier->function_specifier = function_specifier(ctx);
	}
	else
	{
		compiler_set_error_with_token(C_UNEXPECTED, ctx, ctx->current, "unexpected");
	}
	return p_declaration_specifier;
}

void init_declarator_delete(struct init_declarator* owner p)
{
	if (p)
	{
		initializer_delete(p->initializer);
		declarator_delete(p->p_declarator);
		assert(p->next == NULL);
		free(p);
	}
}
struct init_declarator* owner init_declarator(struct parser_ctx* ctx,
	struct declaration_specifiers* p_declaration_specifiers)
{
	/*
	 init-declarator:
	   declarator
	   declarator = initializer
	*/
	struct init_declarator* owner p_init_declarator = calloc(1, sizeof(struct init_declarator));
	try
	{
		struct token* tkname = 0;
		p_init_declarator->p_declarator = declarator(ctx,
			NULL,
			p_declaration_specifiers,
			false,
			&tkname);

		if (p_init_declarator->p_declarator == NULL) throw;
		p_init_declarator->p_declarator->name = tkname;

		if (tkname == NULL)
		{
			compiler_set_error_with_token(C_UNEXPECTED, ctx, ctx->current, "empty declarator name?? unexpected");
			return p_init_declarator;
		}

		p_init_declarator->p_declarator->declaration_specifiers = p_declaration_specifiers;
		p_init_declarator->p_declarator->name = tkname;

		if (p_init_declarator->p_declarator->declaration_specifiers->storage_class_specifier_flags & STORAGE_SPECIFIER_AUTO)
		{
			/*
			  auto requires we find the type after initializer
			*/
		}
		else
		{
			assert(p_init_declarator->p_declarator->type.type_specifier_flags == 0);
			p_init_declarator->p_declarator->type = make_type_using_declarator(ctx, p_init_declarator->p_declarator);
		}

		const char* name = p_init_declarator->p_declarator->name->lexeme;
		if (name)
		{
			if (tkname)
			{
				/*
				  Checking nameming conventions
				*/
				if (ctx->scopes.tail->scope_level == 0)
				{
					if (type_is_function(&p_init_declarator->p_declarator->type))
					{
						naming_convention_global_var(ctx,
							tkname,
							&p_init_declarator->p_declarator->type,
							p_init_declarator->p_declarator->declaration_specifiers->storage_class_specifier_flags);
					}
					else
					{
						naming_convention_global_var(ctx,
							tkname,
							&p_init_declarator->p_declarator->type,
							p_init_declarator->p_declarator->declaration_specifiers->storage_class_specifier_flags);
					}
				}
			}

			struct scope* out_scope = NULL;
			struct declarator* previous = find_declarator(ctx, name, &out_scope);
			if (previous)
			{
				if (out_scope->scope_level == ctx->scopes.tail->scope_level)
				{
					if (out_scope->scope_level == 0)
					{
						/*file scope*/
						if (!type_is_same(&previous->type, &p_init_declarator->p_declarator->type, true))
						{
							//TODO failing on windows headers
							//parser_seterror_with_token(ctx, p_init_declarator->declarator->name, "redeclaration of  '%s' with diferent types", previous->name->lexeme);
							//parser_set_info_with_token(ctx, previous->name, "previous declaration");
						}
					}
					else
					{
						compiler_set_error_with_token(C_REDECLARATION, ctx, ctx->current, "redeclaration");
						compiler_set_info_with_token(W_NONE, ctx, previous->name, "previous declaration");
					}
				}
				else
				{
					hashmap_set(&ctx->scopes.tail->variables, name, p_init_declarator, TAG_TYPE_INIT_DECLARATOR);

					/*global scope no warning...*/
					if (out_scope->scope_level != 0)
					{
						/*but redeclaration at function scope we show warning*/
						if (compiler_set_warning_with_token(W_DECLARATOR_HIDE, ctx, p_init_declarator->p_declarator->first_token, "declaration of '%s' hides previous declaration", name))
						{
							compiler_set_info_with_token(W_NONE, ctx, previous->first_token, "previous declaration is here");
						}
					}
				}
			}
			else
			{
				/*first time we see this declarator*/
				hashmap_set(&ctx->scopes.tail->variables, name, p_init_declarator, TAG_TYPE_INIT_DECLARATOR);
			}
		}
		else
		{
			assert(false);
		}

		if (ctx->current && ctx->current->type == '=')
		{
			parser_match(ctx);
			p_init_declarator->initializer = initializer(ctx);
			if (p_init_declarator->initializer->braced_initializer)
			{
				if (type_is_array(&p_init_declarator->p_declarator->type))
				{
					const int sz = type_get_array_size(&p_init_declarator->p_declarator->type);
					if (sz == 0)
					{
						/*int a[] = {1, 2, 3}*/
						const int braced_initializer_size =
							p_init_declarator->initializer->braced_initializer->initializer_list->size;
						type_set_array_size(&p_init_declarator->p_declarator->type, braced_initializer_size);
					}
				}

				/*
				  Fixing the type of auto declarator
				  ??
				*/
			}
			else if (p_init_declarator->initializer->assignment_expression)
			{
				/*
				  Fixing the type of auto declarator
				*/
				if (p_init_declarator->p_declarator->declaration_specifiers->storage_class_specifier_flags & STORAGE_SPECIFIER_AUTO)
				{
					struct type t = { 0 };

					if (p_init_declarator->initializer->assignment_expression->expression_type == UNARY_EXPRESSION_ADDRESSOF)
					{
						t = type_dup(&p_init_declarator->initializer->assignment_expression->type);
					}
					else
					{
						struct type t2 = type_lvalue_conversion(&p_init_declarator->initializer->assignment_expression->type);
						type_swap(&t2, &t);
						type_destroy(&t2);
					}

					type_remove_names(&t);
					assert(t.name_opt == NULL);
					t.name_opt = strdup(p_init_declarator->p_declarator->name->lexeme);

					type_set_qualifiers_using_declarator(&t, p_init_declarator->p_declarator);
					//storage qualifiers?

					type_visit_to_mark_anonymous(&t);
					type_swap(&p_init_declarator->p_declarator->type, &t);
					type_destroy(&t);
				}

				/*
				  Checking for "const qualifier discarded"
				*/
				if (type_is_pointer_to_const(&p_init_declarator->initializer->assignment_expression->type))
				{
					if (p_init_declarator->p_declarator &&
						!type_is_pointer_to_const(&p_init_declarator->p_declarator->type))
					{
						compiler_set_warning_with_token(W_DISCARDED_QUALIFIERS, ctx, ctx->current, "const qualifier discarded");
					}
				}

				if (type_is_owner(&p_init_declarator->initializer->assignment_expression->type))
				{
					if (p_init_declarator->initializer->assignment_expression->expression_type == POSTFIX_FUNCTION_CALL)
					{
						//type * p = f();
						if (!type_is_owner(&p_init_declarator->p_declarator->type))
						{
							compiler_set_error_with_token(C_OWNERSHIP_MISSING_OWNER_QUALIFIER, ctx, p_init_declarator->p_declarator->first_token, "missing owner qualifier");
						}
					}
				}

				if (type_is_owner(&p_init_declarator->p_declarator->type))
				{
					if (!type_is_owner(&p_init_declarator->initializer->assignment_expression->type))
					{
						const bool is_zero =
							constant_value_is_valid(&p_init_declarator->initializer->assignment_expression->constant_value) &&
							constant_value_to_bool(&p_init_declarator->initializer->assignment_expression->constant_value) == false;

						if (!is_zero)
						{
							compiler_set_error_with_token(C_OWNERSHIP_MISSING_OWNER_QUALIFIER,
								ctx,
								p_init_declarator->p_declarator->first_token, "cannot initialize an owner type with a non owner");
						}
						else
						{
							/*
								 T * owner p =  NULL; // OK
							*/
						}
					}
				}

			}
		}
	}
	catch
	{
	}

	/*
	   checking usage of [static ] other than in function arguments
	*/
	if (p_init_declarator->p_declarator)
	{
		if (type_is_array(&p_init_declarator->p_declarator->type))
			if (p_init_declarator->p_declarator->type.type_qualifier_flags != 0 ||
				p_init_declarator->p_declarator->type.static_array)
			{
				compiler_set_error_with_token(C_STATIC_OR_TYPE_QUALIFIERS_NOT_ALLOWED_IN_NON_PARAMETER,
					ctx,
					p_init_declarator->p_declarator->first_token,
					"static or type qualifiers are not allowed in non-parameter array declarator");
			}


		if (!type_is_pointer(&p_init_declarator->p_declarator->type) &&
			p_init_declarator->p_declarator->type.type_qualifier_flags & TYPE_QUALIFIER_OBJ_OWNER)
		{
			compiler_set_error_with_token(C_OBJ_OWNER_CAN_BE_USED_ONLY_IN_POINTER,
				ctx,
				p_init_declarator->p_declarator->first_token,
				"obj_owner qualifier can only be used with pointers");
		}
	}

	return p_init_declarator;
}

void init_declarator_list_destroy(struct init_declarator_list* obj_owner p)
{
	struct init_declarator* owner item = p->head;
	while (item)
	{
		struct init_declarator* owner next = item->next;
		item->next = NULL;
		init_declarator_delete(item);
		item = next;
	}
}

struct init_declarator_list init_declarator_list(struct parser_ctx* ctx,
	struct declaration_specifiers* p_declaration_specifiers)
{
	/*
	init-declarator-list:
	  init-declarator
	  init-declarator-list , init-declarator
	*/
	struct init_declarator_list init_declarator_list = { 0 };
	struct init_declarator* owner p_init_declarator = NULL;

	try
	{
		p_init_declarator = init_declarator(ctx, p_declaration_specifiers);

		if (p_init_declarator == NULL) throw;
		LIST_ADD(&init_declarator_list, p_init_declarator);
		p_init_declarator = NULL; /*MOVED*/

		while (ctx->current != NULL && ctx->current->type == ',')
		{
			parser_match(ctx);
			p_init_declarator = init_declarator(ctx, p_declaration_specifiers);
			if (p_init_declarator == NULL) throw;
			LIST_ADD(&init_declarator_list, p_init_declarator);
			p_init_declarator = NULL; /*MOVED*/
		}
	}
	catch
	{
	}

	return init_declarator_list;
}

void storage_class_specifier_delete(struct storage_class_specifier* owner p)
{
	if (p)
	{
		free(p);
	}
}

struct storage_class_specifier* owner storage_class_specifier(struct parser_ctx* ctx)
{
	if (ctx->current == NULL)
		return NULL;

	struct storage_class_specifier* owner new_storage_class_specifier = calloc(1, sizeof(struct storage_class_specifier));
	if (new_storage_class_specifier == NULL)
		return NULL;

	new_storage_class_specifier->token = ctx->current;
	switch (ctx->current->type)
	{
	case TK_KEYWORD_TYPEDEF:
		new_storage_class_specifier->flags = STORAGE_SPECIFIER_TYPEDEF;
		break;
	case TK_KEYWORD_EXTERN:
		new_storage_class_specifier->flags = STORAGE_SPECIFIER_EXTERN;
		break;
	case TK_KEYWORD_CONSTEXPR:

		new_storage_class_specifier->flags = STORAGE_SPECIFIER_CONSTEXPR;
		if (ctx->scopes.tail->scope_level == 0)
			new_storage_class_specifier->flags |= STORAGE_SPECIFIER_CONSTEXPR_STATIC;
		break;
	case TK_KEYWORD_STATIC:
		new_storage_class_specifier->flags = STORAGE_SPECIFIER_STATIC;
		break;
	case TK_KEYWORD__THREAD_LOCAL:
		new_storage_class_specifier->flags = STORAGE_SPECIFIER_THREAD_LOCAL;
		break;
	case TK_KEYWORD_AUTO:
		new_storage_class_specifier->flags = STORAGE_SPECIFIER_AUTO;
		break;
	case TK_KEYWORD_REGISTER:
		new_storage_class_specifier->flags = STORAGE_SPECIFIER_REGISTER;
		break;
	default:
		assert(false);
	}

	/*
	 TODO
	 thread_local may appear with static or extern,
	 auto may appear with all the others except typedef138), and
	 constexpr may appear with auto, register, or static.
	*/

	parser_match(ctx);
	return new_storage_class_specifier;
}

struct typeof_specifier_argument* owner typeof_specifier_argument(struct parser_ctx* ctx)
{
	struct typeof_specifier_argument* owner new_typeof_specifier_argument = calloc(1, sizeof(struct typeof_specifier_argument));
	if (new_typeof_specifier_argument == NULL)
		return NULL;
	try
	{
		if (first_of_type_name(ctx))
		{
			new_typeof_specifier_argument->type_name = type_name(ctx);
		}
		else
		{
			const bool disable_evaluation_copy = ctx->evaluation_is_disabled;
			ctx->evaluation_is_disabled = true;
			new_typeof_specifier_argument->expression = expression(ctx);
			/*restore*/
			ctx->evaluation_is_disabled = disable_evaluation_copy;

			if (new_typeof_specifier_argument->expression == NULL) throw;

			//declarator_type_clear_name(new_typeof_specifier_argument->expression->type.declarator_type);
		}
	}
	catch
	{
	}
	return new_typeof_specifier_argument;
}

bool first_of_typeof_specifier(struct parser_ctx* ctx)
{
	if (ctx->current == NULL)
		return false;

	return ctx->current->type == TK_KEYWORD_TYPEOF ||
		ctx->current->type == TK_KEYWORD_TYPEOF_UNQUAL;
}

struct typeof_specifier* owner typeof_specifier(struct parser_ctx* ctx)
{
	struct typeof_specifier* owner p_typeof_specifier = NULL;
	try
	{
		p_typeof_specifier = calloc(1, sizeof(struct typeof_specifier));
		if (p_typeof_specifier == NULL) throw;

		p_typeof_specifier->first_token = ctx->current;

		const bool is_typeof_unqual = ctx->current->type == TK_KEYWORD_TYPEOF_UNQUAL;
		parser_match(ctx);
		if (parser_match_tk(ctx, '(') != 0) throw;

		p_typeof_specifier->typeof_specifier_argument = typeof_specifier_argument(ctx);
		if (p_typeof_specifier->typeof_specifier_argument == NULL) throw;

		if (p_typeof_specifier->typeof_specifier_argument->expression)
		{
			p_typeof_specifier->type = type_dup(&p_typeof_specifier->typeof_specifier_argument->expression->type);
		}
		else if (p_typeof_specifier->typeof_specifier_argument->type_name)
		{
			p_typeof_specifier->type = type_dup(&p_typeof_specifier->typeof_specifier_argument->type_name->declarator->type);
		}

		if (p_typeof_specifier->type.storage_class_specifier_flags & STORAGE_SPECIFIER_PARAMETER)
		{
			compiler_set_warning_with_token(W_TYPEOF_ARRAY_PARAMETER, ctx, ctx->current, "typeof used in array arguments");

			if (type_is_array(&p_typeof_specifier->type))
			{
				struct type t = type_param_array_to_pointer(&p_typeof_specifier->type);
				type_swap(&t, &p_typeof_specifier->type);
				type_destroy(&t);
			}

		}

		if (is_typeof_unqual)
		{
			type_remove_qualifiers(&p_typeof_specifier->type);
		}

		type_visit_to_mark_anonymous(&p_typeof_specifier->type);

		free((void* owner) p_typeof_specifier->type.name_opt);
		p_typeof_specifier->type.name_opt = NULL;

		p_typeof_specifier->last_token = ctx->current;
		parser_match_tk(ctx, ')');
	}
	catch
	{
	}

	return p_typeof_specifier;
}

void typeof_specifier_argument_delete(struct typeof_specifier_argument* owner p)
{
	if (p)
	{
		expression_delete(p->expression);
		type_name_delete(p->type_name);
		free(p);
	}

}

void typeof_specifier_delete(struct typeof_specifier* owner p)
{
	if (p)
	{
		typeof_specifier_argument_delete(p->typeof_specifier_argument);
		type_destroy(&p->type);
		free(p);
	}
}
void type_specifier_delete(struct type_specifier* owner p)
{
	if (p)
	{
		struct_or_union_specifier_delete(p->struct_or_union_specifier);
		typeof_specifier_delete(p->typeof_specifier);
		enum_specifier_delete(p->enum_specifier);
		atomic_type_specifier_delete(p->atomic_type_specifier);
		free(p);
	}
}
struct type_specifier* owner type_specifier(struct parser_ctx* ctx)
{
	/*
	 type-specifier:
	   void
	   char
	   short
	   int
	   long
	   float
	   double
	   signed
	   unsigned
	   _BitInt ( constant-expression )
	   bool                                  C23
	   _Complex
	   _Decimal32
	   _Decimal64
	   _Decimal128
	   atomic-type-specifier
	   struct-or-union-specifier
	   enum-specifier
	   typedef-name
	   typeof-specifier                      C23
	*/

	struct type_specifier* owner p_type_specifier = calloc(1, sizeof * p_type_specifier);
	if (p_type_specifier == NULL)
		return NULL;




	switch (ctx->current->type)
	{
	case TK_KEYWORD_VOID:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_VOID;
		parser_match(ctx);
		return p_type_specifier;

	case TK_KEYWORD_CHAR:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_CHAR;
		parser_match(ctx);
		return p_type_specifier;

	case TK_KEYWORD_SHORT:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_SHORT;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;

	case TK_KEYWORD_INT:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_INT;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;

		//microsoft
	case TK_KEYWORD__INT8:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_INT8;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;

	case TK_KEYWORD__INT16:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_INT16;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;
	case TK_KEYWORD__INT32:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_INT32;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;
	case TK_KEYWORD__INT64:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_INT64;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;
		//end microsoft

	case TK_KEYWORD_LONG:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_LONG;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;

	case TK_KEYWORD_FLOAT:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_FLOAT;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;

	case TK_KEYWORD_DOUBLE:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_DOUBLE;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;

	case TK_KEYWORD_SIGNED:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_SIGNED;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;

	case TK_KEYWORD_UNSIGNED:

		p_type_specifier->flags = TYPE_SPECIFIER_UNSIGNED;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;

	case TK_KEYWORD__BOOL:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_BOOL;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;

	case TK_KEYWORD__COMPLEX:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_COMPLEX;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;

	case TK_KEYWORD__DECIMAL32:
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_DECIMAL32;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;

	case TK_KEYWORD__DECIMAL64:

		p_type_specifier->flags = TYPE_SPECIFIER_DECIMAL64;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;

	case TK_KEYWORD__DECIMAL128:
		p_type_specifier->flags = TYPE_SPECIFIER_DECIMAL128;
		p_type_specifier->token = ctx->current;
		parser_match(ctx);
		return p_type_specifier;


	}



	if (first_of_typeof_specifier(ctx))
	{
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_TYPEOF;
		p_type_specifier->typeof_specifier = typeof_specifier(ctx);
	}
	else if (first_of_atomic_type_specifier(ctx))
	{
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_ATOMIC;
		p_type_specifier->atomic_type_specifier = atomic_type_specifier(ctx);
	}
	else if (first_of_struct_or_union(ctx))
	{
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_STRUCT_OR_UNION;
		p_type_specifier->struct_or_union_specifier = struct_or_union_specifier(ctx);
	}
	else if (first_of_enum_specifier(ctx))
	{
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_ENUM;
		p_type_specifier->enum_specifier = enum_specifier(ctx);
	}
	else if (ctx->current->type == TK_IDENTIFIER)
	{
		p_type_specifier->token = ctx->current;
		p_type_specifier->flags = TYPE_SPECIFIER_TYPEDEF;

		p_type_specifier->typedef_declarator =
			find_declarator(ctx, ctx->current->lexeme, NULL);

		//Ser chegou aqui já tem que exitir (reaprovecitar?)
		assert(p_type_specifier->typedef_declarator != NULL);

		parser_match(ctx);
	}


	return p_type_specifier;
}



struct struct_or_union_specifier* get_complete_struct_or_union_specifier(struct struct_or_union_specifier* p_struct_or_union_specifier)
{
	if (p_struct_or_union_specifier == NULL)
		return NULL;

	if (p_struct_or_union_specifier->member_declaration_list.head)
	{
		/*p_struct_or_union_specifier is complete*/
		return p_struct_or_union_specifier;
	}
	else if (p_struct_or_union_specifier->complete_struct_or_union_specifier_indirection &&
		p_struct_or_union_specifier->complete_struct_or_union_specifier_indirection->member_declaration_list.head)
	{
		/*p_struct_or_union_specifier is the first seem tag tag points directly to complete*/
		return p_struct_or_union_specifier->complete_struct_or_union_specifier_indirection;
	}
	else if (p_struct_or_union_specifier->complete_struct_or_union_specifier_indirection &&
		p_struct_or_union_specifier->complete_struct_or_union_specifier_indirection->complete_struct_or_union_specifier_indirection &&
		p_struct_or_union_specifier->complete_struct_or_union_specifier_indirection->complete_struct_or_union_specifier_indirection->member_declaration_list.head)
	{
		/* all others points to the first seem that points to the complete*/
		return p_struct_or_union_specifier->complete_struct_or_union_specifier_indirection->complete_struct_or_union_specifier_indirection;
	}

	return NULL;
}

bool struct_or_union_specifier_is_complete(struct struct_or_union_specifier* p_struct_or_union_specifier)
{
	return
		get_complete_struct_or_union_specifier(p_struct_or_union_specifier) != NULL;
}

void struct_or_union_specifier_delete(struct struct_or_union_specifier* owner p)
{
	if (p)
	{
		member_declaration_list_destroy(&p->member_declaration_list);
		attribute_specifier_sequence_delete(p->attribute_specifier_sequence_opt);
		free(p);
	}
}

struct struct_or_union_specifier* owner struct_or_union_specifier(struct parser_ctx* ctx)
{
	struct struct_or_union_specifier* owner p_struct_or_union_specifier = calloc(1, sizeof * p_struct_or_union_specifier);

	if (p_struct_or_union_specifier == NULL)
		return NULL;

	static_set(*p_struct_or_union_specifier, "zero");

	if (ctx->current->type == TK_KEYWORD_STRUCT ||
		ctx->current->type == TK_KEYWORD_UNION)
	{
		p_struct_or_union_specifier->first_token = ctx->current;
		parser_match(ctx);
	}
	else
	{
		assert(false);
	}

	p_struct_or_union_specifier->attribute_specifier_sequence_opt =
		attribute_specifier_sequence_opt(ctx);

	struct struct_or_union_specifier* p_first_tag_in_this_scope = NULL;

	if (ctx->current->type == TK_IDENTIFIER)
	{
		p_struct_or_union_specifier->tagtoken = ctx->current;
		/*
		 Structure, union, and enumeration tags have scope that begins just after the
		 appearance of the tag in a type specifier that declares the tag.
		*/

		snprintf(p_struct_or_union_specifier->tag_name, sizeof p_struct_or_union_specifier->tag_name, "%s", ctx->current->lexeme);

		struct map_entry* p_entry = hashmap_find(&ctx->scopes.tail->tags, ctx->current->lexeme);
		if (p_entry)
		{
			/*this tag already exist in this scope*/
			if (p_entry->type == TAG_TYPE_STRUCT_OR_UNION_SPECIFIER)
			{
				p_first_tag_in_this_scope = p_entry->p;
				p_struct_or_union_specifier->complete_struct_or_union_specifier_indirection = p_first_tag_in_this_scope;
			}
			else
			{
				compiler_set_error_with_token(C_TAG_TYPE_DOES_NOT_MATCH_PREVIOUS_DECLARATION,
					ctx,
					ctx->current,
					"use of '%s' with tag type that does not match previous declaration.",
					ctx->current->lexeme);
			}
		}
		else
		{
			/*tag does not exist in the current scope, let search on upper scopes*/
			struct struct_or_union_specifier* p_first_tag_previous_scopes = find_struct_or_union_specifier(ctx, ctx->current->lexeme);
			if (p_first_tag_previous_scopes == NULL)
			{
				/*tag not found, so it is the first appearence*/
				p_struct_or_union_specifier->scope_level = ctx->scopes.tail->scope_level;
				hashmap_set(&ctx->scopes.tail->tags, ctx->current->lexeme, p_struct_or_union_specifier, TAG_TYPE_STRUCT_OR_UNION_SPECIFIER);

			}
			else
			{
				/*tag already exists in some scope*/
				p_struct_or_union_specifier->complete_struct_or_union_specifier_indirection = p_first_tag_previous_scopes;
			}
		}

		parser_match(ctx);
	}
	else
	{
		/*struct without a tag, in this case we make one*/
		snprintf(p_struct_or_union_specifier->tag_name, sizeof p_struct_or_union_specifier->tag_name, "_anonymous_struct_%d", s_anonymous_struct_count);
		s_anonymous_struct_count++;
		p_struct_or_union_specifier->has_anonymous_tag = true;
		p_struct_or_union_specifier->scope_level = ctx->scopes.tail->scope_level;
		hashmap_set(&ctx->scopes.tail->tags, p_struct_or_union_specifier->tag_name, p_struct_or_union_specifier, TAG_TYPE_STRUCT_OR_UNION_SPECIFIER);
	}



	if (ctx->current->type == '{')
	{
		/*
		this is the complete struct
		*/

		struct struct_or_union_specifier* first = find_struct_or_union_specifier(ctx, p_struct_or_union_specifier->tag_name);

		if (first)
		{
			/*
			   The first tag (will the one at symbol table) will point to the complete struct
			*/
			first->complete_struct_or_union_specifier_indirection = p_struct_or_union_specifier;
		}

		if (p_struct_or_union_specifier->tagtoken)
			naming_convention_struct_tag(ctx, p_struct_or_union_specifier->tagtoken);

		struct token* firsttoken = ctx->current;
		parser_match(ctx);

		p_struct_or_union_specifier->member_declaration_list = member_declaration_list(ctx, p_struct_or_union_specifier);
		p_struct_or_union_specifier->member_declaration_list.first_token = firsttoken;
		p_struct_or_union_specifier->last_token = ctx->current;
		p_struct_or_union_specifier->member_declaration_list.last_token = ctx->current;
		parser_match_tk(ctx, '}');

	}
	else
	{
		p_struct_or_union_specifier->last_token = ctx->current;
	}

	struct struct_or_union_specifier* p_complete =
		get_complete_struct_or_union_specifier(p_struct_or_union_specifier);

	/*check if complete struct is deprecated*/
	if (p_complete)
	{
		if (p_complete->attribute_specifier_sequence_opt &&
			p_complete->attribute_specifier_sequence_opt->attributes_flags & STD_ATTRIBUTE_DEPRECATED)
		{
			if (p_struct_or_union_specifier->tagtoken)
			{
				//TODO add deprecated message
				compiler_set_warning_with_token(W_DEPRECATED, ctx, p_struct_or_union_specifier->first_token, "'%s' is deprecated", p_struct_or_union_specifier->tagtoken->lexeme);
			}
			else
			{
				compiler_set_warning_with_token(W_DEPRECATED, ctx, p_struct_or_union_specifier->first_token, "deprecated");
			}
		}
	}

	return p_struct_or_union_specifier;
}

struct member_declarator* owner member_declarator(
	struct parser_ctx* ctx,
	struct struct_or_union_specifier* p_struct_or_union_specifier,
	const struct specifier_qualifier_list* p_specifier_qualifier_list
)
{
	/*
	member-declarator:
	 declarator
	 declaratoropt : constant-expression
	*/
	struct member_declarator* owner p_member_declarator = calloc(1, sizeof(struct member_declarator));

	struct token* p_token_name = NULL;

	p_member_declarator->declarator = declarator(ctx, p_specifier_qualifier_list, /*declaration_specifiers*/NULL, false, &p_token_name);
	p_member_declarator->declarator->name = p_token_name;
	p_member_declarator->declarator->specifier_qualifier_list = p_specifier_qualifier_list;

	p_member_declarator->declarator->type = make_type_using_declarator(ctx, p_member_declarator->declarator);

	/*extension*/
	if (type_is_owner(&p_member_declarator->declarator->type))
	{
		/*having at least 1 owner member, the struct type is owner by default*/
		p_struct_or_union_specifier->is_owner = true;
	}

	if (p_member_declarator->declarator->name)
		naming_convention_struct_member(ctx, p_member_declarator->declarator->name, &p_member_declarator->declarator->type);

	if (ctx->current->type == ':')
	{
		parser_match(ctx);
		p_member_declarator->constant_expression = constant_expression(ctx, true);
	}
	return p_member_declarator;
}

void member_declarator_delete(struct member_declarator* owner p)
{
	if (p)
	{
		expression_delete(p->constant_expression);
		assert(p->next == NULL);
		declarator_delete(p->declarator);
		free(p);
	}
}

void member_declarator_list_delete(struct member_declarator_list* owner p)
{
	if (p)
	{
		struct member_declarator* owner item = p->head;
		while (item)
		{
			struct member_declarator* owner next = item->next;
			item->next = NULL;
			member_declarator_delete(item);
			item = next;
		}
		free(p);
	}
}
struct member_declarator_list* owner member_declarator_list(
	struct parser_ctx* ctx,
	struct struct_or_union_specifier* p_struct_or_union_specifier,
	const struct specifier_qualifier_list* p_specifier_qualifier_list)
{
	struct member_declarator_list* owner p_member_declarator_list = calloc(1, sizeof(struct member_declarator_list));
	LIST_ADD(p_member_declarator_list, member_declarator(ctx, p_struct_or_union_specifier, p_specifier_qualifier_list));
	while (ctx->current->type == ',')
	{
		parser_match(ctx);
		LIST_ADD(p_member_declarator_list, member_declarator(ctx, p_struct_or_union_specifier, p_specifier_qualifier_list));
	}
	return p_member_declarator_list;
}


void member_declaration_list_destroy(struct member_declaration_list* obj_owner p)
{
	struct member_declaration* owner item = p->head;
	while (item)
	{
		struct member_declaration* owner next = item->next;
		item->next = NULL;
		member_declaration_delete(item);
		item = next;
	}
}

struct member_declaration_list member_declaration_list(struct parser_ctx* ctx, const struct struct_or_union_specifier* p_struct_or_union_specifier)
{
	struct member_declaration_list list = { 0 };
	//member_declaration
	//member_declaration_list member_declaration

	struct member_declaration* owner p_member_declaration = NULL;

	try
	{
		p_member_declaration = member_declaration(ctx, p_struct_or_union_specifier);

		if (p_member_declaration == NULL) throw;
		LIST_ADD(&list, p_member_declaration);
		p_member_declaration = NULL; /*MOVED*/

		while (ctx->current && ctx->current->type != '}')
		{
			p_member_declaration = member_declaration(ctx, p_struct_or_union_specifier);
			if (p_member_declaration == NULL) throw;
			LIST_ADD(&list, p_member_declaration);
			p_member_declaration = NULL; /*MOVED*/
		}
	}
	catch
	{
	}

	return list;
}

void member_declaration_delete(struct member_declaration* owner p)
{
	if (p)
	{
		assert(p->next == NULL);
		specifier_qualifier_list_delete(p->specifier_qualifier_list);
		member_declarator_list_delete(p->member_declarator_list_opt);
		attribute_specifier_sequence_delete(p->p_attribute_specifier_sequence_opt);
		static_assert_declaration_delete(p->static_assert_declaration);
		free(p);
	}
}
struct member_declaration* owner member_declaration(struct parser_ctx* ctx,
	struct struct_or_union_specifier* p_struct_or_union_specifier)
{
	struct member_declaration* owner p_member_declaration = calloc(1, sizeof(struct member_declaration));
	//attribute_specifier_sequence_opt specifier_qualifier_list member_declarator_list_opt ';'
	//static_assert_declaration
	if (ctx->current->type == TK_KEYWORD__STATIC_ASSERT)
	{
		p_member_declaration->static_assert_declaration = static_assert_declaration(ctx);
	}
	else
	{
		p_member_declaration->p_attribute_specifier_sequence_opt = attribute_specifier_sequence_opt(ctx);

		p_member_declaration->specifier_qualifier_list = specifier_qualifier_list(ctx);
		if (ctx->current->type != ';')
		{
			p_member_declaration->member_declarator_list_opt = member_declarator_list(ctx,
				p_struct_or_union_specifier,
				p_member_declaration->specifier_qualifier_list);
		}
		parser_match_tk(ctx, ';');
	}
	return p_member_declaration;
}

struct member_declarator* find_member_declarator(struct member_declaration_list* list, const char* name, int* p_member_index)
{
	int member_index = 0;

	struct member_declaration* p_member_declaration = list->head;
	while (p_member_declaration)
	{
		struct member_declarator* p_member_declarator = NULL;

		if (p_member_declaration->member_declarator_list_opt)
		{
			p_member_declarator = p_member_declaration->member_declarator_list_opt->head;

			while (p_member_declarator)
			{
				if (strcmp(p_member_declarator->declarator->name->lexeme, name) == 0)
				{
					*p_member_index = member_index;
					return p_member_declarator;
				}

				member_index++;
				p_member_declarator = p_member_declarator->next;
			}
		}
		else if (p_member_declaration->specifier_qualifier_list)
		{
			/*
			 struct X {
				union  {
				  unsigned char       Byte[16];
				  unsigned short      Word[8];
				  };
			};

			struct X* a;
			a.Byte[0] & 0xe0;
			*/

			if (p_member_declaration->specifier_qualifier_list->struct_or_union_specifier)
			{
				struct member_declaration_list* p_member_declaration_list =
					&p_member_declaration->specifier_qualifier_list->struct_or_union_specifier->member_declaration_list;
				int inner_member_index = 0;
				struct member_declarator* p = find_member_declarator(p_member_declaration_list, name, &inner_member_index);
				if (p)
				{
					*p_member_index = member_index + inner_member_index;
					return p;
				}
			}
		}
		else
		{
			assert(p_member_declaration->static_assert_declaration != NULL);
		}


		p_member_declaration = p_member_declaration->next;
	}
	return NULL;
}


void print_specifier_qualifier_list(struct osstream* ss, bool* first, struct specifier_qualifier_list* p_specifier_qualifier_list)
{

	print_type_qualifier_flags(ss, first, p_specifier_qualifier_list->type_qualifier_flags);

	if (p_specifier_qualifier_list->enum_specifier)
	{

		//TODO
		assert(false);

	}
	else if (p_specifier_qualifier_list->struct_or_union_specifier)
	{
		ss_fprintf(ss, "struct %s", p_specifier_qualifier_list->struct_or_union_specifier->tag_name);
	}
	else if (p_specifier_qualifier_list->typedef_declarator)
	{
		print_item(ss, first, p_specifier_qualifier_list->typedef_declarator->name->lexeme);
	}
	else
	{
		print_type_specifier_flags(ss, first, p_specifier_qualifier_list->type_specifier_flags);
	}
}


void specifier_qualifier_list_delete(struct specifier_qualifier_list* owner p)
{
	if (p)
	{
		struct type_specifier_qualifier* owner item = p->head;
		while (item)
		{
			struct type_specifier_qualifier* owner next = item->next;
			item->next = NULL;
			type_specifier_qualifier_delete(item);
			item = next;
		}

		attribute_specifier_sequence_delete(p->p_attribute_specifier_sequence);


		free(p);
	}
}

struct specifier_qualifier_list* owner specifier_qualifier_list(struct parser_ctx* ctx)
{
	struct specifier_qualifier_list* owner p_specifier_qualifier_list = calloc(1, sizeof(struct specifier_qualifier_list));
	if (p_specifier_qualifier_list == NULL)
		return NULL;

	static_set(*p_specifier_qualifier_list, "zero");

	/*
	  type_specifier_qualifier attribute_specifier_sequence_opt
	  type_specifier_qualifier specifier_qualifier_list
	*/
	try
	{
		p_specifier_qualifier_list->first_token = ctx->current;

		while (ctx->current != NULL &&
			(first_of_type_specifier(ctx) ||
				first_of_type_qualifier(ctx)))
		{

			if (ctx->current->flags & TK_FLAG_IDENTIFIER_IS_TYPEDEF)
			{
				if (p_specifier_qualifier_list->type_specifier_flags != TYPE_SPECIFIER_NONE)
				{
					//typedef tem que aparecer sozinho
					//exemplo Socket eh nome e nao typdef
					//typedef int Socket;
					//struct X {int Socket;}; 
					break;
				}
			}

			struct type_specifier_qualifier* owner p_type_specifier_qualifier = type_specifier_qualifier(ctx);

			if (p_type_specifier_qualifier->type_specifier)
			{
				if (add_specifier(ctx,
					&p_specifier_qualifier_list->type_specifier_flags,
					p_type_specifier_qualifier->type_specifier->flags) != 0)
				{
					type_specifier_qualifier_delete(p_type_specifier_qualifier);
					throw;
				}

				if (p_type_specifier_qualifier->type_specifier->struct_or_union_specifier)
				{
					p_specifier_qualifier_list->struct_or_union_specifier = p_type_specifier_qualifier->type_specifier->struct_or_union_specifier;
				}
				else if (p_type_specifier_qualifier->type_specifier->enum_specifier)
				{
					p_specifier_qualifier_list->enum_specifier = p_type_specifier_qualifier->type_specifier->enum_specifier;
				}
				else if (p_type_specifier_qualifier->type_specifier->typeof_specifier)
				{
					p_specifier_qualifier_list->typeof_specifier = p_type_specifier_qualifier->type_specifier->typeof_specifier;
				}
				else if (p_type_specifier_qualifier->type_specifier->token->type == TK_IDENTIFIER)
				{
					p_specifier_qualifier_list->typedef_declarator =
						find_declarator(ctx,
							p_type_specifier_qualifier->type_specifier->token->lexeme,
							NULL);
				}

			}
			else if (p_type_specifier_qualifier->type_qualifier)
			{
				p_specifier_qualifier_list->type_qualifier_flags |= p_type_specifier_qualifier->type_qualifier->flags;
			}

			LIST_ADD(p_specifier_qualifier_list, p_type_specifier_qualifier);
			p_specifier_qualifier_list->p_attribute_specifier_sequence = attribute_specifier_sequence_opt(ctx);
		}
	}
	catch
	{
	}

	final_specifier(ctx, &p_specifier_qualifier_list->type_specifier_flags);
	p_specifier_qualifier_list->last_token = previous_parser_token(ctx->current);
	return p_specifier_qualifier_list;
}

void type_specifier_qualifier_delete(struct type_specifier_qualifier* owner p)
{
	if (p)
	{
		assert(p->next == NULL);
		if (p->type_qualifier)
		{
			assert(p->type_qualifier->next == NULL);
			free(p->type_qualifier);
		}
		alignment_specifier_delete(p->alignment_specifier);


		type_specifier_delete(p->type_specifier);
		free(p);
	}
}
struct type_specifier_qualifier* owner type_specifier_qualifier(struct parser_ctx* ctx)
{
	struct type_specifier_qualifier* owner type_specifier_qualifier = calloc(1, sizeof * type_specifier_qualifier);
	//type_specifier
	//type_qualifier
	//alignment_specifier
	if (first_of_type_specifier(ctx))
	{
		type_specifier_qualifier->type_specifier = type_specifier(ctx);
	}
	else if (first_of_type_qualifier(ctx))
	{
		type_specifier_qualifier->type_qualifier = type_qualifier(ctx);
	}
	else if (first_of_alignment_specifier(ctx))
	{
		type_specifier_qualifier->alignment_specifier = alignment_specifier(ctx);
	}
	else
	{
		assert(false);
	}
	return type_specifier_qualifier;
}


void enum_specifier_delete(struct enum_specifier* owner p)
{
	if (p)
	{
		specifier_qualifier_list_delete(p->specifier_qualifier_list);
		attribute_specifier_sequence_delete(p->attribute_specifier_sequence_opt);
		enumerator_list_destroy(&p->enumerator_list);
		free(p);
	}
}

struct enum_specifier* owner enum_specifier(struct parser_ctx* ctx)
{
	/*
	 enum-type-specifier:
	 : specifier-qualifier-list
	*/

	/*
		enum-specifier:

		"enum" attribute-specifier-sequence opt identifier opt enum-type-specifier opt
		{ enumerator-list }

		"enum" attribute-specifier-sequence opt identifier opt enum-type-specifier opt
		{ enumerator-list , }
		enum identifier enum-type-specifier opt
	*/
	struct enum_specifier* owner p_enum_specifier = NULL;
	try
	{
		p_enum_specifier = calloc(1, sizeof * p_enum_specifier);

		p_enum_specifier->first_token = ctx->current;
		parser_match_tk(ctx, TK_KEYWORD_ENUM);

		p_enum_specifier->attribute_specifier_sequence_opt =
			attribute_specifier_sequence_opt(ctx);


		struct enum_specifier* p_previous_tag_in_this_scope = NULL;
		bool has_identifier = false;
		if (ctx->current->type == TK_IDENTIFIER)
		{
			has_identifier = true;
			p_enum_specifier->tag_token = ctx->current;
			parser_match(ctx);
		}

		if (ctx->current->type == ':')
		{
			/*C23*/
			parser_match(ctx);
			p_enum_specifier->specifier_qualifier_list = specifier_qualifier_list(ctx);
		}

		if (ctx->current->type == '{')
		{
			if (p_enum_specifier->tag_token)
				naming_convention_enum_tag(ctx, p_enum_specifier->tag_token);

			/*points to itself*/
			p_enum_specifier->complete_enum_specifier = p_enum_specifier;

			parser_match_tk(ctx, '{');
			p_enum_specifier->enumerator_list = enumerator_list(ctx, p_enum_specifier);
			if (ctx->current->type == ',')
			{
				parser_match(ctx);
			}
			parser_match_tk(ctx, '}');
		}
		else
		{
			if (!has_identifier)
			{
				compiler_set_error_with_token(C_MISSING_ENUM_TAG_NAME, ctx, ctx->current, "missing enum tag name");
				throw;
			}
		}

		/*
		* Let's search for this tag at current scope only
		*/
		struct map_entry* p_entry = NULL;

		if (p_enum_specifier->tag_token &&
			p_enum_specifier->tag_token->lexeme)
		{
			p_entry = hashmap_find(&ctx->scopes.tail->tags, p_enum_specifier->tag_token->lexeme);
		}
		if (p_entry)
		{
			/*
			   ok.. we have this tag at this scope
			*/
			if (p_entry->type == TAG_TYPE_ENUN_SPECIFIER)
			{
				p_previous_tag_in_this_scope = p_entry->p;

				if (p_previous_tag_in_this_scope->enumerator_list.head != NULL &&
					p_enum_specifier->enumerator_list.head != NULL)
				{
					compiler_set_error_with_token(C_MULTIPLE_DEFINITION_ENUM,
						ctx,
						p_enum_specifier->tag_token,
						"multiple definition of 'enum %s'",
						p_enum_specifier->tag_token->lexeme);
				}
				else if (p_previous_tag_in_this_scope->enumerator_list.head != NULL)
				{
					p_enum_specifier->complete_enum_specifier = p_previous_tag_in_this_scope;
				}
				else if (p_enum_specifier->enumerator_list.head != NULL)
				{
					p_previous_tag_in_this_scope->complete_enum_specifier = p_enum_specifier;
				}
			}
			else
			{
				compiler_set_error_with_token(C_TAG_TYPE_DOES_NOT_MATCH_PREVIOUS_DECLARATION,
					ctx,
					ctx->current, "use of '%s' with tag type that does not match previous declaration.",
					ctx->current->lexeme);
				throw;
			}
		}
		else
		{
			/*
			* we didn't find at current scope let's search in previous scopes
			*/
			struct enum_specifier* p_other = NULL;

			if (p_enum_specifier->tag_token)
			{
				p_other = find_enum_specifier(ctx, p_enum_specifier->tag_token->lexeme);
			}

			if (p_other == NULL)
			{
				/*
				 * we didn't find, so this is the first time this tag is used
				*/
				if (p_enum_specifier->tag_token)
				{
					hashmap_set(&ctx->scopes.tail->tags, p_enum_specifier->tag_token->lexeme, p_enum_specifier, TAG_TYPE_ENUN_SPECIFIER);
				}
				else
				{
					//make a name?
				}
			}
			else
			{


				/*
				 * we found this enum tag in previous scopes
				*/

				if (p_enum_specifier->enumerator_list.head != NULL)
				{
					/*it is a new definition - itself*/
					//p_enum_specifier->complete_enum_specifier = p_enum_specifier;
				}
				else if (p_other->enumerator_list.head != NULL)
				{
					/*previous enum is complete*/
					p_enum_specifier->complete_enum_specifier = p_other;
				}
			}
		}

	}
	catch
	{
	}

	return p_enum_specifier;
}

void enumerator_list_destroy(struct enumerator_list* obj_owner p)
{
	struct enumerator* owner item = p->head;
	while (item)
	{
		struct enumerator* owner next = item->next;
		item->next = NULL;
		enumerator_delete(item);
		item = next;
	}
}

struct enumerator_list enumerator_list(struct parser_ctx* ctx, const struct enum_specifier* p_enum_specifier)
{

	/*
	   enumerator
		enumerator_list ',' enumerator
	 */
	long long next_enumerator_value = 0;

	struct enumerator_list enumeratorlist = { 0 };
	struct enumerator* owner p_enumerator = NULL;
	try
	{
		p_enumerator = enumerator(ctx, p_enum_specifier, &next_enumerator_value);
		if (p_enumerator == NULL) throw;

		LIST_ADD(&enumeratorlist, p_enumerator);

		while (ctx->current != NULL && ctx->current->type == ',')
		{
			parser_match(ctx);  /*pode ter uma , vazia no fim*/

			if (ctx->current && ctx->current->type != '}')
			{
				p_enumerator = enumerator(ctx, p_enum_specifier, &next_enumerator_value);
				if (p_enumerator == NULL) throw;
				LIST_ADD(&enumeratorlist, p_enumerator);
			}
		}
	}
	catch
	{
	}

	return enumeratorlist;
}

void enumerator_delete(struct enumerator* owner p)
{
	if (p)
	{
		assert(p->next == NULL);
		attribute_specifier_sequence_delete(p->attribute_specifier_sequence_opt);
		expression_delete(p->constant_expression_opt);

		free(p);
	}
}
struct enumerator* owner enumerator(struct parser_ctx* ctx,
	const struct enum_specifier* p_enum_specifier,
	long long* p_next_enumerator_value)
{
	//TODO VALUE
	struct enumerator* owner p_enumerator = calloc(1, sizeof(struct enumerator));
	p_enumerator->enum_specifier = p_enum_specifier;
	struct token* name = ctx->current;

	naming_convention_enumerator(ctx, name);

	parser_match_tk(ctx, TK_IDENTIFIER);

	p_enumerator->attribute_specifier_sequence_opt = attribute_specifier_sequence_opt(ctx);

	p_enumerator->token = name;
	hashmap_set(&ctx->scopes.tail->variables, p_enumerator->token->lexeme, p_enumerator, TAG_TYPE_ENUMERATOR);

	if (ctx->current->type == '=')
	{
		parser_match(ctx);
		p_enumerator->constant_expression_opt = constant_expression(ctx, true);
		p_enumerator->value = constant_value_to_ll(&p_enumerator->constant_expression_opt->constant_value);
		*p_next_enumerator_value = p_enumerator->value;
		(*p_next_enumerator_value)++; //TODO overflow  and size check
	}
	else
	{
		p_enumerator->value = *p_next_enumerator_value;
		(*p_next_enumerator_value)++; //TODO overflow  and size check
	}

	return p_enumerator;
}


void alignment_specifier_delete(struct alignment_specifier* owner p)
{
	if (p)
	{
		expression_delete(p->constant_expression);
		type_name_delete(p->type_name);
		free(p);
	}
}

struct alignment_specifier* owner alignment_specifier(struct parser_ctx* ctx)
{
	struct alignment_specifier* owner alignment_specifier = calloc(1, sizeof * alignment_specifier);
	alignment_specifier->token = ctx->current;
	parser_match_tk(ctx, TK_KEYWORD__ALIGNAS);
	parser_match_tk(ctx, '(');
	if (first_of_type_name(ctx))
	{
		alignment_specifier->type_name = type_name(ctx);
	}
	else
	{
		alignment_specifier->constant_expression = constant_expression(ctx, true);
	}
	parser_match_tk(ctx, ')');
	return alignment_specifier;
}


void atomic_type_specifier_delete(struct atomic_type_specifier* owner p)
{
	if (p)
	{
		type_name_delete(p->type_name);
		free(p);
	}
}
struct atomic_type_specifier* owner atomic_type_specifier(struct parser_ctx* ctx)
{
	//'_Atomic' '(' type_name ')'
	struct atomic_type_specifier* owner p = calloc(1, sizeof * p);
	p->token = ctx->current;
	parser_match_tk(ctx, TK_KEYWORD__ATOMIC);
	parser_match_tk(ctx, '(');
	p->type_name = type_name(ctx);
	parser_match_tk(ctx, ')');
	return p;
}


struct type_qualifier* owner type_qualifier(struct parser_ctx* ctx)
{
	struct type_qualifier* owner p_type_qualifier = calloc(1, sizeof * p_type_qualifier);

	switch (ctx->current->type)
	{
	case TK_KEYWORD_CONST:
		p_type_qualifier->flags = TYPE_QUALIFIER_CONST;
		break;
	case TK_KEYWORD_RESTRICT:
		p_type_qualifier->flags = TYPE_QUALIFIER_RESTRICT;
		break;
	case TK_KEYWORD_VOLATILE:
		p_type_qualifier->flags = TYPE_QUALIFIER_VOLATILE;
		break;
	case TK_KEYWORD__ATOMIC:
		p_type_qualifier->flags = TYPE_QUALIFIER__ATOMIC;
		break;

		/*
		  ownership extensions
		*/

	case TK_KEYWORD__OUT:
		p_type_qualifier->flags = TYPE_QUALIFIER_OUT;
		break;

	case TK_KEYWORD__OWNER:
		p_type_qualifier->flags = TYPE_QUALIFIER_OWNER;
		break;

	case TK_KEYWORD__OPT:
		p_type_qualifier->flags = TYPE_QUALIFIER_OPT;
		break;

	case TK_KEYWORD__OBJ_OWNER:
		p_type_qualifier->flags = TYPE_QUALIFIER_OBJ_OWNER;
		break;
	case TK_KEYWORD__VIEW:
		p_type_qualifier->flags = TYPE_QUALIFIER_VIEW;
		break;

	}

	p_type_qualifier->token = ctx->current;

	//'const'
	//'restrict'
	//'volatile'
	//'_Atomic'
	parser_match(ctx);
	return p_type_qualifier;
}
//

struct type_qualifier* owner type_qualifier_opt(struct parser_ctx* ctx)
{
	if (first_of_type_qualifier(ctx))
	{
		return type_qualifier(ctx);
	}
	return NULL;
}


void function_specifier_delete(struct function_specifier* owner p)
{
	if (p)
	{
		free(p);
	}
}

struct function_specifier* owner function_specifier(struct parser_ctx* ctx)
{
	if (ctx->current->type == TK_KEYWORD__NORETURN)
	{
		compiler_set_info_with_token(W_STYLE, ctx, ctx->current, "_Noreturn is deprecated use attributes");
	}

	struct function_specifier* owner p_function_specifier = NULL;
	try
	{
		p_function_specifier = calloc(1, sizeof * p_function_specifier);
		if (p_function_specifier == NULL) throw;

		p_function_specifier->token = ctx->current;
		parser_match(ctx);

	}
	catch
	{
	}

	return p_function_specifier;
}

void declarator_delete(struct declarator* owner p)
{
	if (p)
	{
		type_destroy(&p->type);
		direct_declarator_delete(p->direct_declarator);
		pointer_delete(p->pointer);
		object_destroy(&p->object);
		free(p);
	}
}
struct declarator* owner declarator(struct parser_ctx* ctx,
	const struct specifier_qualifier_list* p_specifier_qualifier_list,
	struct declaration_specifiers* p_declaration_specifiers,
	bool abstract_acceptable,
	struct token** pp_token_name)
{
	/*
	  declarator:
	  pointer_opt direct-declarator
	*/
	struct declarator* owner p_declarator = calloc(1, sizeof(struct declarator));
	p_declarator->first_token = ctx->current;
	p_declarator->pointer = pointer_opt(ctx);
	p_declarator->direct_declarator = direct_declarator(ctx, p_specifier_qualifier_list, p_declaration_specifiers, abstract_acceptable, pp_token_name);

	if (ctx->current != p_declarator->first_token)
	{
		p_declarator->last_token = previous_parser_token(ctx->current);
	}
	else
	{
		/*empty declarator*/

		p_declarator->last_token = p_declarator->first_token;
		p_declarator->first_token = NULL; /*this is the way we can know...first is null*/
	}


	return p_declarator;
}

const char* declarator_get_name(struct declarator* p_declarator)
{
	if (p_declarator->direct_declarator)
	{
		if (p_declarator->direct_declarator->name_opt)
			return p_declarator->direct_declarator->name_opt->lexeme;
	}


	return NULL;
}

bool declarator_is_function(struct declarator* p_declarator)
{
	return (p_declarator->direct_declarator &&
		p_declarator->direct_declarator->function_declarator != NULL);

}

struct array_declarator* owner array_declarator(struct direct_declarator* owner p_direct_declarator, struct parser_ctx* ctx);
struct function_declarator* owner function_declarator(struct direct_declarator* owner p_direct_declarator, struct parser_ctx* ctx);

void function_declarator_delete(struct function_declarator* owner p)
{
	if (p)
	{
		direct_declarator_delete(p->direct_declarator);
		scope_destroy(&p->parameters_scope);
		parameter_type_list_delete(p->parameter_type_list_opt);
		free(p);
	}
}
void direct_declarator_delete(struct direct_declarator* owner p)
{
	if (p)
	{
		declarator_delete(p->declarator);
		attribute_specifier_sequence_delete(p->p_attribute_specifier_sequence_opt);
		array_declarator_delete(p->array_declarator);
		function_declarator_delete(p->function_declarator);

		free(p);
	}
}
struct direct_declarator* owner direct_declarator(struct parser_ctx* ctx,
	const struct specifier_qualifier_list* p_specifier_qualifier_list,
	struct declaration_specifiers* p_declaration_specifiers,
	bool abstract_acceptable,
	struct token** pptoken_name)
{
	/*
	direct-declarator:
	 identifier attribute-specifier-sequenceopt
	 ( declarator )

	 array-declarator attribute-specifier-sequenceopt
	 function-declarator attribute-specifier-sequenceopt
	*/
	struct direct_declarator* owner p_direct_declarator = calloc(1, sizeof(struct direct_declarator));
	try
	{
		if (ctx->current == NULL) throw;

		struct token* p_token_ahead = parser_look_ahead(ctx);
		if (ctx->current->type == TK_IDENTIFIER)
		{
			p_direct_declarator->name_opt = ctx->current;
			if (pptoken_name != NULL)
			{
				*pptoken_name = ctx->current;
			}


			parser_match(ctx);
			p_direct_declarator->p_attribute_specifier_sequence_opt = attribute_specifier_sequence_opt(ctx);
		}
		else if (ctx->current->type == '(')
		{
			struct token* ahead = parser_look_ahead(ctx);

			if (!first_of_type_specifier_token(ctx, p_token_ahead) &&
				!first_of_type_qualifier_token(p_token_ahead) &&
				ahead->type != ')' &&
				ahead->type != '...')
			{
				//look ahead para nao confundir (declarator) com parametros funcao ex void (int)
				//or function int ()

				parser_match(ctx);

				p_direct_declarator->declarator = declarator(ctx,
					p_specifier_qualifier_list,
					p_declaration_specifiers,
					abstract_acceptable,
					pptoken_name);


				parser_match(ctx); //)
			}
		}


		while (ctx->current != NULL &&
			(ctx->current->type == '[' || ctx->current->type == '('))
		{
			struct direct_declarator* owner p_direct_declarator2 = calloc(1, sizeof(struct direct_declarator));
			static_set(*p_direct_declarator2, "zero");
			if (ctx->current->type == '[')
			{
				p_direct_declarator2->array_declarator = array_declarator(p_direct_declarator, ctx);
			}
			else
			{
				p_direct_declarator2->function_declarator = function_declarator(p_direct_declarator, ctx);
			}
			p_direct_declarator = p_direct_declarator2;
		}
	}
	catch
	{
	}

	return p_direct_declarator;
}

void array_declarator_delete(struct array_declarator* owner p)
{
	if (p)
	{
		expression_delete(p->assignment_expression);
		direct_declarator_delete(p->direct_declarator);
		expression_delete(p->expression);
		type_qualifier_list_delete(p->type_qualifier_list_opt);

		free(p);
	}
}
unsigned long long array_declarator_get_size(struct array_declarator* p_array_declarator)
{
	if (p_array_declarator->assignment_expression)
	{
		if (constant_value_is_valid(&p_array_declarator->assignment_expression->constant_value))
		{
			return
				constant_value_to_ull(&p_array_declarator->assignment_expression->constant_value);
		}
	}
	return 0;
}

struct array_declarator* owner array_declarator(struct direct_declarator* owner p_direct_declarator, struct parser_ctx* ctx)
{
	//direct_declarator '['          type_qualifier_list_opt           assignment_expression_opt ']'
	//direct_declarator '[' 'static' type_qualifier_list_opt           assignment_expression     ']'
	//direct_declarator '['          type_qualifier_list      'static' assignment_expression     ']'
	//direct_declarator '['          type_qualifier_list_opt  '*'           ']'

	struct array_declarator* owner p_array_declarator = NULL;
	try
	{
		p_array_declarator = calloc(1, sizeof * p_array_declarator);
		if (p_array_declarator == NULL) throw;

		p_array_declarator->direct_declarator = p_direct_declarator;
		parser_match_tk(ctx, '[');

		bool has_static = false;
		if (ctx->current->type == TK_KEYWORD_STATIC)
		{
			p_array_declarator->static_token_opt = ctx->current;
			parser_match(ctx);
			has_static = true;
		}

		if (first_of_type_qualifier(ctx))
		{
			p_array_declarator->type_qualifier_list_opt = type_qualifier_list(ctx);
		}

		if (!has_static)
		{
			if (ctx->current->type == TK_KEYWORD_STATIC)
			{
				parser_match(ctx);
				has_static = true;
			}
		}

		if (has_static)
		{
			//tem que ter..

			const bool evaluation_is_disabled = ctx->evaluation_is_disabled;
			ctx->evaluation_is_disabled = false;
			p_array_declarator->assignment_expression = assignment_expression(ctx);
			/*restore*/
			ctx->evaluation_is_disabled = evaluation_is_disabled;

			if (p_array_declarator->assignment_expression == NULL) throw;
		}
		else
		{
			//opcional
			if (ctx->current->type == '*')
			{
				parser_match(ctx);
			}
			else if (ctx->current->type != ']')
			{
				const bool evaluation_is_disabled = ctx->evaluation_is_disabled;
				ctx->evaluation_is_disabled = false;
				p_array_declarator->assignment_expression = assignment_expression(ctx);
				/*restore*/
				ctx->evaluation_is_disabled = evaluation_is_disabled;
				if (p_array_declarator->assignment_expression == NULL) throw;
			}
			else
			{
			}
		}

		parser_match_tk(ctx, ']');
	}
	catch
	{
		if (p_array_declarator)
		{
		}
	}



	return p_array_declarator;
}


struct function_declarator* owner function_declarator(struct direct_declarator* owner p_direct_declarator, struct parser_ctx* ctx)
{
	struct function_declarator* owner p_function_declarator = calloc(1, sizeof(struct function_declarator));
	//faz um push da funcion_scope_declarator_list que esta vivendo mais em cima
	//eh feito o pop mais em cima tb.. aqui dentro do decide usar.
	//ctx->funcion_scope_declarator_list->outer_scope = ctx->current_scope;
	//ctx->current_scope = ctx->funcion_scope_declarator_list;
	//direct_declarator '(' parameter_type_list_opt ')'


	p_function_declarator->direct_declarator = p_direct_declarator;
	p_function_declarator->parameters_scope.scope_level = ctx->scopes.tail->scope_level + 1;
	p_function_declarator->parameters_scope.variables.capacity = 5;
	p_function_declarator->parameters_scope.tags.capacity = 1;


	scope_list_push(&ctx->scopes, &p_function_declarator->parameters_scope);

	//print_scope(&ctx->scopes);

	parser_match_tk(ctx, '(');
	if (ctx->current->type != ')')
	{
		p_function_declarator->parameter_type_list_opt = parameter_type_list(ctx);
	}
	parser_match_tk(ctx, ')');

	//print_scope(&ctx->scopes);

	scope_list_pop(&ctx->scopes);

	//print_scope(&ctx->scopes);


	return p_function_declarator;
}

void pointer_delete(struct pointer* owner p)
{
	if (p)
	{
		attribute_specifier_sequence_delete(p->attribute_specifier_sequence_opt);
		type_qualifier_list_delete(p->type_qualifier_list_opt);

		struct pointer* owner item = p->pointer;
		while (item)
		{
			struct pointer* owner next = item->pointer;
			attribute_specifier_sequence_delete(item->attribute_specifier_sequence_opt);
			type_qualifier_list_delete(item->type_qualifier_list_opt);
			free(item);
			item = next;
		}

		free(p);
	}
}
struct pointer* owner pointer_opt(struct parser_ctx* ctx)
{
	struct pointer* owner p = NULL;
	struct pointer* owner p_pointer = NULL;
	try
	{
		while (ctx->current != NULL && ctx->current->type == '*')
		{
			p_pointer = calloc(1, sizeof(struct pointer));
			if (p_pointer == NULL) throw;

			static_set(*p_pointer, "zero");

			p = p_pointer;
			parser_match(ctx);

			p_pointer->attribute_specifier_sequence_opt =
				attribute_specifier_sequence_opt(ctx);

			if (first_of_type_qualifier(ctx))
			{
				p_pointer->type_qualifier_list_opt = type_qualifier_list(ctx);
			}


			while (ctx->current != NULL && ctx->current->type == '*')
			{
				p_pointer->pointer = pointer_opt(ctx);
				if (p_pointer->pointer == NULL)
					throw;
			}
		}
	}
	catch
	{
	}

	//'*' attribute_specifier_sequence_opt type_qualifier_list_opt
	//'*' attribute_specifier_sequence_opt type_qualifier_list_opt pointer
	return p;
}


void type_qualifier_list_delete(struct type_qualifier_list* owner p)
{
	if (p)
	{
		struct type_qualifier* owner item = p->head;
		while (item)
		{
			struct type_qualifier* owner next = item->next;
			item->next = NULL;
			free(item);
			item = next;
		}
		free(p);
	}
}

struct type_qualifier_list* owner type_qualifier_list(struct parser_ctx* ctx)
{
	//type_qualifier
	//type_qualifier_list type_qualifier

	struct type_qualifier_list* owner p_type_qualifier_list = NULL;
	struct type_qualifier* owner p_type_qualifier = NULL;

	try
	{
		p_type_qualifier_list = calloc(1, sizeof(struct type_qualifier_list));
		if (p_type_qualifier_list == NULL) throw;


		p_type_qualifier = type_qualifier(ctx);
		if (p_type_qualifier == NULL) throw;

		p_type_qualifier_list->flags |= p_type_qualifier->flags;
		LIST_ADD(p_type_qualifier_list, p_type_qualifier);
		p_type_qualifier = NULL; /*MOVED*/

		while (ctx->current != NULL && first_of_type_qualifier(ctx))
		{
			p_type_qualifier = type_qualifier(ctx);
			if (p_type_qualifier == NULL) throw;

			p_type_qualifier_list->flags |= p_type_qualifier->flags;
			LIST_ADD(p_type_qualifier_list, p_type_qualifier);
			p_type_qualifier = NULL; /*MOVED*/
		}
	}
	catch
	{
	}

	return p_type_qualifier_list;
}

void parameter_type_list_delete(struct parameter_type_list* owner p)
{
	if (p)
	{
		parameter_list_delete(p->parameter_list);
		free(p);
	}
}

struct parameter_type_list* owner parameter_type_list(struct parser_ctx* ctx)
{
	struct parameter_type_list* owner p_parameter_type_list = calloc(1, sizeof(struct parameter_type_list));
	//parameter_list
	//parameter_list ',' '...'
	p_parameter_type_list->parameter_list = parameter_list(ctx);

	if (p_parameter_type_list->parameter_list->head ==
		p_parameter_type_list->parameter_list->tail)
	{
		if (type_is_void(&p_parameter_type_list->parameter_list->head->declarator->type))
		{
			p_parameter_type_list->is_void = true;
		}
	}

	/*ja esta saindo com a virgula consumida do parameter_list para evitar ahead*/
	if (ctx->current->type == '...')
	{
		parser_match(ctx);
		//parser_match_tk(ctx, '...');
		p_parameter_type_list->is_var_args = true;
	}
	return p_parameter_type_list;
}


void parameter_list_delete(struct parameter_list* owner  p)
{
	if (p)
	{
		struct parameter_declaration* owner item = p->head;
		while (item)
		{
			struct parameter_declaration* owner next = item->next;
			item->next = NULL;
			parameter_declaration_delete(item);
			item = next;
		}
		free(p);
	}
}
struct parameter_list* owner parameter_list(struct parser_ctx* ctx)
{
	/*
	  parameter_list
	  parameter_declaration
	  parameter_list ',' parameter_declaration
	*/
	struct parameter_list* owner p_parameter_list = NULL;
	struct parameter_declaration* owner p_parameter_declaration = NULL;
	try
	{
		p_parameter_list = calloc(1, sizeof(struct parameter_list));
		if (p_parameter_list == NULL) throw;

		p_parameter_declaration = parameter_declaration(ctx);
		if (p_parameter_declaration == NULL) throw;

		LIST_ADD(p_parameter_list, p_parameter_declaration);
		p_parameter_declaration = NULL; /*MOVED*/

		while (ctx->current != NULL && ctx->current->type == ',')
		{
			parser_match(ctx);
			if (ctx->current->type == '...')
			{
				//follow
				break;
			}

			p_parameter_declaration = parameter_declaration(ctx);
			if (p_parameter_declaration == NULL) throw;

			LIST_ADD(p_parameter_list, p_parameter_declaration);
			p_parameter_declaration = NULL; /*MOVED*/
		}
	}
	catch
	{
	}
	return p_parameter_list;
}


void parameter_declaration_delete(struct parameter_declaration* owner p)
{
	if (p)
	{
		attribute_specifier_sequence_delete(p->attribute_specifier_sequence_opt);
		declaration_specifiers_delete(p->declaration_specifiers);
		declarator_delete(p->declarator);

		assert(p->next == NULL);
		free(p);
	}
}
struct parameter_declaration* owner parameter_declaration(struct parser_ctx* ctx)
{
	struct parameter_declaration* owner p_parameter_declaration = calloc(1, sizeof(struct parameter_declaration));


	p_parameter_declaration->attribute_specifier_sequence_opt =
		attribute_specifier_sequence_opt(ctx);

	p_parameter_declaration->declaration_specifiers = declaration_specifiers(ctx, STORAGE_SPECIFIER_PARAMETER);


	//talvez no ctx colocar um flag que esta em argumentos
	//TODO se tiver uma struct tag novo...
	//warning: declaration of 'struct X' will not be visible outside of this function [-Wvisibility]
	struct token* p_token_name = 0;
	p_parameter_declaration->declarator = declarator(ctx,
		/*specifier_qualifier_list*/NULL,
		p_parameter_declaration->declaration_specifiers,
		true/*can be abstract*/,
		&p_token_name);
	p_parameter_declaration->declarator->name = p_token_name;



	p_parameter_declaration->declarator->declaration_specifiers = p_parameter_declaration->declaration_specifiers;

	p_parameter_declaration->declarator->type = make_type_using_declarator(ctx, p_parameter_declaration->declarator);

	if (p_parameter_declaration->attribute_specifier_sequence_opt)
	{
		p_parameter_declaration->declarator->type.attributes_flags |=
			p_parameter_declaration->attribute_specifier_sequence_opt->attributes_flags;
	}

	p_parameter_declaration->declarator->type.storage_class_specifier_flags |= STORAGE_SPECIFIER_PARAMETER;

	if (p_parameter_declaration->implicit_token)
	{
		p_parameter_declaration->declarator->type.attributes_flags |= CAKE_ATTRIBUTE_IMPLICT;
	}

	if (p_parameter_declaration->declarator->name)
		naming_convention_parameter(ctx, p_parameter_declaration->declarator->name, &p_parameter_declaration->declarator->type);

	//coloca o pametro no escpo atual que deve apontar para escopo paramtros
	// da funcao .
	// 
	//assert ctx->current_scope->variables parametrosd
	if (p_parameter_declaration->declarator->name)
	{
		//parametro void nao te name 
		hashmap_set(&ctx->scopes.tail->variables,
			p_parameter_declaration->declarator->name->lexeme,
			p_parameter_declaration->declarator,
			TAG_TYPE_ONLY_DECLARATOR);
		//print_scope(ctx->current_scope);
	}
	return p_parameter_declaration;
}


struct specifier_qualifier_list* owner copy(struct declaration_specifiers* p_declaration_specifiers)
{
	struct specifier_qualifier_list* owner p_specifier_qualifier_list = calloc(1, sizeof(struct specifier_qualifier_list));

	p_specifier_qualifier_list->type_qualifier_flags = p_declaration_specifiers->type_qualifier_flags;
	p_specifier_qualifier_list->type_specifier_flags = p_declaration_specifiers->type_specifier_flags;

	struct declaration_specifier* p_declaration_specifier =
		p_declaration_specifiers->head;

	while (p_declaration_specifier)
	{
		if (p_declaration_specifier->type_specifier_qualifier)
		{
			struct type_specifier_qualifier* owner p_specifier_qualifier = calloc(1, sizeof(struct type_specifier_qualifier));

			if (p_declaration_specifier->type_specifier_qualifier->type_qualifier)
			{
				struct type_qualifier* owner p_type_qualifier = calloc(1, sizeof(struct type_qualifier));

				p_type_qualifier->flags = p_declaration_specifier->type_specifier_qualifier->type_qualifier->flags;


				p_type_qualifier->token = p_declaration_specifier->type_specifier_qualifier->type_qualifier->token;
				p_specifier_qualifier->type_qualifier = p_type_qualifier;
			}
			else if (p_declaration_specifier->type_specifier_qualifier->type_specifier)
			{
				struct type_specifier* owner p_type_specifier = calloc(1, sizeof(struct type_specifier));

				p_type_specifier->flags = p_declaration_specifier->type_specifier_qualifier->type_specifier->flags;

				//todo
				assert(p_declaration_specifier->type_specifier_qualifier->type_specifier->struct_or_union_specifier == NULL);

				p_type_specifier->token = p_declaration_specifier->type_specifier_qualifier->type_specifier->token;
				p_specifier_qualifier->type_specifier = p_type_specifier;
			}

			LIST_ADD(p_specifier_qualifier_list, p_specifier_qualifier);
		}
		p_declaration_specifier = p_declaration_specifier->next;
	}
	return p_specifier_qualifier_list;

}


void print_declarator(struct osstream* ss, struct declarator* p_declarator, bool is_abstract);

void print_direct_declarator(struct osstream* ss, struct direct_declarator* p_direct_declarator, bool is_abstract)
{
	if (p_direct_declarator->declarator)
	{
		ss_fprintf(ss, "(");
		print_declarator(ss, p_direct_declarator->declarator, is_abstract);
		ss_fprintf(ss, ")");
	}

	if (p_direct_declarator->name_opt && !is_abstract)
	{
		//Se is_abstract for true é pedido para nao imprimir o nome do indentificador
		ss_fprintf(ss, "%s", p_direct_declarator->name_opt->lexeme);
	}

	if (p_direct_declarator->function_declarator)
	{
		print_direct_declarator(ss, p_direct_declarator->function_declarator->direct_declarator, is_abstract);

		ss_fprintf(ss, "(");
		struct parameter_declaration* p_parameter_declaration =
			p_direct_declarator->function_declarator->parameter_type_list_opt ?
			p_direct_declarator->function_declarator->parameter_type_list_opt->parameter_list->head : NULL;

		while (p_parameter_declaration)
		{
			if (p_parameter_declaration != p_direct_declarator->function_declarator->parameter_type_list_opt->parameter_list->head)
				ss_fprintf(ss, ",");

			print_declaration_specifiers(ss, p_parameter_declaration->declaration_specifiers);
			ss_fprintf(ss, " ");
			print_declarator(ss, p_parameter_declaration->declarator, is_abstract);

			p_parameter_declaration = p_parameter_declaration->next;
		}
		//... TODO
		ss_fprintf(ss, ")");
	}
	if (p_direct_declarator->array_declarator)
	{
		//TODO
		ss_fprintf(ss, "[]");
	}

}


enum type_specifier_flags declarator_get_type_specifier_flags(const struct declarator* p)
{
	if (p->declaration_specifiers)
		return p->declaration_specifiers->type_specifier_flags;
	if (p->specifier_qualifier_list)
		return p->specifier_qualifier_list->type_specifier_flags;
	return 0;
}
void print_declarator(struct osstream* ss, struct declarator* p_declarator, bool is_abstract)
{
	bool first = true;
	if (p_declarator->pointer)
	{
		struct pointer* p = p_declarator->pointer;
		while (p)
		{
			if (p->type_qualifier_list_opt)
			{
				print_type_qualifier_flags(ss, &first, p->type_qualifier_list_opt->flags);
			}
			ss_fprintf(ss, "*");
			p = p->pointer;
		}
	}
	print_direct_declarator(ss, p_declarator->direct_declarator, is_abstract);

}

void print_type_name(struct osstream* ss, struct type_name* p)
{
	bool first = true;
	print_specifier_qualifier_list(ss, &first, p->specifier_qualifier_list);
	print_declarator(ss, p->declarator, true);
}

void type_name_delete(struct type_name* owner p)
{
	if (p)
	{
		specifier_qualifier_list_delete(p->specifier_qualifier_list);
		type_destroy(&p->type);
		declarator_delete(p->declarator);
		free(p);
	}
}
struct type_name* owner type_name(struct parser_ctx* ctx)
{
	struct type_name* owner p_type_name = calloc(1, sizeof(struct type_name));

	p_type_name->first_token = ctx->current;


	p_type_name->specifier_qualifier_list = specifier_qualifier_list(ctx);


	p_type_name->declarator = declarator(ctx,
		p_type_name->specifier_qualifier_list,//??
		/*declaration_specifiers*/ NULL,
		true /*DEVE SER TODO*/,
		NULL);
	p_type_name->declarator->specifier_qualifier_list = p_type_name->specifier_qualifier_list;
	p_type_name->declarator->type = make_type_using_declarator(ctx, p_type_name->declarator);


	p_type_name->last_token = ctx->current->prev;
	p_type_name->type = type_dup(&p_type_name->declarator->type);


	return p_type_name;
}

void braced_initializer_delete(struct braced_initializer* owner p)
{
	if (p)
	{
		initializer_list_delete(p->initializer_list);
		free(p);
	}
}
struct braced_initializer* owner braced_initializer(struct parser_ctx* ctx)
{
	/*
	 { }
	 { initializer-list }
	 { initializer-list , }
	*/

	struct braced_initializer* owner p_bracket_initializer_list = calloc(1, sizeof(struct braced_initializer));
	p_bracket_initializer_list->first_token = ctx->current;
	parser_match_tk(ctx, '{');
	if (ctx->current->type != '}')
	{
		p_bracket_initializer_list->initializer_list = initializer_list(ctx);
	}
	parser_match_tk(ctx, '}');
	return p_bracket_initializer_list;
}


void initializer_delete(struct initializer* owner p)
{
	if (p)
	{
		assert(p->next == NULL);
		expression_delete(p->assignment_expression);
		braced_initializer_delete(p->braced_initializer);
		designation_delete(p->designation);
		attribute_specifier_sequence_delete(p->p_attribute_specifier_sequence_opt);
		free(p);
	}
}

struct initializer* owner initializer(struct parser_ctx* ctx)
{
	/*
	initializer:
	  assignment-expression
	  braced-initializer
	*/

	struct initializer* owner p_initializer = calloc(1, sizeof(struct initializer));

	p_initializer->first_token = ctx->current;

	if (ctx->current->type == '{')
	{
		p_initializer->braced_initializer = braced_initializer(ctx);
	}
	else
	{
		p_initializer->p_attribute_specifier_sequence_opt =
			attribute_specifier_sequence_opt(ctx);

		p_initializer->assignment_expression = assignment_expression(ctx);
	}
	return p_initializer;
}


void initializer_list_delete(struct initializer_list* owner p)
{
	if (p)
	{
		struct initializer* owner item = p->head;
		while (item)
		{
			struct initializer* owner next = item->next;
			item->next = NULL;
			initializer_delete(item);
			item = next;
		}
		free(p);
	}
}
struct initializer_list* owner initializer_list(struct parser_ctx* ctx)
{
	/*
	initializer-list:
	   designation opt initializer
	   initializer-list , designation opt initializer
	*/


	struct initializer_list* owner p_initializer_list = calloc(1, sizeof(struct initializer_list));

	p_initializer_list->first_token = ctx->current;

	struct designation* owner p_designation = NULL;
	if (first_of_designator(ctx))
	{
		p_designation = designation(ctx);
	}
	struct initializer* owner p_initializer = initializer(ctx);

	assert(p_initializer->designation == NULL);
	p_initializer->designation = p_designation;

	LIST_ADD(p_initializer_list, p_initializer);
	p_initializer_list->size++;

	while (ctx->current != NULL && ctx->current->type == ',')
	{
		parser_match(ctx);
		if (ctx->current->type == '}')
			break; //follow

		struct designation* owner p_designation2 = NULL;
		if (first_of_designator(ctx))
		{
			p_designation2 = designation(ctx);
		}
		struct initializer* owner p_initializer2 = initializer(ctx);

		assert(p_initializer2->designation == NULL);
		p_initializer2->designation = p_designation2;

		LIST_ADD(p_initializer_list, p_initializer2);
		p_initializer_list->size++;
	}

	return p_initializer_list;
}


void designation_delete(struct designation* owner p)
{
	if (p)
	{
		designator_list_delete(p->designator_list);
		free(p);
	}
}
struct designation* owner designation(struct parser_ctx* ctx)
{
	//designator_list '='
	struct designation* owner p_designation = calloc(1, sizeof(struct designation));
	p_designation->designator_list = designator_list(ctx);
	parser_match_tk(ctx, '=');
	return p_designation;
}

void designator_list_delete(struct designator_list* owner p)
{
	if (p)
	{
		struct designator* owner item = p->head;
		while (item)
		{
			struct designator* owner next = item->next;
			item->next = NULL;
			designator_delete(item);
			item = next;
		}
		free(p);
	}
}
struct designator_list* owner designator_list(struct parser_ctx* ctx)
{
	//designator
	//designator_list designator
	struct designator_list* owner p_designator_list = NULL;
	struct designator* owner p_designator = NULL;
	try
	{
		p_designator_list = calloc(1, sizeof(struct designator_list));
		if (p_designator_list == NULL) throw;

		p_designator = designator(ctx);
		if (p_designator == NULL) throw;
		LIST_ADD(p_designator_list, p_designator);
		p_designator = NULL; /*MOVED*/

		while (ctx->current != NULL && first_of_designator(ctx))
		{
			p_designator = designator(ctx);
			if (p_designator == NULL) throw;
			LIST_ADD(p_designator_list, p_designator);
			p_designator = NULL; /*MOVED*/
		}
	}
	catch
	{
	}

	return p_designator_list;
}


void designator_delete(struct designator* owner p)
{
	if (p)
	{
		assert(p->next == NULL);
		expression_delete(p->constant_expression_opt);
		free(p);
	}

}
struct designator* owner designator(struct parser_ctx* ctx)
{
	//'[' constant_expression ']'
	//'.' identifier
	struct designator* owner p_designator = calloc(1, sizeof(struct designator));
	if (ctx->current->type == '[')
	{
		parser_match_tk(ctx, '[');
		p_designator->constant_expression_opt = constant_expression(ctx, true);
		parser_match_tk(ctx, ']');
	}
	else if (ctx->current->type == '.')
	{
		parser_match(ctx);
		parser_match_tk(ctx, TK_IDENTIFIER);
	}
	return p_designator;
}


void static_assert_declaration_delete(struct static_assert_declaration* owner p)
{
	if (p)
	{
		expression_delete(p->constant_expression);
		free(p);
	}
}

struct static_assert_declaration* owner static_assert_declaration(struct parser_ctx* ctx)
{

	/*
	 static_assert-declaration:
	  "static_assert" ( constant-expression , string-literal ) ;
	  "static_assert" ( constant-expression ) ;
	*/

	struct static_assert_declaration* owner p_static_assert_declaration = NULL;
	try
	{
		p_static_assert_declaration = calloc(1, sizeof(struct static_assert_declaration));
		if (p_static_assert_declaration == NULL) throw;

		p_static_assert_declaration->first_token = ctx->current;
		struct token* position = ctx->current;

		parser_match(ctx);

		parser_match_tk(ctx, '(');

		/*
		 When flow analysis is enabled static assert is evaluated there
		*/
		bool show_error_if_not_constant = false;
		if (p_static_assert_declaration->first_token->type == TK_KEYWORD__STATIC_ASSERT)
		{
			show_error_if_not_constant = true;
		}

		p_static_assert_declaration->constant_expression = constant_expression(ctx, show_error_if_not_constant);
		if (p_static_assert_declaration->constant_expression == NULL) throw;

		if (ctx->current->type == ',')
		{
			parser_match(ctx);
			p_static_assert_declaration->string_literal_opt = ctx->current;
			parser_match_tk(ctx, TK_STRING_LITERAL);
		}

		parser_match_tk(ctx, ')');
		p_static_assert_declaration->last_token = ctx->current;
		parser_match_tk(ctx, ';');

		if (position->type == TK_KEYWORD__STATIC_ASSERT)
		{
			if (!constant_value_to_bool(&p_static_assert_declaration->constant_expression->constant_value))
			{
				if (p_static_assert_declaration->string_literal_opt)
				{
					compiler_set_error_with_token(C_STATIC_ASSERT_FAILED, ctx, position, "_Static_assert failed %s\n",
						p_static_assert_declaration->string_literal_opt->lexeme);
				}
				else
				{
					compiler_set_error_with_token(C_STATIC_ASSERT_FAILED, ctx, position, "_Static_assert failed");
				}
			}
		}

	}
	catch
	{
	}

	return p_static_assert_declaration;
}

void attribute_specifier_sequence_delete(struct attribute_specifier_sequence* owner p)
{
	if (p)
	{
		struct attribute_specifier* owner item = p->head;
		while (item)
		{
			struct attribute_specifier* owner next = item->next;
			item->next = NULL;
			attribute_specifier_delete(item);
			item = next;
		}
		free(p);
	}
}

struct attribute_specifier_sequence* owner attribute_specifier_sequence_opt(struct parser_ctx* ctx)
{
	struct attribute_specifier_sequence* owner p_attribute_specifier_sequence = NULL;

	if (first_of_attribute_specifier(ctx))
	{
		p_attribute_specifier_sequence = calloc(1, sizeof(struct attribute_specifier_sequence));

		p_attribute_specifier_sequence->first_token = ctx->current;

		while (ctx->current != NULL &&
			first_of_attribute_specifier(ctx))
		{
			struct attribute_specifier* owner p_attribute_specifier = attribute_specifier(ctx);

			p_attribute_specifier_sequence->attributes_flags |=
				p_attribute_specifier->attribute_list->attributes_flags;

			LIST_ADD(p_attribute_specifier_sequence, p_attribute_specifier);
		}
		p_attribute_specifier_sequence->last_token = ctx->previous;
	}



	return p_attribute_specifier_sequence;
}

struct attribute_specifier_sequence* owner attribute_specifier_sequence(struct parser_ctx* ctx)
{
	//attribute_specifier_sequence_opt attribute_specifier
	struct attribute_specifier_sequence* owner p_attribute_specifier_sequence = calloc(1, sizeof(struct attribute_specifier_sequence));
	while (ctx->current != NULL && first_of_attribute_specifier(ctx))
	{
		LIST_ADD(p_attribute_specifier_sequence, attribute_specifier(ctx));
	}
	return p_attribute_specifier_sequence;
}


void attribute_specifier_delete(struct attribute_specifier* owner p)
{
	if (p)
	{
		attribute_list_destroy(p->attribute_list);
		free(p->attribute_list);
		assert(p->next == NULL);
		free(p);
	}
}
struct attribute_specifier* owner attribute_specifier(struct parser_ctx* ctx)
{
	struct attribute_specifier* owner p_attribute_specifier = calloc(1, sizeof(struct attribute_specifier));

	p_attribute_specifier->first_token = ctx->current;

	//'[' '[' attribute_list ']' ']'
	parser_match_tk(ctx, '[');
	parser_match_tk(ctx, '[');
	p_attribute_specifier->attribute_list = attribute_list(ctx);
	parser_match_tk(ctx, ']');
	p_attribute_specifier->last_token = ctx->current;
	parser_match_tk(ctx, ']');
	return p_attribute_specifier;
}


void attribute_delete(struct attribute* owner p)
{
	if (p)
	{
		attribute_token_delete(p->attribute_token);
		attribute_argument_clause_delete(p->attribute_argument_clause);
		assert(p->next == NULL);
		free(p);
	}
}
void attribute_list_destroy(struct attribute_list* obj_owner p)
{
	struct attribute* owner item = p->head;
	while (item)
	{
		struct attribute* owner next = item->next;
		item->next = NULL;
		attribute_delete(item);
		item = next;
	}
}

struct attribute_list* owner attribute_list(struct parser_ctx* ctx)
{
	struct attribute_list* owner p_attribute_list = calloc(1, sizeof(struct attribute_list));
	//
	//attribute_list ',' attribute_opt
	while (ctx->current != NULL && (
		first_of_attribute(ctx) ||
		ctx->current->type == ','))
	{
		if (first_of_attribute(ctx))
		{
			struct attribute* owner p_attribute = attribute(ctx);
			p_attribute_list->attributes_flags |= p_attribute->attributes_flags;
			LIST_ADD(p_attribute_list, p_attribute);
		}
		if (ctx->current->type == ',')
		{
			parser_match(ctx);
		}
	}
	return p_attribute_list;
}

bool first_of_attribute(struct parser_ctx* ctx)
{
	if (ctx->current == NULL)
		return false;
	return ctx->current->type == TK_IDENTIFIER;
}

struct attribute* owner attribute(struct parser_ctx* ctx)
{
	struct attribute* owner p_attribute = calloc(1, sizeof(struct attribute));
	//attribute_token attribute_argument_clause_opt
	p_attribute->attribute_token = attribute_token(ctx);
	p_attribute->attributes_flags = p_attribute->attribute_token->attributes_flags;
	if (ctx->current->type == '(') //first
	{
		p_attribute->attribute_argument_clause = attribute_argument_clause(ctx);
	}
	return p_attribute;
}


void attribute_token_delete(struct attribute_token* owner p)
{
	if (p)
	{
		free(p);
	}
}
struct attribute_token* owner attribute_token(struct parser_ctx* ctx)
{
	struct attribute_token* owner p_attribute_token = calloc(1, sizeof(struct attribute_token));

	struct token* attr_token = ctx->current;

	bool is_standard_attribute = false;
	if (strcmp(attr_token->lexeme, "deprecated") == 0)
	{
		is_standard_attribute = true;
		p_attribute_token->attributes_flags = STD_ATTRIBUTE_DEPRECATED;
	}
	else if (strcmp(attr_token->lexeme, "fallthrough") == 0)
	{
		is_standard_attribute = true;
	}
	else if (strcmp(attr_token->lexeme, "maybe_unused") == 0)
	{
		is_standard_attribute = true;
		p_attribute_token->attributes_flags = STD_ATTRIBUTE_MAYBE_UNUSED;
	}
	else if (strcmp(attr_token->lexeme, "noreturn") == 0)
	{
		is_standard_attribute = true;
		p_attribute_token->attributes_flags = STD_ATTRIBUTE_NORETURN;
	}
	else if (strcmp(attr_token->lexeme, "reproducible") == 0)
	{
		is_standard_attribute = true;
		p_attribute_token->attributes_flags = STD_ATTRIBUTE_REPRODUCIBLE;
	}
	else if (strcmp(attr_token->lexeme, "unsequenced") == 0)
	{
		is_standard_attribute = true;
		p_attribute_token->attributes_flags = STD_ATTRIBUTE_UNSEQUENCED;
	}
	else if (strcmp(attr_token->lexeme, "nodiscard") == 0)
	{
		is_standard_attribute = true;
		p_attribute_token->attributes_flags = STD_ATTRIBUTE_NODISCARD;
	}

	const bool is_cake_attr =
		strcmp(attr_token->lexeme, "cake") == 0;

	parser_match_tk(ctx, TK_IDENTIFIER);

	if (ctx->current->type == '::')
	{
		parser_match(ctx);
		if (is_cake_attr)
		{

			compiler_set_warning_with_token(W_ATTRIBUTES, ctx, attr_token, "warning '%s' is not an cake attribute", ctx->current->lexeme);

		}
		parser_match_tk(ctx, TK_IDENTIFIER);
	}
	else
	{
		/*
		* Each implementation should choose a distinctive name for the attribute prefix in an attribute
		* prefixed token. Implementations should not define attributes without an attribute prefix unless it is
		* a standard attribute as specified in this document.
		*/
		if (!is_standard_attribute)
		{
			compiler_set_warning_with_token(W_ATTRIBUTES, ctx, attr_token, "warning '%s' is not an standard attribute", attr_token->lexeme);
		}
	}
	return p_attribute_token;
}


void attribute_argument_clause_delete(struct attribute_argument_clause* owner p)
{
	if (p)
	{
		balanced_token_sequence_delete(p->p_balanced_token_sequence);
		free(p);
	}
}
struct attribute_argument_clause* owner attribute_argument_clause(struct parser_ctx* ctx)
{
	struct attribute_argument_clause* owner p_attribute_argument_clause = calloc(1, sizeof(struct attribute_argument_clause));
	//'(' balanced_token_sequence_opt ')'
	parser_match_tk(ctx, '(');
	p_attribute_argument_clause->p_balanced_token_sequence = balanced_token_sequence_opt(ctx);
	parser_match_tk(ctx, ')');
	return p_attribute_argument_clause;
}


void balanced_token_sequence_delete(struct balanced_token_sequence* owner p)
{
	if (p)
	{
		struct balanced_token* owner item = p->head;
		while (item)
		{
			struct balanced_token* owner next = item->next;
			free(item);
			item = next;
		}
		free(p);
	}
}
struct balanced_token_sequence* owner balanced_token_sequence_opt(struct parser_ctx* ctx)
{
	struct balanced_token_sequence* owner p_balanced_token_sequence = calloc(1, sizeof(struct balanced_token_sequence));
	//balanced_token
	//balanced_token_sequence balanced_token
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	for (; ctx->current;)
	{
		if (ctx->current->type == '(')
			count1++;
		else if (ctx->current->type == '[')
			count2++;
		else if (ctx->current->type == '{')
			count3++;
		else if (ctx->current->type == ')')
		{
			if (count1 == 0)
			{
				//parser_match(ctx);
				break;
			}
			count1--;
		}
		else if (ctx->current->type == '[')
			count2--;
		else if (ctx->current->type == '{')
			count3--;
		parser_match(ctx);
	}
	if (count2 != 0)
	{
		compiler_set_error_with_token(C_ATTR_UNBALANCED, ctx, ctx->current, "expected ']' before ')'");

	}
	if (count3 != 0)
	{
		compiler_set_error_with_token(C_ATTR_UNBALANCED, ctx, ctx->current, "expected '}' before ')'");

	}
	return p_balanced_token_sequence;
}

void statement_delete(struct statement* owner p)
{
	if (p)
	{
		labeled_statement_delete(p->labeled_statement);
		unlabeled_statement_delete(p->unlabeled_statement);
		free(p);
	}
}
struct statement* owner statement(struct parser_ctx* ctx)
{
	struct statement* owner p_statement = calloc(1, sizeof(struct statement));
	if (first_of_labeled_statement(ctx))
	{
		p_statement->labeled_statement = labeled_statement(ctx);
	}
	else
	{
		p_statement->unlabeled_statement = unlabeled_statement(ctx);
	}

	return p_statement;
}

struct primary_block* owner primary_block(struct parser_ctx* ctx)
{
	assert(ctx->current != NULL);
	struct primary_block* owner p_primary_block = calloc(1, sizeof(struct primary_block));
	if (first_of_compound_statement(ctx))
	{
		p_primary_block->compound_statement = compound_statement(ctx);
	}
	else if (first_of_selection_statement(ctx))
	{
		p_primary_block->selection_statement = selection_statement(ctx);
	}
	else if (first_of_iteration_statement(ctx))
	{
		p_primary_block->iteration_statement = iteration_statement(ctx);
	}
	else if (ctx->current->type == TK_KEYWORD_DEFER)
	{
		p_primary_block->defer_statement = defer_statement(ctx);
	}
	else if (ctx->current->type == TK_KEYWORD_TRY)
	{
		p_primary_block->try_statement = try_statement(ctx);
	}
	else
	{
		compiler_set_error_with_token(C_UNEXPECTED_TOKEN, ctx, ctx->current, "unexpected token");
	}
	return p_primary_block;
}


struct secondary_block* owner secondary_block(struct parser_ctx* ctx)
{
	check_open_brace_style(ctx, ctx->current);

	struct secondary_block* owner  p_secondary_block = calloc(1, sizeof(struct secondary_block));
	p_secondary_block->first_token = ctx->current;


	p_secondary_block->statement = statement(ctx);

	p_secondary_block->last_token = ctx->previous;

	check_close_brace_style(ctx, p_secondary_block->last_token);

	return p_secondary_block;
}

void secondary_block_delete(struct secondary_block* owner opt p)
{
	if (p)
	{
		statement_delete(p->statement);
		free(p);
	}
}
void primary_block_delete(struct primary_block* owner p)
{
	if (p)
	{
		compound_statement_delete(p->compound_statement);
		defer_statement_delete(p->defer_statement);
		iteration_statement_delete(p->iteration_statement);
		selection_statement_delete(p->selection_statement);
		try_statement_delete(p->try_statement);
		free(p);
	}
}
bool first_of_primary_block(struct parser_ctx* ctx)
{
	if (first_of_compound_statement(ctx) ||
		first_of_selection_statement(ctx) ||
		first_of_iteration_statement(ctx) ||
		ctx->current->type == TK_KEYWORD_DEFER /*extension*/ ||
		ctx->current->type == TK_KEYWORD_TRY/*extension*/
		)
	{
		return true;
	}
	return false;
}

void unlabeled_statement_delete(struct unlabeled_statement* owner p)
{
	if (p)
	{
		expression_statement_delete(p->expression_statement);
		jump_statement_delete(p->jump_statement);
		primary_block_delete(p->primary_block);
		free(p);
	}
}
struct unlabeled_statement* owner unlabeled_statement(struct parser_ctx* ctx)
{
	/*
	 unlabeled-statement:
	   expression-statement
	   attribute-specifier-sequence opt primary-block
	   attribute-specifier-sequence opt jump-statement
	*/
	struct unlabeled_statement* owner p_unlabeled_statement = calloc(1, sizeof(struct unlabeled_statement));

	if (first_of_primary_block(ctx))
	{
		p_unlabeled_statement->primary_block = primary_block(ctx);
	}
	else if (first_of_jump_statement(ctx))
	{
		p_unlabeled_statement->jump_statement = jump_statement(ctx);
	}
	else
	{
		p_unlabeled_statement->expression_statement = expression_statement(ctx);
		if (p_unlabeled_statement->expression_statement)
		{
			if (p_unlabeled_statement->expression_statement->expression_opt)
			{
				if (!type_is_void(&p_unlabeled_statement->expression_statement->expression_opt->type) &&
					type_is_nodiscard(&p_unlabeled_statement->expression_statement->expression_opt->type) &&
					p_unlabeled_statement->expression_statement->expression_opt->type.storage_class_specifier_flags & STORAGE_SPECIFIER_FUNCTION_RETURN)
				{

					if (p_unlabeled_statement->expression_statement->expression_opt->first_token->level == 0)
					{
						compiler_set_warning_with_token(W_ATTRIBUTES, ctx,
							p_unlabeled_statement->expression_statement->expression_opt->first_token,
							"ignoring return value of function declared with 'nodiscard' attribute");
					}

				}
				if (type_is_owner(&p_unlabeled_statement->expression_statement->expression_opt->type) &&
					p_unlabeled_statement->expression_statement->expression_opt->type.storage_class_specifier_flags & STORAGE_SPECIFIER_FUNCTION_RETURN)
				{

					if (p_unlabeled_statement->expression_statement->expression_opt->first_token->level == 0)
					{
						compiler_set_warning_with_token(W_ATTRIBUTES, ctx,
							p_unlabeled_statement->expression_statement->expression_opt->first_token,
							"ignoring the result of owner type ");
					}

				}
			}
			if (p_unlabeled_statement->expression_statement->expression_opt &&
				p_unlabeled_statement->expression_statement->expression_opt->expression_type == POSTFIX_FUNCTION_CALL)
			{

			}
			else
			{
				/*
				*  The objective here is to detect expression with not effect
				*  a == b; etc
				*/
				if (p_unlabeled_statement != NULL &&
					p_unlabeled_statement->jump_statement == NULL &&
					p_unlabeled_statement->expression_statement != NULL &&
					p_unlabeled_statement->expression_statement->expression_opt &&
					!type_is_void(&p_unlabeled_statement->expression_statement->expression_opt->type) &&
					p_unlabeled_statement->expression_statement->expression_opt->expression_type != ASSIGNMENT_EXPRESSION &&
					p_unlabeled_statement->expression_statement->expression_opt->expression_type != POSTFIX_FUNCTION_CALL &&
					p_unlabeled_statement->expression_statement->expression_opt->expression_type != POSTFIX_INCREMENT &&
					p_unlabeled_statement->expression_statement->expression_opt->expression_type != POSTFIX_DECREMENT &&
					p_unlabeled_statement->expression_statement->expression_opt->expression_type != UNARY_EXPRESSION_INCREMENT &&
					p_unlabeled_statement->expression_statement->expression_opt->expression_type != UNARY_EXPRESSION_DECREMENT &&
					p_unlabeled_statement->expression_statement->expression_opt->expression_type != UNARY_DECLARATOR_ATTRIBUTE_EXPR &&
					p_unlabeled_statement->expression_statement->expression_opt->expression_type != UNARY_EXPRESSION_ASSERT)
				{
					if (ctx->current &&
						ctx->current->level == 0)
					{
#if 0
						//too many false..alerts.
						//make list of for sure ...
						compiler_set_warning_with_token(W_UNUSED_VALUE,
							ctx,
							p_unlabeled_statement->expression_statement->expression_opt->first_token,
							"expression not used");
#endif
					}
				}
			}
		}
	}

	return p_unlabeled_statement;
}

void label_delete(struct label* owner p)
{
	if (p)
	{
		expression_delete(p->constant_expression);
		free(p);
	}
}
struct label* owner label(struct parser_ctx* ctx)
{
	struct label* owner p_label = calloc(1, sizeof(struct label));
	if (ctx->current->type == TK_IDENTIFIER)
	{
		p_label->name = ctx->current;
		parser_match(ctx);
		parser_match_tk(ctx, ':');
	}
	else if (ctx->current->type == TK_KEYWORD_CASE)
	{
		parser_match(ctx);
		p_label->constant_expression = constant_expression(ctx, true);
		parser_match_tk(ctx, ':');
	}
	else if (ctx->current->type == TK_KEYWORD_DEFAULT)
	{
		parser_match(ctx);
		parser_match_tk(ctx, ':');
	}
	//attribute_specifier_sequence_opt identifier ':'
	//attribute_specifier_sequence_opt 'case' constant_expression ':'
	//attribute_specifier_sequence_opt 'default' ':'
	return p_label;
}

void labeled_statement_delete(struct labeled_statement* owner p)
{
	if (p)
	{
		label_delete(p->label);
		statement_delete(p->statement);
		free(p);
	}
}
struct labeled_statement* owner labeled_statement(struct parser_ctx* ctx)
{
	struct labeled_statement* owner p_labeled_statement = calloc(1, sizeof(struct labeled_statement));
	//label statement
	p_labeled_statement->label = label(ctx);
	p_labeled_statement->statement = statement(ctx);
	return p_labeled_statement;
}

void compound_statement_delete(struct compound_statement* owner p)
{
	if (p)
	{
		block_item_list_destroy(&p->block_item_list);
		free(p);
	}
}

struct compound_statement* owner compound_statement(struct parser_ctx* ctx)
{
	//'{' block_item_list_opt '}'
	struct compound_statement* owner p_compound_statement = calloc(1, sizeof(struct compound_statement));
	struct scope block_scope = { .variables.capacity = 10 };
	scope_list_push(&ctx->scopes, &block_scope);

	p_compound_statement->first_token = ctx->current;
	parser_match_tk(ctx, '{');

	if (ctx->current->type != '}')
	{
		p_compound_statement->block_item_list = block_item_list(ctx);
	}

	p_compound_statement->last_token = ctx->current;
	parser_match_tk(ctx, '}');

	//TODO ver quem nao foi usado.

	for (int i = 0; i < block_scope.variables.capacity; i++)
	{
		if (block_scope.variables.table == NULL)
			continue;
		struct map_entry* entry = block_scope.variables.table[i];
		while (entry)
		{

			if (entry->type != TAG_TYPE_ONLY_DECLARATOR &&
				entry->type != TAG_TYPE_INIT_DECLARATOR)
			{
				entry = entry->next;
				continue;
			}

			struct declarator* p_declarator = NULL;
			struct init_declarator* p_init_declarator = NULL;
			if (entry->type == TAG_TYPE_INIT_DECLARATOR)
			{
				p_init_declarator = entry->p;
				p_declarator = p_init_declarator->p_declarator;
			}
			else
			{
				p_declarator = entry->p;
			}

			if (p_declarator)
			{


				if (!type_is_maybe_unused(&p_declarator->type) &&
					p_declarator->num_uses == 0)
				{
					if (p_declarator->name->token_origin->level == 0)
					{
						compiler_set_warning_with_token(W_UNUSED_VARIABLE,
							ctx,
							p_declarator->name,
							"'%s': unreferenced declarator",
							p_declarator->name->lexeme);
					}
				}
			}

			entry = entry->next;
		}
	}

	scope_list_pop(&ctx->scopes);

	scope_destroy(&block_scope);

	return p_compound_statement;
}

void block_item_list_destroy(struct block_item_list* obj_owner list)
{
	struct block_item* owner item = list->head;
	while (item)
	{
		struct block_item* owner next = item->next;
		item->next = NULL;
		block_item_delete(item);
		item = next;
	}
}
struct block_item_list block_item_list(struct parser_ctx* ctx)
{
	/*
	  block_item_list:
	  block_item
	  block_item_list block_item
	*/
	struct block_item_list block_item_list = { 0 };
	struct block_item* owner p_block_item = NULL;
	try
	{
		p_block_item = block_item(ctx);
		if (p_block_item == NULL) throw;
		LIST_ADD(&block_item_list, p_block_item);
		p_block_item = NULL; /*MOVED*/

		while (ctx->current != NULL && ctx->current->type != '}') //follow
		{
			p_block_item = block_item(ctx);
			if (p_block_item == NULL) throw;
			LIST_ADD(&block_item_list, p_block_item);
			p_block_item = NULL; /*MOVED*/
		}
	}
	catch
	{
	}

	return block_item_list;
}

void block_item_delete(struct block_item* owner p)
{
	if (p)
	{
		declaration_delete(p->declaration);
		label_delete(p->label);
		unlabeled_statement_delete(p->unlabeled_statement);
		assert(p->next == NULL);
		free(p);
	}
}

struct block_item* owner block_item(struct parser_ctx* ctx)
{
	//   declaration
	//     unlabeled_statement
	//   label
	struct block_item* owner p_block_item = calloc(1, sizeof(struct block_item));


	/*
	* Attributes can be first of declaration, labels etc..
	* so it is better to parse it in advance.
	*/
	struct attribute_specifier_sequence* owner p_attribute_specifier_sequence_opt =
		attribute_specifier_sequence_opt(ctx);

	p_block_item->first_token = ctx->current;

	if (ctx->current->type == TK_KEYWORD__ASM)
	{  /*
	asm-block:
	__asm assembly-instruction ;opt
	__asm { assembly-instruction-list } ;opt

assembly-instruction-list:
	assembly-instruction ;opt
	assembly-instruction ; assembly-instruction-list ;opt
	*/

		parser_match(ctx);
		if (ctx->current->type == '{')
		{
			parser_match(ctx);
			while (ctx->current->type != '}')
			{
				parser_match(ctx);
			}
			parser_match(ctx);
		}
		else
		{
			while (ctx->current->type != TK_NEWLINE)
			{
				ctx->current = ctx->current->next;
			}
			parser_match(ctx);

		}
		if (ctx->current->type == ';')
			parser_match(ctx);
	}
	else if (first_of_declaration_specifier(ctx) ||
		first_of_static_assert_declaration(ctx))
	{
		p_block_item->declaration = declaration(ctx, p_attribute_specifier_sequence_opt, STORAGE_SPECIFIER_AUTOMATIC_STORAGE);

		p_attribute_specifier_sequence_opt = NULL; /*MOVED*/

		struct init_declarator* p = p_block_item->declaration->init_declarator_list.head;
		while (p)
		{
			if (p->p_declarator && p->p_declarator->name)
			{
				naming_convention_local_var(ctx, p->p_declarator->name, &p->p_declarator->type);
			}
			p = p->next;
		}
	}
	else if (first_of_label(ctx))
	{
		//so identifier confunde com expression
		p_block_item->label = label(ctx);
	}
	else
	{
		p_block_item->unlabeled_statement = unlabeled_statement(ctx);
	}
	/*
										   declaration-specifiers init-declarator-list_opt;
			  attribute-specifier-sequence declaration-specifiers init-declarator-list;
			  static_assert-declaration attribute_declaration
	*/
	/*
	unlabeled-statement:
	 expression-statement
	 attribute-specifier-sequenceopt compound-statement
	 attribute-specifier-sequenceopt selection-statement
	 attribute-specifier-sequenceopt iteration-statement
	 attribute-specifier-sequenceopt jump-statement

	label:
	attribute-specifier-sequenceopt identifier :
	attribute-specifier-sequenceopt case constant-expression :
	attribute-specifier-sequenceopt default :
	*/

	attribute_specifier_sequence_delete(p_attribute_specifier_sequence_opt);
	return p_block_item;
}


void try_statement_delete(struct try_statement* owner p)
{
	if (p)
	{
		secondary_block_delete(p->catch_secondary_block_opt);
		secondary_block_delete(p->secondary_block);
		free(p);
	}
}
struct try_statement* owner try_statement(struct parser_ctx* ctx)
{
	struct try_statement* owner p_try_statement = calloc(1, sizeof(struct try_statement));

	p_try_statement->first_token = ctx->current;

	assert(ctx->current->type == TK_KEYWORD_TRY);
	const struct try_statement* try_statement_copy_opt = ctx->p_current_try_statement_opt;
	ctx->p_current_try_statement_opt = p_try_statement;
	ctx->try_catch_block_index++;
	p_try_statement->try_catch_block_index = ctx->try_catch_block_index;
	parser_match_tk(ctx, TK_KEYWORD_TRY);

	p_try_statement->secondary_block = secondary_block(ctx);
	/*retores the previous one*/
	ctx->p_current_try_statement_opt = try_statement_copy_opt;


	if (ctx->current->type == TK_KEYWORD_CATCH)
	{
		p_try_statement->catch_token_opt = ctx->current;
		parser_match(ctx);

		p_try_statement->catch_secondary_block_opt = secondary_block(ctx);
	}
	p_try_statement->last_token = ctx->previous;

	return p_try_statement;
}

void selection_statement_delete(struct selection_statement* owner p)
{
	if (p)
	{
		secondary_block_delete(p->else_secondary_block_opt);
		init_declarator_delete(p->init_declarator);
		secondary_block_delete(p->secondary_block);
		declaration_specifiers_delete(p->declaration_specifiers);
		expression_delete(p->expression);
		free(p);
	}
}
struct selection_statement* owner selection_statement(struct parser_ctx* ctx)
{
	/*
	init-statement:
	expression-statement
	simple-declaration
	*/
	/*
	   'if' '(' init_statement_opt expression ')' statement
	   'if' '(' init_statement_opt expression ')' statement 'else' statement
	   'switch' '(' expression ')' statement
	*/
	/*
	   'if' '(' expression ')' statement
	   'if' '(' expression ')' statement 'else' statement
	   'switch' '(' expression ')' statement
	*/
	struct selection_statement* owner p_selection_statement = calloc(1, sizeof(struct selection_statement));

	p_selection_statement->first_token = ctx->current;

	struct scope if_scope = { 0 };
	scope_list_push(&ctx->scopes, &if_scope); //variaveis decladas no if

	if (ctx->current->type == TK_KEYWORD_IF)
	{
		parser_match(ctx);

		if (!(ctx->current->flags & TK_FLAG_MACRO_EXPANDED)
			&& !style_has_one_space(ctx->current))
		{
			compiler_set_info_with_token(W_STYLE, ctx, ctx->current, "one space");
		}

		parser_match_tk(ctx, '(');
		if (first_of_declaration_specifier(ctx))
		{
			p_selection_statement->declaration_specifiers = declaration_specifiers(ctx, STORAGE_SPECIFIER_AUTOMATIC_STORAGE);
			struct init_declarator_list list = init_declarator_list(ctx, p_selection_statement->declaration_specifiers);
			p_selection_statement->init_declarator = list.head; //only one
			parser_match_tk(ctx, ';');
		}


		p_selection_statement->expression = expression(ctx);

		if (constant_value_is_valid(&p_selection_statement->expression->constant_value))
		{
			//parser_setwarning_with_token(ctx, p_selection_statement->expression->first_token, "conditional expression is constant");
		}


		if (type_is_function(&p_selection_statement->expression->type) ||
			type_is_array(&p_selection_statement->expression->type))
		{
			compiler_set_warning_with_token(W_ADDRESS, ctx, ctx->current, "always true");
		}

		parser_match_tk(ctx, ')');

		p_selection_statement->secondary_block = secondary_block(ctx);

		if (ctx->current)
		{
			if (ctx->current->type == TK_KEYWORD_ELSE)
			{
				p_selection_statement->else_token_opt = ctx->current;
				parser_match(ctx);
				p_selection_statement->else_secondary_block_opt = secondary_block(ctx);
			}
		}
		else
		{
			compiler_set_error_with_token(C_UNEXPECTED_END_OF_FILE, ctx, ctx->input_list.tail, "unexpected end of file");
		}
	}
	else if (ctx->current->type == TK_KEYWORD_SWITCH)
	{
		parser_match(ctx);
		parser_match_tk(ctx, '(');

		p_selection_statement->expression = expression(ctx);
		parser_match_tk(ctx, ')');

		p_selection_statement->secondary_block = secondary_block(ctx);

	}
	else
	{
		assert(false);
		compiler_set_error_with_token(C_UNEXPECTED_TOKEN, ctx, ctx->input_list.tail, "unexpected token");
	}

	p_selection_statement->last_token = ctx->previous;

	scope_list_pop(&ctx->scopes);

	scope_destroy(&if_scope);

	return p_selection_statement;
}

struct defer_statement* owner  defer_statement(struct parser_ctx* ctx)
{
	struct defer_statement* owner p_defer_statement = calloc(1, sizeof(struct defer_statement));
	if (ctx->current->type == TK_KEYWORD_DEFER)
	{
		p_defer_statement->first_token = ctx->current;
		parser_match(ctx);
		p_defer_statement->secondary_block = secondary_block(ctx);
		p_defer_statement->last_token = ctx->previous;
	}
	return p_defer_statement;
}

void iteration_statement_delete(struct iteration_statement* owner p)
{
	if (p)
	{
		expression_delete(p->expression0);
		expression_delete(p->expression1);
		expression_delete(p->expression2);
		declaration_delete(p->declaration);
		secondary_block_delete(p->secondary_block);
		free(p);
	}
}
struct iteration_statement* owner  iteration_statement(struct parser_ctx* ctx)
{
	/*
	iteration-statement:
	  while ( expression ) statement
	  do statement while ( expression ) ;
	  for ( expressionopt ; expressionopt ; expressionopt ) statement
	  for ( declaration expressionopt ; expressionopt ) statement
	*/
	struct iteration_statement* owner  p_iteration_statement = calloc(1, sizeof(struct iteration_statement));


	p_iteration_statement->first_token = ctx->current;
	if (ctx->current->type == TK_KEYWORD_DO)
	{
		parser_match(ctx);
		p_iteration_statement->secondary_block = secondary_block(ctx);
		p_iteration_statement->second_token = ctx->current;
		parser_match_tk(ctx, TK_KEYWORD_WHILE);
		parser_match_tk(ctx, '(');

		p_iteration_statement->expression1 = expression(ctx);
		parser_match_tk(ctx, ')');
		parser_match_tk(ctx, ';');
	}
	else if (ctx->current->type == TK_KEYWORD_WHILE)
	{
		parser_match(ctx);
		parser_match_tk(ctx, '(');

		p_iteration_statement->expression1 = expression(ctx);
		parser_match_tk(ctx, ')');
		p_iteration_statement->secondary_block = secondary_block(ctx);
	}
	else if (ctx->current->type == TK_KEYWORD_FOR)
	{
		parser_match(ctx);
		parser_match_tk(ctx, '(');
		if (first_of_declaration_specifier(ctx))
		{
			struct scope for_scope = { 0 };
			scope_list_push(&ctx->scopes, &for_scope);

			p_iteration_statement->declaration = declaration(ctx, NULL, STORAGE_SPECIFIER_AUTOMATIC_STORAGE);
			if (ctx->current->type != ';')
			{
				p_iteration_statement->expression1 = expression(ctx);
			}
			parser_match_tk(ctx, ';');
			if (ctx->current->type != ')')
				p_iteration_statement->expression2 = expression(ctx);

			parser_match_tk(ctx, ')');

			p_iteration_statement->secondary_block = secondary_block(ctx);

			scope_list_pop(&ctx->scopes);

			scope_destroy(&for_scope);
		}
		else
		{
			/*
			*   int i;
			*   for (i = 0; i < 10; i++)
			*   {
			*   }
			*/

			if (ctx->current->type != ';')
				p_iteration_statement->expression0 = expression(ctx);
			parser_match_tk(ctx, ';');
			if (ctx->current->type != ';')
				p_iteration_statement->expression1 = expression(ctx);
			parser_match_tk(ctx, ';');
			if (ctx->current->type != ')')
				p_iteration_statement->expression2 = expression(ctx);
			parser_match_tk(ctx, ')');

			p_iteration_statement->secondary_block = secondary_block(ctx);
		}
	}
	return p_iteration_statement;
}

void jump_statement_delete(struct jump_statement* owner p)
{
	if (p)
	{
		expression_delete(p->expression_opt);
		free(p);
	}
}
struct jump_statement* owner jump_statement(struct parser_ctx* ctx)
{
	/*
	  jump-statement:
			goto identifier ;
			continue ;
			break ;
			return expressionopt ;
	*/

	/*
	   throw; (extension)
	*/

	struct jump_statement* owner p_jump_statement = calloc(1, sizeof(struct jump_statement));

	p_jump_statement->first_token = ctx->current;

	if (ctx->current->type == TK_KEYWORD_GOTO)
	{
		parser_match(ctx);
		p_jump_statement->label = ctx->current;
		parser_match_tk(ctx, TK_IDENTIFIER);
	}
	else if (ctx->current->type == TK_KEYWORD_CONTINUE)
	{
		parser_match(ctx);
	}
	else if (ctx->current->type == TK_KEYWORD_BREAK)
	{
		parser_match(ctx);
	}
	else if (ctx->current->type == TK_KEYWORD_THROW)
	{
		if (ctx->p_current_try_statement_opt == NULL)
		{

			compiler_set_error_with_token(C_THROW_STATEMENT_NOT_WITHIN_TRY_BLOCK, ctx, ctx->current, "throw statement not within try block");
		}
		else
		{
			p_jump_statement->try_catch_block_index = ctx->p_current_try_statement_opt->try_catch_block_index;
		}

		parser_match(ctx);
	}
	else if (ctx->current->type == TK_KEYWORD_RETURN)
	{
		const struct token* const p_return_token = ctx->current;
		parser_match(ctx);


		if (ctx->current->type != ';')
		{
			p_jump_statement->expression_opt = expression(ctx);


			if (p_jump_statement->expression_opt)
			{
				/*
				* Check is return type is compatible with function return
				*/
				struct type return_type =
					get_function_return_type(&ctx->p_current_function_opt->init_declarator_list.head->p_declarator->type);

				if (type_is_void(&return_type))
				{
					compiler_set_error_with_token(C_VOID_FUNCTION_SHOULD_NOT_RETURN_VALUE,
						ctx,
						p_return_token,
						"void function '%s' should not return a value",
						ctx->p_current_function_opt->init_declarator_list.head->p_declarator->name->lexeme);
				}
				else
				{
					if (p_jump_statement->expression_opt)
					{
						check_assigment(ctx,
							&return_type,
							p_jump_statement->expression_opt,
							true);

					}
				}


				type_destroy(&return_type);
			}
		}
	}
	else
	{
		assert(false);
	}
	p_jump_statement->last_token = ctx->current;
	parser_match_tk(ctx, ';');
	return p_jump_statement;
}

void expression_statement_delete(struct expression_statement* owner p)
{
	if (p)
	{
		attribute_specifier_sequence_delete(p->p_attribute_specifier_sequence_opt);
		expression_delete(p->expression_opt);
		free(p);
	}
}

struct expression_statement* owner expression_statement(struct parser_ctx* ctx)
{
	struct expression_statement* owner p_expression_statement = calloc(1, sizeof(struct expression_statement));
	/*
	 expression-statement:
	   expression opt ;
	   attribute-specifier-sequence expression ;
	*/

	p_expression_statement->p_attribute_specifier_sequence_opt =
		attribute_specifier_sequence_opt(ctx);

	if (ctx->current->type != ';')
	{
		p_expression_statement->expression_opt = expression(ctx);
	}

	parser_match_tk(ctx, ';');

	return p_expression_statement;
}

void declaration_list_add(struct declaration_list* list, struct declaration* owner p_declaration)
{
	if (list->head == NULL)
	{
		list->head = p_declaration;
	}
	else
	{
		assert(list->tail->next == NULL);
		list->tail->next = p_declaration;
	}
	list->tail = p_declaration;
}

void declaration_delete(struct declaration* owner p)
{
	if (p)
	{

		attribute_specifier_sequence_delete(p->p_attribute_specifier_sequence_opt);
		static_assert_declaration_delete(p->static_assert_declaration);

		declaration_specifiers_delete(p->declaration_specifiers);

		compound_statement_delete(p->function_body);

		init_declarator_list_destroy(&p->init_declarator_list);
		assert(p->next == NULL);
		free(p);
	}
}

void declaration_list_destroy(struct declaration_list* obj_owner list)
{
	struct declaration* owner p = list->head;
	while (p)
	{
		struct declaration* owner next = p->next;
		p->next = NULL;
		declaration_delete(p);
		p = next;
	}
}

struct declaration_list translation_unit(struct parser_ctx* ctx)
{
	struct declaration_list declaration_list = { 0 };
	/*
	  translation_unit:
	  external_declaration
	  translation_unit external_declaration
	*/
	while (ctx->current != NULL)
	{
		declaration_list_add(&declaration_list, external_declaration(ctx));
	}
	return declaration_list;
}


struct declaration* owner external_declaration(struct parser_ctx* ctx)
{
	/*
	 function_definition
	 declaration
	 */
	return function_definition_or_declaration(ctx);
}

struct compound_statement* owner function_body(struct parser_ctx* ctx)
{
	/*
	* Used to give an unique index (inside the function)
	* for try-catch blocks
	*/
	ctx->try_catch_block_index = 0;
	ctx->p_current_try_statement_opt = NULL;
	return compound_statement(ctx);
}

static void show_unused_file_scope(struct parser_ctx* ctx)
{

	for (int i = 0; i < ctx->scopes.head->variables.capacity; i++)
	{
		if (ctx->scopes.head->variables.table == NULL)
			continue;
		struct map_entry* entry = ctx->scopes.head->variables.table[i];
		while (entry)
		{

			if (entry->type != TAG_TYPE_ONLY_DECLARATOR &&
				entry->type != TAG_TYPE_INIT_DECLARATOR)
			{
				entry = entry->next;
				continue;
			}

			struct declarator* p_declarator = NULL;
			struct init_declarator* p_init_declarator = NULL;
			if (entry->type == TAG_TYPE_INIT_DECLARATOR)
			{
				p_init_declarator = entry->p;
				p_declarator = p_init_declarator->p_declarator;
			}
			else
			{
				p_declarator = entry->p;
			}

			if (p_declarator &&
				p_declarator->first_token &&
				p_declarator->first_token->level == 0 &&
				declarator_is_function(p_declarator) &&
				(p_declarator->declaration_specifiers->storage_class_specifier_flags & STORAGE_SPECIFIER_STATIC))
			{
				if (!type_is_maybe_unused(&p_declarator->type) &&
					p_declarator->num_uses == 0)
				{
					compiler_set_warning_with_token(W_UNUSED_VARIABLE,
						ctx,
						p_declarator->name,
						"declarator '%s' not used", p_declarator->name->lexeme);
				}
			}

			entry = entry->next;
		}
	}
}

struct declaration_list parse(struct parser_ctx* ctx,
	struct token_list* list)
{

	s_anonymous_struct_count = 0;

	struct scope file_scope = { 0 };

	scope_list_push(&ctx->scopes, &file_scope);
	ctx->input_list = *list;
	ctx->current = ctx->input_list.head;
	parser_skip_blanks(ctx);

	struct declaration_list l = translation_unit(ctx);
	show_unused_file_scope(ctx);


	scope_destroy(&file_scope);

	return l;
}



int fill_preprocessor_options(int argc, const char** argv, struct preprocessor_ctx* prectx)
{
	/*first loop used to collect options*/
	for (int i = 1; i < argc; i++)
	{
		if (argv[i][0] != '-')
			continue;


		if (argv[i][1] == 'I')
		{
			include_dir_add(&prectx->include_dir, argv[i] + 2);
			continue;
		}
		if (argv[i][1] == 'D')
		{
			char buffer[200];
			snprintf(buffer, sizeof buffer, "#define %s \n", argv[i] + 2);

			/*TODO make it more precise*/
			char* p = &buffer[7];
			while (*p)
			{
				if (*p == '=')
				{
					*p = ' ';
					break;
				}
				p++;
			}

			struct tokenizer_ctx tctx = { 0 };
			struct token_list l1 = tokenizer(&tctx, buffer, "", 0, TK_FLAG_NONE);
			struct token_list r = preprocessor(prectx, &l1, 0);
			token_list_destroy(&l1);
			token_list_destroy(&r);
			continue;
		}
	}
	return 0;
}

#ifdef _WIN32
unsigned long __stdcall GetEnvironmentVariableA(
	const char* lpname,
	char* lpbuffer,
	unsigned long nsize
);
#else

unsigned long GetEnvironmentVariableA(
	const char* lpname,
	char* lpbuffer,
	unsigned long nsize
)
{

}
#endif

void append_msvc_include_dir(struct preprocessor_ctx* prectx)
{



#ifdef _WIN32
	char env[2000] = { 0 };
	int n = GetEnvironmentVariableA("INCLUDE", env, sizeof(env));

	if (n > 0)
	{

		const char* p = env;
		for (;;)
		{
			if (*p == '\0')
			{
				break;
			}
			char filename_local[500] = { 0 };
			int count = 0;
			while (*p != '\0' && (*p != ';' && *p != '\n'))
			{
				filename_local[count] = *p;
				p++;
				count++;
			}
			filename_local[count] = 0;
			if (count > 0)
			{
				strcat(filename_local, "/");
				include_dir_add(&prectx->include_dir, filename_local);
			}
			if (*p == '\0')
			{
				break;
			}
			p++;
		}
	}
#endif

}

const char* owner format_code(struct options* options, const char* content)
{
	struct ast ast = { 0 };
	const char* owner s = NULL;


	struct preprocessor_ctx prectx = { 0 };

	prectx.macros.capacity = 5000;
	add_standard_macros(&prectx);

	struct report report = { 0 };
	struct parser_ctx ctx = { 0 };
	ctx.options = *options;
	ctx.p_report = &report;
	struct tokenizer_ctx tctx = { 0 };
	struct token_list tokens = { 0 };

	try
	{
		prectx.options = *options;
		append_msvc_include_dir(&prectx);

		tokens = tokenizer(&tctx, content, "", 0, TK_FLAG_NONE);
		ast.token_list = preprocessor(&prectx, &tokens, 0);
		if (prectx.n_errors != 0) throw;


		ast.declaration_list = parse(&ctx, &ast.token_list);
		if (report.error_count > 0) throw;

		struct format_visit_ctx visit_ctx = { 0 };
		visit_ctx.ast = ast;
		format_visit(&visit_ctx);

		if (options->direct_compilation)
			s = get_code_as_compiler_see(&visit_ctx.ast.token_list);
		else
			s = get_code_as_we_see(&visit_ctx.ast.token_list, options->remove_comments);

	}
	catch
	{

	}

	token_list_destroy(&tokens);

	parser_ctx_destroy(&ctx);
	ast_destroy(&ast);
	preprocessor_ctx_destroy(&prectx);
	return s;
}


void ast_format_visit(struct ast* ast)
{
	/*format input source before transformation*/
	struct format_visit_ctx visit_ctx = { 0 };
	visit_ctx.ast = *ast;
	format_visit(&visit_ctx);
}

void c_visit(struct ast* ast)
{

}

int compile_one_file(const char* file_name,
	struct options* options,
	const char* out_file_name,
	int argc,
	const char** argv,
	struct report* report)
{
	printf("%s\n", file_name);
	struct preprocessor_ctx prectx = { 0 };

	prectx.macros.capacity = 5000;

	add_standard_macros(&prectx);

	include_config_header(&prectx);
	//print_all_macros(&prectx);

	struct ast ast = { 0 };

	const char* owner s = NULL;

	struct parser_ctx ctx = { 0 };
	struct visit_ctx visit_ctx = { 0 };
	struct tokenizer_ctx tctx = { 0 };
	struct token_list tokens = { 0 };

	ctx.options = *options;
	ctx.p_report = report;
	char* owner content = NULL;

	try
	{


		if (fill_preprocessor_options(argc, argv, &prectx) != 0)
		{
			throw;
		}

		prectx.options = *options;
		append_msvc_include_dir(&prectx);



		content = read_file(file_name);
		if (content == NULL)
		{
			report->error_count++;
			printf("file not found '%s'\n", file_name);
			throw;
		}

		if (options->sarif_output)
		{
			char sarif_file_name[260] = { 0 };
			strcpy(sarif_file_name, file_name);
			strcat(sarif_file_name, ".sarif");
			ctx.sarif_file = (FILE * owner) fopen(sarif_file_name, "w");
			if (ctx.sarif_file)
			{
				const char* begin_sarif =
					"{\n"
					"  \"version\": \"2.1.0\",\n"
					//"  \"$schema\": \"https://raw.githubusercontent.com/oasis-tcs/sarif-spec/master/Schemata/sarif-schema-2.1.0.json\",\n"
					"  \"$schema\": \"https://schemastore.azurewebsites.net/schemas/json/sarif-2.1.0-rtm.5.json\",\n"
					"  \"runs\": [\n"
					"    {\n"
					"      \"results\": [\n"
					"\n";

				fprintf(ctx.sarif_file, "%s", begin_sarif);
			}
			else
			{
				report->error_count++;
				printf("cannot open sarif output file '%s'\n", sarif_file_name);
				throw;
			}
		}

		tokens = tokenizer(&tctx, content, file_name, 0, TK_FLAG_NONE);

		ast.token_list = preprocessor(&prectx, &tokens, 0);
		if (prectx.n_errors > 0) throw;

		if (options->preprocess_only)
		{
			const char* owner s2 = print_preprocessed_to_string2(ast.token_list.head);
			printf("%s", s2);
			free((void* owner)s2);
		}
		else
		{

			ast.declaration_list = parse(&ctx, &ast.token_list);
			if (report->error_count > 0) throw;

			//ast_wasm_visit(&ast);

			if (!options->no_output)
			{
				if (options->format_input)
				{
					struct format_visit_ctx f = { .ast = ast, .indentation = 4 };
					format_visit(&f);
				}

				visit_ctx.target = options->target;
				visit_ctx.hide_non_used_declarations = options->direct_compilation;

				visit_ctx.ast = ast;
				visit(&visit_ctx);

				if (options->direct_compilation)
					s = get_code_as_compiler_see(&visit_ctx.ast.token_list);
				else
					s = get_code_as_we_see(&visit_ctx.ast.token_list, options->remove_comments);

				if (options->format_ouput)
				{
					/*re-parser ouput and format*/
					const char* owner s2 = format_code(options, s);
					free((void* owner)s);
					s = s2;
				}

				FILE* owner outfile = fopen(out_file_name, "w");
				if (outfile)
				{
					if (s)
						fprintf(outfile, "%s", s);

					fclose(outfile);
					//printf("%-30s ", path);
				}
				else
				{
					report->error_count++;
					printf("cannot open output file '%s' - %s\n", out_file_name, get_posix_error_message(errno));
					throw;
				}


			}
		}
	}
	catch
	{
		//printf("Error %s\n", error->message);
	}

	if (ctx.sarif_file)
	{
		if (ctx.sarif_file)
		{
#define END \
"      ],\n"\
"      \"tool\": {\n"\
"        \"driver\": {\n"\
"          \"name\": \"cake\",\n"\
"          \"fullName\": \"cake code analysis\",\n"\
"          \"version\": \"0.5\",\n"\
"          \"informationUri\": \"https://github.com/cake-build\"\n"\
"        }\n"\
"      }\n"\
"    }\n"\
"  ]\n"\
"}\n"\
"\n"
			fprintf(ctx.sarif_file, "%s", END);
		}
		fclose(ctx.sarif_file);
		ctx.sarif_file = NULL;
	}
	token_list_destroy(&tokens);
	visit_ctx_destroy(&visit_ctx);
	parser_ctx_destroy(&ctx);
	free((void* owner)s);
	free(content);
	ast_destroy(&ast);
	preprocessor_ctx_destroy(&prectx);

	return report->error_count > 0;
}

static void longest_common_path(int argc, const char** argv, char root_dir[MAX_PATH])
{
	/*
	 find the longest common path
	*/
	for (int i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
			continue;

		char fullpath_i[MAX_PATH] = { 0 };
		realpath(argv[i], fullpath_i);
		strcpy(root_dir, fullpath_i);
		dirname(root_dir);

		for (int k = 0; ; k++)
		{
			const char ch = fullpath_i[k];
			for (int j = 2; j < argc; j++)
			{
				if (argv[j][0] == '-')
					continue;

				char fullpath_j[MAX_PATH] = { 0 };
				realpath(argv[j], fullpath_j);
				if (fullpath_j[k] != ch)
				{
					strncpy(root_dir, fullpath_j, k);
					root_dir[k] = '\0';
					dirname(root_dir);
					goto exit;
				}
			}
			if (ch == '\0')
				break;
		}
	}
exit:;
}

static int create_multiple_paths(const char* root, const char* outdir)
{
	/*
	   This function creates all dirs (folder1, forder2 ..) after root
	   root   : C:/folder
	   outdir : C:/folder/folder1/folder2 ...
	*/

	const char* p = outdir + strlen(root) + 1;
	for (;;)
	{
		if (*p != '\0' && *p != '/' && *p != '\\')
		{
			p++;
			continue;
		}

		char temp[MAX_PATH] = { 0 };
		strncpy(temp, outdir, p - outdir);

		int er = mkdir(temp, 0777);
		if (er != 0)
		{
			er = errno;
			if (er != EEXIST)
			{
				printf("error creating output folder '%s' - %s\n", temp, get_posix_error_message(er));
				return er;
			}
		}
		if (*p == '\0')
			break;
		p++;
	}
	return 0;
}

int compile(int argc, const char** argv, struct report* report)
{
	struct options options = { 0 };
	if (fill_options(&options, argc, argv) != 0)
	{
		return 1;
	}

	clock_t begin_clock = clock();
	int no_files = 0;

	char root_dir[MAX_PATH] = { 0 };

	if (!options.no_output)
	{
		longest_common_path(argc, argv, root_dir);
	}

	const int root_dir_len = strlen(root_dir);

	/*second loop to compile each file*/
	for (int i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-')
			continue;
		no_files++;
		char output_file[400] = { 0 };

		if (!options.no_output)
		{
			if (no_files == 1 && options.output[0] != '\0')
			{
				/*
				   -o outputname
				   works when we compile just one file
				*/
				strcat(output_file, options.output);
			}
			else
			{
				char fullpath[MAX_PATH] = { 0 };
				realpath(argv[i], fullpath);

				strcpy(output_file, root_dir);
				strcat(output_file, "/out");

				strcat(output_file, fullpath + root_dir_len);

				char outdir[MAX_PATH];
				strcpy(outdir, output_file);
				dirname(outdir);
				if (create_multiple_paths(root_dir, outdir) != 0)
				{
					return 1;
				}
			}
		}

		char fullpath[260];
		realpath(argv[i], fullpath);
		compile_one_file(fullpath, &options, output_file, argc, argv, report);
	}


	clock_t end_clock = clock();
	double cpu_time_used = ((double)(end_clock - begin_clock)) / CLOCKS_PER_SEC;
	report->no_files = no_files;
	report->cpu_time_used_sec = cpu_time_used;
	return 0;
}


struct ast get_ast(struct options* options,
	const char* filename,
	const char* source,
	struct report* report)
{
	struct ast ast = { 0 };
	struct tokenizer_ctx tctx = { 0 };

	struct token_list list = tokenizer(&tctx, source, filename, 0, TK_FLAG_NONE);

	struct preprocessor_ctx prectx = { 0 };
	prectx.options = *options;
	prectx.macros.capacity = 5000;

	add_standard_macros(&prectx);


	ast.token_list = preprocessor(&prectx, &list, 0);

	if (prectx.n_errors == 0)
	{
		struct parser_ctx ctx = { 0 };
		ctx.options = *options;
		ctx.p_report = report;
		ast.declaration_list = parse(&ctx, &ast.token_list);
		parser_ctx_destroy(&ctx);
	}

	token_list_destroy(&list);
	preprocessor_ctx_destroy(&prectx);

	return ast;
}

/*
* dada uma string s produz o argv modificando a string de entrada
* return argc
*/
int strtoargv(char* s, int n, const char* argv[/*n*/])
{
	int argvc = 0;
	char* p = s;
	while (*p)
	{
		while (*p == ' ')
			p++;
		if (*p == 0)
			break;
		argv[argvc] = p;
		argvc++;
		while (*p != ' ' && *p != '\0')
			p++;
		if (*p == 0)
			break;
		*p = 0;
		p++;
		if (argvc >= n)
			break;/*nao tem mais lugares*/
	}
	return argvc;
}

const char* owner compile_source(const char* pszoptions, const char* content, struct report* report)
{
	const char* argv[100] = { 0 };
	char string[200] = { 0 };
	snprintf(string, sizeof string, "exepath %s", pszoptions);

	const int argc = strtoargv(string, 10, argv);

	const char* owner s = NULL;

	struct preprocessor_ctx prectx = { 0 };
	struct ast ast = { 0 };
	struct options options = { .input = LANGUAGE_CXX };

	struct visit_ctx visit_ctx = { 0 };
	try
	{
		if (fill_options(&options, argc, argv) != 0)
		{
			throw;
		}

		visit_ctx.target = options.target;
		visit_ctx.hide_non_used_declarations = options.direct_compilation;
		prectx.options = options;
		add_standard_macros(&prectx);


		if (options.preprocess_only)
		{
			struct tokenizer_ctx tctx = { 0 };
			struct token_list tokens = tokenizer(&tctx, content, "c:/main.c", 0, TK_FLAG_NONE);


			struct token_list token_list = preprocessor(&prectx, &tokens, 0);
			if (prectx.n_errors == 0)
			{
				s = print_preprocessed_to_string2(token_list.head);
			}

			token_list_destroy(&tokens);
			token_list_destroy(&token_list);
		}
		else
		{

			ast = get_ast(&options, "c:/main.c", content, report);
			if (report->error_count > 0) throw;

			visit_ctx.ast = ast;
			visit(&visit_ctx);

			if (options.direct_compilation)
			{
				s = get_code_as_compiler_see(&visit_ctx.ast.token_list);
			}
			else
			{
				s = get_code_as_we_see(&visit_ctx.ast.token_list, options.remove_comments);
			}
			if (options.format_ouput)
			{

				/*re-parser ouput and format*/
				const char* owner s2 = format_code(&options, s);
				free((void* owner) s);
				s = s2;
			}

		}
	}
	catch
	{
	}

	preprocessor_ctx_destroy(&prectx);
	visit_ctx_destroy(&visit_ctx);
	ast_destroy(&ast);

	return s;
}



char* owner CompileText(const char* pszoptions, const char* content)
{
	/*
	  This function is called by the web playground
	*/
	printf(WHITE "Cake " CAKE_VERSION RESET "\n");
	struct report report = { 0 };
	return  (char* owner) compile_source(pszoptions, content, &report);
}

void ast_destroy(struct ast* obj_owner ast)
{
	token_list_destroy(&ast->token_list);
	declaration_list_destroy(&ast->declaration_list);
}

static bool is_all_upper(const char* text)
{
	const char* p = text;
	while (*p)
	{
		if (*p != toupper(*p))
		{
			return false;
		}
		p++;
	}
	return true;
}

static bool is_snake_case(const char* text)
{
	if (text == NULL)
		return true;

	if (!(*text >= 'a' && *text <= 'z'))
	{
		return false;
	}

	while (*text)
	{
		if ((*text >= 'a' && *text <= 'z') ||
			*text == '_' ||
			(*text >= '0' && *text <= '9'))

		{
			//ok
		}
		else
			return false;
		text++;
	}

	return true;
}

static bool is_camel_case(const char* text)
{
	if (text == NULL)
		return true;

	if (!(*text >= 'a' && *text <= 'z'))
	{
		return false;
	}

	while (*text)
	{
		if ((*text >= 'a' && *text <= 'z') ||
			(*text >= 'A' && *text <= 'Z') ||
			(*text >= '0' && *text <= '9'))
		{
			//ok
		}
		else
			return false;
		text++;
	}

	return true;
}

static bool is_pascal_case(const char* text)
{
	if (text == NULL)
		return true;

	if (!(text[0] >= 'A' && text[0] <= 'Z'))
	{
		/*first letter uppepr case*/
		return false;
	}

	while (*text)
	{
		if ((*text >= 'a' && *text <= 'z') ||
			(*text >= 'A' && *text <= 'Z') ||
			(*text >= '0' && *text <= '9'))
		{
			//ok
		}
		else
			return false;
		text++;
	}

	return true;
}

/*
 * This naming conventions are not ready yet...
 * but not dificult to implement.maybe options to choose style
 */
void naming_convention_struct_tag(struct parser_ctx* ctx, struct token* token)
{
	if (!parser_is_warning_enabled(ctx, W_STYLE) || token->level != 0)
	{
		return;
	}

	if (ctx->options.style == STYLE_CAKE)
	{
		if (!is_snake_case(token->lexeme))
		{
			compiler_set_info_with_token(W_STYLE, ctx, token, "use snake_case for struct/union tags");
		}
	}
	else if (ctx->options.style == STYLE_MICROSOFT)
	{
		if (!is_pascal_case(token->lexeme))
		{
			compiler_set_info_with_token(W_STYLE, ctx, token, "use camelCase for struct/union tags");
		}
	}
}

void naming_convention_enum_tag(struct parser_ctx* ctx, struct token* token)
{
	if (!parser_is_warning_enabled(ctx, W_STYLE) || token->level != 0)
	{
		return;
	}


	if (ctx->options.style == STYLE_CAKE)
	{
		if (!is_snake_case(token->lexeme))
		{
			compiler_set_info_with_token(W_STYLE, ctx, token, "use snake_case for enum tags");
		}
	}
	else if (ctx->options.style == STYLE_MICROSOFT)
	{
		if (!is_pascal_case(token->lexeme))
		{
			compiler_set_info_with_token(W_STYLE, ctx, token, "use PascalCase for enum tags");
		}
	}
}

void naming_convention_function(struct parser_ctx* ctx, struct token* token)
{
	if (token == NULL)
		return;

	if (!parser_is_warning_enabled(ctx, W_STYLE) || token->level != 0)
	{
		return;
	}

	if (ctx->options.style == STYLE_CAKE)
	{
		if (!is_snake_case(token->lexeme))
		{
			compiler_set_info_with_token(W_STYLE, ctx, token, "use snake_case for functions");
		}
	}
	else if (ctx->options.style == STYLE_MICROSOFT)
	{
		if (!is_pascal_case(token->lexeme))
		{
			compiler_set_info_with_token(W_STYLE, ctx, token, "use PascalCase for functions");
		}
	}
}

void naming_convention_global_var(struct parser_ctx* ctx, struct token* token, struct type* type, enum storage_class_specifier_flags storage)
{
	if (!parser_is_warning_enabled(ctx, W_STYLE) || token->level != 0)
	{
		return;
	}


	if (!type_is_function_or_function_pointer(type))
	{
		if (storage & STORAGE_SPECIFIER_STATIC)
		{
			if (token->lexeme[0] != 's' || token->lexeme[1] != '_')
			{
				compiler_set_info_with_token(W_STYLE, ctx, token, "use prefix s_ for static global variables");
			}
		}
		if (!is_snake_case(token->lexeme))
		{
			compiler_set_info_with_token(W_STYLE, ctx, token, "use snake_case global variables");
		}
	}
}

void naming_convention_local_var(struct parser_ctx* ctx, struct token* token, struct type* type)
{
	if (!parser_is_warning_enabled(ctx, W_STYLE) || token->level != 0)
	{
		return;
	}


	if (ctx->options.style == STYLE_CAKE)
	{
		if (!is_snake_case(token->lexeme))
		{
			compiler_set_info_with_token(W_STYLE, ctx, token, "use snake_case for local variables");
		}
	}
	else if (ctx->options.style == STYLE_MICROSOFT)
	{
		if (!is_camel_case(token->lexeme))
		{
			compiler_set_info_with_token(W_STYLE, ctx, token, "use camelCase for local variables");
		}
	}

}

void naming_convention_enumerator(struct parser_ctx* ctx, struct token* token)
{
	if (!parser_is_warning_enabled(ctx, W_STYLE) || token->level != 0)
	{
		return;
	}

	if (!is_all_upper(token->lexeme))
	{
		compiler_set_info_with_token(W_STYLE, ctx, token, "use UPPERCASE for enumerators");
	}
}

void naming_convention_struct_member(struct parser_ctx* ctx, struct token* token, struct type* type)
{
	if (!parser_is_warning_enabled(ctx, W_STYLE) || token->level != 0)
	{
		return;
	}

	if (!is_snake_case(token->lexeme))
	{
		compiler_set_info_with_token(W_STYLE, ctx, token, "use snake_case for struct members");
	}
}

void naming_convention_parameter(struct parser_ctx* ctx, struct token* token, struct type* type)
{
	if (!parser_is_warning_enabled(ctx, W_STYLE) || token->level != 0)
	{
		return;
	}

	if (!is_snake_case(token->lexeme))
	{
		compiler_set_info_with_token(W_STYLE, ctx, token, "use snake_case for arguments");
	}
}





void defer_scope_delete_all(struct defer_scope* owner p);

void visit_ctx_destroy(struct visit_ctx* obj_owner ctx)
{
	defer_scope_delete_all(ctx->tail_block);
	token_list_destroy(&ctx->insert_before_declaration);
	token_list_destroy(&ctx->insert_before_block_item);
}

static void visit_attribute_specifier_sequence(struct visit_ctx* ctx, struct attribute_specifier_sequence* p_visit_attribute_specifier_sequence);

struct token* next_parser_token(struct token* token)
{
	struct token* r = token->next;
	while (!(r->flags & TK_FLAG_FINAL))
	{
		r = r->next;
	}
	return r;
}

static void visit_struct_or_union_specifier(struct visit_ctx* ctx, struct struct_or_union_specifier* p_struct_or_union_specifier);
static void visit_expression(struct visit_ctx* ctx, struct expression* p_expression);
static void visit_statement(struct visit_ctx* ctx, struct statement* p_statement);
static void visit_enum_specifier(struct visit_ctx* ctx, struct enum_specifier* p_enum_specifier);
static void visit_type_specifier(struct visit_ctx* ctx, struct type_specifier* p_type_specifier);

void convert_if_statement(struct visit_ctx* ctx, struct selection_statement* p_selection_statement)
{
	if (p_selection_statement->init_declarator == NULL ||
		p_selection_statement->first_token->type != TK_KEYWORD_IF)
	{
		return;
	}

	struct token* before_first_token =
		p_selection_statement->first_token->prev;
	struct token* token =
		next_parser_token(p_selection_statement->first_token);
	token = next_parser_token(token);
	struct token* first = token;
	while (token)
	{
		if (token->type == ';')
			break;
		token = next_parser_token(token);
	}
	struct token_list list =
		token_list_remove_get(&ctx->ast.token_list, first, token);

	token_list_insert_after(&ctx->ast.token_list,
		before_first_token,
		&list);

	struct tokenizer_ctx tctx = { 0 };
	struct token_list list1 = tokenizer(&tctx, "{", "", 0, TK_FLAG_FINAL);
	token_list_insert_after(&ctx->ast.token_list,
		before_first_token,
		&list1);
	struct token_list list2 = tokenizer(&tctx, "}", "", 0, TK_FLAG_FINAL);
	token_list_insert_after(&ctx->ast.token_list,
		p_selection_statement->last_token,
		&list2);
	token_list_destroy(&list2);
	token_list_destroy(&list1);
	token_list_destroy(&list);
}

void print_block_defer(struct defer_scope* defer_block, struct osstream* ss, bool hide_tokens)
{
	struct defer_scope* defer_child = defer_block->lastchild;
	while (defer_child != NULL)
	{
		view struct token_list l = { 0 };

		l.head = defer_child->defer_statement->first_token;
		l.tail = defer_child->defer_statement->last_token;

		l.head->flags |= TK_FLAG_HIDE;
		const char* owner s = get_code_as_compiler_see(&l);
		if (s != NULL)
		{
			if (hide_tokens)
				token_range_add_flag(l.head, l.tail, TK_FLAG_HIDE);

			ss_fprintf(ss, "%s", s);
			free((void* owner)s);
		}
		defer_child = defer_child->previous;
	}
}


void hide_block_defer(struct defer_scope* deferblock)
{
	struct defer_scope* deferchild = deferblock->lastchild;
	while (deferchild != NULL)
	{
		struct token* head = deferchild->defer_statement->first_token;
		struct token* tail = deferchild->defer_statement->last_token;
		token_range_add_flag(head, tail, TK_FLAG_HIDE);
		deferchild = deferchild->previous;
	}
}


void print_all_defer_until_try(struct defer_scope* deferblock, struct osstream* ss)
{
	struct defer_scope* p_defer = deferblock;
	while (p_defer != NULL)
	{
		print_block_defer(p_defer, ss, false);

		if (p_defer->p_try_statement)
		{
			break;
		}

		p_defer = p_defer->previous;
	}
}

bool find_label_statement(struct statement* statement, const char* label);
bool find_label_unlabeled_statement(struct unlabeled_statement* p_unlabeled_statement, const char* label)
{
	if (p_unlabeled_statement->primary_block)
	{
		if (p_unlabeled_statement->primary_block->compound_statement)
		{
			struct block_item* block_item =
				p_unlabeled_statement->primary_block->compound_statement->block_item_list.head;
			while (block_item)
			{
				if (block_item &&
					block_item->label &&
					block_item->label->name &&
					strcmp(block_item->label->name->lexeme, label) == 0)
				{
					/*achou*/
					return true;
				}
				else if (block_item->unlabeled_statement)
				{
					if (find_label_unlabeled_statement(block_item->unlabeled_statement, label))
					{
						return true;
					}
				}

				block_item = block_item->next;
			}
		}
		else if (p_unlabeled_statement->primary_block->selection_statement)
		{
			if (find_label_statement(p_unlabeled_statement->primary_block->selection_statement->secondary_block->statement, label))
			{
				return true;
			}
			if (p_unlabeled_statement->primary_block->selection_statement->else_secondary_block_opt)
			{
				if (find_label_statement(p_unlabeled_statement->primary_block->selection_statement->else_secondary_block_opt->statement, label))
				{
					return true;
				}
			}
		}
		else if (p_unlabeled_statement->primary_block->try_statement)
		{
			if (find_label_statement(p_unlabeled_statement->primary_block->try_statement->secondary_block->statement, label))
			{
				return true;
			}
			if (p_unlabeled_statement->primary_block->try_statement->catch_secondary_block_opt)
			{
				if (find_label_statement(p_unlabeled_statement->primary_block->try_statement->catch_secondary_block_opt->statement, label))
				{
					return true;
				}
			}
		}
		else if (p_unlabeled_statement->primary_block->iteration_statement)
		{
			if (find_label_statement(p_unlabeled_statement->primary_block->iteration_statement->secondary_block->statement, label))
			{
				return true;
			}
		}
	}
	return false;
}

bool find_label_statement(struct statement* statement, const char* label)
{
	if (statement->labeled_statement)
	{
		if (statement->labeled_statement &&
			statement->labeled_statement->label &&
			strcmp(statement->labeled_statement->label->name->lexeme, label) == 0)
		{
			/*achou*/
			return true;
		}
	}
	else if (statement->unlabeled_statement)
	{
		if (find_label_unlabeled_statement(statement->unlabeled_statement, label))
			return true;
	}
	return false;
}

static bool find_label_scope(struct defer_scope* deferblock, const char* label)
{
	if (deferblock->p_iteration_statement)
	{
		if (deferblock->p_iteration_statement->secondary_block)
		{
			if (find_label_statement(deferblock->p_iteration_statement->secondary_block->statement, label))
				return true;
		}
	}
	else if (deferblock->p_selection_statement2)
	{
		if (deferblock->p_selection_statement2->secondary_block)
		{
			if (find_label_statement(deferblock->p_selection_statement2->secondary_block->statement, label))
				return true;
		}

		if (deferblock->p_selection_statement2->else_secondary_block_opt)
		{
			if (find_label_statement(deferblock->p_selection_statement2->else_secondary_block_opt->statement, label))
				return true;
		}
	}
	else if (deferblock->p_try_statement)
	{
		if (deferblock->p_try_statement->secondary_block)
		{
			if (find_label_statement(deferblock->p_try_statement->secondary_block->statement, label))
				return true;
		}

		if (deferblock->p_try_statement->catch_secondary_block_opt)
		{
			if (find_label_statement(deferblock->p_try_statement->catch_secondary_block_opt->statement, label))
				return true;
		}
	}
	else if (deferblock->p_statement)
	{
		if (find_label_statement(deferblock->p_statement, label))
			return true;
	}
	return false;
}

void print_all_defer_until_label(struct defer_scope* deferblock, const char* label, struct osstream* ss)
{
	/*
	* Precisamos saber quantos escopos nós saimos até achar o label.
	* Para isso procuramos no escopo atual aonde aparede o goto.
	* Se o label não esta diretamente neste escopo ou dentro de algum escopo interno
	* Não nós imprimos os defers pois estamos saindo do escopo e vamos para o escopo
	* de cima. Assim vamos repetindo em cada saida de escopo imprimos o defer.
	*/
	struct defer_scope* p_defer = deferblock;

	while (p_defer != NULL)
	{
		if (!find_label_scope(p_defer, label))
		{
			print_block_defer(p_defer, ss, false);
		}
		else
		{
			break;
		}
		p_defer = p_defer->previous;
	}

}

void print_all_defer_until_iter(struct defer_scope* deferblock, struct osstream* ss)
{
	struct defer_scope* p_defer = deferblock;
	while (p_defer != NULL)
	{
		print_block_defer(p_defer, ss, false);
		if (p_defer->p_iteration_statement)
		{
			break;
		}
		p_defer = p_defer->previous;
	}
}

void print_all_defer_until_end(struct defer_scope* deferblock, struct osstream* ss)
{
	struct defer_scope* p_defer = deferblock;
	while (p_defer != NULL)
	{
		print_block_defer(p_defer, ss, false);
		p_defer = p_defer->previous;
	}
}

static void visit_secondary_block(struct visit_ctx* ctx, struct secondary_block* p_secondary_block)
{
	visit_statement(ctx, p_secondary_block->statement);
}
struct defer_scope* visit_ctx_push_tail_child(struct visit_ctx* ctx)
{
	struct defer_scope* owner p_defer = calloc(1, sizeof * p_defer);
	p_defer->previous = ctx->tail_block->lastchild;
	ctx->tail_block->lastchild = p_defer;

	return ctx->tail_block->lastchild;
}


struct defer_scope* visit_ctx_push_tail_block(struct visit_ctx* ctx)
{
	struct defer_scope* owner p_defer = calloc(1, sizeof * p_defer);
	p_defer->previous = ctx->tail_block;
	ctx->tail_block = p_defer;

	return ctx->tail_block;
}
static void visit_defer_statement(struct visit_ctx* ctx, struct defer_statement* p_defer_statement)
{
	if (!ctx->is_second_pass)
	{
		//adiciona como filho do ultimo bloco
		struct defer_scope* p_defer = visit_ctx_push_tail_child(ctx);
		p_defer->defer_statement = p_defer_statement;


		if (p_defer_statement->secondary_block)
		{
			visit_secondary_block(ctx, p_defer_statement->secondary_block);
		}
	}
	else //if (ctx->is_second_pass)
	{
		if (p_defer_statement->secondary_block)
			visit_secondary_block(ctx, p_defer_statement->secondary_block);
	}
}



void defer_scope_delete_one(struct defer_scope* owner p_block);

void visit_ctx_pop_tail_block(struct visit_ctx* ctx)
{
	if (ctx->tail_block)
	{
		struct defer_scope* owner previous = ctx->tail_block->previous;
		ctx->tail_block->previous = NULL;
		defer_scope_delete_one(ctx->tail_block);
		ctx->tail_block = previous;
	}
}

static void visit_try_statement(struct visit_ctx* ctx, struct try_statement* p_try_statement)
{
	if (!ctx->is_second_pass)
	{
		struct defer_scope* p_defer = visit_ctx_push_tail_block(ctx);
		p_defer->p_try_statement = p_try_statement;

		if (p_try_statement->secondary_block)
			visit_secondary_block(ctx, p_try_statement->secondary_block);


		struct osstream ss = { 0 };

		print_block_defer(p_defer, &ss, true);
		struct tokenizer_ctx tctx = { 0 };
		struct token_list l = tokenizer(&tctx, ss.c_str, NULL, 0, TK_FLAG_FINAL);
		token_list_insert_after(&ctx->ast.token_list, p_try_statement->secondary_block->last_token->prev, &l);


		visit_ctx_pop_tail_block(ctx);


		free(p_try_statement->first_token->lexeme);
		p_try_statement->first_token->lexeme = strdup("if (1) /*try*/");


		char buffer[50] = { 0 };
		if (p_try_statement->catch_secondary_block_opt)
		{

			snprintf(buffer, sizeof buffer, "else _catch_label_%d:", p_try_statement->try_catch_block_index);

			free(p_try_statement->catch_token_opt->lexeme);
			p_try_statement->catch_token_opt->lexeme = strdup(buffer);

			visit_secondary_block(ctx, p_try_statement->catch_secondary_block_opt);
		}
		else
		{
			snprintf(buffer, sizeof buffer, "} else {_catch_label_%d:;}", p_try_statement->try_catch_block_index);
			free(p_try_statement->last_token->lexeme);
			p_try_statement->last_token->lexeme = strdup(buffer);
		}

		ss_close(&ss);
		token_list_destroy(&l);
	}
}

static void visit_selection_statement(struct visit_ctx* ctx, struct selection_statement* p_selection_statement)
{
	convert_if_statement(ctx, p_selection_statement);

	//PUSH
	struct defer_scope* p_defer = visit_ctx_push_tail_block(ctx);
	p_defer->p_selection_statement2 = p_selection_statement;

	if (p_selection_statement->secondary_block)
		visit_secondary_block(ctx, p_selection_statement->secondary_block);

	struct osstream ss = { 0 };
	print_block_defer(p_defer, &ss, true);

	if (ss.size > 0)
	{
		struct tokenizer_ctx tctx = { 0 };
		struct token_list l = tokenizer(&tctx, ss.c_str, NULL, 0, TK_FLAG_FINAL);
		token_list_insert_after(&ctx->ast.token_list, p_selection_statement->secondary_block->last_token->prev, &l);
		token_list_destroy(&l);
	}

	visit_ctx_pop_tail_block(ctx);

	if (p_selection_statement->else_secondary_block_opt)
		visit_secondary_block(ctx, p_selection_statement->else_secondary_block_opt);

	ss_close(&ss);
}

static void visit_compound_statement(struct visit_ctx* ctx, struct compound_statement* p_compound_statement);



char* remove_char(char* input, char ch)
{
	if (input == NULL)
		return NULL;
	char* p_write = input;
	const char* p = input;
	while (*p)
	{
		if (p[0] == ch)
		{
			p++;
		}
		else
		{
			*p_write = *p;
			p++;
			p_write++;
		}
	}
	*p_write = 0;
	return input;
}

static void visit_initializer_list(struct visit_ctx* ctx, struct initializer_list* p_initializer_list);

static void visit_bracket_initializer_list(struct visit_ctx* ctx, struct braced_initializer* p_bracket_initializer_list)
{
	if (p_bracket_initializer_list->initializer_list == NULL)
	{
		if (ctx->target < LANGUAGE_C2X)
		{
			assert(p_bracket_initializer_list->first_token->type == '{');

			const int level = p_bracket_initializer_list->first_token->level;
			//Criar token 0
			struct tokenizer_ctx tctx = { 0 };
			struct token_list list2 = tokenizer(&tctx, "0", NULL, level, TK_FLAG_FINAL);

			//inserir na frente
			token_list_insert_after(&ctx->ast.token_list, p_bracket_initializer_list->first_token, &list2);
			token_list_destroy(&list2);
		}
	}
	else
	{
		visit_initializer_list(ctx, p_bracket_initializer_list->initializer_list);
	}
}

static void visit_designation(struct visit_ctx* ctx, struct designation* p_designation)
{
}

static void visit_initializer(struct visit_ctx* ctx, struct initializer* p_initializer)
{
	if (p_initializer->p_attribute_specifier_sequence_opt)
	{
		visit_attribute_specifier_sequence(ctx, p_initializer->p_attribute_specifier_sequence_opt);
	}

	if (p_initializer->designation)
	{
		visit_designation(ctx, p_initializer->designation);
	}

	if (p_initializer->assignment_expression)
	{
		visit_expression(ctx, p_initializer->assignment_expression);
	}
	else if (p_initializer->braced_initializer)
	{
		visit_bracket_initializer_list(ctx, p_initializer->braced_initializer);
	}
}

static void visit_initializer_list(struct visit_ctx* ctx, struct initializer_list* p_initializer_list)
{
	struct initializer* p_initializer = p_initializer_list->head;
	while (p_initializer)
	{
		visit_initializer(ctx, p_initializer);
		p_initializer = p_initializer->next;
	}
}

static void visit_type_qualifier(struct visit_ctx* ctx, struct type_qualifier* p_type_qualifier)
{
	if (p_type_qualifier->token)
	{
		if (ctx->target < LANGUAGE_C99 && p_type_qualifier->token->type == TK_KEYWORD_RESTRICT)
		{
			free(p_type_qualifier->token->lexeme);
			p_type_qualifier->token->lexeme = strdup("/*restrict*/");
		}

		if (p_type_qualifier->token->type == TK_KEYWORD__OUT ||
			p_type_qualifier->token->type == TK_KEYWORD__OWNER ||
			p_type_qualifier->token->type == TK_KEYWORD__OBJ_OWNER ||
			p_type_qualifier->token->type == TK_KEYWORD__VIEW)
		{
			char temp[100] = { 0 };
			snprintf(temp, sizeof temp, "/*%s*/", p_type_qualifier->token->lexeme);
			free(p_type_qualifier->token->lexeme);
			p_type_qualifier->token->lexeme = strdup(temp);
		}
	}
}

static void visit_specifier_qualifier(struct visit_ctx* ctx, struct type_specifier_qualifier* p_specifier_qualifier)
{
	if (p_specifier_qualifier->type_specifier)
		visit_type_specifier(ctx, p_specifier_qualifier->type_specifier);

	if (p_specifier_qualifier->type_qualifier)
		visit_type_qualifier(ctx, p_specifier_qualifier->type_qualifier);
}

static void visit_specifier_qualifier_list(struct visit_ctx* ctx, struct specifier_qualifier_list* p_specifier_qualifier_list_opt,
	struct type* p_type)
{

	//(typeof(int[2])*)
	// 
	//TODO se tiver typeof em qualquer parte tem que imprimir todo  tipo
	// tem que refazer
	if (p_specifier_qualifier_list_opt->type_specifier_flags & TYPE_SPECIFIER_TYPEOF)
	{
		const int level = p_specifier_qualifier_list_opt->first_token->level;

		token_range_add_flag(p_specifier_qualifier_list_opt->first_token,
			p_specifier_qualifier_list_opt->last_token, TK_FLAG_HIDE);

		struct osstream ss = { 0 };
		print_type(&ss, type_get_specifer_part(p_type));


		struct tokenizer_ctx tctx = { 0 };
		struct token_list l2 = tokenizer(&tctx, ss.c_str, NULL, level, TK_FLAG_FINAL);
		token_list_insert_after(&ctx->ast.token_list, p_specifier_qualifier_list_opt->last_token, &l2);

		ss_close(&ss);
		token_list_destroy(&l2);
	}


	if (p_specifier_qualifier_list_opt == NULL)
		return;

	if (p_specifier_qualifier_list_opt->struct_or_union_specifier)
	{
		visit_struct_or_union_specifier(ctx, p_specifier_qualifier_list_opt->struct_or_union_specifier);
	}
	else if (p_specifier_qualifier_list_opt->enum_specifier)
	{
		visit_enum_specifier(ctx, p_specifier_qualifier_list_opt->enum_specifier);
	}
	else if (p_specifier_qualifier_list_opt->typedef_declarator)
	{
		//typedef name
	}
	//else if (p_specifier_qualifier_list->p_typeof_expression_opt)
	//{
	  //  visit_expression(ctx, p_specifier_qualifier_list->p_typeof_expression_opt);
	//}
	else
	{
		struct type_specifier_qualifier* p_specifier_qualifier = p_specifier_qualifier_list_opt->head;
		while (p_specifier_qualifier)
		{
			visit_specifier_qualifier(ctx, p_specifier_qualifier);
			p_specifier_qualifier = p_specifier_qualifier->next;
		}
	}
}
static void visit_declarator(struct visit_ctx* ctx, struct declarator* p_declarator);
static void visit_type_name(struct visit_ctx* ctx, struct type_name* p_type_name)
{

	visit_specifier_qualifier_list(ctx, p_type_name->specifier_qualifier_list, &p_type_name->type);
	visit_declarator(ctx, p_type_name->declarator);


	/*
	* Vamos esconder tudo e gerar um novo
	*  Exemplo
	*  (const typeof(int (*)())) -> *  ( int (*const )() )
	*/
}



static void visit_argument_expression_list(struct visit_ctx* ctx, struct argument_expression_list* p_argument_expression_list)
{
	struct argument_expression* p_argument_expression =
		p_argument_expression_list->head;
	while (p_argument_expression)
	{
		visit_expression(ctx, p_argument_expression->expression);
		p_argument_expression = p_argument_expression->next;
	}
}

static void visit_generic_selection(struct visit_ctx* ctx, struct generic_selection* p_generic_selection)
{
	if (p_generic_selection->expression)
	{
		visit_expression(ctx, p_generic_selection->expression);
	}
	else if (p_generic_selection->type_name)
	{
		visit_type_name(ctx, p_generic_selection->type_name);
	}

	struct generic_association* p = p_generic_selection->generic_assoc_list.head;
	while (p)
	{
		visit_type_name(ctx, p->p_type_name);
		visit_expression(ctx, p->expression);
		p = p->next;
	}

	if (ctx->target < LANGUAGE_C11)
	{
		//TODO lambada inside teh expression
		/*let's hide everything first*/
		token_range_add_flag(p_generic_selection->first_token, p_generic_selection->last_token, TK_FLAG_HIDE);

		if (p_generic_selection->p_view_selected_expression)
		{
			/*then let's show up the selected expression*/
			token_range_remove_flag(p_generic_selection->p_view_selected_expression->first_token,
				p_generic_selection->p_view_selected_expression->last_token,
				TK_FLAG_HIDE);
		}
	}

}


static void visit_expression(struct visit_ctx* ctx, struct expression* p_expression)
{
	switch (p_expression->expression_type)
	{
	case PRIMARY_EXPRESSION__FUNC__:
		break;
	case PRIMARY_IDENTIFIER:
		break;
	case PRIMARY_EXPRESSION_ENUMERATOR:
		if (ctx->target < LANGUAGE_C2X)
		{
			struct type t = type_get_enum_type(&p_expression->type);
			if (t.type_specifier_flags != TYPE_SPECIFIER_INT)
			{
				struct osstream ss0 = { 0 };
				print_type(&ss0, &t);
				struct osstream ss = { 0 };
				ss_fprintf(&ss, "((%s)%s)", ss0.c_str, p_expression->first_token->lexeme);

				free(p_expression->first_token->lexeme);
				p_expression->first_token->lexeme = ss.c_str;
				ss.c_str = NULL; /*MOVED*/
				ss_close(&ss);
				ss_close(&ss0);
			}
			type_destroy(&t);
		}
		break;
	case PRIMARY_EXPRESSION_DECLARATOR:

		if (ctx->target < LANGUAGE_C2X)
		{
			if (constant_value_is_valid(&p_expression->constant_value))
			{
				free((void* owner)p_expression->type.name_opt);
				p_expression->type.name_opt = NULL;

				struct osstream ss1 = { 0 };
				struct osstream ss = { 0 };
				print_type(&ss, &p_expression->type);
				/*
				  this is the way we handle constexpr, replacing the declarator
				  for it's number and changing the expression type
				  we are not handling &a at this moment
				*/
				char buffer[40] = { 0 };
				constant_value_to_string(&p_expression->constant_value, buffer, sizeof buffer);
				free(p_expression->first_token->lexeme);

				ss_fprintf(&ss1, "((%s)%s)", ss.c_str, buffer);

				p_expression->first_token->lexeme = ss1.c_str;
				ss1.c_str = NULL;// MOVED
				p_expression->expression_type = PRIMARY_EXPRESSION_NUMBER;


				ss_close(&ss);
				ss_close(&ss1);
			}
		}

		break;
	case PRIMARY_EXPRESSION_STRING_LITERAL:
		break;
	case PRIMARY_EXPRESSION_CHAR_LITERAL:
		break;
	case PRIMARY_EXPRESSION_NUMBER:
		break;

	case PRIMARY_EXPRESSION_PREDEFINED_CONSTANT:
		if (p_expression->first_token &&
			p_expression->first_token->type == TK_KEYWORD_NULLPTR)
		{
			if (ctx->target < LANGUAGE_C2X)
			{
				free(p_expression->first_token->lexeme);
				p_expression->first_token->lexeme = strdup("((void*)0)");
			}
		}
		else if (p_expression->first_token &&
			p_expression->first_token->type == TK_KEYWORD_TRUE)
		{
			if (ctx->target < LANGUAGE_C99)
			{
				free(p_expression->first_token->lexeme);
				p_expression->first_token->lexeme = strdup("1");
			}
			else if (ctx->target < LANGUAGE_C2X)
			{
				free(p_expression->first_token->lexeme);
				p_expression->first_token->lexeme = strdup("((_Bool)1)");
			}
		}
		else if (p_expression->first_token &&
			p_expression->first_token->type == TK_KEYWORD_FALSE)
		{
			if (ctx->target < LANGUAGE_C99)
			{
				free(p_expression->first_token->lexeme);
				p_expression->first_token->lexeme = strdup("0");
			}
			else if (ctx->target < LANGUAGE_C2X)
			{
				free(p_expression->first_token->lexeme);
				p_expression->first_token->lexeme = strdup("((_Bool)0)");
			}
		}
		break;

	case PRIMARY_EXPRESSION_PARENTESIS:
		visit_expression(ctx, p_expression->right);
		break;

	case PRIMARY_EXPRESSION_GENERIC:
		visit_generic_selection(ctx, p_expression->generic_selection);
		break;

	case POSTFIX_DOT:
		break;
	case POSTFIX_ARROW:
		break;
	case POSTFIX_INCREMENT:
		break;
	case POSTFIX_DECREMENT:
		break;
	case POSTFIX_ARRAY:
		//visit_expression(ctx, p_expression->left);
		break;
	case POSTFIX_FUNCTION_CALL:
		visit_expression(ctx, p_expression->left);
		visit_argument_expression_list(ctx, &p_expression->argument_expression_list);
		break;
	case POSTFIX_EXPRESSION_FUNCTION_LITERAL:
	{
		ctx->has_lambda = true;
		ctx->is_inside_lambda = true;
		visit_type_name(ctx, p_expression->type_name);
		visit_compound_statement(ctx, p_expression->compound_statement);
		ctx->is_inside_lambda = false;

		if (ctx->is_second_pass)
		{
			/*no segundo passo nós copiamos a funcao*/
			char name[100] = { 0 };
			snprintf(name, sizeof name, " _lit_func_%d", ctx->lambdas_index);
			ctx->lambdas_index++;

			struct osstream ss = { 0 };



			bool is_first = true;
			print_type_qualifier_flags(&ss, &is_first, p_expression->type_name->declarator->type.type_qualifier_flags);
			print_type_specifier_flags(&ss, &is_first, p_expression->type_name->declarator->type.type_specifier_flags);


			free((void* owner)p_expression->type_name->declarator->type.name_opt);
			p_expression->type_name->declarator->type.name_opt = strdup(name);

			struct osstream ss0 = { 0 };

			print_type(&ss0, &p_expression->type_name->declarator->type);
			ss_fprintf(&ss, "static %s", ss0.c_str);

			ss_close(&ss0);

			struct tokenizer_ctx tctx = { 0 };
			struct token_list l1 = tokenizer(&tctx, ss.c_str, NULL, 0, TK_FLAG_FINAL);

			token_list_append_list(&ctx->insert_before_declaration, &l1);
			ss_close(&ss);
			token_list_destroy(&l1);

			for (struct token* current = p_expression->compound_statement->first_token;
				current != p_expression->compound_statement->last_token->next;
				current = current->next)
			{
				token_list_clone_and_add(&ctx->insert_before_declaration, current);
			}

			token_range_add_flag(p_expression->first_token, p_expression->last_token, TK_FLAG_HIDE);


			struct token_list l3 = tokenizer(&tctx, "\n\n", NULL, 0, TK_FLAG_NONE);
			token_list_append_list(&ctx->insert_before_declaration, &l3);
			token_list_destroy(&l3);

			struct token_list l2 = tokenizer(&tctx, name, NULL, 0, TK_FLAG_FINAL);
			token_list_insert_after(&ctx->ast.token_list, p_expression->last_token, &l2);
			token_list_destroy(&l2);
		}
	}
	break;

	case POSTFIX_EXPRESSION_COMPOUND_LITERAL:

		if (p_expression->type_name)
		{
			visit_type_name(ctx, p_expression->type_name);
		}

		visit_bracket_initializer_list(ctx, p_expression->braced_initializer);

		assert(p_expression->left == NULL);
		assert(p_expression->right == NULL);

		break;

	case UNARY_EXPRESSION_ALIGNOF:

		if (ctx->target < LANGUAGE_C11)
		{
			const int level = p_expression->first_token->level;
			token_range_add_flag(p_expression->first_token, p_expression->last_token, TK_FLAG_HIDE);
			char buffer[30] = { 0 };
			snprintf(buffer, sizeof buffer, "%lld", constant_value_to_ll(&p_expression->constant_value));
			struct tokenizer_ctx tctx = { 0 };
			struct token_list l3 = tokenizer(&tctx, buffer, NULL, level, TK_FLAG_FINAL);
			l3.head->flags = p_expression->last_token->flags;
			token_list_insert_after(&ctx->ast.token_list, p_expression->last_token, &l3);
			token_list_destroy(&l3);
		}

		if (p_expression->right)
		{
			visit_expression(ctx, p_expression->right);
		}

		if (p_expression->type_name)
		{
			/*sizeof*/
			visit_type_name(ctx, p_expression->type_name);
		}
		break;

	case UNARY_EXPRESSION_SIZEOF_EXPRESSION:
	case UNARY_EXPRESSION_SIZEOF_TYPE:
	case UNARY_EXPRESSION_INCREMENT:
	case UNARY_EXPRESSION_DECREMENT:

	case UNARY_EXPRESSION_NOT:
	case UNARY_EXPRESSION_BITNOT:
	case UNARY_EXPRESSION_NEG:
	case UNARY_EXPRESSION_PLUS:
	case UNARY_EXPRESSION_CONTENT:
	case UNARY_EXPRESSION_ADDRESSOF:
		if (p_expression->right)
		{
			visit_expression(ctx, p_expression->right);
		}

		if (p_expression->type_name)
		{
			/*sizeof*/
			visit_type_name(ctx, p_expression->type_name);
		}

		break;




	case ASSIGNMENT_EXPRESSION:
	case CAST_EXPRESSION:
	case MULTIPLICATIVE_EXPRESSION_MULT:
	case MULTIPLICATIVE_EXPRESSION_DIV:
	case MULTIPLICATIVE_EXPRESSION_MOD:
	case ADDITIVE_EXPRESSION_PLUS:
	case ADDITIVE_EXPRESSION_MINUS:
	case SHIFT_EXPRESSION_RIGHT:
	case SHIFT_EXPRESSION_LEFT:
	case RELATIONAL_EXPRESSION_BIGGER_THAN:
	case RELATIONAL_EXPRESSION_LESS_THAN:
	case EQUALITY_EXPRESSION_EQUAL:
	case EQUALITY_EXPRESSION_NOT_EQUAL:
	case AND_EXPRESSION:
	case EXCLUSIVE_OR_EXPRESSION:
	case INCLUSIVE_OR_EXPRESSION:
	case INCLUSIVE_AND_EXPRESSION:
	case LOGICAL_OR_EXPRESSION:
	case RELATIONAL_EXPRESSION_LESS_OR_EQUAL_THAN:
	case RELATIONAL_EXPRESSION_BIGGER_OR_EQUAL_THAN:

		if (p_expression->left)
		{
			visit_expression(ctx, p_expression->left);
		}
		if (p_expression->right)
		{
			visit_expression(ctx, p_expression->right);
		}
		if (p_expression->type_name)
		{
			visit_type_name(ctx, p_expression->type_name);
		}


		break;

	case UNARY_EXPRESSION_TRAITS:
	{
		if (ctx->target < LANGUAGE_CXX)
		{
			struct tokenizer_ctx tctx = { 0 };
			struct token_list l2 = { 0 };

			if (constant_value_to_bool(&p_expression->constant_value))
				l2 = tokenizer(&tctx, "1", NULL, 0, TK_FLAG_FINAL);
			else
				l2 = tokenizer(&tctx, "0", NULL, 0, TK_FLAG_FINAL);


			token_list_insert_after(&ctx->ast.token_list,
				p_expression->last_token,
				&l2);

			token_range_add_flag(p_expression->first_token,
				p_expression->last_token,
				TK_FLAG_HIDE);

			token_list_destroy(&l2);
		}
	}
	break;

	case UNARY_EXPRESSION_IS_SAME:
		break;

	case UNARY_DECLARATOR_ATTRIBUTE_EXPR:
		break;

	case CONDITIONAL_EXPRESSION:
		if (p_expression->condition_expr)
		{
			visit_expression(ctx, p_expression->condition_expr);
		}

		if (p_expression->left)
		{
			visit_expression(ctx, p_expression->left);
		}
		if (p_expression->right)
		{
			visit_expression(ctx, p_expression->right);
		}

		break;

	default:
		break;
	}
}

static void visit_expression_statement(struct visit_ctx* ctx, struct expression_statement* p_expression_statement)
{
	if (p_expression_statement->expression_opt)
		visit_expression(ctx, p_expression_statement->expression_opt);
}

static void visit_block_item_list(struct visit_ctx* ctx, struct block_item_list* p_block_item_list);

static void visit_compound_statement(struct visit_ctx* ctx, struct compound_statement* p_compound_statement)
{
	visit_block_item_list(ctx, &p_compound_statement->block_item_list);
}

//
static void visit_iteration_statement(struct visit_ctx* ctx, struct iteration_statement* p_iteration_statement)
{

	if (p_iteration_statement->expression1)
	{
		visit_expression(ctx, p_iteration_statement->expression1);
	}

	if (p_iteration_statement->expression2)
	{
		visit_expression(ctx, p_iteration_statement->expression2);
	}


	if (p_iteration_statement->secondary_block)
	{
		struct defer_scope* p_defer = visit_ctx_push_tail_block(ctx);
		p_defer->p_iteration_statement = p_iteration_statement;

		visit_secondary_block(ctx, p_iteration_statement->secondary_block);

		struct osstream ss = { 0 };
		//defer_print(defer, &ss, ctx->bHasThrowWithVariable, ctx->bHasBreakWithVariable, ctx->bHasReturnWithVariable);
		print_block_defer(p_defer, &ss, true);

		struct tokenizer_ctx tctx = { 0 };
		struct token_list l = tokenizer(&tctx, ss.c_str, NULL, 0, TK_FLAG_FINAL);
		token_list_insert_after(&ctx->ast.token_list, p_iteration_statement->secondary_block->last_token->prev, &l);


		visit_ctx_pop_tail_block(ctx);


		ss_close(&ss);
		token_list_destroy(&l);
	}
}



static void visit_jump_statement(struct visit_ctx* ctx, struct jump_statement* p_jump_statement)
{

	if (p_jump_statement->first_token->type == TK_KEYWORD_THROW)
	{
		struct osstream ss0 = { 0 };
		print_all_defer_until_try(ctx->tail_block, &ss0);

		if (ss0.size > 0)
		{
			struct osstream ss = { 0 };
			ss_fprintf(&ss, "{ %s ", ss0.c_str);
			ss_fprintf(&ss, "goto _catch_label_%d;", p_jump_statement->try_catch_block_index);
			ss_fprintf(&ss, "}");

			free(p_jump_statement->first_token->lexeme);
			p_jump_statement->first_token->lexeme = ss.c_str;


			p_jump_statement->last_token->flags |= TK_FLAG_HIDE;

		}
		else
		{
			struct osstream ss = { 0 };
			ss_fprintf(&ss, "goto _catch_label_%d", p_jump_statement->try_catch_block_index);
			free(p_jump_statement->first_token->lexeme);
			p_jump_statement->first_token->lexeme = ss.c_str; /*MOVED*/
		}

		ss_close(&ss0);
	}
	else if (p_jump_statement->first_token->type == TK_KEYWORD_RETURN)
	{
		const bool constant_expression =
			p_jump_statement->expression_opt == NULL ||
			constant_value_is_valid(&p_jump_statement->expression_opt->constant_value);

		if (constant_expression)
		{
			struct osstream ss0 = { 0 };
			print_all_defer_until_end(ctx->tail_block, &ss0);

			if (ss0.size > 0)
			{
				struct osstream ss = { 0 };
				ss_fprintf(&ss, "{ %s ", ss0.c_str);
				ss_fprintf(&ss, "return");
				free(p_jump_statement->first_token->lexeme);

				p_jump_statement->first_token->lexeme = ss.c_str;
				ss.c_str = NULL; /*MOVED*/

				free(p_jump_statement->last_token->lexeme);
				p_jump_statement->last_token->lexeme = strdup(";}");
				ss_close(&ss);
			}
			ss_close(&ss0);
		}
		else
		{
			//defer must run after return
			struct osstream defer_str = { 0 };
			print_all_defer_until_end(ctx->tail_block, &defer_str);

			if (defer_str.size > 0)
			{
				struct type t =
					type_dup(&p_jump_statement->expression_opt->type);
				type_add_const(&t);
				type_remove_names(&t);
				struct osstream return_type_str = { 0 };
				print_type(&return_type_str, &t);
				free(p_jump_statement->first_token->lexeme);
				
				struct osstream sst = { 0 };
				ss_fprintf(&sst, "{ ");
				ss_fprintf(&sst, " %s _tmp = ", return_type_str.c_str);
				
				ss_close(&return_type_str);

				p_jump_statement->first_token->lexeme = sst.c_str;
				sst.c_str = NULL; //moved
				struct osstream ss = { 0 };
				ss_fprintf(&ss, "; %s return _tmp;}", defer_str.c_str);
				free(p_jump_statement->last_token->lexeme);
				p_jump_statement->last_token->lexeme = ss.c_str;
				ss.c_str = NULL; /*MOVED*/
				ss_close(&ss);

				type_destroy(&t);
			}
			ss_close(&defer_str);
		}
	}
	else if (p_jump_statement->first_token->type == TK_KEYWORD_BREAK ||
		p_jump_statement->first_token->type == TK_KEYWORD_CONTINUE)
	{
		struct osstream ss0 = { 0 };

		print_all_defer_until_iter(ctx->tail_block, &ss0);
		if (ss0.size > 0)
		{
			struct osstream ss = { 0 };
			ss_fprintf(&ss, "{ %s ", ss0.c_str);
			ss_fprintf(&ss, "break;");
			ss_fprintf(&ss, "}");
			free(p_jump_statement->first_token->lexeme);
			p_jump_statement->first_token->lexeme = ss.c_str;
			ss.c_str = NULL;

			p_jump_statement->last_token->flags |= TK_FLAG_HIDE;
			ss_close(&ss);
		}

		ss_close(&ss0);
	}
	else if (p_jump_statement->first_token->type == TK_KEYWORD_GOTO)
	{
		struct osstream ss0 = { 0 };
		print_all_defer_until_label(ctx->tail_block, p_jump_statement->label->lexeme, &ss0);

		if (ss0.size > 0)
		{
			struct osstream ss = { 0 };
			ss_fprintf(&ss, "{ %s ", ss0.c_str);
			ss_fprintf(&ss, "goto");
			free(p_jump_statement->first_token->lexeme);
			p_jump_statement->first_token->lexeme = ss.c_str;
			ss.c_str = NULL; /*MOVED*/
			free(p_jump_statement->last_token->lexeme);
			p_jump_statement->last_token->lexeme = strdup(";}");
			ss_close(&ss);
		}

		ss_close(&ss0);
	}
	else
	{
		assert(false);
	}
}


static void visit_labeled_statement(struct visit_ctx* ctx, struct labeled_statement* p_labeled_statement)
{
	//p_labeled_statement->label

	if (p_labeled_statement->statement)
	{
		visit_statement(ctx, p_labeled_statement->statement);
	}
}

static void visit_primary_block(struct visit_ctx* ctx, struct primary_block* p_primary_block)
{



	if (p_primary_block->defer_statement)
	{
		visit_defer_statement(ctx, p_primary_block->defer_statement);
	}
	else
	{
		if (p_primary_block->compound_statement)
		{
			visit_compound_statement(ctx, p_primary_block->compound_statement);
		}
		else if (p_primary_block->iteration_statement)
		{
			visit_iteration_statement(ctx, p_primary_block->iteration_statement);
		}
		else if (p_primary_block->selection_statement)
		{
			visit_selection_statement(ctx, p_primary_block->selection_statement);
		}
		else if (p_primary_block->try_statement)
		{
			visit_try_statement(ctx, p_primary_block->try_statement);
		}
	}

}

static void visit_unlabeled_statement(struct visit_ctx* ctx, struct unlabeled_statement* p_unlabeled_statement)
{
	if (p_unlabeled_statement->primary_block)
	{
		visit_primary_block(ctx, p_unlabeled_statement->primary_block);
	}
	else if (p_unlabeled_statement->expression_statement)
	{
		visit_expression_statement(ctx, p_unlabeled_statement->expression_statement);
	}
	else if (p_unlabeled_statement->jump_statement)
	{
		visit_jump_statement(ctx, p_unlabeled_statement->jump_statement);
	}
	else
	{
		assert(false);
	}
}

static void visit_declaration(struct visit_ctx* ctx, struct declaration* p_declaration);

static void visit_statement(struct visit_ctx* ctx, struct statement* p_statement)
{
	if (p_statement->labeled_statement)
	{
		visit_labeled_statement(ctx, p_statement->labeled_statement);
	}
	else if (p_statement->unlabeled_statement)
	{
		visit_unlabeled_statement(ctx, p_statement->unlabeled_statement);
	}
}

static void visit_label(struct visit_ctx* ctx, struct label* p_label)
{
	//p_label->name
}
static void visit_block_item(struct visit_ctx* ctx, struct block_item* p_block_item)
{
	if (p_block_item->declaration)
	{
		visit_declaration(ctx, p_block_item->declaration);
	}
	else if (p_block_item->unlabeled_statement)
	{
		visit_unlabeled_statement(ctx, p_block_item->unlabeled_statement);
	}
	else if (p_block_item->label)
	{
		visit_label(ctx, p_block_item->label);
	}
	if (ctx->insert_before_block_item.head != NULL)
	{
		token_list_insert_after(&ctx->ast.token_list, p_block_item->first_token->prev, &ctx->insert_before_block_item);
	}
}

static void visit_block_item_list(struct visit_ctx* ctx, struct block_item_list* p_block_item_list)
{
	struct block_item* p_block_item = p_block_item_list->head;
	while (p_block_item)
	{
		visit_block_item(ctx, p_block_item);
		p_block_item = p_block_item->next;
	}
}

static void visit_static_assert_declaration(struct visit_ctx* ctx, struct static_assert_declaration* p_static_assert_declaration)
{
	visit_expression(ctx, p_static_assert_declaration->constant_expression);

	if (ctx->target < LANGUAGE_C11)
	{
		/*let's hide everything first*/
		token_range_add_flag(p_static_assert_declaration->first_token,
			p_static_assert_declaration->last_token,
			TK_FLAG_HIDE);
	}
	else if (ctx->target == LANGUAGE_C11)
	{
		if (p_static_assert_declaration->string_literal_opt == NULL)
		{
			struct token* rp = previous_parser_token(p_static_assert_declaration->last_token);
			rp = previous_parser_token(rp);

			struct tokenizer_ctx tctx = { 0 };
			struct token_list list1 = tokenizer(&tctx, ", \"error\"", "", 0, TK_FLAG_FINAL);
			token_list_insert_after(&ctx->ast.token_list, rp, &list1);
			token_list_destroy(&list1);
		}
		if (strcmp(p_static_assert_declaration->first_token->lexeme, "static_assert") == 0)
		{
			/*C23 has static_assert but C11 _Static_assert*/
			free(p_static_assert_declaration->first_token->lexeme);
			p_static_assert_declaration->first_token->lexeme = strdup("_Static_assert");
		}
	}
	else
	{
		free(p_static_assert_declaration->first_token->lexeme);
		p_static_assert_declaration->first_token->lexeme = strdup("static_assert");
	}
}

static void visit_declaration_specifiers(struct visit_ctx* ctx,
	struct declaration_specifiers* p_declaration_specifiers,
	struct type* p_type);


static void visit_direct_declarator(struct visit_ctx* ctx, struct direct_declarator* p_direct_declarator)
{
	if (p_direct_declarator->function_declarator)
	{
		struct parameter_declaration* parameter = NULL;

		if (p_direct_declarator->function_declarator->parameter_type_list_opt)
		{
			parameter = p_direct_declarator->function_declarator->parameter_type_list_opt->parameter_list->head;
		}

		while (parameter)
		{
			if (parameter->implicit_token)
			{
				free(parameter->implicit_token->lexeme);
				parameter->implicit_token->lexeme = strdup("/*_Implicit*/");
			}

			if (parameter->attribute_specifier_sequence_opt)
			{
				visit_attribute_specifier_sequence(ctx, parameter->attribute_specifier_sequence_opt);
			}

			visit_declaration_specifiers(ctx, parameter->declaration_specifiers, &parameter->declarator->type);
			visit_declarator(ctx, parameter->declarator);
			parameter = parameter->next;
		}

	}
	else if (p_direct_declarator->array_declarator)
	{
		if (p_direct_declarator->array_declarator->assignment_expression)
		{
			visit_expression(ctx, p_direct_declarator->array_declarator->assignment_expression);
		}

		if (ctx->target < LANGUAGE_C99)
		{
			/*static and type qualifiers in parameter array declarators where added in C99*/
			if (p_direct_declarator->array_declarator->static_token_opt)
			{
				p_direct_declarator->array_declarator->static_token_opt->flags |= TK_FLAG_HIDE;

				if (p_direct_declarator->array_declarator->type_qualifier_list_opt)
				{
					struct type_qualifier* p_type_qualifier =
						p_direct_declarator->array_declarator->type_qualifier_list_opt->head;

					while (p_type_qualifier)
					{
						p_type_qualifier->token->flags |= TK_FLAG_HIDE;
						p_type_qualifier = p_type_qualifier->next;
					}
				}
			}
		}
	}
}

static void visit_declarator(struct visit_ctx* ctx, struct declarator* p_declarator)
{
	bool need_transformation = false;

	if (p_declarator->pointer)
	{
		struct pointer* p = p_declarator->pointer;
		while (p)
		{
			if (p->type_qualifier_list_opt)
			{
				struct type_qualifier* current = p->type_qualifier_list_opt->head;
				while (current)
				{
					visit_type_qualifier(ctx, current);
					current = current->next;
				}
			}
			p = p->pointer;
		}
	}

	if (ctx->target < LANGUAGE_C2X)
	{
		if (p_declarator->declaration_specifiers)
		{
			if (p_declarator->declaration_specifiers->storage_class_specifier_flags & STORAGE_SPECIFIER_AUTO)
			{
				need_transformation = true;
			}
			if (p_declarator->declaration_specifiers->type_specifier_flags & TYPE_SPECIFIER_TYPEOF)
			{
				need_transformation = true;
			}
		}

		if (p_declarator->specifier_qualifier_list &&
			p_declarator->specifier_qualifier_list->type_specifier_flags & TYPE_SPECIFIER_TYPEOF)
		{
			need_transformation = true;
		}
	}


	//we may have a diference type from the current syntax 
	if (need_transformation)
	{

		struct osstream ss = { 0 };

		/*types like nullptr are converted to other types like void* */
		struct type new_type = type_convert_to(&p_declarator->type, ctx->target);

		type_remove_names(&new_type);
		if (p_declarator->name)
		{
			free((void* owner)new_type.name_opt);
			new_type.name_opt = strdup(p_declarator->name->lexeme);
		}

		print_type_declarator(&ss, &new_type);

		if (ss.c_str != NULL)
		{
			const int level = p_declarator->first_token ? p_declarator->first_token->level : 0;
			struct tokenizer_ctx tctx = { 0 };
			struct token_list l2 = tokenizer(&tctx, ss.c_str, NULL, level, TK_FLAG_FINAL);


			/*let's hide the old declarator*/
			if (p_declarator->first_token != NULL &&
				p_declarator->first_token != p_declarator->last_token)
			{
				l2.head->flags = p_declarator->first_token->flags;
				token_list_insert_after(&ctx->ast.token_list, p_declarator->last_token, &l2);
				token_range_add_flag(p_declarator->first_token, p_declarator->last_token, TK_FLAG_HIDE);
			}
			else
			{

				if (p_declarator->first_token == NULL)
				{
					l2.head->flags = p_declarator->last_token->flags;
					/*it is a empty declarator, so first_token is not part of declarator it only marks de position*/
					token_list_insert_after(&ctx->ast.token_list, p_declarator->last_token->prev, &l2);
				}
				else
				{
					l2.head->flags = p_declarator->first_token->flags;
					/*it is a empty declarator, so first_token is not part of declarator it only marks de position*/
					token_list_insert_after(&ctx->ast.token_list, p_declarator->last_token, &l2);
					token_range_add_flag(p_declarator->first_token, p_declarator->last_token, TK_FLAG_HIDE);
				}

			}
			token_list_destroy(&l2);
		}

		type_destroy(&new_type);
		ss_close(&ss);
	}


	if (p_declarator->direct_declarator)
	{
		visit_direct_declarator(ctx, p_declarator->direct_declarator);
	}
}

static void visit_init_declarator_list(struct visit_ctx* ctx, struct init_declarator_list* p_init_declarator_list)
{
	struct init_declarator* p_init_declarator = p_init_declarator_list->head;



	while (p_init_declarator)
	{
		if (p_init_declarator->p_declarator)
		{
			visit_declarator(ctx, p_init_declarator->p_declarator);
		}

		if (p_init_declarator->initializer)
		{
			if (p_init_declarator->initializer->assignment_expression)
			{
				visit_expression(ctx, p_init_declarator->initializer->assignment_expression);
			}
			else
			{
				assert(p_init_declarator->initializer->braced_initializer != NULL);
				if (p_init_declarator->initializer->braced_initializer)
				{
					visit_bracket_initializer_list(ctx,
						p_init_declarator->initializer->braced_initializer);
				}

			}
		}

		p_init_declarator = p_init_declarator->next;
	}
}



static void visit_member_declarator(struct visit_ctx* ctx, struct member_declarator* p_member_declarator)
{
	if (p_member_declarator->declarator)
	{
		visit_declarator(ctx, p_member_declarator->declarator);
	}
}

static void visit_member_declarator_list(struct visit_ctx* ctx, struct member_declarator_list* p_member_declarator_list)
{
	struct member_declarator* p_member_declarator = p_member_declarator_list->head;
	while (p_member_declarator)
	{
		visit_member_declarator(ctx, p_member_declarator);
		p_member_declarator = p_member_declarator->next;
	}
}
static void visit_member_declaration(struct visit_ctx* ctx, struct member_declaration* p_member_declaration)
{
	if (p_member_declaration->member_declarator_list_opt)
	{
		visit_specifier_qualifier_list(ctx,
			p_member_declaration->specifier_qualifier_list,
			&p_member_declaration->member_declarator_list_opt->head->declarator->type); /*se nao tem?*/
	}

	if (p_member_declaration->member_declarator_list_opt)
	{
		visit_member_declarator_list(ctx, p_member_declaration->member_declarator_list_opt);
	}
}

static void visit_member_declaration_list(struct visit_ctx* ctx, struct member_declaration_list* p_member_declaration_list)
{
	struct member_declaration* p_member_declaration =
		p_member_declaration_list->head;
	while (p_member_declaration)
	{
		visit_member_declaration(ctx, p_member_declaration);
		p_member_declaration = p_member_declaration->next;
	}
}

static void visit_attribute_specifier(struct visit_ctx* ctx, struct attribute_specifier* p_attribute_specifier)
{
	if (ctx->target < LANGUAGE_C2X)
	{
		token_range_add_flag(p_attribute_specifier->first_token, p_attribute_specifier->last_token, TK_FLAG_HIDE);
	}
}

static void visit_attribute_specifier_sequence(struct visit_ctx* ctx, struct attribute_specifier_sequence* p_visit_attribute_specifier_sequence)
{
	struct attribute_specifier* current = p_visit_attribute_specifier_sequence->head;
	while (current)
	{
		visit_attribute_specifier(ctx, current);
		current = current->next;
	}
}

static void visit_struct_or_union_specifier(struct visit_ctx* ctx, struct struct_or_union_specifier* p_struct_or_union_specifier)
{

	if (p_struct_or_union_specifier->attribute_specifier_sequence_opt)
		visit_attribute_specifier_sequence(ctx, p_struct_or_union_specifier->attribute_specifier_sequence_opt);

	struct struct_or_union_specifier* p_complete = get_complete_struct_or_union_specifier(p_struct_or_union_specifier);

	if (p_struct_or_union_specifier->show_anonymous_tag && !ctx->is_second_pass)
	{
		struct token* first = p_struct_or_union_specifier->first_token;

		const char* tag = p_struct_or_union_specifier->tag_name;
		char buffer[200] = { 0 };
		snprintf(buffer, sizeof buffer, " %s", tag);
		struct tokenizer_ctx tctx = { 0 };
		struct token_list l2 = tokenizer(&tctx, buffer, NULL, 0, TK_FLAG_FINAL);
		token_list_insert_after(&ctx->ast.token_list, first, &l2);
		token_list_destroy(&l2);
	}

	if (p_complete)
	{
		if (ctx->is_inside_lambda && !ctx->is_second_pass)
		{
			/*
			  Na primeira passada marcamos os tipos que são renomeados
			*/
			if (p_complete->scope_level >
				p_struct_or_union_specifier->scope_level &&
				p_complete->visit_moved == 0)
			{
				char newtag[212] = { 0 };
				snprintf(newtag, sizeof newtag, "_%s%d", p_struct_or_union_specifier->tag_name, ctx->capture_index);
				ctx->capture_index++;

				free(p_complete->tagtoken->lexeme);
				p_complete->tagtoken->lexeme = strdup(newtag);
				p_complete->visit_moved = 1;
			}
		}
		else if (ctx->is_second_pass)
		{
			/*
			 Na segunda passada vou renomear quem usa este tag exporado
			*/
			if (p_complete->visit_moved == 1)
			{
				if (p_struct_or_union_specifier != p_complete)
				{
					free(p_struct_or_union_specifier->tagtoken->lexeme);
					p_struct_or_union_specifier->tagtoken->lexeme = strdup(p_complete->tagtoken->lexeme);
				}
			}
		}
	}



	visit_member_declaration_list(ctx, &p_struct_or_union_specifier->member_declaration_list);

}

static void visit_enumerator(struct visit_ctx* ctx, struct enumerator* p_enumerator)
{
	if (p_enumerator->constant_expression_opt)
		visit_expression(ctx, p_enumerator->constant_expression_opt);

}

//struct enumerator_list* enumerator_list;
static void visit_enumerator_list(struct visit_ctx* ctx, struct enumerator_list* p_enumerator_list)
{
	struct enumerator* current = p_enumerator_list->head;
	while (current)
	{
		visit_enumerator(ctx, current);
		current = current->next;
	}
}

static void visit_enum_specifier(struct visit_ctx* ctx, struct enum_specifier* p_enum_specifier)
{
	if (ctx->target < LANGUAGE_C2X)
	{
		if (p_enum_specifier->specifier_qualifier_list)
		{
			struct token* tk = p_enum_specifier->specifier_qualifier_list->first_token;
			while (tk)
			{
				if (tk->type == ':')
					break;
				tk = tk->prev;
			}
			token_range_add_flag(tk,
				p_enum_specifier->specifier_qualifier_list->last_token,
				TK_FLAG_HIDE);
		}


		if (p_enum_specifier->complete_enum_specifier != NULL &&
			p_enum_specifier != p_enum_specifier->complete_enum_specifier &&
			p_enum_specifier->complete_enum_specifier->specifier_qualifier_list)
		{
			p_enum_specifier->first_token->flags |= TK_FLAG_HIDE;

			if (p_enum_specifier->tag_token)
				p_enum_specifier->tag_token->flags |= TK_FLAG_HIDE;

			struct osstream ss = { 0 };
			bool b_first = true;

			print_type_qualifier_flags(&ss, &b_first, p_enum_specifier->complete_enum_specifier->specifier_qualifier_list->type_qualifier_flags);
			print_type_specifier_flags(&ss, &b_first, p_enum_specifier->complete_enum_specifier->specifier_qualifier_list->type_specifier_flags);

			struct tokenizer_ctx tctx = { 0 };
			struct token_list l2 = tokenizer(&tctx, ss.c_str, NULL, 0, TK_FLAG_NONE);

			token_list_insert_after(&ctx->ast.token_list,
				p_enum_specifier->tag_token,
				&l2);

			ss_close(&ss);
			token_list_destroy(&l2);
		}

	}

	if (p_enum_specifier->attribute_specifier_sequence_opt)
	{
		visit_attribute_specifier_sequence(ctx, p_enum_specifier->attribute_specifier_sequence_opt);
	}

	visit_enumerator_list(ctx, &p_enum_specifier->enumerator_list);
}

static void visit_typeof_specifier(struct visit_ctx* ctx, struct typeof_specifier* p_typeof_specifier)
{
}

static void visit_type_specifier(struct visit_ctx* ctx, struct type_specifier* p_type_specifier)
{
	if (p_type_specifier->typeof_specifier)
	{
		visit_typeof_specifier(ctx, p_type_specifier->typeof_specifier);
	}

	if (p_type_specifier->struct_or_union_specifier)
	{
		visit_struct_or_union_specifier(ctx, p_type_specifier->struct_or_union_specifier);
	}

	if (p_type_specifier->enum_specifier)
	{
		visit_enum_specifier(ctx, p_type_specifier->enum_specifier);
	}


	if (p_type_specifier->atomic_type_specifier)
	{
		//visit_deped(ctx, p_type_specifier->enum_specifier);
	}

	if (p_type_specifier->flags & TYPE_SPECIFIER_BOOL)
	{
		if (ctx->target < LANGUAGE_C99)
		{
			free(p_type_specifier->token->lexeme);
			p_type_specifier->token->lexeme = strdup("unsigned char");
		}
		else
		{
			if (ctx->target < LANGUAGE_C2X)
			{
				if (strcmp(p_type_specifier->token->lexeme, "bool") == 0)
				{
					free(p_type_specifier->token->lexeme);
					p_type_specifier->token->lexeme = strdup("_Bool");
				}
			}
			else
			{
				free(p_type_specifier->token->lexeme);
				p_type_specifier->token->lexeme = strdup("bool");
			}
		}
	}
}

static void visit_type_specifier_qualifier(struct visit_ctx* ctx, struct type_specifier_qualifier* p_type_specifier_qualifier)
{
	if (p_type_specifier_qualifier->type_qualifier)
	{
	}
	else if (p_type_specifier_qualifier->type_specifier)
	{
		visit_type_specifier(ctx, p_type_specifier_qualifier->type_specifier);
	}
	else if (p_type_specifier_qualifier->alignment_specifier)
	{
	}
}

static void visit_storage_class_specifier(struct visit_ctx* ctx, struct storage_class_specifier* p_storage_class_specifier)
{
	if (p_storage_class_specifier->flags & STORAGE_SPECIFIER_AUTO)
	{
		if (ctx->target < LANGUAGE_C2X)
		{
			p_storage_class_specifier->token->flags |= TK_FLAG_HIDE;
		}
	}
}

static void visit_declaration_specifier(struct visit_ctx* ctx, struct declaration_specifier* p_declaration_specifier)
{

	if (p_declaration_specifier->function_specifier)
	{
		if (p_declaration_specifier->function_specifier->token->type == TK_KEYWORD__NORETURN)
		{
			if (ctx->target < LANGUAGE_C11)
			{
				free(p_declaration_specifier->function_specifier->token->lexeme);
				p_declaration_specifier->function_specifier->token->lexeme = strdup("/*[[noreturn]]*/");
			}
			else if (ctx->target == LANGUAGE_C11)
			{
				/*nothing*/
			}
			else if (ctx->target > LANGUAGE_C11)
			{
				/*use attributes*/
				free(p_declaration_specifier->function_specifier->token->lexeme);
				p_declaration_specifier->function_specifier->token->lexeme = strdup("[[noreturn]]");
			}

		}
	}


	if (p_declaration_specifier->storage_class_specifier)
	{
		visit_storage_class_specifier(ctx, p_declaration_specifier->storage_class_specifier);

	}

	if (p_declaration_specifier->type_specifier_qualifier)
	{
		visit_type_specifier_qualifier(ctx, p_declaration_specifier->type_specifier_qualifier);

	}

}

static void visit_declaration_specifiers(struct visit_ctx* ctx,
	struct declaration_specifiers* p_declaration_specifiers,
	struct type* p_type_opt)
{
	/*
		* Se tiver typeof ou auto vamos apagar todos type specifiers.
		* e trocar por um novo
		* const typeof(int (*)()) a;
		   //a = 1;
		  auto p = (const typeof(int (*)())) 0;

		  TODO esconder os type spefiver e qualifider , esconder auto.
		  o resto tipo static deixar.

		*/
		//
	if (!ctx->is_second_pass &&
		ctx->target < LANGUAGE_C2X &&
		(p_declaration_specifiers->storage_class_specifier_flags & STORAGE_SPECIFIER_AUTO ||
			p_declaration_specifiers->type_specifier_flags & TYPE_SPECIFIER_TYPEOF))
	{

		struct declaration_specifier* p_declaration_specifier = p_declaration_specifiers->head;
		while (p_declaration_specifier)
		{
			if (p_declaration_specifier->function_specifier)
			{
			}
			if (p_declaration_specifier->storage_class_specifier)
			{
			}
			if (p_declaration_specifier->type_specifier_qualifier)
			{
				if (p_declaration_specifier->type_specifier_qualifier->type_qualifier)
				{
					p_declaration_specifier->type_specifier_qualifier->type_qualifier->token->flags |= TK_FLAG_HIDE;
				}
				if (p_declaration_specifier->type_specifier_qualifier->type_specifier)
				{
					if (p_declaration_specifier->type_specifier_qualifier->type_specifier->typeof_specifier)
					{
						token_range_add_flag(p_declaration_specifier->type_specifier_qualifier->type_specifier->typeof_specifier->first_token,
							p_declaration_specifier->type_specifier_qualifier->type_specifier->typeof_specifier->last_token,
							TK_FLAG_HIDE);
					}
					p_declaration_specifier->type_specifier_qualifier->type_specifier->token->flags |= TK_FLAG_HIDE;
				}
			}
			p_declaration_specifier = p_declaration_specifier->next;
		}


		/*now we print new specifiers then convert to tokens*/
		struct osstream ss0 = { 0 };
		struct type new_type = { 0 };

		if (p_type_opt)
			new_type = type_convert_to(p_type_opt, ctx->target);

		const struct type* p = type_get_specifer_part(&new_type);
		print_type_qualifier_specifiers(&ss0, p);

		const int level = p_declaration_specifiers->last_token->level;
		struct tokenizer_ctx tctx = { 0 };
		struct token_list l2 = tokenizer(&tctx, ss0.c_str, NULL, level, TK_FLAG_FINAL);

		token_list_insert_after(&ctx->ast.token_list, p_declaration_specifiers->last_token, &l2);


		type_destroy(&new_type);
		ss_close(&ss0);
		token_list_destroy(&l2);
	}

	struct declaration_specifier* p_declaration_specifier = p_declaration_specifiers->head;

	struct declaration_specifier* p_constexpr_declaration_specifier = NULL;
	while (p_declaration_specifier)
	{
		if (p_declaration_specifier->storage_class_specifier &&
			p_declaration_specifier->storage_class_specifier->flags & STORAGE_SPECIFIER_CONSTEXPR)
		{
			p_constexpr_declaration_specifier = p_declaration_specifier;
		}

		visit_declaration_specifier(ctx, p_declaration_specifier);
		p_declaration_specifier = p_declaration_specifier->next;
	}


	if (ctx->target < LANGUAGE_C2X)
	{
		/*
		  fixing constexpr, we add static const if necessary
		*/
		if (p_constexpr_declaration_specifier &&
			p_declaration_specifiers->storage_class_specifier_flags & STORAGE_SPECIFIER_CONSTEXPR)
		{
			struct osstream ss = { 0 };
			const bool is_file_scope =
				p_declaration_specifiers->storage_class_specifier_flags & STORAGE_SPECIFIER_CONSTEXPR_STATIC;

			const bool has_static =
				p_declaration_specifiers->storage_class_specifier_flags & STORAGE_SPECIFIER_STATIC;

			const bool has_const =
				p_declaration_specifiers->type_qualifier_flags & TYPE_QUALIFIER_CONST;


			if (is_file_scope && !has_static)
			{
				ss_fprintf(&ss, "static");
				if (!has_const)
				{
					ss_fprintf(&ss, " const");
				}
			}
			else
			{
				if (!has_const)
				{
					ss_fprintf(&ss, "const");
				}
				else
				{
					ss_fprintf(&ss, " ");
				}
			}

			free(p_constexpr_declaration_specifier->storage_class_specifier->token->lexeme);
			p_constexpr_declaration_specifier->storage_class_specifier->token->lexeme = ss.c_str;
			ss.c_str = NULL; /*MOVED*/
			ss_close(&ss);
		}
	}

}

/*
* retorna true se o ultimo item for um return
*/
static bool is_last_item_return(struct compound_statement* p_compound_statement)
{
	if (p_compound_statement &&
		p_compound_statement->block_item_list.tail &&
		p_compound_statement->block_item_list.tail->unlabeled_statement &&
		p_compound_statement->block_item_list.tail->unlabeled_statement->jump_statement &&
		p_compound_statement->block_item_list.tail->unlabeled_statement->jump_statement->first_token &&
		p_compound_statement->block_item_list.tail->unlabeled_statement->jump_statement->first_token->type == TK_KEYWORD_RETURN)
	{
		return true;
	}
	return false;
}

void defer_scope_delete_one(struct defer_scope* owner p_block)
{
	if (p_block != NULL)
	{
		struct defer_scope* owner child = p_block->lastchild;
		while (child != NULL)
		{
			struct defer_scope* owner prev = child->previous;

			child->previous = NULL;
			defer_scope_delete_one(child);

			child = prev;
		}

		assert(p_block->previous == NULL);
		free(p_block);
	}
}

void defer_scope_delete_all(struct defer_scope* owner p)
{
	struct defer_scope* owner p_block = p;
	while (p_block != NULL)
	{
		struct defer_scope* owner prev_block = p_block->previous;
		p_block->previous = NULL;
		defer_scope_delete_one(p_block);
		p_block = prev_block;
	}
}

static void visit_declaration(struct visit_ctx* ctx, struct declaration* p_declaration)
{



	if (p_declaration->static_assert_declaration)
	{
		visit_static_assert_declaration(ctx, p_declaration->static_assert_declaration);
	}

	if (p_declaration->p_attribute_specifier_sequence_opt)
	{
		visit_attribute_specifier_sequence(ctx, p_declaration->p_attribute_specifier_sequence_opt);
	}


	if (p_declaration->declaration_specifiers)
	{

		if (p_declaration->init_declarator_list.head)
		{
			visit_declaration_specifiers(ctx, p_declaration->declaration_specifiers,
				&p_declaration->init_declarator_list.head->p_declarator->type);
		}
		else
		{
			visit_declaration_specifiers(ctx, p_declaration->declaration_specifiers, NULL);
		}

	}

	if (p_declaration->p_attribute_specifier_sequence_opt)
	{
		if (!ctx->is_second_pass)
		{
			token_range_add_flag(p_declaration->p_attribute_specifier_sequence_opt->first_token,
				p_declaration->p_attribute_specifier_sequence_opt->last_token,
				TK_FLAG_HIDE);

		}
	}
	if (ctx->is_second_pass)
	{

		if (p_declaration->declaration_specifiers &&
			p_declaration->declaration_specifiers->type_specifier_flags == TYPE_SPECIFIER_STRUCT_OR_UNION)
		{
			if (p_declaration->declaration_specifiers->struct_or_union_specifier->visit_moved == 1)
			{
				struct tokenizer_ctx tctx = { 0 };
				struct token_list list0 = tokenizer(&tctx, "struct ", NULL, 0, TK_FLAG_FINAL);
				token_list_append_list(&ctx->insert_before_declaration, &list0);
				token_list_destroy(&list0);


				struct token_list list = tokenizer(&tctx, p_declaration->declaration_specifiers->struct_or_union_specifier->tagtoken->lexeme, NULL, 0, TK_FLAG_FINAL);
				token_list_append_list(&ctx->insert_before_declaration, &list);
				token_list_destroy(&list);

				//struct token_list list3 = tokenizer("{", NULL, 0, TK_FLAG_FINAL);
				//token_list_append_list(&ctx->insert_before_declaration, &list3);



				struct token* first = p_declaration->declaration_specifiers->struct_or_union_specifier->member_declaration_list.first_token;
				struct token* last = p_declaration->declaration_specifiers->struct_or_union_specifier->member_declaration_list.last_token;
				for (struct token* current = first;
					current != last->next;
					current = current->next)
				{
					token_list_clone_and_add(&ctx->insert_before_declaration, current);
					//current->flags |= TK_FLAG_FINAL;
				}

				struct token_list list3 = tokenizer(&tctx, ";\n", NULL, 0, TK_FLAG_FINAL);
				token_list_append_list(&ctx->insert_before_declaration, &list3);


				if (p_declaration->init_declarator_list.head == NULL)
				{
					token_range_add_flag(p_declaration->declaration_specifiers->struct_or_union_specifier->first_token,
						p_declaration->declaration_specifiers->struct_or_union_specifier->last_token,
						TK_FLAG_HIDE);
				}
				else
				{
					token_range_add_flag(p_declaration->declaration_specifiers->struct_or_union_specifier->member_declaration_list.first_token,
						p_declaration->declaration_specifiers->struct_or_union_specifier->member_declaration_list.last_token,
						TK_FLAG_HIDE);
				}
				token_list_destroy(&list3);
			}
		}
	}


	if (p_declaration->init_declarator_list.head)
	{
		visit_init_declarator_list(ctx, &p_declaration->init_declarator_list);
	}

	if (p_declaration->function_body)
	{
		ctx->has_lambda = false;
		ctx->is_second_pass = false;


		struct defer_scope* p_defer = visit_ctx_push_tail_block(ctx);
		p_defer->p_function_body = p_declaration->function_body;

		visit_compound_statement(ctx, p_declaration->function_body);

		if (!is_last_item_return(p_declaration->function_body))
		{
			struct osstream ss = { 0 };
			print_block_defer(p_defer, &ss, true);
			if (ss.size > 0)
			{
				struct tokenizer_ctx tctx = { 0 };
				struct token_list l = tokenizer(&tctx, ss.c_str, NULL, 0, TK_FLAG_FINAL);
				token_list_insert_after(&ctx->ast.token_list, p_declaration->function_body->last_token->prev, &l);
				token_list_destroy(&l);
			}
			ss_close(&ss);
		}
		else
		{
			//ja tem um return antes que chama defer
			hide_block_defer(p_defer);
		}

		visit_ctx_pop_tail_block(ctx);



		if (ctx->has_lambda)
		{
			/*functions with lambdas requires two phases*/
			ctx->is_second_pass = true;
			visit_compound_statement(ctx, p_declaration->function_body);
		}
	}


	/*
	   In direct mode, we hide non used declarations (just to make the result smaller)
	*/
	if (ctx->hide_non_used_declarations &&
		p_declaration->init_declarator_list.head)
	{
		if (p_declaration->init_declarator_list.head->p_declarator &&
			p_declaration->init_declarator_list.head->p_declarator->num_uses == 0 &&
			p_declaration->init_declarator_list.head->p_declarator->function_body == NULL)
		{
			/*
			  transformations must keep first_token and last_token correct - updated
			*/
			token_range_add_flag(p_declaration->first_token, p_declaration->last_token, TK_FLAG_HIDE);
		}
	}
}

int visit_literal_string(struct visit_ctx* ctx, struct token* current)
{
	bool has_u8_prefix =
		current->lexeme[0] == 'u' && current->lexeme[1] == '8';

	if (has_u8_prefix && ctx->target < LANGUAGE_C11)
	{
		struct osstream ss = { 0 };
		unsigned char* psz = (unsigned char*)(current->lexeme + 2);

		while (*psz)
		{
			if (*psz >= 128)
			{
				ss_fprintf(&ss, "\\x%x", *psz);
			}
			else
			{
				ss_fprintf(&ss, "%c", *psz);
			}
			psz++;
		}

		free(current->lexeme);
		current->lexeme = ss.c_str;
		ss.c_str = NULL;
		ss_close(&ss);
	}

	return 0;
}

int visit_tokens(struct visit_ctx* ctx)
{
	struct token* current = ctx->ast.token_list.head;
	while (current)
	{

		if (current->type == TK_STRING_LITERAL)
		{
			visit_literal_string(ctx, current);
		}

		if (ctx->target < LANGUAGE_C2X)
		{
			if (current->type == TK_LINE_COMMENT)
			{
				if (ctx->target < LANGUAGE_C99)
				{
					struct osstream ss = { 0 };
					//TODO  check /* inside
					ss_fprintf(&ss, "/*%s*/", current->lexeme + 2);
					free(current->lexeme);
					current->lexeme = ss.c_str;
				}
			}
			else if (current->type == TK_PREPROCESSOR_LINE)
			{
				while (current->next && current->next->type == TK_BLANKS)
					current = current->next;

				/*
				  Trocar C23 #elifdef e #elifndef
				*/
				if (current->next && strcmp(current->next->lexeme, "elifdef") == 0)
				{
					free(current->next->lexeme);
					current->next->lexeme = strdup("elif defined ");
					current = current->next->next;
					continue;
				}
				else if (current->next && strcmp(current->next->lexeme, "elifndef") == 0)
				{
					free(current->next->lexeme);
					current->next->lexeme = strdup("elif ! defined ");
					current = current->next->next;
					continue;
				}
			}

			if (
				(current->type == TK_COMPILER_BINARY_CONSTANT) ||
				(current->type == TK_PPNUMBER && current->lexeme[0] == '0' && (current->lexeme[1] == 'b' || current->lexeme[1] == 'B')) /*dentro macros*/
				)
			{
				/*remove digit separators*/
				remove_char(current->lexeme, '\'');

				/*
				* Binary literals were added into C23.
				* We are converting to C99 hex.
				*/
				current->type = TK_COMPILER_HEXADECIMAL_CONSTANT;
				int value = strtol(current->lexeme + 2, 0, 2);
				char buffer[33 + 2] = { '0', 'x' };
				snprintf(buffer, sizeof buffer, "0x%x", value);
				free(current->lexeme);
				current->lexeme = strdup(buffer);
			}
			else if (current->type == TK_COMPILER_HEXADECIMAL_FLOATING_CONSTANT)
			{
				remove_char(current->lexeme, '\'');

				if (ctx->target < LANGUAGE_C99)
				{
					/*
					 * C99 Hexadecimal floating constants to C89.
					 */
					long double d = strtold(current->lexeme, 0);
					char buffer[50] = { 0 };
					snprintf(buffer, sizeof buffer, "%Lg", d);

					free(current->lexeme);
					current->lexeme = strdup(buffer);
				}
			}
			else if (current->type == TK_COMPILER_DECIMAL_CONSTANT ||
				current->type == TK_COMPILER_OCTAL_CONSTANT ||
				current->type == TK_COMPILER_HEXADECIMAL_CONSTANT ||
				current->type == TK_COMPILER_DECIMAL_FLOATING_CONSTANT ||
				current->type == TK_PPNUMBER)
			{
				/*remove digit separators*/
				remove_char(current->lexeme, '\'');
			}
		}

		current = current->next;
	}
	return 0;
}

void visit(struct visit_ctx* ctx)
{
	ctx->capture_index = 0;
	ctx->lambdas_index = 0;

	if (visit_tokens(ctx) != 0)
		return;

	struct declaration* p_declaration = ctx->ast.declaration_list.head;
	while (p_declaration)
	{
		visit_declaration(ctx, p_declaration);

		if (ctx->insert_before_block_item.head != NULL)
		{
			token_list_insert_after(&ctx->ast.token_list, p_declaration->first_token->prev, &ctx->insert_before_block_item);
		}

		/*
		* Tem que inserir algo antes desta declaracao?
		*/
		if (ctx->insert_before_declaration.head != NULL)
		{
			token_list_insert_after(&ctx->ast.token_list, p_declaration->first_token->prev, &ctx->insert_before_declaration);

		}

		p_declaration = p_declaration->next;
	}
	//if (ctx->instanciations.head != NULL)
	//{
	//    token_list_append_list(&ctx->ast.token_list, &ctx->instanciations);
	//}
}




/*
			  NULL
				|
			[function] (NULL <- child0 <- last_child)
				|
			  [try]  (NULL <- child0 <- last_child)
				|
tail_block-> [while] (NULL <- child0 <- last_child)

*/

struct flow_defer_scope
{

	//things must called at end of scope
	struct declarator* declarator; // declarator 
	struct defer_statement* defer_statement; // defer 

	//statements for controling where jump like break, throw stop.

	struct try_statement* p_try_statement; //try
	struct selection_statement* p_selection_statement; //if switch
	struct iteration_statement* p_iteration_statement; //for do while
	struct statement* p_statement;//
	struct compound_statement* p_compound_statement;
	struct compound_statement* p_function_body;
	struct secondary_block* p_secondary_block;
	struct primary_block* p_primary_block;

	struct flow_defer_scope* owner last_child; /**/
	struct flow_defer_scope* owner previous;
};

void flow_visit_declaration(struct flow_visit_ctx* ctx, struct declaration* p_declaration);
static void flow_visit_attribute_specifier_sequence(struct flow_visit_ctx* ctx, struct attribute_specifier_sequence* p_visit_attribute_specifier_sequence);

static void flow_visit_secondary_block(struct flow_visit_ctx* ctx, struct secondary_block* p_secondary_block);
static void flow_visit_struct_or_union_specifier(struct flow_visit_ctx* ctx, struct struct_or_union_specifier* p_struct_or_union_specifier);
static void flow_visit_expression(struct flow_visit_ctx* ctx, struct expression* p_expression);
static void flow_visit_statement(struct flow_visit_ctx* ctx, struct statement* p_statement);
static void flow_visit_enum_specifier(struct flow_visit_ctx* ctx, struct enum_specifier* p_enum_specifier);
static void flow_visit_type_specifier(struct flow_visit_ctx* ctx, struct type_specifier* p_type_specifier);

struct visit_objects {
	struct flow_defer_scope* current_block;
	struct flow_defer_scope* next_child;
};

struct object* visit_objects_next(struct visit_objects* visit_objects)
{
	while (visit_objects->current_block)
	{
		while (visit_objects->next_child)
		{
			if (visit_objects->next_child->declarator)
			{
				struct object* p = &visit_objects->next_child->declarator->object;
				visit_objects->next_child = visit_objects->next_child->previous;
				return p;
			}
			else
			{
				visit_objects->next_child = visit_objects->next_child->previous;
			}
		}

		visit_objects->current_block = visit_objects->current_block->previous;
		if (visit_objects->current_block)
			visit_objects->next_child = visit_objects->current_block->last_child;



	}

	return NULL;
}

struct flow_defer_scope* flow_visit_ctx_push_tail_block(struct flow_visit_ctx* ctx)
{
	struct flow_defer_scope* owner p_block = calloc(1, sizeof * p_block);
	p_block->previous = ctx->tail_block;
	ctx->tail_block = p_block;
	return ctx->tail_block;
}

struct flow_defer_scope* flow_visit_ctx_push_child(struct flow_visit_ctx* ctx)
{
	struct flow_defer_scope* owner child = calloc(1, sizeof * child);
	child->previous = ctx->tail_block->last_child;
	ctx->tail_block->last_child = child;
	return ctx->tail_block->last_child;
}

void flow_defer_scope_delete_one(struct flow_defer_scope* owner p)
{
	struct flow_defer_scope* owner p_block = p;
	if (p_block != NULL)
	{
		struct flow_defer_scope* owner child = p_block->last_child;
		while (child != NULL)
		{
			struct flow_defer_scope* owner previous = child->previous;
			child->previous = NULL;
			flow_defer_scope_delete_one(child);
			child = previous;
		}
		assert(p_block->previous == NULL);
		free(p_block);
	}
}


void flow_visit_ctx_pop_tail_block(struct flow_visit_ctx* ctx)
{
	if (ctx->tail_block)
	{
		struct flow_defer_scope* owner previous = ctx->tail_block->previous;
		ctx->tail_block->previous = NULL;
		flow_defer_scope_delete_one(ctx->tail_block);
		ctx->tail_block = previous;
	}
}

static bool check_defer_and_variables(struct flow_visit_ctx* ctx,
	struct flow_defer_scope* deferblock,
	struct token* position_token)
{
	bool found_error = false;

	struct flow_defer_scope* deferchild = deferblock->last_child;
	while (deferchild != NULL)
	{
		if (deferchild->defer_statement)
		{
			const int error_count = ctx->ctx->p_report->error_count;
			const int warnings_count = ctx->ctx->p_report->warnings_count;
			const int info_count = ctx->ctx->p_report->info_count;

			flow_visit_secondary_block(ctx, deferchild->defer_statement->secondary_block);

			if (error_count != ctx->ctx->p_report->error_count ||
				warnings_count != ctx->ctx->p_report->warnings_count ||
				info_count != ctx->ctx->p_report->info_count)
			{
				compiler_set_info_with_token(0, ctx->ctx, position_token, "defer end of scope");
			}
		}
		else if (deferchild->declarator)
		{
			struct declarator* p_declarator = deferchild->declarator;
			const char* name = p_declarator->name ? p_declarator->name->lexeme : "?";

			visit_object(ctx->ctx, &p_declarator->type, &p_declarator->object, position_token, name, false);

		}
		deferchild = deferchild->previous;
	}
	return found_error;
}
static bool flow_find_label_unlabeled_statement(struct flow_visit_ctx* ctx, struct unlabeled_statement* p_unlabeled_statement, const char* label);

static bool check_all_defer_until_try(struct flow_visit_ctx* ctx, struct flow_defer_scope* deferblock,
	struct token* position_token)
{
	bool found_error = false;
	struct flow_defer_scope* p_defer = deferblock;
	while (p_defer != NULL)
	{
		if (check_defer_and_variables(ctx, p_defer, position_token))
			found_error = true;

		if (p_defer->p_try_statement)
		{
			break;
		}

		p_defer = p_defer->previous;
	}
	return found_error;
}

static bool flow_find_label_block_item_list(struct flow_visit_ctx* ctx, struct block_item_list* p_block_item, const char* label)
{
	struct block_item* block_item = p_block_item->head;
	while (block_item)
	{
		if (block_item &&
			block_item->label &&
			block_item->label->name &&
			strcmp(block_item->label->name->lexeme, label) == 0)
		{
			/*achou*/
			return true;
		}
		else if (block_item->unlabeled_statement)
		{
			if (flow_find_label_unlabeled_statement(ctx, block_item->unlabeled_statement, label))
			{
				return true;
			}
		}

		block_item = block_item->next;
	}

	return false;
}

static bool flow_find_label_statement(struct flow_visit_ctx* ctx, struct statement* statement, const char* label);
static bool flow_find_label_unlabeled_statement(struct flow_visit_ctx* ctx, struct unlabeled_statement* p_unlabeled_statement, const char* label)
{
	if (p_unlabeled_statement->primary_block)
	{
		if (p_unlabeled_statement->primary_block->compound_statement)
		{
			if (flow_find_label_block_item_list(ctx,
				&p_unlabeled_statement->primary_block->compound_statement->block_item_list,
				label))
			{
				return true;
			}
		}
		else if (p_unlabeled_statement->primary_block->selection_statement)
		{
			if (flow_find_label_statement(ctx, p_unlabeled_statement->primary_block->selection_statement->secondary_block->statement, label))
			{
				return true;
			}
			if (p_unlabeled_statement->primary_block->selection_statement->else_secondary_block_opt)
			{
				if (flow_find_label_statement(ctx, p_unlabeled_statement->primary_block->selection_statement->else_secondary_block_opt->statement, label))
				{
					return true;
				}
			}
		}
		else if (p_unlabeled_statement->primary_block->try_statement)
		{
			if (flow_find_label_statement(ctx, p_unlabeled_statement->primary_block->try_statement->secondary_block->statement, label))
			{
				return true;
			}
			if (p_unlabeled_statement->primary_block->try_statement->catch_secondary_block_opt)
			{
				if (flow_find_label_statement(ctx, p_unlabeled_statement->primary_block->try_statement->catch_secondary_block_opt->statement, label))
				{
					return true;
				}
			}
		}
		else if (p_unlabeled_statement->primary_block->iteration_statement)
		{
			if (flow_find_label_statement(ctx, p_unlabeled_statement->primary_block->iteration_statement->secondary_block->statement, label))
			{
				return true;
			}
		}
	}
	return false;
}

static bool flow_find_label_statement(struct flow_visit_ctx* ctx, struct statement* statement, const char* label)
{
	if (statement->labeled_statement)
	{
		if (statement->labeled_statement &&
			statement->labeled_statement->label &&
			strcmp(statement->labeled_statement->label->name->lexeme, label) == 0)
		{
			/*achou*/
			return true;
		}
	}
	else if (statement->unlabeled_statement)
	{
		if (flow_find_label_unlabeled_statement(ctx, statement->unlabeled_statement, label))
			return true;
	}
	return false;
}

static bool flow_find_label_scope(struct flow_visit_ctx* ctx, struct flow_defer_scope* deferblock, const char* label)
{
	if (deferblock->p_iteration_statement)
	{
		if (deferblock->p_iteration_statement->secondary_block)
		{
			if (flow_find_label_statement(ctx, deferblock->p_iteration_statement->secondary_block->statement, label))
				return true;
		}
	}
	else if (deferblock->p_selection_statement)
	{
		if (deferblock->p_selection_statement->secondary_block)
		{
			if (flow_find_label_statement(ctx, deferblock->p_selection_statement->secondary_block->statement, label))
				return true;
		}

		if (deferblock->p_selection_statement->else_secondary_block_opt)
		{
			if (flow_find_label_statement(ctx, deferblock->p_selection_statement->else_secondary_block_opt->statement, label))
				return true;
		}
	}
	else if (deferblock->p_try_statement)
	{
		if (deferblock->p_try_statement->secondary_block)
		{
			if (flow_find_label_statement(ctx, deferblock->p_try_statement->secondary_block->statement, label))
				return true;
		}

		if (deferblock->p_try_statement->catch_secondary_block_opt)
		{
			if (flow_find_label_statement(ctx, deferblock->p_try_statement->catch_secondary_block_opt->statement, label))
				return true;
		}
	}
	else if (deferblock->p_statement)
	{
		if (flow_find_label_statement(ctx, deferblock->p_statement, label))
			return true;
	}
	else if (deferblock->p_function_body)
	{
		if (flow_find_label_block_item_list(ctx,
			&deferblock->p_function_body->block_item_list,
			label))
		{
			return true;
		}
	}
	else if (deferblock->p_compound_statement)
	{
		if (flow_find_label_block_item_list(ctx,
			&deferblock->p_compound_statement->block_item_list,
			label))
		{
			return true;
		}
	}
	return false;
}

static bool check_all_defer_until_label(struct flow_visit_ctx* ctx, struct flow_defer_scope* deferblock, const char* label,
	struct token* position_token)
{
	bool error_found = false;
	/*
	* Precisamos saber quantos escopos nós saimos até achar o label.
	* Para isso procuramos no escopo atual aonde aparede o goto.
	* Se o label não esta diretamente neste escopo ou dentro de algum escopo interno
	* Não nós imprimos os defers pois estamos saindo do escopo e vamos para o escopo
	* de cima. Assim vamos repetindo em cada saida de escopo imprimos o defer.
	*/
	struct flow_defer_scope* p_defer = deferblock;

	while (p_defer != NULL)
	{
		if (!flow_find_label_scope(ctx, p_defer, label))
		{
			error_found = error_found || check_defer_and_variables(ctx, p_defer, position_token);
		}
		else
		{
			break;
		}
		p_defer = p_defer->previous;
	}
	return error_found;
}

static bool check_all_defer_until_iter(struct flow_visit_ctx* ctx,
	struct flow_defer_scope* deferblock,
	struct token* position_token)
{
	bool error_found = false;
	struct flow_defer_scope* p_defer = deferblock;
	while (p_defer != NULL)
	{
		if (check_defer_and_variables(ctx, p_defer, position_token))
			error_found = true;
		if (p_defer->p_iteration_statement)
		{
			break;
		}
		p_defer = p_defer->previous;
	}
	return error_found;
}

static bool check_all_defer_until_iteration_or_selection_statement(struct flow_visit_ctx* ctx,
	struct flow_defer_scope* deferblock,
	struct token* position_token)
{
	bool error_found = false;
	struct flow_defer_scope* p_defer = deferblock;
	while (p_defer != NULL)
	{
		if (check_defer_and_variables(ctx, p_defer, position_token))
			error_found = true;
		if (p_defer->p_iteration_statement || p_defer->p_selection_statement)
		{
			//break pode ser usado em loops or switch
			break;
		}
		p_defer = p_defer->previous;
	}
	return error_found;
}

static bool check_all_defer_until_end(struct flow_visit_ctx* ctx, struct flow_defer_scope* deferblock, struct token* position_token)
{
	bool found_found = false;
	struct flow_defer_scope* p_defer = deferblock;
	while (p_defer != NULL)
	{
		found_found = found_found || check_defer_and_variables(ctx, p_defer, position_token);
		p_defer = p_defer->previous;
	}
	return found_found;
}



static void flow_visit_secondary_block(struct flow_visit_ctx* ctx, struct secondary_block* p_secondary_block)
{

	flow_visit_statement(ctx, p_secondary_block->statement);

}

static void flow_visit_defer_statement(struct flow_visit_ctx* ctx, struct defer_statement* p_defer_statement)
{

	//adiciona como filho do ultimo bloco
//    struct defer_scope* p_defer = visit_ctx_push_tail_child(ctx);
  //  p_defer->defer_statement = p_defer_statement;




	struct flow_defer_scope* p_defer = flow_visit_ctx_push_child(ctx);
	p_defer->defer_statement = p_defer_statement;


	/*
	  We are not going to visit the secondary block here because
	  this is not the place were defer is executed.
	*/
}

static void flow_visit_try_statement(struct flow_visit_ctx* ctx, struct try_statement* p_try_statement)
{
	struct flow_defer_scope* p_defer = flow_visit_ctx_push_tail_block(ctx);
	p_defer->p_try_statement = p_try_statement;

	if (p_try_statement->secondary_block)
		flow_visit_secondary_block(ctx, p_try_statement->secondary_block);

	check_defer_and_variables(ctx, p_defer, p_try_statement->secondary_block->last_token);

	flow_visit_ctx_pop_tail_block(ctx);
}

static struct object* expression_is_comparing_owner_with_null(struct expression* p_expression)
{
	if (p_expression->expression_type == EQUALITY_EXPRESSION_EQUAL &&
		type_is_pointer(&p_expression->left->type) &&
		expression_is_null_pointer_constant(p_expression->right))
	{
		// if ( pointer == NULL )
		struct type type = { 0 };
		struct object* p_object = expression_get_object(p_expression->left, &type);
		type_destroy(&type);
		return p_object;
	}


	if (p_expression->expression_type == EQUALITY_EXPRESSION_EQUAL &&
		expression_is_null_pointer_constant(p_expression->left) &&
		type_is_pointer(&p_expression->right->type))
	{
		// if (NULL == pointer)
		struct type type = { 0 };
		struct object* p_object = expression_get_object(p_expression->right, &type);
		type_destroy(&type);
		return p_object;
	}


	if (p_expression->expression_type == UNARY_EXPRESSION_NOT &&
		type_is_pointer(&p_expression->right->type))
	{
		//if (!p) same as p == NULL
		struct type type = { 0 };
		struct object* p_object = expression_get_object(p_expression->right, &type);
		type_destroy(&type);
		return p_object;
	}

	return NULL;
}

static struct object* expression_is_comparing_owner_with_not_null(struct expression* p_expression)
{


	if (p_expression->expression_type == EQUALITY_EXPRESSION_NOT_EQUAL &&
		type_is_pointer(&p_expression->left->type) &&
		expression_is_null_pointer_constant(p_expression->right))
	{
		//if (p != NULL)
		struct type type = { 0 };
		struct object* p_object = expression_get_object(p_expression->left, &type);
		type_destroy(&type);
		return p_object;
	}

	if (p_expression->expression_type == EQUALITY_EXPRESSION_NOT_EQUAL &&
		expression_is_null_pointer_constant(p_expression->right) &&
		type_is_pointer(&p_expression->left->type))
	{
		//NULL != p 
		struct type type = { 0 };
		struct object* p_object = expression_get_object(p_expression->right, &type);
		type_destroy(&type);
		return p_object;
	}


	if (type_is_pointer(&p_expression->type))
	{
		// if (p) same as p != NULL
		struct type type = { 0 };
		struct object* p_object = expression_get_object(p_expression, &type);
		type_destroy(&type);
		return p_object;
	}

	return NULL;
}

void push_copy_of_current_state(struct flow_visit_ctx* ctx)
{
	/*
	  top of stack constains the copy
	*/

	struct visit_objects v1 = { .current_block = ctx->tail_block,
								  .next_child = ctx->tail_block->last_child };

	struct object* p_object = visit_objects_next(&v1);
	while (p_object)
	{
		object_push_copy_current_state(p_object);
		p_object = visit_objects_next(&v1);
	}

}

void restore_state(struct flow_visit_ctx* ctx, int state_index_to_restore)
{
	struct visit_objects v1 = { .current_block = ctx->tail_block,
							   .next_child = ctx->tail_block->last_child };

	struct object* p_object = visit_objects_next(&v1);
	while (p_object)
	{
		object_restore_state(p_object, state_index_to_restore);
		p_object = visit_objects_next(&v1);
	};
}


static void object_merge_states_with_current(struct object* object,
	int dest_index,
	int before_index,
	int after_index)
{
	if (dest_index == 0 || (object->object_state_stack.size - dest_index >= 0 &&
		object->object_state_stack.size - dest_index < object->object_state_stack.size))
	{
	}
	else
	{
		return;
	}

	enum object_state* dest = dest_index == 0 ? &object->state :
		&object->object_state_stack.data[object->object_state_stack.size - dest_index];


	if (before_index == 0 || (object->object_state_stack.size - before_index >= 0 &&
		object->object_state_stack.size - before_index < object->object_state_stack.size))
	{
	}
	else
	{
		return;
	}
	enum object_state state_before = before_index == 0 ? object->state :
		object->object_state_stack.data[object->object_state_stack.size - before_index];




	if (after_index == 0 ||
		(object->object_state_stack.size - after_index >= 0 &&
			object->object_state_stack.size - after_index < object->object_state_stack.size))
	{
	}
	else
	{

		return;
	}
	enum object_state state_after = after_index == 0 ? object->state :
		object->object_state_stack.data[object->object_state_stack.size - after_index];

	*dest |= (state_before | state_after);


	if (object->pointed)
	{
		object_merge_states_with_current(object->pointed, dest_index, before_index, after_index);
	}

	for (int i = 0; i < object->members.size; i++)
	{
		object_merge_states_with_current(&object->members.data[i], dest_index, before_index, after_index);
	}

}

void merge_states(struct flow_visit_ctx* ctx,
	int dest_index,
	int before_index, //before while
	int after_index)
{
	struct visit_objects v1 = { .current_block = ctx->tail_block,
							   .next_child = ctx->tail_block->last_child };

	struct object* p_object = visit_objects_next(&v1);
	while (p_object)
	{
		object_merge_states_with_current(p_object, dest_index,
			before_index,
			after_index);
		p_object = visit_objects_next(&v1);
	};
}


static void object_merge_if_else_states(struct object* object,
	int dest_index,
	int original_state,
	int true_branch_state,
	int false_branch_state)
{
	if (dest_index == 0 || (object->object_state_stack.size - dest_index >= 0 &&
		object->object_state_stack.size - dest_index < object->object_state_stack.size))
	{
	}
	else
	{
		return;
	}
	if (original_state == 0 || (object->object_state_stack.size - original_state >= 0 &&
		object->object_state_stack.size - original_state < object->object_state_stack.size))
	{
	}
	else
	{

		return;
	}    if (true_branch_state == 0 ||
		(object->object_state_stack.size - true_branch_state >= 0 &&
			object->object_state_stack.size - true_branch_state < object->object_state_stack.size))
	{
	}
	else
	{
		return;
	}
	if (false_branch_state == 0 || (object->object_state_stack.size - false_branch_state >= 0 &&
		object->object_state_stack.size - false_branch_state < object->object_state_stack.size))
	{
	}
	else
	{

		return;
	}


	enum object_state* dest = dest_index == 0 ? &object->state :
		&object->object_state_stack.data[object->object_state_stack.size - dest_index];


	enum object_state s_original = original_state == 0 ? object->state :
		object->object_state_stack.data[object->object_state_stack.size - original_state];


	enum object_state s_true_branch = true_branch_state == 0 ? object->state :
		object->object_state_stack.data[object->object_state_stack.size - true_branch_state];


	enum object_state s_false_branch = false_branch_state == 0 ? object->state :
		object->object_state_stack.data[object->object_state_stack.size - false_branch_state];


	if (s_true_branch != s_original &&
		s_false_branch != s_original)
	{
		*dest |= (s_true_branch | s_false_branch);
	}
	else if (s_true_branch != s_original)
	{
		*dest |= (s_true_branch | s_original);
	}
	else if (s_false_branch != s_original)
	{
		*dest |= (s_false_branch | s_original);
	}
	else
	{
		*dest |= s_original;
	}

	if (object->pointed)
	{
		object_merge_if_else_states(object->pointed, dest_index, original_state, true_branch_state, false_branch_state);
	}

	for (int i = 0; i < object->members.size; i++)
	{
		object_merge_if_else_states(&object->members.data[i], dest_index, original_state, true_branch_state, false_branch_state);
	}

}

void merge_if_else_states(struct flow_visit_ctx* ctx,
	int dest_index,
	int original_state, //original
	int true_branch_state, //true branch
	int false_branch_state) //false branch
{
	struct visit_objects v1 = { .current_block = ctx->tail_block,
							   .next_child = ctx->tail_block->last_child };

	struct object* p_object = visit_objects_next(&v1);
	while (p_object)
	{
		object_merge_if_else_states(p_object, dest_index,
			original_state,
			true_branch_state,
			false_branch_state);
		p_object = visit_objects_next(&v1);
	};
}

void pop_states(struct flow_visit_ctx* ctx, int n)
{
	struct visit_objects v1 = { .current_block = ctx->tail_block,
							   .next_child = ctx->tail_block->last_child };

	struct object* p_object = visit_objects_next(&v1);
	while (p_object)
	{
		object_pop_states(p_object, n);
		p_object = visit_objects_next(&v1);
	};
}


static void flow_visit_if_statement(struct flow_visit_ctx* ctx, struct selection_statement* p_selection_statement)
{
	assert(p_selection_statement->first_token->type == TK_KEYWORD_IF);
	struct object* p_object_compared_with_null = NULL;

	if (p_selection_statement->expression)
	{
		p_object_compared_with_null = expression_is_comparing_owner_with_null(p_selection_statement->expression);
	}

	struct object* p_object_compared_with_not_null = NULL;
	if (p_selection_statement->expression)
	{
		p_object_compared_with_not_null = expression_is_comparing_owner_with_not_null(p_selection_statement->expression);
	}


	/*
	   This index is from the end of top of stack going to base of statck
	*/
	const int original = 2;
	push_copy_of_current_state(ctx);

	if (p_object_compared_with_null)
	{
		//if (p == 0) {  p is null }
		p_object_compared_with_null->state = OBJECT_STATE_NULL;
	}
	if (p_object_compared_with_not_null)
	{
		//if (p != 0) {  p is not null }
		p_object_compared_with_not_null->state = OBJECT_STATE_NOT_NULL;
	}

	if (p_selection_statement->secondary_block)
	{

		flow_visit_secondary_block(ctx, p_selection_statement->secondary_block);
		// check_defer_and_variables(ctx, p_defer, p_selection_statement->secondary_block->last_token);

	}

	bool was_last_statement_inside_true_branch_return = false;
	if (ctx->p_last_jump_statement)
	{
		//TODO gotos etc...

		was_last_statement_inside_true_branch_return =
			ctx->p_last_jump_statement->first_token->type == TK_KEYWORD_RETURN ||
			ctx->p_last_jump_statement->first_token->type == TK_KEYWORD_BREAK ||
			ctx->p_last_jump_statement->first_token->type == TK_KEYWORD_THROW ||
			ctx->p_last_jump_statement->first_token->type == TK_KEYWORD_CONTINUE;
	}

	//enum object_state state_left_in_true_branch = 0;
	//if (p_object_compared_with_null)
	  //  state_left_in_true_branch = p_object_compared_with_null->state;
	//else if (p_object_compared_with_not_null)
	  //  state_left_in_true_branch = p_object_compared_with_not_null->state;

	/*let's make a copy of the state we left true branch*/
	const int true_branch = 1;
	push_copy_of_current_state(ctx);

	restore_state(ctx, original);

	const int current = 0;

	/*when we dont have else block we have a empty imaginary one */
	/*we invert the object state*/
	if (p_object_compared_with_null)
	{
		// if (p == NULL) { } else { p is not null }
		p_object_compared_with_null->state = OBJECT_STATE_NOT_NULL;
	}
	if (p_object_compared_with_not_null)
	{
		// if (p != NULL) { } else { p is null }
		p_object_compared_with_not_null->state = OBJECT_STATE_NULL;
	}

	ctx->p_last_jump_statement = NULL;
	if (p_selection_statement->else_secondary_block_opt)
	{
		//struct flow_defer_scope* owner p_defer = calloc(1, sizeof * p_defer);
		//p_defer->previous = ctx->tail_block;
		//ctx->tail_block = p_defer;
		//p_defer->p_selection_statement = p_selection_statement;
		flow_visit_secondary_block(ctx, p_selection_statement->else_secondary_block_opt);
		//ctx->tail_block = ctx->tail_block->previous; //POP

	}

	bool was_last_statement_inside_else_branch_return = false;
	if (ctx->p_last_jump_statement)
	{
		//TODO gotos etc...
		was_last_statement_inside_else_branch_return =
			ctx->p_last_jump_statement->first_token->type == TK_KEYWORD_RETURN ||
			ctx->p_last_jump_statement->first_token->type == TK_KEYWORD_BREAK ||
			ctx->p_last_jump_statement->first_token->type == TK_KEYWORD_THROW ||
			ctx->p_last_jump_statement->first_token->type == TK_KEYWORD_CONTINUE;
	}


	if (was_last_statement_inside_true_branch_return)
	{
		if (was_last_statement_inside_else_branch_return)
		{
			restore_state(ctx, original);
		}
		else
		{
			//the else state is the current state
		}
	}
	else
	{
		if (was_last_statement_inside_else_branch_return)
		{
			restore_state(ctx, true_branch);
		}
		else
		{
			merge_if_else_states(ctx, current, original, true_branch, current);
		}
	}


	pop_states(ctx, 2);



}
static void flow_visit_block_item(struct flow_visit_ctx* ctx, struct block_item* p_block_item);

static void flow_visit_switch_statement(struct flow_visit_ctx* ctx, struct selection_statement* p_selection_statement)
{
	assert(p_selection_statement->first_token->type == TK_KEYWORD_SWITCH);

	int inverse_stack = 1; //we have 1 item
	push_copy_of_current_state(ctx); //2 (permanent copy)


	//const int current = 0;

	//const int nothing = -1;

	//bool has_default_case = false;
	int default_index = -1;

	//for each case
	// visit
	// merge not so simple if set in all branches the initial cannot be merged
	// restore
	struct statement* p_statement = p_selection_statement->secondary_block->statement;
	if (p_statement &&
		p_statement->unlabeled_statement &&
		p_statement->unlabeled_statement->primary_block &&
		p_statement->unlabeled_statement->primary_block->compound_statement)
	{
		struct compound_statement* p_compound_statement =
			p_statement->unlabeled_statement->primary_block->compound_statement;

		struct block_item* item = p_compound_statement->block_item_list.head;
		while (item)
		{
			if (item->label && item->first_token->type == TK_KEYWORD_CASE)
			{
				/*
				  Each time we find a case we restore the state to the state we
				  have before entering switch
				*/
				restore_state(ctx, inverse_stack);
			}
			if (item->label && item->first_token->type == TK_KEYWORD_DEFAULT)
			{
				default_index = inverse_stack;
				/*
				  Each time we find a case we restore the state to the state we
				  have before entering switch
				*/
				restore_state(ctx, inverse_stack);
			}
			else if (item->unlabeled_statement &&
				item->unlabeled_statement->jump_statement &&
				item->first_token->type == TK_KEYWORD_BREAK)
			{
				/*
				  Each time we find a break we safe the state
				  pushing it
				*/
				push_copy_of_current_state(ctx);
				inverse_stack++;
			}
			flow_visit_block_item(ctx, item);

			item = item->next;
		}
	}

	if (default_index == -1)
	{
		inverse_stack++;
		default_index = inverse_stack;
		push_copy_of_current_state(ctx);

	}

	const int original = inverse_stack;

	merge_if_else_states(ctx, 0, original, 2, default_index);

	for (int i = 3; i < inverse_stack; i++)
	{
		merge_if_else_states(ctx, 0, original, i, 0);
	}


	/*
	  we have a stack of states for each case label
	  now we need to merge them
	*/
	//The number of case we have is  inverse_stack - 1

	pop_states(ctx, inverse_stack);
}

static void flow_visit_selection_statement(struct flow_visit_ctx* ctx, struct selection_statement* p_selection_statement)
{
	struct flow_defer_scope* p_defer = flow_visit_ctx_push_tail_block(ctx);
	p_defer->p_selection_statement = p_selection_statement;


	if (p_selection_statement->first_token->type == TK_KEYWORD_IF)
	{
		flow_visit_if_statement(ctx, p_selection_statement);
	}
	else if (p_selection_statement->first_token->type == TK_KEYWORD_SWITCH)
	{
		flow_visit_switch_statement(ctx, p_selection_statement);
	}
	else
		assert(false);

	flow_visit_ctx_pop_tail_block(ctx);
}

static void flow_visit_compound_statement(struct flow_visit_ctx* ctx, struct compound_statement* p_compound_statement);

static void flow_visit_initializer_list(struct flow_visit_ctx* ctx, struct initializer_list* p_initializer_list);

static void flow_visit_bracket_initializer_list(struct flow_visit_ctx* ctx, struct braced_initializer* p_bracket_initializer_list)
{
	if (p_bracket_initializer_list->initializer_list == NULL)
	{

	}
	else
	{
		flow_visit_initializer_list(ctx, p_bracket_initializer_list->initializer_list);
	}
}

static void flow_visit_designation(struct flow_visit_ctx* ctx, struct designation* p_designation)
{
}

static void flow_visit_initializer(struct flow_visit_ctx* ctx, struct initializer* p_initializer)
{
	if (p_initializer->p_attribute_specifier_sequence_opt)
	{
		flow_visit_attribute_specifier_sequence(ctx, p_initializer->p_attribute_specifier_sequence_opt);
	}

	if (p_initializer->designation)
	{
		flow_visit_designation(ctx, p_initializer->designation);
	}

	if (p_initializer->assignment_expression)
	{
		flow_visit_expression(ctx, p_initializer->assignment_expression);
	}
	else if (p_initializer->braced_initializer)
	{
		flow_visit_bracket_initializer_list(ctx, p_initializer->braced_initializer);
	}
}

static void flow_visit_initializer_list(struct flow_visit_ctx* ctx, struct initializer_list* p_initializer_list)
{
	struct initializer* p_initializer = p_initializer_list->head;
	while (p_initializer)
	{
		flow_visit_initializer(ctx, p_initializer);
		p_initializer = p_initializer->next;
	}
}

static void flow_visit_type_qualifier(struct flow_visit_ctx* ctx, struct type_qualifier* p_type_qualifier)
{

}

static void flow_visit_specifier_qualifier(struct flow_visit_ctx* ctx, struct type_specifier_qualifier* p_specifier_qualifier)
{
	if (p_specifier_qualifier->type_specifier)
		flow_visit_type_specifier(ctx, p_specifier_qualifier->type_specifier);

	if (p_specifier_qualifier->type_qualifier)
		flow_visit_type_qualifier(ctx, p_specifier_qualifier->type_qualifier);
}

static void flow_visit_specifier_qualifier_list(struct flow_visit_ctx* ctx, struct specifier_qualifier_list* p_specifier_qualifier_list_opt,
	struct type* p_type)
{
	if (p_specifier_qualifier_list_opt == NULL)
		return;

	if (p_specifier_qualifier_list_opt->struct_or_union_specifier)
	{
		flow_visit_struct_or_union_specifier(ctx, p_specifier_qualifier_list_opt->struct_or_union_specifier);
	}
	else if (p_specifier_qualifier_list_opt->enum_specifier)
	{
		flow_visit_enum_specifier(ctx, p_specifier_qualifier_list_opt->enum_specifier);
	}
	else if (p_specifier_qualifier_list_opt->typedef_declarator)
	{
		//typedef name
	}
	//else if (p_specifier_qualifier_list->p_typeof_expression_opt)
	//{
	  //  flow_visit_expression(ctx, p_specifier_qualifier_list->p_typeof_expression_opt);
	//}
	else
	{
		struct type_specifier_qualifier* p_specifier_qualifier = p_specifier_qualifier_list_opt->head;
		while (p_specifier_qualifier)
		{
			flow_visit_specifier_qualifier(ctx, p_specifier_qualifier);
			p_specifier_qualifier = p_specifier_qualifier->next;
		}
	}
}
static void flow_visit_declarator(struct flow_visit_ctx* ctx, struct declarator* p_declarator);
static void flow_visit_type_name(struct flow_visit_ctx* ctx, struct type_name* p_type_name)
{

	flow_visit_specifier_qualifier_list(ctx, p_type_name->specifier_qualifier_list, &p_type_name->type);
	flow_visit_declarator(ctx, p_type_name->declarator);


	/*
	* Vamos esconder tudo e gerar um novo
	*  Exemplo
	*  (const typeof(int (*)())) -> *  ( int (*const )() )
	*/
}

static void flow_visit_argument_expression_list(struct flow_visit_ctx* ctx, struct argument_expression_list* p_argument_expression_list)
{
	struct argument_expression* p_argument_expression =
		p_argument_expression_list->head;
	while (p_argument_expression)
	{
		flow_visit_expression(ctx, p_argument_expression->expression);
		p_argument_expression = p_argument_expression->next;
	}
}

static void flow_visit_generic_selection(struct flow_visit_ctx* ctx, struct generic_selection* p_generic_selection)
{
	if (p_generic_selection->expression)
	{
		flow_visit_expression(ctx, p_generic_selection->expression);
	}
	else if (p_generic_selection->type_name)
	{
		flow_visit_type_name(ctx, p_generic_selection->type_name);
	}
}


static int compare_function_arguments2(struct parser_ctx* ctx,
	struct type* p_type,
	struct argument_expression_list* p_argument_expression_list)
{

	struct param* p_current_parameter_type = NULL;

	const struct param_list* p_param_list = type_get_func_or_func_ptr_params(p_type);

	if (p_param_list)
	{
		p_current_parameter_type = p_param_list->head;
	}

	int param_num = 1;
	struct argument_expression* p_current_argument = p_argument_expression_list->head;

	while (p_current_argument && p_current_parameter_type)
	{
		struct type argument_object_type = { 0 };
		struct object* p_argument_object =
			expression_get_object(p_current_argument->expression, &argument_object_type);

		bool bool_source_zero_value = constant_value_is_valid(&p_current_argument->expression->constant_value) &&
			constant_value_to_ull(&p_current_argument->expression->constant_value) == 0;

		struct type argument_object_type2 = { 0 };
		struct object* p_argument_object2 =
			expression_get_object(p_current_argument->expression, &argument_object_type2);


		if (ctx->options.null_checks)
		{
			if (type_is_pointer(&p_current_parameter_type->type) &&
				!(p_current_parameter_type->type.type_qualifier_flags & TYPE_QUALIFIER_OPT))
			{

				if (p_argument_object2 &&
					p_argument_object2->state & OBJECT_STATE_NULL)
				{
					compiler_set_error_with_token(C_OWNERSHIP_FLOW_MISSING_DTOR,
						ctx,
						p_current_argument->expression->first_token,
						"pointer can be null, but the parameter is not optional");
				}

				type_destroy(&argument_object_type2);
			}
		}


		/*
		  checking is some uninitialized or moved object is being used as parameter
		*/
		if (p_argument_object)
		{
			//TODO check if pointed object is const
			bool check_pointed_object = !type_is_void_ptr(&p_current_parameter_type->type);

			bool pointer_to_out = false;

			if (type_is_pointer(&p_current_parameter_type->type) &&
				check_pointed_object)
			{
				struct type t2 = type_remove_pointer(&p_current_parameter_type->type);
				if (type_is_out(&t2))
				{
					pointer_to_out = true;
					type_destroy(&t2);
				}
			}

			if (!pointer_to_out)
			{
				checked_read_object(ctx,
					&argument_object_type,
					p_argument_object,
					p_current_argument->expression->first_token,
					check_pointed_object);

			}
		}

		if (type_is_any_owner(&p_current_parameter_type->type))
		{
#if 1

#endif

			object_assignment(ctx,
				p_argument_object,
				&argument_object_type,
				NULL, /*dest object*/
				&p_current_parameter_type->type,
				p_current_argument->expression->first_token,
				bool_source_zero_value,
				OBJECT_STATE_UNINITIALIZED);
		}
		else
		{
			if (p_argument_object &&
				type_is_pointer(&p_current_parameter_type->type))
			{
				struct type parameter_type =
					type_remove_pointer(&p_current_parameter_type->type);

				if (!type_is_const(&parameter_type))
				{
					if (type_is_void(&parameter_type))
					{
						//
					}
					else
					{
						if (p_argument_object->pointed)
						{
							struct type pointed_type = type_remove_pointer(&argument_object_type);
							object_set_unknown(&pointed_type, p_argument_object->pointed);
							type_destroy(&pointed_type);
						}
					}
				}

				type_destroy(&parameter_type);
			}
		}
		p_current_argument = p_current_argument->next;
		p_current_parameter_type = p_current_parameter_type->next;
		param_num++;

		type_destroy(&argument_object_type);
	}

	while (p_current_argument) {
		/*
		   We have more argument than parameters, this happens with variadic functions
		*/
		struct type argument_object_type = { 0 };
		struct object* p_argument_object =
			expression_get_object(p_current_argument->expression, &argument_object_type);

		checked_read_object(ctx,
			&argument_object_type,
			p_argument_object,
			p_current_argument->expression->first_token,
			false);

		p_current_argument = p_current_argument->next;
	}
	return 0;
}
static void flow_visit_expression(struct flow_visit_ctx* ctx, struct expression* p_expression)
{
	if (p_expression == NULL)
		return;

	switch (p_expression->expression_type)
	{
	case PRIMARY_EXPRESSION__FUNC__:
		break;
	case PRIMARY_IDENTIFIER:
		break;
	case PRIMARY_EXPRESSION_ENUMERATOR:

		break;
	case PRIMARY_EXPRESSION_DECLARATOR:

		if (p_expression->declarator->object.state & OBJECT_STATE_UNINITIALIZED)
		{
			//TODO inside sizeof(v)  is not an error. :D
			//TODO function type...
#if 0
			compiler_set_warning_with_token(W_UNINITIALZED,
				ctx->ctx,
				p_expression->first_token,
				"'%s' is uninitialized ",
				p_expression->declarator->object_name->lexeme);
#endif
		}

		break;

	case PRIMARY_EXPRESSION_PARENTESIS:
		flow_visit_expression(ctx, p_expression->right);
		break;

	case PRIMARY_EXPRESSION_STRING_LITERAL:
		break;
	case PRIMARY_EXPRESSION_CHAR_LITERAL:
		break;
	case PRIMARY_EXPRESSION_NUMBER:
		break;

	case PRIMARY_EXPRESSION_PREDEFINED_CONSTANT:

		break;

	case PRIMARY_EXPRESSION_GENERIC:
		flow_visit_generic_selection(ctx, p_expression->generic_selection);
		break;

	case POSTFIX_DOT:
		break;
	case POSTFIX_ARROW:
		break;
	case POSTFIX_INCREMENT:
		break;
	case POSTFIX_DECREMENT:
		break;
	case POSTFIX_ARRAY:

		flow_visit_expression(ctx, p_expression->left);
		flow_visit_expression(ctx, p_expression->right);

		struct type t = { 0 };
		struct object* p_object = expression_get_object(p_expression->left, &t);

		if (p_object && p_object->state == OBJECT_STATE_UNINITIALIZED)
		{
			compiler_set_error_with_token(C_STATIC_ASSERT_FAILED,
				ctx->ctx,
				p_expression->left->first_token, "using a uninitialized object");
		}
		else if (p_object && p_object->state & OBJECT_STATE_UNINITIALIZED)
		{
			compiler_set_error_with_token(C_STATIC_ASSERT_FAILED,
				ctx->ctx,
				p_expression->left->first_token, "maybe using a uninitialized object");
		}
		type_destroy(&t);

		break;

	case POSTFIX_FUNCTION_CALL:

		flow_visit_expression(ctx, p_expression->left);

		flow_visit_argument_expression_list(ctx, &p_expression->argument_expression_list);
		compare_function_arguments2(ctx->ctx, &p_expression->left->type, &p_expression->argument_expression_list);

		break;
	case POSTFIX_EXPRESSION_FUNCTION_LITERAL:


		flow_visit_compound_statement(ctx, p_expression->compound_statement);


		break;

	case POSTFIX_EXPRESSION_COMPOUND_LITERAL:

		if (p_expression->type_name)
		{
			flow_visit_type_name(ctx, p_expression->type_name);
		}

		flow_visit_bracket_initializer_list(ctx, p_expression->braced_initializer);

		struct object temp2 = make_object(&p_expression->type, p_expression->type_name->declarator);
		object_swap(&temp2, &p_expression->type_name->declarator->object);
		object_destroy(&temp2);

		//TODO the state of object depends of the initializer
		set_direct_state(&p_expression->type, &p_expression->type_name->declarator->object, OBJECT_STATE_ZERO);


		assert(p_expression->left == NULL);
		assert(p_expression->right == NULL);

		break;

	case UNARY_EXPRESSION_ALIGNOF:

		if (p_expression->right)
		{
			flow_visit_expression(ctx, p_expression->right);
		}

		if (p_expression->type_name)
		{
			/*sizeof*/
			flow_visit_type_name(ctx, p_expression->type_name);
		}
		break;

	case UNARY_EXPRESSION_ASSERT:

		if (p_expression->right)
		{
			flow_visit_expression(ctx, p_expression->right);

			struct object* p_object_compared_with_null = NULL;

			if (p_expression->right)
			{
				p_object_compared_with_null = expression_is_comparing_owner_with_null(p_expression->right);
			}

			struct object* p_object_compared_with_not_null = NULL;
			if (p_expression->right)
			{
				p_object_compared_with_not_null = expression_is_comparing_owner_with_not_null(p_expression->right);
			}

			if (p_object_compared_with_null)
			{
				//if (p == 0) {  p is null }
				p_object_compared_with_null->state = OBJECT_STATE_NULL;
			}

			if (p_object_compared_with_not_null)
			{
				//if (p != 0) {  p is not null }
				p_object_compared_with_not_null->state = OBJECT_STATE_NOT_NULL;
			}
		}

		break;

	case UNARY_EXPRESSION_SIZEOF_EXPRESSION:
	case UNARY_EXPRESSION_SIZEOF_TYPE:
	case UNARY_EXPRESSION_INCREMENT:
	case UNARY_EXPRESSION_DECREMENT:

	case UNARY_EXPRESSION_NOT:
	case UNARY_EXPRESSION_BITNOT:
	case UNARY_EXPRESSION_NEG:
	case UNARY_EXPRESSION_PLUS:
	case UNARY_EXPRESSION_CONTENT:
	case UNARY_EXPRESSION_ADDRESSOF:
		if (p_expression->right)
		{
			flow_visit_expression(ctx, p_expression->right);
		}

		if (p_expression->type_name)
		{
			/*sizeof*/
			flow_visit_type_name(ctx, p_expression->type_name);
		}

		break;







	case ASSIGNMENT_EXPRESSION:
	{

		struct type right_object_type = { 0 };
		struct object* const p_right_object = expression_get_object(p_expression->right, &right_object_type);

		struct type dest_object_type = { 0 };
		struct object* const p_dest_object = expression_get_object(p_expression->left, &dest_object_type);
		//print_object(&dest_object_type, p_dest_object);
		flow_visit_expression(ctx, p_expression->left);
		//print_object(&dest_object_type, p_dest_object);
		flow_visit_expression(ctx, p_expression->right);



		bool bool_source_zero_value = constant_value_is_valid(&p_expression->right->constant_value) &&
			constant_value_to_ull(&p_expression->right->constant_value) == 0;

		if (p_expression->right &&
			p_expression->right->expression_type == POSTFIX_FUNCTION_CALL)
		{
			if (p_expression->right->left &&
				p_expression->right->left->declarator &&
				p_expression->right->left->declarator->name &&
				strcmp(p_expression->right->left->declarator->name->lexeme, "calloc") == 0)
			{
				bool_source_zero_value = true;
			}
		}

		object_assignment(ctx->ctx,
			p_right_object, /*source*/
			&right_object_type, /*source type*/
			p_dest_object, /*dest object*/
			&dest_object_type, /*dest type*/
			p_expression->left->first_token,
			bool_source_zero_value,
			OBJECT_STATE_MOVED);

		type_destroy(&right_object_type);
		type_destroy(&dest_object_type);

	}
	break;

	case CAST_EXPRESSION:
	case MULTIPLICATIVE_EXPRESSION_MULT:
	case MULTIPLICATIVE_EXPRESSION_DIV:
	case MULTIPLICATIVE_EXPRESSION_MOD:
	case ADDITIVE_EXPRESSION_PLUS:
	case ADDITIVE_EXPRESSION_MINUS:
	case SHIFT_EXPRESSION_RIGHT:
	case SHIFT_EXPRESSION_LEFT:
	case RELATIONAL_EXPRESSION_BIGGER_THAN:
	case RELATIONAL_EXPRESSION_LESS_THAN:


	case EQUALITY_EXPRESSION_EQUAL:
		flow_visit_expression(ctx, p_expression->left);
		flow_visit_expression(ctx, p_expression->right);

		break;

	case EQUALITY_EXPRESSION_NOT_EQUAL:
		flow_visit_expression(ctx, p_expression->left);
		flow_visit_expression(ctx, p_expression->right);
		break;

	case AND_EXPRESSION:
	case EXCLUSIVE_OR_EXPRESSION:
	case INCLUSIVE_OR_EXPRESSION:
	case INCLUSIVE_AND_EXPRESSION:
	case LOGICAL_OR_EXPRESSION:
	case RELATIONAL_EXPRESSION_LESS_OR_EQUAL_THAN:
	case RELATIONAL_EXPRESSION_BIGGER_OR_EQUAL_THAN:

		if (p_expression->left)
		{
			flow_visit_expression(ctx, p_expression->left);
		}
		if (p_expression->right)
		{
			flow_visit_expression(ctx, p_expression->right);
		}
		if (p_expression->type_name)
		{
			flow_visit_type_name(ctx, p_expression->type_name);
		}
		break;

	case UNARY_EXPRESSION_TRAITS:
	{

	}
	break;

	case UNARY_EXPRESSION_IS_SAME:
		break;

	case UNARY_DECLARATOR_ATTRIBUTE_EXPR:
		break;

	case CONDITIONAL_EXPRESSION:
		if (p_expression->condition_expr)
		{
			flow_visit_expression(ctx, p_expression->condition_expr);
		}

		if (p_expression->left)
		{
			flow_visit_expression(ctx, p_expression->left);
		}
		if (p_expression->right)
		{
			flow_visit_expression(ctx, p_expression->right);
		}

		break;

	default:
		break;
		}
	}

static void flow_visit_expression_statement(struct flow_visit_ctx* ctx, struct expression_statement* p_expression_statement)
{
	if (p_expression_statement->expression_opt)
		flow_visit_expression(ctx, p_expression_statement->expression_opt);
}

static void flow_visit_block_item_list(struct flow_visit_ctx* ctx, struct block_item_list* p_block_item_list);

static void flow_visit_compound_statement(struct flow_visit_ctx* ctx, struct compound_statement* p_compound_statement)
{
	struct flow_defer_scope* p_defer = flow_visit_ctx_push_tail_block(ctx);
	p_defer->p_compound_statement = p_compound_statement;

	flow_visit_block_item_list(ctx, &p_compound_statement->block_item_list);
	check_defer_and_variables(ctx, p_defer, p_compound_statement->last_token);

	flow_visit_ctx_pop_tail_block(ctx);
}

static void flow_visit_do_while_statement(struct flow_visit_ctx* ctx, struct iteration_statement* p_iteration_statement)
{
	assert(p_iteration_statement->first_token->type == TK_KEYWORD_DO);

	struct object* p_object_compared_with_not_null = NULL;

	if (p_iteration_statement->expression1)
	{
		p_object_compared_with_not_null = expression_is_comparing_owner_with_not_null(p_iteration_statement->expression1);
		flow_visit_expression(ctx, p_iteration_statement->expression1);
	}

	if (p_iteration_statement->secondary_block)
	{
		struct flow_defer_scope* p_defer = flow_visit_ctx_push_tail_block(ctx);
		p_defer->p_iteration_statement = p_iteration_statement;

		flow_visit_secondary_block(ctx, p_iteration_statement->secondary_block);

		check_defer_and_variables(ctx, p_defer, p_iteration_statement->secondary_block->last_token);

		flow_visit_ctx_pop_tail_block(ctx);

		bool was_last_statement_inside_true_branch_return = false;
		if (ctx->p_last_jump_statement)
		{

			was_last_statement_inside_true_branch_return =
				ctx->p_last_jump_statement->first_token->type == TK_KEYWORD_RETURN ||
				ctx->p_last_jump_statement->first_token->type == TK_KEYWORD_BREAK ||
				ctx->p_last_jump_statement->first_token->type == TK_KEYWORD_THROW ||
				ctx->p_last_jump_statement->first_token->type == TK_KEYWORD_CONTINUE;
		}

		if (was_last_statement_inside_true_branch_return)
		{
			//restore_state(ctx, 0);
			//if (p_object_compared_with_not_null)
			//{
				//do {}  while (p);
			  //  p_object_compared_with_not_null->state = OBJECT_STATE_NULL;
			//}
		}
		else
		{
			//do { } while (p); 

			if (p_object_compared_with_not_null)
			{
				p_object_compared_with_not_null->state = OBJECT_STATE_NULL;
			}
		}
	}
}
static void flow_visit_while_statement(struct flow_visit_ctx* ctx, struct iteration_statement* p_iteration_statement)
{
	assert(p_iteration_statement->first_token->type == TK_KEYWORD_WHILE);

	struct object* p_object_compared_with_not_null = NULL;

	if (p_iteration_statement->expression1)
	{
		p_object_compared_with_not_null = expression_is_comparing_owner_with_not_null(p_iteration_statement->expression1);
		flow_visit_expression(ctx, p_iteration_statement->expression1);
	}

	if (p_iteration_statement->secondary_block)
	{
		const int original = 1;
		push_copy_of_current_state(ctx);

		const int current = 0;

		struct flow_defer_scope* p_defer = flow_visit_ctx_push_tail_block(ctx);
		p_defer->p_iteration_statement = p_iteration_statement;

		if (p_object_compared_with_not_null)
		{
			//while (p != 0) {  p is not null }
			p_object_compared_with_not_null->state = OBJECT_STATE_NOT_NULL;
		}

		flow_visit_secondary_block(ctx, p_iteration_statement->secondary_block);

		check_defer_and_variables(ctx, p_defer, p_iteration_statement->secondary_block->last_token);


		bool was_last_statement_inside_true_branch_return = false;
		if (ctx->p_last_jump_statement)
		{
			//TODO gotos etc...
			was_last_statement_inside_true_branch_return =
				ctx->p_last_jump_statement->first_token->type == TK_KEYWORD_RETURN;
		}

		if (was_last_statement_inside_true_branch_return)
		{
			restore_state(ctx, original);
			//if (p_object_compared_with_not_null)
			//{
				/*
				 while (p)
				 {
					   return;
				 }
				*/
				//  p_object_compared_with_not_null->state = OBJECT_STATE_NULL;
			  //}
		}
		else
		{
			/*
			   while (p)
			   {
			   }
			*/
			//merge_if_else_states(ctx, current, current, original, -1 /*nothing*/);
			merge_states(ctx, current, original, current);
			if (p_object_compared_with_not_null)
			{
				p_object_compared_with_not_null->state = OBJECT_STATE_NULL;
			}
		}
		pop_states(ctx, 1);
		flow_visit_ctx_pop_tail_block(ctx);
	}
}

static void flow_visit_iteration_statement(struct flow_visit_ctx* ctx, struct iteration_statement* p_iteration_statement)
{
	if (p_iteration_statement->first_token->type == TK_KEYWORD_WHILE)
	{
		flow_visit_while_statement(ctx, p_iteration_statement);
	}
	else if (p_iteration_statement->first_token->type == TK_KEYWORD_DO)
	{
		flow_visit_do_while_statement(ctx, p_iteration_statement);
	}
	else if (p_iteration_statement->first_token->type == TK_KEYWORD_FOR)
	{
		//flow_visit_do_while_statement(ctx, p_iteration_statement);
	}
}

static void flow_visit_jump_statement(struct flow_visit_ctx* ctx, struct jump_statement* p_jump_statement)
{
	ctx->p_last_jump_statement = p_jump_statement;


	if (p_jump_statement->first_token->type == TK_KEYWORD_THROW)
	{
		check_all_defer_until_try(ctx, ctx->tail_block, p_jump_statement->first_token);
	}
	else if (p_jump_statement->first_token->type == TK_KEYWORD_RETURN)
	{
		if (p_jump_statement->expression_opt)
		{
			flow_visit_expression(ctx, p_jump_statement->expression_opt);
		}

		/*
		  returning a declarator will move the onwership
		*/
		if (p_jump_statement->expression_opt)
		{
			struct type type = { 0 };
			struct object* p_object = expression_get_object(p_jump_statement->expression_opt, &type);
			bool bool_source_zero_value = constant_value_is_valid(&p_jump_statement->expression_opt->constant_value) &&
				constant_value_to_ull(&p_jump_statement->expression_opt->constant_value) == 0;


			checked_read_object(ctx->ctx,
				&type,
				p_object,
				p_jump_statement->expression_opt->first_token,
				true);

			object_assignment(ctx->ctx,
				p_object, /*source*/
				&type, /*source type*/
				NULL, /*dest object*/
				ctx->p_return_type, /*dest type*/
				p_jump_statement->expression_opt->first_token,
				bool_source_zero_value,
				OBJECT_STATE_UNINITIALIZED);

			type_destroy(&type);

		}
		check_all_defer_until_end(ctx, ctx->tail_block, p_jump_statement->first_token);
	}
	else if (p_jump_statement->first_token->type == TK_KEYWORD_CONTINUE)
	{
		check_all_defer_until_iter(ctx, ctx->tail_block, p_jump_statement->first_token);
	}
	else if (p_jump_statement->first_token->type == TK_KEYWORD_BREAK)
	{
		check_all_defer_until_iteration_or_selection_statement(ctx, ctx->tail_block, p_jump_statement->first_token);
	}
	else if (p_jump_statement->first_token->type == TK_KEYWORD_GOTO)
	{
		check_all_defer_until_label(ctx, ctx->tail_block, p_jump_statement->label->lexeme, p_jump_statement->first_token);

		//set_all_until_end(ctx, ctx->tail_block, (OBJECT_STATE_NOT_NULL | OBJECT_STATE_NULL));
	}
	else
	{
		assert(false);
	}
}

static void flow_visit_label(struct flow_visit_ctx* ctx, struct label* p_label);

static void flow_visit_labeled_statement(struct flow_visit_ctx* ctx, struct labeled_statement* p_labeled_statement)
{
	if (p_labeled_statement->label)
	{
		flow_visit_label(ctx, p_labeled_statement->label);
	}

	if (p_labeled_statement->statement)
	{
		flow_visit_statement(ctx, p_labeled_statement->statement);
	}
}

static void flow_visit_primary_block(struct flow_visit_ctx* ctx, struct primary_block* p_primary_block)
{

	if (p_primary_block->defer_statement)
	{
		flow_visit_defer_statement(ctx, p_primary_block->defer_statement);
	}
	else
	{
		if (p_primary_block->compound_statement)
		{
			flow_visit_compound_statement(ctx, p_primary_block->compound_statement);
		}
		else if (p_primary_block->iteration_statement)
		{
			flow_visit_iteration_statement(ctx, p_primary_block->iteration_statement);
		}
		else if (p_primary_block->selection_statement)
		{
			flow_visit_selection_statement(ctx, p_primary_block->selection_statement);
		}
		else if (p_primary_block->try_statement)
		{
			flow_visit_try_statement(ctx, p_primary_block->try_statement);
		}
	}
}

static void flow_visit_unlabeled_statement(struct flow_visit_ctx* ctx, struct unlabeled_statement* p_unlabeled_statement)
{
	ctx->p_last_jump_statement = NULL;
	if (p_unlabeled_statement->primary_block)
	{
		flow_visit_primary_block(ctx, p_unlabeled_statement->primary_block);
	}
	else if (p_unlabeled_statement->expression_statement)
	{
		flow_visit_expression_statement(ctx, p_unlabeled_statement->expression_statement);
	}
	else if (p_unlabeled_statement->jump_statement)
	{
		flow_visit_jump_statement(ctx, p_unlabeled_statement->jump_statement);
	}
	else
	{
		assert(false);
	}
}

static void flow_visit_statement(struct flow_visit_ctx* ctx, struct statement* p_statement)
{
	ctx->p_last_jump_statement = NULL;

	if (p_statement->labeled_statement)
	{
		flow_visit_labeled_statement(ctx, p_statement->labeled_statement);
	}
	else if (p_statement->unlabeled_statement)
	{
		flow_visit_unlabeled_statement(ctx, p_statement->unlabeled_statement);
	}
}

static void flow_visit_label(struct flow_visit_ctx* ctx, struct label* p_label)
{

}

static void flow_visit_block_item(struct flow_visit_ctx* ctx, struct block_item* p_block_item)
{
	ctx->p_last_jump_statement = NULL;
	if (p_block_item->declaration)
	{
		flow_visit_declaration(ctx, p_block_item->declaration);
	}
	else if (p_block_item->unlabeled_statement)
	{
		flow_visit_unlabeled_statement(ctx, p_block_item->unlabeled_statement);
	}
	else if (p_block_item->label)
	{
		flow_visit_label(ctx, p_block_item->label);
	}

}

static void flow_visit_block_item_list(struct flow_visit_ctx* ctx, struct block_item_list* p_block_item_list)
{
	struct block_item* p_block_item = p_block_item_list->head;
	while (p_block_item)
	{
		flow_visit_block_item(ctx, p_block_item);
		p_block_item = p_block_item->next;
	}
}

enum object_state parse_string_state(const char* s, bool* invalid)
{
	*invalid = false;

	enum object_state e = 0;
	const char* p = s;

	while (*p)
	{
		if (isalpha(*p))
		{
			const char* start = p;
			while (isalpha(*p) || *p == '-')
			{
				p++;
			}

			if (strncmp(start, "moved", p - start) == 0)
				e |= OBJECT_STATE_MOVED;
			else if (strncmp(start, "null", p - start) == 0)
				e |= OBJECT_STATE_NULL;
			else if (strncmp(start, "not-null", p - start) == 0)
				e |= OBJECT_STATE_NOT_NULL;
			else if (strncmp(start, "maybe-null", p - start) == 0)
				e |= (OBJECT_STATE_NOT_NULL | OBJECT_STATE_NULL);
			else if (strncmp(start, "uninitialized", p - start) == 0)
				e |= OBJECT_STATE_UNINITIALIZED;
			else if (strncmp(start, "zero", p - start) == 0)
				e |= OBJECT_STATE_ZERO;
			else if (strncmp(start, "not-zero", p - start) == 0)
				e |= OBJECT_STATE_NOT_ZERO;
			else if (strncmp(start, "any", p - start) == 0)
				e |= (OBJECT_STATE_NOT_ZERO | OBJECT_STATE_ZERO);
			else if (strncmp(start, "moved", p - start) == 0)
				e |= OBJECT_STATE_MOVED;
			else if (strncmp(start, "or", p - start) == 0)
			{
				//skiped
			}
			else
			{
				*invalid = true;
				return 0; //error invalid name
			}
		}
		else
		{
			p++;
		}
	}

	return e;

}


static void flow_visit_static_assert_declaration(struct flow_visit_ctx* ctx, struct static_assert_declaration* p_static_assert_declaration)
{
	flow_visit_expression(ctx, p_static_assert_declaration->constant_expression);

	if (p_static_assert_declaration->first_token->type == TK_KEYWORD_STATIC_DEBUG)
	{
		compiler_set_info_with_token(W_NONE, ctx->ctx, p_static_assert_declaration->first_token, "static_debug");

		struct type t = { 0 };
		struct object* p_obj = expression_get_object(p_static_assert_declaration->constant_expression, &t);



		if (p_obj)
		{
			print_object(&t, p_obj, true);
		}

		type_destroy(&t);
	}
	else if (p_static_assert_declaration->first_token->type == TK_KEYWORD_STATIC_STATE)
	{
		struct type t = { 0 };
		struct object* p_obj = expression_get_object(p_static_assert_declaration->constant_expression, &t);
		if (p_obj)
		{
			if (p_static_assert_declaration->string_literal_opt)
			{
				bool is_invalid = false;
				enum object_state e =
					parse_string_state(p_static_assert_declaration->string_literal_opt->lexeme, &is_invalid);
				if (!is_invalid)
				{
					if (e != p_obj->state)
					{
						compiler_set_error_with_token(C_STATIC_ASSERT_FAILED, ctx->ctx, p_static_assert_declaration->first_token, "static_state failed");
					}
				}
				else
				{
					compiler_set_error_with_token(C_STATIC_ASSERT_FAILED, ctx->ctx, p_static_assert_declaration->first_token, "invalid parameter %s", p_static_assert_declaration->string_literal_opt->lexeme);
				}
			}

		}
		type_destroy(&t);
	}
	else if (p_static_assert_declaration->first_token->type == TK_KEYWORD_STATIC_SET)
	{
		struct type t = { 0 };
		struct object* p_obj = expression_get_object(p_static_assert_declaration->constant_expression, &t);
		if (p_obj)
		{
			if (p_static_assert_declaration->string_literal_opt)
			{

				const char* lexeme =
					p_static_assert_declaration->string_literal_opt->lexeme;

				if (strcmp(lexeme, "\"zero\"") == 0)
				{
					//gives the semantics of {0} or calloc                    
					set_direct_state(&t, p_obj, OBJECT_STATE_ZERO);
				}
				else
				{
					bool is_invalid = false;
					enum object_state e =
						parse_string_state(p_static_assert_declaration->string_literal_opt->lexeme, &is_invalid);

					if (!is_invalid)
					{
						set_object(&t, p_obj, e);
					}
					else
					{
						compiler_set_error_with_token(C_STATIC_ASSERT_FAILED, ctx->ctx, p_static_assert_declaration->first_token, "invalid parameter %s", p_static_assert_declaration->string_literal_opt->lexeme);
					}
				}
			}

		}
		type_destroy(&t);
	}
}

static void flow_visit_declaration_specifiers(struct flow_visit_ctx* ctx,
	struct declaration_specifiers* p_declaration_specifiers,
	struct type* p_type);


static void flow_visit_direct_declarator(struct flow_visit_ctx* ctx, struct direct_declarator* p_direct_declarator)
{
	if (p_direct_declarator->function_declarator)
	{
		struct parameter_declaration* parameter = NULL;

		if (p_direct_declarator->function_declarator->parameter_type_list_opt)
		{
			parameter = p_direct_declarator->function_declarator->parameter_type_list_opt->parameter_list->head;
		}


		ctx->parameter_list++;

		while (parameter)
		{
			if (parameter->attribute_specifier_sequence_opt)
			{
				flow_visit_attribute_specifier_sequence(ctx, parameter->attribute_specifier_sequence_opt);
			}

			flow_visit_declaration_specifiers(ctx, parameter->declaration_specifiers, &parameter->declarator->type);
			flow_visit_declarator(ctx, parameter->declarator);
			parameter = parameter->next;
		}

		ctx->parameter_list--;

	}
	else if (p_direct_declarator->array_declarator)
	{
		if (p_direct_declarator->array_declarator->assignment_expression)
		{
			flow_visit_expression(ctx, p_direct_declarator->array_declarator->assignment_expression);
		}

	}
}

static void flow_visit_declarator(struct flow_visit_ctx* ctx, struct declarator* p_declarator)
{
	if (ctx->tail_block &&
		p_declarator->type.category != TYPE_CATEGORY_FUNCTION)
	{

		if (ctx->parameter_list > 1)
		{
			/*
			 The objective here is to avoid including the arguments
			 of function pointers inside the scope.
			 Sample
			 void x_destroy(void (*f)(void * owner p))
			 We add f but not p.
			*/
			return;
		}

		struct flow_defer_scope* p_defer = flow_visit_ctx_push_child(ctx);
		p_defer->declarator = p_declarator;


		struct object temp = make_object(&p_declarator->type, p_declarator);
		object_swap(&temp, &p_declarator->object);
		object_destroy(&temp);

		if (p_declarator->declaration_specifiers &&
			p_declarator->declaration_specifiers->storage_class_specifier_flags & STORAGE_SPECIFIER_PARAMETER)
		{
			if (type_is_pointer(&p_declarator->type))
			{
				if (!ctx->ctx->options.null_checks ||
					(p_declarator->type.type_qualifier_flags & TYPE_QUALIFIER_OPT))
				{
					set_object(&p_declarator->type, &p_declarator->object, (OBJECT_STATE_NOT_NULL | OBJECT_STATE_NULL));
				}
				else
				{
					set_object(&p_declarator->type, &p_declarator->object, (OBJECT_STATE_NOT_NULL));
				}
			}
			else
			{
				set_object(&p_declarator->type, &p_declarator->object, (OBJECT_STATE_NOT_NULL | OBJECT_STATE_NULL));
			}


#if 0
			if (type_is_pointer(&p_declarator->type))
			{
				//TODO necessary?
				struct type t2 = type_remove_pointer(&p_declarator->type);
				if (p_declarator->object.pointed)
				{
					set_object(&t2, p_declarator->object.pointed, (OBJECT_STATE_NOT_NULL | OBJECT_STATE_NULL));
				}
				type_destroy(&t2);
			}
#endif
		}
	}

	/*if (p_declarator->pointer)
	{
		struct pointer* p = p_declarator->pointer;
		while (p)
		{
			p = p->pointer;
		}
	}*/


	if (p_declarator->direct_declarator)
	{
		flow_visit_direct_declarator(ctx, p_declarator->direct_declarator);
	}
			}

static void flow_visit_init_declarator_list(struct flow_visit_ctx* ctx, struct init_declarator_list* p_init_declarator_list)
{
	struct init_declarator* p_init_declarator = p_init_declarator_list->head;

	while (p_init_declarator)
	{
		if (p_init_declarator->p_declarator)
		{
			flow_visit_declarator(ctx, p_init_declarator->p_declarator);
		}

		if (p_init_declarator->initializer)
		{
			if (p_init_declarator->initializer->assignment_expression)
			{
				flow_visit_expression(ctx, p_init_declarator->initializer->assignment_expression);
			}
			else
			{
				assert(p_init_declarator->initializer->braced_initializer != NULL);
				if (p_init_declarator->initializer->braced_initializer)
				{
					flow_visit_bracket_initializer_list(ctx,
						p_init_declarator->initializer->braced_initializer);

					//set zero
				}
			}
		}

		if (p_init_declarator->p_declarator->type.category != TYPE_CATEGORY_FUNCTION)
		{
			if (p_init_declarator->initializer &&
				p_init_declarator->initializer->assignment_expression)
			{
				struct type right_object_type = { 0 };
				struct object* p_right_object =
					expression_get_object(p_init_declarator->initializer->assignment_expression, &right_object_type);

				bool bool_source_zero_value = constant_value_is_valid(&p_init_declarator->initializer->assignment_expression->constant_value) &&
					constant_value_to_ull(&p_init_declarator->initializer->assignment_expression->constant_value) == 0;


				//cast?
				if (p_init_declarator->initializer->assignment_expression->expression_type == POSTFIX_FUNCTION_CALL &&
					p_init_declarator->initializer->assignment_expression->left &&
					p_init_declarator->initializer->assignment_expression->left->declarator &&
					p_init_declarator->initializer->assignment_expression->left->declarator->name)
				{
					if (strcmp(p_init_declarator->initializer->assignment_expression->left->declarator->name->lexeme, "calloc") == 0)
					{
						p_init_declarator->p_declarator->object.state = OBJECT_STATE_NOT_NULL | OBJECT_STATE_NULL;

						if (p_init_declarator->p_declarator->object.pointed)
						{
							struct type t = type_remove_pointer(&p_init_declarator->p_declarator->type);
							set_direct_state(&t, p_init_declarator->p_declarator->object.pointed, OBJECT_STATE_ZERO);
							type_destroy(&t);
						}
					}
					else if (strcmp(p_init_declarator->initializer->assignment_expression->left->declarator->name->lexeme, "malloc") == 0)
					{
						p_init_declarator->p_declarator->object.state = OBJECT_STATE_NOT_NULL | OBJECT_STATE_NULL;

						struct type t = type_remove_pointer(&p_init_declarator->p_declarator->type);
						set_direct_state(&t, p_init_declarator->p_declarator->object.pointed, OBJECT_STATE_UNINITIALIZED);
						type_destroy(&t);
					}
					else
					{
						const struct token* const token_position =
							p_init_declarator->p_declarator->name ?
							p_init_declarator->p_declarator->name :
							p_init_declarator->p_declarator->first_token
							;

						object_assignment(ctx->ctx, p_right_object, &right_object_type,
							&p_init_declarator->p_declarator->object,
							&p_init_declarator->p_declarator->type,
							token_position,
							bool_source_zero_value,
							OBJECT_STATE_MOVED);
					}
				}
				else
				{
					const struct token* const token_position =
						p_init_declarator->p_declarator->name ?
						p_init_declarator->p_declarator->name :
						p_init_declarator->p_declarator->first_token
						;

					object_assignment(ctx->ctx, p_right_object, &right_object_type,
						&p_init_declarator->p_declarator->object,
						&p_init_declarator->p_declarator->type,
						token_position,
						bool_source_zero_value,
						OBJECT_STATE_MOVED);
				}

				type_destroy(&right_object_type);
			}
			else  if (p_init_declarator->initializer &&
				p_init_declarator->initializer->braced_initializer)
			{
				bool is_zero_initialized = false;
				if (p_init_declarator->initializer->braced_initializer->initializer_list == NULL)
				{
					is_zero_initialized = true;
				}
				else
				{
					if (p_init_declarator->initializer->braced_initializer->initializer_list->size == 1 &&
						p_init_declarator->initializer->braced_initializer->initializer_list->head->assignment_expression)
					{
						struct constant_value* p_constant_value =
							&p_init_declarator->initializer->braced_initializer->initializer_list->head->assignment_expression->constant_value;

						if (constant_value_is_valid(p_constant_value) &&
							constant_value_to_ull(p_constant_value) == 0)
						{
							is_zero_initialized = true;
						}

					}
				}

				if (is_zero_initialized)
				{
					set_direct_state(&p_init_declarator->p_declarator->type, &p_init_declarator->p_declarator->object, OBJECT_STATE_ZERO);
				}
				else
				{
					set_direct_state(&p_init_declarator->p_declarator->type, &p_init_declarator->p_declarator->object, OBJECT_STATE_ZERO);
				}
			}
			else
			{
				set_object(&p_init_declarator->p_declarator->type,
					&p_init_declarator->p_declarator->object,
					OBJECT_STATE_UNINITIALIZED);
			}
		}

		p_init_declarator = p_init_declarator->next;
	}



}

static void flow_visit_member_declarator(struct flow_visit_ctx* ctx, struct member_declarator* p_member_declarator)
{
	if (p_member_declarator->declarator)
	{
		flow_visit_declarator(ctx, p_member_declarator->declarator);
	}
}

static void flow_visit_member_declarator_list(struct flow_visit_ctx* ctx, struct member_declarator_list* p_member_declarator_list)
{
	struct member_declarator* p_member_declarator = p_member_declarator_list->head;
	while (p_member_declarator)
	{
		flow_visit_member_declarator(ctx, p_member_declarator);
		p_member_declarator = p_member_declarator->next;
	}
}

static void flow_visit_member_declaration(struct flow_visit_ctx* ctx, struct member_declaration* p_member_declaration)
{
	if (p_member_declaration->member_declarator_list_opt)
	{
		flow_visit_specifier_qualifier_list(ctx,
			p_member_declaration->specifier_qualifier_list,
			&p_member_declaration->member_declarator_list_opt->head->declarator->type); /*se nao tem?*/
	}

	if (p_member_declaration->member_declarator_list_opt)
	{
		flow_visit_member_declarator_list(ctx, p_member_declaration->member_declarator_list_opt);
	}
}

static void flow_visit_member_declaration_list(struct flow_visit_ctx* ctx, struct member_declaration_list* p_member_declaration_list)
{
	struct member_declaration* p_member_declaration =
		p_member_declaration_list->head;
	while (p_member_declaration)
	{
		flow_visit_member_declaration(ctx, p_member_declaration);
		p_member_declaration = p_member_declaration->next;
	}
}

static void flow_visit_attribute_specifier(struct flow_visit_ctx* ctx, struct attribute_specifier* p_attribute_specifier)
{

}

static void flow_visit_attribute_specifier_sequence(struct flow_visit_ctx* ctx, struct attribute_specifier_sequence* p_visit_attribute_specifier_sequence)
{
	struct attribute_specifier* current = p_visit_attribute_specifier_sequence->head;
	while (current)
	{
		flow_visit_attribute_specifier(ctx, current);
		current = current->next;
	}
}

static void flow_visit_struct_or_union_specifier(struct flow_visit_ctx* ctx, struct struct_or_union_specifier* p_struct_or_union_specifier)
{

	if (p_struct_or_union_specifier->attribute_specifier_sequence_opt)
		flow_visit_attribute_specifier_sequence(ctx, p_struct_or_union_specifier->attribute_specifier_sequence_opt);

	//struct struct_or_union_specifier* p_complete = get_complete_struct_or_union_specifier(p_struct_or_union_specifier);


	flow_visit_member_declaration_list(ctx, &p_struct_or_union_specifier->member_declaration_list);

}

static void flow_visit_enumerator(struct flow_visit_ctx* ctx, struct enumerator* p_enumerator)
{
	if (p_enumerator->constant_expression_opt)
		flow_visit_expression(ctx, p_enumerator->constant_expression_opt);

}

static void flow_visit_enumerator_list(struct flow_visit_ctx* ctx, struct enumerator_list* p_enumerator_list)
{
	struct enumerator* current = p_enumerator_list->head;
	while (current)
	{
		flow_visit_enumerator(ctx, current);
		current = current->next;
	}
}

static void flow_visit_enum_specifier(struct flow_visit_ctx* ctx, struct enum_specifier* p_enum_specifier)
{
	if (p_enum_specifier->attribute_specifier_sequence_opt)
	{
		flow_visit_attribute_specifier_sequence(ctx, p_enum_specifier->attribute_specifier_sequence_opt);
	}

	flow_visit_enumerator_list(ctx, &p_enum_specifier->enumerator_list);
}

static void flow_visit_typeof_specifier(struct flow_visit_ctx* ctx, struct typeof_specifier* p_typeof_specifier)
{
}

static void flow_visit_type_specifier(struct flow_visit_ctx* ctx, struct type_specifier* p_type_specifier)
{
	if (p_type_specifier->typeof_specifier)
	{
		flow_visit_typeof_specifier(ctx, p_type_specifier->typeof_specifier);
	}

	if (p_type_specifier->struct_or_union_specifier)
	{
		flow_visit_struct_or_union_specifier(ctx, p_type_specifier->struct_or_union_specifier);
	}

	if (p_type_specifier->enum_specifier)
	{
		flow_visit_enum_specifier(ctx, p_type_specifier->enum_specifier);
	}


	if (p_type_specifier->atomic_type_specifier)
	{
		//visit_deped(ctx, p_type_specifier->enum_specifier);
	}

}

static void flow_visit_type_specifier_qualifier(struct flow_visit_ctx* ctx, struct type_specifier_qualifier* p_type_specifier_qualifier)
{
	if (p_type_specifier_qualifier->type_qualifier)
	{
	}
	else if (p_type_specifier_qualifier->type_specifier)
	{
		flow_visit_type_specifier(ctx, p_type_specifier_qualifier->type_specifier);
	}
	else if (p_type_specifier_qualifier->alignment_specifier)
	{
	}
}

static void flow_visit_storage_class_specifier(struct flow_visit_ctx* ctx, struct storage_class_specifier* p_storage_class_specifier)
{
	if (p_storage_class_specifier->flags & STORAGE_SPECIFIER_AUTO)
	{

	}
}

static void flow_visit_declaration_specifier(struct flow_visit_ctx* ctx, struct declaration_specifier* p_declaration_specifier)
{

	if (p_declaration_specifier->function_specifier)
	{

	}


	if (p_declaration_specifier->storage_class_specifier)
	{
		flow_visit_storage_class_specifier(ctx, p_declaration_specifier->storage_class_specifier);

	}

	if (p_declaration_specifier->type_specifier_qualifier)
	{
		flow_visit_type_specifier_qualifier(ctx, p_declaration_specifier->type_specifier_qualifier);

	}

}

static void flow_visit_declaration_specifiers(struct flow_visit_ctx* ctx,
	struct declaration_specifiers* p_declaration_specifiers,
	struct type* p_type_opt)
{
	/*
		* Se tiver typeof ou auto vamos apagar todos type specifiers.
		* e trocar por um novo
		* const typeof(int (*)()) a;
		   //a = 1;
		  auto p = (const typeof(int (*)())) 0;

		  TODO esconder os type spefiver e qualifider , esconder auto.
		  o resto tipo static deixar.

		*/
		//

	struct declaration_specifier* p_declaration_specifier = p_declaration_specifiers->head;


	while (p_declaration_specifier)
	{
		flow_visit_declaration_specifier(ctx, p_declaration_specifier);
		p_declaration_specifier = p_declaration_specifier->next;
	}
}

/*
* retorna true se o ultimo item for um return
*/
static bool flow_is_last_item_return(struct compound_statement* p_compound_statement)
{
	if (p_compound_statement &&
		p_compound_statement->block_item_list.tail &&
		p_compound_statement->block_item_list.tail->unlabeled_statement &&
		p_compound_statement->block_item_list.tail->unlabeled_statement->jump_statement &&
		p_compound_statement->block_item_list.tail->unlabeled_statement->jump_statement->first_token &&
		p_compound_statement->block_item_list.tail->unlabeled_statement->jump_statement->first_token->type == TK_KEYWORD_RETURN)
	{
		return true;
	}
	return false;
}

void flow_visit_declaration(struct flow_visit_ctx* ctx, struct declaration* p_declaration)
{
	if (p_declaration->static_assert_declaration)
	{
		flow_visit_static_assert_declaration(ctx, p_declaration->static_assert_declaration);
	}


	if (p_declaration->p_attribute_specifier_sequence_opt)
	{
		flow_visit_attribute_specifier_sequence(ctx, p_declaration->p_attribute_specifier_sequence_opt);
	}


	if (p_declaration->declaration_specifiers)
	{
		if (p_declaration->init_declarator_list.head)
		{
			flow_visit_declaration_specifiers(ctx, p_declaration->declaration_specifiers,
				&p_declaration->init_declarator_list.head->p_declarator->type);
		}
		else
		{
			flow_visit_declaration_specifiers(ctx, p_declaration->declaration_specifiers, NULL);

		}

	}

	if (p_declaration->p_attribute_specifier_sequence_opt)
	{
	}

	if (p_declaration->init_declarator_list.head)
	{
		flow_visit_init_declarator_list(ctx, &p_declaration->init_declarator_list);
	}

	if (p_declaration->function_body)
	{

		assert(ctx->p_return_type == NULL);

		struct type type = get_function_return_type(&p_declaration->init_declarator_list.head->p_declarator->type);
		ctx->p_return_type = &type;

		//struct flow_defer_scope* p_defer = flow_visit_ctx_push_tail_block(ctx);
		//p_defer->p_statement = p_declaration->function_body;

		flow_visit_compound_statement(ctx, p_declaration->function_body);
		type_destroy(&type);
		ctx->p_return_type = NULL;

		//flow_visit_ctx_pop_tail_block(ctx);
	}

}


void flow_visit_function(struct flow_visit_ctx* ctx, struct declaration* p_declaration)
{
	assert(p_declaration->function_body);

	assert(ctx->tail_block == NULL);
	struct flow_defer_scope* p_defer = flow_visit_ctx_push_tail_block(ctx);
	p_defer->p_function_body = p_declaration->function_body;

	flow_visit_declaration(ctx, p_declaration);

	if (!flow_is_last_item_return(p_declaration->function_body))
	{
		check_defer_and_variables(ctx, p_defer, p_declaration->function_body->last_token);
	}

	flow_visit_ctx_pop_tail_block(ctx);
}

void flow_visit_ctx_destroy(struct flow_visit_ctx* obj_owner p)
{
	assert(p->tail_block == NULL);
}

void flow_analysis_visit(struct flow_visit_ctx* ctx)
{
	struct declaration* p_declaration = ctx->ast.declaration_list.head;
	while (p_declaration)
	{
		flow_visit_declaration(ctx, p_declaration);
		p_declaration = p_declaration->next;
	}
}




#ifdef _WIN32


#include <winerror.h>
//#include <winsock2.h>
#endif


const char* get_posix_error_message(int error)
{
    switch (error)
    {
    case EPERM:
        return "Operation not permitted";
    case  ENOENT:
        return "No such file or directory";
    case  ESRCH:
        return "No such process";
    case  EINTR:
        return "Interrupted system call";
    case  EIO:
        return "I/O error";
    case  ENXIO:
        return "No such device or address";
    case  E2BIG:
        return "Arg list too long";
    case  ENOEXEC:
        return "Exec string_format error";
    case  EBADF:
        return "Bad file number";
    case  ECHILD:
        return "No child processes";
    case  EAGAIN:
        return "Try again";
    case  ENOMEM:
        return "Out of memory";
    case  EACCES:
        return "Permission denied";
    case  EFAULT:
        return "Bad address";
    case  EBUSY:
        return "Device or resource busy";
    case  EEXIST:
        return "File exists";
    case  EXDEV:
        return "Cross-device link";
    case  ENODEV:
        return "No such device";
    case  ENOTDIR:
        return "Not a directory";
    case  EISDIR:
        return "Is a directory";
    case  EINVAL:
        return "Invalid argument";
    case  ENFILE:
        return "File table overflow";
    case  EMFILE:
        return "Too many open files";
    case  ENOTTY:
        return "Not a typewriter";
    case  ETXTBSY:
        return "Text file busy";
    case  EFBIG:
        return "File too large";
    case  ENOSPC:
        return "No space left on device";
    case  ESPIPE:
        return "Illegal seek";
    case  EROFS:
        return "Read-only file system";
    case  EMLINK:
        return "Too many links";
    case  EPIPE:
        return "Broken pipe";
    case  EDOM:
        return "Math argument out of domain of func";
    case  ERANGE:
        return "Math result not representable";
    case  EDEADLK:
        return "Resource deadlock would occur";
    case  ENAMETOOLONG:
        return "File name too long";
    case  ENOLCK:
        return "No record locks available";
    case  ENOSYS:
        return "Function not implemented";
    case  ENOTEMPTY:
        return "Directory not empty";
    case  ELOOP:
        return "Too many symbolic links encountered";
    //case  EWOULDBLOCK:
    //case EAGAIN:  return "Operation would block";
    case  ENOMSG:
        return "No message of desired type";
    case  EIDRM:
        return "Identifier removed";
    case  ENOSTR:
        return "Device not a stream";
    case  ENODATA:
        return "No data available";
    case  ETIME:
        return "Timer expired";
    case  ENOSR:
        return "Out of streams resources";

    case  ENOLINK:
        return "Link has been severed";
    case  EPROTO:
        return "Protocol error";
    case  EBADMSG:
        return "Not a data message";
    case  EOVERFLOW:
        return "Value too large for defined data type";
    case  EILSEQ:
        return "Illegal byte sequence";
    case  ENOTSOCK:
        return "Socket operation on non-socket";
    case  EDESTADDRREQ:
        return "Destination address required";
    case  EMSGSIZE:
        return "Message too long";
    case  EPROTOTYPE:
        return "Protocol wrong type for socket";
    case  ENOPROTOOPT:
        return "Protocol not available";
    case  EPROTONOSUPPORT:
        return "Protocol not supported";

    case  EOPNOTSUPP:
        return "Operation not supported on transport endpoint";

    case  EAFNOSUPPORT:
        return "Address family not supported by protocol";
    case  EADDRINUSE:
        return "Address already in use";
    case  EADDRNOTAVAIL:
        return "Cannot assign requested address";
    case  ENETDOWN:
        return "Network is down";
    case  ENETUNREACH:
        return "Network is unreachable";
    case  ENETRESET:
        return "Network dropped connection because of reset";
    case  ECONNABORTED:
        return "Software caused connection abort";
    case  ECONNRESET:
        return "Connection reset by peer";
    case  ENOBUFS:
        return "No buffer space available";
    case  EISCONN:
        return "Transport endpoint is already connected";
    case  ENOTCONN:
        return "Transport endpoint is not connected";

    case  ETIMEDOUT:
        return "Connection timed out";
    case  ECONNREFUSED:
        return "Connection refused";

    case  EHOSTUNREACH:
        return "No route to host";
    case  EALREADY:
        return "Operation already in progress";
    case  EINPROGRESS:
        return "Operation now in progress";
#ifndef _WIN32
    case  ENOTBLK:
        return "Block device required";
    case  ECHRNG:
        return "Channel number out of range";
    case  EL2NSYNC:
        return "Level 2 not synchronized";
    case  EL3HLT:
        return "Level 3 halted";
    case  EL3RST:
        return "Level 3 reset";
    case  ELNRNG:
        return "Link number out of range";
    case  EUNATCH:
        return "Protocol driver not attached";
    case  ENOCSI:
        return "No CSI structure available";
    case  EL2HLT:
        return "Level 2 halted";
    case  EBADE:
        return "Invalid ex   ";
    case  EBADR:
        return "Invalid request descriptor";
    case  EXFULL:
        return "Exchange full";
    case  ENOANO:
        return "No anode";
    case  EBADRQC:
        return "Invalid request code";
    case  EBADSLT:
        return "Invalid slot";

    //case  EDEADLOCK:
    //case EDEADLK:

    case  EBFONT:
        return "Bad font file string_format";
    case  ENONET:
        return "Machine is not on the network";
    case  ENOPKG:
        return "Package not installed";
    case  EREMOTE:
        return "Object is remote";

    case  EMULTIHOP:
        return "Multihop attempted";
    case  EDOTDOT:
        return "RFS specific error";
    case  EADV:
        return "Advertise error";
    case  ESRMNT:
        return "Srmount error";
    case  ECOMM:
        return "Communication error on send";
    case  ERESTART:
        return "Interrupted system call should be restarted";
    case  ESTRPIPE:
        return "Streams pipe error";
    case  EUSERS:
        return "Too many users";
    case  ENOTUNIQ:
        return "Email not unique on network";
    case  EBADFD:
        return "File descriptor in bad state";
    case  EREMCHG:
        return "Remote address changed";
    case  ELIBACC:
        return "Can not access a needed shared library";
    case  ELIBBAD:
        return "Accessing a corrupted shared library";
    case  ELIBSCN:
        return ".lib section in a.out corrupted";
    case  ELIBMAX:
        return "Attempting to link in too many shared libraries";
    case  ELIBEXEC:
        return "Cannot exec a shared library directly";
    case  ESOCKTNOSUPPORT:
        return "Socket type not supported";
    case  EPFNOSUPPORT:
        return "Protocol family not supported";
    case  EHOSTDOWN:
        return "Host is down";
    case  ESHUTDOWN:
        return "Cannot send after transport endpoint shutdown";
    case  ETOOMANYREFS:
        return "Too many references: cannot splice";
    case  ESTALE:
        return "Stale NFS file handle";
    case  EUCLEAN:
        return "Structure needs cleaning";
    case  ENOTNAM:
        return "Not a XENIX named type file";
    case  ENAVAIL:
        return "No XENIX semaphores available";
    case  EISNAM:
        return "Is a named type file";
    case  EREMOTEIO:
        return "Remote I/O error";
    case  EDQUOT:
        return "Quota exceeded";
    case  ENOMEDIUM:
        return "No medium found";
    case  EMEDIUMTYPE:
        return "Wrong medium type";
#endif
    default:
        break;

    }

    return "Unknown";
}
#ifdef _WIN32


int windows_error_to_posix(int i)
{
    switch (i)
    {
    case ERROR_ACCESS_DENIED:
        return EACCES;
    case ERROR_ALREADY_EXISTS:
        return EEXIST;
    case ERROR_BAD_UNIT:
        return ENODEV;
    case ERROR_BUFFER_OVERFLOW:
        return ENAMETOOLONG;
    case ERROR_BUSY:
        return EBUSY;
    case ERROR_BUSY_DRIVE:
        return EBUSY;
    case ERROR_CANNOT_MAKE:
        return EACCES;
    case ERROR_CANTOPEN:
        return EIO;
    case ERROR_CANTREAD:
        return EIO;
    case ERROR_CANTWRITE:
        return EIO;
    case ERROR_CURRENT_DIRECTORY:
        return EACCES;
    case ERROR_DEV_NOT_EXIST:
        return ENODEV;
    case ERROR_DEVICE_IN_USE:
        return EBUSY;
    case ERROR_DIR_NOT_EMPTY:
        return ENOTEMPTY;
    case ERROR_DIRECTORY:
        return EINVAL;
    case ERROR_DISK_FULL:
        return ENOSPC;
    case ERROR_FILE_EXISTS:
        return EEXIST;
    case ERROR_FILE_NOT_FOUND:
        return ENOENT;
    case ERROR_HANDLE_DISK_FULL:
        return ENOSPC;
    case ERROR_INVALID_ACCESS:
        return EACCES;
    case ERROR_INVALID_DRIVE:
        return ENODEV;
    case ERROR_INVALID_FUNCTION:
        return ENOSYS;
    case ERROR_INVALID_HANDLE:
        return EINVAL;
    case ERROR_INVALID_NAME:
        return EINVAL;
    case ERROR_LOCK_VIOLATION:
        return ENOLCK;
    case ERROR_LOCKED:
        return ENOLCK;
    case ERROR_NEGATIVE_SEEK:
        return EINVAL;
    case ERROR_NOACCESS:
        return EACCES;
    case ERROR_NOT_ENOUGH_MEMORY:
        return ENOMEM;
    case ERROR_NOT_READY:
        return EAGAIN;
    case ERROR_NOT_SAME_DEVICE:
        return EXDEV;
    case ERROR_OPEN_FAILED:
        return EIO;
    case ERROR_OPEN_FILES:
        return EBUSY;
    case ERROR_OPERATION_ABORTED:
        return ECANCELED;
    case ERROR_OUTOFMEMORY:
        return ENOMEM;
    case ERROR_PATH_NOT_FOUND:
        return ENOENT;
    case ERROR_READ_FAULT:
        return EIO;
    case ERROR_RETRY:
        return EAGAIN;
    case ERROR_SEEK:
        return EIO;
    case ERROR_SHARING_VIOLATION:
        return EACCES;
    case ERROR_TOO_MANY_OPEN_FILES:
        return EMFILE;
    case ERROR_WRITE_FAULT:
        return EIO;
    case ERROR_WRITE_PROTECT:
        return EACCES;
    case WSAEACCES:
        return EACCES;
    case WSAEADDRINUSE:
        return EADDRINUSE;
    case WSAEADDRNOTAVAIL:
        return EADDRNOTAVAIL;
    case WSAEAFNOSUPPORT:
        return EAFNOSUPPORT;
    case WSAEALREADY:
        return EALREADY;
    case WSAEBADF:
        return EBADF;
    case WSAECONNABORTED:
        return ECONNABORTED;
    case WSAECONNREFUSED:
        return ECONNREFUSED;
    case WSAECONNRESET:
        return ECONNRESET;
    case WSAEDESTADDRREQ:
        return EDESTADDRREQ;
    case WSAEFAULT:
        return EFAULT;
    case WSAEHOSTUNREACH:
        return EHOSTUNREACH;
    case WSAEINPROGRESS:
        return EINPROGRESS;
    case WSAEINTR:
        return EINTR;
    case WSAEINVAL:
        return EINVAL;
    case WSAEISCONN:
        return EISCONN;
    case WSAEMFILE:
        return EMFILE;
    case WSAEMSGSIZE:
        return EMSGSIZE;
    case WSAENETDOWN:
        return ENETDOWN;
    case WSAENETRESET:
        return ENETRESET;
    case WSAENETUNREACH:
        return ENETUNREACH;
    case WSAENOBUFS:
        return ENOBUFS;
    case WSAENOPROTOOPT:
        return ENOPROTOOPT;
    case WSAENOTCONN:
        return ENOTCONN;
    case WSAENOTSOCK:
        return ENOTSOCK;
    case WSAEOPNOTSUPP:
        return EOPNOTSUPP;
    case WSAEPROTONOSUPPORT:
        return EPROTONOSUPPORT;
    case WSAEPROTOTYPE:
        return EPROTOTYPE;
    case WSAETIMEDOUT:
        return ETIMEDOUT;
    case WSAEWOULDBLOCK:
        return EWOULDBLOCK;
    default:
        break;
    }
    return EPERM;
}
#endif
/*
int GetWindowsOrLinuxSocketLastErrorAsPosix(void)
{
#ifdef _WIN32
    return windows_error_to_posix(WSAGetLastError());
#else
    return errno;
#endif
}
*/






void ajust_line_and_identation(struct token* token, struct format_visit_ctx* ctx)
{
    /*
    * Before this token we must have a indentation and before indentation a new line.
    * If we don't have it we need to insert.
    */

    if (token && token->level == 0)
    {
        struct token* previous_token = token->prev;
        if (previous_token)
        {
            if (previous_token->type == TK_BLANKS)
            {
                char blanks[50] = { 0 };
                if (ctx->indentation > 0)
                    snprintf(blanks, sizeof blanks, "%*c", (ctx->indentation * 4), ' ');

                /*only adjust the number of spaces*/
                free(previous_token->lexeme);
                previous_token->lexeme = strdup(blanks);

                struct token* previous_previous_token =
                    previous_token->prev;

                if (previous_previous_token->type != TK_NEWLINE)
                {
                    struct tokenizer_ctx tctx = { 0 };
                    struct token_list list = tokenizer(&tctx, "\n", NULL, 0, TK_FLAG_NONE);
                    token_list_insert_after(&ctx->ast.token_list, previous_previous_token, &list);
                    token_list_destroy(&list);
                }
            }
            else if (previous_token->type != TK_NEWLINE)
            {
                char blanks[50] = {0};
                if (ctx->indentation > 0)
                {
                    snprintf(blanks, sizeof blanks, "\n%*c", (ctx->indentation * 4), ' ');
                }
                else
                {
                    snprintf(blanks, sizeof blanks, "\n");
                }

                struct tokenizer_ctx tctx = { 0 };
                struct token_list list = tokenizer(&tctx, blanks, NULL, 0, TK_FLAG_NONE);
                token_list_insert_after(&ctx->ast.token_list, previous_token, &list);
                token_list_destroy(&list);
            }
        }
    }
}

void ajust_if_begin(struct token* token, struct format_visit_ctx* ctx)
{
    /*
    * if we have 
      newline blancks
      then we ident
    */
    if (token && token->level == 0)
    {
        struct token* previous_token = token->prev;
        if (previous_token && previous_token->type == TK_BLANKS)
        {
            struct token* previous_previous_token =
                previous_token->prev;
            if (previous_previous_token &&
                previous_previous_token->type == TK_NEWLINE)
            {
                char blanks[50] = { 0 };
                if (ctx->indentation > 0)
                    snprintf(blanks, sizeof blanks, "%*c", (ctx->indentation * 4), ' ');

                /*only adjust the number of spaces*/
                free(previous_token->lexeme);
                previous_token->lexeme = strdup(blanks);
            }
        }
    }
}

static void format_visit_unlabeled_statement(struct format_visit_ctx* ctx, struct unlabeled_statement* p_unlabeled_statement);
static void format_visit_labeled_statement(struct format_visit_ctx* ctx, struct labeled_statement* p_labeled_statement);

static void format_visit_statement(struct format_visit_ctx* ctx, struct statement* p_statement)
{
    if (p_statement->labeled_statement)
    {
        format_visit_labeled_statement(ctx, p_statement->labeled_statement);
    }
    else if (p_statement->unlabeled_statement)
    {
        format_visit_unlabeled_statement(ctx, p_statement->unlabeled_statement);
    }
}



static void format_visit_selection_statement(struct format_visit_ctx* ctx, struct selection_statement* p_selection_statement)
{
    if (p_selection_statement->secondary_block)
    {
        ajust_line_and_identation(p_selection_statement->secondary_block->first_token, ctx);

        if (p_selection_statement->secondary_block &&
            p_selection_statement->secondary_block->statement &&
            p_selection_statement->secondary_block->statement->unlabeled_statement &&
            p_selection_statement->secondary_block->statement->unlabeled_statement->primary_block &&
            p_selection_statement->secondary_block->statement->unlabeled_statement->primary_block->compound_statement)
        {
            format_visit_statement(ctx, p_selection_statement->secondary_block->statement);
        }
        else
        {
            ajust_line_and_identation(p_selection_statement->secondary_block->first_token, ctx);

            format_visit_statement(ctx, p_selection_statement->secondary_block->statement);            
        }        
    }

    if (p_selection_statement->else_secondary_block_opt)
    {
        ajust_line_and_identation(p_selection_statement->else_token_opt, ctx);
        ajust_line_and_identation(p_selection_statement->else_secondary_block_opt->first_token, ctx);

        if (p_selection_statement->else_secondary_block_opt->statement &&
            p_selection_statement->else_secondary_block_opt->statement->unlabeled_statement &&
            p_selection_statement->else_secondary_block_opt->statement->unlabeled_statement->primary_block &&
            p_selection_statement->else_secondary_block_opt->statement->unlabeled_statement->primary_block->compound_statement)
        {
            /*compound statement*/
            format_visit_statement(ctx, p_selection_statement->else_secondary_block_opt->statement);
        }
        else
        {            
            format_visit_statement(ctx, p_selection_statement->else_secondary_block_opt->statement);         
        }
    }

}

static void format_visit_jump_statement(struct format_visit_ctx* ctx, struct jump_statement* p_jump_statement)
{



    if (p_jump_statement->first_token->type == TK_KEYWORD_THROW ||
        p_jump_statement->first_token->type == TK_KEYWORD_RETURN ||
        p_jump_statement->first_token->type == TK_KEYWORD_BREAK ||
        p_jump_statement->first_token->type == TK_KEYWORD_CONTINUE ||
        p_jump_statement->first_token->type == TK_KEYWORD_GOTO)
    {
        ajust_line_and_identation(p_jump_statement->first_token, ctx);
    }
    else
    {
        assert(false);
    }
}

static void format_visit_compound_statement(struct format_visit_ctx* ctx, struct compound_statement* p_compound_statement);


static void format_visit_secondary_block(struct format_visit_ctx* ctx, struct secondary_block* p_secondary_block)
{
    format_visit_statement(ctx, p_secondary_block->statement);
}

static void format_visit_iteration_statement(struct format_visit_ctx* ctx, struct iteration_statement* p_iteration_statement)
{
    ajust_line_and_identation(p_iteration_statement->first_token, ctx);

    if (p_iteration_statement->expression1)
    {
        //format_visit_expression(ctx, p_iteration_statement->expression1);
    }

    if (p_iteration_statement->expression2)
    {
        //format_visit_expression(ctx, p_iteration_statement->expression2);
    }

    if (p_iteration_statement->first_token->type == TK_KEYWORD_DO)
    {
        ajust_line_and_identation(p_iteration_statement->second_token, ctx);
    }

    if (p_iteration_statement->secondary_block)
    {
        format_visit_secondary_block(ctx, p_iteration_statement->secondary_block);
    }
}

static void format_visit_try_statement(struct format_visit_ctx* ctx, struct try_statement* p_try_statement)
{
    if (p_try_statement->secondary_block)
        format_visit_secondary_block(ctx, p_try_statement->secondary_block);

    if (p_try_statement->catch_secondary_block_opt)
    {
        format_visit_secondary_block(ctx, p_try_statement->catch_secondary_block_opt);
    }
}


static void format_visit_primary_block(struct format_visit_ctx* ctx, struct primary_block* p_primary_block)
{

    if (p_primary_block->compound_statement)
    {
        format_visit_compound_statement(ctx, p_primary_block->compound_statement);
    }
    else if (p_primary_block->iteration_statement)
    {
        format_visit_iteration_statement(ctx, p_primary_block->iteration_statement);
    }
    else if (p_primary_block->selection_statement)
    {
        format_visit_selection_statement(ctx, p_primary_block->selection_statement);
    }
    else if (p_primary_block->defer_statement)
    {
        //visit_defer_statement(ctx, p_primary_block->defer_statement);
    }
    else if (p_primary_block->try_statement)
    {
        format_visit_try_statement(ctx, p_primary_block->try_statement);
    }
    else
    {
        assert(false);
    }
}


static void format_visit_expression_statement(struct format_visit_ctx* ctx, struct expression_statement* p_expression_statement)
{
    if (p_expression_statement->expression_opt)
    {
        //ajust_line_and_identation(p_expression_statement->first_token, ctx);
    }
}

static void format_visit_labeled_statement(struct format_visit_ctx* ctx, struct labeled_statement* p_labeled_statement)
{
    ajust_line_and_identation(p_labeled_statement->label->name, ctx);

    if (p_labeled_statement->statement)
        format_visit_statement(ctx, p_labeled_statement->statement);
}

static void format_visit_unlabeled_statement(struct format_visit_ctx* ctx, struct unlabeled_statement* p_unlabeled_statement)
{
    if (p_unlabeled_statement->primary_block)
    {
        format_visit_primary_block(ctx, p_unlabeled_statement->primary_block);
    }
    else if (p_unlabeled_statement->expression_statement)
    {
        format_visit_expression_statement(ctx, p_unlabeled_statement->expression_statement);
    }
    else if (p_unlabeled_statement->jump_statement)
    {
        format_visit_jump_statement(ctx, p_unlabeled_statement->jump_statement);
    }
    else
    {
        assert(false);
    }
}

static void format_visit_block_item(struct format_visit_ctx* ctx, struct block_item* p_block_item)
{
    ajust_line_and_identation(p_block_item->first_token, ctx);

    if (p_block_item->declaration)
    {
        //visit_declaration(ctx, p_block_item->declaration);
    }
    else if (p_block_item->unlabeled_statement)
    {
        format_visit_unlabeled_statement(ctx, p_block_item->unlabeled_statement);
    }
    else if (p_block_item->label)
    {
        //visit_labeled_statement(ctx, p_block_item->labeled_statement);
    }
}

static void format_visit_block_item_list(struct format_visit_ctx* ctx, struct block_item_list* p_block_item_list)
{
    struct block_item* p_block_item = p_block_item_list->head;
    while (p_block_item)
    {
        format_visit_block_item(ctx, p_block_item);
        p_block_item = p_block_item->next;
    }
}

static void format_visit_compound_statement(struct format_visit_ctx* ctx, struct compound_statement* p_compound_statement)
{
    ajust_line_and_identation(p_compound_statement->first_token, ctx);

    ctx->indentation++;
    format_visit_block_item_list(ctx, &p_compound_statement->block_item_list);

    ctx->indentation++;
    /*fix comments anything that is not part of AST*/
    struct token* tk = p_compound_statement->first_token;
    while (tk)
    {
        if (tk->type == TK_LINE_COMMENT ||
            tk->type == TK_COMMENT)
        {
            ajust_if_begin(tk, ctx);
        }
        tk = tk->next;
    }
    ctx->indentation--;

    ctx->indentation--;

    ajust_line_and_identation(p_compound_statement->last_token, ctx);
}

static void format_visit_declaration(struct format_visit_ctx* ctx, struct declaration* p_declaration)
{
    if (p_declaration->static_assert_declaration)
    {
        //format_visit_static_assert_declaration(ctx, p_declaration->static_assert_declaration);
    }

    if (p_declaration->declaration_specifiers)
    {
        //format_visit_declaration_specifiers(ctx, p_declaration->declaration_specifiers);

    }

    if (p_declaration->init_declarator_list.head)
    {
        //format_visit_init_declarator_list(ctx, &p_declaration->init_declarator_list);
    }

    if (p_declaration->function_body)
    {
        format_visit_compound_statement(ctx, p_declaration->function_body);
    }
}

void format_visit(struct format_visit_ctx* ctx)
{
    struct declaration* p_declaration = ctx->ast.declaration_list.head;
    while (p_declaration)
    {
        format_visit_declaration(ctx, p_declaration);
        p_declaration = p_declaration->next;
    }
}




#ifdef TEST



static bool compile_without_errors(bool flow_analysis, bool nullchecks, const char* src)
{
	struct options options = { .input = LANGUAGE_C99, .flow_analysis = flow_analysis, .null_checks = nullchecks };
	struct report report = { 0 };
	get_ast(&options, "source", src, &report);
	return report.error_count == 0;
}

static bool compile_with_errors(bool flow_analysis, bool nullchecks, const char* src)
{

	struct options options = { .input = LANGUAGE_C99, .flow_analysis = flow_analysis, .null_checks = nullchecks };
	struct report report = { 0 };
	get_ast(&options, "source", src, &report);
	return report.error_count != 0;
}

void parser_specifier_test()
{
	const char* src = "long long long i;";
	assert(compile_with_errors(false, false, src));
}

void char_constants()
{
	const char* source
		=
		"#define TYPE_IS(e, T) _Generic(typeof(e), T : 1, default: 0)\n"
		"\n"
		"static_assert(U'ç' == 231);\n"
		"static_assert(u'ç' == 231);\n"
		"//static_assert('ç' == 231);\n"
		"\n"
		"static_assert(TYPE_IS('a', int));\n"
		"static_assert(TYPE_IS(u8'a', unsigned char));\n"
		"static_assert(TYPE_IS(u'a', unsigned short));\n"
		"static_assert(TYPE_IS(U'a', unsigned int));";

	assert(compile_without_errors(false, false, source));
}

void array_item_type_test()
{
	const char* src =
		"#define _is_same(T1, T2) _Generic(T1, T2 : 1, default: 0)\n"
		"void (*pf[10])(void* val);\n"
		"static_assert(_is_same(typeof(pf[0]), void (*)(void* val)));\n";
	assert(compile_without_errors(false, false, src));
}

void take_address_type_test()
{
	const char* src =
		"void F(char(*p)[10])"
		"{"
		"    (*p)[0] = 'a';"
		"}";
	assert(compile_without_errors(false, false, src));
}

void parser_scope_test()
{
	const char* src = "void f() {int i; char i;}";
	assert(compile_with_errors(false, false, src));
}

void parser_tag_test()
{
	//mudou tipo do tag no mesmo escopo
	const char* src = "enum E { A }; struct E { int i; };";
	assert(compile_with_errors(false, false, src));
}

void string_concatenation_test()
{
	const char* src = " const char* s = \"part1\" \"part2\";";
	assert(compile_without_errors(false, false, src));
}

void test_digit_separator()
{
	struct report report = { 0 };
	char* result = compile_source("-std=c99", "int i = 1'000;", &report);
	assert(strcmp(result, "int i = 1000;") == 0);
	free(result);
}

void test_lit()
{
	struct report report = { 0 };
	char* result = compile_source("-std=c99", "char * s = u8\"maçã\";", &report);
	assert(strcmp(result, "char * s = \"ma\\xc3\\xa7\\xc3\\xa3\";") == 0);
	free(result);
}

void type_test2()
{
	char* src =
		"#define _is_same(T1, T2) _Generic(T1, T2 : 1, default: 0)\n"
		"int a[10];\n"
		" static_assert(_is_same(typeof(&a) ,int (*)[10]));\n"
		;

	assert(compile_without_errors(false, false, src));
}

void type_test3()
{
	char* src =
		"#define _is_same(T1, T2) _Generic(T1, T2 : 1, default: 0)\n"
		"int i;"
		"int (*f)(void);"
		" static_assert(_is_same(typeof(&i), int *));"
		" static_assert(_is_same(typeof(&f), int (**)(void)));"
		;

	assert(compile_without_errors(false, false, src));
}

void crazy_decl()
{
	const char* src =
		"void (*f(int i))(void)\n"
		"{\n"
		"   i = 1; \n"
		"    return 0;\n"
		"}\n";

	assert(compile_without_errors(false, false, src));
}

void crazy_decl2()
{
	const char* src =
		"void (*f(int i))(void)\n"
		"{\n"
		"   i = 1; \n"
		"    return 0;\n"
		"}\n"
		"int main()\n"
		"{\n"
		"  f(1);\n"
		"}\n";

	assert(compile_without_errors(false, false, src));
}

void crazy_decl4()
{
	const char* src =
		"void (*F(int a, int b))(void) { return 0; }\n"
		"void (*(*PF)(int a, int b))(void) = F;\n"
		"int main() {\n"
		"    PF(1, 2);\n"
		"}\n";

	assert(compile_without_errors(false, false, src));
}

void sizeof_not_evaluated()
{
	assert(compile_without_errors(false, false, "int i = sizeof(1/0);\n"));
}

void sizeof_array_test()
{
	assert(compile_without_errors(false,
		false,
		"int main() {\n"
		"int a[] = { 1, 2, 3 };\n"
		"static_assert(sizeof(a) == sizeof(int) * 3);\n"
		"}\n"
	));
}

void sizeof_test()
{

	const char* src =
		"static_assert(sizeof(\"ABC\") == 4);"
		"char a[10];"
		"char b[10][2];"
		"static_assert(sizeof(a) == 10);"
		"static_assert(sizeof(b) == sizeof(char)*10*2);"
		"char *p[10];"
		"static_assert(sizeof(p) == 40);"
		"static_assert(sizeof(int) == 4);"
		"static_assert(sizeof(long) == 4);"
		"static_assert(sizeof(char) == 1);"
		"static_assert(sizeof(short) == 4);"
		"static_assert(sizeof(unsigned int) == 4);"
		"static_assert(sizeof(void (*pf)(int i)) == sizeof(void*));"
		;

	assert(compile_without_errors(false, false, src));
}

void alignof_test()
{
	const char* src =
		"struct X { char s; double c; char s2;};\n"
		"static_assert(alignof(struct X) == 8);"
		"static_assert(sizeof(struct X) == 24);"
		;

	assert(compile_without_errors(false, false, src));
}

void indirection_struct_size()
{
	const char* src =
		"typedef struct X X;\n"
		"struct X {\n"
		"    void* data;\n"
		"};\n"
		"static_assert(sizeof(X) == sizeof(void*));"
		;

	assert(compile_without_errors(false, false, src));
}

void traits_test()
{
	//https://en.cppreference.com/w/cpp/header/type_traits
	const char* src =
		"void (*F)();\n"
		"static_assert(_is_pointer(F));\n"
		"static_assert(_is_integral(1));\n"
		"int a[2];\n"
		"static_assert(_is_array(a));\n"
		"int((a2))[10];\n"
		"static_assert(_is_array(a2));"
		;
	assert(compile_without_errors(false, false, src));
}

void comp_error1()
{
	const char* src =
		"void F() {\n"
		"    char* z;\n"
		"    *z-- = '\\0';\n"
		"}\n";

	assert(compile_without_errors(false, false, src));
}

void array_size()
{
	const char* src =
		"void (*f[2][3])(int i);\n"
		"int main() {\n"
		"static_assert(sizeof(void (*[2])(int i)) == sizeof(void*) * 2);\n"
		"static_assert(sizeof(f) == sizeof(void (*[2])(int i)) * 3);\n"
		"}"
		;

	assert(compile_without_errors(false, false, src));
}

void expr_type()
{
	const char* src =
		"#define _is_same(T1, T2) _Generic(T1, T2 : 1, default: 0)\n"
		"static_assert(_is_same(typeof(1 + 2.0), double));";

	assert(compile_without_errors(false, false, src));
}

void expand_test()
{
	char* src =
		"#define _is_same(T1, T2) _Generic(T1, T2 : 1, default: 0)\n"
		"typedef int A[2];"
		"typedef A *B [1];"
		"static_assert(_is_same(typeof(B), int (*[1])[2]));";
	;

	assert(compile_without_errors(false, false, src));

	//https://godbolt.org/z/WbK9zP7zM
}

void expand_test2()
{

	const char* source
		=
		"\n"
		"\n"
		"typedef char* A;\n"
		"typedef const A* B; \n"
		"static_assert(_Generic(typeof(B), char * const * : 1));\n"
		"\n"
		"typedef const int T;\n"
		"T i;\n"
		"static_assert(_Generic(typeof(i), const int : 1));\n"
		"\n"
		"const T i2;\n"
		"static_assert(_Generic(typeof(i2), const int : 1));\n"
		"\n"
		"typedef  int T3;\n"
		"const T3 i3;\n"
		"static_assert(_Generic(typeof(i3), const int : 1));\n"
		"";


	assert(compile_without_errors(false, false, source));

	//https://godbolt.org/z/WbK9zP7zM
}
void expand_test3()
{


	char* src3 =
		"#define _is_same(T1, T2) _Generic(T1, T2 : 1, default: 0)\n"
		"typedef char* T1;"
		"typedef T1(*f[3])(int); "
		"static_assert(_is_same(typeof(f), char* (* [3])(int)));";

	assert(compile_without_errors(false, false, src3));

	//https://godbolt.org/z/WbK9zP7zM
}

void bigtest()
{
	const char* str =
		"\n"
		"#define _is_same(T1, T2) _Generic(T1, T2 : 1, default: 0)\n"
		"\n"
		"struct X { int i; };\n"
		"\n"
		"struct Y { double d;};\n"
		"\n"
		"enum E { A = 1 };\n"
		"enum E e1;\n"
		"\n"
		"struct X* F() { return 0; }\n"
		"\n"
		"int main()\n"
		"{\n"
		"    enum E { B } e2;\n"
		"    static_assert(_is_same(typeof(e2), enum E));\n"
		"\n"
		"    static_assert(!_is_same(typeof(e2), typeof(e1)));\n"
		"\n"
		"\n"
		"    struct X x;\n"
		"    struct Y y;\n"
		"\n"
		"    static_assert(_is_same(typeof(x), struct X));\n"
		"    static_assert(!_is_same(typeof(x), struct Y));\n"
		"\n"
		"    static_assert(!_is_same(int(double), int()));\n"
		"\n"
		"    int aa[10];\n"
		"\n"
		"    static_assert(_is_same(typeof(*F()), struct X));\n"
		"    static_assert(_is_same(typeof(&aa), int(*)[10]));\n"
		"\n"
		"    int* p = 0;\n"
		"    static_assert(_is_same(typeof(*(p + 1)), int));\n"
		"\n"
		"    static_assert(_is_same(typeof(1), int));\n"
		"\n"
		"    static_assert(_is_same(typeof(main), int()));\n"
		"\n"
		"\n"
		"    static_assert(!_is_same(typeof(main), int(double)));\n"
		"    static_assert(!_is_same(typeof(main), int));\n"
		"\n"
		"\n"
		"    struct X x2;\n"
		"    enum E e;\n"
		"    static_assert(_is_same(typeof(e), enum E));\n"
		"    static_assert(_is_same(typeof(x2), struct X));\n"
		"    static_assert(!_is_same(typeof(e), struct X));\n"
		"\n"
		"\n"
		"\n"
		"    static_assert(_is_same(typeof(1L), long));\n"
		"    static_assert(_is_same(typeof(1UL) , unsigned long));\n"
		"    static_assert(_is_same(typeof(1ULL), unsigned long long));\n"
		"    \n"
		"    //static_assert(_is_same(typeof(A), int));\n"
		"\n"
		"    static_assert(_is_same(typeof(1.0), double));\n"
		"    static_assert(_is_same(typeof(1.0f), float));\n"
		"    static_assert(_is_same(typeof(1.0L), long double));\n"
		"    \n"
		"    \n"
		"    static_assert(_is_same(typeof(((int*)0) + 1), int*));\n"
		"    static_assert(_is_same(typeof(*(((int*)0) + 1)), int));\n"
		"\n"
		"}\n"
		"\n"
		"\n"
		;
	assert(compile_without_errors(false, false, str));
}

void literal_string_type()
{
	const char* source =
		"#define _is_same(T1, T2) _Generic(T1, T2 : 1, default: 0)\n"
		"    static_assert(_is_same(typeof(\"A\"),  char [2]));\n"
		"    static_assert(_is_same(typeof(\"AB\"),  char [3]));\n"
		;

	assert(compile_without_errors(false, false, source));
}

void digit_separator_test()
{
	const char* source =
		"static_assert(1'00'00 == 10000);"
		;

	assert(compile_without_errors(false, false, source));
}

void numbers_test()
{
	const char* source =
		"#if 0xA1 == 161\n"
		"_Static_assert(0xA1 == 161); \n"
		"#endif"
		;

	assert(compile_without_errors(false, false, source));
}

void binary_digits_test()
{
	const char* source =
		"_Static_assert(0b101010 == 42);"
		"_Static_assert(0b1010'10 == 42);"
		"_Static_assert(052 == 42);"
		;

	assert(compile_without_errors(false, false, source));
}

void type_suffix_test()
{
	const char* source =
		"\n"
		"#define _is_same(T1, T2) _Generic(T1, T2 : 1, default: 0)\n"
		"\n"
		"static_assert(_is_same(typeof(1), int));\n"
		"static_assert(_is_same(typeof(1L), long));\n"
		"static_assert(_is_same(typeof(1LL), long long));\n"
		"static_assert(_is_same(typeof(1U), unsigned int));\n"
		"static_assert(_is_same(typeof(1ULL), unsigned long long));\n"
		"static_assert(_is_same(typeof(1), int));\n"
		"static_assert(_is_same(typeof(1l), long));\n"
		"static_assert(_is_same(typeof(1ll), long long) );\n"
		"static_assert(_is_same(typeof(1u), unsigned int));\n"
		"static_assert(_is_same(typeof(1ull), unsigned long long));\n"
		"static_assert(_is_same(typeof(0x1), int));\n"
		"static_assert(_is_same(typeof(0x1L), long));\n"
		"static_assert(_is_same(typeof(0x1LL), long long));\n"
		"static_assert(_is_same(typeof(0x1U), unsigned int));\n"
		"static_assert(_is_same(typeof(0x1ULL), unsigned long long));  \n"
		"static_assert(_is_same(typeof(0x1), int));\n"
		"static_assert(_is_same(typeof(0x1l), long));\n"
		"static_assert(_is_same(typeof(0x1ll), long long));\n"
		"static_assert(_is_same(typeof(0x1u), unsigned int));\n"
		"static_assert(_is_same(typeof(0x1ull), unsigned long long));\n"
		"static_assert(_is_same(typeof(0b1), int));\n"
		"static_assert(_is_same(typeof(0b1L), long));\n"
		"static_assert(_is_same(typeof(0b1LL), long long));\n"
		"static_assert(_is_same(typeof(0b1U), unsigned int));\n"
		"static_assert(_is_same(typeof(0b1ULL), unsigned long long));\n"
		"static_assert(_is_same(typeof(0b1l), long));\n"
		"static_assert(_is_same(typeof(0b1ll), long long));\n"
		"static_assert(_is_same(typeof(0b1ul), unsigned long));\n"
		"static_assert(_is_same(typeof(0b1ull), unsigned long long));\n"
		"static_assert(_is_same(typeof(1.0f), float));\n"
		"static_assert(_is_same(typeof(1.0), double));\n"
		"static_assert(_is_same(typeof(1.0L), long double));\n"
		;


	assert(compile_without_errors(false, false, source));
}

void type_test()
{
	const char* source =
		"#define _is_same(T1, T2) _Generic(T1, T2 : 1, default: 0)\n"
		"int * p = 0;"
		"static_assert(_is_same( typeof( *(p + 1) ), int)   );"
		;

	assert(compile_without_errors(false, false, source));
}

void is_pointer_test()
{
	const char* source =
		"#define _is_same(T1, T2) _Generic(T1, T2 : 1, default: 0)\n"
		"\n"
		"int main()\n"
		"{\n"
		"  int i;\n"
		"  static_assert(_is_integral(i));\n"
		"  static_assert(_is_floating_point(double) && _is_floating_point(float));\n"
		"  static_assert(_is_function(main));\n"
		"\n"
		"  char * p;\n"
		"  static_assert(_is_scalar(p));\n"
		"  static_assert(_is_scalar(nullptr));\n"
		"\n"
		"  int a[10];\n"
		"  static_assert(_is_array(a));\n"
		"\n"
		"  /*pf = pointer to function (void) returning array 10 of int*/\n"
		"  int (*pf)(void)[10];\n"
		"  static_assert(!_is_array(pf));\n"
		"  static_assert(_is_pointer(pf));\n"
		"\n"
		"  static_assert(_is_same(int, typeof(i)));\n"
		"\n"
		"  static_assert(_is_const(const int));\n"
		"  static_assert(!_is_const(const int*));\n"
		"  static_assert(_is_const(int* const));\n"
		"\n"
		"}\n"
		;
	assert(compile_without_errors(false, false, source));
}

void params_test()
{
	const char* source =
		"void f1();"
		"void f2(void);"
		"void f3(char * s, ...);"
		"int main()"
		"{"
		"  f1();"
		"  f2();"
		"  f3(\"\");"
		"  f3(\"\", 1, 2, 3);"
		"}"
		;

	assert(compile_without_errors(false, false, source));
}

void test_compiler_constant_expression()
{
	const char* source =
		"int main()"
		"{"
		"  static_assert('ab' == 'a'*256+'b');\n"
		"  static_assert(sizeof(char)  == 1);\n"
		"  static_assert(true == 1);\n"
		"  static_assert(false == 0);\n"
		"}"
		;

	assert(compile_without_errors(false, false, source));
}

void zerodiv()
{
	const char* source =
		"int main()"
		"{"
		"  int a = 2/0;\n"
		"}"
		;

	assert(compile_with_errors(false, false, source));
}

void function_result_test()
{
	const char* source =
		"int (*(*F1)(void))(int, int*);\n"
		"int (* F2(void) )(int, int*);\n"
		"static_assert(_Generic(F1(), int (*)(int, int*) : 1));\n"
		"static_assert(_Generic(F2(), int (*)(int, int*) : 1));\n"
		;

	assert(compile_without_errors(false, false, source));
}

void type_normalization()
{
	const char* source =
		"char ((a1));\n"
		"char b1;\n"
		"static_assert((typeof(a1)) == (typeof(b1)));\n"
		"\n"
		"char ((a2))[2];\n"
		"char b2[2];\n"
		"static_assert((typeof(a2)) == (typeof(b2)));\n"
		"\n"
		"char ((a3))(int (a));\n"
		"char (b3)(int a);\n"
		"static_assert((typeof(a3)) == (typeof(b3)));\n"
		;


	assert(compile_without_errors(false, false, source));
}

void auto_test()
{
	const char* source =
		"#define _is_same(T1, T2) _Generic(T1, T2 : 1, default: 0)\n"
		"    int main()\n"
		"    {\n"
		"        double const x = 78.9;\n"
		"        double y = 78.9;\n"
		"        auto q = x;\n"
		"        static_assert( (typeof(q)) == (double));\n"
		"        auto const p = &x;\n"
		"        static_assert( (typeof(p)) == (const double  * const));\n"
		"        auto const r = &y;\n"
		"        static_assert( (typeof(r)) == (double  * const));\n"
		"        auto s = \"test\";\n"
		"        static_assert(_is_same(typeof(s), char *));\n"
		"    }\n"
		;

	assert(compile_without_errors(false, false, source));

}

void visit_test_auto_typeof()
{
	const char* source = "auto p2 = (typeof(int[2])*) 0;";

	struct report report = { 0 };
	char* result = compile_source("-std=c99", source, &report);
	assert(strcmp(result, "int  (* p2)[2] = (int(*)[2]) 0;") == 0);
	free(result);
}

void enum_scope()
{
	const char* source =
		"enum E { A = 1 };\n"
		"int main()\n"
		"{\n"
		"  enum E { B } e2; \n"
		"  static_assert( (typeof(e2)), (enum E) ); \n"
		"}\n";
	assert(compile_without_errors(false, false, source));
}

void const_member()
{
	const char* source
		=
		"struct X {\n"
		"  int i;\n"
		"};\n"
		"void f() {\n"
		"  const struct X x = {0};\n"
		"  x.i = 1;\n" //error x.i is constant
		"}\n"
		"";


	struct options options = { .input = LANGUAGE_C99 };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 &&
		report.last_error == C_ASSIGNMENT_OF_READ_ONLY_OBJECT);
}

void register_struct_member()
{
	const char* source
		=
		"struct X {\n"
		"    int i;\n"
		"};\n"
		"\n"
		"int main() {\n"
		"  register struct X x = {0};\n"
		"  int * p = &x.i;\n" //error: address of register variable 'x' requested
		"}\n"
		"";
	struct options options = { .input = LANGUAGE_C99, .flow_analysis = true };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1);
}

void address_of_const()
{
	const char* source =
		"const int i;\n"
		"static_assert(_Generic(&i, const int * : 1 ));\n"
		"\n"
		"const int * const p;\n"
		"static_assert(_Generic(&p, const int *  const * : 1 ));\n"
		"";

	assert(compile_without_errors(false, false, source));
}

void lvalue_test()
{
	//https://en.cppreference.com/w/c/language/value_category

	const char* source
		=
		"//https://en.cppreference.com/w/c/language/value_category\n"
		"\n"
		"struct X\n"
		"{\n"
		"	int i;\n"
		"};\n"
		"\n"
		"struct X f() { struct X x = {0};  return x; }\n"
		"\n"
		"const int i;\n"
		"static_assert(_Generic(&i, const int* : 1));\n"
		"\n"
		"const int* const p;\n"
		"static_assert(_Generic(&p, const int* const* : 1));\n"
		"\n"
		"\n"
		"int main() {\n"
		"	static_assert(!_is_lvalue(1));\n"
		"	static_assert(_is_lvalue(\"a\"));\n"
		"	static_assert(_is_lvalue((int) { 0 }));\n"
		"\n"
		"	int a;\n"
		"	static_assert(_is_lvalue(a));\n"
		"	static_assert(_is_lvalue((a)));\n"
		"\n"
		"	enum  E { A };\n"
		"	static_assert(!_is_lvalue(A));\n"
		"\n"
		"\n"
		"	struct X x = {0};\n"
		"	static_assert(_is_lvalue(x.i));\n"
		"\n"
		"	struct X *px = 0;\n"
		"	static_assert(_is_lvalue(px->i));\n"
		"\n"
		"	//== Non-lvalue object expressions ==\n"
		"	// \n"
		"	//integer, character, and floating constants \n"
		"	static_assert(!_is_lvalue(1));\n"
		"	static_assert(!_is_lvalue(1.2));\n"
		"	static_assert(!_is_lvalue('a'));\n"
		"\n"
		"	//any function call expression\n"
		"	static_assert(!_is_lvalue(f()));\n"
		"	\n"
		"	//any cast expression\n"
		"	static_assert(!_is_lvalue((int)(0)));\n"
		"\n"
		"	//member access operator (dot) applied to a non-lvalue structure/union\n"
		"	static_assert(!_is_lvalue(f().i));\n"
		"	\n"
		"	//results of all arithmetic, relational, logical, and bitwise operators\n"
		"	static_assert(!_is_lvalue(1 + 2));\n"
		"	static_assert(!_is_lvalue(1 && 2));\n"
		"	static_assert(!_is_lvalue(~1));\n"
		"\n"
		"	//results of increment and decrement operators \n"
		"	static_assert(!_is_lvalue(a++));\n"
		"	\n"
		"	//results of assignment operators\n"
		"\n"
		"	//the conditional operator\n"
		"	static_assert(!_is_lvalue(a ? a : a));\n"
		"\n"
		"	//the comma operator\n"
		"	static_assert(!_is_lvalue(a , a)); \n"
		"	\n"
		"	//the address-of operator, even if neutralized by application to the result of unary * operator \n"
		"	static_assert(!_is_lvalue(&a));\n"
		"\n"
		"}\n"
		"";
	;


	assert(compile_without_errors(false, false, source));
}

void simple_no_discard_test()
{
	const char* source
		=
		"[[nodiscard]] int destroy();\n"
		"\n"
		"int main()\n"
		"{\n"
		"  destroy();\n"
		"}\n"
		"";

	struct options options = { .input = LANGUAGE_C99, .enabled_warnings_stack[0] = (~0 & ~W_STYLE) };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.warnings_count == 1 && report.last_warning == W_ATTRIBUTES);
}

void simple_no_discard_test2()
{
	const char* source
		=
		"[[nodiscard]] int destroy();\n"
		"\n"
		"int main()\n"
		"{\n"
		"  int i;\n"
		"  i = destroy();\n"
		"}\n"
		"";


	struct options options = { .input = LANGUAGE_C99, .enabled_warnings_stack[0] = (~0 & ~W_STYLE) };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.warnings_count == 0 && report.error_count == 0);
}

void address_of_register()
{
	const char* source
		=
		"struct X\n"
		"{\n"
		"    int i;\n"
		"};\n"
		"\n"
		"void f()\n"
		"{\n"
		"  register struct X x;\n"
		"  &x;\n"
		"}\n"
		"";
	struct options options = { .input = LANGUAGE_C99, .enabled_warnings_stack[0] = (~0 & ~W_STYLE) };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.last_error == C_ADDRESS_OF_REGISTER);
}

void return_address_of_local()
{
	const char* source
		=
		"struct X\n"
		"{\n"
		"    int i;\n"
		"};\n"
		"\n"
		"int* f()\n"
		"{\n"
		"  struct X x;\n"
		"  return &x.i;\n"
		"}\n"
		"";
	struct options options = { .input = LANGUAGE_C99, .enabled_warnings_stack[0] = (~0 & ~W_STYLE) };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.warnings_count == 1 && report.last_warning == W_RETURN_LOCAL_ADDR);
}

void return_address_of_local2()
{
	const char* source
		=
		"\n"
		"char* f() {\n"
		"    char str[] = \".\";\n"
		"    return str;\n"
		"}\n"
		;

	struct options options = { .input = LANGUAGE_C99, .enabled_warnings_stack[0] = (~0 & ~W_STYLE) };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.warnings_count == 1 && report.last_warning == W_RETURN_LOCAL_ADDR);
}

void assignment_of_read_only_object()
{
	const char* source
		=
		"struct X\n"
		"{\n"
		"    int i;\n"
		"};\n"
		"\n"
		"int* f()\n"
		"{\n"
		"  const struct X * p;\n"
		"  p->i = 1;\n"
		"}\n";

	struct options options = { .input = LANGUAGE_C99, .enabled_warnings_stack[0] = (~0 & ~W_STYLE) };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.last_error == C_ASSIGNMENT_OF_READ_ONLY_OBJECT);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////     OWNER /////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

void simple_move()
{
	const char* source
		=
		"char * _Owner f() {\n"
		"    char * _Owner p = 0;\n"
		"    return p; /*implicit move*/\n"
		"}";
	assert(compile_without_errors(true, false, source));
}

void simple_move_error()
{
	const char* source
		=
		"char * f() {\n"
		"    char * _Owner p = 0;\n"
		"    return p; \n"
		"}";

	struct options options = { .input = LANGUAGE_C99 };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 &&
		report.last_error == C_OWNERSHIP_MOVE_ASSIGNMENT_OF_NON_OWNER);
}

void parameter_view()
{
	const char* source
		=
		"\n"
		"struct X { char  * _Owner owner_variable;   };\n"
		"char * f(struct X *parameter) \n"
		"{\n"
		"    return parameter->owner_variable;\n"  //ok to move from parameter
		"}\n";

	assert(compile_without_errors(true, false, source));
}

void move_from_extern()
{
	const char* source
		=
		"struct X { char  * _Owner owner_variable;   };\n"
		"struct X global;\n"
		"char * f() \n"
		"{\n"
		"    return global.owner_variable;\n" /*makes a _View*/
		"}\n";

	assert(compile_without_errors(true, false, source));
}

void owner_type_test()
{
	const char* source
		=
		"\n"
		"struct Y { \n"
		"    char  * _Owner owner_variable;   \n"
		"    char  * non_owner_variable;   \n"
		"};\n"
		"\n"
		"struct X { \n"
		"    char  * _Owner owner_variable;   \n"
		"    char  * non_owner_variable;   \n"
		"    struct Y y1;\n"
		"    _View struct Y y2;\n"
		"};\n"
		"\n"
		"void f()\n"
		"{\n"
		"    struct X x;\n"
		"    \n"
		"    static_assert(_is_owner(typeof(x)));\n"
		"    static_assert(_is_owner(typeof(x.owner_variable)));\n"
		"    static_assert(!_is_owner(typeof(x.non_owner_variable)));\n"
		"    static_assert(_is_owner(struct X));\n"
		"    static_assert(_is_owner(typeof(x.y1)));\n"
		"    static_assert(!_is_owner(typeof(x.y2)));\n"
		"    \n"
		"    static_assert(_is_owner(typeof(x.y1.owner_variable)));\n"
		"    static_assert(!_is_owner(typeof(x.y1.non_owner_variable)));\n"
		"\n"
		"    static_assert(!_is_owner(typeof(x.y2.owner_variable)));\n"
		"    static_assert(!_is_owner(typeof(x.y2.non_owner_variable)));\n"
		"\n"
		"    _View struct X x2;\n"
		"    static_assert(!_is_owner(typeof(x2)));\n"
		"    static_assert(!_is_owner(typeof(x2.owner_variable)));\n"
		"    static_assert(!_is_owner(typeof(x2.non_owner_variable)));\n"
		"\n"
		"    _Owner char * p;\n"
		"    static_assert(!_is_owner(typeof(p)));\n"
		"    static_assert(_is_owner(typeof(*p)));    \n"
		"}\n";

	assert(compile_without_errors(true, false, source));
}

void correct_move_assigment()
{
	const char* source
		=
		"\n"
		"struct Y { \n"
		"    int i;\n"
		"};\n"
		"\n"
		"struct X { \n"
		"    char * _Owner name;\n"
		"};\n"
		"\n"
		"int main()\n"
		"{\n"
		"    struct Y y1 = {};\n"
		"    struct Y y2 = {};\n"
		"    y1 = y2; //ok\n"
		"\n"
		"    struct X x1 = {};\n"
		"    struct X x2 = {};\n"
		"    x1 = x2; //ok\n"
		"\n"
		"}";
	assert(compile_without_errors(true, false, source));
}

void no_explicit_move_required()
{
	const char* source
		=
		"char * _Owner create();\n"
		"void f(char * _Owner p);\n"
		"\n"
		"int main()\n"
		"{\n"
		"    f(create());\n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));

}

void no_explicit_move_with_function_result()
{
	const char* source
		=
		"void destroy(char* _Owner x);\n"
		"char   * _Owner  get();\n"
		"\n"
		"int main()\n"
		"{\n"
		"  destroy(get());\n"
		"}\n";

	assert(compile_without_errors(true, false, source));
}

void cannot_ignore_owner_result()
{
	const char* source
		=
		"struct X {\n"
		"  char * _Owner name;\n"
		"};\n"
		"\n"
		"struct X f();\n"
		"\n"
		"int main()\n"
		"{\n"
		"  f();\n"
		"}\n";

	struct options options = { .input = LANGUAGE_C99, .enabled_warnings_stack[0] = (~0 & ~W_STYLE) };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.warnings_count == 1);
}

void can_ignore_owner_result()
{
	const char* source
		=
		"struct X {\n"
		"  char * _Owner name;\n"
		"};\n"
		"\n"
		"_View struct X f();\n"
		"\n"
		"int main()\n"
		"{\n"
		"  f();\n"
		"}\n";

	assert(compile_without_errors(true, false, source));
}

void move_not_necessary_on_return()
{
	const char* source
		=
		"struct X {\n"
		"  char * _Owner name;\n"
		"};\n"
		"\n"
		"struct X f();\n"
		"struct X f2()\n"
		"{\n"
		"    return f();\n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void explicit_move_not_required()
{
	const char* source
		=
		"#define NULL ((void*)0)\n"
		"\n"
		"int main()\n"
		"{\n"
		"    const char * _Owner s;\n"
		"    s = NULL;    \n"
		"    s = 0;    \n"
		"    s = nullptr;    \n"
		"}\n"
		;
	assert(compile_without_errors(true, false, source));
}

void error_using_temporary_owner()
{
	const char* source
		=
		"\n"
		"void F(int i);\n"
		"_Owner int make();\n"
		"int main()\n"
		"{\n"
		"    F(make());\n"
		"}";
	struct options options = { .input = LANGUAGE_C99, .enabled_warnings_stack[0] = (~0 & ~W_STYLE) };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.last_error == C_OWNERSHIP_USING_TEMPORARY_OWNER);

}

void passing_view_to_owner()
{
	const char* source
		=
		"void destroy(_Owner int i);\n"
		"\n"
		"int main()\n"
		"{\n"
		"  _Owner int i = 0;\n"
		"  int v = i;\n"
		"  destroy(v);\n"
		"}\n"
		"";
	struct options options = { .input = LANGUAGE_C99, .enabled_warnings_stack[0] = (~0 & ~W_STYLE) };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.last_error == C_OWNERSHIP_MOVE_ASSIGNMENT_OF_NON_OWNER);
}

void obj_owner_cannot_be_used_in_non_pointer()
{
	const char* source
		=
		"void f() {\n"
		"    _Obj_owner int i;\n"
		"}\n"
		;
	struct options options = { .input = LANGUAGE_C99, .enabled_warnings_stack[0] = (~0 & ~W_STYLE) };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.last_error == C_OBJ_OWNER_CAN_BE_USED_ONLY_IN_POINTER);

}

void ownership_flow_test_null_ptr_at_end_of_scope()
{
	const char* source
		=
		"void f() {\n"
		"    _Owner int * p = 0;\n"
		"}\n"
		" ";
	assert(compile_without_errors(true, false, source));
}

void ownership_flow_test_pointer_must_be_deleted()
{
	const char* source
		=
		"\n"
		"int* _Owner  get();\n"
		"\n"
		"void f() {\n"
		"    int * _Owner p = 0;\n"
		"    p = get();\n"
		"}\n"
		" ";
	struct options options = { .input = LANGUAGE_C2X, .flow_analysis = true };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.last_error == C_OWNERSHIP_FLOW_MISSING_DTOR);
}

void ownership_flow_test_basic_pointer_check()
{
	const char* source
		=
		"\n"
		"int* _Owner  get();\n"
		"void dtor(int* _Owner p);\n"
		"\n"
		"void f(int a)\n"
		"{\n"
		"    int* _Owner p = 0;\n"
		"    p = get();    \n"
		"    dtor(p);    \n"
		"}\n"
		"";

	assert(compile_without_errors(true, false, source));
}

void ownership_flow_test_struct_member_missing_free()
{
	const char* source
		=
		"\n"
		"char * _Owner strdup(const char* s);\n"
		"void free(void* _Owner p);\n"
		"\n"
		"struct X {\n"
		"  char * _Owner text;\n"
		"};\n"
		"\n"
		"void f(int a)\n"
		"{\n"
		"    struct X x = {0};\n"
		"    x.text = strdup(\"a\");\n"
		"}\n"
		"";
	struct options options = { .input = LANGUAGE_C2X, .flow_analysis = true };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.last_error == C_OWNERSHIP_FLOW_MISSING_DTOR);
	////TODO return ROOT object!

}

void ownership_flow_test_struct_member_free()
{
	const char* source
		=
		"\n"
		"char * _Owner strdup(const char* s);\n"
		"void free(void* _Owner p);\n"
		"\n"
		"struct X {\n"
		"  char * _Owner text;\n"
		"};\n"
		"\n"
		"void f(int a)\n"
		"{\n"
		"    struct X x = {0};\n"
		"    x.text = strdup(\"a\");\n"
		"    free(x.text);\n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));

}

void ownership_flow_test_move_inside_if()
{
	const char* source
		=
		"void free( void* _Owner ptr);\n"
		"void* _Owner malloc(int size);\n"
		"\n"
		"void f(int c) \n"
		"{\n"
		"    int * _Owner p = malloc(sizeof (int));    \n"
		"    if (c) {\n"
		"      free(p);\n"
		"    }\n"
		"}\n"
		"";
	struct options options = { .input = LANGUAGE_C2X, .flow_analysis = true };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1);
}

void ownership_flow_test_goto_same_scope()
{
	const char* source
		=
		"void free( void* _Owner ptr);\n"
		"void* _Owner malloc(int size);\n"
		"\n"
		"void f(int condition) \n"
		"{\n"
		"    int * _Owner p = malloc(sizeof(int));\n"
		"  \n"
		"    if (condition)\n"
		"       goto end;\n"
		"  end:\n"
		"    free(p);\n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void ownership_flow_test_jump_labels()
{
	const char* source
		=
		"void free( void* _Owner ptr);\n"
		"void* _Owner malloc(int size);\n"
		"\n"
		"void f(int condition)\n"
		"{\n"
		"    int* _Owner p = malloc(sizeof(int));\n"
		"\n"
		"    if (condition)\n"
		"        goto end;\n"
		"\n"
		"    free(p);\n"
		"end:\n"
		"\n"
		"}\n"
		"";
	struct options options = { .input = LANGUAGE_C2X, .flow_analysis = true };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.last_error == C_OWNERSHIP_FLOW_MISSING_DTOR);
}

void ownership_flow_test_owner_if_pattern_1()
{
	const char* source
		=
		"\n"
		"void free( void* _Owner ptr);\n"
		"void* _Owner malloc(int size);\n"
		"\n"
		"int main()\n"
		"{\n"
		"    int* _Owner p = malloc(sizeof(int));\n"
		"    if (p)\n"
		"    {\n"
		"       free(p);     \n"
		"    }\n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void ownership_flow_test_owner_if_pattern_2()
{
	const char* source
		=
		"\n"
		"void free( void* _Owner ptr);\n"
		"void* _Owner malloc(int size);\n"
		"\n"
		"int main()\n"
		"{\n"
		"    int* _Owner p = malloc(sizeof(int));\n"
		"    if (p != 0)\n"
		"    {\n"
		"       free(p);     \n"
		"    }\n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void ownership_flow_test_missing_destructor()
{
	const char* source
		=
		"struct X {\n"
		"  _Owner i;\n"
		"};\n"
		"void f() {\n"
		"  const struct X x = {0};\n"
		"}\n"
		"";


	struct options options = { .input = LANGUAGE_C99, .flow_analysis = true };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.last_error == C_OWNERSHIP_FLOW_MISSING_DTOR);

}

void ownership_flow_test_no_warning()
{
	const char* source
		=
		"void free( void * _Owner p);\n"
		"struct X {\n"
		"  char * _Owner text;\n"
		"};\n"
		"void x_delete( struct X * _Owner p)\n"
		"{\n"
		"    if (p)\n"
		"    {\n"
		"      free(p->text);\n"
		"      free(p);\n"
		"    }\n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void ownership_flow_test_moved_if_not_null()
{
	const char* source
		=
		"void * _Owner malloc(int i);\n"
		"void free( void * _Owner p);\n"
		"\n"
		"struct X { int i; };\n"
		"struct Y { struct X * _Owner p; };\n"
		"\n"
		"int main() {\n"
		"   struct Y y = {0};\n"
		"   struct X * _Owner p = malloc(sizeof(struct X));\n"
		"   if (p){\n"
		"     y.p = p;\n"
		"   }\n"
		"  free(y.p);\n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void ownership_flow_test_struct_moved()
{
	const char* source
		=
		"void free( void * _Owner p);\n"
		"\n"
		"struct X {\n"
		"  char * _Owner name;\n"
		"};\n"
		"\n"
		"void x_destroy( struct X * _Obj_owner p);\n"
		"\n"
		"struct Y {\n"
		"  struct X x;\n"
		"};\n"
		"\n"
		"void y_destroy(struct Y * _Obj_owner p) {\n"
		"   x_destroy(&p->x);\n"
		"}\n"
		;
	assert(compile_without_errors(true, false, source));
}

void ownership_flow_test_scope_error()
{
	const char* source
		=
		"void * _Owner malloc(int i);\n"
		"void free( void* _Owner p);\n"
		"\n"
		"int main() {\n"
		"    try\n"
		"    {\n"
		"         if (1)\n"
		"         {\n"
		"             char * _Owner s = malloc(1);\n"
		"             free(s);\n"
		"         }\n"
		"         else\n"
		"         {\n"
		"            throw;\n"
		"         }\n"
		"    }\n"
		"    catch\n"
		"    {\n"
		"    }\n"
		"}";
	assert(compile_without_errors(true, false, source));
}


void ownership_flow_test_void_destroy()
{
	/*TODO moving to void* requires object is moved before*/
	const char* source
		=
		"void * _Owner malloc(int i);\n"
		"void free( void * _Owner p);\n"
		"\n"
		"struct X {\n"
		"  char * _Owner name;    \n"
		"};\n"
		"\n"
		"int main() {\n"
		"   struct X * _Owner p = malloc(sizeof * p);\n"
		"   free(p);   \n"
		"} \n"
		;

	assert(compile_without_errors(true, false, source));
}

void ownership_flow_test_void_destroy_ok()
{
	/*TODO moving to void* requires object is moved before*/
	const char* source
		=
		"void * _Owner malloc(int i);\n"
		"void free( void * _Owner p);\n"
		"\n"
		"struct X {\n"
		"  char * _Owner name;    \n"
		"};\n"
		"\n"
		"int main() {\n"
		"   struct X * _Owner p = malloc(sizeof * p);\n"
		"   p->name = malloc(10);\n"
		"   free(p->name);\n"
		"   free(p);   \n"
		"} \n"
		;
	assert(compile_without_errors(true, false, source));
}

void ownership_flow_test_moving_owner_pointer()
{
	const char* source
		=
		"\n"
		"void * _Owner malloc(int i);\n"
		"void free( void * _Owner p);\n"
		"\n"
		"struct X {\n"
		"  char * _Owner name;    \n"
		"};\n"
		"\n"
		"void x_delete( struct X * _Owner p)\n"
		"{\n"
		"  if (p) {\n"
		"      free(p->name);\n"
		"      free(p);\n"
		"  }\n"
		"}\n"
		"\n"
		"int main() {\n"
		"   struct X * _Owner p = malloc(sizeof * p);   \n"
		"   x_delete(p);      \n"
		"} \n"
		"";
	assert(compile_with_errors(true, false, source));
}

void ownership_flow_test_moving_owner_pointer_missing()
{
	const char* source
		=
		"\n"
		"void * _Owner malloc(int i);\n"
		"void free( void * _Owner p);\n"
		"\n"
		"struct X {\n"
		"  char * _Owner name;    \n"
		"};\n"
		"\n"
		"void x_delete( struct X * _Owner p)\n"
		"{\n"
		"  if (p) {\n"
		"      //free(p->name);\n"
		"      free(p);\n"
		"  }\n"
		"}\n"
		"\n"
		"";
	struct options options = { .input = LANGUAGE_C99, .flow_analysis = true };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.warnings_count == 0);
}

void ownership_flow_test_error()
{
	const char* source
		=
		"\n"
		"void* _Owner malloc(int size);\n"
		"\n"
		"struct X {    \n"
		"    char * _Owner name;\n"
		"};\n"
		"\n"
		"void * _Owner f1(){\n"
		"  struct X * _Owner p = malloc(sizeof (struct X));\n"
		"  p->name = malloc(1);  \n"
		"  return p;\n"
		"}\n"
		"";

	struct options options = { .input = LANGUAGE_C99, .flow_analysis = true };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.warnings_count == 0);
}

void ownership_flow_test_setting_owner_pointer_to_null()
{
	const char* source
		=
		"\n"
		"void * _Owner malloc(int i);\n"
		"void free( void * _Owner p);\n"
		"\n"
		"struct X {\n"
		"  char * _Owner name;    \n"
		"};\n"
		"\n"
		"int main() {\n"
		"   struct X * _Owner p = malloc(sizeof * p);   \n"
		"   p = 0;\n"
		"} \n"
		"";
	struct options options = { .input = LANGUAGE_C99, .flow_analysis = true };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.warnings_count == 0);
}

void ownership_flow_test_while_not_null()
{
	const char* source
		=
		"struct item  {\n"
		"    struct item * _Owner next;\n"
		"};\n"
		"void item_delete( struct item * _Owner p);\n"
		"\n"
		"struct list {\n"
		"    struct item * _Owner head;\n"
		"    struct item * tail;\n"
		"};\n"
		"int main()\n"
		"{\n"
		"    struct list list = {0};\n"
		"    struct item * _Owner p = list.head;\n"
		"    while (p){\n"
		"      struct item * _Owner next = p->next;\n"
		"      p->next = 0;\n"
		"      item_delete(p);\n"
		"      p = next;\n"
		"  }  \n"
		"}";
	assert(compile_without_errors(true, false, source));
}

void ownership_flow_test_if_state()
{
	const char* source
		=
		"\n"
		"int* _Owner make();\n"
		"void free(int * _Owner p);\n"
		"\n"
		"\n"
		"void f(int condition)\n"
		"{\n"
		"  int * _Owner p = 0;\n"
		"  static_state(p, \"null\");\n"
		"  \n"
		"  if (condition)\n"
		"  {\n"
		"       static_state(p, \"null\");   \n"
		"       p = make();\n"
		"       static_state(p, \"maybe-null\");\n"
		"  }\n"
		"  else\n"
		"  {\n"
		"    static_state(p, \"null\");\n"
		"  }\n"
		"  free(p);\n"
		"}\n"
		"\n"
		"";

	assert(compile_without_errors(true, false, source));
}

void ownership_types_test_error_owner()
{
	const char* source
		=
		"void * f();\n"
		"int main() {\n"
		"   void * _Owner p = f();   \n"
		"}\n"
		;
	struct options options = { .input = LANGUAGE_C99 };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.warnings_count == 0);
}

void ownership_flow_test_if_variant()
{
	const char* source
		=
		"void * _Owner f();\n"
		"void free( void *_Owner p);\n"
		"int main() {\n"
		"   void * _Owner p = f();   \n"
		"   if (p)\n"
		"   {\n"
		"       free(p);\n"
		"       p = f();   \n"
		"   }\n"
		"}\n"
		"";


	struct options options = { .input = LANGUAGE_C99, .flow_analysis = true };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.warnings_count == 0);
}

void check_leaks_on_else_block()
{
	const char* source
		=
		"void * _Owner malloc(int sz);\n"
		"\n"
		"void f(int i) {   \n"
		"        if (i){\n"
		"        }   \n"
		"        else {\n"
		"            int * _Owner p3 = malloc(1);\n"
		"        }\n"
		"}\n"
		;

	struct options options = { .input = LANGUAGE_C99, .flow_analysis = true };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1 && report.warnings_count == 0);
}

void ownership_flow_test_two_ifs()
{
	const char* source
		=
		"void * _Owner malloc(int sz);\n"
		"void free( void * _Owner opt p);\n"
		"\n"
		"\n"
		"void f(int i) {   \n"
		"    void * _Owner p = 0;\n"
		"    if (i)\n"
		"    {\n"
		"        if (i)\n"
		"        {\n"
		"            p =  malloc(1);\n"
		"        }\n"
		"        else\n"
		"        {\n"
		"            p = malloc(1);\n"
		"        }     \n"
		"    }\n"
		"    \n"
		"    free(p);\n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));

}

void ownership_no_name_parameter()
{
	const char* source
		=
		"void free( void * _Owner){ }\n"
		"";

	assert(compile_with_errors(true, false, source));
}

void ownership_flow_switch_case()
{
	const char* source
		=
		"void* _Owner make();\n"
		"void free( void* _Owner p);\n"
		"\n"
		"void f(condition)\n"
		"{\n"
		"    void* _Owner p = make();\n"
		"\n"
		"\n"
		"    switch (condition)\n"
		"    {\n"
		"        case 1:\n"
		"        {\n"
		"            free(p);\n"
		"        }\n"
		"        break;\n"
		"        case 2:\n"
		"        {\n"
		"            free(p);\n"
		"        }\n"
		"        break;\n"
		"\n"
		"        default:\n"
		"            free(p);\n"
		"            break;\n"
		"    }        \n"
		"}";
	assert(compile_without_errors(true, false, source));
}

void state_inner_objects_preserved()
{
	const char* source
		=
		"void *_Owner malloc(int i);\n"
		"void free(void  *_Owner);\n"
		"\n"
		"struct X{\n"
		"  char * _Owner name;\n"
		"};\n"
		"\n"
		"int main()\n"
		"{\n"
		"    struct X * _Owner p = malloc(sizeof(struct X));    \n"
		"    if (p)\n"
		"    {\n"
		"        p->name = malloc(1);\n"
		"    }\n"
		"    else \n"
		"    {        \n"
		"        p->name = malloc(1);\n"
		"    }\n"
		"    free(p->name);\n"
		"    free(p);\n"
		"}";
	assert(compile_without_errors(true, false, source));
}

//TODO make test with
// f(void (*pf)(void* _Owner p)){}
// 
void owner_parameter_must_be_ignored()
{
	const char* source = "void f(void (*pf)(void* _Owner p)){}";
	assert(compile_without_errors(true, false, source));
}

void taking_address()
{
	const char* source
		=
		"struct X {\n"
		"  void * _Owner text;\n"
		"};\n"
		"\n"
		"void x_change(struct X* list);\n"
		"void x_destroy(struct X* _Obj_owner p);\n"
		"\n"
		"int main()\n"
		"{\n"
		"  struct X x = {};\n"
		"  static_debug(x);\n"
		"  x_change(&x);\n"
		"  //list_destroy(&list);\n"
		"}\n"
		"";
	struct options options = { .input = LANGUAGE_C99, .flow_analysis = true };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 1);
}

void taking_address_const()
{
	const char* source
		=
		"struct X {\n"
		"  void * _Owner text;\n"
		"};\n"
		"\n"
		"void f(const struct X* list);\n"
		"\n"
		"int main()\n"
		"{\n"
		"  struct X x = {};\n"
		"  f(&x);\n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void pointer_argument()
{
	const char* source
		=
		"void * _Owner malloc(int i);\n"
		"\n"
		"struct X {\n"
		"  void * _Owner text;\n"
		"};\n"
		"\n"
		"void x_change( struct X* list);\n"
		"\n"
		"int main()\n"
		"{\n"
		"  struct X * _Owner x = malloc(sizeof * x);\n"
		"  x_change(x);\n"
		"}\n"
		"";
	struct options options = { .input = LANGUAGE_C99, .flow_analysis = true };
	struct report report = { 0 };
	get_ast(&options, "source", source, &report);
	assert(report.error_count == 3);
}

void do_while()
{
	const char* source
		=
		"\n"
		"void* _Owner malloc(unsigned size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"int main() {\n"
		"   void * _Owner p = malloc(1);\n"
		"   do{\n"
		"      free(p);\n"
		"   }\n"
		"   while(0);   \n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void switch_cases_state()
{
	const char* source
		=
		"void* _Owner malloc(unsigned size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"void* _Owner f(int i)\n"
		"{\n"
		"    void* _Owner p = malloc(1);\n"
		"    switch (i)\n"
		"    {\n"
		"        case 1:\n"
		"            break;\n"
		"        case 2:\n"
		"            break;\n"
		"    }\n"
		"\n"
		"    return p;\n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void switch_break()
{
	const char* source
		=
		"void * _Owner malloc(int i);\n"
		"\n"
		"void* _Owner f(int i)\n"
		"{\n"
		"    void* _Owner p = malloc(1);        \n"
		"    switch (i) {\n"
		"        case 1: break;\n"
		"    }\n"
		"    return p;\n"
		"}";
	assert(compile_without_errors(true, false, source));
}

void passing_non_owner()
{
	/*
	  We need to analuse better this case...

	*/
	const char* source
		=
		"struct X { \n"
		"    char * _Owner p;\n"
		"};\n"
		"void x_destroy(struct X * _Obj_owner p);\n"
		"void f(struct X* x)\n"
		"{\n"
		"    x_destroy(x);        \n"
		"}\n"
		"";

	assert(compile_with_errors(true, false, source));
}

void flow_analysis_else()
{
	const char* source

		=
		"void * _Owner malloc(int i);\n"
		"void free(void * _Owner p);\n"
		"\n"
		"int main() {\n"
		"    int * _Owner p1 = 0;\n"
		"    int * _Owner p2 = malloc(1);\n"
		"\n"
		"    if (p2 == 0) {\n"
		"        return 1;\n"
		"    }\n"
		"    else\n"
		"    {\n"
		"      p1 = p2;\n"
		"    }\n"
		"    static_state(p2, \"moved\");\n"
		"    free(p1);\n"
		"    return 0;\n"
		"}";

	"}";

	assert(compile_without_errors(true, false, source));
}
void moving_content_of_owner()
{
	const char* source
		=
		"\n"
		"void* _Owner malloc(unsigned size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"\n"
		"struct X {  char *_Owner name; };\n"
		"struct Y { struct X x; };\n"
		"\n"
		"void f(struct Y * y, struct X * _Obj_owner p) \n"
		"{\n"
		"    free(y->x.name);\n"
		"    y->x = *p;\n"
		"}\n"
		;
	assert(compile_without_errors(true, false, source));
}

void switch_scope()
{
	const char* source
		=
		"\n"
		"void* _Owner calloc(unsigned n, unsigned size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"struct X {\n"
		"    char* _Owner name;\n"
		"};\n"
		"\n"
		"struct X* _Owner F(int i)\n"
		"{\n"
		"    struct X* _Owner p1 = 0;\n"
		"\n"
		"    switch (i)\n"
		"    {\n"
		"        case 1:\n"
		"            struct X* _Owner p2 = calloc(1, sizeof * p2);\n"
		"            if (p2)\n"
		"            {\n"
		"              static_set(*p2, \"zero\");\n"
		"                p1 = p2;\n"
		"            }\n"
		"            break;\n"
		"        case 2:\n"
		"            break;\n"
		"    }\n"
		"\n"
		"    return p1;\n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void swith_and_while()
{
	const char* source
		=
		"\n"
		"void* _Owner malloc(unsigned size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"struct X {\n"
		"    char* _Owner name;\n"
		"};\n"
		"\n"
		"struct X* _Owner F(int i)\n"
		"{\n"
		"\n"
		"    struct X* _Owner p1 = 0;\n"
		"    try\n"
		"    {\n"
		"        if (i == 1)\n"
		"        {\n"
		"            p1 = malloc(sizeof * p1);            \n"
		"            while (0){}            \n"
		"        }\n"
		"        else if (i == 3)\n"
		"        {\n"
		"            p1 = malloc(sizeof * p1);\n"
		"        }\n"
		"    }\n"
		"    catch\n"
		"    {\n"
		"    }\n"
		"\n"
		"    return p1;\n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void owner_to_non_owner()
{
	const char* source
		=
		"void * f();\n"
		"int main() {\n"
		"  void * _Owner p = f();\n"
		"}";

	assert(compile_with_errors(true, false, source));
}

void owner_to_non_owner_zero()
{
	const char* source
		=
		"void * f();\n"
		"int main() {\n"
		"  void * _Owner p = 0;\n"
		"}";

	assert(compile_without_errors(true, false, source));
}

void incomplete_struct()
{
	const char* source
		=
		"void free(void * _Owner p);\n"
		"struct X;\n"
		"struct X f();\n"
		"struct X { char * _Owner p; };\n"
		"int main()\n"
		"{\n"
		"    struct X x = 1 ? f() : f(); \n"
		"    free(x.p);\n"
		"}";
	assert(compile_without_errors(true, false, source));

}

void switch_pop_problem()
{
	const char* source
		=
		"\n"
		"void* _Owner malloc(unsigned size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"\n"
		"void f(int i)\n"
		"{\n"
		"  void * _Owner p1 = malloc(1);\n"
		"  switch(i)\n"
		"  {\n"
		"      case 1:\n"
		"      {\n"
		"          void * _Owner p2 = malloc(1);\n"
		"          free(p2);\n"
		"      }\n"
		"      break;\n"
		"\n"
		"      case 2:\n"
		"      {\n"
		"          void * _Owner p3 = malloc(1);\n"
		"            free(p3);\n"
		"      }\n"
		"      break;\n"
		"  }\n"
		"\n"
		"  free(p1);\n"
		"  \n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void switch_pop2()
{
	const char* source
		=
		"\n"
		"void* _Owner malloc(unsigned size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"\n"
		"void f(int i)\n"
		"{\n"
		"    void* _Owner p1 = malloc(1);\n"
		"    switch (i)\n"
		"    {\n"
		"        case 1:\n"
		"            void* _Owner p2 = malloc(1);\n"
		"            free(p2);\n"
		"            break;\n"
		"\n"
		"        case 3:\n"
		"            void* _Owner p3 = malloc(1);\n"
		"            free(p3);\n"
		"            break;\n"
		"    }\n"
		"\n"
		"    free(p1);\n"
		"\n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void scopes_pop()
{
	const char* source
		=
		"\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"struct X { char* _Owner name; };\n"
		"\n"
		"void x_destroy(struct X* _Obj_owner p);\n"
		"struct X f();\n"
		"\n"
		"void f()\n"
		"{\n"
		"    {\n"
		"        struct X x = {0};   \n"
		"        \n"
		"        if (1)\n"
		"        {            \n"
		"            x = f();\n"
		"        }\n"
		"        else\n"
		"        {         \n"
		"            x = f();\n"
		"        }\n"
		"        x_destroy(&x);\n"
		"    }\n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}
void owner_moved()
{
	const char* source
		=
		"void free( void* _Owner ptr);\n"
		"void* _Owner malloc(int size);\n"
		"struct X { char * _Owner text; };\n"
		"\n"
		"void x_destroy(struct X* _Obj_owner p)\n"
		"{\n"
		"    free(p->text);\n"
		"}\n"
		"\n"
		"void x_delete(struct X* _Owner p)\n"
		"{\n"
		"    if (p)\n"
		"    {\n"
		"        x_destroy(p);\n"
		"        free(p);\n"
		"    }\n"
		"}";
	assert(compile_without_errors(true, false, source));

}

void partially_owner_moved()
{
	const char* source
		=
		"void free( void* _Owner ptr);\n"
		"void* _Owner malloc(int size);\n"
		"struct X { char * _Owner text; };\n"
		"\n"
		"void x_destroy(struct X* _Obj_owner p)\n"
		"{\n"
		"    free(p->text);\n"
		"}\n"
		"\n"
		"void x_delete(struct X* _Owner p)\n"
		"{\n"
		"    if (p)\n"
		"    {\n"
		"        x_destroy(p);\n"
		"    }\n"
		"}";
	assert(compile_with_errors(true, false, source));

}
void use_after_destroy()
{
	const char* source
		=
		"\n"
		"char* _Owner strdup(const char* s);\n"
		"void* _Owner malloc(unsigned size);\n"
		"void free(void* _Owner ptr);"
		"\n"
		"struct X {\n"
		"  char *_Owner name;\n"
		"};\n"
		"\n"
		"void x_destroy(struct X * _Obj_owner p) {\n"
		"  free(p->name);\n"
		"}\n"
		"\n"
		"void x_print(struct X * p) \n"
		"{\n"
		"  //printf(\"%s\", p->name);\n"
		"}\n"
		"\n"
		"int main() {\n"
		"   struct X x = {0};\n"
		"   x.name = strdup(\"a\");\n"
		"   x_destroy(&x);\n"
		"   x_print(&x);\n"
		"}\n"
		"";
	assert(compile_with_errors(true, false, source));

}

void obj_owner_must_be_from_addressof()
{
	const char* source
		=
		"void free(void* _Owner ptr);\n"
		"void* _Owner malloc(int size);\n"
		"char * _Owner strdup(const char* );\n"
		"\n"
		"struct X {\n"
		"  char *_Owner name;\n"
		"};\n"
		"\n"
		"struct Y {\n"
		"  struct X x;\n"
		"  struct X * px;\n"
		"};\n"
		"\n"
		"void x_destroy(struct X * _Obj_owner p) \n"
		"{\n"
		"  free(p->name);\n"
		"}\n"
		"\n"
		"void f(struct Y * p)\n"
		"{    \n"
		"    x_destroy(p->px);\n"
		"}\n"
		"\n"
		"int main() {\n"
		"   struct Y  y = {};   \n"
		"   struct * p = &y.x;\n"
		"   x_destroy(&y.x);\n"
		"}\n"
		"\n"
		"";
	assert(compile_with_errors(true, false, source));
}

void discarding_owner()
{
	const char* source
		=
		"void* _Owner malloc(unsigned long size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"struct X {\n"
		"  char *_Owner name;\n"
		"};\n"
		"\n"
		"int main()\n"
		"{  \n"
		"  struct X * p = (struct X * _Owner) malloc(1);\n"
		"}";
	assert(compile_with_errors(true, false, source));
}

void using_uninitialized()
{
	const char* source
		=
		"void* _Owner malloc(unsigned long size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"struct X {\n"
		"  char * _Owner text;\n"
		"};\n"
		"\n"
		"void x_delete(struct X * _Owner  p);\n"
		"\n"
		"int main() {   \n"
		"   struct X * _Owner p = malloc(sizeof(struct X));      \n"
		"   x_delete(p); /*uninitialized*/\n"
		"}\n"
		"\n"
		"";
	assert(compile_with_errors(true, false, source));
}

void using_uninitialized_struct()
{
	const char* source
		=
		"struct X {\n"
		"  char * _Owner text;\n"
		"};\n"
		"\n"
		"void x_destroy(struct X * _Obj_owner p);\n"
		"\n"
		"\n"
		"int main() {   \n"
		"   struct X x;\n"
		"   x_destroy(&x);\n"
		"}\n"
		"\n"
		"";

	assert(compile_with_errors(true, false, source));
}

void zero_initialized()
{
	const char* source
		=
		"struct Y {\n"
		"  char * _Owner p0;\n"
		"  int * _Owner p2;\n"
		"  double i2;\n"
		"};\n"
		"\n"
		"struct X {\n"
		"  char * _Owner text;\n"
		"  int * _Owner p1;\n"
		"  int i;\n"
		"  struct Y  *pY;\n"
		"};\n"
		"\n"
		"int main() {   \n"
		"   struct X x = {0};   \n"
		"   static_state(x.text, \"null\");\n"
		"   static_state(x.p1, \"null\");\n"
		"   static_state(x.i, \"zero\");\n"
		"   static_state(x.pY, \"null\");\n"
		"   static_state(x.pY->p0, \"\");\n"
		"   static_state(x.pY->p2, \"\");\n"
		"   static_state(x.pY->i2, \"\");\n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));
}


void empty_initialized()
{
	const char* source
		=
		"struct Y {\n"
		"  char * _Owner p0;\n"
		"  int * _Owner p2;\n"
		"  double i2;\n"
		"};\n"
		"\n"
		"struct X {\n"
		"  char * _Owner text;\n"
		"  int * _Owner p1;\n"
		"  int i;\n"
		"  struct Y  *pY;\n"
		"};\n"
		"\n"
		"int main() {   \n"
		"   struct X x = {};   \n"
		"   static_state(x.text, \"null\");\n"
		"   static_state(x.p1, \"null\");\n"
		"   static_state(x.i, \"zero\");\n"
		"   static_state(x.pY, \"null\");\n"
		"   static_state(x.pY->p0, \"\");\n"
		"   static_state(x.pY->p2, \"\");\n"
		"   static_state(x.pY->i2, \"\");\n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void calloc_state()
{
	const char* source
		=
		"\n"
		"void* _Owner calloc(unsigned long n , unsigned long size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"struct Y {\n"
		"  char * _Owner p0;\n"
		"  int * _Owner p2;\n"
		"  double i2;\n"
		"};\n"
		"\n"
		"struct X {\n"
		"  char * _Owner text;\n"
		"  int * _Owner p1;\n"
		"  int i;\n"
		"  struct Y  *pY;\n"
		"};\n"
		"\n"
		"int main() {   \n"
		"   struct X * _Owner x = calloc(1,sizeof * x);\n"
		"   static_state(x, \"maybe-null\");\n"
		"\n"
		"   static_state(x->p1, \"null\");\n"
		"   static_state(x->i, \"zero\");\n"
		"   static_state(x->pY, \"null\");\n"
		"   static_state(x->pY->p0, \"uninitialized\");\n"
		"   static_state(x->pY->p2, \"uninitialized\");\n"
		"   static_state(x->pY->i2, \"uninitialized\");   \n"
		"   free(x);\n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void malloc_initialization()
{
	const char* source
		=
		"\n"
		"void* _Owner malloc(unsigned long size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"struct Y {\n"
		"  char * _Owner p0;\n"
		"  int * _Owner p2;\n"
		"  double i2;\n"
		"};\n"
		"\n"
		"struct X {\n"
		"  char * _Owner text;\n"
		"  int * _Owner p1;\n"
		"  int i;\n"
		"  struct Y  *pY;\n"
		"};\n"
		"\n"
		"int main() {   \n"
		"   struct X * _Owner x = malloc(sizeof * x);\n"
		"   static_state(x, \"maybe-null\");\n"
		"\n"
		"   static_state(x->p1, \"uninitialized\");\n"
		"   static_state(x->i, \"uninitialized\");\n"
		"   static_state(x->pY, \"uninitialized\");\n"
		"   static_state(x->pY->p0, \"\");\n"
		"   static_state(x->pY->p2, \"\");\n"
		"   static_state(x->pY->i2, \"\");   \n"
		"   free(x);\n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void valid_but_unkown_result()
{
	const char* source
		=
		"\n"
		"void* _Owner malloc(unsigned long size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"struct Y {\n"
		"  char * _Owner p0;\n"
		"  int * _Owner p2;\n"
		"  double i2;\n"
		"};\n"
		"\n"
		"struct X {\n"
		"  char * _Owner text;\n"
		"  int * _Owner p1;\n"
		"  int i;\n"
		"  struct Y  *pY;\n"
		"};\n"
		"\n"
		"struct X f();\n"
		"\n"
		"int main() {   \n"
		"   struct X x;\n"
		"   x = f();\n"
		"\n"
		"   static_state(x.p1, \"maybe-null\");\n"
		"   static_state(x.i, \"any\");\n"
		"   static_state(x.pY, \"maybe-null\");\n"
		"   static_state(x.pY->p0, \"maybe-null\");\n"
		"   static_state(x.pY->p2, \"maybe-null\");\n"
		"   static_state(x.pY->i2, \"any\");   \n"
		"   free(x);\n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void calling_non_const_func()
{
	const char* source
		=
		"\n"
		"void* _Owner malloc(unsigned long size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"struct Y {\n"
		"  char * _Owner p0;\n"
		"  int * _Owner p2;\n"
		"  double i2;\n"
		"};\n"
		"\n"
		"struct X {\n"
		"  char * _Owner text;\n"
		"  int * _Owner p1;\n"
		"  int i;\n"
		"  struct Y  *pY;\n"
		"};\n"
		"\n"
		"void init(struct X * p);\n"
		"\n"
		"int main() {   \n"
		"   struct X x;\n"
		"   /*lying here, to avoid error of using uninitialized*/\n"
		"   static_set(x,\"zero\");\n"
		"   init(&x);\n"
		"\n"
		"   static_state(x.p1, \"maybe-null\");\n"
		"   static_state(x.i, \"any\");\n"
		"   static_state(x.pY, \"maybe-null\");\n"
		"   static_state(x.pY->p0, \"maybe-null\");\n"
		"   static_state(x.pY->p2, \"maybe-null\");\n"
		"   static_state(x.pY->i2, \"any\");   \n"
		"   free(x);\n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));
}
void calling_const_func()
{
	const char* source
		=
		"void* _Owner malloc(unsigned long size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"struct Y {\n"
		"    char* _Owner p0;\n"
		"    int* _Owner p2;\n"
		"    double i2;\n"
		"};\n"
		"\n"
		"struct X {\n"
		"    char* _Owner text;\n"
		"    int* _Owner p1;\n"
		"    int i;\n"
		"    struct Y* pY;\n"
		"};\n"
		"\n"
		"void f(const struct X* p);\n"
		"\n"
		"int main()\n"
		"{\n"
		"    struct X x = {0};\n"
		"    f(&x);\n"
		"\n"
		"    static_state(x.p1, \"null\");\n"
		"    static_state(x.i, \"zero\");\n"
		"    static_state(x.pY, \"null\");\n"
		"    static_state(x.pY->p0, \"\");\n"
		"    static_state(x.pY->p2, \"\");\n"
		"    static_state(x.pY->i2, \"\");\n"
		"\n"
		"    free(x);\n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));
}
void pointer_to_owner()
{
	const char* source
		=
		"\n"
		"void* _Owner malloc(unsigned long size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"struct X {\n"
		"  char * _Owner text;\n"
		"};\n"
		"\n"
		"void f(struct X * _Owner p1, struct X * _Owner* p2){\n"
		"  *p2 = p1;\n"
		"}\n"
		"\n"
		"int main() {   \n"
		"   struct X * _Owner p1 = malloc(sizeof * p1);\n"
		"   p1->text = 0;\n"
		"   struct X * _Owner p2 = 0;\n"
		"   f(p1, &p2);\n"
		"   \n"
		"   free(p2->text);\n"
		"   free(p2);\n"
		"}\n"
		"\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void socket_sample()
{
	const char* source
		=
		"_Owner int socket();\n"
		"void close(_Owner int fd);\n"
		"\n"
		"int main()\n"
		"{\n"
		"  _Owner int fd;\n"
		"  \n"
		"  fd = socket();\n"
		"  if (fd < 0)\n"
		"  {\n"
		"     static_set(fd, \"null\");   \n"
		"     return 1;\n"
		"  }\n"
		"  close(fd);\n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void return_object()
{
	const char* source
		=
		"char * _Owner strdup(const char* s);\n"
		"void free(void * _Owner p);\n"
		"\n"
		"struct X {\n"
		"  char *_Owner name;\n"
		"};\n"
		"\n"
		"struct X make()\n"
		"{\n"
		"  struct X x = {0};\n"
		"  x.name = strdup(\"text\");  \n"
		"  return x;\n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}
void return_bad_object()
{
	const char* source
		=
		"char * _Owner strdup(const char* s);\n"
		"void free(void * _Owner p);\n"
		"\n"
		"struct X {\n"
		"  char *_Owner name;\n"
		"};\n"
		"\n"
		"struct X make()\n"
		"{\n"
		"  struct X x = {0};\n"
		"  x.name = strdup(\"text\");  \n"
		"  free(x.name)\n"
		"  return x;\n"
		"}\n"
		"";
	assert(compile_with_errors(true, false, source));
}

void null_to_owner()
{
	const char* source
		=
		"\n"
		"void f(int * _Owner p);\n"
		"int main()\n"
		"{\n"
		"   int * _Owner p = 0;\n"
		"   p = ((void *) 0); \n"
		"   f(0);\n"
		"   f((void *) 0);\n"
		"   f(nullptr);\n"
		"}\n";
	assert(compile_without_errors(true, false, source));
}

void return_true_branch()
{

	const char* source
		=
		"void* _Owner malloc(unsigned long size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"void f5()\n"
		"{\n"
		"    void * _Owner p = malloc(1);\n"
		"    \n"
		"    if (p) {\n"
		"       free(p);\n"
		"       return;\n"
		"    }\n"
		"    \n"
		"    static_state(p, \"null\");    \n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}
void flow_tests()
{
	const char* source
		=
		"\n"
		"\n"
		"void* _Owner malloc(unsigned long size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"void f1()\n"
		"{\n"
		"    void * _Owner p = malloc(1);\n"
		"    if (p) {\n"
		"      static_state(p, \"not-null\");\n"
		"    }\n"
		"\n"
		"    static_state(p, \"maybe-null\");\n"
		"    free(p);\n"
		"}\n"
		"\n"
		"void f2(int condition)\n"
		"{\n"
		"    void * _Owner p = malloc(1);\n"
		"    if (condition) {\n"
		"      static_state(p, \"maybe-null\");\n"
		"    }\n"
		"\n"
		"    static_state(p, \"maybe-null\");\n"
		"    static_set(p, \"null\");\n"
		"}\n"
		"\n"
		"void f3(int condition)\n"
		"{\n"
		"    void * _Owner p = malloc(1);\n"
		"    \n"
		"    if (condition) {\n"
		"       free(p);\n"
		"    }\n"
		"    else {\n"
		"       free(p);\n"
		"    }\n"
		"\n"
		"    static_state(p, \"uninitialized\");    \n"
		"}\n"
		"\n"
		"void f3(int condition)\n"
		"{\n"
		"    void * _Owner p = malloc(1);\n"
		"    \n"
		"    if (condition) {\n"
		"       \n"
		"    }\n"
		"    else {\n"
		"       free(p);\n"
		"    }\n"
		"\n"
		"    static_state(p, \"uninitialized or maybe_null\");    \n"
		"    static_set(p, \"null\");\n"
		"}\n"
		"\n"
		"\n"
		"void f4(int condition)\n"
		"{\n"
		"    void * _Owner p = malloc(1);\n"
		"    \n"
		"    if (condition) {\n"
		"       free(p);\n"
		"    }\n"
		"    else {\n"
		"       \n"
		"    }\n"
		"\n"
		"    static_state(p, \"uninitialized or maybe_null\");   \n"
		"    static_set(p, \"null\");\n"
		"}\n"
		"\n"
		"void f5(int condition)\n"
		"{\n"
		"    void * _Owner p = malloc(1);\n"
		"    \n"
		"    if (p) {\n"
		"       free(p);\n"
		"       return;\n"
		"    }\n"
		"    \n"
		"    static_state(p, \"null\");    \n"
		"}\n"
		"\n"
		"";
	assert(compile_without_errors(true, false, source));
}

void member()
{
	const char* source
		=
		"struct X {\n"
		"  union {\n"
		"    struct {\n"
		"      int *pSelect;\n"
		"    } view;\n"
		"  }u;\n"
		"};\n"
		"\n"
		"int main()\n"
		"{\n"
		"    struct X t;\n"
		"    t.u.view.pSelect = 0;\n"
		"}\n"
		"";
	assert(compile_without_errors(true, false, source));
}
void loop_leak()
{
	const char* source
		=
		"void* _Owner malloc(unsigned long size);\n"
		"void free(void* _Owner ptr);\n"
		"\n"
		"int main() {\n"
		"   void * _Owner p = 0;\n"
		"   for (int i=0; i < 2; i++) {\n"
		"     p = malloc(1);\n"
		"   }\n"
		"   free(p);\n"
		"}";
	assert(compile_with_errors(true, false, source));
}

void out_parameter()
{
	const char* source
		=
		"void  free(void* _Owner p);\n"
		"char* _Owner strdup(const char* s);\n"
		"\n"
		"struct X {\n"
		"    char* _Owner s;\n"
		"};\n"
		"void init(_Out struct X *  px)\n"
		"{\n"
		"    static_state(px, \"maybe-null\");\n"
		"    static_state(px->s, \"uninitialized\");\n"
		"    px->s = strdup(\"a\");\n"
		"}\n"
		"\n"
		"int main() {\n"
		"    struct X x;\n"
		"    init(&x);\n"
		"    free(x.s);\n"
		"}";

	assert(compile_without_errors(true, false, source));
}

void lvalue_required_1()
{
	const char* source
		=
		"int main()\n"
		"{\n"
		" 1++;\n"
		"}\n"
		"";
	assert(compile_with_errors(true, false, source));
}

void lvalue_required_2()
{
	const char* source
		=
		"int main()\n"
		"{\n"
		" 1--;\n"
		"}\n"
		"";
	assert(compile_with_errors(true, false, source));
}

void lvalue_required_3()
{
	const char* source
		=
		"int main()\n"
		"{\n"
		" int * p = &1;\n"
		"}\n"
		"";
	assert(compile_with_errors(true, false, source));
}
void lvalue_required_4()
{
	const char* source
		=
		"struct X { int i; };\n"
		"struct X f() {\n"
		"    struct X x = {};\n"
		"    return x;\n"
		"}\n"
		"int main() {\n"
		"    f().i = 1;\n"
		"}\n"
		"\n"
		"";
	assert(compile_with_errors(true, false, source));
}


void null_check_1()
{
	const char* source
		=
		"void f(int  *p)\n"
		"{\n"
		" static_state(p, \"not-null\");\n"
		"}\n"
		"";
	assert(compile_without_errors(true, true, source));
}

void null_check_2()
{
	const char* source
		=
		"void f(int  *p)\n"
		"{\n"
		" static_state(p, \"maybe-null\");\n"
		"}\n"
		"";
	assert(compile_without_errors(true, false /*nullcheck disabled*/, source));
}

void compound_literal_object()
{
	const char* source
		=
		"struct X { int i; void* p; }\n"
		"int main() {\n"
		"	struct X x;\n"
		"	x = (struct X){ 0 };\n"
		"	static_state(x.i, \"zero\");\n"
		"	static_state(x.p, \"null\");\n"
		"}";
	assert(compile_without_errors(true, false /*nullcheck disabled*/, source));
}

void bounds_check1()
{
	const char* source
		=
		"int main() {\n"
		"	int a[5];\n"
		"	int i = a[5];\n"
		"}";
	assert(compile_with_errors(true, false /*nullcheck disabled*/, source));
}

void bounds_check2()
{
	const char* source
		=
		"void f1(int array[5])\n"
		"{\n"
		"    int i = array[5];\n"
		"}\n"
		"";

	assert(compile_with_errors(true, false /*nullcheck disabled*/, source));
}

void uninitialized_objects_passed_to_variadic_function()
{
	const char* source
		=
		"void f(char* s, ...);\n"
		"int main() {\n"
		"   int i;\n"
		"   f(\"\", i);\n"
		"   return 0;\n"
		"}";
	assert(compile_with_errors(true, false /*nullcheck disabled*/, source));
}


#endif


