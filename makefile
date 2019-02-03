# Masukkan semua file c Anda
OBJS = frame_buffer.c draw.c draw_driver.c

CC = gcc
# COMPILER_FLAGS = -o
# LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = image
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
