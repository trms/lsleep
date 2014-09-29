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
_int64 TICKS;

#define NANOS 10 * 1000 * 1000

int lsleep_getticks(lua_State *L) {
	lua_pushinteger(L, (_int64) TICKS);
	return 1;
}

int lsleep_time(lua_State *L)
{
	LARGE_INTEGER ft;
	QueryPerformanceCounter(&ft);
	lua_pushinteger(L, (_int64) ft.QuadPart * NANOS / TICKS );
	return 1;
}

int lsleep_sleep(lua_State *L ) 
{ 
	__int64 nt_tv;
    HANDLE timer; 
    LARGE_INTEGER ft; 
	
	nt_tv = (__int64) luaL_checkinteger(L,1);
	ft.QuadPart = - ( nt_tv * TICKS / NANOS ); // neg is relative
	
	timer = CreateWaitableTimer(NULL, TRUE, NULL); 
   SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0); 
   WaitForSingleObject(timer, INFINITE); 
   CloseHandle(timer);

	return lsleep_time(L);
}
#else
static int lsleep_sleep(lua_State *L){
	long usecs = luaL_checkinteger(L, 1);
	usleep(usecs);
	return 0;  
}

#endif
/***
Blocks execution of your Lua script for `wait` seconds.
@function sleep
@param[type=number] wait The number of seconds to wait.
*/

static const struct luaL_Reg lsleep_metamethods [] = {
	{"__call", lsleep_time},
	{NULL, NULL}

};
static const struct luaL_Reg lsleep_funcs [] = {
	{"sleep", lsleep_sleep},
	{"time", lsleep_time},
	{"getticks", lsleep_getticks},
	{NULL, NULL}

};

//register table with default __call to sleep
 DLL int luaopen_lsleep(lua_State *L){
	
	LARGE_INTEGER PERF_FREQ;

	if (!QueryPerformanceFrequency(&PERF_FREQ)) {
		luaL_error(L, "Performance timer is not supported on this Windows platrform.");
	}
	TICKS = PERF_FREQ.QuadPart;

	luaL_newlib(L, lsleep_funcs); //returned table with sleep and usleep as the fields.
	luaL_newlib(L, lsleep_metamethods); //add the metatable, which adds the __call to sleep.
	lua_setmetatable(L, -2);
	return 1;
}

