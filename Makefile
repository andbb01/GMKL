GO = GameObjects/*.cpp
GrM = GraphicsManager/*.cpp
BoBJ = BasicObjects/*.cpp
PhY = GameObjects/PhysicsObject/*.cpp
TXT = GameObjects/TextObject/*.cpp

GrM_H = GraphicsManager/*.h
GO_H = GameObjects/*.h
PhY_H = GameObjects/PhysicsObject/*.h
TXT_H = GameObjects/TextObject/*.h
GM_H = GameManager/*.h
H = GameMaker.h
BoBJ_H = BasicObjects/*.h

LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf
compiler = g++

CompileGMKL:
	$(compiler) $(GrM_H) $(GO_H) $(GM_H) $(H) $(BoBJ_H) $(PhY_H) $(TXT_H)
	$(compiler) -c $(GO) $(GrM) $(BoBJ) $(PhY) $(TXT) $(LIBS)

BuildGMKL:
	ar -rc libGMKL.a *.o

InfoGMKL:
	tree
	wc $(GrM_H) $(GO_H) $(GM_H) $(H) $(BoBJ_H) $(PhY_H) $(GO) $(TXT) $(TXT_H) $(GrM) $(BoBJ) $(PhY)

ClearCompilation:
	rm *.o GraphicsManager/*.h.gch GameObjects/*.h.gch GameManager/*.h.gch GameMaker.h.gch BasicObjects/*.h.gch GameObjects/PhysicsObject/*.h.gch GameObjects/TextObject/*.h.gch

All:
	$(compiler) $(GrM_H) $(GO_H) $(GM_H) $(H) $(BoBJ_H) $(PhY_H)
	$(compiler) -c $(GO) $(GrM) $(BoBJ) $(PhY) $(LIBS)
	ar -rc libGMKL.a *.o
	rm *.o GraphicsManager/*.h.gch GameObjects/*.h.gch GameManager/*.h.gch GameMaker.h.gch BasicObjects/*.h.gch GameObjects/PhysicsObject/*.h.gch GameObjects/TextObject/*.h.gch
