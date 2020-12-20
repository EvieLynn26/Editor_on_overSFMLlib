CXX = g++
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system
OBJDIR = object


link: main.cpp $(OBJDIR)/button.o $(OBJDIR)/color.o $(OBJDIR)/Engine.o $(OBJDIR)/window.o $(OBJDIR)/event_system.o $(OBJDIR)/pointmap.o $(OBJDIR)/editor.o
	$(CXX) $^ $(LDLIBS) -o main

make_all:
	$(CXX) main.cpp Editor+Engine/source/button.cpp Editor+Engine/source/color.cpp Editor+Engine/source/Engine.cpp Editor+Engine/source/window.cpp Editor+Engine/source/event_system.cpp Editor+Engine/source/pointmap.cpp Editor+Engine/source/editor.cpp $^ $(LDLIBS) -o main


$(OBJDIR)/button.o: Editor+Engine/source/button.cpp Editor+Engine/include/button.hpp
	$(CXX) -c Editor+Engine/source/button.cpp -o $(OBJDIR)/button.o

$(OBJDIR)/color.o: Editor+Engine/source/color.cpp Editor+Engine/include/color.hpp
	$(CXX) -c Editor+Engine/source/color.cpp -o $(OBJDIR)/color.o

$(OBJDIR)/SFML_engine.o: Editor+Engine/source/Engine.cpp graphics/include/Engine.hpp
	$(CXX) -c Editor+Engine/source/Engine.cpp -o $(OBJDIR)/Engine.o

$(OBJDIR)/window.o: Editor+Engine/source/window.cpp Editor+Engine/include/window.hpp
	$(CXX) -c Editor+Engine/source/window.cpp -o $(OBJDIR)/window.o

$(OBJDIR)/event_system.o: Editor+Engine/source/event_system.cpp Editor+Engine/include/event_system.hpp
	$(CXX) -c Editor+Engine/source/event_system.cpp -o $(OBJDIR)/event_system.o

$(OBJDIR)/pointmap.o: Editor+Engine/source/pointmap.cpp Editor+Engine/include/pointmap.hpp
	$(CXX) -c Editor+Engine/source/pointmap.cpp -o $(OBJDIR)/pointmap.o

$(OBJDIR)/EDITOR.o: Editor+Engine/source/editor.cpp Editor+Engine/include/editor.hpp
	$(CXX) -c Editor+Engine/source/editor.cpp -o $(OBJDIR)/editor.o
