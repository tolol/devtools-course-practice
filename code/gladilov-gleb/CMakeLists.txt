#############################################
##### Declaring
#############################################

set(libname  "gladilov-gleb-simplecomplexcalculator-library")
set(testname "gladilov-gleb-simplecomplexcalculator-test")

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
add_lib_static(${libname} "include" "src")

# Declare module with unit tests
add_local_dependency(${libname})
add_app(${testname} "test")
target_link_libraries(${testname})
