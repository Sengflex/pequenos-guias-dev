PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

OBJS = teste.o

# A lua module is a dynamic link library. So we compile sources with -fPIC and link the library with -shared
LDFLAGS:=-shared -llua
CFLAGS:=-fPIC

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
else ifeq ($(BUILD_MODE),linuxtools)
	CFLAGS += -g -pg -fprofile-arcs -ftest-coverage
	LDFLAGS += -pg -fprofile-arcs -ftest-coverage
	EXTRA_CLEAN += teste.gcda teste.gcno $(PROJECT_ROOT)gmon.out
	EXTRA_CMDS = rm -rf teste.gcda
else
    $(error Build mode $(BUILD_MODE) not supported by this Makefile)
endif

all:	test.so

# módulo lua
test.so:	$(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^
	$(EXTRA_CMDS)

%.o:	$(PROJECT_ROOT)%.cpp
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

%.o:	$(PROJECT_ROOT)%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -fr test.so $(OBJS) $(EXTRA_CLEAN)
