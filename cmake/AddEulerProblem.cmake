function(project_euler_add_problem problem_id source_file)
  if(NOT TARGET project_euler_core)
    message(FATAL_ERROR "project_euler_core must exist before registering problems")
  endif()

  set(target_name "project_euler_problem_${problem_id}")
  cmake_path(CONVERT "${PROJECT_SOURCE_DIR}" TO_CMAKE_PATH_LIST project_euler_source_dir)

  add_executable(${target_name} "${source_file}")
  target_link_libraries(
    ${target_name}
    PRIVATE project_euler_core
            project_euler_options
            project_euler_warnings)
  target_compile_definitions(${target_name} PRIVATE PROJECT_EULER_SOURCE_DIR="${project_euler_source_dir}")

  if(problem_id STREQUAL "0022")
    set(problem_22_names_file "${CMAKE_CURRENT_BINARY_DIR}/0022_names.txt")
    if(NOT EXISTS "${problem_22_names_file}")
      file(
        DOWNLOAD
        "https://raw.githubusercontent.com/miguelcasanas/project-euler-solutions/main/0022_names.txt"
        "${problem_22_names_file}"
        STATUS problem_22_download_status
        TLS_VERIFY ON)
      list(GET problem_22_download_status 0 problem_22_download_code)
      if(NOT problem_22_download_code EQUAL 0)
        list(GET problem_22_download_status 1 problem_22_download_message)
        message(FATAL_ERROR "Failed to download problem 22 data: ${problem_22_download_message}")
      endif()
    endif()

    target_compile_definitions(
      ${target_name}
      PRIVATE PROJECT_EULER_0022_NAMES_FILE="${problem_22_names_file}")
  endif()

  set_target_properties(${target_name} PROPERTIES OUTPUT_NAME "${target_name}")
endfunction()
