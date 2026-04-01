function(project_euler_add_problem problem_id source_file)
  if(NOT TARGET project_euler_core)
    message(FATAL_ERROR "project_euler_core must exist before registering problems")
  endif()

  set(target_name "project_euler_problem_${problem_id}")

  add_executable(${target_name} "${source_file}")
  target_link_libraries(
    ${target_name}
    PRIVATE project_euler_core
            project_euler_options
            project_euler_warnings)

  set_target_properties(${target_name} PROPERTIES OUTPUT_NAME "${target_name}")
endfunction()

