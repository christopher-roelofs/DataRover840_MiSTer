project_open r3900_cached_syn
create_timing_netlist
read_sdc
update_timing_netlist
set p [get_timing_paths -setup -npaths 1 -detail path_only]
foreach_in_collection path $p {
    puts "slack: [get_path_info $path -slack]"
    puts "from : [get_node_info [get_path_info $path -from] -name]"
    puts "to   : [get_node_info [get_path_info $path -to] -name]"
}
