HHVM_EXTENSION_CHECK_DEPENDENCIES(xmlreader LibXml2)
if (ENABLE_EXTENSION_XMLREADER)
  HHVM_SELECT_SOURCES(HRE_CURRENT_EXT_PATH)
  message(STATUS "Building the xmlreader extension")
else()
  message("Not building the xmlreader extension")
endif ()