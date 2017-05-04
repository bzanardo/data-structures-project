CMP = g++
CLASS = board
CLASS2 = movement
MAIN = main
EXEC = chess

$(EXEC): $(CLASS).o $(CLASS2).o $(MAIN).o
	$(CMP) $(CLASS).o $(CLASS2).o $(MAIN).o -std=c++11 -o $(EXEC)
	
$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp -o $(CLASS).o

$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h
	$(CMP) -c $(CLASS2).cpp -o $(CLASS2).o

$(MAIN).o: $(MAIN).cpp $(CLASS).h $(CLASS2).h
	$(CMP) -c $(MAIN).cpp -o $(MAIN).o

clean:
	rm *.o
	rm $(EXEC)
