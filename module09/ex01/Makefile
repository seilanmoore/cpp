# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

# Program name
NAME = RPN

# Source files
SRC = main.cpp RPN.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(NAME)

# Compile the program
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Rule to compile each .cpp file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean object files and executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Prevent make from getting confused by files named like targets
.PHONY: all clean fclean re