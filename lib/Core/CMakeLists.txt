set( LLVM_LINK_COMPONENTS
  Object
  BinaryFormat
  )

add_tapi_library(tapiCore
  Architecture.cpp
  ArchitectureSet.cpp
  ArchitectureSupport.cpp
  API.cpp
  APIPrinter.cpp
  APIVisitor.cpp
  AvailabilityInfo.cpp
  FakeSymbols.cpp
  FileManager.cpp
  FileSystem.cpp
  Framework.cpp
  ExtendedInterfaceFile.cpp
  HeaderFile.cpp
  InterfaceFile.cpp
  InterfaceFileBase.cpp
  InterfaceFileManager.cpp
  JSONFile.cpp
  MachODylibReader.cpp
  Path.cpp
  Platform.cpp
  ReexportFileWriter.cpp
  Registry.cpp
  Symbol.cpp
  TapiError.cpp
  TextStub_v1.cpp
  TextStub_v2.cpp
  TextStub_v3.cpp
  Utils.cpp
  XPI.cpp
  XPISet.cpp
  YAML.cpp
  YAMLReaderWriter.cpp

  LINK_LIBS
  clangBasic
  )
