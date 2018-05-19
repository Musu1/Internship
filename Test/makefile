ifeq ($(OS),Windows_NT)
    ifeq ($(shell uname -s),)
        CLEANUP = del /F /Q
        MKDIR = mkdir
    else
        CLEANUP =rm -f
        MKDIR = mkdir -p
    endif
        TARGET_EXTENSION=.exe
else
    CLEANUP = rm if
    MKDIR = mkdir -p
    TARGET_EXTENSION=.out
endif

C_COMPILER=gcc
ifeq ($(shell uname -s),Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=../..

CFLAGS=-std=c89

TARGET_BASE=test
TARGET1 = $ (TARGET_BASE) $ (TARGET_EXTENSION)
SRC_FILES=$(UNITY_ROOT)/src/unity.c src/function.c  test/Calculator_Test.c  
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src

all: clean default

default: $(SRC_FILES)
****$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SRC_FILES) -o $(TARGET)
****- ./$(TARGET)

#clean:
 #   $(CLEANUP) $(TARGET)

ci: CFLAGS += -Werror
ci: default