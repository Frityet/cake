#pragma nullable enable
#pragma ownership enable

void * _Owner _Opt calloc(int i, int sz);
void free( void * _Owner _Opt p);

struct X { int i; };
struct Y { struct X * _Owner p; };

int main() {
   struct Y y = {0};
   struct X * _Owner _Opt p = calloc(1, sizeof(struct X));
   if (p){
     y.p = p;
   }
  free(y.p);
}

