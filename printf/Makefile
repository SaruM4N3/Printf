###############################################################################
###################################VARIABLES###################################
###############################################################################

NAME = libftprintf.a

CC ?= cc
GCC = gcc -g3
CFLAGS ?= -Wall -Wextra -Werror -I.
OBJDIR = Obj
DEPDIR = Dep

SRCS =	ft_printf.c \
		ft_printf_parse.c

OBJECTS = $(SRCS:%.c=$(OBJDIR)/%.o)
DEPFILES = $(SRCS:%.c=$(DEPDIR)/%.d)


###############################################################################
#####################################RULES#####################################
###############################################################################


######################################ALL######################################

# Build the library
.PHONY: all
all: $(NAME)

$(NAME): $(OBJDIR) $(DEPDIR) $(OBJECTS)
	@echo "$(GREEN)Creating Archive... \n$(YELLOW)$@$(RESET)\n"
	@ar rcs $(NAME) $(OBJECTS)

# Compile .c to .o
$(OBJDIR)/%.o: %.c Makefile
	@echo "$(YELLOW)Compiling objects and dependencies... $(GREEN)$@ $(YELLOW)from $(GREEN)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ -MP -MMD -MF $(DEPDIR)/$*.d

# Create obj dir
$(OBJDIR):
	@echo "$(GREEN)Creating directory... $(YELLOW)$@$(RESET)"
	@mkdir -p $(OBJDIR)

# Create dep dir
$(DEPDIR):
	@echo "$(GREEN)Creating directory... $(YELLOW)$@$(RESET)"
	@mkdir -p $(DEPDIR)

###Includes###
-include $(DEPFILES)/$*.d
####################^^^^^THIS IS A TEST BUT NORMALLY DEPENDENCIES SHOULD BE BETTER OPTIMIZED

######################################DEBUG####################################
#THIS IS WIP IM EXPERIMENTING
.PHONY: debug
debug: $(NAME)

$(NAME): $(OBJDIR) $(DEPDIR) $(OBJECTS)
	@echo "$(GREEN)Creating Archive... \n$(YELLOW)$@$(RESET)\n"
	@ar rcs $(NAME) $(OBJECTS)

$(OBJDIR)/%.o: %.c Makefile
	@echo "$(YELLOW)Compiling objects and dependencies... $(GREEN)$@ $(YELLOW)from $(GREEN)$<$(RESET)"
	@$(GCC) $(CFLAGS) -c $< -o $@ -MP -MMD -MF $(DEPDIR)/$*.d

######################################CLEAN####################################

.PHONY: clean
clean:
	@echo "$(RED)Basic Cleaning... \n$(YELLOW)Removing $(OBJDIR)$(RESET)"
	@rm -rf $(OBJDIR) $(DEPDIR)


.PHONY: fclean
fclean: clean
	@echo "$(RED)Full Cleaning... \n$(YELLOW)Removing $(DEPDIR) \nRemoving $(NAME)$(RESET)"
	@rm -rf $(NAME)

######################################RESTART##################################

.PHONY: re
re: fclean all

######################################COLORS###################################

RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
RESET  = \033[0m
