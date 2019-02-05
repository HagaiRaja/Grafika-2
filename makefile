# Masukkan semua file c Anda
OBJS = graphics/frame_buffer.c graphics/draw.cpp graphics/input.cpp object/object.cpp object/canon/canon.cpp object/bullet/bullet.cpp object/airplane/airplane.cpp game_engine.cpp

# frame_buffer.c draw.c object.cpp sample_object.cpp driver_sampleObject.cpp

CC = g++
# COMPILER_FLAGS = -g -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = image
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
