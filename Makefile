src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)
dep = $(src:.cpp=.d)

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

game: $(obj)
	clang++ -std=c++17 $^ -o $@ $(LDFLAGS) -I include

src/%.o: src/%.cpp
	clang++ -std=c++17 -o $@ -c $< -I include

.PHONY: clean
clean:
	rm -f $(obj) $(dep) game

test_src = $(wildcard test/*.cpp)
test_obj = $(test_src:.cpp=.o)

.PHONY: test
test:
	make bin/test && ./bin/test

.PHONY: clean_test
clean_test:
	rm -f $(test_obj) bin/test

bin/test: $(test_obj) $(filter-out src/main.o, $(obj))
	clang++ -std=c++17 $^ -o $@ -I include

test/%.o: test/%.cpp
	clang++ -std=c++17 -o $@ -c $< -I include