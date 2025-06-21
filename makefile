CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

# Manually list all source files
SOURCES = \
    $(SRC_DIR)/Address.cpp \
    $(SRC_DIR)/CashMemo.cpp \
    $(SRC_DIR)/CellNumber.cpp \
    $(SRC_DIR)/Date.cpp \
    $(SRC_DIR)/Item.cpp \
    $(SRC_DIR)/cashmemo_app.cpp \
    $(SRC_DIR)/Name.cpp \
    $(SRC_DIR)/ReceiptNo.cpp \
    $(SRC_DIR)/ShopDetails.cpp

# Manually list all object files
OBJECTS = \
    $(OBJ_DIR)/Address.o \
    $(OBJ_DIR)/CashMemo.o \
    $(OBJ_DIR)/CellNumber.o \
    $(OBJ_DIR)/Date.o \
    $(OBJ_DIR)/Item.o \
    $(OBJ_DIR)/cashmemo_app.o \
    $(OBJ_DIR)/Name.o \
    $(OBJ_DIR)/ReceiptNo.o \
    $(OBJ_DIR)/ShopDetails.o

TARGET = $(BIN_DIR)/cashmemo.exe

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Explicit rules for each object file
$(OBJ_DIR)/Address.o: $(SRC_DIR)/Address.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/CashMemo.o: $(SRC_DIR)/CashMemo.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/CellNumber.o: $(SRC_DIR)/CellNumber.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Date.o: $(SRC_DIR)/Date.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Item.o: $(SRC_DIR)/Item.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/cashmemo_app.o: $(SRC_DIR)/cashmemo_app.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Name.o: $(SRC_DIR)/Name.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/ReceiptNo.o: $(SRC_DIR)/ReceiptNo.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/ShopDetails.o: $(SRC_DIR)/ShopDetails.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

run: all
	@$(TARGET)