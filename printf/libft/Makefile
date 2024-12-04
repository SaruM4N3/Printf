# COLORS
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
RESET  = \033[0m

# VARIABLES
NAME = libft.a

CC = cc
CFLAGS ?= -Wall -Wextra -Werror -I.
OBJDIR = Obj
DEPDIR = Dep

SRCS =	ft_isalpha.c \
        ft_isdigit.c \
        ft_isalnum.c \
        ft_isascii.c \
        ft_isprint.c \
        ft_strlen.c \
        ft_memset.c \
        ft_bzero.c \
        ft_memcpy.c \
        ft_memmove.c \
        ft_strlcpy.c \
        ft_strlcat.c \
        ft_toupper.c \
        ft_tolower.c \
        ft_strchr.c \
        ft_strrchr.c \
        ft_strncmp.c \
        ft_memchr.c \
        ft_memcmp.c \
        ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

SRCBONUS =	ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJECTS = $(SRCS:%.c=$(OBJDIR)/%.o)
DEPFILES = $(SRCS:%.c=$(DEPDIR)/%.d)

BONUSOBJ = $(SRCBONUS:%.c=$(OBJDIR)/%.o)
BONUSDEP = $(SRCBONUS:%.c=$(DEPDIR)/%.d)

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

# Include Dependencies
-include $(DEPFILES) $(BONUSDEP)


.PHONY: bonus
bonus:
	@echo "$(GREEN)Adding bonuses to library...$(RESET)"
	@$(MAKE) --no-print-directory all SRCS="$(SRCS) $(SRCBONUS)"

# Clean part
.PHONY: clean
clean:
	@echo "$(RED)Basic Cleaning... \n$(YELLOW)Removing $(OBJDIR)$(RESET)"
	@rm -rf $(OBJDIR) $(DEPDIR)

.PHONY: fclean
fclean: clean
	@echo "$(RED)Full Cleaning... \n$(YELLOW)Removing $(DEPDIR) \nRemoving $(NAME)$(RESET)"
	@rm -rf $(NAME)

.PHONY: re
re: fclean all
