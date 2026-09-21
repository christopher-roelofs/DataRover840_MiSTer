project_open DataRover840
create_timing_netlist -model slow -speed 7 -temperature 85 -voltage 1100
read_sdc
update_timing_netlist
set paths [get_timing_paths -setup -npaths 8 -detail path_only]
foreach_in_collection p $paths {
    puts [format "%8.3f  %s  ->  %s" [get_path_info $p -slack] \
        [get_node_info [get_path_info $p -from] -name] \
        [get_node_info [get_path_info $p -to] -name]]
}
