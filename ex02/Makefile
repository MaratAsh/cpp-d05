TARGET = Bureaucrat

CC = c++
CFAGS = -Wall -Wextra -Werror -std=c++98
OBJS_DIR = objs
SRCS_DIR = srcs
INCL_DIR = ./includes
FILES := $(shell ls $(SRCS_DIR))
INCLUDES := $(addprefix $(INCL_DIR)/, $(shell ls $(INCL_DIR)))

OBJS = $(addprefix $(OBJS_DIR)/, $(FILES:.cpp=.o))

all: create_dirs $(TARGET)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(INCLUDES)
		$(CC) -I$(INCL_DIR) $(CFAGS) -c $< -o $@

$(TARGET):  $(OBJS) $(INCLUDES)
		$(CC) $(CFAGS) $(OBJS) -o $(TARGET)

create_dirs:
		@ mkdir -p $(OBJS_DIR)

clean:
		rm -rf $(OBJS_DIR)

fclean: clean
		rm -rf $(TARGET)

re: fclean all

run: $(TARGET)
		@ ./$(TARGET)

leaks: $(TARGET)
	@ leaks --atExit -- ./$(TARGET)

.PHONY: all leaks re fclean clean run create_dirs
