EXEC:=toylang
SRC_DIR=compiler
OUTPUT_DIR=bin
SOURCES:= $(shell find ${SRC_DIR} -type f -name "*.c")
OBJECTS= $(SOURCES:.c=.o)
# $(info $(OBJECTS))
CFLAGS= -Wall -Wextra -pedantic -g -std=c99

all: ${OUTPUT_DIR} $(OBJECTS)
	gcc $(OBJECTS) $(CFLAGS) -o ${OUTPUT_DIR}/$(EXEC)

run: all
	@./${OUTPUT_DIR}/${EXEC}

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

${OUTPUT_DIR}:
	@mkdir ${OUTPUT_DIR}

clean:
	@rm -rfv ${SRC_DIR}/*.o
	@rm -rfv ${OUTPUT_DIR}
