#############################################
##### Declaring
#############################################

set(libname  "kornyakov-kirill-scalc-library")
set(testname "kornyakov-kirill-scalc-test")

message("")
message("############################################")
message("##### Testing ${libname}")
message("############################################")
message("")

#############################################
##### Building
#############################################

# Declare directory with public headers
add_dir_inc("./")

# Declare static library
add_lib_static(${libname} "src" "./src")

# Declare unit tests
add_local_dependency(${libname})
add_app(${testname} "test")
target_link_libraries(${testname})
