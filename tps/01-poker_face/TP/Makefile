CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/poker.o $(OBJ)/card.o $(OBJ)/deck.o $(OBJ)/hand.o $(OBJ)/player.o $(OBJ)/bets_queue.o $(OBJ)/round.o $(OBJ)/round_queue.o $(OBJ)/match.o $(OBJ)/memlog.o

HDRS = $(INC)/card.hpp $(INC)/deck.hpp $(INC)/hand.hpp $(INC)/player.hpp $(INC)/bets_queue.hpp $(INC)/round.hpp $(INC)/round_queue.hpp $(INC)/match.hpp $(INC)/memlog.hpp

CFLAGS = -pg -Wall -c -I$(INC)

ANALISAMEM = ./analisamem/bin/analisamem
EXE = $(BIN)/tp1.exe

GPROF = analises/gprof
# --------------------------------------------
MEM_EXEC_LOGS = analises/mem/logs
MEM_INPUTS = analises/mem/partida
MEM_OUTPUTS = analises/mem/resultados
# --------------------------------------------
PERF_EXEC_LOGS = analises/perf/logs
PERF_INPUTS = analises/perf/partidas
PERF_OUTPUTS = analises/perf/resultados
# --------------------------------------------
TEST_INPUTS = in_and_expected_outs/in
MY_TEST_OUTPUTS = in_and_expected_outs/out
TEST_OUTPUTS = in_and_expected_outs/expected_out

# folders:
# 	@echo criando estrutura de pastas para análise dos resultados.

# 	@ mkdir analises analises/mem analises/perf

# 	@ mkdir $(MEM_EXEC_LOGS) $(PERF_EXEC_LOGS) $(GPROF) $(MEM_INPUTS) $(MEM_OUTPUTS) $(PERF_INPUTS) $(PERF_OUTPUTS)

# mem: $(EXE)
# 	$(EXE) -i $(MEM_INPUTS)/entrada.txt -o $(MEM_INPUTS)/saida.txt -p $(MEM_EXEC_LOGS)/memlog.out -l

# 	rm -rf $(MEM_OUTPUTS)

# 	mkdir $(MEM_OUTPUTS)

# 	$(ANALISAMEM) -i $(MEM_EXEC_LOGS)/memlog.out -p $(MEM_OUTPUTS)/mem_analysis

# perf: $(EXE)
# 	$(EXE) -i $(PERF_INPUTS)/entrada_1000.out -o $(PERF_INPUTS)/saida_1000.out -p $(PERF_EXEC_LOGS)/perf_res_1000.out

# 	$(EXE) -i $(PERF_INPUTS)/entrada_5000.out -o $(PERF_INPUTS)/saida_5000.out -p $(PERF_EXEC_LOGS)/perf_res_5000.out
	
# 	$(EXE) -i $(PERF_INPUTS)/entrada_10000.out -o $(PERF_INPUTS)/saida_10000.out -p $(PERF_EXEC_LOGS)/perf_res_10000.out

# 	$(EXE) -i $(PERF_INPUTS)/entrada_15000.out -o $(PERF_INPUTS)/saida_15000.out -p $(PERF_EXEC_LOGS)/perf_res_15000.out
	
# 	$(EXE) -i $(PERF_INPUTS)/entrada_20000.out -o $(PERF_INPUTS)/saida_20000.out -p $(PERF_EXEC_LOGS)/perf_res_20000.out

# gprof: $(EXE)
# 	$(EXE) -i $(PERF_INPUTS)/entrada_20000.out -o $(PERF_INPUTS)/saida_20000.out -p $(GPROF)/perf_res_20000.out
# 	gprof $(EXE) gmon.out > $(GPROF)/perf_res_20000.txt

test: $(EXE)
	for number in 1 2 3 4 5 6 7 8; do \
	$(EXE) -i $(TEST_INPUTS)/entrada_$$number.txt -o $(MY_TEST_OUTPUTS)/saida_$$number.txt; \
	diff $(MY_TEST_OUTPUTS)/saida_$$number.txt $(TEST_OUTPUTS)/saida_$$number.txt; \
	done

$(BIN)/tp1.exe: $(OBJS)
	$(CC) -pg -o $(BIN)/tp1.exe $(OBJS) $(LIBS)

$(OBJ)/poker.o: $(HDRS) $(SRC)/poker.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/poker.o $(SRC)/poker.cpp 

$(OBJ)/card.o: $(HDRS) $(SRC)/card.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/card.o $(SRC)/card.cpp 

$(OBJ)/deck.o: $(HDRS) $(SRC)/deck.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/deck.o $(SRC)/deck.cpp 

$(OBJ)/hand.o: $(HDRS) $(SRC)/hand.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/hand.o $(SRC)/hand.cpp
	
$(OBJ)/player.o: $(HDRS) $(SRC)/player.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/player.o $(SRC)/player.cpp

$(OBJ)/bets_queue.o: $(HDRS) $(SRC)/bets_queue.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/bets_queue.o $(SRC)/bets_queue.cpp

$(OBJ)/round.o: $(HDRS) $(SRC)/round.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/round.o $(SRC)/round.cpp

$(OBJ)/round_queue.o: $(HDRS) $(SRC)/round_queue.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/round_queue.o $(SRC)/round_queue.cpp

$(OBJ)/match.o: $(HDRS) $(SRC)/match.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/match.o $(SRC)/match.cpp

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.cpp

clean:
	rm $(OBJ)/*.o $(BIN)/tp1.exe