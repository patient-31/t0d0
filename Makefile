NAME								:=		t0d0

C_COMPILER							:=		gcc

SRC_LAB-COMPILER_DIR				:=		source/lab-compiler/
SRC_PROCESS_DIR						:=		source/process/
OBJ_LAB-COMPILER_DIR				:=		object/lab-compiler/
OBJ_PROCESS_DIR						:=		object/process/

FLAGS								:=		-Wextra
ADDSAN								:=	

SOURCE_COMPILER						:=		$(wildcard $(SRC_LAB-COMPILER_DIR)*.c)
SOURCE_PROCESS						:=		$(wildcard $(SRC_PROCESS_DIR)*.c)

OBJECTS_LAB-COMPILER				:=		$(patsubst $(SRC_LAB-COMPILER_DIR)%.c,$(OBJ_LAB-COMPILER_DIR)%.o,$(SOURCE_COMPILER))
OBJECTS_PROCESS						:=		$(patsubst $(SRC_PROCESS_DIR)%.c,$(OBJ_PROCESS_DIR)%.o,$(SOURCE_PROCESS))

LINK								:=		$(C_COMPILER) $(FLAGS) -o $(NAME) $(OBJECTS_PROCESS) $(OBJECTS_LAB-COMPILER) -lncurses $(ADDSAN)


engine: clean
									echo "PLEASE STANDBY... BEEP!"
									make $(NAME)


$(NAME): $(OBJ_LAB-COMPILER_DIR) $(OBJ_PROCESS_DIR) $(OBJECTS_PROCESS) $(OBJECTS_LAB-COMPILER) 
									echo "CREATING EXECUTABLE..."
									$(LINK)


$(OBJECTS_LAB-COMPILER): $(OBJ_LAB-COMPILER_DIR)%.o: $(SRC_LAB-COMPILER_DIR)%.c | $(OBJ_LAB-COMPILER_DIR)
									echo "COMPILING COMPILER OBJECT ($@)"
									$(C_COMPILER) $(FLAGS) -g -o $@ -c $<


$(OBJECTS_PROCESS): $(OBJ_PROCESS_DIR)%.o: $(SRC_PROCESS_DIR)%.c | $(OBJ_PROCESS_DIR)
									echo "COMPILING PROCESS OBJECT ($@)"
									$(C_COMPILER) $(FLAGS) -g -o $@ -c $<


$(OBJ_LAB-COMPILER_DIR) $(OBJ_PROCESS_DIR):
									echo "CREATING OBJECT DIRECTORIES..."
									mkdir -p $@


clean:
									echo "REMOVING LAB-COMPILER OBJECT FILES..."
									rm -rf $(OBJ_LAB-COMPILER_DIR)
									echo "REMOVING PROCESS OBJECT FILES..."
									rm -rf $(OBJ_PROCESS_DIR)

.PHONY: clean all
.SILENT:
# 	-fsanitize=address