/***
lsleep
Because sometimes, you just want sleep.

@module lsleep
*/

#ifdef _WINDLL
#include <windows.h>
#define  DLL __declspec(dllexport)
#define sleep Sleep
#define S_TICKS 1000
#else
#include <unistd.h>
#define  DLL //empty
#define S_TICKS 1
#endif
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#define LSLEEP_LIBNAME "lsleep"

/***
@function lsleep
@param[type=number] wait The number of seconds to wait.
Calls `lsleep.sleep`
@see lsleep:sleep
*/

///@type lsleep

/***
Blocks execution of your Lua script for `wait` X 100 nanoseconds (NT) (1/10,000,000th) of a second.
@function usleep
@param[type=number] wait The number of NT to wait.
*/

#ifdef _WINDLL
int lsleep_usleep(lua_State *L ) 
{ 
	__int64 usec;
    HANDLE timer; 
    LARGE_INTEGER ft; 

	usec = (__int64) lua_tonumber(L,1);
    ft.QuadPart = -(10*usec); // neg is relative

    timer = CreateWaitableTimer(NULL, TRUE, NULL); 
    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0); 
    WaitForSingleObject(timer, INFINITE); 
    CloseHandle(timer);
	return 0;
}
#else
static int lsleep_usleep(lua_State *L){
	long usecs = lua_tointeger(L, -1);
	usleep(usecs);
	return 0;  
}

#endif
/***
Blocks execution of your Lua script for `wait` seconds.
@function sleep
@param[type=number] wait The number of seconds to wait.
*/
static int lsleep_sleep(lua_State *L){
	sleep((long) lua_tointeger(L, -1) * S_TICKS);
	return 0;
}

static const struct luaL_Reg lsleep_metamethods [] = {
	{"__call", lsleep_sleep},
	{NULL, NULL}

};
static const struct luaL_Reg lsleep_funcs [] = {
	{"sleep", lsleep_sleep},
	{"usleep", lsleep_usleep},
	{NULL, NULL}

};

//register table with default __call to sleep
 DLL int luaopen_lsleep(lua_State *L){
	luaL_newlib(L, lsleep_funcs); //returned table with sleep and usleep as the fields.
	luaL_newlib(L, lsleep_metamethods); //add the metatable, which adds the __call to sleep.
	lua_setmetatable(L, -2);
	return 1;
}

