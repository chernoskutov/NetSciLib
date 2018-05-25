CC=g++

CFLAGS=-std=c++11

OBJ_DIR=../../obj

NETSCILIB_ROOT_DIR=../../netscilib

BUILDING_BLOCK_SOURCES=$(NETSCILIB_ROOT_DIR)/data_structures_building_blocks/*.hpp
DATA_STRUCTURE_SOURCES=$(NETSCILIB_ROOT_DIR)/data_structures/*.hpp

SOURCES=compressed_sparse_row_test.cpp

all:
	$(CC) $(CFLAGS) $(SOURCES) $(BUILDING_BLOCK_SOURCES) $(DATA_STRUCTURE_SOURCES) -o $(OBJ_DIR)/compressed_sparse_row_test