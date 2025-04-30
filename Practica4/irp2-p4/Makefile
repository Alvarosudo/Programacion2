# Copyright (C) Programacion-II, DLSI, UA 2019

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

###################################
# ACTUALIZA EL NUMERO DE PRACTICA #
###################################
PR=4

#############
# VARIABLES #                     PUEDES CAMBIARLAS
#############--------------------------------------------------------------

# COMPILE OPTIONS
CXXFLAGS= -Wall -Wpedantic -Wextra -Wconversion -fsanitize=undefined -g --std=c++17
# LINK OPTIONS
LDFLAGS= -fsanitize=undefined

# SOURCES FOLDER
SRC=src
# BINARIES FOLDER
BINDIR=bin

######################
# COMPUTED VARIABLES #            NO DEBES MODIFICARLAS
######################-----------------------------------------------------
# SOURCES
SRCS=$(wildcard $(SRC)/*.cc)
# OBJETCS
OBJS=$(patsubst $(SRC)/%.cc, $(BINDIR)/%.o, $(SRCS))
# TAR FILE
TARF=$(shell basename "$$(pwd)")
#TARF=irp2-p4
# Backup Files
BUF=$(shell find . -name *~)
#########------------------------------------------------------------------


#########
# RULES #                         NO DEBES MODIFICARLAS
#########------------------------------------------------------------------
all: $(BINDIR)/p$(PR)

doc:
	@doxygen

$(BINDIR):
	@mkdir -p $@

$(BINDIR)/%.o : $(SRC)/%.cc
	$(CXX) -c $(CXXFLAGS) $? -o $@

$(BINDIR)/main$(PR).o : $(SRC)/container.tcc $(SRC)/main.cc
	$(CXX) -c $(CXXFLAGS) $(SRC)/main$(PR).cc -o $@

########
# CODE #
########
$(BINDIR)/p$(PR) : $(BINDIR) $(OBJS)
	@echo '[7m[1m'Enlazando practica...'[0m'
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

#################
# PHONY TARGETS #
#################
run: $(BINDIR)/p$(PR)
	@echo '[7m[1m'Ejecutando practica...'[0m'
	$(BINDIR)/p$(PR)

runv: $(BINDIR)/p$(PR)
	@echo '[7m[1m'Ejecutando practica desde valgrind...'[0m'
	@valgrind --leak-check=full $(BINDIR)/p$(PR)

vstats: $(BINDIR)/p$(PR)
	@echo '[7m[1m'Estadisticas de valgrind...'[0m'
	@valgrind --leak-check=full $(BINDIR)/p$(PR) 2>&1 | grep "lost\|reachable" ; true

debug: $(BINDIR)/p$(PR)
	@echo '[7m[1m'Depurando practica...'[0m'
	@gdb --tui $(BINDIR)/p$(PR)

tgz:
	@echo '[7m[1mCreando archivo: $(TARF).tgz ...[0m'
	@rm -rf $(TARF); mkdir -p $(TARF)/src
	@cp src/*.cc src/*.tcc $(TARF)/src
	@tar cfz $(TARF).tgz $(TARF)
	@rm -rf $(TARF)

clean:
	@echo '[7m[1m'Limpiando...'[0m'
	@rm -r -f $(BUF) $(BINDIR) $(TARF).tgz

.PHONY: clean tgz run debug all doc
#########------------------------------------------------------------------
