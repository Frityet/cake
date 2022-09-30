﻿var sample = {};

sample["C99 _Bool"] =
`
//line comments
int main(void)
{
    _Bool b = 1;
    return 0;
}
`;

sample["C99 Hexadecimal floating constants"] =
`
const double d = 0x1p+1;
const double dmax = 0x1.fffffffffffffp+1023;
const double dmin = 0x1p-1022;
`;



sample["C11 _Generic"] =
    `
#include <math.h>

#define cbrt(X) _Generic((X), \\
                  double: cbrtl, \\
                  float: cbrtf ,\\
                  default: cbrtl  \\
              )(X)

#pragma expand cbrt


int main(void)
{
    cbrt(1.0);
}

`;

sample["C11 _Static_assert"] =
`
int main()
{
    _Static_assert(1 == 1, "error");    
}
`;


sample["C11 _Noreturn"] =
    `
#include <stdio.h>
#include <stdlib.h>

_Noreturn void not_coming_back(void)
{
    puts("There's no coming back");
    exit(1);
    return;
}
`;

sample["C11 u8 literals"] =
`
/*
* cake input source code encode is always utf8
* cake ouput source code is also utf8
*
* This web ouput also works with utf8. So everthing just works
* even without u8 prefix. (press compile ouput)
*
* u8 prefix may be useful in case you have a compiler where
* the input or output is not uft8.
*/

#include <stdio.h>

int main()
{
  printf("Hello, 世界\\n");
  printf(u8"Hello, 世界\\n");
}
`;


sample["C23 Digit Separator"] =
`
#define M 1000'00

int main()
{
    int a = 1000'00;
    static_assert(1000'00 == 100000);
}

`;

sample["C23 Binary Literal"] =
`
#define X  0b1010

int main()
{
    int a = X;
    int b = 0B1010;
}
`;


sample["C23 static_assert"] =
`
int main()
{    
    static_assert(1 == 1, "error");
    static_assert(1 == 1);
}
`;


sample["C23 #elifdef  #elifndef"] =
`
/*
  C23 preprocessing directives elifdef and elifndef N2645
*/
#define Y

#ifdef X
#define VERSION 1
#elifdef  Y
#define VERSION 2
#else
#define VERSION 3
#endif

_Static_assert(VERSION == 2, "");

`;


sample["C23 __VA_OPT__"] =
`
 #define F(...)  f(0 __VA_OPT__(,) __VA_ARGS__)
 F(a, b, c);

 #define F2(...)  f(0 __VA_OPT__(,) __VA_ARGS__)
 F2()
`;

sample["C23 _has_include|__has_embed|__has_c_attribute"] =
`

#if __has_include(<stdio.h>)
#warning  yes we have <stdio.h>
#endif


#if __has_embed(<stdio.h>)
#warning  yes we have <stdio.h> embed
#endif


#if __has_include(<any.h>)
#warning  YES
#else
#warning  NO we dont have <any.h>
#endif


#if __has_c_attribute(fallthrough)
#else
#warning at this moment we return 0 for all attributes
#endif

`;

sample["C23 #embed"] =
`
#include <stdio.h>

int main()
{
  static const char file_txt[] = {
   #embed "stdio.h"
   ,0
  };

  printf("%s\\n", file_txt);

}
`;

sample["C23 #warning"] =
    `
#include <stdio.h>

int main()
{
  #warning TODO ..missing code  
}
`;

sample["C23 empty initializer"] =
    `
int main()
{
    struct X {
        int i;
    } x = {};

    x = (struct X) {};

    struct Y
    {
        struct X x;
    } y = { {} };
}

`;

sample["C23 typeof"] =
`
#include <stdlib.h>

#define SWAP(a, b) \\
  do {\\
    typeof(a) temp = a; a = b; b = temp; \\
  } while (0)

#pragma expand SWAP

int main()
{
    /*simple case*/
    int a = 1;
    typeof(a) b = 1;

    /*pay attention to the pointer*/
    typeof(int*) p1, p2;

    /*let's expand this macro and see inside*/
    SWAP(a, b);

    /*for anonymous structs we insert a tag*/
    struct { int i; } x;
    typeof(x) x2;
    typeof(x) x3;

   /*Things get a little more complicated*/
   int *array[2];
   typeof(array) a1, a2;
   
   typeof(array) a3[3];
   typeof(array) *a4[4];

   /*abstract declarator*/
   int k = sizeof(typeof(array));


   /*new way to declare pointer to functions?*/
   typeof(void (int)) * pf = NULL;
}



`;




sample["C23 bool true false"] =
 `
int main()
{
  bool b = true;
  b = false;
  static_assert(1 == true);
  static_assert(0 == false);
}

`;

sample["C23 nullptr"] =
`
#include <stdlib.h>

int main()
{
  void * p = nullptr;
  void * p2 = NULL;
}
`;


sample["C23 [[maybe_unused]] "] =
`

void f( [[maybe_unused]] int arg1, int arg2)
{
    [[maybe_unused]] int local1;
    int local2;
    /*warning not used for local2*/
    /*warning not used for arg2*/
}

`;


sample["C23 [[deprecated]] "] =
`
[[deprecated]] void f2() {
}


struct [[deprecated]] S {
  int a;
};

enum [[deprecated]] E1 {
 one
};

int main(void) {
    struct S s;
    enum E1 e;
    f2();
}
`;

sample["C23 [[nodiscard]] "] =
`

#include <stdlib.h>

struct [[nodiscard]] error_info { int error; };

struct error_info enable_missile_safety_mode(void);

void launch_missiles(void);

void test_missiles(void) {
    enable_missile_safety_mode();
    launch_missiles();
}

[[nodiscard("must check armed state")]]
bool arm_detonator(int within);

void detonate();

void call(void) {
  arm_detonator(3);
  detonate();
}



`;

sample["Extension _Hashof"] =
`
struct X {
    int a[10];
  
    /*uncomment the next line*/
    //char * text;
};

void x_destroy(struct X* p);

int main()
{
    struct X x = {};
    x_destroy(&x);
}










void x_destroy(struct X* p)
{
    /*In a far away galaxy*/
    static_assert(_Hashof(p) == 283780300, "check this function x_destroy");
}


`
;

   

sample["Extension typeid"] =
`
int a[10];
static_assert(typeid(a) == typeid(double [10]), "types are different");

`;

sample["Extension try catch throw"] =
`
#include <stdio.h>

int main()
{
  FILE * f = NULL;
  try
  {
     f = fopen("file.txt", "r");
     if (f == NULL) throw;

    /*success here*/
  }
  catch
  {
     /*some error*/
  }

  if (f)
    fclose(f);
}

`;


sample["Extension try catch throw II"] =
`
#include <stdio.h>

/*not sure if usefull , but this is allowed*/

int main()
{
  try
  {
      FILE * f = NULL;
      try {
         FILE *f = fopen("file.txt", "r");
         if (f == NULL) throw;
         /*more*/
      }
      catch {
         if (f)
          fclose(f);
         throw;
      }
  }
  catch
  {
  }
}

`;

sample["Extension defer inside try blocks"] =
    `
#include <stdio.h>

int main()
{

  try
  {
     FILE* f = fopen("in.txt", "r");
     if (f == NULL) throw;
     defer fclose(f);

     FILE* f2 = fopen("out.txt", "w");
     if (f2 == NULL) throw;
     defer fclose(f2);

     //...

    /*success here*/
  }
  catch
  {
     /*some error*/
  }


}

`;

sample["Extension defer with breaks III"] =
    `

#include <stdio.h>

int main()
{

  do
  {
     FILE* f = fopen("in.txt", "r");
     if (f == NULL) break;
     defer fclose(f);

     FILE* f2 = fopen("out.txt", "w");
     if (f2 == NULL) break;
     defer fclose(f2);

     //...

    /*success here*/
  }
  while(0);


}

`;


sample["Extension defer with breaks IV"] =
    `

#include <stdio.h>

int main()
{
  FILE* f = NULL;
  defer if (f) fclose(f);

  do
  {
     f = fopen("in.txt", "r");
     if (f == NULL) break;     
  }
  while(0);

}

`;


sample["Extension defer with return V"] =
    `

#include <stdio.h>

int main()
{
  FILE* f = fopen("in.txt", "r");
  if (f == NULL) return 1;
  defer fclose(f);

  FILE* f2 = fopen("out.txt", "w");
  if (f2 == NULL) return 1;
  defer fclose(f2);

  return 0;
}


`;


sample["Extension defer goto VI"] =
    `

#include <stdio.h>

int main()
{
  FILE* f = fopen("in.txt", "r");
  if (f != NULL)
  {
     defer fclose(f);

     FILE* f2 = fopen("out.txt", "w");
     if (f2 == NULL) goto LEND;
     defer fclose(f2);
  }
  LEND:
  return 0;
}

`;

sample["Extension if with initialization (Like C++17)"] =
    `
#include <stdio.h>

int main()
{
   int size = 10;
   if (FILE* f = fopen("file.txt", "r"); f)
   {
     /*...*/
     fclose(f);
   }
}
`;

sample["Extension repeat"] =
`
int main()
{
   repeat {
     break;
   }
}
`;

sample["Extension Literal function (lambda) I"] =
`
/*simple lambda*/
#include <stdio.h>
int main()
{
  printf("%d", (int (void)){
    return 1;
  }());
}
`;

sample["Extension Literal function (lambdas)"] =
    `
#include <stdio.h>
#include <stdlib.h>
extern char* strdup(const char* s);

void async(void* capture, int sz, void (*F)(void* data))
{
  /*
    The real function would copy capture and the function pointer
    to a queue and then execute at some thread pool
  */
  F(capture);
}

void dispatch(void* capture, int sz, void (*F)(void* data))
{
  /*
    The real function would copy capture and the function pointer
    to a queue and then execute sequencially.
  */
  F(capture);
}


void create_app(const char* appname)
{
  printf("main thread\\n");
 
  struct capture {
     char * name;
  } capture = { .name = strdup(appname) };

  async(&capture, sizeof capture, (void (void* p))
  {
    struct capture* capture = p;
    printf("this is running at any thread (name=%s)\\n", capture->name);

    dispatch(capture, sizeof *capture, (void (void* p) )
    {
      struct capture* capture = p;
      printf("back to main thread\\n");
      free(capture->name);
    });
  });
}

int main()
{
  create_app("string");
  return 0;
}

`;

sample["Extension typeof + lambdas"] =
`
/* Use -fo option to format output*/

#define SWAP(a, b)\\
  (void (typeof(a)* arg1, typeof(b)* arg2)) { \\
    typeof(a) temp = *arg1; *arg1 = *arg2; *arg2 = temp; \\
  }(&(a), &(b))

#pragma expand SWAP
int main()
{
    int a;
    int b;
    SWAP(a, b);
}
`;

sample["little of semantics analysis"] =
`
int main()
{
    int a = 1;
    *a = 2; //error

    struct X { int i; }x;
    x.j = 1;
   
}

`;


sample["little of static analysis"] =
    `
int main()
{
    int a = 1;
    if (a)
    {
       int a = 2;
    }   
}
`;

