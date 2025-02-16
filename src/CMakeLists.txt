#Lista os arquivos a serem adicionados
set(SRC_FILES 
    ${CMAKE_SOURCE_DIR}/src/MainLED.c
    ${CMAKE_SOURCE_DIR}/src/General.c
    ${CMAKE_SOURCE_DIR}/src/LEDMatrix.c
    ${CMAKE_SOURCE_DIR}/src/Interrupt.c
    ${CMAKE_SOURCE_DIR}/src/ssd1306.c
    ${CMAKE_SOURCE_DIR}/src/Interfaces.c
    ${CMAKE_SOURCE_DIR}/src/Joystick.c
)

#Adiciona ao executável no CMakeLists da pasta de origem
target_sources(${PROJECT_NAME} PRIVATE 
    ${SRC_FILES}
)
