project_open DataRover840
create_timing_netlist -model slow -speed 7 -temperature 85 -voltage 1100
read_sdc
update_timing_netlist
set p [lindex [get_path -setup -npaths 1 -nworst 1 -from [get_registers *adapter|ram_rdata*]] 0]
set paths [get_timing_paths -setup -npaths 1 -detail full_path]
foreach_in_collection path $paths {
  puts "SLACK [get_path_info $path -slack]  ARRIVAL [get_path_info $path -arrival_time]"
  puts "DATA DELAY [get_path_info $path -data_delay]"
  set n 0
  foreach_in_collection pt [get_path_info $path -arrival_points] {
     puts [format "  %-70s %8.3f %s" [get_point_info $pt -name] [get_point_info $pt -total] [get_point_info $pt -type]]
     incr n
     if {$n > 24} break
  }
}
