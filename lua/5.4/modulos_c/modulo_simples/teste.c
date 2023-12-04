#include <lua.h>
#include <lauxlib.h>

/* This is a function that have the C Function signature */
static int soma(lua_State *L) {
	int n = lua_gettop(L); /* number of arguments */
	lua_Number sum = 0.0;
	int i;
	for (i = 1; i <= n; i++) {
		if (!lua_isnumber(L, i)) {
			lua_pushliteral(L, "incorrect argument");
			lua_error(L);
		}
		sum += lua_tonumber(L, i);
	}
	lua_pushnumber(L, sum / n); /* first result */
	lua_pushnumber(L, sum); /* second result */
	return 2; /* number of results */
}
/* This array conatins the functions of the module */
static luaL_Reg exports[] = {
		"soma", soma
};

/* This is the function Lua will altomaticaly find when doing a require("test") call
 * it aways have the form luaopen_<libname> */
int luaopen_test(lua_State *L) {
	/*
	 * From official docs:
	 * 		void luaL_newlib (lua_State *L, const luaL_Reg l[]);
	 *		Creates a new table and registers there the functions in the list l.
	 * */
	luaL_newlib(L, exports);
	return 1;
}
