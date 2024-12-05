###############################################################################
###################################VARIABLES###################################
###############################################################################

NAME = libftprintf.a

CC ?= cc
GCC = gcc -g3
CFLAGS ?= -Wall -Wextra -Werror -I.
OBJDIR = .obj
DEPDIR = .dep
LIBFTDIR = libft

SRCS =	ft_printf.c \
		ft_printf_parse.c

LIBFTSRCS =	$(LIBFTDIR)/ft_isalpha.c \
        $(LIBFTDIR)/ft_isdigit.c \
        $(LIBFTDIR)/ft_isalnum.c \
        $(LIBFTDIR)/ft_isascii.c \
        $(LIBFTDIR)/ft_isprint.c \
        $(LIBFTDIR)/ft_strlen.c \
        $(LIBFTDIR)/ft_memset.c \
        $(LIBFTDIR)/ft_bzero.c \
        $(LIBFTDIR)/ft_memcpy.c \
        $(LIBFTDIR)/ft_memmove.c \
        $(LIBFTDIR)/ft_strlcpy.c \
        $(LIBFTDIR)/ft_strlcat.c \
        $(LIBFTDIR)/ft_toupper.c \
        $(LIBFTDIR)/ft_tolower.c \
        $(LIBFTDIR)/ft_strchr.c \
        $(LIBFTDIR)/ft_strrchr.c \
        $(LIBFTDIR)/ft_strncmp.c \
        $(LIBFTDIR)/ft_memchr.c \
        $(LIBFTDIR)/ft_memcmp.c \
        $(LIBFTDIR)/ft_strnstr.c \
		$(LIBFTDIR)/ft_atoi.c \
		$(LIBFTDIR)/ft_calloc.c \
		$(LIBFTDIR)/ft_strdup.c \
		$(LIBFTDIR)/ft_substr.c \
		$(LIBFTDIR)/ft_strjoin.c \
		$(LIBFTDIR)/ft_strtrim.c \
		$(LIBFTDIR)/ft_split.c \
		$(LIBFTDIR)/ft_itoa.c \
		$(LIBFTDIR)/ft_strmapi.c \
		$(LIBFTDIR)/ft_striteri.c \
		$(LIBFTDIR)/ft_putchar_fd.c \
		$(LIBFTDIR)/ft_putstr_fd.c \
		$(LIBFTDIR)/ft_putendl_fd.c \
		$(LIBFTDIR)/ft_putnbr_fd.c

OBJECTS = $(SRCS:%.c=$(OBJDIR)/%.o)
LIBFTOBJ = $(LIBFTSRCS:$(LIBFTDIR)/%.c=$(LIBFTDIR)/%.o)
DEPFILES = $(SRCS:%.c=$(DEPDIR)/%.d)
LIBFTDEP = $(LIBFTSRCS:$(LIBFTDIR)/%.c=$(LIBFTDIR)/%.d)

###############################################################################
#####################################RULES#####################################
###############################################################################


######################################ALL######################################

# Build the library
.PHONY: all
all: $(NAME)

$(NAME): $(OBJDIR) $(DEPDIR) $(OBJECTS) $(LIBFTOBJ)
	@echo "$(GREEN)Creating Archive... \n$(YELLOW)$@$(RESET)\n"
	@ar rcs $(NAME) $(OBJECTS) $(LIBFTOBJ)

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

$(LIBFTDIR)/%o: %.c 
	@echo "$(YELLOW)Compiling objects and dependencies... $(GREEN)$@ $(YELLOW)from $(GREEN)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ -MP -MMD -MF $(DEPDIR)/$*.d

###Includes###
-include $(DEPFILES)/$*.d
####################^^^^^THIS IS A TEST BUT NORMALLY DEPENDENCIES SHOULD BE BETTER OPTIMIZED

######################################CLEAN####################################

.PHONY: clean
clean:
	@echo "$(RED)Basic Cleaning... \n$(YELLOW)Removing $(OBJDIR) and $(DEPDIR) $(RESET)"
	@rm -rf $(OBJDIR) $(DEPDIR) $(LIBFTOBJ)


.PHONY: fclean
fclean: clean
	@echo "$(RED)Full Cleaning... \n$(YELLOW)Removing $(NAME)$(RESET)"
	@rm -rf $(NAME)

######################################RESTART##################################

.PHONY: re
re: fclean all

######################################COLORS###################################

RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
RESET  = \033[0m
