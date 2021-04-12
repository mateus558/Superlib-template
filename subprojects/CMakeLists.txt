add_subdirectory(liba)
add_subdirectory(libb)
add_subdirectory(libc)

set(LIBMAIN ${PROJECT_NAME})

set(OBJECTS $<TARGET_OBJECTS:${LIBA_TARGET}> )
set(OBJECTS $<TARGET_OBJECTS:${LIBB_TARGET}> )
set(OBJECTS $<TARGET_OBJECTS:${LIBC_TARGET}> )

add_library(${PROJECT_NAME} SHARED $<TARGET_OBJECTS:superlib-liba>
                                   $<TARGET_OBJECTS:superlib-libb>
                                    $<TARGET_OBJECTS:superlib-libc>)

install(TARGETS ${PROJECT_NAME}
        EXPORT  ${PROJECT_NAME}
        LIBRARY       DESTINATION "${CMAKE_INSTALL_LIBDIR}"                            COMPONENT shlib
        ARCHIVE       DESTINATION "${CMAKE_INSTALL_LIBDIR}"                            COMPONENT lib
        RUNTIME       DESTINATION "${CMAKE_INSTALL_BINDIR}"                            COMPONENT bin
        PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}" COMPONENT dev)

message(STATUS "Created target ${PROJECT_NAME} for export ${PROJECT_NAME}.")
