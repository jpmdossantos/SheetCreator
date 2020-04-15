################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/PulseLoader.cpp \
../src/PulseLoader_test.cpp \
../src/ResultSheet.cpp \
../src/ResultSheet_test.cpp \
../src/tests_main.cpp 

OBJS += \
./src/PulseLoader.o \
./src/PulseLoader_test.o \
./src/ResultSheet.o \
./src/ResultSheet_test.o \
./src/tests_main.o 

CPP_DEPS += \
./src/PulseLoader.d \
./src/PulseLoader_test.d \
./src/ResultSheet.d \
./src/ResultSheet_test.d \
./src/tests_main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -lboost_system-mt -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


