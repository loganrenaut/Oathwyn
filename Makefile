
CC = clang
SDKROOT = $(shell xcrun --sdk macosx --show-sdk-path)

CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -Iinclude -isysroot $(SDKROOT)
DEPFLAGS = -MMD -MP

SDL_CFLAGS = $(shell pkg-config --cflags sdl3)
SDL_LIBS = $(shell pkg-config --libs sdl3)

BUILD_DIR = build

GAME_SOURCES = src/main.c src/world.c
GAME_OBJECTS = $(GAME_SOURCES:src/%.c=$(BUILD_DIR)/%.o)

TEST_OBJECTS = $(BUILD_DIR)/test_world.o $(BUILD_DIR)/world.o

.PHONY: all clean test

all: $(BUILD_DIR)/oathwyn

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/main.o: src/main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SDL_CFLAGS) $(DEPFLAGS) -MF $(BUILD_DIR)/main.d -c $< -o $@

$(BUILD_DIR)/world.o: src/world.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -MF $(BUILD_DIR)/world.d -c $< -o $@

$(BUILD_DIR)/test_world.o: tests/test_world.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -MF $(BUILD_DIR)/test_world.d -c $< -o $@

$(BUILD_DIR)/oathwyn: $(GAME_OBJECTS)
	$(CC) $^ $(SDL_LIBS) -o $@

$(BUILD_DIR)/test_world: $(TEST_OBJECTS)
	$(CC) $^ -o $@

test: $(BUILD_DIR)/test_world
	./$(BUILD_DIR)/test_world

clean:
	rm -rf $(BUILD_DIR)

-include $(BUILD_DIR)/main.d $(BUILD_DIR)/world.d $(BUILD_DIR)/test_world.d
