CXX			:= g++

EXE			:= main
SRC     	:= $(wildcard *.cpp)
DIR			:= buld
OBJ     	:= $(SRC:%.cpp=$(DIR)/%.o)
DEP         := $(OBJ:.o=.d)

CPPFLAGS	:= -g -c -std=gnu++0x -MMD -MP -I.



# The main executable target
$(EXE): $(OBJ)
	$(CXX) -o $@ $^



# Dependencies
$(DIR)/%.o: %.cpp | $(DIR)
	$(CXX) $(CPPFLAGS) -o $@ $<

# Create build dir
$(DIR):
	@mkdir $@

-include $(DEP)



# Clean build files
clean:
	rm -f $(OBJ)
	rm -fR $(DIR)

cleanall: clean
	rm -f $(EXE)
