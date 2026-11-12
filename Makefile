IN := example.cpp
OUT := example.o

$(OUT): $(IN)
	@g++ -std=c++23 -o $(OUT) $(IN)

run: $(OUT)
	@./$(OUT)

clean:
	@if [ -e $(OUT) ]; then rm ./$(OUT); else echo "Nothing to clean."; fi
