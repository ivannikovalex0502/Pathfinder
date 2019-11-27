NAME = pathfinder
INC = ./inc/header.h
INCLIB = ./libmx/inc/libmx.h
HEADTMP = ./header.h ./libmx.h

SRC = ./main.c ./mx_isalpha.c ./mx_isdigit.c ./mx_printerr.c ./mx_free_all.c ./mx_print_error.c  ./mx_atoi.c ./mx_print_short_path.c ./mx_make_paths.c ./mx_push_element_in_island.c ./mx_check_text_file.c ./mx_read_text_file.c ./mx_city_malloc.c ./mx_restore_paths.c ./mx_restore.c  ./mx_search_index_island.c 

SRCS = ./src/main.c ./src/mx_isalpha.c ./src/mx_isdigit.c ./src/mx_printerr.c ./src/mx_free_all.c  ./src/mx_print_error.c  ./src/mx_atoi.c ./src/mx_print_short_path.c ./src/mx_make_paths.c ./src/mx_push_element_in_island.c ./src/mx_check_text_file.c ./src/mx_read_text_file.c ./src/mx_city_malloc.c ./src/mx_restore_paths.c ./src/mx_restore.c  ./src/mx_search_index_island.c 

OBJ = ./main.o ./mx_isalpha.o ./mx_isdigit.o ./mx_printerr.o ./mx_free_all.o ./mx_print_error.o  ./mx_atoi.o ./mx_print_short_path.o ./mx_make_paths.o ./mx_push_element_in_island.o ./mx_check_text_file.o ./mx_read_text_file.o ./mx_city_malloc.o ./mx_restore_paths.o ./mx_restore.o  ./mx_search_index_island.o 

OBJO = ./obj/main.o ./obj/mx_isalpha.o ./obj/mx_isdigit.o ./obj/mx_printerr.o ./obj/mx_free_all.o  ./obj/mx_print_error.o  ./obj/mx_atoi.o ./obj/mx_print_short_path.o ./obj/mx_make_paths.o ./obj/mx_push_element_in_island.o ./obj/mx_check_text_file.o ./obj/mx_read_text_file.o ./obj/mx_city_malloc.o ./obj/mx_restore_paths.o ./obj/mx_restore.o  ./obj/mx_search_index_island.o 

CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install uninstall
install:
	@cd libmx && make -f Makefile install
	@cp $(INC) $(SRCS) .
	@cp $(INCLIB) . 
	@clang $(CFLGS) -c  $(SRC)
	@mkdir  obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)
uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj
	@rm -rf ./libmx/obj
clean: uninstall
	@cd libmx && make -f Makefile clean
	@rm -rf $(NAME)
reinstall: clean all