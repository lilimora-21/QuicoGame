# Makefile sin archivos .o

CXX      := g++
CXXFLAGS := -std=c++17 -Iinclude `pkg-config --cflags sfml-all`
LDFLAGS  := `pkg-config --libs sfml-graphics sfml-window sfml-system sfml-audio`

SRC_DIR  := src
SRCS     := $(wildcard $(SRC_DIR)/*.cpp)
TARGET   := QuicoChrome

.PHONY: all clean run

# Regla por defecto: compila y enlaza todo en un solo comando
all:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

# Ejecuta el juego (primero compila)
run: all
	@./$(TARGET)

# Limpia solo el ejecutable
clean:
	rm -f $(TARGET)
