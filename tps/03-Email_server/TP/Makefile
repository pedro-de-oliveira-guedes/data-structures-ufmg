CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin

OBJS = $(OBJ)/emailContent.o $(OBJ)/memlog.o $(OBJ)/email.o $(OBJ)/inbox.o $(OBJ)/operations.o $(OBJ)/server.o $(OBJ)/session.o $(OBJ)/main.o

HDRS = $(INC)/emailContent.hpp $(INC)/memlog.hpp $(INC)/email.hpp $(INC)/operations.hpp $(INC)/inbox.hpp $(INC)/server.hpp $(INC)/session.hpp

CFLAGS = -pg -Wall -c -I$(INC)

ANALISAMEM = ./analisamem/bin/analisamem
EXE = $(BIN)/tp3.exe

GPROF = analises/gprof
# --------------------------------------------
MEM_EXEC_LOGS = analises/mem/logs
MEM_INPUTS = analises/mem/in_out
MEM_OUTPUTS = analises/mem/resultados
# --------------------------------------------
PERF_EXEC_LOGS = analises/perf/logs
PERF_INPUTS = analises/perf/in_out
# --------------------------------------------
TEST_INPUTS = tests/inputs
TEST_OUTPUTS = tests/outputs
MY_TEST_OUTPUTS = tests/my_outputs

# folders:
# 	@echo criando estrutura de pastas para análise dos resultados.

# 	@ mkdir analises analises/mem analises/perf

# 	@ mkdir $(MEM_EXEC_LOGS) $(PERF_EXEC_LOGS) $(GPROF) $(MEM_INPUTS) $(MEM_OUTPUTS) $(PERF_INPUTS) $(PERF_OUTPUTS)

# mem: $(EXE)
# 	$(EXE) -i $(MEM_INPUTS)/entrada.txt -o $(MEM_INPUTS)/saida.txt -p $(MEM_EXEC_LOGS)/memlog.out -l

# 	rm -rf $(MEM_OUTPUTS)

# 	mkdir $(MEM_OUTPUTS)

# 	$(ANALISAMEM) -i $(MEM_EXEC_LOGS)/memlog.out -p $(MEM_OUTPUTS)/mem_analysis

# 	gnuplot $(MEM_OUTPUTS)/*.gp

# perf: $(EXE)
# 	$(EXE) -i $(PERF_INPUTS)/entrada_1.out -o $(PERF_INPUTS)/saida_1.out -p $(PERF_EXEC_LOGS)/perf_res_1.out

# 	$(EXE) -i $(PERF_INPUTS)/entrada_2.out -o $(PERF_INPUTS)/saida_2.out -p $(PERF_EXEC_LOGS)/perf_res_2.out
	
# 	$(EXE) -i $(PERF_INPUTS)/entrada_3.out -o $(PERF_INPUTS)/saida_3.out -p $(PERF_EXEC_LOGS)/perf_res_3.out

# 	$(EXE) -i $(PERF_INPUTS)/entrada_4.out -o $(PERF_INPUTS)/saida_4.out -p $(PERF_EXEC_LOGS)/perf_res_4.out
	
# 	$(EXE) -i $(PERF_INPUTS)/entrada_5.out -o $(PERF_INPUTS)/saida_5.out -p $(PERF_EXEC_LOGS)/perf_res_5.out

# gprof: $(EXE)
# 	$(EXE) -i $(PERF_INPUTS)/entrada_5.out -o $(PERF_INPUTS)/saida_5.out -p $(GPROF)/perf_res_5.out
# 	gprof $(EXE) gmon.out > $(GPROF)/perf_res_5.txt

# test:
# 	@ echo "Testing the program..."
# 	@ for number in 1 2 3 4; do \
# 	$(EXE) -I $(TEST_INPUTS)/entrada_$$number.txt -O $(MY_TEST_OUTPUTS)/saida_$$number.txt; \
# 	diff $(MY_TEST_OUTPUTS)/saida_$$number.txt $(TEST_OUTPUTS)/saida_$$number.txt; \
# 	done
# 	@ echo "Test finished successfully!"

$(EXE): $(OBJS)
	$(CC) -pg -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/emailContent.o: $(HDRS) $(SRC)/emailContent.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/emailContent.o $(SRC)/emailContent.cpp

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.cpp 

$(OBJ)/email.o: $(HDRS) $(SRC)/email.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/email.o $(SRC)/email.cpp 

$(OBJ)/inbox.o: $(HDRS) $(SRC)/inbox.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/inbox.o $(SRC)/inbox.cpp 

$(OBJ)/operations.o: $(HDRS) $(SRC)/operations.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/operations.o $(SRC)/operations.cpp 

$(OBJ)/server.o: $(HDRS) $(SRC)/server.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/server.o $(SRC)/server.cpp 

$(OBJ)/session.o: $(HDRS) $(SRC)/session.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/session.o $(SRC)/session.cpp 

clean:
	rm $(OBJ)/*.o $(EXE)