
set( LLVM_LINK_COMPONENTS
  Support 
  Object
  ObjCMetadata
  )

set(INPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Inputs")
add_definitions(-DINPUT_PATH="${INPUT_PATH}")

add_tapi_unittest(FileSystemTests
  FileSystem.cpp
  )

target_link_libraries(FileSystemTests
  PRIVATE
  tapiCore
  )
