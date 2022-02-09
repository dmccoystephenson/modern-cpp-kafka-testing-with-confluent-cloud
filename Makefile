all: testing

testing: src/testing.cpp
	@echo "---"
	@echo "Compiling testing.cpp"

	g++ src/test.cpp -o test

	@echo "Finished compiling testing.cpp"