CC = c++
FLAGS = -Wall -Wextra -Werror
SRCS = ScalarConverter.cpp \
	   main.cpp
RM = rm -rf
OBJS_DIR = obj
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

NAME = converter

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:%.cpp
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(NAME)

fclean: clean
	@$(RM) $(OBJS_DIR)

re : fclean $(NAME)

.PHONY: clean, fclean, re, all



