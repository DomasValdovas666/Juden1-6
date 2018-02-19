#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Juden1-6-master-Makefile.mk

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AbstractAppState.o \
	${OBJECTDIR}/Button.o \
	${OBJECTDIR}/Checkbox.o \
	${OBJECTDIR}/ClientListencer.o \
	${OBJECTDIR}/ClientMain.o \
	${OBJECTDIR}/ExitButton.o \
	${OBJECTDIR}/GameManager.o \
	${OBJECTDIR}/GuiAppState.o \
	${OBJECTDIR}/GuiRect.o \
	${OBJECTDIR}/GuiText.o \
	${OBJECTDIR}/InputManager.o \
	${OBJECTDIR}/Key.o \
	${OBJECTDIR}/Listbox.o \
	${OBJECTDIR}/OptionsButton.o \
	${OBJECTDIR}/Player.o \
	${OBJECTDIR}/ServerMain.o \
	${OBJECTDIR}/Slider.o \
	${OBJECTDIR}/StateManager.o \
	${OBJECTDIR}/Textbox.o \
	${OBJECTDIR}/Util.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=/usr/lib/libOgreMain.so /usr/lib/libboost_system.so /usr/lib/libOpenGL.so /usr/lib/libsfml-audio.so /usr/lib/libsfml-network.so /usr/lib/libSDL.so /usr/lib/libOIS.so /usr/lib/libOgreOverlay.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juden1-6-master

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juden1-6-master: /usr/lib/libOgreMain.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juden1-6-master: /usr/lib/libboost_system.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juden1-6-master: /usr/lib/libOpenGL.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juden1-6-master: /usr/lib/libsfml-audio.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juden1-6-master: /usr/lib/libsfml-network.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juden1-6-master: /usr/lib/libSDL.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juden1-6-master: /usr/lib/libOIS.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juden1-6-master: /usr/lib/libOgreOverlay.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juden1-6-master: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juden1-6-master ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/AbstractAppState.o: AbstractAppState.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractAppState.o AbstractAppState.cpp

${OBJECTDIR}/Button.o: Button.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Button.o Button.cpp

${OBJECTDIR}/Checkbox.o: Checkbox.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Checkbox.o Checkbox.cpp

${OBJECTDIR}/ClientListencer.o: ClientListencer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ClientListencer.o ClientListencer.cpp

${OBJECTDIR}/ClientMain.o: ClientMain.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ClientMain.o ClientMain.cpp

${OBJECTDIR}/ExitButton.o: ExitButton.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ExitButton.o ExitButton.cpp

${OBJECTDIR}/GameManager.o: GameManager.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GameManager.o GameManager.cpp

${OBJECTDIR}/GuiAppState.o: GuiAppState.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GuiAppState.o GuiAppState.cpp

${OBJECTDIR}/GuiRect.o: GuiRect.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GuiRect.o GuiRect.cpp

${OBJECTDIR}/GuiText.o: GuiText.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GuiText.o GuiText.cpp

${OBJECTDIR}/InputManager.o: InputManager.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InputManager.o InputManager.cpp

${OBJECTDIR}/Key.o: Key.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Key.o Key.cpp

${OBJECTDIR}/Listbox.o: Listbox.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Listbox.o Listbox.cpp

${OBJECTDIR}/OptionsButton.o: OptionsButton.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OptionsButton.o OptionsButton.cpp

${OBJECTDIR}/Player.o: Player.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Player.o Player.cpp

${OBJECTDIR}/ServerMain.o: ServerMain.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ServerMain.o ServerMain.cpp

${OBJECTDIR}/Slider.o: Slider.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Slider.o Slider.cpp

${OBJECTDIR}/StateManager.o: StateManager.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StateManager.o StateManager.cpp

${OBJECTDIR}/Textbox.o: Textbox.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Textbox.o Textbox.cpp

${OBJECTDIR}/Util.o: Util.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I/usr/include/OIS -I/usr/include/SFML -I/usr/include/SDL -I/usr/include/OGRE -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Util.o Util.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOIS.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libboost_system.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOpenGL.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-network.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOgreOverlay.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libOgreMain.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libSDL.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsfml-audio.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/juden1-6-master

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
