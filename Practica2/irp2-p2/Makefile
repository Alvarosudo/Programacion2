# Copyright (C) Programacion-II, DLSI, UA 2023

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
PR=2

#############
# VARIABLES #                     PUEDES CAMBIARLAS
#############--------------------------------------------------------------

# COMPILE OPTIONS
CXXFLAGS= -Wall -Wpedantic -Wextra -Wconversion -fsanitize=undefined -g --std=c++17
# LINK OPTIONS
LDFLAGS= -fsanitize=undefined -L./lib


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
all : listmain stackmain queuemain treemain graphmain


#################
#    ERRORS     #
#################
lib: liberror.a

liberror.a : lib/error.o
	ar rcs lib/liberror.a lib/error.o

#################
#    EXAMPLES   #
#################

listmain: listmain.o list.o
	$(CXX) $(LDFLAGS) listmain.o list.o -o $@

stackmain: lib stackmain.o stack.o list.o
	$(CXX) $(LDFLAGS) stackmain.o stack.o list.o -lerror -o $@

queuemain: lib queuemain.o queue.o list.o
	$(CXX) $(LDFLAGS) queuemain.o queue.o list.o -lerror -o $@

treemain: treemain.o tree.o
	$(CXX) $(LDFLAGS) treemain.o tree.o -o $@

graphmain: graphmain.o graph.o
	$(CXX) $(LDFLAGS) graphmain.o graph.o -o $@

runlistmain: listmain
	@echo '[7m[1m'Ejecutando listmain...'[0m'
	./listmain

runstackmain: stackmain
	@echo '[7m[1m'Ejecutando stackmain...'[0m'
	./stackmain

runqueuemain: queuemain
	@echo '[7m[1m'Ejecutando queuemain...'[0m'
	./queuemain

runtreemain: treemain
	@echo '[7m[1m'Ejecutando treemain...'[0m'
	./treemain

rungraphmain: graphmain
	@echo '[7m[1m'Ejecutando graphmain...'[0m'
	./graphmain

runvlistmain: listmain
	@echo '[7m[1m'Ejecutando listmain desde valgrind...'[0m'
	@valgrind --leak-check=full ./listmain

runvstackmain: stackmain
	@echo '[7m[1m'Ejecutando stackmain desde valgrind...'[0m'
	@valgrind --leak-check=full ./stackmain

runvqueuemain: queuemain
	@echo '[7m[1m'Ejecutando queuemain desde valgrind...'[0m'
	@valgrind --leak-check=full ./queuemain

runvtreemain: treemain
	@echo '[7m[1m'Ejecutando treemain desde valgrind...'[0m'
	@valgrind --leak-check=full ./treemain

runvgraphmain: graphmain
	@echo '[7m[1m'Ejecutando graphmain desde valgrind...'[0m'
	@valgrind --leak-check=full ./graphmain

#################
# PHONY TARGETS #
#################

tgz: clean
	@echo '[7m[1mCreando archivo: $(TARF).tgz ...[0m'
	@cd ..;tar cfz $(TARF).tgz $(TARF); \
	 mv $(TARF).tgz $(TARF);cd $(TARF)

clean:
	@echo '[7m[1m'Limpiando...'[0m'
	@rm -r -f *~ p$(PR) $(OBJS) *.tgz listmain stackmain queuemain treemain graphmain lib/*~ lib/*.o lib/*.a

.PHONY: clean tgz all
#########------------------------------------------------------------------
