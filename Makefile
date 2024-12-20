build_deps:
	cd deps/lua && make liblua.a

build:
	gcc -o .build/vallasm.o -c src/main.c -Ideps/lua/ -Ldeps/lua/ -llua -lm
	ld -r -static -b binary --whole-archive -o .build/assemblerMain.o src/scripts/assemblerMain.lua
	ld -r -static -b binary --whole-archive -o .build/disassemblerMain.o src/scripts/disassemblerMain.lua
	ld -r -static -b binary --whole-archive -o .build/shared.o src/scripts/shared.lua
	gcc .build/vallasm.o deps/lua/liblua.a  .build/shared.o -static -o .build/vallasm