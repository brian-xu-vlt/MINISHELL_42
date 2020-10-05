#include "vector.h"

char	vct_getlastchar(t_vector *vct)
{
	if (vct == NULL || vct->str == NULL)
		return ('\0');
	return (vct->str[vct_getlen(vct) - 1]);
}
