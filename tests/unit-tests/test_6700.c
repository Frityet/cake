#pragma nullable enable
#pragma ownership enable

void free( void* _Owner ptr);
void* _Owner malloc(int size);

int main()
{
    int* _Owner p = malloc(sizeof(int));
    if (p)
    {
       free(p);     
    }
}

