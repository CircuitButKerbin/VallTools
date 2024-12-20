#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lua.h>
#include "lauxlib.h"
#include "lualib.h"

extern const char _binary_src_scripts_assemblerMain_lua_end[];
extern const char _binary_src_scripts_assemblerMain_lua_start[];

extern const char _binary_src_scripts_disassemblerMain_lua_start[];
extern const char _binary_src_scripts_disassemblerMain_lua_end[];

extern const char _binary_src_scripts_shared_lua_start[];
extern const char _binary_src_scripts_shared_lua_end[];


char *load_resource(const char *resource_start, const char *resource_end) {
	size_t len = (unsigned int)(&resource_end - &resource_start);
	void* buffer = malloc(len);
	return memcpy(buffer, &resource_start, len);
}

int main(int argc, char *argv[]) {
	char buff[256];
	int error;
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	
	if (argc == 0) {
		return 1;
	};
	char* sharedLib = load_resource(_binary_src_scripts_shared_lua_start, _binary_src_scripts_shared_lua_end);
	luaL_loadstring(L, sharedLib);

	if (argv[1] == "assemble") {


	} else if (argv[1] == "dissassemble") {


	} else {
		return 1;
	}
    return 0;
}