function(project_euler_setup_warnings)
  if(TARGET project_euler_warnings)
    return()
  endif()

  add_library(project_euler_warnings INTERFACE)

  if(MSVC)
    target_compile_options(project_euler_warnings INTERFACE /W4 /permissive- /EHsc)
  else()
    target_compile_options(
      project_euler_warnings
      INTERFACE -Wall
                -Wextra
                -Wpedantic
                -Wconversion
                -Wsign-conversion
                -Wshadow)
  endif()
endfunction()

