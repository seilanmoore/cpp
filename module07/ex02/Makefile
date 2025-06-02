# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smoore-a <smoore-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/28 22:56:15 by smoore-a          #+#    #+#              #
#    Updated: 2025/05/29 00:37:15 by smoore-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Program name
NAME = array

# Source files
SRC = main.cpp

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
