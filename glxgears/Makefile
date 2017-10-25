#/*
# *  Copyright (C) 2016.
# *  All Rights Reserved.
# *
# */
#
#
.PHONY: clean

ROOTFS ?= $(SDKTARGETSYSROOT)

ROOTFS_USR :=$(ROOTFS)/usr

OBJS := glxgears.o

CFLAGS += -I $(ROOTFS)/usr/include --sysroot=$(ROOTFS)

LFLAGS += -Wl,-rpath-link,$(ROOTFS)/usr/lib -Wl,-rpath-link,$(ROOTFS)/usr/lib/arm-linux-gnueabi -lGL -lEGL -lX11 -lm --sysroot=$(ROOTFS)


TARGET := glxgears
all:$(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# build as shared library
glxgears: glxgears.o
	$(CC) $^ -o glxgears $(LFLAGS)

clean:
	-@rm $(TARGET) $(OBJS)

