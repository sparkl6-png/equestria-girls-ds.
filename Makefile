# devkitPro/libnds Makefile
TARGET := equestria-girls-ds
BUILD := build
SOURCES := source
INCLUDES :=
ARCH := -mthumb -mthumb-interwork

CFLAGS := -g -Wall -O2 -ffunction-sections -fdata-sections \
          $(ARCH) $(INCLUDES) -DARM9
CXXFLAGS := $(CFLAGS) -fno-rtti -fno-exceptions
ASFLAGS := $(ARCH)
LDFLAGS := -specs=ds_arm9.specs -g $(ARCH) -Wl,--gc-sections
LIBS := -lnds9

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. Run this from a devkitPro shell.")
endif

include $(DEVKITARM)/ds_rules