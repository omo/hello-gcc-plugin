# locally insalled
GCC=/opt/gcc45/bin/gcc
GCCPLUGINS_DIR:= $(shell $(GCC) -print-file-name=plugin)
CFLAGS+= -I$(GCCPLUGINS_DIR)/include -fPIC -O2

PLUGIN_SOURCE_FILES = hello.c
PLUGIN_OBJECT_FILES = $(patsubst %.c,%.o,$(PLUGIN_SOURCE_FILES))
PLUGIN_SO_NAME = hello.so

$(PLUGIN_SO_NAME): $(PLUGIN_OBJECT_FILES)
	$(GCC) -shared $^ -o $@

all: $(PLUGIN_SO_NAME)

clean:
	-rm ${PLUGIN_SO_NAME} ${PLUGIN_OBJECT_FILES}

play:
	cd playground && make
