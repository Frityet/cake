#pragma nullable enable
#pragma ownership enable

struct X {
  char * _Owner name;
};

struct X f();
struct X f2()
{
    return f();
}
