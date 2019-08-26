#******************************************************************************
#
# Makefile - Makefile for building this project.
#
# Copyright (c) 2012-2017 Texas Instruments Incorporated.  All rights reserved.
# Software License Agreement
#
# Texas Instruments (TI) is supplying this software for use solely and
# exclusively on TI's microcontroller products. The software is owned by
# TI and/or its suppliers, and is protected under applicable copyright
# laws. You may not combine this software with "viral" open-source
# software in order to form a larger program.
#
# THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
# NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
# NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
# CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
# DAMAGES, FOR ANY REASON WHATSOEVER.
#
# This is part of revision 2.1.4.178 of the EK-TM4C123GXL Firmware Package.
#
#******************************************************************************

#******************************************************************************
#
# Modified by Zee Lv
# Nov 6, 2018
#
#******************************************************************************

#******************************************************************************
#
# Modified by Juan Pablo Pino
# Jan, 2019
#
#******************************************************************************

#
# Defines project name
#
TARGET=applet

#
# The root directory.
#
ROOT=../..

#
# Include the common make definitions.
#
include ${ROOT}/common.mk

#
# Where to find header files that do not live in the source directory.
#
IPATH = \
	${ROOT}/inc		          \
	$/inc           				\

#
# The default rule
#
all: ${BUILDPATH}/$(TARGET)


# *****************************************************************************
# Add object files you need below
# *****************************************************************************
${BUILDPATH}/$(TARGET): src/main.o
# *****************************************************************************

#
# The rule to clean out all the build products.
#
clean:
	@echo "  CLEAN"
	@rm -rf ${BUILDPATH} ${wildcard *~} 2> /dev/null
	@find . -name "*.o" -type f -delete
	@find . -name "*.d" -type f -delete
