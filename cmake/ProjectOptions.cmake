function(project_euler_setup_options)
  if(TARGET project_euler_options)
    return()
  endif()

  add_library(project_euler_options INTERFACE)
  target_compile_features(project_euler_options INTERFACE cxx_std_23)

  target_compile_definitions(
    project_euler_options
    INTERFACE PROJECT_EULER_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
              PROJECT_EULER_VERSION_MINOR=${PROJECT_VERSION_MINOR}
              PROJECT_EULER_VERSION_PATCH=${PROJECT_VERSION_PATCH})

  if(MSVC)
    target_compile_definitions(project_euler_options INTERFACE _CRT_SECURE_NO_WARNINGS)
  endif()
endfunction()

