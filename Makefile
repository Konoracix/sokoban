
# output: main.o message.o
# 	g++ main.o message.o -o output

# main.o: main.cpp
# 	g++ -c main.cpp

# MapController.o: main.cpp
# 	g++ -c main.cpp

# message.o: message.cpp message.h
# 	g++ -c message.cpp

# clean: 
# 	rm *.o output

define uniq =
  $(eval seen :=)
  $(foreach _,$1,$(if $(filter $_,${seen}),,$(eval seen += $_)))
  ${seen}
endef

SRCDIR := .
OBJDIR := build

SRCS := $(shell find $(SRCDIR) -name "*.cpp")
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
TREE := $(patsubst %/,%,$(dir $(OBJS)))

.PHONY: all clean


__ : main
	./$(OBJDIR)/main

main: $(OBJS)
	g++ $^ -o $(OBJDIR)/$@

all: $(OBJS)

.SECONDEXPANSION:
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $$(@D)
	g++ -o $@ -c $<

$(call uniq, $(TREE)): %:
	mkdir -p $@

clean:
	$(RM) -r $(OBJDIR)