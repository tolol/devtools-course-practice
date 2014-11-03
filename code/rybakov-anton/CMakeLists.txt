#############################################
##### Declaring
#############################################

set(testname "rybakov-anton-tree-test")

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

# Declare module with unit tests
add_app(${testname} "test")
target_link_libraries(${testname})
