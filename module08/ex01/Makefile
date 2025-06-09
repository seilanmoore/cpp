# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smoore-a <smoore-a@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 18:52:40 by smoore-a          #+#    #+#              #
#    Updated: 2025/06/05 18:53:03 by smoore-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Program name
NAME = span

# Source files
SRC = main.cpp Span.cpp

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
