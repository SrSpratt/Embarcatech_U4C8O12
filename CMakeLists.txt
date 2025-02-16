# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Ajusta caminhos e versões
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if(EXISTS ${picoVscode})
    include(${picoVscode})
endif()

set(PICO_BOARD pico CACHE STRING "Board type")

# Ajusta a menor versão requerida do CMake para o projeto
cmake_minimum_required(VERSION 3.12)

# Inclui as funções de construção do Kit Pico
include(${USERHOME}/.pico-sdk/sdk/2.1.0/external/pico_sdk_import.cmake)

# Define o nome do projeto
project(Interrupts C CXX ASM)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Define as versões de C e C++ a serem utilizadas
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Cria um subdiretório no projeto, para que sejam referenciadas as bibliotecas
pico_sdk_init()

# Adiciona a main
add_executable(${PROJECT_NAME}
    main.c
)

# Adiciona os arquivos de fonte da pasta src
add_subdirectory(src)

#Cria os arquivos: map, bin, hex e uf2
pico_add_extra_outputs(${PROJECT_NAME})

pico_generate_pio_header(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/PIO_U4C6.pio)

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    hardware_pio
    hardware_adc
    hardware_clocks
    hardware_gpio
    hardware_i2c
)

#Indica o diretório de cabeçalhos
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Ligando o usb, desligando uart
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 1)
