#############################################
##### Declaring
#############################################

set(libname  "Tolstolutskaya-Olga-3DVector-library")
set(testname "Tolstolutskaya-Olga-3DVector-test")
set(appname  "Tolstolutskaya-Olga-3DVector-application")

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

# Declare application
add_local_dependency(${libname})
add_app(${appname} "application")
