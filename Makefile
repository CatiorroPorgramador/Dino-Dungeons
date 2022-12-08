all:
	g++ src/Main.cpp -o bin/Main.exe -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lopengl32
	@echo Compiled.