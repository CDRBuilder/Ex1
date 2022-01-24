#ifndef _UTILS_H
#define _UTILS_H_
//#define DEBUG 1
#ifdef DEBUG 
#define DBGVAR( os, var ) \
  (os) << "DBG: " << __FILE__ << "::" << __FUNCTION__ <<"(" << __LINE__ << ") \t\t\t"\
       << #var << " = [" << (var) << "]"

#define DBGVAR_2( os, var1, var2 ) \
  DBGVAR(os, var1) <<" " << #var2 << " = [" << (var2) << "]"

#define DBGVAR_3( os, var1, var2 , var3) \
  DBGVAR_2( (os) , (var1), (var2) ) <<" " << #var3 << " = [" << (var3) << "]"

#define DBGVAR_4( os, var1, var2 , var3 , var4 ) \
  DBGVAR_3( (os), (var1) , (var2) , (var3)) <<" " << #var4 << " = [" << (var4) << "]"

#define DBGSTR(var) \
  std::cout << "DBG: " << __FILE__ << "::" << __FUNCTION__ << "(" << __LINE__ << ") \t\t\t" << var

#define ENDL std::endl 
#define DBGVARL( os, var) DBGVAR( (os) , (var) ) << ENDL;
#define DBGVAR_2L( os, var1, var2 ) DBGVAR_2( (os) , (var1), (var2) ) << ENDL;
#define DBGVAR_3L( os, var1, var2 , var3) DBGVAR_3( (os) , (var1), (var2), (var3) ) << ENDL;
#define DBGVAR_4L( os, var1, var2 , var3 , var4) DBGVAR_4( (os) , (var1), (var2), (var3), (var4) ) << ENDL;
#define DBGSTRL(str) DBGSTR(str)<<ENDL
#else

#define DBGVAR( os, var ) 
#define DBGVAR_2( os, var1, var2 ) 
#define DBGVAR_3( os, var1, var2 , var3) 
#define DBGVAR_4( os, var1, var2 , var3 , var4 )
#define DBGSTR(var)
#define ENDL 
#define DBGVAR_2L( os, var, var2 ) 
#define DBGVAR_3L( os, var, var2 , var3) 
#define DBGVAR_4L( os, var, var2 , var3, var4) 
#define DBGVARL( os, var) 
#define DBGSTRL(str) 
#endif
#endif