# Build the project
build:
	clang++ -fcolor-diagnostics -fansi-escape-codes -g -std=c++17 -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo *.cpp -o TETRIS

run:
	./TETRIS

# Clean up executable
clear:
	rm -f TETRIS


