struct X {
  void * _Owner _Opt text;
};

void f(const struct X* list);

int main()
{
  struct X x = {};
  f(&x);
}