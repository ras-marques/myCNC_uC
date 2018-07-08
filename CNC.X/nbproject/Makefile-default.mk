#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/CNC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/CNC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c Library/uart.c Library/interface.c Library/config_pins.c Library/utils.c Library/timer2.c Library/timer3.c Library/timer4.c Library/delays.c Library/plot_manager.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/Library/uart.o ${OBJECTDIR}/Library/interface.o ${OBJECTDIR}/Library/config_pins.o ${OBJECTDIR}/Library/utils.o ${OBJECTDIR}/Library/timer2.o ${OBJECTDIR}/Library/timer3.o ${OBJECTDIR}/Library/timer4.o ${OBJECTDIR}/Library/delays.o ${OBJECTDIR}/Library/plot_manager.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/Library/uart.o.d ${OBJECTDIR}/Library/interface.o.d ${OBJECTDIR}/Library/config_pins.o.d ${OBJECTDIR}/Library/utils.o.d ${OBJECTDIR}/Library/timer2.o.d ${OBJECTDIR}/Library/timer3.o.d ${OBJECTDIR}/Library/timer4.o.d ${OBJECTDIR}/Library/delays.o.d ${OBJECTDIR}/Library/plot_manager.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/Library/uart.o ${OBJECTDIR}/Library/interface.o ${OBJECTDIR}/Library/config_pins.o ${OBJECTDIR}/Library/utils.o ${OBJECTDIR}/Library/timer2.o ${OBJECTDIR}/Library/timer3.o ${OBJECTDIR}/Library/timer4.o ${OBJECTDIR}/Library/delays.o ${OBJECTDIR}/Library/plot_manager.o

# Source Files
SOURCEFILES=main.c Library/uart.c Library/interface.c Library/config_pins.c Library/utils.c Library/timer2.c Library/timer3.c Library/timer4.c Library/delays.c Library/plot_manager.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/CNC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F4011
MP_LINKER_FILE_OPTION=,--script=p30F4011.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/uart.o: Library/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/uart.o.d 
	@${RM} ${OBJECTDIR}/Library/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/uart.c  -o ${OBJECTDIR}/Library/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/interface.o: Library/interface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/interface.o.d 
	@${RM} ${OBJECTDIR}/Library/interface.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/interface.c  -o ${OBJECTDIR}/Library/interface.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/interface.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/interface.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/config_pins.o: Library/config_pins.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/config_pins.o.d 
	@${RM} ${OBJECTDIR}/Library/config_pins.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/config_pins.c  -o ${OBJECTDIR}/Library/config_pins.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/config_pins.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/config_pins.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/utils.o: Library/utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/utils.o.d 
	@${RM} ${OBJECTDIR}/Library/utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/utils.c  -o ${OBJECTDIR}/Library/utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/utils.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/utils.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/timer2.o: Library/timer2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/timer2.o.d 
	@${RM} ${OBJECTDIR}/Library/timer2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/timer2.c  -o ${OBJECTDIR}/Library/timer2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/timer2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/timer2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/timer3.o: Library/timer3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/timer3.o.d 
	@${RM} ${OBJECTDIR}/Library/timer3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/timer3.c  -o ${OBJECTDIR}/Library/timer3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/timer3.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/timer3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/timer4.o: Library/timer4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/timer4.o.d 
	@${RM} ${OBJECTDIR}/Library/timer4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/timer4.c  -o ${OBJECTDIR}/Library/timer4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/timer4.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/timer4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/delays.o: Library/delays.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/delays.o.d 
	@${RM} ${OBJECTDIR}/Library/delays.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/delays.c  -o ${OBJECTDIR}/Library/delays.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/delays.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/delays.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/plot_manager.o: Library/plot_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/plot_manager.o.d 
	@${RM} ${OBJECTDIR}/Library/plot_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/plot_manager.c  -o ${OBJECTDIR}/Library/plot_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/plot_manager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/plot_manager.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/uart.o: Library/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/uart.o.d 
	@${RM} ${OBJECTDIR}/Library/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/uart.c  -o ${OBJECTDIR}/Library/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/uart.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/interface.o: Library/interface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/interface.o.d 
	@${RM} ${OBJECTDIR}/Library/interface.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/interface.c  -o ${OBJECTDIR}/Library/interface.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/interface.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/interface.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/config_pins.o: Library/config_pins.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/config_pins.o.d 
	@${RM} ${OBJECTDIR}/Library/config_pins.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/config_pins.c  -o ${OBJECTDIR}/Library/config_pins.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/config_pins.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/config_pins.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/utils.o: Library/utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/utils.o.d 
	@${RM} ${OBJECTDIR}/Library/utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/utils.c  -o ${OBJECTDIR}/Library/utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/utils.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/utils.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/timer2.o: Library/timer2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/timer2.o.d 
	@${RM} ${OBJECTDIR}/Library/timer2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/timer2.c  -o ${OBJECTDIR}/Library/timer2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/timer2.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/timer2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/timer3.o: Library/timer3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/timer3.o.d 
	@${RM} ${OBJECTDIR}/Library/timer3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/timer3.c  -o ${OBJECTDIR}/Library/timer3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/timer3.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/timer3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/timer4.o: Library/timer4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/timer4.o.d 
	@${RM} ${OBJECTDIR}/Library/timer4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/timer4.c  -o ${OBJECTDIR}/Library/timer4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/timer4.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/timer4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/delays.o: Library/delays.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/delays.o.d 
	@${RM} ${OBJECTDIR}/Library/delays.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/delays.c  -o ${OBJECTDIR}/Library/delays.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/delays.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/delays.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Library/plot_manager.o: Library/plot_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Library" 
	@${RM} ${OBJECTDIR}/Library/plot_manager.o.d 
	@${RM} ${OBJECTDIR}/Library/plot_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  Library/plot_manager.c  -o ${OBJECTDIR}/Library/plot_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Library/plot_manager.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/Library/plot_manager.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/CNC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/CNC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/CNC.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/CNC.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/CNC.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
