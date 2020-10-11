CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
ODIR = build
SRCDIR = src

_DEPS = raymarching.h scene.h vector.h
DEPS = $(patsubst %,$(SRCDIR)/%,$(_DEPS))

_OBJ = render.o vector.o raymarching.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $<

ray: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o
