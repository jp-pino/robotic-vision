#******************************************************************************
#
# definitions for tools to be used.
#
#******************************************************************************

#
# The command for calling the compiler.
#
CC=gcc

#
# The command for calling gdb.
#
GDB=gdb


#******************************************************************************
#
# definitions for common paths to be used.
#
#******************************************************************************

BUILDPATH = build

#******************************************************************************
#
# FLAGS
#
#******************************************************************************

#
# The flags passed to the compiler.
# Tell the compiler to include debugging information if the DEBUG environment
# variable is set.
#
CFLAGS=-g -D DEBUG -O3

#
# Add the include file paths to CFLAGS.
#
CFLAGS+=${patsubst %,-I%,${subst :, ,${IPATH}}}


#******************************************************************************
#
# Rule definitions
#
#******************************************************************************


#
# The rule for building the object file from each C source file.
#
%.o: %.c
	@echo "  BUILD"
	@echo ${CC} -c ${CFLAGS} -o ${@} ${<}
	@${CC} -c ${CFLAGS} -o ${@} ${<}

#
# The rule for linking the application.
#
${BUILDPATH}/${TARGET}:
	@mkdir -p ${BUILDPATH}
	@echo "  MAKE"
	@echo ${CC} -o ${@} ${^} $(CFLAGS)
	@${CC} -o ${@} ${^} $(CFLAGS)



#
# The rule for running.
#
run:
	@./${BUILDPATH}/${TARGET}

#
# The rule for showing results.
#
show:
	@open ./out/.

#
# Debug depends on the axf, but if we put the dependency as axf here, it
# runs into an infinite loop for checking the existence of axf file from
# make all. Since bin file and axf file are created at the same time, we
# we can just move the dependency to the bin file.
#
# debug: ${BUILDPATH}/$(PROJ_NAME).bin
# 	$(OPENOCD) --file /usr/local/Cellar/open-ocd/HEAD-8f518d3/share/openocd/scripts/board/ek-tm4c123gxl.cfg &
# 	$(GDB) ${BUILDPATH}/$(PROJ_NAME).axf
