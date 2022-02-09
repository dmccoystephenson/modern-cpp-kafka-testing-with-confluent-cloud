all: test

test: src/test.cpp
	@echo "---"
	@echo "Compiling test.cpp"

	g++ src/test.cpp -o test

	@echo "Finished compiling test.cpp"