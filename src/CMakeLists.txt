
set (include_dir "${CMAKE_CURRENT_LIST_DIR}/../include/ph_macros")
set (src_dir "${CMAKE_CURRENT_LIST_DIR}")

ph_create_modules (

	MODULES 
		"macros"

	INCLUDE
		"${include_dir}"

	SRC 
		"${src_dir}"
)

file(GLOB_RECURSE HEADER_LIST "${include_dir}/*.hpp")
file(GLOB SOURCE_LIST "${src_dir}/*.cpp")

set (self ph_macros)

add_library (${self}
	${SOURCE_LIST}  ${HEADER_LIST} 
)





ph_precompile (TARGET ${self} PUBLIC PCH ${std_pch} ${boost_pch})

add_library (ph::macros ALIAS ph_macros)
target_link_libraries (${self} PRIVATE ${Boost_LIBRARIES})
target_include_directories (${self} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories (${self} PRIVATE ${Boost_INCLUDE_DIRS})
target_compile_features (${self} PUBLIC cxx_std_20)


target_include_directories(${self} PRIVATE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/${self}>
    $<INSTALL_INTERFACE:include/${self}>
)

target_include_directories(${self} PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

else()
    set_target_properties(${PROJECT_NAME}          PROPERTIES FOLDER "dependencies/${PROJECT_NAME}")
endif()