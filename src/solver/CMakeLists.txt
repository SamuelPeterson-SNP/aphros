set(T "solver")
add_library(${T} solver.cpp)
target_link_libraries(${T} timer)

set(T "approx")
add_library(${T} approx.cpp)
target_link_libraries(${T} solver suspender use_dims use_mpi)

set(T "embed")
add_library(${T} embed.cpp)
target_link_libraries(${T} suspender mesh)

set(T "approx_eb")
add_library(${T} approx_eb.cpp)
target_link_libraries(${T} approx embed vars inside use_dims)

set(T "vofm")
add_library(${T} vofm.cpp)
target_link_libraries(${T} solver normal utilvof approx_eb dump_hdf)

set(T "vof")
add_library(${T} vof.cpp)
target_link_libraries(${T} solver normal utilvof approx_eb use_dims)

set(T "tracer")
add_library(${T} tracer.cpp)
target_link_libraries(${T} PUBLIC approx_eb PRIVATE use_dims)

set(T "particles")
add_library(${T} particles.cpp)
target_link_libraries(${T} PUBLIC mesh PRIVATE use_dims)

set(T "normal")
add_library(${T} normal.cpp)
target_link_libraries(${T} PUBLIC approx_eb use_dims PRIVATE use_avx)

set(T "curv")
add_library(${T} curv.cpp)
target_link_libraries(${T} partstrmeshm normal vof vofm)

set(T "partstrmeshm")
add_library(${T} partstrmeshm.cpp)
target_link_libraries(${T} PUBLIC dumper suspender PRIVATE use_mpi use_dims)

set(T "convdiffi")
add_library(${T} convdiffi.cpp)
target_link_libraries(${T} solver approx approx_eb)

set(T "convdiffe")
add_library(${T} convdiffe.cpp)
target_link_libraries(${T} solver approx approx_eb)

set(T "convdiffvg")
add_library(${T} convdiffvg.cpp)
target_link_libraries(${T} convdiffi convdiffe)

set(T "simple")
add_library(${T} simple.cpp)
target_link_libraries(${T} convdiffvg utilconvdiff)

set(T "proj")
add_library(${T} proj.cpp)
target_link_libraries(${T} PRIVATE utilconvdiff PUBLIC use_dims)

set(T "proj_eb")
add_library(${T} proj_eb.cpp)
target_link_libraries(${T} PRIVATE utilconvdiff PUBLIC use_dims)

set(T "fluid_dummy")
add_library(${T} fluid_dummy.cpp)
target_link_libraries(${T} vars suspender posthook_default approx_eb)

set(T "electro")
add_library(${T} electro.cpp)
target_link_libraries(${T} PRIVATE approx_eb PUBLIC use_dims)

