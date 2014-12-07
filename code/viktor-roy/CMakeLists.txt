#############################################
##### Declaring
#############################################

set(libname "roy-viktor-mat-stat-library")
set(testname "roy-viktor-mat-stat-test")

message("")
message("############################################")
message("##### Testing ${libname}")
message("############################################")
message("")

#############################################
##### Building
#############################################

# Declare directory with public headers
add_dir_inc("include")

# Declare static library
add_lib_static(${libname} "include" "src")

# Declare unit tests
add_local_dependency(${libname})
add_app(${testname} "test")
target_link_libraries(${testname})
