APP_NAME = chessviz
LIB_NAME = libchessviz
TEST_NAME = chess-test
CXX = g++
SRC_EXT = cpp

CPPFLAGS = -Wall -Wextra -Werror -I src -I thirdparty -MP -MMD
LDLIBS = -lm

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME).exe
TEST_PATH = $(BIN_DIR)/$(TEST_NAME).exe
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name main.cpp)
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

TEST_SOURCES = $(shell find $(TEST_DIR) -name tests.cpp)
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(TEST_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name lib.cpp)
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

all: $(APP_PATH)

test: $(TEST_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CXX) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CXX) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/$(SRC_DIR)/$(APP_NAME)/%.o: $(SRC_DIR)/$(APP_NAME)/%.cpp
	$(CXX) -c $(CPPFLAGS) $< -o $@ $(LDLIBS)

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) -c $(CPPFLAGS) $< -o $@ $(LDLIBS)

$(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/%.o: $(SRC_DIR)/$(LIB_NAME)/%.cpp
	$(CXX) -c $(CPPFLAGS) $< -o $@ $(LDLIBS)

.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH) $(TEST_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
