project_open DataRover840
create_timing_netlist -model slow -speed 7 -temperature 85 -voltage 1100
read_sdc
update_timing_netlist
set paths [get_timing_paths -setup -npaths 1 -detail full_path]
foreach_in_collection p $paths {
  puts "SLACK     [get_path_info $p -slack]"
  puts "REQUIRED  [get_path_info $p -required_time]"
  puts "ARRIVAL   [get_path_info $p -arrival_time]"
  puts "LAUNCH    [get_path_info $p -launch_time]"
  puts "LATCH     [get_path_info $p -latch_time]"
  puts "DATADELAY [get_path_info $p -data_delay]"
}
