#include "symbol.h"

void            scope_enter();
void            scope_exit();
int         scope_level();
void            scope_bind( const char *name, struct symbol *s );
struct symbol * scope_lookup( const char *name );
struct symbol * scope_lookup_current( const char *name );