IF(MSVC) 

	ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE)
	ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
	SET(CMAKE_MFC_FLAG 2) 

ELSE(MSVC)

	SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall -O2 -fno-strict-aliasing")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -O2 -fno-strict-aliasing")

ENDIF(MSVC) 

set(Test_SRCS
	stdafx.cpp
	stdafx.h
	Json2015Test.cpp

)

set(Test_SRCS_W
	targetver.h
	
)
set(Test_SRCS_U
#	XXX.cpp
)




include_directories(
	${CMAKE_SOURCE_DIR}/include
	)
link_libraries(Test 
		debug 
		"${CMAKE_SOURCE_DIR}/lib/Debug/jsoncpp.lib"
		optimized 
		"${CMAKE_SOURCE_DIR}/lib/Release/jsoncpp.lib" )

	

IF(WIN32)
	ADD_EXECUTABLE(Test ${Test_SRCS} ${Test_SRCS_W})   
ELSE(WIN32)
	ADD_EXECUTABLE(Test ${Test_SRCS} ${Test_SRCS_U})   
ENDIF(WIN32)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
 
