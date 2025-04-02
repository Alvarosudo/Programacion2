# Copyright (C) Programacion-II, DLSI, UA 2025

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
PR=3



#############
# VARIABLES #                     PUEDES CAMBIARLAS
#############--------------------------------------------------------------

# COMPILE OPTIONS
CXXFLAGS= -Wall -Wpedantic -Wextra -Wconversion -fsanitize=undefined -g --std=c++17
# LINK OPTIONS
LDFLAGS= -fsanitize=undefined


######################
# COMPUTED VARIABLES #            NO DEBES MODIFICARLAS
######################-----------------------------------------------------
# SOURCES
SRCS=$(wildcard *.cc)
# OBJETCS
OBJS=$(patsubst %.cc, %.o, $(SRCS))
# TAR FILE
TARF=$(shell basename "$$(pwd)")
#########------------------------------------------------------------------


#########
# RULES #                         NO DEBES MODIFICARLAS
#########------------------------------------------------------------------
all : p$(PR)

########
# CODE #
########
p$(PR) : $(OBJS)
	@echo '[7m[1m'Enlazando practica...'[0m'
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

#################
# Documentation #
#################
Doxyfile:
	@echo '[7m[1m'Generando Doxyfile...'[0m'
	@doxygen -g

#################
# PHONY TARGETS #
#################
run: p$(PR)
	@echo '[7m[1m'Ejecutando practica...'[0m'
	./p$(PR)

runv: p$(PR)
	@echo '[7m[1m'Ejecutando practica desde valgrind...'[0m'
	@valgrind --leak-check=full ./p$(PR)

vstats: p$(PR)
	@echo '[7m[1m'Estadisticas de valgrind...'[0m'
	@valgrind --leak-check=full ./p$(PR) 2>&1 | grep "lost\|reachable" ; true

debug: p$(PR)
	@echo '[7m[1m'Depurando practica...'[0m'
	@gdb --tui p$(PR)

tgz: clean
	@echo '[7m[1mCreando archivo: irp2-p3.tgz ...[0m'
	@cd ..; tar cfz irp2-p3.tgz irp2-p3; mv irp2-p3.tgz irp2-p3; cd irp2-p3


clean:
	@echo '[7m[1m'Limpiando...'[0m'
	@rm -r -f *~ p$(PR) *.o *.tgz *.bak doc

doc: Doxyfile
	@echo '[7m[1m'Generando documentacion...'[0m'
	@doxygen


.PHONY: clean tgz run debug doc all
#########------------------------------------------------------------------
