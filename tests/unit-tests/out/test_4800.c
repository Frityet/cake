#pragma nullable enable
#pragma ownership enable

struct X { char  * /*_Owner*/ owner_variable;   };
char * f(struct X *parameter) 
{
    return parameter->owner_variable;
}
