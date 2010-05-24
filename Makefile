# locally insalled
GCC=/opt/gcc45/bin/gcc
GCCPLUGINS_DIR:= $(shell $(GCC) -print-file-name=plugin)
CFLAGS+= -I$(GCCPLUGINS_DIR)/include -fPIC -O2

PLUGIN_SOURCE_FILES = hello.c
PLUGIN_OBJECT_FILES = $(patsubst %.c,%.o,$(PLUGIN_SOURCE_FILES))
PLUGIN_SO = hello.so

$(PLUGIN_SO): $(PLUGIN_OBJECT_FILES)
	$(GCC) -shared $^ -o $@

all: $(PLUGIN_SO)

play: ${PLUGIN_SO}
	cd playground && make

clean:
	-rm ${PLUGIN_SO} ${PLUGIN_OBJECT_FILES}
