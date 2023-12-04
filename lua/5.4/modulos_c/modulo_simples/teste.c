#include <lua.h>
#include <lauxlib.h>

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

static luaL_Reg exports[] = {
		"soma", soma
};

int luaopen_test(lua_State *L) {
	luaL_newlib(L, exports);
	return 1;
}
