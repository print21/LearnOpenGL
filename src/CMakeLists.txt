
find_package(Qt5 COMPONENTS Core Gui Widgets OpenGL)

set(GL_SRCS
    gl/GLFunc.cpp
    gl/GLFunc.h
)

source_group("GL" FILES ${GL_SRCS})

set(WIDGETS_SRCS
    widgets/QtOpenGLWidget.cpp
    widgets/QtOpenGLWidget.h
)

source_group("Widgets" FILES ${WIDGETS_SRCS})

set(GLDEMO_SRCS
    ${GL_SRCS}
    ${WIDGETS_SRCS}
    main/main.cpp
    main/MainWindow.cpp
    main/MainWindow.h
)

set(GLDEMO_LIBS
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::OpenGL
    GLEW::glew_s
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(GLDemo ${GLDEMO_SRCS})
target_link_libraries(GLDemo ${GLDEMO_LIBS})

set_target_properties(GLDemo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build/$<CONFIG>)
set_target_properties(GLDemo PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib/$<CONFIG>)
set_target_properties(GLDemo PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib/$<CONFIG>)

add_custom_command(TARGET GLDemo 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${QT5_BIN_DIR}/Qt5Core$<$<CONFIG:Debug>:d>.dll ${CMAKE_BINARY_DIR}/Build/$<CONFIG>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${QT5_BIN_DIR}/Qt5Gui$<$<CONFIG:Debug>:d>.dll ${CMAKE_BINARY_DIR}/Build/$<CONFIG>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${QT5_BIN_DIR}/Qt5Widgets$<$<CONFIG:Debug>:d>.dll ${CMAKE_BINARY_DIR}/Build/$<CONFIG>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${QT5_BIN_DIR}/Qt5OpenGL$<$<CONFIG:Debug>:d>.dll ${CMAKE_BINARY_DIR}/Build/$<CONFIG>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${QT5_BIN_DIR}/Qt5Network$<$<CONFIG:Debug>:d>.dll ${CMAKE_BINARY_DIR}/Build/$<CONFIG>
)