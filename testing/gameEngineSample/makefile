# Masukkan semua file c Anda
OBJS = ../../graphics/frame_buffer.c ../../graphics/draw.cpp ../../object/object.cpp ../../object/canon/canon.cpp ../../object/bullet/bullet.cpp ../../object/airplane/airplane.cpp game_engine_sample.cpp

# frame_buffer.c draw.c object.cpp sample_object.cpp driver_sampleObject.cpp

CC = g++
# COMPILER_FLAGS = -g -std=c++11 -Wall -O2
LINKER_FLAGS = -lcurses
OBJ_NAME = image
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
