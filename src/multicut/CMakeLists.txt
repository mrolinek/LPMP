add_subdirectory(eval)

add_library(multicut_factors_messages multicut_factors_messages.cpp)
target_link_libraries(multicut_factors_messages LPMP)

add_library(multicut_instance multicut_instance.cpp)
target_link_libraries(multicut_instance LPMP)

add_library(correlation_clustering_instance correlation_clustering_instance.cpp)
target_link_libraries(correlation_clustering_instance LPMP)

add_library(multicut_kernighan_lin multicut_kernighan_lin.cpp)
target_link_libraries(multicut_kernighan_lin LPMP)

add_library(multicut_cycle_packing multicut_cycle_packing.cpp)
target_link_libraries(multicut_cycle_packing LPMP)

add_library(multicut_cycle_packing_parallel multicut_cycle_packing_parallel.cpp)
target_link_libraries(multicut_cycle_packing_parallel LPMP)

add_library(multicut_odd_wheel_packing multicut_odd_wheel_packing.cpp)
target_link_libraries(multicut_odd_wheel_packing LPMP)

add_library(multicut_odd_bicycle_wheel_packing multicut_odd_bicycle_wheel_packing.cpp)
target_link_libraries(multicut_odd_bicycle_wheel_packing LPMP)

add_library(transform_multigraph_matching transform_multigraph_matching.cpp)
target_link_libraries(transform_multigraph_matching LPMP)

add_library(multicut_text_input multicut_text_input.cpp)
target_link_libraries(multicut_text_input LPMP)

add_library(multicut_opengm_input multicut_opengm_input.cpp)
target_link_libraries(multicut_opengm_input LPMP HDF5)

add_library(multicut_andres_input multicut_andres_input.cpp)
target_link_libraries(multicut_andres_input LPMP HDF5)

add_library(multicut_greedy_additive_edge_contraction multicut_greedy_additive_edge_contraction.cpp)
target_link_libraries(multicut_greedy_additive_edge_contraction LPMP multicut_instance multicut_kernighan_lin)

add_executable(multicut_gaec_text_input multicut_gaec_text_input.cpp)
target_link_libraries(multicut_gaec_text_input LPMP multicut_instance multicut_text_input multicut_greedy_additive_edge_contraction)

add_library(multicut_greedy_additive_edge_contraction_parallel multicut_greedy_additive_edge_contraction_parallel.cpp)
target_link_libraries(multicut_greedy_additive_edge_contraction_parallel LPMP multicut_instance)

add_executable(multicut_gaec_parallel_text_input multicut_gaec_parallel_text_input.cpp)
target_link_libraries(multicut_gaec_parallel_text_input LPMP multicut_instance multicut_text_input multicut_greedy_additive_edge_contraction_parallel multicut_cycle_packing_parallel)

add_library(multicut_message_passing_parallel multicut_message_passing_parallel.cpp)
target_link_libraries(multicut_message_passing_parallel LPMP multicut_instance multicut_cycle_packing_parallel multicut_greedy_additive_edge_contraction_parallel)

add_executable(multicut_message_passing_text_input_parallel multicut_message_passing_text_input_parallel.cpp)
target_link_libraries(multicut_message_passing_text_input_parallel LPMP multicut_instance multicut_text_input multicut_message_passing_parallel multicut_cycle_packing_parallel)

add_executable(multicut_greedy_additive_edge_contraction_andres_input multicut_greedy_additive_edge_contraction_andres_input.cpp)
target_link_libraries(multicut_greedy_additive_edge_contraction_andres_input LPMP multicut_instance multicut_andres_input multicut_greedy_additive_edge_contraction)

add_library(multicut_greedy_edge_fixation multicut_greedy_edge_fixation.cpp)
target_link_libraries(multicut_greedy_edge_fixation LPMP multicut_instance multicut_kernighan_lin)

add_executable(multicut_greedy_edge_fixation_text_input multicut_greedy_edge_fixation_text_input.cpp)
target_link_libraries(multicut_greedy_edge_fixation_text_input LPMP multicut_instance multicut_text_input multicut_greedy_edge_fixation multicut_kernighan_lin)

add_library(multicut_local_search multicut_local_search.cpp)
target_link_libraries(multicut_local_search LPMP multicut_instance multicut_greedy_additive_edge_contraction)

add_executable(multicut_local_search_text_input multicut_local_search_text_input.cpp)
target_link_libraries(multicut_local_search_text_input LPMP multicut_text_input multicut_local_search multicut_greedy_additive_edge_contraction multicut_kernighan_lin)

# text input
SET(SOURCE_FILES 
   multicut_cycle_packing_text_input_parallel.cpp
   multicut_cycle_text_input.cpp
   multicut_odd_wheel_text_input.cpp
   multicut_odd_bicycle_wheel_text_input.cpp
)

foreach( source_file ${SOURCE_FILES} )
   string( REPLACE ".cpp" "" executable_file ${source_file} )
   add_executable( ${executable_file} ${source_file} ${headers} ${sources})
   target_link_libraries( ${executable_file} LPMP multicut_cycle_packing_parallel multicut_cycle_packing multicut_odd_wheel_packing multicut_odd_bicycle_wheel_packing multicut_text_input multicut_greedy_additive_edge_contraction multicut_greedy_edge_fixation)
endforeach( source_file ${SOURCE_FILES} )


# opengm input
SET(SOURCE_FILES
   multicut_cycle_opengm_input.cpp
   multicut_odd_wheel_opengm_input.cpp
   multicut_odd_bicycle_wheel_opengm_input.cpp
   )

foreach( source_file ${SOURCE_FILES} )
   string( REPLACE ".cpp" "" executable_file ${source_file} )
   add_executable( ${executable_file} ${source_file} ${headers} ${sources})
   target_link_libraries( ${executable_file} LPMP multicut_cycle_packing multicut_odd_wheel_packing multicut_odd_bicycle_wheel_packing multicut_opengm_input multicut_greedy_additive_edge_contraction multicut_greedy_edge_fixation)
endforeach( source_file ${SOURCE_FILES} )


# andres multicut input
SET(SOURCE_FILES
   multicut_cycle_andres_input.cpp
   multicut_odd_wheel_andres_input.cpp
   multicut_odd_bicycle_wheel_andres_input.cpp
   )

foreach( source_file ${SOURCE_FILES} )
   string( REPLACE ".cpp" "" executable_file ${source_file} )
   add_executable( ${executable_file} ${source_file} ${headers} ${sources})
   target_link_libraries( ${executable_file} LPMP multicut_cycle_packing multicut_odd_wheel_packing multicut_odd_bicycle_wheel_packing multicut_andres_input multicut_greedy_additive_edge_contraction multicut_greedy_edge_fixation)
endforeach( source_file ${SOURCE_FILES} )

add_executable(multicut_cycle_packing_text_input multicut_cycle_packing_text_input.cpp)
target_link_libraries(multicut_cycle_packing_text_input LPMP multicut_text_input multicut_cycle_packing)

add_executable(multicut_odd_wheel_packing_text_input multicut_odd_wheel_packing_text_input.cpp)
target_link_libraries(multicut_odd_wheel_packing_text_input LPMP multicut_text_input multicut_odd_wheel_packing multicut_cycle_packing)

# converters
add_executable(convert_opengm_multicut_to_text convert_opengm_multicut_to_text.cpp)
target_link_libraries(convert_opengm_multicut_to_text LPMP HDF5)

add_executable(convert_simple_multicut_hdf5_to_text convert_simple_multicut_hdf5_to_text.cpp)
target_link_libraries(convert_simple_multicut_hdf5_to_text LPMP HDF5 transform_multigraph_matching)

add_executable(convert_andres_multicut_to_text convert_andres_multicut_to_text.cpp)
target_link_libraries(convert_andres_multicut_to_text LPMP HDF5)

add_executable(convert_andres_multicut_grid_graph_to_text convert_andres_multicut_grid_graph_to_text.cpp)
target_link_libraries(convert_andres_multicut_grid_graph_to_text LPMP HDF5)

add_executable(convert_multigraph_matching_to_multicut convert_multigraph_matching_to_multicut.cpp)
target_link_libraries(convert_multigraph_matching_to_multicut LPMP correlation_clustering_instance multigraph_matching_input transform_multigraph_matching)
