# You can define variables. These are literally just string substitutions that
# appear later in the code. You can refer to a variable X by $(X) or ${X}.
#
# Here we define our C compiler, in case we want to add or delete flags. It will
# show up as $(CC) in the rules of the Makefile.
#
CC = gcc

# Here we define the files that are the inputs to our project
SOURCES = matrix.c matrix_operations.c matrix_file_io.o example.c
HEADERS = matrix.h

# And here are the outputs. The second one is a substitution of the form
# $(var:a=b). It means, take every occurence of the pattern a in var and
# replace it by b. Thus, OBJECTS will become "matrix.o operations.o example.o".
TARGET = example
OBJECTS=$(SOURCES:.c=.o)

# Now we define rules. Each rule has the form
#
# target ... : dependencies ...
#        command
#        ...
#        ...
# ^ TAB ^

# This rule just says that making everything depends on the sources and the
# the targets. So if you do "make" or "make all", nothing will happen unless
# the sources and target need to be updated.
all: $(SOURCES) $(TARGET)

# Here we say that the target (example in this case) depends on the object
# files (which are compiled but not linked code). This rule goes and checks
# whether the objects need to be updated, and updates them if so. If the
# objects were updated, then run the commands. Here, the command is to compile
# the target from the objects. $@ refers to whatever is before the ":". the
# -o flag tells gcc the name of the binary (so it isn't a.out).
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# Here we define a rule schema. It says how to make any object file from its
# source. Here % is a stem wildcard that matches any target name. Because of
# the above rules, make will be looking for how to make, for example, matrix.o.
# This rule says how to make it. Note that $< matches the _first_ dependency,
# which is the c file, so this command wouldn't work if $(HEADERS) came first.
%.o: %.c $(HEADERS)
	$(CC) -c $<

# As usual, here's a way to clean up.
clean:
	rm -f $(TARGET) $(OBJECTS)
