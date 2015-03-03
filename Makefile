CPPFLAGS=-g 
LDLIBS += -L/usrs/include/-lxerces-c

OUTFILE=xmldemo
all: $(OUTFILE)

OBJ	=	XmlDomDocument.o main.o
$(OUTFILE): g++ $(OBJS) $(LDLIBS) -o $(OUTFILE) 

