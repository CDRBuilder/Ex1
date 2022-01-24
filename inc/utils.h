#ifndef _UTILS_H
#define _UTILS_H_


#define DBGVAR( os, var ) \
  (os) << "DBG: " << __FILE__ << "::" << __FUNCTION__ <<"(" << __LINE__ << ") "\
       << #var << " = [" << (var) << "]"

#define DBGVAR_2( os, var1, var2 ) \
  DBGVAR(os, var1) <<" " << #var2 << " = [" << (var2) << "]"

#define DBGVAR_3( os, var1, var2 ) \
  DBGVAR_2(os, var1) <<" " << #var2 << " = [" << (var2) << "]"

#define DBGSTR(os) \
  (os) << "DBG: " << __FILE__ << "(" << __LINE__ << ") "

#define ENDL std::endl 
#endif